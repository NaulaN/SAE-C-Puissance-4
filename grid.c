#include <stdio.h>

#define GRID_SIZE 6
#define EMPTY 0
#define O 1
#define X 2
#define TRUE 1
#define FALSE 0


/*
 *  init_grid(int grid[][]); -> void
 *      Remplie l'array par des cases vide.
 */
void init_grid(int grid[GRID_SIZE][GRID_SIZE])
{
    for (int row = 0; row < GRID_SIZE; row++)
        for (int column = 0; column < GRID_SIZE; column++)
            grid[row][column] = EMPTY;
}

/*
 *  affiche_grille(int grid[][]); -> void
 *      Affiche les données de facons visuelle.
 */
void display_grid(int grid[GRID_SIZE][GRID_SIZE])
{    
    for (int n = 1; n <= GRID_SIZE; n++)
        printf(" %d", n);
    printf("\n");

    for (int row = 0; row < GRID_SIZE; row++) {
        for (int column = 0; column < GRID_SIZE; column++) {
            printf("|");
            if (grid[row][column] == EMPTY)
                printf(" ");
            else if (grid[row][column] == X)
                printf("X");
            else if (grid[row][column] == O)
                printf("O");
        }
        printf("|\n");
    }
        
}

/*
 *  hauteur_colonne(int grid[][], int column); -> int
 *      Retourne la valeurs libre selon la colonne.
 */
int column_height(int grid[GRID_SIZE][GRID_SIZE], int column) 
{
    int i = GRID_SIZE-1;
    while (i >= 0 && grid[i][column] != EMPTY)
        i--;
    
    return i;
}

/*
 *  place_jeton(int grid[][], int column, int player)
 *      Place le jeton selon la colonne entrée.
 */
int put_token(int grid[GRID_SIZE][GRID_SIZE], int column, int row, int player)
{
    if (row < 0) {
        return FALSE;
    } else {
        grid[row][column] = player;
        return TRUE;
    }
}
