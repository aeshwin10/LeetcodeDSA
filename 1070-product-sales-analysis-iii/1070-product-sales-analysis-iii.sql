# Write your MySQL query statement below
SELECT s.product_id, s.year as first_year, s.quantity, s.price
FROM Sales s
WHERE (s.product_id,s.year) IN(
    SELECT product_id,min(year) from Sales GROUP BY product_id
)