# Write your MySQL query statement below
SELECT product_id, 
new_price AS price
FROM Products WHERE (product_id,change_date) IN(
    select product_id, max(change_date)
    from products
    where change_date<="2019-08-16"
    group by product_id
)
UNION  #Case cannot be used or difficult, just try doing it and you will know.
(
    select distinct product_id, 10 as price
    from Products
    group by product_id
    having(min(change_date))>"2019-08-16"
)
