# Write your MySQL query statement below
SELECT a.visited_on as visited_on, sum(b.day_sum) as amount, 
round(sum(b.day_sum)/7,2)  as average_amount
FROM 
(select visited_on, sum(amount) as day_sum from customer group by visited_on) a,
(select visited_on, sum(amount) as day_sum from customer group by visited_on) b
WHERE datediff(a.visited_on, b.visited_on) between 0 and 6 #FROM cross join n*n, we reduce it to n*7
GROUP BY a.visited_on
HAVING a.visited_on - (select min(visited_on) from Customer) >=6 #Omitting first 6 dates since their difference will not satisfy the condition.
ORDER BY a.visited_on
