#include<stdio.h>
void TOH(int n, int source, int destination, int auxilliary){
    if (n == 1){
        printf("(%d, %d)\n", source, destination);
    }
    else if(n > 1){
        TOH(n-1, source, auxilliary, destination);
        TOH(1, source, destination, auxilliary);
        TOH(n-1, auxilliary, destination, source);
    }
}
int main(){
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    TOH(n, 1, 3, 2);
}