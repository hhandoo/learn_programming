Apache Parquet is a **columnar storage file format** optimized for **analytical workloads**, widely used in the big data ecosystem. It's the **de facto standard** for storing structured and semi-structured data in platforms like **Apache Spark**, **Hive**, **Presto**, **Trino**, **Athena**, and many cloud-based analytics services (e.g., AWS S3 + Athena, Google BigQuery, Azure Synapse, etc.).

---

## 📘 1. What is Parquet?

Parquet is an **open-source** file format developed by Apache as part of the **Hadoop ecosystem**. It's designed for:
- Efficient storage
- High performance
- Schema evolution
- Interoperability across multiple tools and languages

It supports **rich data structures** and offers **storage efficiency** through features like **compression**, **encoding**, and **columnar storage**.

---

## 🧱 2. Row vs Columnar Storage

### 🧾 Row-based Format (like CSV, JSON, Avro):
- Stores data row by row.
- Better for transactional workloads (e.g., OLTP).
- Reads whole rows even if only 1-2 columns are needed.

### 🧮 Columnar Format (like Parquet, ORC):
- Stores data column by column.
- Better for analytics (e.g., OLAP).
- Reads only the columns you query — improves **I/O** and **CPU efficiency**.

---

## 📁 3. Key Features of Parquet

| Feature | Description |
|--------|-------------|
| **Columnar storage** | Only read required columns during queries. |
| **Efficient encoding** | Uses techniques like RLE, Dictionary Encoding, Bit Packing. |
| **Compression** | Supports Snappy (default), GZIP, Brotli, ZSTD, LZO. |
| **Schema** | Self-describing (schema is embedded in file). |
| **Nested data** | Supports complex types: struct, list, map (via Thrift schema). |
| **Splittable** | Hadoop/Spark can split files for parallel reads. |
| **Language Support** | Java, Python (PyArrow, fastparquet), C++, Go, Rust. |

---

## 🧬 4. Internal Architecture

Parquet organizes data into a **hierarchical structure**:

```
File
 └── Row Groups
      └── Column Chunks
           └── Pages (Data Pages, Dictionary Pages)
```

### 🔹 File
- Contains file metadata (footer).
- Encodes schema and other info.

### 🔹 Row Group
- Logical horizontal partition of the data (e.g., 128 MB per row group).
- Each row group holds a complete set of columns.

### 🔹 Column Chunk
- A single column’s data in a row group.
- Stored contiguously to allow fast scanning of columns.

### 🔹 Page
- Column chunk is broken into pages.
- Types: **Dictionary Page**, **Data Page V1**, **Data Page V2**.

---

## 🧠 5. Encoding Techniques

Parquet reduces file size using **encodings**:

| Encoding | Description |
|----------|-------------|
| **Plain** | Raw values, default fallback. |
| **Dictionary** | Unique values stored once, data encoded as indices. |
| **Run Length Encoding (RLE)** | Great for repeated values. |
| **Bit Packing** | Packs integers using fewer bits. |
| **Delta Encoding** | Stores difference between consecutive numbers (used in time series). |

---

## 🧊 6. Compression

Each column chunk can be compressed **independently**.

| Compression | Use Case |
|-------------|----------|
| **Snappy (default)** | Fast, balanced compression ratio. |
| **GZIP** | Higher compression, slower. |
| **ZSTD** | Modern, better than gzip in speed/ratio. |
| **LZO** | Very fast, but less compression. |

Compression is more effective in Parquet due to **columnar layout** — similar values grouped together compress better.

---

## 🧾 7. Schema Evolution

Parquet supports **schema evolution**, i.e., you can:
- Add new columns (forward compatible)
- Drop columns (backward compatible)

> However, changes like **renaming columns** or **changing types** may break compatibility unless explicitly handled.

---

## 🧪 8. Performance Benefits

Parquet is **optimized for read-heavy operations**:

- **Predicate Pushdown**: Filters are applied at metadata level before reading data.
- **Column Pruning**: Only required columns are read.
- **Vectorized Reads**: Supports batch reading for CPU efficiency.

---

## 🛠️ 9. Tools & Ecosystem Support

| Tool / Platform | Support |
|-----------------|---------|
| **Apache Spark** | Native |
| **Apache Hive** | Native |
| **Apache Drill / Impala / Trino / Presto** | Native |
| **AWS Athena / Glue** | Native |
| **Google BigQuery** | Can read/export |
| **Azure Synapse / Data Lake** | Full support |
| **Python** | PyArrow, fastparquet |
| **Pandas** | `df.to_parquet()` and `read_parquet()` |
| **DuckDB** | Excellent integration |

---

## 📦 10. Writing & Reading Parquet (Python Example)

### 🔹 Pandas + PyArrow

```python
import pandas as pd

# Save to Parquet
df = pd.DataFrame({'name': ['Alice', 'Bob'], 'age': [25, 30]})
df.to_parquet('people.parquet', engine='pyarrow', compression='snappy')

# Read from Parquet
df_read = pd.read_parquet('people.parquet', engine='pyarrow')
```

---

## 🧰 11. Parquet vs ORC vs Avro

| Format | Best For | Columnar | Compression | Splittable |
|--------|----------|----------|-------------|------------|
| **Parquet** | General-purpose analytics | ✅ | ✅ | ✅ |
| **ORC** | Optimized for Hive/Presto | ✅ | ✅ | ✅ |
| **Avro** | Row-based, streaming, serialization | ❌ | ✅ | ✅ |

---

## 🔒 12. Parquet Security

- **Encryption Support**: Optional in Parquet 1.12+.
- **Sensitive Fields**: Can be encrypted at column level.
- Works with secure storage (AWS S3 + SSE, Azure ADLS, GCS).

---

## 📌 13. Best Practices

- Choose optimal **row group size** (e.g., 128MB–1GB).
- Avoid small files (partition wisely).
- Use **Snappy** for faster reads.
- Stick to **primitive types** for better performance.
- Always define schema explicitly if possible (especially in production ETL).

---

## 🧭 14. Real-World Use Cases

- **Data Lakes** (AWS S3, Azure ADLS, GCS)
- **ETL Pipelines** (e.g., with Spark, Airflow, Dataflow)
- **Batch and Interactive Query Engines** (Athena, Presto, Dremio)
- **Machine Learning** (used for model training datasets)
- **IoT and Time-Series** (Delta encoding helps with compression)

---

## 📚 15. Further Reading & Tools

- [Apache Parquet Documentation](https://parquet.apache.org/documentation/latest/)
- [PyArrow Documentation](https://arrow.apache.org/docs/python/)
- [DuckDB](https://duckdb.org/) for local analytics
- [fastparquet GitHub](https://github.com/dask/fastparquet)

---

If you'd like, I can show a **hex dump of a Parquet file**, analyze its **footer**, or go into **Parquet internals** like **Thrift schema**, **Parquet magic bytes**, etc. Just say the word!