
# Shopkeeper Simulation — Greedy Customer Query Handler

## Problem Statement

Simulate a shopkeeper who handles multiple customers. Each customer has:
- A fixed budget
- A list of product requests
- A value they associate with each request

The shopkeeper must decide:
- Which product requests to fulfill for each customer (within their budget)
- How to manage inventory, cash, and debt
- How to maximize profit and log transactions

---

## Approach Used

This simulation uses a **Greedy Algorithm** to select which customer requests to fulfill. It prioritizes the queries that provide the **maximum value per rupee spent**, using a **value-to-cost ratio**.

---

## Data Structures Used

| Data Structure            | Purpose                                                                 |
|--------------------------|-------------------------------------------------------------------------|
| `unordered_map<int, int> inv`         | Product ID → Current stock                                     |
| `unordered_map<int, double> cp`       | Product ID → Cost price per unit                               |
| `unordered_map<int, double> sp`       | Product ID → Selling price per unit                            |
| `vector<string> logs`                 | List of transaction types (SALE, RESTOCK, LOAN, REPAY)         |
| `vector<int> cids, pids, qtys`        | Parallel vectors for customer ID, product ID, quantity         |
| `vector<double> amts`                 | Transaction amount corresponding to logs                       |
| `struct Item`                         | Represents a product query with useful data for sorting        |
| `vector<Item> items`                 | Temporary list of items for sorting by value-to-cost ratio     |
| `vector<int> res`                    | Indices of selected queries that can be fulfilled              |

---

## Steps of Execution

### Step 1: Initialization
- Set initial cash.
- Initialize inventory with:
  - Product ID
  - Stock
  - Cost Price
  - Selling Price

### Step 2: Handling a Customer
- Each customer submits multiple product requests (queries).
- Each query contains:
  - Product ID
  - Quantity
  - Value (how much they value the item)

### Step 3: Solve Function (Greedy Selection)
- For each query:
  - Calculate the cost = selling price × quantity
  - Calculate value-to-cost ratio = value / cost
- Sort all queries in descending order of this ratio.
- Select queries one by one until the total cost ≤ budget.

### Step 4: Processing Selected Queries
- For each selected query:
  - Check if enough stock is available.
  - If not:
    - Try to restock using available cash.
    - If cash is not enough, take a loan to restock.
  - Deduct sold quantity from inventory.
  - Add money to cash based on sale price.
  - Calculate profit = revenue - cost price.
  - Log the transaction.

### Step 5: End of Day Summary
- If there's any loan, repay it with 10% interest.
- Print:
  - Total cash
  - Net profit
  - Inventory
  - Transaction log

---

## Sample Execution Flow

1. Initialize with Rs. 1000.
2. Add 3 products to inventory.
3. Handle 3 customers with different budgets and product demands.
4. Print:
   - Selected products per customer
   - Cost & value
   - End of day finances
   - Transaction history
   - Updated inventory

---

## Why Greedy?

- Greedy works well here since the goal is to maximize value within a fixed budget.
- No partial selection or fine-grained fractions required — each query is either fulfilled fully or not at all.
- Greedy ensures efficient and simple logic, which is suitable for this kind of real-time simulation.

---

## Example Logs

```
Type        Cust    Prod    Qty     Amt       
--------------------------------------------------
SALE        1       1       5       75.00     
SALE        1       2       2       70.00     
SALE        1       3       10      80.00     
...
```

---

## Inventory Sample

```
ID      Stock   Cost      Price     
----------------------------------------
1       35      10.00     15.00     
2       25      20.00     35.00     
3       10      5.00      8.00      
```

---

## How to Run

Just compile and run the C++ code:

```bash
g++ shop_sim.cpp -o shop_sim
./shop_sim
```

---

## Features Covered

- Greedy selection strategy
- Real-time stock and finance management
- Logging of all events
- End-of-day processing (with interest on debt)

---

## End Note

This simulation models a simplified but realistic scenario a shopkeeper might face — balancing between customer demands, inventory, and finances using a smart greedy approach.
