SELECT AVG(songs.energy) FROM songs
JOIN artists ON songs.id = artists.id
WHERE artists.name = 'Drake';