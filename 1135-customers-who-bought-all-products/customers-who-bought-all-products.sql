# Write your MySQL query statement below
SELECT customer_id
FROM Customer
group by customer_id
HAVING count(distinct product_key)=(select count(product_key)from Product)