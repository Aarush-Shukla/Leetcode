# Write your MySQL query statement below
Select p.project_id , ifnull(round(avg(e.experience_years ),2),0) as average_years
FROM Project p
join Employee e
on p.employee_id =e.employee_id 
group by p.project_id  