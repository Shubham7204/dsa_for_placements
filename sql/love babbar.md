```sql
CREATE DATABASE ORG;
SHOW DATABASES;
USE ORG;

CREATE TABLE Worker (
	WORKER_ID INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
	FIRST_NAME CHAR(25),
	LAST_NAME CHAR(25),
	SALARY INT(15),
	JOINING_DATE DATETIME,
	DEPARTMENT CHAR(25)
);

INSERT INTO Worker 
	(WORKER_ID, FIRST_NAME, LAST_NAME, SALARY, JOINING_DATE, DEPARTMENT) VALUES
		(001, 'Monika', 'Arora', 100000, '14-02-20 09.00.00', 'HR'),
		(002, 'Niharika', 'Verma', 80000, '14-06-11 09.00.00', 'Admin'),
		(003, 'Vishal', 'Singhal', 300000, '14-02-20 09.00.00', 'HR'),
		(004, 'Amitabh', 'Singh', 500000, '14-02-20 09.00.00', 'Admin'),
		(005, 'Vivek', 'Bhati', 500000, '14-06-11 09.00.00', 'Admin'),
		(006, 'Vipul', 'Diwan', 200000, '14-06-11 09.00.00', 'Account'),
		(007, 'Satish', 'Kumar', 75000, '14-01-20 09.00.00', 'Account'),
		(008, 'Geetika', 'Chauhan', 90000, '14-04-11 09.00.00', 'Admin');
        
SELECT * FROM Title;

CREATE TABLE Bonus (
	WORKER_REF_ID INT,
	BONUS_AMOUNT INT(10),
	BONUS_DATE DATETIME,
	FOREIGN KEY (WORKER_REF_ID)
		REFERENCES Worker(WORKER_ID)
        ON DELETE CASCADE
);

INSERT INTO Bonus 
	(WORKER_REF_ID, BONUS_AMOUNT, BONUS_DATE) VALUES
		(001, 5000, '16-02-20'),
		(002, 3000, '16-06-11'),
		(003, 4000, '16-02-20'),
		(001, 4500, '16-02-20'),
		(002, 3500, '16-06-11');
        
CREATE TABLE Title (
	WORKER_REF_ID INT,
	WORKER_TITLE CHAR(25),
	AFFECTED_FROM DATETIME,
	FOREIGN KEY (WORKER_REF_ID)
		REFERENCES Worker(WORKER_ID)
        ON DELETE CASCADE
);

INSERT INTO Title 
	(WORKER_REF_ID, WORKER_TITLE, AFFECTED_FROM) VALUES
 (001, 'Manager', '2016-02-20 00:00:00'),
 (002, 'Executive', '2016-06-11 00:00:00'),
 (008, 'Executive', '2016-06-11 00:00:00'),
 (005, 'Manager', '2016-06-11 00:00:00'),
 (004, 'Asst. Manager', '2016-06-11 00:00:00'),
 (007, 'Executive', '2016-06-11 00:00:00'),
 (006, 'Lead', '2016-06-11 00:00:00'),
 (003, 'Lead', '2016-06-11 00:00:00');
```
### **1. `Worker` Table**

| WORKER_ID | FIRST_NAME | LAST_NAME | SALARY | JOINING_DATE        | DEPARTMENT |
| --------- | ---------- | --------- | ------ | ------------------- | ---------- |
| 1         | Monika     | Arora     | 100000 | 2014-02-20 09:00:00 | HR         |
| 2         | Niharika   | Verma     | 80000  | 2014-06-11 09:00:00 | Admin      |
| 3         | Vishal     | Singhal   | 300000 | 2014-02-20 09:00:00 | HR         |
| 4         | Amitabh    | Singh     | 500000 | 2014-02-20 09:00:00 | Admin      |
| 5         | Vivek      | Bhati     | 500000 | 2014-06-11 09:00:00 | Admin      |
| 6         | Vipul      | Diwan     | 200000 | 2014-06-11 09:00:00 | Account    |
| 7         | Satish     | Kumar     | 75000  | 2014-01-20 09:00:00 | Account    |
| 8         | Geetika    | Chauhan   | 90000  | 2014-04-11 09:00:00 | Admin      |

