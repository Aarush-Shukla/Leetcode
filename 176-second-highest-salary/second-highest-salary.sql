# Write your MySQL query statement below
SELECT(select distinct salary
    from 
    employee
    order by salary desc
    limit 1
    offset 1) AS SecondHighestSalary