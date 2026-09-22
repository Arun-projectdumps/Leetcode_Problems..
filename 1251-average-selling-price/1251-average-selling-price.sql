SELECT 
    p.product_id, 
    IFNULL(ROUND(SUM(u.units * p.price) / SUM(u.units), 2), 0) AS average_price 
FROM prices p 
LEFT JOIN unitssold u 
    ON p.product_id = u.product_id 
    and u.purchase_date between p.start_date and p.end_date
GROUP BY p.product_id;
