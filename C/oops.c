#include<stdio.h>
int main(){
    char name[10][50];
    int units[10];
    int amount[10];
    int n;
    printf("Enter the number of users:");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
    int k;
    printf("Enter the name: ");
    scanf("%s", name[i]);
    printf("Enter the number of units: ");
    scanf("%d", &units[i]);
    if(units[i] <= 100){
        amount[i] = 100*30;
    }
    else if(units[i]<=300){
        amount[i] = ((100*30)+(units[i]-100)*50);
    }
    else{
        amount[i] = ((100*30)+(200*50)+(units[i]-300)*70);
    }    
    amount[i] = (amount[i]/100)+200;
  }
    printf("S.No        Name          Units       Bill\n");
    for(int i=0; i<n; i++){
        printf("%d        %s            %d          %d\n", i, name[i], units[i], amount[i]);
    }
    }
    

    
