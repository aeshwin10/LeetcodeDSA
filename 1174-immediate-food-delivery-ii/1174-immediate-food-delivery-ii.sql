# Write your MySQL query statement below
select Round(100*SUM(CASE WHEN order_date=customer_pref_delivery_date THEN 1 ELSE 0 END)/
COUNT(distinct customer_id),2) AS immediate_percentage

FROM Delivery

WHERE (customer_id, order_date) IN  #Brackets are needed coz checking pairwise.
(select customer_id, min(order_date)  
FROM Delivery 
GROUP BY customer_id);