# Write your MySQL query statement below
select e.name , u.unique_id
from employees e
LEFT JOIN employeeUNI u
ON e.id = u.id
