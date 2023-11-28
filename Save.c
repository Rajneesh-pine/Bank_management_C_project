
void Save() {
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
