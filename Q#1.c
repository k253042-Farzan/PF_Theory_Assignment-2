#include <stdio.h>
#define MAX 100

void addBook(int isbns[], float prices[], int quantities[], int *count);
void processSale(int isbns[], int quantities[], int count);
void lowStockReport(int isbns[], float prices[], int quantities[], int count);

int main() {
    int isbns[MAX], quantities[MAX], count = 0, choice;
    float prices[MAX];

    while (1) {
        printf("\n1. Add New Book\n");
        printf("2. Process a Sale\n");
        printf("3. Generate Low-Stock Report\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(isbns, prices, quantities, &count);
                break;
            case 2:
                processSale(isbns, quantities, count);
                break;
            case 3:
                lowStockReport(isbns, prices, quantities, count);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}

void addBook(int isbns[], float prices[], int quantities[], int *count) {
    int isbn, i, quantity;
    float price;

    if (*count >= MAX) {
        printf("Inventory full!\n");
        return;
    }
    printf("Enter ISBN: ");
    scanf("%d", &isbn);

    for (i = 0; i < *count; i++) {
        if (isbns[i] == isbn) {
            printf("Duplicate ISBN!\n");
            return;
        }
    }

    printf("Enter Price: ");
    scanf("%f", &price);
    printf("Enter Quantity: ");
    scanf("%d", &quantity);
    isbns[*count] = isbn;
    prices[*count] = price;
    quantities[*count] = quantity;

    (*count)++;

    printf("Book added successfully.\n");
}

void processSale(int isbns[], int quantities[], int count) {
    int isbn, qty, i, found = 0;

    printf("Enter ISBN: ");
    scanf("%d", &isbn);
    printf("Enter number of copies sold: ");
    scanf("%d", &qty);

    for (i = 0; i < count; i++) {
        if (isbns[i] == isbn) {
            found = 1;
            if (quantities[i] >= qty) {
                quantities[i] -= qty;
                printf("Sale processed successfully.\n");
            } else {
                printf("Not enough stock.\n");
            }
            break;
        }
    }
    if (!found)
        printf("Book not found.\n");
}

void lowStockReport(int isbns[], float prices[], int quantities[], int count) {
    int i, found = 0;
    printf("\nLow Stock Books:\n");
    for (i = 0; i < count; i++) {
        if (quantities[i] < 5) {
            printf("ISBN: %d | Price: %.2f | Quantity: %d\n", isbns[i], prices[i], quantities[i]);
            found = 1;
        }
    }
    if (!found)
        printf("No low stock books.\n");
}
