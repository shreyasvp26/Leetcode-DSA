-- 176. Second Highest Salary
-- https://leetcode.com/problems/second-highest-salary/

SELECT MAX(salary) AS SecondHighestSalary
FROM Employee
WHERE salary < (
    SELECT MAX(salary)
    FROM Employee
) 