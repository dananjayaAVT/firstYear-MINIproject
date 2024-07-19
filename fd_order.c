#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations
void clearScreen();
void successfulLogin();
void displayMenu(int category);
float getPrice(int category, int code);

int main() {
    int registration, post, category;
    char name[30], email[30], password[30];

    printf("\t***********************************\n");
    printf("\t\t   Welcome to\n\t\t FD King Delivery\n");
    printf("\t***********************************\n");
    printf("ENTER REGISTRATION\tPRESS 1\nENTER LOGIN\t\tPRESS 2\n");
    scanf("%d", &registration);

    while (registration > 2) {
        printf("\nYOUR LOGIN DETAIL WAS WRONG PLEASE TRY AGAIN\n");
        printf("ENTER REGISTRATION\tPRESS 1\nENTER LOGIN\t\tPRESS 2\n");
        scanf("%d", &registration);
    }

    if (registration == 1) {
        printf("ENTER YOUR NAME:\n");
        scanf("%s", name);
        printf("ENTER YOUR EMAIL:\n");
        scanf("%s", email);
        printf("ENTER YOUR PASSWORD:\n");
        scanf("%s", password);

        clearScreen();
        successfulLogin();
    } else {
        printf("ENTER YOUR EMAIL:\n");
        scanf("%s", email);
        printf("ENTER YOUR PASSWORD:\n");
        scanf("%s", password);
        successfulLogin();
    }

    printf("ENTER YOUR POST [CUSTOMER]\tPRESS 1\n");
    printf("ENTER YOUR POST [STAFF]\t\tPRESS 2\n");
    scanf("%d", &post);

    while (post > 2) {
        printf("\nYOUR LOGIN DETAIL WAS WRONG PLEASE TRY AGAIN\n");
        printf("ENTER YOUR POST [CUSTOMER]\tPRESS 1\n");
        printf("ENTER YOUR POST [STAFF]\t\tPRESS 2\n");
        scanf("%d", &post);
    }

    int code, qty;
    float price, amt = 0.0, TotalPrice = 0.0;
    char addAnother;

    if (post == 1) {
        do {
            clearScreen();
            printf("ENTER YOUR SELECTED FOOD CATEGORY:\nBREAKFAST\tPRESS 1\nLUNCH\t\tPRESS 2\nDINNER\t\tPRESS 3\n");
            scanf("%d", &category);

            if (category < 1 || category > 3) {
                printf("INVALID CATEGORY\n");
                continue;
            }

            displayMenu(category);

            printf("\nEnter code: ");
            scanf("%d", &code);
            printf("Enter Quantity: ");
            scanf("%d", &qty);

            price = getPrice(category, code);
            if (price == 0.0) {
                printf("ERROR: INVALID CODE\n");
                continue;
            }

            amt = price * qty;
            printf("\nAmount: %.2f", amt);

            TotalPrice += amt;
            printf("\nTotal Price: %.2f", TotalPrice);
            printf("\nAdd another order (y/n)? ");
            getchar();  // Clear the newline character from the buffer
            addAnother = getchar();

        } while (addAnother == 'y' || addAnother == 'Y');

        int card_number, cvc_number, expire_date, pay, contact, distance, exit;
        char holder_name[30], receiver_name[30], delivery_address[50];

        printf("\n");
        printf("Press any key to continue...\n");
        getchar();
        clearScreen();

        printf("\t=============================\n");
        printf("\t\tPayment Gateway\n");
        printf("\t=============================\n");

        printf("Enter your card number: ");
        scanf("%d", &card_number);
        printf("Enter card holder name: ");
        scanf("%s", holder_name);
        printf("Enter card CVC number: ");
        scanf("%d", &cvc_number);
        printf("Enter expire date of card: ");
        scanf("%d", &expire_date);

        printf("\nDo you want to pay? Yes[1] No[2]: ");
        scanf("%d", &pay);
        if (pay == 1) {
            printf("Enter Your name: ");
            scanf("%s", receiver_name);
            printf("Enter delivery address: ");
            scanf("%s", delivery_address);
            printf("Enter Your contact: ");
            scanf("%d", &contact);
            printf("Enter distance (in km): ");
            scanf("%d", &distance);
            if (distance <= 20) {
                clearScreen();

                printf("\t=============================\n");
                printf("\t\tPAYMENT SUCCESSFUL\n");
                printf("\t=============================\n");

                printf("NAME: %s\n", receiver_name);
                printf("DELIVERY ADDRESS: %s\n", delivery_address);
                printf("AMOUNT: %.2f\n", TotalPrice);
                printf("CONTACT NO: %d\n", contact);
                printf("\n");
                printf("\n");
                printf("\n");
                printf("\t\t-THANK YOU FOR CHOOSING US-\n");
                printf("\n");
                printf("\n");
                printf("\n");
                printf("\t\t\tFD DELIVERY KING\n");
                printf("\t\t\tMAIN STREET, COLOMBO\n");
                printf("\t\t\tCONTACT US: 077 4545000\n");
            } else {
                printf("Sorry, we only deliver within 20km\n");
                printf("Exit PRESS 1: ");
                scanf("%d", &exit);
            }
        } else {
            printf("Exit\n");
        }
    } else if (post == 2) {
        printf("\t\t\t*WELCOME TO THE STAFF MENU* \n\n");
        printf("\tOrder Checking = Mr.W.A.T.S.Weerasinghe\n");
        printf("\tPayment Handling = Mr.A.V.T.Dhananjaya\n");
        printf("\tCustomer Care = Ms.P.G.N.P.Ekanayaka\n");
        printf("\tOrder Delivering = Mr.W.A.D.R.Devinda\n");
        printf("\tFood Store Management = Ms.A.D.D.Sarathchandra\n");
    }

    return 0;
}

