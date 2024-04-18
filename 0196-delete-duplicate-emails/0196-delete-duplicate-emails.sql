DELETE p1
FROM Person p1
LEFT JOIN (
    SELECT email, MIN(id) AS min_id
    FROM Person
    GROUP BY email
) p2 ON p1.email = p2.email
WHERE p1.id != p2.min_id;


#When using delete function, we cannot use in or not in operator, so we join the table
#and do the checking.