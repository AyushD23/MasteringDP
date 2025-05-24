
# Shopkeeper Simulation — Customer Request Handler

## Problem Statement

You are simulating a shopkeeper who needs to handle multiple customers. Each customer has:
- A fixed amount of money (budget)
- A list of items they want to buy
- A value they assign to each request (how useful the item is to them)

The shopkeeper must decide:
- Which items to sell to each customer (without going over their budget)
- How to manage stock, money, and loans
- How to earn the most profit and keep records of all activities

---

## How the Shopkeeper Makes Decisions

This simulation chooses which requests to fulfill by picking the ones that give **the most value for the money spent**. In other words, it:
- Looks at all the customer requests
- Calculates how much value each request gives compared to its cost
- Picks the most worthwhile ones first, as long as the total stays within the customer’s budget

---

## Information Stored

| What It Is                       | What It’s For                                                  |
|----------------------------------|----------------------------------------------------------------|
| `inv` (product ID → stock)       | Tracks how many units of each product the shop has             |
| `cp` (product ID → cost price)   | Cost of buying one unit of the product                         |
| `sp` (product ID → selling price)| Price at which the shop sells one unit                         |
| `logs`                           | Records all activities like selling, restocking, loans, etc.  |
| `cids`, `pids`, `qtys`           | Lists to keep track of customer ID, product ID, and quantity  |
| `amts`                           | Amount of money involved in each activity                      |
| `Item` structure                 | Represents a customer request with details                     |
| `items`                          | Temporary list of requests used for decision-making            |
| `res`                            | Final list of requests that will be accepted                   |

---

## How It Works

### Step 1: Setup
- Start with some money in hand.
- Load the store with products: their stock, cost, and selling prices.

### Step 2: Handle a Customer
- A customer gives multiple requests (e.g., 3 apples, 2 bananas, etc.)
- Each request has:
  - Product ID
  - Quantity
  - Value (how important it is to them)

### Step 3: Pick the Best Requests
- For every request:
  - Find how much it will cost the customer
  - Divide the value by cost to find out how much value they get per rupee
- Sort all requests so the best ones come first
- Go down the list and pick as many as possible until the customer’s budget runs out

### Step 4: Process Those Requests
- For every chosen request:
  - Check if the store has enough stock
  - If not enough:
    - Try to buy more using available money
    - If money isn’t enough, take a loan
  - Reduce stock
  - Add money earned to the cash
  - Calculate the profit earned (money made - money spent)
  - Write down the transaction in the log

### Step 5: End of Day
- If there was a loan, repay it with 10% extra
- Show a summary:
  - Cash left
  - Total profit
  - Items remaining in the store
  - Full list of transactions

---

## Example Flow

1. Start with ₹1000.
2. Add 3 different products.
3. 3 customers come, each with their own budgets and item requests.
4. Print:
   - Which products were sold to whom
   - Costs, values, and earnings
   - Final cash and profits
   - Full activity history
   - Updated stock levels

---

## Why This Method Works

- It chooses requests that give the most value for the least cost.
- It works well here because:
  - Requests are either fully accepted or not accepted at all
  - There’s no need to break them into parts
- The logic is simple, fast, and works well for this real-time situation

---

## Sample Transaction Log

```
Type        Cust    Prod    Qty     Amt       
--------------------------------------------------
SALE        1       1       5       75.00     
SALE        1       2       2       70.00     
SALE        1       3       10      80.00     
...
```

---

## Sample Inventory

```
ID      Stock   Cost      Price     
----------------------------------------
1       35      10.00     15.00     
2       25      20.00     35.00     
3       10      5.00      8.00      
```

---

## How to Run

Compile and run the C++ program using:

```bash
g++ shop_sim.cpp -o shop_sim
./shop_sim
```

---

## Features

- Smart selection of customer requests based on value for money
- Tracks stock, money, and loans in real-time
- Keeps detailed records of all actions
- Handles end-of-day activities like loan repayment

---

## Final Note

This simulation shows how a shopkeeper can manage customer needs, stock, and money wisely. The idea is to fulfill requests that give the best return, while keeping the business profitable and organized.
