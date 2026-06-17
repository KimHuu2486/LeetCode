# Write your MySQL query statement below
select contest_id, round(1.0 * count(*) / (
    select count(*)
    from Users
) * 100.0, 2) as percentage
from Register
group by contest_id
order by percentage desc, contest_id asc 