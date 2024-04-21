# Write your MySQL query statement below
SELECT p.product_name AS product_name, sum(o.unit) AS unit 
FROM Products p INNER JOIN Orders o ON p.product_id = o.product_id
WHERE o.order_date >= '2020-02-01' and o.order_date < '2020-03-01'
GROUP BY o.product_id 
HAVING sum(o.unit) >=100