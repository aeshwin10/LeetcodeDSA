# Write your MySQL query statement below
SELECT "Low Salary" AS category, count(account_id) AS accounts_count
FROM Accounts
WHERE income < 20000

UNION(
SELECT "Average Salary" AS category, count(account_id) AS accounts_count
FROM Accounts
WHERE income between 20000 and 50000
)

UNION(
SELECT "High Salary" AS category, count(account_id) AS accounts_count
FROM Accounts
WHERE income > 50000
)