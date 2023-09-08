#include "common.h"
#include <stdio.h>
#include <stdbool.h>
#define MAXROW 20
#define MAXCOL 60

typedef enum state {DEAD, ALIVE} State;

typedef State Grid[MAXROW + 2][MAXCOL + 2];



/*CopyMap: copy newmap into map.
  pre: the grid newmap has the current Life configuration
  post: the grid map has a copy of newmap*/
void CopyMap(Grid map, Grid newmap){
    int row, col;
    for(row = 0; row <= MAXROW + 1; row++){
        for(col = 0; col <= MAXCOL + 1; col++){
            map[row][col] = newmap[row][col];
        }
    }
}
/*UserSaysYes: TRUE if the user wants to continue execution.
  pre: none.
  post: returns TRUE if the user's answer begins with either y or Y. FALSE if the user 
        responds with any response beginning with either n or N*/
bool UserSaysYes(void){
    int c;
    printf(" (y,n)");
    do {
        while ((c = getchar()) == '\n')
        ; // ignore new line character ?? anlamadim
        {
            if( c == 'y' || c == 'Y' || c == 'n' || c == 'N'){
                return(c == 'y' || c == 'Y');
            }
            printf("please respond by tuping one of the letters y or n\n");
        }
        
    }while(1);
}


/*Initialize grid map
  Pre: none
  Post: all the cells in the grid map have been set to inital configuration of living cells*/
void Initialize(Grid map){
    int row, col; //coordinates of a cell
    printf("this program is a simulation of game of life. \n"
            "the grid has a size of %d rows and\n"
            "%d columns.\n", MAXROW, MAXCOL);
    for(row = 0; row <= MAXROW + 1; row++){
        for(col = 0; col <= MAXCOL; col++){
            map[row][col] = DEAD; //set all cells empty, including the hedge.
        }
    }
    printf("on each line give a pair of coordinates for a a living cell. \n"
            "terminate the list with the special pair 0 0. \n");
    scanf("%d %d", &row, &col);
    while(row != 0 || col != 0){
        if(row >= 1 && row <= MAXROW && col >= 1 && col <= MAXCOL){
            map[row][col] = ALIVE;}
        else{
            printf("values are not within range.");}
        scanf(" %d %d", &row, &col);
        
    }
    while (getchar() != '\n'); //discard remaining characters.
}

/*NeighborCount. count neighbors of row,col
  pre: the pair row, col is a valid cell in a Life program
  post: the function returns the number of living neighbors of the living cell.*/
int NeighborCount(Grid map, int row, int col){
    int i, j;
    int count = 0;
    for(i = row - 1; i <=row + 1; i++){
        for(j = col - 1; j <= col +1; j++){
            if(map[i][j] == ALIVE){
                count ++;
            }
        }
    }
    if(map[row][col] == ALIVE){
        count--;
        }
    
    return count;
}

/*WriteMap: display grid map.
  Pre: The rectangular array map contains the current Life configuration.
  Post: The current Life configuration is written for the user. */
void WriteMap(Grid map){
    int row, col;
    putchar('\n');
    putchar('\n');
    for(row = 1; row <= MAXROW; row++){
        for(col =1; col <= MAXCOL; col++){
            if(map[row][col] == ALIVE){
                putchar('*');
            }
            else{
                putchar('-');
            }
        }
    }
}