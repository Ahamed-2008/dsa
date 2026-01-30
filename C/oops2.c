#include<stdio.h>
#include<stdlib.h>
struct marks{
    char name[50];
    int mat, eng, oops, dsa;
};
int main(){
    int n;
    struct marks *arr;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    arr = (struct marks *)malloc(sizeof(struct marks)*n);
    for(int i=0; i<n; i++){
        printf("Enter the name: ");
        scanf("%s", arr[i].name);
        printf("Enter the marks(mat eng oops dsa): ");
        scanf("%d %d %d %d", &arr[i].mat, &arr[i].eng, &arr[i].oops, &arr[i].dsa);
    }
    for(int i=0; i<n; i++){
        printf("The marks of the students are: ");
        printf("%s: ", arr[i].name);
        printf("maths: %d, eng: %d, oops: %d, dsa: %d\n", arr[i].mat, arr[i].eng, arr[i].oops, arr[i].dsa);
    }
    return 0;
    
}