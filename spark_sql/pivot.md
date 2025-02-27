## **Pivot in SQL & PySpark 🚀**

**Pivoting** is the process of **converting rows into columns**, often used to **summarize data** in reporting.

---

## **📌 1. Pivot in SQL**

### **Example Table: `sales`**

| product | year | revenue |
| ------- | ---- | ------- |
| Laptop  | 2022 | 50000   |
| Laptop  | 2023 | 60000   |
| Phone   | 2022 | 30000   |
| Phone   | 2023 | 40000   |

🔹 **Goal:** Convert `year` values into columns (`2022` and `2023`) and show revenue per product.

### **SQL Pivot Query (MySQL, SQL Server, PostgreSQL)**

```sql
SELECT product,
       SUM(CASE WHEN year = 2022 THEN revenue END) AS "2022 Revenue",
       SUM(CASE WHEN year = 2023 THEN revenue END) AS "2023 Revenue"
FROM sales
GROUP BY product;
```

🔹 **Using `PIVOT` in SQL Server:**

```sql
SELECT * FROM (
    SELECT product, year, revenue FROM sales
) AS src
PIVOT (
    SUM(revenue) FOR year IN ([2022], [2023])
) AS pivot_table;
```

**🔍 Output:**
| product | 2022 Revenue | 2023 Revenue |
|---------|-------------|-------------|
| Laptop | 50000 | 60000 |
| Phone | 30000 | 40000 |

---

## **📌 2. Pivot in PySpark**

PySpark provides `.groupBy().pivot().agg()` for pivoting DataFrames.

### **Example: Pivot in PySpark**

```python
from pyspark.sql import SparkSession

# Initialize Spark
spark = SparkSession.builder.appName("PivotExample").getOrCreate()

# Sample Data
data = [("Laptop", 2022, 50000),
        ("Laptop", 2023, 60000),
        ("Phone", 2022, 30000),
        ("Phone", 2023, 40000)]

# Create DataFrame
df = spark.createDataFrame(data, ["product", "year", "revenue"])

# Pivot on 'year'
pivot_df = df.groupBy("product").pivot("year").sum("revenue")

# Show Output
pivot_df.show()
```

🔹 **Output:**

```
+--------+-----+-----+
| product| 2022| 2023|
+--------+-----+-----+
| Laptop |50000|60000|
| Phone  |30000|40000|
+--------+-----+-----+
```

---

## **📌 Key Differences**

| Feature      | SQL                                                          | PySpark                                   |
| ------------ | ------------------------------------------------------------ | ----------------------------------------- |
| Syntax       | Uses `PIVOT` (SQL Server) or `CASE WHEN` (MySQL, PostgreSQL) | Uses `.groupBy().pivot().agg()`           |
| Performance  | Efficient for small datasets                                 | Optimized for large-scale data processing |
| Aggregations | Supports multiple aggregations                               | Uses `agg()` function                     |

---

## **📌 Conclusion**

✅ Use **SQL PIVOT** for **database queries & reporting**.  
✅ Use **PySpark PIVOT** for **big data processing & transformations**.

Would you like an example of **unpivot (melting data back into rows)?** 🚀
