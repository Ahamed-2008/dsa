#include<stdio.h>

void insertion_sort(int arr[], int n){
    int key;
    int i, j;
    for(i=0; i<n; i++){
        key = arr[i];
        j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
int main(){
    int n;
    int arr[10];
    printf("Enter the size: "); scanf("%d", &n);
    printf("Enter the elements: ");
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    insertion_sort(arr, n);
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}