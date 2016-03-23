#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>

#define N 50

/* As I am using the matrix as a vector, because a vector is faster to acess than a matrix,
  there is a function to return the value of the array as if it were a matrix with : 
  matrix[i][j] = array[i * N + j] */
char getCharInPosition(int i, int j, char *array){
    int index = i * N + j;
    return array[index];
}

/* Function that takes as parameters: initial position of the search[row, col], 
   direction to do the search [d_row][d_col], the word to search and 
   search space[*array] */
bool wordSearch(int row, int col, int d_row, int d_col, char *word, char *array){
    for (int i = 0; i < strlen(word); i++){
        if (word[i] != getCharInPosition(row, col, array)){
            return false;
        }
        row += d_row;
        col += d_col;
    }
    return true;
}

/* Function to load a txt file into a array */
void txtToArray(char *file, char *array){
    FILE *f = fopen(file, "r");
    if (!f){
        printf ("Error opening %s!\n", file);
        exit(1);
    }
    int i = 0;
    while (!feof(f)){
        char c = fgetc(f);
        if (!isspace(c)){
            array[i] = c;
            i++;
        }
    }
    fclose(f);  
}

/* Function to print the coordinates of a word that is found in the puzzle */
void printCoordinates(int row, int col, int d_row, int d_col, char *word){
    for (int i = 0; i < strlen(word); i++){
        printf("[%d][%d]\n", row, col);
        row += d_row;
        col += d_col;
    }
}

int main(int argc, char const *argv[]){

    // Char matrix that contains the words to search in the puzzle array
    char *wordBank[] = {
        "FEBRUARY", "AUGUST", "JUNE", "JANUARY",
        "DECEMBER", "NOVEMBER", "APRIL", "SEPTEMBER",
        "JULY", "MARCH", "MAY", "OCTOBER"
    };
    
    char puzzle[2500]; // Array that contains the characters from the txt file
    txtToArray("puzzle.txt", puzzle); // Loading the txt file into the array

    for (int z = 0; z < 12; z++){
       for (int i = 0; i < 50; i++){
            for (int j = 0; j < 50; j++){
                
                // Searching horizontally
                if (wordSearch(i, j, 0, 1, wordBank[z], puzzle)){
                    printf("\nFound: %s\n", wordBank[z]);
                    printf ("Coordinates:\n");
                    printCoordinates(i, j, 0, 1, wordBank[z]);
                }

                // Searching vertically
                if (wordSearch(i, j, 1, 0, wordBank[z], puzzle)){
                    printf("Found: %s\n", wordBank[z]);
                    printf ("Coordinates:\n");
                    printCoordinates(i, j, 1, 0, wordBank[z]);
                }
                
                // Searching diagonally top-down
                if (wordSearch(i, j, 1, 1, wordBank[z], puzzle)){
                    printf("\nFound: %s\n", wordBank[z]);
                    printf ("Coordinates:\n");
                    printCoordinates(i, j, 1, 1, wordBank[z]);
                }
                
                // Searching horizontally (reverse)
                if (wordSearch(i, j, 0, -1, wordBank[z], puzzle)){
                    printf("\nFound: %s\n", wordBank[z]);
                    printf ("Coordinates:\n");
                    printCoordinates(i, j, 0, -1, wordBank[z]);
                }
                
                // Searching vertically (reverse)
                if (wordSearch(i, j, -1, 0, wordBank[z], puzzle)){
                    printf("\nFound: %s\n", wordBank[z]);
                    printf ("Coordinates:\n");
                    printCoordinates(i, j, -1, 0, wordBank[z]);
                }
                
                // Searching diagonally top-down (reverse)
                if (wordSearch(i, j, -1, -1, wordBank[z], puzzle)){
                    printf("\nFound: %s\n", wordBank[z]);
                    printf ("Coordinates:\n");
                    printCoordinates(i, j, -1, -1, wordBank[z]);
                }

                // Seaching diagonally down-top
                if (wordSearch(i, j, -1, 1, wordBank[z], puzzle)){
                    printf("\nFound: %s\n", wordBank[z]);
                    printf ("Coordinates:\n");
                    printCoordinates(i, j, -1, 1, wordBank[z]);
                }

                // Seaching diagonally down-top (reverse)
                if (wordSearch(i, j, 1, -1, wordBank[z], puzzle)){
                    printf("\nFound: %s\n", wordBank[z]);
                    printf ("Coordinates:\n");
                    printCoordinates(i, j, 1, -1, wordBank[z]);
                }        
            }
        }  
    }

    printf("\n");
    
    return 0;
}