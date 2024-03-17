# Write your MySQL query statement below
select pri.product_id, IFNULL(ROUND(SUM(uni.units*pri.price)/SUM(uni.units),2),0) as average_price
FROM Prices pri LEFT JOIN UnitsSold uni 
ON pri.product_id = uni.product_id AND (uni.purchase_date BETWEEN pri.start_date AND pri.end_date)
GROUP BY pri.product_id;


#Learn IFNULL function and reviced the between keyword.
