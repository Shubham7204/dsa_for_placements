### ✅ **Definition**

**Normalization** is a **technique used in DBMS to remove or reduce data redundancy** and **avoid undesirable characteristics** like _insertion_, _deletion_, and _update anomalies_ in database tables.
### 📌 **Purpose of Normalization**

- Avoid **duplicate data**.
- Minimize **data inconsistency**.
- Ensure **efficient storage**.
- Achieve **data integrity**.
- Simplify **maintenance and modification** of the database.

## 🔍 **Types of Anomalies**

When a database is not normalized, we encounter three major types of anomalies:
### 1. **Insertion Anomaly**
Occurs when certain data cannot be inserted into the database **without the presence of other data**

🔸 Example:  
Suppose a student hasn’t yet enrolled in any course, but we want to store their information. Since course fields can't be NULL in a single-table setup, we **can't insert the student**.

### 2. **Deletion Anomaly**
Occurs when deletion of data representing **one fact** unintentionally causes loss of **unrelated information**.

🔸 Example:  
If we delete a student who is the **only one enrolled in a course**, the course information is lost too.

`DELETE FROM Student WHERE SID = 2;`

👎 If that student was the only one taking a course, we lose **both** student and course data.

### 3. **Update Anomaly**
Occurs when one piece of data is **stored in multiple places**, and updating it in one place doesn’t automatically update it elsewhere.

🔸 Example:  
If John's salary changes from 30,000 to 40,000 and he teaches multiple students, we must update it **everywhere** manually:

`UPDATE Student SET Salary = 40000 WHERE FName = 'John';`

If missed anywhere ➝ **inconsistency**.

## 🔐 **Primary Key**

- A **Primary Key** uniquely identifies each row in a table.
- It is **unique** and **not null**.
- Helps avoid **duplicate rows**.
    
👎 In the image, `SID = 1` is repeated, which **violates primary key constraint** (row-level redundancy).
```sql
-- Invalid
SID | Sname | Age
----|-------|----
 1  |  RAM  |  20
 1  |  RAM  |  20  ← Duplicate SID
```

## 🧱 **Level of Redundancy**

### ➤ **Row Level**
- Duplicate records.
- Same SID, Sname, and Age appear multiple times.
- Violates uniqueness.
### ➤ **Column Level**
- Same data (e.g., Faculty Name, Course Name) repeated in many rows.
- Wastes space and invites inconsistency.

Example:

`FName = John, repeated with every student taking the DBMS course.`

## 🧾 **Unnormalized Table Design (Before Normalization)**

|SID|Sname|Cid|Cname|FID|Fname|Salary|
|---|---|---|---|---|---|---|
|1|RAM|C1|DBMS|F1|John|30000|
|2|Ravi|C2|JAVA|F2|Bob|40000|
|3|Nitin|C1|DBMS|F1|John|30000|
|4|Amit|C1|DBMS|F1|John|30000|
|...|...|...|...|...|...|...|
👎 Redundancy in:
- Course Name (DBMS)
- Faculty Name (John)
- Salary (30000)
---
## 🎯 **Goal of Normalization**

To split the table into **multiple related tables** such that:

- Redundant data is removed.
- Data is stored only once.
- Changes in one table reflect consistently across.

## **✅ First Normal Form (1NF)**

### 📌 Definition Recap:

A table is in **1NF** when:
- Each column contains **only atomic (indivisible)** values.
- There are **no repeating groups or multi-valued attributes**.
- Each row is **uniquely identifiable** (primary key).
### 🔴 Initial Table – **Not in 1NF**

| RollNo | Name   | Course |
| ------ | ------ | ------ |
| 1      | Sai    | C/C++  |
| 2      | Harsh  | Java   |
| 3      | Ontkar | C/DBMS |

🚫 Here, the `Course` column contains **multiple values** for some students. This violates the 1NF rule.
## ✅ Method 1: **Split into Atomic Rows (Row Duplication)**

**🔄 Split multiple course values into separate rows:**

|RollNo|Name|Course|
|---|---|---|
|1|Sai|C|
|1|Sai|C++|
|2|Harsh|Java|
|3|Ontkar|C|
|3|Ontkar|DBMS|
### 🔑 Primary Key:
Composite Key = `(RollNo, Course)`

✅ Pros:
- Fully atomic
- Easy to query individual course enrollments
- Normalized and consistent

## ✅ Method 2: **Split into Two Related Tables**

### 1️⃣ **Student Table** (Base Table):

| RollNo | Name   |
| ------ | ------ |
| 1      | Sai    |
| 2      | Harsh  |
| 3      | Ontkar |
✅ Primary Key: `RollNo`
### 2️⃣ **StudentCourse Table** (Mapping Table):

