# Personal Experience Interview (PEI) Preparation

## Leadership & Collaboration

_"Tell me about a time when you led a team through a challenging project."_

- **Example from your experience:** The **Data Control Center** backend ETL architecture you designed.
- **How to structure it:**
  - **Situation:** Processing Data Quality Output of SAP S4 HANA data in SQL database which consisted of 400-500 individual tables with data volumn of 1 million records per table and its results to be shown on BI Dashboard.
  - **Task:** I was the person responsible for building the backend data framework architecture for processing this data end to end.
  - **Action:** How did you lead? (Technical decisions, coordination, stakeholder communication)  
    Created SQL Only System, Dynamically Processing 400-500 Tables, metadata Driven Architecture, Reporting to the client about the Data Quality.
  - **Result:** Created the system in such a way that it minimized manual scripting, gave granular data control to end user and a solid infrastructure to handle errors.

---

## Problem-Solving & Impact

_"Give an example of when you solved a complex problem and delivered impact."_

- **Example from your experience:** _Optimizing ELT pipelines to reduce cloud contention & BI downtime by 60%._
- **Structure:**
  - **Situation:** There were two existing schemas in Azure Dedicated SQL Pool, one source and one target, and data was supposed to be upserted in the target + deletes needed to be handled.
  - **Task:** Both the source and target dataset was huge and using delete + merge statement took almost double the amount of time that it actually required, so there had to be a more optimized approach to handle millions of records.
  - **Action:** Used partition swap technique and swapped the last two partitions of the table in just 7-8 seconds instead of 2 minutes processing time.
  - **Result:** Made data available for the BI consumers faster and release cloud resources quickly hence saving cost.

---

## Resilience & Overcoming Challenges

_"Tell me about a time you faced failure and how you handled it."_

- **Example from your experience:** _Data ingestion pipeline failed due to unmonitored data ingestion framework missing data_
- **Structure:**
  - **Situation:** Data ingestion framework missing data, impacting analytics.
  - **Task:** You had to ensure seamless ingestion from REST APIs making sure that the errors are handled.
  - **Action:** Added a logging system to the synapse pipeline + added control limits + went through docs and applied threshold limits
  - **Result:** Decreased ingestion time by 30%, improved system reliability.

---

# Problem-Solving & Analytical Thinking Preparation

McKinsey will test your structured thinking, logical problem-solving, and ability to connect data engineering to business value.

## Types of Questions & How to Approach Them

### **1️⃣ Business Case Study (Data Engineering Context)**

💬 _"A retail company wants to improve demand forecasting. How would you approach this?"_  
✅ **Approach:**

1. **Clarify the problem** – What type of data is available? Are we predicting daily, weekly, or monthly demand?
2. **Break it down into data & analytics needs** – Data sources (transaction data, external market trends), model selection, data pipeline design.
3. **Scalability & Performance Considerations** – What cloud solutions (Azure Synapse)? How do we ensure real-time insights?
4. **Communicate a clear roadmap** – A step-by-step plan for implementation.

---

### **2️⃣ Data Engineering-Specific Problem-Solving**

💬 _"Your cloud data pipeline is running slowly. How do you debug it?"_  
✅ **Approach:**

- **Check bottlenecks** – Compute resources (Azure Synapse), query performance, parallelization.
- **Optimize data structures** – Partitioning, indexing, reducing unnecessary transformations.
- **Improve scheduling & orchestration** – ADF optimization.
- **Consider cost implications** – Reduce redundant storage, caching strategies, OOP

---

### **3️⃣ Market Sizing / Guesstimation Questions**

💬 _"Estimate the number of daily online transactions in India."_  
✅ **Approach:**

1. **Break it into segments** – Total population → Internet penetration → Online shoppers → Transaction frequency.
2. **Use logical assumptions** – Assume 50% of Indians use the internet, 30% shop online, and they make ~2 transactions/week.
3. **Do quick math & verify plausibility** – Always state assumptions clearly.

---

# **Final Preparation Tips:**

✅ **Mock Practice** – Do 2-3 PEI answers per theme using STAR.  
✅ **Think Out Loud** – McKinsey values structured problem-solving, so verbalize your thought process.  
✅ **Stay Business-Focused** – Always tie back technical work to business impact.

Would you like to do a **mock interview session** to practice your answers? 🚀
