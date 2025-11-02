#include <stdio.h>
int strLength(char str[]) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

void removeNewline(char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
        i++;
    }
}

void reverseString(char str[]) {
    int len = strLength(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void toggleBits(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        str[i] ^= (1 << 1); 
        str[i] ^= (1 << 4);  
        i++;
    }
}

void encodeMessage(char message[]) {
    reverseString(message); 
    toggleBits(message);   
    printf("\nEncoded Message: %s\n", message);
}

void decodeMessage(char message[]) {
    toggleBits(message);    
    reverseString(message); 
    printf("\nDecoded Message: %s\n", message);
}
int main() {
    char message[500];
    int choice;

    printf("=========================================\n");
    printf("   TCS Secure Message Encoder/Decoder\n");
    printf("=========================================\n");

    do {
        printf("\nMenu:\n");
        printf("1. Encode Message\n");
        printf("2. Decode Message\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                printf("\nEnter the message to encode: ");
                fgets(message, sizeof(message), stdin);
                removeNewline(message);
                encodeMessage(message);
                break;

            case 2:
                printf("\nEnter the message to decode: ");
                fgets(message, sizeof(message), stdin);
                removeNewline(message);
                decodeMessage(message);
                break;

            case 3:
                printf("\nExiting program. Goodbye!\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
