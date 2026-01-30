#include<stdio.h>
struct word{
    char word[50];
    int length;
};
int main(){
    struct word arr[10];
    printf("Enter the string: ");
    char str[500];
    fgets(str, sizeof(str), stdin);
    int i=0, j=0, k=0;
    arr[i].length = 0;
    while(str[k] != '\0'){ //parse through each letter in the string
        if(str[k] != ' '){ //Check if it is a white space
            arr[i].word[j] = str[k]; //If it is not a white space append it to the word in structure
            j++;
            arr[i].length = j; //Set the length of the word to j
        }
        else{
            arr[i].word[j] = '\0'; //If it is space append it with null character to mark the end of the rd
            i++; // Move to the next structure
            j=0; // Reset the index of the word in the structure
            arr[i].length = 0; //Reset the length of the word
        }
        k++; //Move to the next letter in the string
    }
    arr[i].word[j] = '\0';
    int word_count = i+1;
    int max_idx = 0;
    for(int x=0; x<word_count; x++){
        if(arr[x].length>arr[max_idx].length) max_idx = x;
    }
    printf("The longest word is: %s\n", arr[max_idx].word);
    
}