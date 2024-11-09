# Write your MySQL query statement below
SELECT Visits.customer_id,count(visit_id) as count_no_trans 
FROM Visits
WHERE visit_id not in (SELECT  visit_id from Transactions)
GROUP BY Visits.customer_id