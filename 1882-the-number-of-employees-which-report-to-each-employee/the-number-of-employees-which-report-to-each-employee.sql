# Write your MySQL query statement below
SELECT e1.employee_id ,e1.name,count(*) as reports_count,round(avg(e2.age)) as average_age
FROM Employees e1
JOIN Employees e2
ON e1.employee_id=e2.reports_to
GROUP BY e1.employee_id
Order BY e1.employee_id
