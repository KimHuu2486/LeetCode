# Write your MySQL query statement below
select d.name as Department, e.name as Employee, e.Salary
from Employee e
join Department d on e.departmentId = d.id
where e.Salary = (
    select max(salary)
    from Employee 
    where departmentId = e.departmentId
)