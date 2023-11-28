
void Withdraw() {
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
                UpdateBalance(fp, &a);
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
