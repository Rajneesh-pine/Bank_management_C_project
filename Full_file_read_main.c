#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct user {
    char name[20];
    char dob[11];
    long long phoneno;
    long long aadharno;
    char account[7];
    int balance;
} u;

void updateBalance(FILE *fp, const u *user) {
    fseek(fp, -sizeof(u), SEEK_CUR);
    fwrite(user, sizeof(u), 1, fp);
}

bool printBalanceForUser(FILE *fp, const char *targetName) {
    u a;
    while (fread(&a, sizeof(a), 1, fp) == 1) {
        if (strcmp(a.name, targetName) == 0) {
            printf("Balance for user %s: %d\n", a.name, a.balance);
            return true;
        }
    }
    return false;
}

void balance() {
    FILE *fp;
    fp = fopen("text.txt", "rb");
    if (fp == NULL) {
        printf("Error opening file\n");
        fclose(fp);
        return;
    }

    char targetName[20];
    printf("Enter the username to check balance: ");
    scanf("%s", targetName);

    if (printBalanceForUser(fp, targetName)) {
        // The user was found, and the balance was printed
    } else {
        printf("User not found\n");
    }

    fclose(fp);
}

void withdraw() {
    int w;
    u a;
    FILE *fp;
    fp = fopen("text.txt", "r+b");
    if (fp == NULL) {
        printf("Error opening file\n");
        fclose(fp);
        return;
    }

    char targetName[20];
    printf("Enter your username: ");
    scanf("%s", targetName);

    while (fread(&a, sizeof(a), 1, fp) == 1) {
        if (strcmp(a.name, targetName) == 0) {
            printf("Enter the amount you want to withdraw: ");
            scanf("%d", &w);

            if (w <= a.balance) {
                printf("Here are your %d rupees\n", w);
                a.balance -= w;
                printf("Balance is %d\n", a.balance);
                updateBalance(fp, &a);
            } else {
                printf("You don't have enough money\n");
            }

            fclose(fp);
            return;
        }
    }

    printf("User not found\n");
    fclose(fp);
}

void save() {
    int a1;
    u a;
    FILE *fp;
    fp = fopen("text.txt", "r+b");
    if (fp == NULL) {
        printf("Error opening file\n");
        fclose(fp);
        return;
    }

    char targetName[20];
    printf("Enter your username: ");
    scanf("%s", targetName);

    while (fread(&a, sizeof(a), 1, fp) == 1) {
        if (strcmp(a.name, targetName) == 0) {
            printf("Enter the amount you want to submit: ");
            scanf("%d", &a1);
            a.balance += a1;
            printf("Your money is submitted, and now your balance is %d\n", a.balance);
            updateBalance(fp, &a);
            fclose(fp);
            return;
        }
    }

    printf("User not found\n");
    fclose(fp);
}

void transfer() {
    int w;
    u a, recipient;
    FILE *fp;
    fp = fopen("text.txt", "r+b");
    if (fp == NULL) {
        printf("Error opening file\n");
        fclose(fp);
        return;
    }

    char sourceName[20], targetName[20];
    printf("Enter your username: ");
    scanf("%s", sourceName);

    while (fread(&a, sizeof(a), 1, fp) == 1) {
        if (strcmp(a.name, sourceName) == 0) {
            printf("Enter the recipient's username: ");
            scanf("%s", targetName);

            FILE *fp2 = fopen("text.txt", "r+b");
            if (fp2 == NULL) {
                printf("Error opening file\n");
                fclose(fp);
                return;
            }

            while (fread(&recipient, sizeof(recipient), 1, fp2) == 1) {
                if (strcmp(recipient.name, targetName) == 0) {
                    printf("Enter the amount you want to transfer: ");
                    scanf("%d", &w);

                    if (w <= a.balance) {
                        printf("Transferring %d rupees to %s\n", w, recipient.name);
                        a.balance -= w;
                        recipient.balance += w;
                        printf("Your balance is now %d\n", a.balance);
                        updateBalance(fp, &a);
                        updateBalance(fp2, &recipient);
                    } else {
                        printf("You don't have enough money to transfer\n");
                    }

                    fclose(fp2);
                    fclose(fp);
                    return;
                }
            }

            printf("Recipient not found\n");
            fclose(fp2);
            fclose(fp);
            return;
        }
    }

    printf("User not found\n");
    fclose(fp);
}

void exitBank() {
    printf("Thanks for coming to our bank\n");
}

int authentication() {
    u a;
    char user[20];
    FILE *fp;
    fp = fopen("text.txt", "rb");
    if (fp == NULL) {
        printf("Error opening file\n");
        fclose(fp);
        return 0;
    }

    while (fread(&a, sizeof(a), 1, fp) == 1) {
        strcpy(user, a.name);
    }

    char ch1[20];
    char p[6] = "R@j03";
    char ch2[20];

    printf("Enter the username: ");
    scanf("%s", ch1);
    printf("Enter the password: ");
    scanf("%s", ch2);

    if ((strcmp(p, ch2) == 0) && (strcmp(user, ch1) == 0)) {
        printf("Welcome to the Bank of Ramgarh\n");
        fclose(fp);
        return 1;
    }

    fclose(fp);
    return 0;
}

int main() {
    int s;
    do{
    printf("<-----------Welcome TO Bank Of Ramgarh-----------\n>");
    printf("<           (To check balance press 1)           \n>");
    printf("<           (To withdraw money press 2)          \n >");
    printf("<           (To save money in the bank press 3)  \n >");
    printf("<           (To transfer money press 4)          \n >");
    printf("<           (To exit press 5)                    \n>");
    printf("Enter your choice: ");
    
    
    scanf("%d", &s);

    switch (s) {
        case 1:
            authentication();
            balance();
            break;
        case 2:
            authentication();
            withdraw();
            break;
        case 3:
            authentication();
            save();
            break;
        case 4:
            authentication();
            transfer();
            break;
        default:
            printf("Bye Bye\n");
            break;
    }
}

while(s!=5);
if(s==5)
{
            exitBank();
            
}

    return 0;

}
