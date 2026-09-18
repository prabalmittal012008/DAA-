#include<stdio.h>

int main() {

    int n,i;
    printf("Enter the number of elements");
    scanf("%d",&n);

    int arr1[n];
    int arr2[n];
    printf("Input elements");
    for(i=0;i<n;i++){
        scanf("%d",&arr1[i]);
    }

    for(i=0;i<n;i++){
        arr2[i]=arr1[i];
    }

    printf("The elements of the first array are:");
    for(i=0;i<n;i++){
        printf("%d ",arr1[i]);
    }

    printf("\n");
    printf("The elements of the second array are");
    for(i=0;i<n;i++){
        printf("%d ",arr2[i]);
}
}