|RollNo|Course|
|---|---|
|1|C|
|1|C++|
|2|Java|
|3|C|
|3|DBMS|

✅ Primary Key: Composite `(RollNo, Course)`  
🔗 Foreign Key: `RollNo` → references `Student.RollNo`

✅ Pros:
- Highly normalized (also preps for 2NF and 3NF)    
- Better data integrity and modular design
    
## ✅ Method 3: **Flatten into Columns (Course1, Course2, etc.)**

|RollNo|Name|Course1|Course2|
|---|---|---|---|
|1|Sai|C|C++|
|2|Harsh|Java|NULL|
|3|Ontkar|C|DBMS|

✅ Primary Key: `RollNo`  
❗ _But this is not recommended for true normalization._

### ⚠️ Limitations:
- Not scalable (what if a student has 5+ courses?)
- Introduces **NULLs**
- Violates **repeating group** rule conceptually (this is a workaround, not true 1NF)
## 🔍 Final Summary Table

| Method No. | Technique Used      | Keys Used                        | Recommended? |
| ---------- | ------------------- | -------------------------------- | ------------ |
| 1          | Split Rows (Atomic) | Composite Key `(RollNo, Course)` | ✅ Yes        |
| 2          | Separate Tables     | Foreign Key + Composite Key      | ✅ Best       |
| 3          | Multiple Columns    | Single Key `RollNo`              | ❌ No (Avoid) |
## 📘 1st Normal Form (1NF)
### 🔹 Definition:

A relation is said to be in **First Normal Form (1NF)** if:
- **All attributes are atomic** (no multiple values in a single cell).
- There are **no repeating groups or arrays**.
- The table must have a **primary key** to uniquely identify each row.
📌 **Given by:** _E.F. Codd_, the father of relational databases.
### ❌ Problem: Not in 1NF

> Consider this student table:

| RollNo | Name   | Course |
| ------ | ------ | ------ |
| 1      | Sai    | C/C++  |
| 2      | Harsh  | Java   |
| 3      | Ontkar | C/DBMS |

🔴 Violation:
- `Course` column contains **multi-valued data** like `C/C++`, `C/DBMS`.
- This **violates atomicity** → hence, not in 1NF.
### ✅ Condition to Achieve 1NF:
➡️ **"Table should not contain any multi-valued attribute."**
## ✅ 3 Ways to Convert into 1NF

### ✅ **Method 1: Row Expansion (Most Preferred)**

> Split each multi-valued course entry into a separate row.

|RollNo|Name|Course|
|---|---|---|
|1|Sai|C|
|1|Sai|C++|
|2|Harsh|Java|
|3|Ontkar|C|
|3|Ontkar|DBMS|

🔹 **Primary Key:** `RollNo + Course` (composite key)

✅ **Advantages:**

- Fully atomic
- No NULL values
- Works well for large/variable datasets

### ✅ **Method 2: Create Two Separate Tables**

> Normalize by separating the multi-valued field into its own relation.

**1. Student Table (Base Table):**

| RollNo | Name   |
| ------ | ------ |
| 1      | Sai    |
| 2      | Harsh  |
| 3      | Ontkar |

🔹 Primary Key: `RollNo`

**2. Course Enrollment Table:**

|RollNo|Course|
|---|---|
|1|C|
|1|C++|
|2|Java|
|3|C|
|3|DBMS|

🔹 Primary Key: `RollNo + Course`  
🔗 Foreign Key: `RollNo` → references `Student`

✅ **Advantages:**

- Follows strict normalization
- Ready for higher normal forms
- Good design for relational models

### ✅ **Method 3: Multiple Columns (Not Preferred)**

> Create separate columns for each course (`Course1`, `Course2`, etc.)

|RollNo|Name|Course1|Course2|
|---|---|---|---|
|1|Sai|C|C++|
|2|Harsh|Java|NULL|
|3|Ontkar|C|DBMS|

🔹 Primary Key: `RollNo`

⚠️ **Drawbacks:**

- Fixed number of courses (non-scalable)
- NULL values increase
- Adds redundancy
- Not flexible for real-world datasets
### ✅ Summary of 3 Approaches

|Method|Description|Primary Key|Recommended|
|---|---|---|---|
|Method 1|Break into atomic rows|`RollNo + Course`|✅ Yes|
|Method 2|Create separate normalized tables|`RollNo`, `RollNo+Course`|✅ Best|
|Method 3|Use multiple columns|`RollNo`|❌ No|

### 🧠 Interview Tips:

- Always mention **atomic values** and **no multi-valued attributes**.    
- Explain **why NULLs and repeating groups are bad** (poor scalability, redundancy).
- Prefer **Method 1 or 2** for relational DB design.
- Highlight **foreign key usage in Method 2** for referential integrity.

