#include <stdio.h>
#include <stdlib.h>

typedef struct vector {
  int size;
  int arr[];
}
vector;


int main() {
    int n = 3;
    printf("\nSize of vector* %d - %d", sizeof(vector * ), sizeof(vector));
    vector *ptr = (vector * ) malloc(sizeof(vector) + n * sizeof(int));
    // This implies 'ptr->arr' can hold `n` integers.

    printf("Enter the elements (space/newline separated): ");
    for (int i = 0; i < n; i++)
        scanf("%d", ptr -> arr + i);

    printf("Given array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", ptr -> arr[i]);
    printf("\n");

    free(ptr);
    return 0;
}