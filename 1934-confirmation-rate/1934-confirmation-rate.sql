SELECT s.user_id,
COALESCE(ROUND(SUM(c.action='confirmed')/COUNT(c.action),2),0) AS confirmation_rate
FROM Signups as s
LEFT JOIN Confirmations AS c
ON s.user_id=c.user_id
GROUP BY s.user_id
