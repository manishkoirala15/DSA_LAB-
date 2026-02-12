#include <stdio.h>

int main() {
    int arr[] = {5, 10, 15, 20, 25};
    int n = 5, key = 15;
    int found = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Element found at index %d\n", i);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Element not found\n");

    return 0;
}