> ✅ Note: `SALARY INT(15)` means it's an integer, and `15` does **not** affect the number's size in MySQL—it’s only for display width in very old versions.
### **2. `Bonus` Table**

|WORKER_REF_ID|BONUS_AMOUNT|BONUS_DATE|
|---|---|---|
|1|5000|2016-02-20 00:00:00|
|2|3000|2016-06-11 00:00:00|
|3|4000|2016-02-20 00:00:00|
|1|4500|2016-02-20 00:00:00|
|2|3500|2016-06-11 00:00:00|

### **3. `Title` Table**

|WORKER_REF_ID|WORKER_TITLE|AFFECTED_FROM|
|---|---|---|
|1|Manager|2016-02-20 00:00:00|
|2|Executive|2016-06-11 00:00:00|
|8|Executive|2016-06-11 00:00:00|
|5|Manager|2016-06-11 00:00:00|
|4|Asst. Manager|2016-06-11 00:00:00|
|7|Executive|2016-06-11 00:00:00|
|6|Lead|2016-06-11 00:00:00|
|3|Lead|2016-06-11 00:00:00|

### ⚠️ Important Notes:

- Dates like `'14-02-20 09.00.00'` should be formatted as `'2014-02-20 09:00:00'` to avoid MySQL errors.    
- The `SHOW DATABASES;` and `USE ORG;` commands are used to check and switch databases.
- The `Title` table was created **after** the initial `SELECT * FROM Title;`, so that `SELECT` would fail unless the table already existed.

✅ Q-1. Fetch `FIRST_NAME` using alias `<WORKER_NAME>`

```sql
SELECT FIRST_NAME AS WORKER_NAME FROM Worker;
```

✅ Q-2. Fetch `FIRST_NAME` in upper case

```sql
SELECT UPPER(FIRST_NAME) FROM Worker;
```

✅ Q-3. Fetch unique values of `DEPARTMENT`

```sql
-- Option 1
SELECT DISTINCT DEPARTMENT FROM Worker;

-- Option 2 (using GROUP BY)
SELECT DEPARTMENT FROM Worker GROUP BY DEPARTMENT;
```

✅ Q-4. Print first three characters of `FIRST_NAME`

```sql
SELECT SUBSTRING(FIRST_NAME, 1, 3) FROM Worker;
```
**Syntax:** `SUBSTRING(string, start, length)`

✅ Q-5. Find position of 'b' in `FIRST_NAME` = 'Amitabh'

```sql
SELECT INSTR(FIRST_NAME, 'b') FROM Worker WHERE FIRST_NAME = 'Amitabh';
```
**Syntax:** `INSTR(string, substring)`

✅ Q-6. Remove trailing white spaces from `FIRST_NAME`

```sql
SELECT RTRIM(FIRST_NAME) FROM Worker;
```

✅ Q-7. Remove leading white spaces from `FIRST_NAME`

```sql
SELECT LTRIM(FIRST_NAME) FROM Worker;
```

✅ Q-8. Fetch unique `DEPARTMENT` and print its length

```sql
SELECT DISTINCT DEPARTMENT, LENGTH(DEPARTMENT) FROM Worker;
```
**Syntax:** `LENGTH(string)`

✅ Q-9. Replace 'a' with 'A' in `FIRST_NAME`

```sql
SELECT REPLACE(FIRST_NAME, 'a', 'A') FROM Worker;
```
**Syntax:** `REPLACE(string, from_substring, to_substring)`

✅ Q-10. Concatenate `FIRST_NAME` and `LAST_NAME` into `COMPLETE_NAME`

