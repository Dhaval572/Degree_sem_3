-- 1. Create Database
CREATE DATABASE CollegeDB;
USE CollegeDB;


-- 2. Create Department Table
CREATE TABLE Department(
    Dept_ID INT,
    Dept_Name VARCHAR(50),
    Location VARCHAR(50)
);


-- 3. Create Student Table
CREATE TABLE Student(
    Student_ID INT,
    Student_Name VARCHAR(50),
    Gender VARCHAR(10),
    City VARCHAR(50),
    Dept_ID INT,
    Age INT
);


-- 4. Insert Data into Department Table
INSERT INTO Department VALUES
(1, 'Computer Engineering', 'Rajkot'),
(2, 'Information Technology', 'Rajkot'),
(3, 'Mechanical Engineering', 'Gandhinagar'),
(4, 'Civil Engineering', 'Ahmedabad');


-- 5. Insert Data into Student Table
INSERT INTO Student VALUES
(101, 'Rahul', 'Male', 'Rajkot', 1, 20),
(102, 'Priya', 'Female', 'Ahmedabad', 2, 21),
(103, 'Amit', 'Male', 'Rajkot', 1, 19),
(104, 'Neha', 'Female', 'Gandhinagar', 3, 20),
(105, 'Karan', 'Male', 'Ahmedabad', 4, 22);


-- 6. Display Data
SELECT * FROM Department;
SELECT * FROM Student;


-- 7. Implement DDL Commands

CREATE TABLE Course(
    Course_ID INT,
    Course_Name VARCHAR(50),
    Duration INT
);

ALTER TABLE Course
ADD Fees DECIMAL(10,2);

DESC Course;

DROP TABLE Course;

TRUNCATE TABLE Student;


-- 8. Implement DML Commands

INSERT INTO Student VALUES
(106, 'Riya', 'Female', 'Rajkot', 2, 21);

UPDATE Student
SET City = 'Baroda'
WHERE Student_ID = 106;

DELETE FROM Student
WHERE Student_ID = 106;

SELECT * FROM Student;


-- 9. Add Primary Key Constraint

ALTER TABLE Department
ADD CONSTRAINT PK_Department
PRIMARY KEY (Dept_ID);

ALTER TABLE Student
ADD CONSTRAINT PK_Student
PRIMARY KEY (Student_ID);


-- 10. Add Unique Key Constraint

ALTER TABLE Department
ADD CONSTRAINT UQ_Dept_Name
UNIQUE (Dept_Name);


-- 11. Add Foreign Key Constraint

ALTER TABLE Student
ADD CONSTRAINT FK_Student_Department
FOREIGN KEY (Dept_ID)
REFERENCES Department(Dept_ID);


-- 12. Add Check Constraint

ALTER TABLE Student
ADD CONSTRAINT CHK_Student_Age
CHECK (Age >= 18);

ALTER TABLE Student
ADD CONSTRAINT CHK_Student_Gender
CHECK (Gender IN ('Male', 'Female'));


-- 13. Test Primary Key Constraint

INSERT INTO Student VALUES
(101, 'Karan', 'Male', 'Rajkot', 2, 20);


-- 14. Test Foreign Key Constraint

INSERT INTO Student VALUES
(107, 'Neha', 'Female', 'Rajkot', 10, 20);


-- 15. Test Check Constraint

INSERT INTO Student VALUES
(108, 'Riya', 'Female', 'Rajkot', 1, 15);


-- 16. Remove Check Constraint

ALTER TABLE Student
DROP CHECK CHK_Student_Age;


-- 17. Remove Foreign Key

ALTER TABLE Student
DROP FOREIGN KEY FK_Student_Department;


-- 18. Remove Unique Key Constraint

ALTER TABLE Department
DROP INDEX UQ_Dept_Name;


-- 19. Remove Primary Key Constraint

ALTER TABLE Student
DROP PRIMARY KEY;


-- 20. Display Final Table Data

SELECT * FROM Department;
SELECT * FROM Student;
