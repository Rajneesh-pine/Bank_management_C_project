#include "bank_man.h"
int Main() {

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
            Authentication();
            Balance();
            break;
        case 2:
            Authentication();
            Withdraw();
            break;
        case 3:
            Authentication();
            Save();
            break;
        case 4:
            Authentication();
            Transfer();
            break;
        default:
            printf("Bye Bye\n");
            break;
    }
}

while(s!=5);
if(s==5)
{
            ExitBank();
            
}

    return 0;

}