void clearScreen() {
    // Clears the console screen
    system("CLS"); 
}

void successfulLogin() {
    char email[30], password[30];
    printf("\t================\n");
    printf("\t\tLOGIN\n");
    printf("\t=================\n");
    printf("ENTER YOUR EMAIL:\n");
    scanf("%s", email);
    printf("ENTER YOUR PASSWORD:\n");
    scanf("%s", password);
    printf("\t\tSUCCESSFUL LOGIN\n");
}

void displayMenu(int category) {
    if (category == 1) {
        printf("\t=============================\n");
        printf("\t\tBREAKFAST MENU\n");
        printf("\t=============================\n");
        printf("[1] RICE & CURRY PARSAL [NON VEG]\tRS.300.00\n");
        printf("[2] RICE & CURRY PARSAL [VEG]\t\tRS.250.00\n");
        printf("[3] STRINGHOPPERS PARSAL\t\tRS.250.00\n");
        printf("[4] NOODLES PARSAL\t\t\tRS.180.00\n");
        printf("[5] THOSE PARSAL\t\t\tRS.150.00\n");
        printf("[6] PARATA PARSAL\t\t\tRS.150.00\n");
        printf("[7] PIECE OF BREAD PACK\t\t\tRS.120.00\n");
    } else if (category == 2) {
        printf("\t=============================\n");
        printf("\t\tLUNCH MENU\n");
        printf("\t=============================\n");
        printf("[1] RICE & CURRY PARSAL\t\tRS.350.00\n");
        printf("[2] FRIED RICE PARSAL\t\tRS.250.00\n");
        printf("[3] BIRIYANI PARSAL\t\tRS.250.00\n");
        printf("[4] THOSE PARSAL\t\tRS.180.00\n");
        printf("[5] PARATA PARSAL\t\tRS.150.00\n");
        printf("[6] PIECE OF BREAD PACK\t\tRS.150.00\n");
    } else if (category == 3) {
        printf("\t=============================\n");
        printf("\t\tDINNER MENU\n");
        printf("\t=============================\n");
        printf("[1] RICE & CURRY PARSAL [NON VEG]\tRS.200.00\n");
        printf("[2] RICE & CURRY PARSAL [VEG]\t\tRS.250.00\n");
        printf("[3] FRIED RICE PARSAL\t\tRS.250.00\n");
        printf("[4] KOTTU PARSAL\t\t\tRS.180.00\n");
        printf("[5] CHEESE KOTTU PARSAL\t\t\tRS.150.00\n");
        printf("[6] NOODLES PARSAL\t\t\tRS.150.00\n");
        printf("[7] PIECE OF BREAD PACK\t\t\tRS.120.00\n");
    }
}

float getPrice(int category, int code) {
    float price = 0.0;
    if (category == 1) {
        switch (code) {
            case 1: price = 300.00; break;
            case 2: price = 250.00; break;
            case 3: price = 250.00; break;
            case 4: price = 180.00; break;
            case 5: price = 150.00; break;
            case 6: price = 150.00; break;
            case 7: price = 120.00; break;
            default: price = 0.00; break;
        }
    } else if (category == 2) {
        switch (code) {
            case 1: price = 350.00; break;
            case 2: price = 250.00; break;
            case 3: price = 250.00; break;
            case 4: price = 180.00; break;
            case 5: price = 150.00; break;
            case 6: price = 150.00; break;
            case 7: price = 120.00; break;
            default: price = 0.00; break;
        }
    } else if (category == 3) {
        switch (code) {
            case 1: price = 200.00; break;
            case 2: price = 250.00; break;
            case 3: price = 250.00; break;
            case 4: price = 180.00; break;
            case 5: price = 150.00; break;
            case 6: price = 150.00; break;
            case 7: price = 120.00; break;
            default: price = 0.00; break;
        }
    }
    return price;
}
