### **All Possible Joins in SQL and Their PySpark Equivalents**

Here’s a comparison of different SQL joins with their equivalent PySpark syntax.

---

## **1. INNER JOIN**

### **SQL Syntax:**

```sql
SELECT A.*, B.*
FROM tableA A
INNER JOIN tableB B
ON A.id = B.id;
```

### **PySpark Equivalent:**

```python
dfA.join(dfB, dfA.id == dfB.id, "inner").show()
```

💡 Returns only matching records between both tables.

---

## **2. LEFT (OUTER) JOIN**

### **SQL Syntax:**

```sql
SELECT A.*, B.*
FROM tableA A
LEFT JOIN tableB B
ON A.id = B.id;
```

### **PySpark Equivalent:**

```python
dfA.join(dfB, dfA.id == dfB.id, "left").show()
```

💡 Returns all records from the left table (`dfA`) and matching records from the right table (`dfB`). If no match is found, `NULL` values appear for `dfB`.

---

## **3. RIGHT (OUTER) JOIN**

### **SQL Syntax:**

```sql
SELECT A.*, B.*
FROM tableA A
RIGHT JOIN tableB B
ON A.id = B.id;
```

### **PySpark Equivalent:**

```python
dfA.join(dfB, dfA.id == dfB.id, "right").show()
```

💡 Returns all records from the right table (`dfB`) and matching records from the left table (`dfA`). If no match is found, `NULL` values appear for `dfA`.

---

## **4. FULL (OUTER) JOIN**

### **SQL Syntax:**

```sql
SELECT A.*, B.*
FROM tableA A
FULL OUTER JOIN tableB B
ON A.id = B.id;
```

### **PySpark Equivalent:**

```python
dfA.join(dfB, dfA.id == dfB.id, "outer").show()
```

💡 Returns all records from both tables, with `NULL` values where no match is found.

---

## **5. LEFT SEMI JOIN (Equivalent to SQL's INNER JOIN with Filtering)**

### **SQL (No direct equivalent, but can be achieved with EXISTS or IN):**

```sql
SELECT A.*
FROM tableA A
WHERE EXISTS (SELECT 1 FROM tableB B WHERE A.id = B.id);
```

### **PySpark Equivalent:**

```python
dfA.join(dfB, dfA.id == dfB.id, "left_semi").show()
```

💡 Returns only matching records from `dfA`, but does **not** include columns from `dfB`.

---

## **6. LEFT ANTI JOIN (Equivalent to SQL’s NOT EXISTS)**

### **SQL Syntax:**

```sql
SELECT A.*
FROM tableA A
WHERE NOT EXISTS (SELECT 1 FROM tableB B WHERE A.id = B.id);
```

### **PySpark Equivalent:**

```python
dfA.join(dfB, dfA.id == dfB.id, "left_anti").show()
```

💡 Returns records from `dfA` that **do not** have a match in `dfB`.

---

## **7. CROSS JOIN**

### **SQL Syntax:**

```sql
SELECT A.*, B.*
FROM tableA A
CROSS JOIN tableB B;
```

### **PySpark Equivalent:**

```python
dfA.crossJoin(dfB).show()
```

💡 Returns the Cartesian product of both tables (each row from `dfA` is combined with every row from `dfB`).

---

### **Summary Table**

| **Join Type**   | **SQL Syntax**     | **PySpark Equivalent** |
| --------------- | ------------------ | ---------------------- |
| Inner Join      | `INNER JOIN`       | `"inner"`              |
| Left Join       | `LEFT JOIN`        | `"left"`               |
| Right Join      | `RIGHT JOIN`       | `"right"`              |
| Full Outer Join | `FULL OUTER JOIN`  | `"outer"`              |
| Left Semi Join  | `WHERE EXISTS`     | `"left_semi"`          |
| Left Anti Join  | `WHERE NOT EXISTS` | `"left_anti"`          |
| Cross Join      | `CROSS JOIN`       | `crossJoin()`          |
