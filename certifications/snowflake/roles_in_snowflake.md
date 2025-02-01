# Roles in Snowflake

In **Snowflake**, roles are a fundamental part of **access control**. They define **who can do what** within the system by granting permissions on objects like databases, schemas, tables, and warehouses.

## **Types of Roles in Snowflake**

Snowflake has **built-in system roles** and supports **custom roles** that users can define.

### **1. System-Defined Roles**

These roles are pre-configured and provide broad privileges:

| **Role**          | **Description**                                                                                                          |
| ----------------- | ------------------------------------------------------------------------------------------------------------------------ |
| **ACCOUNTADMIN**  | The highest-level role. Has full control over the Snowflake account, including billing and security.                     |
| **SECURITYADMIN** | Manages users, roles, and access control but does not have account-level privileges.                                     |
| **SYSADMIN**      | Manages objects like warehouses, databases, and schemas. Typically, grants object-level privileges to lower-level roles. |
| **USERADMIN**     | Manages users and roles but does not manage objects. Assigns roles to users.                                             |
| **PUBLIC**        | A default role assigned to all users. Grants minimal access.                                                             |

### **2. Custom Roles**

- You can create **custom roles** to follow the **principle of least privilege**.
- Example: You can create a role for **data analysts** with read-only access to specific schemas.

### **How to Manage Roles in Snowflake**

#### **Creating a Custom Role**

```sql
CREATE ROLE data_analyst;
```

#### **Granting a Role to a User**

```sql
GRANT ROLE data_analyst TO USER john_doe;
```

#### **Granting Privileges to a Role**

Example: Granting **SELECT** on a table to the `data_analyst` role.

```sql
GRANT SELECT ON TABLE sales_db.public.orders TO ROLE data_analyst;
```

#### **Assigning a Role to Another Role**

Example: Assign `data_analyst` to `sysadmin` (Role Hierarchy).

```sql
GRANT ROLE data_analyst TO ROLE sysadmin;
```

#### **Viewing Assigned Roles**

```sql
SHOW GRANTS TO USER john_doe;
```

Would you like help designing role-based access control (RBAC) for a Snowflake environment? 🚀