```sql
SELECT CONCAT(FIRST_NAME, ' ', LAST_NAME) AS COMPLETE_NAME FROM Worker;
```
**Syntax:** `CONCAT(str1, str2, ...)`
`
✅ Q-11. Print all Worker details ordered by `FIRST_NAME` ascending

```sql
SELECT * FROM Worker ORDER BY FIRST_NAME;
```

✅ Q-12. Print all Worker details ordered by `FIRST_NAME` ascending and `DEPARTMENT` descending

```sql
SELECT * FROM Worker ORDER BY FIRST_NAME ASC, DEPARTMENT DESC;
```

✅ Q-13. Print details of Workers with `FIRST_NAME` as "Vipul" and "Satish"

```sql
SELECT * FROM Worker WHERE FIRST_NAME IN ('Vipul', 'Satish');
```

✅ Q-14. Print details of Workers excluding `FIRST_NAME` "Vipul" and "Satish"

```sql
SELECT * FROM Worker WHERE FIRST_NAME NOT IN ('Vipul', 'Satish');
```

✅ Q-15. Print details of Workers with `DEPARTMENT` starting with "Admin"

```sql
SELECT * FROM Worker WHERE DEPARTMENT LIKE 'Admin%';
```

**Syntax:** `LIKE 'pattern%'` → starts with pattern

✅ Q-16. Print details of Workers whose `FIRST_NAME` contains 'a'

```sql
SELECT * FROM Worker WHERE FIRST_NAME LIKE '%a%';
```

**Syntax:** `LIKE '%pattern%'` → contains pattern

✅ Q-17. Print details of Workers whose `FIRST_NAME` ends with 'a'

```sql
SELECT * FROM Worker WHERE FIRST_NAME LIKE '%a';
```

**Syntax:** `LIKE '%a'` → ends with `a`

✅ Q-18. Print Workers whose `FIRST_NAME` ends with 'h' and has 6 letters

```sql
SELECT * FROM Worker WHERE FIRST_NAME LIKE '_____h';
```

**Syntax:** `LIKE '_____h'` → 5 underscores + 1 letter = 6 letters

✅ Q-19. Print Workers with `SALARY` between 100000 and 500000

```sql
SELECT * FROM Worker WHERE SALARY BETWEEN 100000 AND 500000;
```

**Syntax:** `BETWEEN value1 AND value2` → inclusive range

✅ Q-20. Print Workers who joined in February 2014

```sql
SELECT * FROM Worker WHERE YEAR(JOINING_DATE) = 2014 AND MONTH(JOINING_DATE) = 2;
```

**Syntax:**

- `YEAR(date_column)` extracts year
- `MONTH(date_column)` extracts month

✅ Q-21. Count employees working in the department 'Admin'

```sql
SELECT DEPARTMENT, COUNT(*) FROM Worker WHERE DEPARTMENT = 'Admin';
```

**Syntax:** `COUNT(*)` counts all rows matching the `WHERE` condition.

✅ Q-22. Fetch worker full names with salaries between 50,000 and 1,00,000

```sql
SELECT CONCAT(FIRST_NAME, ' ', LAST_NAME) FROM Worker WHERE SALARY BETWEEN 50000 AND 100000;
```

**Syntax:**

- `CONCAT()` joins strings
- `BETWEEN val1 AND val2` is inclusive

✅ Q-23. Count of workers per department in descending order

```sql
SELECT DEPARTMENT, COUNT(WORKER_ID) AS no_of_worker FROM Worker GROUP BY DEPARTMENT ORDER BY no_of_worker DESC;
```

**Syntax:**

- `GROUP BY` groups rows
- `COUNT(column)` counts non-NULL rows per group
- `ORDER BY ... DESC` sorts in descending order

✅ Q-24. Print details of Workers who are also **Managers**

```sql

