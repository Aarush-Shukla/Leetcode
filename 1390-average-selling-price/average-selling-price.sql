# Write your MySQL query statement below
SELECT p.product_id, IFNULL(round(SUM(s.units*p.price)/sum(s.units),2),0)as  average_price
FROM Prices p
Left join UnitsSold s
ON p.product_id=s.product_id AND
s.purchase_date BETWEEN start_date AND end_date
GROUP BY p.product_id
