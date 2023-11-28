int main() {
    char choice;

    do {
        u customer;

        printf("Enter Customer Details:\n");

        printf("Name: ");
        scanf("%19s", customer.name);

        printf("Date of Birth (YYYY-MM-DD): ");
        scanf("%10s", customer.dob);

        printf("Phone Number: ");
        scanf("%lld", &customer.phoneno);

        printf("Aadhar Number: ");
        scanf("%lld", &customer.aadharno);

        printf("Account Number: ");
        scanf(" %6[^\n]%*c", customer.account);  // Consume newline characters

        printf("Initial Balance: ");
        scanf("%d", &customer.balance);

        FILE *fp = fopen("text.txt", "ab");
        if (fp == NULL) {
            printf("Error opening file");
            return 1;
        }

        fwrite(&customer, sizeof(customer), 1, fp);

        fclose(fp);

        printf("Customer details saved to text.txt successfully.\n");

        printf("Do you want to enter another customer? (y/n): ");
        scanf(" %c", &choice);  // Notice the space before %c to consume any leftover newline character

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
