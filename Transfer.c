void Transfer() {
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
                        UpdateBalance(fp, &a);
                        UpdateBalance(fp2, &recipient);
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
