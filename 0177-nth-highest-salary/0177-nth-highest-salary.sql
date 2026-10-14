CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
SET N=N-1;
  RETURN (
    SELECT salary FROM(
      SELECT DISTINCT salary FROM Employee
      ORDER BY salary DESC
      LIMIT N,1
    )as temp


  );
END