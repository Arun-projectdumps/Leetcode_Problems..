SELECT 
    p.product_id, 
    IFNULL(ROUND(SUM(u.units * p.price) / SUM(u.units), 2), 0) AS average_price 
FROM prices p 
LEFT JOIN unitssold u 
    ON p.product_id = u.product_id 
    and u.purchase_date >= p.start_date 
    AND u.purchase_date <= p.end_date 
GROUP BY p.product_id;
