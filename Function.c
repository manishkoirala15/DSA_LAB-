#include <stdio.h>

int add(int x, int y) {
    return x + y;
}

int main() {
    int a, b, result;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    result = add(a, b);

    printf("Sum = %d\n", result);

    return 0;
}
