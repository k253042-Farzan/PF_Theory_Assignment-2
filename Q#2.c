#include <stdio.h>
#define MAX 100

void CustomerInfo(int *customerID, long long *cnic){
    printf("Enter Customer ID (number): ");
    scanf("%d", customerID);
    printf("Enter CNIC (digits only): ");
    scanf("%lld", cnic);
}
void Inventory(int codes[4], int quantities[4], int prices[4]){
	printf("\nProduct Code\tQuantity\tPrice\n");
	int i;
    for (i = 0; i < 4; i++){
        printf("00%d\t\t%d\t\t%d\n", codes[i], quantities[i], prices[i]);
    }
}
int main() {
    int codes[4] = {1, 2, 3, 4};        
    int quantities[4] = {50, 10, 20, 8}; 
    int prices[4] = {100, 200, 300, 150}; 

    int cartCodes[MAX];
    int cartQty[MAX];
    float cartPrice[MAX];
    int cartCount = 0;

    int customerID;
    long long cnic;

    int choice, code, qty, i, found;
    float total, discounted;
    int hasPromo, promoCode;

    while (1) {
        printf("\n1. Enter Customer Info");
        printf("\n2. Display Inventory");
        printf("\n3. Add Item to Cart");
        printf("\n4. Display Bill");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                CustomerInfo(&customerID, &cnic);
                break;

            case 2:
                Inventory(codes, quantities, prices);
                break;

            case 3:
            int n;
            do{
                printf("Enter product code: ");
                scanf("%d", &code);
                printf("Enter quantity: ");
                scanf("%d", &qty);
                found = 0;
                for (i = 0; i < 4; i++) {
                    if (codes[i] == code) {
                        found = 1;
                        if (quantities[i] >= qty) {
                            quantities[i] -= qty;  
                            cartCodes[cartCount] = code;
                            cartQty[cartCount] = qty;
                            cartPrice[cartCount] = prices[i] * qty;
                            cartCount++;
                            printf("Item added to cart.\n");
                        } else {
                            printf("Not enough stock.\n");
                        }
                        break;
                    }
                }
                if (!found){
                    printf("Product not found.\n");}
                    printf("Do you want to add more product (1 for Yes 0 for No): ");
                    scanf("%d", &n);
        }while(n!=0);
                break;
            case 4:
                total = 0;
                for (i = 0; i < cartCount; i++)
                    total += cartPrice[i];
                printf("\nDo you have a promo code? (1 for yes, 0 for no): ");
                scanf("%d", &hasPromo);
                if (hasPromo == 1) {
                    printf("Enter promo code: ");
                    scanf("%d", &promoCode);
                    if (promoCode == 2025)
                        discounted = total * 0.75; 
                    else
                        discounted = total;
                } else {
                    discounted = total;
                }
                printf("\n----- Invoice -----\n");
                printf("Customer ID: %d\nCNIC: %lld\n", customerID, cnic);
                printf("\nCode\tQty\tPrice\n");
                for (i = 0; i < cartCount; i++)
                    printf("%d\t%d\t%.2f\n", cartCodes[i], cartQty[i], cartPrice[i]);
                printf("\nTotal Bill: %.2f\n", total);
                printf("Discounted Bill: %.2f\n", discounted);
                break;
            case 5:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
