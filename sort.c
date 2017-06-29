#include<stdio.h>

void sort(int *p, int n) {
    int *a, *b, t;
    for (a = p + 1; a;)
        for (b = p + n - 1; b >= a; --b) {
            if (*(b - 1) > *b) {
                t = *(b - 1);
                *(b - 1) = *b;
                *b = t;
            }
        }
}

int main2() {
    int i, a[10];
    for (i = 0; i < 10; i++)
        scanf("%d", a + i);
    sort(a, 10);
    printf("sorted array:\n");
    for (i = 0; i < 10; i++)
        printf("%d", *(a + i));
    return 0;
}
