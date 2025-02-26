In **PySpark**, there are several types of **joins** you can use when combining DataFrames. These are similar to SQL joins and are implemented using `.join()`.

---

## **1. Inner Join (Default)**

🔹 **Keeps only matching records from both DataFrames.**

```python
df1.join(df2, df1.id == df2.id, "inner")
```

📝 **Equivalent to SQL:**

```sql
SELECT * FROM df1 INNER JOIN df2 ON df1.id = df2.id;
```

---

## **2. Left Join (Left Outer Join)**

🔹 **Keeps all records from the left DataFrame and matching records from the right. Non-matching rows get NULLs.**

```python
df1.join(df2, df1.id == df2.id, "left")
```

📝 **Equivalent to SQL:**

```sql
SELECT * FROM df1 LEFT OUTER JOIN df2 ON df1.id = df2.id;
```

---

## **3. Right Join (Right Outer Join)**

🔹 **Keeps all records from the right DataFrame and matching records from the left. Non-matching rows get NULLs.**

```python
df1.join(df2, df1.id == df2.id, "right")
```

📝 **Equivalent to SQL:**

```sql
SELECT * FROM df1 RIGHT OUTER JOIN df2 ON df1.id = df2.id;
```

---

## **4. Full Outer Join**

🔹 **Keeps all records from both DataFrames. Non-matching rows get NULLs.**

```python
df1.join(df2, df1.id == df2.id, "outer")
```

📝 **Equivalent to SQL:**

```sql
SELECT * FROM df1 FULL OUTER JOIN df2 ON df1.id = df2.id;
```

---

## **5. Left Semi Join**

🔹 **Keeps only records from the left DataFrame where a match is found in the right DataFrame.**  
🔹 **Unlike an INNER JOIN, it returns only columns from the left DataFrame.**

```python
df1.join(df2, df1.id == df2.id, "left_semi")
```

📝 **Equivalent to SQL:**

```sql
SELECT df1.* FROM df1 WHERE df1.id IN (SELECT id FROM df2);
```

---

## **6. Left Anti Join**

🔹 **Keeps only records from the left DataFrame that have no match in the right DataFrame.**

```python
df1.join(df2, df1.id == df2.id, "left_anti")
```

📝 **Equivalent to SQL:**

```sql
SELECT df1.* FROM df1 WHERE df1.id NOT IN (SELECT id FROM df2);
```

---

## **7. Cross Join (Cartesian Product)**

🔹 **Returns the Cartesian product of both DataFrames (i.e., every row in `df1` is combined with every row in `df2`).**

```python
df1.crossJoin(df2)
```

📝 **Equivalent to SQL:**

```sql
SELECT * FROM df1 CROSS JOIN df2;
```

⚠️ **Be careful! This can generate a huge dataset.**

---

### **Example Usage**

```python
from pyspark.sql import SparkSession
from pyspark.sql.functions import col

# Initialize Spark Session
spark = SparkSession.builder.appName("JoinExamples").getOrCreate()

# Sample Data
data1 = [(1, "Alice"), (2, "Bob"), (3, "Charlie")]
data2 = [(1, "HR"), (2, "Finance")]

# Create DataFrames
df1 = spark.createDataFrame(data1, ["id", "name"])
df2 = spark.createDataFrame(data2, ["id", "department"])

# Perform a Left Join
df1.join(df2, df1.id == df2.id, "left").show()
```

Would you like a performance comparison between different joins in PySpark? 🚀

### **Joins in PySpark with Broadcast Join Optimization 🚀**

In **PySpark**, joins can be **expensive** because they require **data shuffling** across nodes. To improve performance, **Broadcast Joins** can be used to optimize joins when one DataFrame is **small enough to fit in memory**.

---

## **1. Standard Joins (Require Shuffling)**

When performing **inner, left, right, full outer, semi, or anti joins**, Spark **shuffles** the data across partitions before performing the join. This can be slow for large datasets.

**Example of a standard join:**

```python
df1.join(df2, df1.id == df2.id, "inner").show()
```

🔹 If both `df1` and `df2` are large, this join will require a **shuffle join**, which is **expensive**.

---

## **2. Broadcast Join (Efficient for Small Tables)**

🔥 **Broadcast Join** is an optimization where Spark **replicates (broadcasts) the smaller DataFrame to all worker nodes** instead of shuffling both datasets. This reduces **network traffic** and speeds up the join.

### **How to Use a Broadcast Join**

You can **manually** broadcast a DataFrame using `broadcast()` from `pyspark.sql.functions`:

```python
from pyspark.sql.functions import broadcast

df1.join(broadcast(df2), df1.id == df2.id, "inner").show()
```

🚀 This makes sense when:

- `df2` is **small** (a few MBs, typically <100MB).
- `df1` is **large**, and shuffling it would be expensive.

### **How Spark Automatically Uses Broadcast Joins**

If Spark detects a small DataFrame, it **automatically broadcasts** it if the size is **below the `spark.sql.autoBroadcastJoinThreshold` (default: 10MB).**

```python
spark.conf.set("spark.sql.autoBroadcastJoinThreshold", 50 * 1024 * 1024)  # 50MB
```

📌 **If you want to disable automatic broadcasting:**

```python
spark.conf.set("spark.sql.autoBroadcastJoinThreshold", -1)
```

---

## **3. When to Use Broadcast Join?**

✅ **Good for:**

- When one DataFrame is **small (<100MB)**.
- Reducing **shuffle operations**.
- Speeding up **joins** on large datasets.

❌ **Avoid when:**

- The small table is still **too large** to fit into memory.
- You have **multiple broadcast joins** that overload memory.

---

## **4. Other Join Optimizations**

### **Shuffle Hash Join**

🔹 If **both DataFrames are large**, Spark **hash partitions** them and performs a **hash join**.

