# Write your MySQL query statement below
SELECT s.name FROM SalesPerson s
WHERE sales_id NOT IN(
    select distinct (o.sales_id) from Orders o
    inner join Company c on o.com_id = c.com_id
    where c.name = 'RED'
)