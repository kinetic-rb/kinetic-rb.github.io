main() {
    long n;
    scanf("%ld", &n);
    if (!(n % 3) && (n & 4)) {
        puts("drew.");
        return 0;
    }
    if (n % 4) {
        puts("xiaoa wins.");
        return 0;
    }
    puts("uim wins.");
}