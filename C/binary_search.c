#include<stdio.h>
int binary_search(int arr[], int high, int low, int key){

    if(low>high){
        return -1;
    }
    int mid = low+(high-low)/2;
    if (arr[mid] == key){
        return mid;
    }
    else if(arr[mid] > key){
        high = mid-1;
        return binary_search(arr, high, low, key);
    }
    else {
        low = mid + 1;
        return binary_search(arr, high, low, key);
    }

}
int main(){
    int n, k;
    int arr[10];
    printf("Enter the length: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    printf("Enter the element to search: ");
    scanf("%d", &k);
    printf("The element is at :%d\n", binary_search(arr, n-1, 0, k));
    return 0;
}