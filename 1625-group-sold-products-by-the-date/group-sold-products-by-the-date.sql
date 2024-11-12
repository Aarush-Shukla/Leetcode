# Write your MySQL query statement below
SELECT sell_date, Count(distinct(product)) as num_sold, GROUP_CONCAT(DISTINCT product ORDER BY product ASC) AS products
FROM Activities
Group by sell_date