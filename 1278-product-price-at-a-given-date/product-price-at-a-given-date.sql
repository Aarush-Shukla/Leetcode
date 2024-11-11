# Write your MySQL query statement below
SELECT p.product_id,
COALESCE((
    SELECT new_price 
    From Products
    Where product_id=p.product_id
    and change_date<='2019-08-16'
    ORDER BY change_date desc
    limit 1
    ),10) as price

FROM(SELECT DISTINCT product_id FROM Products)p