SELECT W.* FROM Worker W INNER JOIN Title T ON W.WORKER_ID = T.WORKER_REF_ID WHERE T.WORKER_TITLE = 'Manager';
```

**Syntax Used:**

- `INNER JOIN table2 ON table1.col = table2.col`
- Aliasing with `W`, `T` is fine but keep it readable.

✅ Q-25. Fetch titles that appear **more than once** in the `Title` table

```sql
SELECT WORKER_TITLE, COUNT(*) AS title_count FROM Title GROUP BY WORKER_TITLE HAVING COUNT(*) > 1;
```

**Syntax Used:**

- `GROUP BY` + `HAVING` (not `WHERE`) to filter aggregates

✅ Q-26. Show only **odd rows** from the `Worker` table (based on `WORKER_ID`)

```sql
SELECT * FROM Worker WHERE MOD(WORKER_ID, 2) <> 0;
```

**Syntax Tip:** `MOD(a, b)` returns the remainder of `a ÷ b`

✅ Q-27. Show only **even rows** from the `Worker` table

```sql
SELECT * FROM Worker WHERE MOD(WORKER_ID, 2) = 0;
```

✅ Q-28. Clone a table and copy all data

```sql
CREATE TABLE Worker_Clone LIKE Worker;
INSERT INTO Worker_Clone SELECT * FROM Worker;
SELECT * FROM Worker_Clone;
```

**Syntax Used:**

- `CREATE TABLE new_table LIKE existing_table;`
- `INSERT INTO new_table SELECT * FROM existing_table;`

✅ Q-29. Fetch **common rows** between `Worker` and `Worker_Clone` (Intersection)

```sql

SELECT W.* FROM Worker W INNER JOIN Worker_Clone WC ON W.WORKER_ID = WC.WORKER_ID;
```

❌ **Avoid:** `USING(WORKER_ID)` → ✅ **Prefer:** `ON W.WORKER_ID = WC.WORKER_ID`

✅ Q-30. Show rows in `Worker` that are **not in** `Worker_Clone` (Set Difference)

```sql

SELECT W.* FROM Worker W LEFT JOIN Worker_Clone WC ON W.WORKER_ID = WC.WORKER_ID WHERE WC.WORKER_ID IS NULL;
```

**Syntax Used:**

- `LEFT JOIN ... ON ...` with `IS NULL` gives difference from left

✅ Q-31. Show the **current date and time**

```sql
SELECT CURDATE(); -- only date
SELECT NOW(); -- full datetime
```

✅ Q-32. Show the **top 5 records** ordered by `SALARY` descending

```sql
SELECT * FROM Worker ORDER BY SALARY DESC LIMIT 5;
```

✅ Q-33. Show the **5th highest salary** using `LIMIT`

```sql
SELECT * FROM Worker ORDER BY SALARY DESC LIMIT 4, 1;
```

**Syntax Tip:** `LIMIT offset, count` — fetch 1 row after skipping 4

✅ Q-34. Find **5th highest salary without LIMIT**

```sql
SELECT SALARY FROM Worker W1 WHERE 4 = ( SELECT COUNT(DISTINCT W2.SALARY) FROM Worker W2 WHERE W2.SALARY > W1.SALARY );
```

**Logic:** We count how many salaries are strictly greater; the one with 4 higher becomes 5th

✅ Q-35. Fetch **employees with same salary**

```sql
SELECT W1.* FROM Worker W1, Worker W2 WHERE W1.SALARY = W2.SALARY AND W1.WORKER_ID <> W2.WORKER_ID;
```

*Can also use `INNER JOIN` but cartesian form is valid and readable.

✅ Q-36. Show the **second highest salary** using subquery

```sql
SELECT MAX(SALARY) FROM Worker WHERE SALARY < ( SELECT MAX(SALARY) FROM Worker );
```

✅ Q-37. Show one row **twice** in result

```sql
SELECT * FROM Worker UNION ALL SELECT * FROM Worker ORDER BY WORKER_ID;
```

**Note:** `UNION ALL` repeats rows. Avoid just `UNION` as it removes duplicates.

✅ Q-38. List `WORKER_ID` who **do not get bonus** — better using `LEFT JOIN`

```sql

SELECT W.WORKER_ID 
FROM Worker W 
LEFT JOIN Bonus B ON W.WORKER_ID = B.WORKER_REF_ID 
WHERE B.WORKER_REF_ID IS NULL;
```

✅ Better than:

```sql
SELECT WORKER_ID 
FROM Worker 
WHERE WORKER_ID NOT IN (SELECT WORKER_REF_ID FROM Bonus);
```

❌ Why avoid `NOT IN`? It can **fail with NULLs** in subquery.

✅ Q-39. Fetch the **first 50% records** from table (approximation by ID)

```sql

