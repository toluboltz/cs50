-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Query to see the description of the crime scene report taken on July 28 on Chamberlin Street
SELECT description
FROM crime_scene_reports
WHERE month = 7
AND day = 28
AND street = 'Humphrey Street';

-- Query the interviews table to see what the witnesses said about the theft
SELECT name, transcript
FROM interviews
WHERE transcript LIKE '%bakery%';

-- Investigating Ruth's statements in the transcript
-- Check the bakery security logs between 10:05am and 10:25am
SELECT license_plate
FROM bakery_security_logs
WHERE activity = 'exit'
AND month = 7
AND hour = 10
AND minute >= 5
AND minute <= 25;

-- Investigating Eugene's statements
-- Get list of account numbers that money was withdrawn at the ATM on Leggett Street on July 28
SELECT account_number
FROM atm_transactions
WHERE month = 7
AND day = 28
AND transaction_type = 'withdraw'
AND atm_location = 'Leggett Street';

-- Get the account numbers of all those that withrew from the ATM
SELECT *
FROM bank_accounts
WHERE account_number
IN (
    SELECT account_number
    FROM atm_transactions
    WHERE month = 7
    AND day = 28
    AND transaction_type = 'withdraw'
    AND atm_location = 'Leggett Street'
);

-- Investigating Raymond's statements
-- Get list of all the phone calls made after 10:15 am on July 28 with a duration of less than a minute
SELECT *
FROM phone_calls
WHERE month = 7
AND day = 28
AND duration < 60;

-- Get the airport the thief departed from
SELECT *
FROM airports
WHERE city = 'Fiftyville';

-- Get list of flights from Fiftyville leaving on July 29
SELECT *
FROM flights
WHERE month = 7
AND day = 29
AND origin_airport_id = (
    SELECT id
    FROM airports
    WHERE city = 'Fiftyville'
);

-- Get list of passenger information leaving Fiftyville on July 29
SELECT *
FROM passengers
WHERE flight_id
IN (
    SELECT id
    FROM flights
    WHERE month = 7
    AND day = 29
    AND origin_airport_id = (
        SELECT id
        FROM airports
        WHERE city = 'Fiftyville'
    )
);

-- Combining some of the info I've extracted
-- Get list of people who exited the bakery that morning, used the atm on Leggett Street and booked a flight for the next day
SELECT *
FROM people
WHERE phone_number IN (
    SELECT caller
    FROM phone_calls
    WHERE month = 7
    AND day = 28
    AND duration < 60;
)
AND passport IN (
    SELECT passport_number
    FROM passengers
    WHERE flight_id
    IN (
        SELECT id
        FROM flights
        WHERE month = 7
        AND day = 29
        AND origin_airport_id = (
            SELECT id
            FROM airports
            WHERE city = 'Fiftyville'
        )
    )
)
AND license_plate IN (
    
)