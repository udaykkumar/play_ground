# Write your MySQL query statement below
select Students.id, 
        Students.name from Students
            where Students.department_id NOT IN (select id from Departments)