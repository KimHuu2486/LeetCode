# Write your MySQL query statement below
select m.name
from Employee m
join Employee e on m.id = e.managerId
group by m.id, m.name
having count(e.id) >= 5