### **Sort Merge Join (Default for Large Tables)**

🔹 Spark sorts both DataFrames on the join key and **merges** them efficiently.  
📌 **Enabled when both tables are large and have sorted partitions.**

### **Bucketed Join**

🔹 If both DataFrames are **bucketed on the same column**, Spark **skips shuffling** and performs a faster join.  
**Example (both tables must be bucketed on `id`):**

```python
df1.write.bucketBy(8, "id").saveAsTable("table1")
df2.write.bucketBy(8, "id").saveAsTable("table2")

df1.join(df2, "id").show()
```

👉 **Best used for repeated queries on large datasets!**

---

## **5. Comparing Join Strategies**

| Join Type             | Best When?                           | Pros                   | Cons                   |
| --------------------- | ------------------------------------ | ---------------------- | ---------------------- |
| **Broadcast Join**    | One DF is small (≤100MB)             | No shuffle, fast       | Large DF in memory     |
| **Shuffle Hash Join** | Both DFs are large but fit in memory | Parallel execution     | High memory usage      |
| **Sort Merge Join**   | Large DFs sorted on join keys        | Efficient for big data | Requires sorting       |
| **Bucketed Join**     | Both DFs are bucketed                | Avoids shuffle, fast   | Requires pre-bucketing |

---

### **6. Example: Comparing Join Performance**

```python
import time
from pyspark.sql.functions import broadcast

# Start Timer
start_time = time.time()

# Regular Join (may cause shuffle)
df1.join(df2, "id").count()

print("Regular Join Time:", time.time() - start_time)

# Broadcast Join
start_time = time.time()

df1.join(broadcast(df2), "id").count()

print("Broadcast Join Time:", time.time() - start_time)
```

🚀 Expect the **broadcast join to be much faster** when `df2` is small!

---

### **Final Thoughts**

1. **Use Broadcast Join when one DataFrame is small (≤100MB).**
2. **Use Bucketed Join if both DataFrames are pre-bucketed on the join key.**
3. **Sort Merge Join is the default for large DataFrames.**
4. **Optimize joins using partitioning and bucketing for massive datasets.**

Would you like a **real-world example** of optimizing PySpark joins? 🚀

### **Example of Sort Merge Join & Shuffle Hash Join in PySpark** 🚀

In PySpark, **Sort Merge Join (SMJ)** and **Shuffle Hash Join (SHJ)** are two strategies for efficiently joining large datasets.

---

## **1. Sort Merge Join (SMJ)**

🔹 **Default join strategy for large tables.**  
🔹 Works best when both DataFrames are **already sorted on the join key**.  
🔹 If the data is **not sorted**, Spark **sorts and shuffles** before joining.

### **Example of Sort Merge Join**

```python
from pyspark.sql import SparkSession

# Initialize Spark session
spark = SparkSession.builder.appName("SortMergeJoinExample") \
    .config("spark.sql.join.preferSortMergeJoin", True) \  # Enforce Sort Merge Join
    .config("spark.sql.autoBroadcastJoinThreshold", -1) \  # Disable Broadcast Join
    .getOrCreate()

# Create sample data
data1 = [(1, "Alice"), (2, "Bob"), (3, "Charlie"), (4, "David")]
data2 = [(1, "HR"), (2, "Finance"), (3, "Engineering"), (5, "Marketing")]

df1 = spark.createDataFrame(data1, ["id", "name"]).repartition(2, "id")  # Ensure partitioning on join key
df2 = spark.createDataFrame(data2, ["id", "department"]).repartition(2, "id")  # Same partitioning

# Perform Sort Merge Join
df1.join(df2, "id", "inner").explain(True)  # Explain plan

df1.join(df2, "id", "inner").show()
```

### **🔍 Explanation of Sort Merge Join**

- `repartition(2, "id")` ensures both DataFrames are **partitioned** on `id`, reducing shuffle.
- **Spark first sorts each partition** on `id`, then performs a **merge join**.
- **Plan should show:** `SortMergeJoin [id], Inner`.

---

## **2. Shuffle Hash Join (SHJ)**

🔹 Used when **one table is much smaller** than the other.  
🔹 Each partition of the large table is **hashed on the join key**.  
🔹 The smaller table is **loaded into memory as a hash table** for faster lookup.

### **Example of Shuffle Hash Join**

```python
spark.conf.set("spark.sql.join.preferSortMergeJoin", False)  # Disable Sort Merge Join

df1.join(df2.hint("SHUFFLE_HASH"), "id", "inner").explain(True)  # Force SHJ

df1.join(df2.hint("SHUFFLE_HASH"), "id", "inner").show()
```

### **🔍 Explanation of Shuffle Hash Join**

- `hint("SHUFFLE_HASH")` forces **Shuffle Hash Join**.
- The **smaller table (`df2`) is converted into a hash table**.
- The **larger table (`df1`) is scanned and matched against the hash table**.
- **Plan should show:** `ShuffledHashJoin [id], Inner`.

---

## **🔄 Performance Comparison**

| **Join Type**               | **Best When?**                   | **Pros**                         | **Cons**                           |
| --------------------------- | -------------------------------- | -------------------------------- | ---------------------------------- |
| **Sort Merge Join (SMJ)**   | Both tables are large and sorted | Efficient for large tables       | Requires sorting if not pre-sorted |
| **Shuffle Hash Join (SHJ)** | One table is much smaller        | Faster than SMJ for small tables | Memory-intensive                   |

---

## **Conclusion**

- Use **Sort Merge Join** when **both tables are large**.
- Use **Shuffle Hash Join** when **one table is significantly smaller**.
- **Optimizing partitions and sorting** can drastically improve performance.

Would you like to test it on a **real dataset**? 🚀
