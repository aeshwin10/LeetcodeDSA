# Write your MySQL query statement below
SELECT IFNULL(MAX(num),null) AS num
FROM MyNumbers 
WHERE num IN(
    SELECT num FROM MyNumbers
    GROUP BY num
    HAVING count(num)=1
)

