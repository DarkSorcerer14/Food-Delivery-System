# Food Delivery System 

This project simulates a **Food Delivery System** using a **Queue Data Structure (FIFO)** in C.  
It is designed as a **college assignment project** for demonstrating queue operations with a real-world example.

---

## Features
- Place a food order (Enqueue)
- Deliver an order (Dequeue)
- Display all pending orders
- Prevents placing orders when queue is **FULL**
- Prevents delivery when queue is **EMPTY**

---

## Queue Concept
- **FIFO (First In, First Out)** principle
- `front` → tracks first order
- `rear` → tracks last order
- Supports **Enqueue, Dequeue, Display**

---

## Project Structure
```
food-delivery-queue/
│── main.c      # Source code
│── README.md   # Documentation
```
---

## Flowchart 

Here is the flowchart showing the process of placing and delivering orders using the Queue:
```
   ┌──────────────┐
   │   START      │
   └──────┬───────┘
          │
   ┌──────▼───────┐
   │ Initialize   │
   │ Queue        │
   └──────┬───────┘
          │
   ┌──────▼───────┐
   │ Display Menu │
   └──────┬───────┘
          │
   ┌──────▼───────┐
   │ Get Choice   │
   └───┬───┬───┬──┘
       │   │   │
       │   │   │
       │   │   │
 ┌─────▼─┐ │   │
 │Choice=1│ │   │
 └───┬────┘ │   │
     │      │   │
     ▼      │   │
Check if Full?  │
  ┌───────┐    │
Yes│Print  │    │
No │Insert │    │
   └───────┘    │
                │
        ┌───────▼───────┐
        │   Choice=2    │
        └──────┬────────┘
               ▼
          Check if Empty?
          ┌───────────┐
   Yes → │ Print "No" │
   No  → │ Deliver    │
          └───────────┘
                │
        ┌───────▼───────┐
        │   Choice=3    │
        └──────┬────────┘
               ▼
          Check if Empty?
          ┌───────────┐
   Yes → │ Print "No" │
   No  → │ Display    │
          └───────────┘
                │
        ┌───────▼───────┐
        │   Choice=4    │
        └──────┬────────┘
               ▼
          ┌───────────┐
          │  STOP     │
          └───────────┘
```
---

## How to Run
```bash
# Compile
gcc main.c -o food_delivery

# Run
./food_delivery
```

---

## Sample Run
```
====== Food Delivery System ======

1. Place Order
2. Deliver Order
3. View Pending Orders
4. Exit
Enter your choice: 1
Enter Customer Name: Rahul
Enter Food Item: Burger

Order Placed Successfully: 100 | Rahul ordered Burger

Enter your choice: 3
Pending Orders:
   1. OrderID: 100 | Customer: Rahul | Food: Burger

Enter your choice: 2
Delivering Order ID: 100 | Customer: Rahul | Food: Burger
```

---

## Educational Value
- Demonstrates **Queue implementation in C**
- Real-world analogy: **Food delivery order management**
- Useful for **Data Structures Lab (DSA/DS Lab)** assignments

---
## License
This project is open-source. You may use or modify it for educational purposes.
