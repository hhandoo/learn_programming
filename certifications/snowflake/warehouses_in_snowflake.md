# Snowflake Compute

In Snowflake, data is held in databases and any processing of data is done by something called a "warehouse." The terminology is a little odd. Most people who work in the data field think of a warehouse as a special kind of database, not as a compute engine. Only Snowflake calls computing engines "warehouses."

## What is a Snowflake Warehouse?

A Snowflake Warehouse is a compute engine that provides the processing power to execute queries, perform data loading/unloading, and handle other tasks within Snowflake. It is independent of storage, meaning compute and storage scale separately.

Regardless of the terminology, when your trial account was created, three compute resources (a.k.a "warehouses") were created for you.

## Types of Warehouses

1. One is called COMPUTE_WH. It's owned by ACCOUNTADMIN. 
2. Another is called SANDBOX_WH and is owned by a new role called the SANDBOX_ROLE. 
3. A third warehouse is is called SYSTEM$STREAMLIT_NOTEBOOK_WH. That warehouse will be used by Snowflake do any work required by streamlit apps and notebooks you create and run. You will not use this warehouse directly, only Snowflake will use it, on your behalf.


## **Warehouse Sizes in Snowflake**  

Snowflake provides multiple warehouse sizes to accommodate different workloads. Each size determines the **compute power** (measured in terms of virtual warehouses or clusters).  

| **Warehouse Size** | **Compute Power (Relative)** | **Typical Use Case** |
|--------------------|----------------------------|---------------------|
| **X-Small (XS)**  | 1 Cluster (Smallest)       | Small workloads, single-user queries, and development/testing. |
| **Small (S)**     | 2x XS                      | Light production workloads, small ETL processes. |
| **Medium (M)**    | 2x S (4x XS)               | Moderate workloads, mid-size BI reports, parallel users. |
| **Large (L)**     | 2x M (8x XS)               | Heavy queries, data transformations, and concurrent users. |
| **X-Large (XL)**  | 2x L (16x XS)              | High-performance computing, machine learning, big data processing. |
| **2X-Large (2XL)**| 2x XL (32x XS)             | Large-scale ETL, massive concurrency workloads. |
| **3X-Large (3XL)**| 2x 2XL (64x XS)            | Enterprise-level workloads, real-time analytics. |
| **4X-Large (4XL)**| 2x 3XL (128x XS)           | Extreme-scale processing, massive parallel execution. |
