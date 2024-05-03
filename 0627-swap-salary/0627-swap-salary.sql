# Write your MySQL query statement below
UPDATE Salary
set sex = (CASE WHEN sex = 'f' THEN 'm' ELSE 'f' END)