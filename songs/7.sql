--SQL: List of songs

SELECT AVG(energy) FROM songs
WHERE artist_id = (SELECT id FROM artists WHERE name = 'Drake');