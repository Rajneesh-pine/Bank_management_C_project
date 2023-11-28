
bool PrintBalanceForUser(FILE *fp, const char *targetName) {
    u a;
    while (fread(&a, sizeof(a), 1, fp) == 1) {
        if (strcmp(a.name, targetName) == 0) {
            printf("Balance for user %s: %d\n", a.name, a.balance);
            return true;
        }
    }
    return false;
}
