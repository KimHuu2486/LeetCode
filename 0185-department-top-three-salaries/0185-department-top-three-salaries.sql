# Write your MySQL query statement below
select Department, Employee, Salary
from (
    select d.name as Department,
            e.name as Employee,
            e.salary as Salary,
            DENSE_RANK() OVER (
                PARTITION BY e.departmentId
                ORDER BY e.salary DESC
            ) as rk
    from Employee e
    join Department d on e.departmentId = d.id
) as temp
where rk <= 3