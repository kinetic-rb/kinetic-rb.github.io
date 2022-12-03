#import<cstdio>
int main(){puts(__builtin_ia32_rdtsc()&1?"food":"paimeng");}