#include<stdio.h>

int main() {

    printf("Enter the number of elements");
    int n,i;
    scanf("%d",&n);

    int arr[n];
      printf("Input elements");
      for(i=n-1;i>=0;i--){
        scanf("%d",&arr[i]);
      }

    printf("The elements are:");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
return 0;
}