# Write your MySQL query statement below
SELECT e1.name
from Employee e1
WHERE e1.id IN (
    SELECT e2.managerId 
    FROM employee e2
    GROUP BY e2.managerID
    HAVING COUNT(e2.id) >= 5
);


