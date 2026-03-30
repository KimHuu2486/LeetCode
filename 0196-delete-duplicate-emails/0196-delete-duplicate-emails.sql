# Write your MySQL query statement below
DELETE FROM Person
WHERE id not in (
    SELECT id
    FROM (
        SELECT MIN(id) as id
        FROM Person
        GROUP BY email
    ) temp
)