### **Question 1:**
**Find the second highest salary from the `emp` table.**

| empno | sal  |
| ----- | ---- |
| 7839  | 5000 |
| 7698  | 2000 |
| 7782  | 4000 |
| 7566  | 4000 |
| 7788  | 3000 |

#### **SQL Query:**
```
SELECT MAX(sal)
FROM emp
WHERE sal < (SELECT MAX(sal) FROM emp);
```
![](../pics/Pasted%20image%2020250616233630.png)
![](../pics/Pasted%20image%2020250616233354.png)
### **Question 2:**

**Find the highest salary in each department from the `emp` table.**
#### **SQL Query:**
```
SELECT MAX(sal), deptno
FROM emp
GROUP BY deptno;
```
### **Question 3:**

**Find the count of employees in each department.**
```
SELECT COUNT(*), deptno
FROM emp
GROUP BY deptno;
```

### **Question 4:**

Display alternative records

MySQL
```
SELECT * 
FROM (
    SELECT customer_id, first_name, last_name, age, 
           ROW_NUMBER() OVER () AS rn
    FROM customers
) AS temp
WHERE MOD(rn, 2) != 0;
```
oracle specific
![](../pics/Pasted%20image%2020250616235110.png)
![](../pics/Pasted%20image%2020250616234109.png)![](../pics/Pasted%20image%2020250616234125.png)![](../pics/Pasted%20image%2020250616234142.png)

### **Question 5:**

Displaying duplicate of a column
![](../pics/Pasted%20image%2020250616235608.png)

### **Question 5:**

Pattern Matching
![](../pics/Pattern%20Matching%20in%20SQL%20_%20Ep-5%20_%20Top%2020%20SQL%20Interview%20Questions%20_%20GeeksforGeeks%200-21%20screenshot.png)
![](../pics/Pasted%20image%2020250617000137.png)
![](../pics/Pasted%20image%2020250617000159.png)
![](../pics/Pasted%20image%2020250617000238.png)
![](../pics/Pasted%20image%2020250617000331.png)

### **Question 6:**
Pattern Matching - 2
![](../pics/Pattern%20Searching%20in%20SQL-%202%20_%20Ep-6%20_%20Top%2020%20SQL%20Interview%20Questions%20_%20GeeksforGeeks%200-17%20screenshot.png)
![](../pics/Pasted%20image%2020250617000545.png)
![](../pics/Pasted%20image%2020250617000640.png)
![](../pics/Pasted%20image%2020250617000708.png)
![](../pics/Pasted%20image%2020250617000749.png)
![](../pics/Pasted%20image%2020250617000812.png)
![](../pics/Pasted%20image%2020250617000910.png)
### **Question 7:**

Display Nth row in the emp table

In SQL, particularly in **MySQL, SQLite**, and **PostgreSQL**, the `LIMIT` clause is used to **restrict the number of rows returned** by a query.

```
SELECT * FROM table_name
LIMIT number_of_rows OFFSET start_position;

SELECT * FROM customers
LIMIT 1 OFFSET 4;
```

- This query fetches **1 row**
- It **skips the first 4 rows**
- So, it returns the **5th row**
🧠 Think of it as:

> **OFFSET** skips rows, **LIMIT** controls how many rows you want to fetch **after skipping**

```
SELECT * 
FROM (
    SELECT *, ROW_NUMBER() OVER () AS rn 
    FROM customers
) AS temp
WHERE rn = N;
```
> Replace `N` with the row number you want (e.g., `5` for the 5th row).

```
SELECT * 
FROM customers
LIMIT 1 OFFSET N-1;
```

