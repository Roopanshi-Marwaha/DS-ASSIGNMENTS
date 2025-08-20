// Develop a Menu driven program to demonstrate the following operations of Arrays
// ——MENU——- 
// 1.CREATE
// 2. DISPLAY
// 3. INSERT
// 4. DELETE
// 5. LINEAR SEARCH
// 6. EXIT

#include <stdio.h>

int main() {
    int a[20];      
    int length = 0;  // Current number of elements
    int choice, val, pos, i, found;

    do {
        // Display menu
        printf("\n---- MENU ----\n");
        printf("1. CREATE\n");
        printf("2. DISPLAY\n");
        printf("3. INSERT\n");
        printf("4. DELETE\n");
        printf("5. LINEAR SEARCH\n");
        printf("6. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:  // CREATE
                printf("Enter number of elements: ");
                scanf("%d", &length);
                printf("Enter the elements:\n");
                for(i = 0; i < length; i++) {
                    scanf("%d", &a[i]);
                }
                break;

            case 2:  // DISPLAY
                if(length == 0) {
                    printf("Array is empty.\n");
                } else {
                    printf("Array elements: ");
                    for(i = 0; i < length; i++) {
                        printf("%d ", a[i]);
                    }
                    printf("\n");
                }
                break;

            case 3:  // INSERT
                printf("Enter the number to insert: ");
                scanf("%d", &val);
                printf("Enter the position (1 to %d): ", length + 1);
                scanf("%d", &pos);
                if(pos < 1 || pos > length + 1) {
                    printf("Invalid position!\n");
                    break;
                }
                for(i = length; i >= pos; i--) {
                    a[i] = a[i-1];
                }
                a[pos-1] = val;
                length++;
                printf("Element inserted.\n");
                break;

            case 4:  // DELETE
                printf("Enter the position to delete (1 to %d): ", length);
                scanf("%d", &pos);
                if(pos < 1 || pos > length) {
                    printf("Invalid position!\n");
                    break;
                }
                for(i = pos-1; i < length-1; i++) {
                    a[i] = a[i+1];
                }
                length--;
                printf("Element deleted.\n");
                break;

            case 5:  // LINEAR SEARCH
                printf("Enter the number to search: ");
                scanf("%d", &val);
                found = 0;
                for(i = 0; i < length; i++) {
                    if(a[i] == val) {
                        printf("Number %d found at position %d\n", val, i+1);
                        found = 1;
                        break;  
                    }
                }
                if(!found) {
                    printf("Number %d not found in the array.\n", val);
                }
                break;

            case 6:  // EXIT
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    } while(choice != 6);

    return 0;
}