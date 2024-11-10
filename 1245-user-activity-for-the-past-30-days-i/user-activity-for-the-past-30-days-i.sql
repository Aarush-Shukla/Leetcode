# Write your MySQL query statement below
SELECT activity_date as day, count(distinct user_id) as active_users
FROM Activity
Where 
activity_date>='2019-06-28' AND activity_date<='2019-07-27'
group by activity_date
