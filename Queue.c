#include<stdio.h>
#define MAX 5

int lq[MAX], cq[MAX];
int lf = -1, rf = -1, lc = -1, rc = -1;

// Linear Queue Functions
void linearEnqueue(int x) {
    if (rf == MAX - 1) {
        printf("Linear Queue is full\n");
    } else {
        if (lf == -1) lf = 0;
        rf++;
        lq[rf] = x;
        printf("Inserted %d in Linear Queue\n", x);
    }
}

void linearDequeue() {
    if (lf == -1 || lf > rf) {
        printf("Linear Queue is empty\n");
    } else {
        printf("Deleted %d from Linear Queue\n", lq[lf]);
        lf++;
    }
}

void displayLinearQueue() {
    if (lf == -1 || lf > rf) {
        printf("Linear Queue is empty\n");
    } else {
        printf("Linear Queue elements: ");
        for (int i = lf; i <= rf; i++) {
            printf("%d ", lq[i]);
        }
        printf("\n");
    }
}

// Circular Queue Functions
void circularEnqueue(int x) {
    if ((rc + 1) % MAX == lc) {
        printf("Circular Queue is full\n");
    } else {
        if (lc == -1) lc = 0;
        rc = (rc + 1) % MAX;
        cq[rc] = x;
        printf("Inserted %d in Circular Queue\n", x);
    }
}

void circularDequeue() {
    if (lc == -1) {
        printf("Circular Queue is empty\n");
    } else {
        printf("Deleted %d from Circular Queue\n", cq[lc]);
        if (lc == rc) {
            lc = -1;
            rc = -1;
        } else {
            lc = (lc + 1) % MAX;
        }
    }
}

void displayCircular() {
    if (lc == -1) {
        printf("Circular Queue is empty\n");
    } else {
        printf("Circular Queue elements: ");
        int i = lc;
        while (1) {
            printf("%d ", cq[i]);
            if (i == rc) break;
            i = (i + 1) % MAX;
        }
        printf("\n");
    }
}

// Main Function
int main() {
    int ch, x;
    do {
        printf("\n1. Enqueue in Linear Queue\n");
        printf("2. Dequeue from Linear Queue\n");
        printf("3. Display Linear Queue\n");
        printf("4. Enqueue in Circular Queue\n");
        printf("5. Dequeue from Circular Queue\n");
        printf("6. Display Circular Queue\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &x);
                linearEnqueue(x);
                break;
            case 2:
                linearDequeue();
                break;
            case 3:
                displayLinearQueue();
                break;
            case 4:
                printf("Enter the element to enqueue: ");
                scanf("%d", &x);
                circularEnqueue(x);
                break;
            case 5:
                circularDequeue();
                break;
            case 6:
                displayCircular();
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(ch != 7);

    return 0;
}
