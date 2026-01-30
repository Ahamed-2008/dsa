#include <stdio.h>
#include <string.h>

int main() {
    char arr[100][50];
    char str[200];
    printf("Enter the string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;

    int k = 0; // Index for the input string 'str'
    int i = 0; // Index for the word count (rows)
    int j = 0; // Index for the character in the current word (columns)

    while (str[k] != '\0') {
        if (str[k] != ' ') {
            // Copy character to the current word
            arr[i][j] = str[k];
            j++;
        } else {
            // We hit a space! Finish the current word
            arr[i][j] = '\0'; 
            i++;           // Move to the next row (next word)
            j = 0;         // Reset character index to start of new word
        }
        k++;
    }
    
    // Don't forget to null-terminate the very last word!
    arr[i][j] = '\0';
    int total_words = i + 1;

    // Assuming total_words is the number of words you stored in arr[][]
    for (int i = 0; i < total_words; i++) {
        int isDuplicate = 0;
    
        // Inner loop: Check all words BEFORE the current word 'i'
        for (int j = 0; j < i; j++) {
            if (strcmp(arr[i], arr[j]) == 0) {
                isDuplicate = 1; // We've seen this word before!
                break;
            }
        }
    
        // If it's NOT a duplicate, it's the first time we're seeing it
        if (!isDuplicate) {
            // Now, to satisfy your assignment, count how many times 
            // this unique word appears in the WHOLE list
            int count = 0;
            for (int k = 0; k < total_words; k++) {
                if (strcmp(arr[i], arr[k]) == 0) {
                    count++;
                }
            }
            
            // Print the unique word and its count
            printf("%s:%d\n", arr[i], count);
            

        }
    }
}