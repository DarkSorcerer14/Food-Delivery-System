#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5   // maximum number of orders in queue
#define NAME_LEN 50

// Structure for an Order
typedef struct {
    int orderID;
    char customerName[NAME_LEN];
    char foodItem[NAME_LEN];
} Order;

// Queue Implementation
typedef struct {
    Order orders[MAX];
    int front, rear;
} Queue;

// Initialize Queue
void initQueue(Queue *q) {
    q->front = q->rear = -1;
}

// Check if queue is full
int isFull(Queue *q) {
    return (q->rear == MAX - 1);
}

// Check if queue is empty
int isEmpty(Queue *q) {
    return (q->front == -1 || q->front > q->rear);
}

// Add order to queue
void placeOrder(Queue *q, int orderID, char *name, char *food) {
    if (isFull(q)) {
        printf("\n🚫 Cannot place order, Queue is FULL!\n");
        return;
    }
    if (q->front == -1) q->front = 0;
    q->rear++;
    q->orders[q->rear].orderID = orderID;
    strcpy(q->orders[q->rear].customerName, name);
    strcpy(q->orders[q->rear].foodItem, food);

    printf("\n✅ Order Placed Successfully: %d | %s ordered %s\n",
           orderID, name, food);
}

// Deliver (remove) order from queue
void deliverOrder(Queue *q) {
    if (isEmpty(q)) {
        printf("\n🚫 No orders to deliver!\n");
        return;
    }
    Order order = q->orders[q->front];
    printf("\n🍴 Delivering Order ID: %d | Customer: %s | Food: %s\n",
           order.orderID, order.customerName, order.foodItem);
    q->front++;
}

// Display pending orders
void displayOrders(Queue *q) {
    if (isEmpty(q)) {
        printf("\n📭 No pending orders.\n");
        return;
    }
    printf("\n📋 Pending Orders:\n");
    for (int i = q->front; i <= q->rear; i++) {
        printf("   %d. OrderID: %d | Customer: %s | Food: %s\n",
               i - q->front + 1,
               q->orders[i].orderID,
               q->orders[i].customerName,
               q->orders[i].foodItem);
    }
}

int main() {
    Queue q;
    initQueue(&q);
    int choice, id = 100;  // starting order ID
    char name[NAME_LEN], food[NAME_LEN];

    printf("====== 🍔 Food Delivery System (Using Queue) ======\n");

    while (1) {
        printf("\n1. Place Order\n2. Deliver Order\n3. View Pending Orders\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline buffer

        switch (choice) {
            case 1:
                printf("Enter Customer Name: ");
                fgets(name, NAME_LEN, stdin);
                name[strcspn(name, "\n")] = 0;  // remove newline

                printf("Enter Food Item: ");
                fgets(food, NAME_LEN, stdin);
                food[strcspn(food, "\n")] = 0;  // remove newline

                placeOrder(&q, id++, name, food);
                break;

            case 2:
                deliverOrder(&q);
                break;

            case 3:
                displayOrders(&q);
                break;

            case 4:
                printf("\n👋 Exiting System. Goodbye!\n");
                exit(0);

            default:
                printf("\n❌ Invalid choice! Try again.\n");
        }
    }
    return 0;
}