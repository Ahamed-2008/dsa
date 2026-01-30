#include<stdio.h>



int maxi(int arr[], int n){
    int m = arr[0];
    for(int i=0; i<n; i++){
        if(m < arr[i]) m = arr[i];
    }
    return m;
}
int main(){
    int arr[10];
    int lsa[10];
    int rsa[10];
    int n;
    //Get the array Input
    printf("Enter the length of the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    //Find the largest element in the array
    int max = maxi(arr, n);
    //Append the elements before the max element to lsa
    int k=0;
    int lsa_l = 0;
    while(arr[k] != max) {
        lsa[lsa_l] = arr[k];
        k++;
        lsa_l++;
    }
    //Append the elements after the max element to rsa
    k++;
    int rsa_l = 0;
    while(k<n){
        rsa[rsa_l] = arr[k];
        k++;
        rsa_l++;
    }
    int l_vol;
    l_vol = (maxi(lsa, lsa_l)*(lsa_l));
    for(int i=0; i<lsa_l; i++){
        if(lsa[i] != maxi(lsa, lsa_l)){
            l_vol -= lsa[i];
        }
    }

    int r_vol;
    r_vol = (maxi(rsa, rsa_l)*(rsa_l));
    for(int i=0; i<rsa_l; i++){
        if(rsa[i] != maxi(rsa, rsa_l)){
            r_vol -= rsa[i];
        }
    }
    
    printf("The volume of water is %d\n", l_vol+r_vol);
    return 0;
    
}