SELECT d.name AS Department , e.name AS Employee , e.salary AS Salary FROM Employee e
join Department d
on e.departmentId=d.id
WHERE (e.salary,e.departmentId) IN (
    SELECT max(salary),departmentId FROM Employee
    GROUP BY departmentId
)
