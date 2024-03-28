# Write your MySQL query statement below
select customer_id
FROM Customer 
GROUP BY customer_id
HAVING count(distinct product_key) = (select count(product_key) from Product)