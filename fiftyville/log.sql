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
-- Get list of those that withdrew money from the ATM on Leggett Street on July 28
SELECT *
FROM atm_transactions
WHERE month = 7
AND day = 28
AND transaction_type = 'withdraw'
AND atm_location = 'Leggett Street';

-- Investigating Raymond's statements
-- Get list of all the phone calls made after 10:15 am on July 28 with a duration of less than a minute
SELECT *
FROM phone_calls
WHERE month = 7
AND day = 28
AND duration < 60;