#include <stdio.h>
#include <string.h>

#define MAX 100

struct Student {
    int roll;
    char name[50];
    float marks;
};

struct Student s[MAX];
int count = 0;

void addStudent() {
    printf("\nEnter Roll: ");
    scanf("%d", &s[count].roll);

    printf("Enter Name: ");
    scanf("%s", s[count].name);

    printf("Enter Marks: ");
    scanf("%f", &s[count].marks);

    count++;
    printf("Student Added Successfully!\n");
}

void displayStudent() {
    if(count == 0) {
        printf("\nNo records found.\n");
        return;
    }

    printf("\n--- Student Records ---\n");
    for(int i = 0; i < count; i++) {
        printf("Roll: %d | Name: %s | Marks: %.2f\n",
               s[i].roll, s[i].name, s[i].marks);
    }
}

void searchStudent() {
    int roll, found = 0;
    printf("\nEnter Roll to Search: ");
    scanf("%d", &roll);

    for(int i = 0; i < count; i++) {
        if(s[i].roll == roll) {
            printf("Record Found!\n");
            printf("Name: %s\nMarks: %.2f\n",
                   s[i].name, s[i].marks);
            found = 1;
            break;
        }
    }

    if(!found) {
        printf("Record Not Found.\n");
    }
}

int main() {
    int choice;

    do {
        printf("\n===== Student Management System =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addStudent(); break;
            case 2: displayStudent(); break;
            case 3: searchStudent(); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }

    } while(choice != 4);

    return 0;
}
