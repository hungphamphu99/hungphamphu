#include <stdio.h>
#include <stdlib.h>
#define MAX_ITEMS 3
// Maximum number of different items in stock

typedef struct Product {
    char name[50];
    int quantity;
    float price;
} Product;

typedef struct Customer {
    char name[50];
    int productId;
    int productsToBuy;
} Customer;

typedef struct Node {
    Customer customer;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *pFront;
    Node *pBack;
    int size;
} Queue;

void initQueue(Queue *q) {
    q->pFront = q->pBack = NULL;
    q->size = 0;
}

int isEmpty(Queue *q) {
    return q->size == 0;
}

void enqueue(Queue *q, Customer customer) {
    Node *p = (Node *)malloc(sizeof(Node));
    if (p == NULL) {
        
        exit(EXIT_FAILURE);
    }

    p->customer = customer;
    p->next = NULL;

    if (isEmpty(q)) {
        q->pFront = q->pBack = p;
    } else {
        q->pBack->next = p;
        q->pBack = p;
    }

    q->size++;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
    
        return 0;
    }

    Node *temp = q->pFront;
    q->pFront = q->pFront->next;

    if (q->pFront == NULL) {
        q->pBack = NULL;
    }

    free(temp);
    q->size--;

    return 1;
}


//Customer Information
void printQueue(Queue *q) {
    Node *current = q->pFront;
    printf("Customer Information :\n");
    while (current != NULL) {
        printf("Customer: %s, Product : %d, Products to buy: %d\n",
               current->customer.name, current->customer.productId, current->customer.productsToBuy);
        current = current->next;
    }
}


//Product Information
void printProductInfo(Product *items) {
    printf("\nProduct Information:\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        printf("%d. Name: %s, Quantity: %d, Price: %.2f\n",
               i ,items[i].name, items[i].quantity, items[i].price);
    }
}


// Process customer purchase
void processPurchase(Product *items, Customer customer) {
    if (customer.productId >= MAX_ITEMS || items[customer.productId].quantity < customer.productsToBuy) {
        // Warning:  item out of stock
        
        printf("Warning:  %s is out of stock! %s cannot purchase.\n",
               items[customer.productId].name, customer.name);
    } else {
        
        printf("%s successfully purchased %d %s. Total cost: %.2f\n",
               customer.name, customer.productsToBuy, items[customer.productId].name,
               customer.productsToBuy * items[customer.productId].price);
        items[customer.productId].quantity -= customer.productsToBuy;
    }
}
void processCustomerQueue(Queue *customerQueue, Product *items) {
    while (!isEmpty(customerQueue)) {
        Customer currentCustomer = customerQueue->pFront->customer;

        printf("\nProcessing Customer: %s\n", currentCustomer.name);
        printf("Buying %d products of Product ID %d...\n", currentCustomer.productsToBuy, currentCustomer.productId);

        processPurchase(items, currentCustomer);
        dequeue(customerQueue);
    }
}


int main() {
    Queue customerQueue;
    initQueue(&customerQueue);

    
    Product items[MAX_ITEMS] = {
        {"Heroin", 10, 2.5},
        {"Cocaine", 8, 5.0},
        {"Tobacco", 15, 1.75}
    };
    
    // Customer wants to buy k products of Product ID
    
    Customer customer1 = {"Pham", 0, 3};
    Customer customer2 = {"Phu", 1, 9};
    Customer customer3 = {"Hung", 2, 6};

    enqueue(&customerQueue, customer1);
    enqueue(&customerQueue, customer2);
    enqueue(&customerQueue, customer3);

    // Display initial product information
    
    printQueue(&customerQueue);
    printProductInfo(items);

    //  buying process
    processCustomerQueue(&customerQueue, items);

    // Display updated product information after purchases
    printProductInfo(items);

    return 0;
}
