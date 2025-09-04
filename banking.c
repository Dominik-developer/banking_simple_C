#include <stdio.h>
//include <stdlib.h>

// defining additional functions
void checkBalance(float balance);
float deposit();
float withdraw(float balance);

int main() {
    // BANKING PROGRAM (SIMPLE)

    int choice = 0;
    float balance = 0.0f;

    printf("*** WELCOME TO BANK ***\n");

    do{
        printf("\nSelect an option:\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money \n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("\nEnter your choice:");
        scanf("%d", &choice);

        switch(choice) {

            case 1: //checking balance
                checkBalance(balance);
                break;

            case 2: //deposit
                balance = balance + deposit();
                break;

            case 3: //withdraw
                balance = balance - withdraw(balance);
                break;

            case 4: //exit
                printf("\nThank your for using this bank!\n");
                return 0;

            default:
                printf("\nInvalid choice. Please choose 1-4.\n");

        }

    }while(choice != 4);

    return 0;
}

// additional functions 
void checkBalance(float balance) {
    printf("\nYour current balance is: $%.2f\n", balance);
}

float deposit() {

    float amount = 0.0f;

    printf("\nEnter amount to deposit: ");
    scanf("%f", &amount);

    if(amount < 0){
        printf("Invalid amount.\n");
        return 0.0f;
    } else {
        printf("Succesfuly deposited $%.2f\n", amount);
        return amount;
    }
}

float withdraw(float balance) {

    float amount = 0.0f;

    printf("\nEnter amount to withdraw: ");
    scanf("%f", &amount);

    if(amount < 0){
        printf("Invalid amount.\n");
        return 0.0f;
    } else if(amount > balance){
        printf("Insufficient funds! Your balance is: $%.2f\n", balance);
        return 0.0f;
    } else {
        printf("Succesfuly withdraw $%.2f\n", amount);
        return amount;
    }
}

// EOF