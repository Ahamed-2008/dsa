#include<stdio.h>
// int main(){
//     char arr[10];
//     char ld;
//     printf("Enter a string: ");
//     scanf("%s", arr);
//     long int h, x;
//     for(int i=0; arr[i] != '\0'; i++){
//         if (arr[i] != ld){
//         x = 1;
//         x = x<<(arr[i]-97);
//         if (h&x) {
//             printf("Duplicated Letter %c\n", arr[i]);
//                 ld = arr[i];
//         }
//         else {
//             h = h|x;
//         }
//         }
//     }
//     }

int s_len(char s[]){
    int count = 0;
    for(int i=0; s[i] != '\0'; i++){
        count++;
    }
    return count;
}

void swap(int x, int y, char *s){
    char temp;
    temp = s[x];
    s[x] = s[y];
    s[y] = temp;
}

void permutation(char s[], int k){
    static int A[10] = {0};
    static char Res[10];
    if(s[k] == '\0'){
        printf("%s\n", Res);
    }
    else{
        for(int i=0; s[i] != '\0'; i++){
            if(A[i] != 1){
                Res[k] = s[i];
                A[i] = 1;
                permutation(s, k+1);
                A[i] = 0;
            }
        }
    }
    
}

void perm(char s[], int l){
    int h = s_len(s) - 1;
    if ( l == h ) printf("%s\n", s);
    else{
      for (int i = l;i<=h ; i++) {
        swap(i, l, s);
        perm(s, l + 1);
        swap(i, l, s);
      }
    }
}

int main(){
    char a[4];
    printf("Enter a string: ");
    scanf("%s", a);
    perm(a, 0);
    return 0;
}