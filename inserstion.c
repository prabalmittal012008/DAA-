#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int n;
    int i, j, key;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int *arr = (int*)malloc(n * sizeof(int));

    srand(time(NULL));


    for (i = 0; i < n; i++){
        arr[i] = rand();
    }

    clock_t start = clock();

    for (i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    clock_t end = clock();

    float time_taken = (float)(end - start) / CLOCKS_PER_SEC;

    printf("Input Size: %d\n", n);
    printf("Time taken: %.4f seconds\n",time_taken);

    free(arr);

    return 0;
}