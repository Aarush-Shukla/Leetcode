# Write your MySQL query statement below
Select s.student_id , s.student_name, su.subject_name, count(e.student_id) as attended_exams 
FROM Students s
CROSS JOIN Subjects su
Left join Examinations e
ON s.student_id=e.student_id and su.subject_name=e.subject_name
Group BY s.student_id , s.student_name, su.subject_name
ORDER BY s.student_id, s.student_name, su.subject_name
