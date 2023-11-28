
void Balance() {
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
