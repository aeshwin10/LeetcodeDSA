SELECT S1.score, (SELECT COUNT(DISTINCT S2.score) FROM Scores S2 WHERE S1.Score<=S2.score) AS 'Rank'
FROM Scores S1
ORDER BY s1.score DESC

#The above logic is that, for each socre in the s1 table, we are finding the count of distinct 
#scores that are greater to get the rank of each score.
#WE can use a DENSE_RANK() OVER() Window function aswell.
