# Write your MySQL query statement below
SELECT Distinct A.num as ConsecutiveNums
FROM Logs A
JOIN Logs B ON B.id-1=A.id
Join Logs C ON C.id+1=A.id
where A.num=B.num and A.num=C.num