SELECT * FROM Worker WHERE WORKER_ID <= ( SELECT COUNT(WORKER_ID)/2 FROM Worker );
```

**Note:** Works only if IDs are continuous & sorted.

✅ Q-40. Departments with **fewer than 4 employees**

```sql
SELECT DEPARTMENT, COUNT(*) AS depCount FROM Worker GROUP BY DEPARTMENT HAVING COUNT(*) < 4;
```

✅ Q-41. Show all departments along with number of employees in each

```sql
SELECT DEPARTMENT, COUNT(*) AS depCount 
FROM Worker 
GROUP BY DEPARTMENT;
```

✅ Q-42. Fetch the **last record** from the table based on `WORKER_ID`

```sql
SELECT * 
FROM Worker 
WHERE WORKER_ID = (
    SELECT MAX(WORKER_ID) 
    FROM Worker
);
```

✅ Q-43. Fetch the **first record** from the table

```sql
SELECT * 
FROM Worker 
WHERE WORKER_ID = (
    SELECT MIN(WORKER_ID) 
    FROM Worker
);
```

✅ Q-44. Fetch the **last 5 records**, ordered by `WORKER_ID`

```sql
SELECT * 
FROM (
    SELECT * 
    FROM Worker 
    ORDER BY WORKER_ID DESC 
    LIMIT 5
) AS Temp 
ORDER BY WORKER_ID;
```

✅ Nested query used to reverse-order first, then restore ascending for final output

✅ Q-45. Employees with **highest salary in each department**

```sql
SELECT W.DEPARTMENT, W.FIRST_NAME, W.SALARY 
FROM Worker W 
INNER JOIN (
    SELECT DEPARTMENT, MAX(SALARY) AS MaxSal 
    FROM Worker 
    GROUP BY DEPARTMENT
) Temp 
ON W.DEPARTMENT = Temp.DEPARTMENT 
AND W.SALARY = Temp.MaxSal;
```

✅ Q-46. Fetch **top 3 max salaries** using **correlated subquery**

```sql
SELECT DISTINCT SALARY 
FROM Worker W1 
WHERE 3 >= (
    SELECT COUNT(DISTINCT SALARY) 
    FROM Worker W2 
    WHERE W1.SALARY < W2.SALARY 
    OR W1.SALARY = W2.SALARY
) 
ORDER BY SALARY DESC;
```

✅ Better and safer: avoid `<=` style comparisons without clarification

✅ Q-47. Fetch **top 3 min salaries** using **correlated subquery**

```sql
SELECT DISTINCT SALARY 
FROM Worker W1 
WHERE 3 >= (
    SELECT COUNT(DISTINCT SALARY) 
    FROM Worker W2 
    WHERE W1.SALARY > W2.SALARY 
    OR W1.SALARY = W2.SALARY
) 
ORDER BY SALARY ASC;
```

✅ Q-48. Fetch **nth highest salary** using correlated subquery (replace `n` manually)

```sql
SELECT DISTINCT SALARY 
FROM Worker W1 
WHERE n >= (
    SELECT COUNT(DISTINCT SALARY) 
    FROM Worker W2 
    WHERE W1.SALARY < W2.SALARY 
    OR W1.SALARY = W2.SALARY
) 
ORDER BY SALARY DESC;
```

✅ Replace `n` with any integer (e.g. 4 for 4th max)

✅ Q-49. Total salary per department

```sql
SELECT DEPARTMENT, SUM(SALARY) AS depSal 
FROM Worker 
GROUP BY DEPARTMENT 
ORDER BY depSal DESC;
```

✅ Q-50. Names of workers earning the **highest salary**

```sql
SELECT FIRST_NAME, SALARY 
FROM Worker 
WHERE SALARY = (
    SELECT MAX(SALARY) 
    FROM Worker
);
```
