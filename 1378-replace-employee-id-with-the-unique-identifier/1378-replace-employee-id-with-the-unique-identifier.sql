# Write your MySQL query statement below
SELECT unique_id,name FROM Employees as E left join EmployeeUNI as D on E.id=D.id;