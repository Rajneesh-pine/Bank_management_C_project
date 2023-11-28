
int Authentication() {
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
