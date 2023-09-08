#include <stdio.h>
#include "common.h" // coomon include files and definitions
#include "life.h"   // life's defines typedefs and prototypes
#include <stdbool.h>  

/* SIMULATION OF GAME OF LIFE ON A BOUNDED GRID
    PRE: THE USER MUST SUPPLY AN INITAL CONFIGURATION OF LIVING CELLS
    POST: THE PROGRAM PRINTS A SEQUENCE OF MAPS SHOWING THE CHANGES IN THE 
    CONFIGURATION OF LIVING CELLS ACCORDING YO THE RULES OF GAME OF LIFE.
    USES: FUNCTIONS INITIALIZE, WRITEMAP, NEIGHBORCOUNT, USERSAYSYES*/
int main(){
    int row, col;
    Grid map;       // current generation
    Grid newmap;    // next generation
    Initialize(map);
    WriteMap(map);
    printf("This is the inital condition you have chosen. \n"
            "Press <Enter> the continue. \n");
    while (getchar() != '\n')
    ;
    do
    {
      for(row = 1; row <= MAXROW; row++){       
        for(col = 1; col <= MAXCOL; col++){
            switch (NeighborCount(map, row, col))
            {
            case 0:
            case 1:
                newmap[row][col] = DEAD;
                break;
            case 2:
                newmap[row][col] = map[row][col];
                break;
            case 3:
                newmap[row][col] = ALIVE;
                break;
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
                newmap[row][col] = DEAD;
                break;}
            }
        }
        CopyMap(map, newmap);
        WriteMap(map);
        printf("Do you wish to continue viewing the new generations");
    } while (UserSaysYes());
    return 0;
}