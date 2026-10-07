#include <stdio.h>

#define MAX 100

int arr[MAX], size=0;

void create () {
printf("Enter number of elements : ");
scanf("%d", &size);
if(size > MAX) {
   printf("Size exceeds max limit.\n");
   return;
}
printf("Enter %d elements:\n", size);
int i;
for(i=0; i <size; i++)
scanf("%d", &arr[i]);
}

void display() {
if(size == 0) {
   printf("Array is empty.\n");
   return;
}
printf("Array elements: ");
int i;
for(i = 0; i< size; i++)
  printf("%d ", arr[i]);
printf("\n");
}

void insert () {
   int pos, value;
   if (size == MAX) {
       printf("Array is full.\n");
       return;
   }
   printf("Enter position to insert (0 to %d): ", size);
   scanf("%d", &pos);
   if(pos<0 || pos > size) {
       printf("Invalid position.\n");
       return;
   }
   printf("Enter value to insert: ");
   scanf("%d", &value);
   int i;
   for(i =size; i > pos; i--)
     arr[i] = arr[i -1];


   arr[pos] = value;
   size++;
   printf("Inserted successfully!\n");
}

void delete_pos() {
   int pos;
   if(size == 0) {
       printf("Array is empty. \n");
       return;
   }
   printf("Enter position to delete (0 to %d): ", size - 1);
   scanf("%d", &pos);
   if(pos < 0 || pos >= size) {
       printf("Invalid position.\n");
       return;
   }
   int i;
   for (i= pos; i < size -1; i++)
     arr[i] = arr [i + 1];


   size--;
   printf("Deleted successfully.\n");
}

void linear_search() {
   int key, found = 0;
   printf("Enter value to search: ");
   scanf("%d", &key);
   int i;
   for(i = 0; i < size; i++) {
       if(arr[i] == key) {
           printf("Element found at position %d\n", i);
           found = 1;
           break;
       }
   }
   if (!found)
     printf("Element not found.\n");
}

void binary_search() {
   int key, low = 0, high = size -1, mid;
   printf("Note: Array must be sorted.\n");
   printf("Enter value to search: ");
   scanf("%d", &key);


   while (low <= high) {
       mid = (low + high) / 2;
       if(arr[mid] == key) {
           printf("Element found at position %d", mid);
           return;
       } else if (key < arr[mid])
          high = mid - 1;
       else
          low = mid +1;
   }
   printf("Element not found.\n");
}

int main() {
   int choice;

   do {
       printf("\n---MENU---\n");
       printf("1. Create Array\n");
       printf("\n2. Display Array\n");
       printf("\n3. Insert at position\n");
       printf("\n4. Delete position\n");
       printf("\n5. Linear Search\n");
       printf("\n6. Binary Search\n");
       printf("\n0. Exit\n");
       printf("Enter your choice: ");
       scanf("%d", &choice);


       switch(choice) {
       case 1: create(); break;
       case 2: display(); break;
       case 3: insert(); break;
       case 4: delete_pos(); break;
       case 5: linear_search(); break;
       case 6: binary_search(); break;
       case 0: printf("Exiting program.\n"); break;
       default: printf("Invalid choice. Try again.\n");
   }
   } while (choice != 0);
   return 0;
}
