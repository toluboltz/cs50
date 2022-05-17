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
SELECT activity, license_plate, minute
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
-- 