
void UpdateBalance(FILE *fp, const u *user) {
    fseek(fp, -sizeof(u), SEEK_CUR);
    fwrite(user, sizeof(u), 1, fp);
}
