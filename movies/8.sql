SELECT name FROM people
WHERE id IN (SELECT stars.person_id FROM stars
             JOIN movies)