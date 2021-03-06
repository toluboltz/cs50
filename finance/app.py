import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash
import datetime

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""

    # Get the user ID
    user_id = session["user_id"]

    # Get the user's stock info
    stocks_info = db.execute("SELECT symbol, name, SUM(shares) AS shares FROM transactions \
                      WHERE transactions.user_id = ? GROUP BY transactions.symbol", user_id)

    # Get the user's current cash
    cash = db.execute("SELECT cash FROM users WHERE id = ?", user_id)
    cash = cash[0]["cash"]

    # Get current price for each stock
    stock_value = 0
    for i in range(len(stocks_info)):
        stocks_info[i]["price"] = lookup(stocks_info[i]["symbol"])["price"]
        stocks_info[i]["total"] = stocks_info[i]["price"] * stocks_info[i]["shares"]
        stock_value += stocks_info[i]["total"]

    return render_template("index.html", stocks_info=stocks_info, cash=cash, total=stock_value+cash)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure input is not blank
        if not request.form.get("symbol"):
            return apology("Input is blank")

        # Lookup current stock's price
        stock = lookup(request.form.get("symbol"))

        # Ensure symbol is valid
        if not stock:
            return apology("Invalid Symbol")

        # Ensure shares is an integer
        try:
            shares = int(request.form.get("shares"))
        except ValueError:
            return apology("Shares must be integer")

        # Ensure shares is positive integer
        if shares < 1:
            return apology("Shares must be postive integer")

        # Get the user id
        user_id = session["user_id"]

        # Get user's current available cash
        rows = db.execute("SELECT cash FROM users WHERE id = ?", user_id)

        # Ensure the user can afford the purchase
        shares_cost = stock["price"] * shares
        user_cash = rows[0]["cash"]
        if user_cash < shares_cost:
            return apology("Can't afford")

        # Otherwise, complete purchase and insert into transactions database
        db.execute("INSERT INTO transactions (user_id, symbol, name, shares, price, date) VALUES (?, ?, ?, ?, ?, ?)",
                   user_id, stock["symbol"], stock["name"], shares, stock["price"], datetime.datetime.now())

        # update the cash on users database
        new_cash = user_cash - shares_cost
        db.execute("UPDATE users SET cash = ? WHERE id = ?", new_cash, user_id)

        # Flash a message
        flash("Bought!")

        # Redirect to homepage
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""

    # Get all user's transactions
    transactions = db.execute("SELECT symbol, shares, price, date FROM transactions")

    # User reached route via GET (as by clicking a link or via redirect)
    return render_template("history.html", transactions=transactions)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Lookup stock quote
        quote = lookup(request.form.get("symbol"))

        # Ensure symbol is valid
        if not quote:
            return apology("Invalid Symbol", 400)

        # Render stock's current price
        return render_template("quoted.html", quote=quote)

    # User reached route via GET (as by clicking a link or via redirect)
    return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username")

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username doesn't exist in the database
        if len(rows) == 1:
            return apology("username already exists")

        # Ensure password was submitted
        if not request.form.get("password"):
            return apology("must provide password")

        # Ensure passwords match
        if request.form.get("password") != request.form.get("confirmation"):
            return apology("passwords do not match")

        # Insert new username and hashed password into the database
        user_id = db.execute("INSERT INTO users (username, hash) VALUES (?, ?)",
                             request.form.get("username"), generate_password_hash(request.form.get("password")))

        # Remember which user has logged in
        session["user_id"] = user_id

        # Flash a message
        flash("Registered!")

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""

    # Get user ID
    user_id = session["user_id"]

    # Get all user's stocks
    symbols = db.execute("SELECT symbol FROM transactions WHERE user_id = ?", user_id)

    # User reached route via POST (as by submiting a form via POST)
    if request.method == "POST":

        # Ensure user enters valid stock
        symbol = request.form.get("symbol")
        if not symbol:
            return apology("Missing symbol")

        # Ensure user owns stock
        if symbol not in [symbol["symbol"] for symbol in symbols]:
            return apology("Symbol not owned")

        # Ensure number of shares is valid
        shares = int(request.form.get("shares"))
        if shares < 1:
            return apology("Shares must be postive integer", 400)

        # Ensure user owns number of shares
        user_shares = db.execute("SELECT SUM(shares) as shares FROM transactions as shares WHERE symbol = ?", symbol)[0]["shares"]
        if user_shares < shares:
            return apology("Too many shares")

        # Otherwise, complete purchase and insert into transactions database
        # Lookup current stock's price
        stock = lookup(request.form.get("symbol"))
        db.execute("INSERT INTO transactions (user_id, symbol, name, shares, price, date) VALUES (?, ?, ?, ?, ?, ?)",
                   user_id, stock["symbol"], stock["name"], -1 * shares, stock["price"], datetime.datetime.now())

        # Get user's current available cash
        rows = db.execute("SELECT cash FROM users WHERE id = ?", user_id)

        # Ensure the user can afford the purchase
        shares_cost = stock["price"] * shares
        user_cash = rows[0]["cash"]
        new_cash = user_cash + shares_cost
        db.execute("UPDATE users SET cash = ? WHERE id = ?", new_cash, user_id)

        # Flash a message
        flash("Sold!")

        # Redirect to homepage
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    return render_template("sell.html", stocks=symbols)