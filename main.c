/*  Codé par CHRZASZCZ Naulan.
        Groupe: B1.

    Note: Monsieur, ne m'en voulait pas, j'ai mis le code en anglais pour la modularité, l'extensibilité et la clarté.
            J'ai partitionné le code pour la même raison cité plus haut. */
#include <stdio.h>

#include "grid.h"

#define TOTAL_PLAYER 2
#define TRUE 1
#define FALSE 0


int win_check(int grid[GRID_SIZE][GRID_SIZE], int column, int row, int player);
int column_scanf(int player);
void launch_test();

int main()
{
    launch_test();
    int grid[GRID_SIZE][GRID_SIZE];

    int current_player;
    int nbTours = 0;
    int running = TRUE;
    

    init_grid(grid); 
    display_grid(grid);
    while (nbTours != GRID_SIZE*GRID_SIZE && running)
    {
        current_player = 0;
        while (current_player < TOTAL_PLAYER && running)
        {
            printf("Nombre de tours: %d", nbTours);
            
            int column = column_scanf(current_player + 1);
            int row = column_height(grid, column);

            int isPuted = put_token(grid, column, row, current_player + 1);
            if (!isPuted) {
                printf("Vous ne pouvez pas vous placez ici.");
            } else {
                running = !win_check(grid, column, row, current_player + 1);
                current_player++;
                nbTours++;
            }

            display_grid(grid);
        }
    }
    printf("\nLe joueur %d a gagné la partie avec %d tours !\n", current_player, nbTours);

    return 0;
}

/*  
 * verifie_gagne(int grid[][], int column, int row, int player); -> TRUE || FALSE
 *       Permet de verifié si lors qu'un joueur posse sont pion, il verifie si il y a un alignement. 
 */
int win_check(int grid[GRID_SIZE][GRID_SIZE], int column, int row, int player) 
{
    int counter = 0;
    int x = column; int y = row;
    
    // Verification horizontal vers la droite.
    while (x+counter < GRID_SIZE && grid[y][x+counter] == player) counter++;

    // Verification horizontal vers la gauche.
    x = (column == 0) ? column : column-1;
    while (counter <= 4 && x >= 0 && grid[y][x] == player) {
        counter++;
        x--;
    }

    counter = (counter < 4) ? 0 : counter;
    x = column; y = row;
    // Verification vertical
    while (counter <= 4 && y+counter < GRID_SIZE && grid[y+counter][x] == player) counter++;

    counter = (counter < 4) ? 0 : counter;
    x = column; y = row;
    // Verification diagonal droite
    while (counter <= 4 && (x >= 0 && y+counter < GRID_SIZE) && grid[y+counter][x] == player) {
        counter++;
        x--;
    }

    x = (column == 0) ? column : column-1; y--;
    while (counter <= 4 && (x < GRID_SIZE && y >= 0) && grid[y][x] == player) {
        counter++;
        x++; y--;
    }

    counter = (counter < 4) ? 0 : counter;
    x = column; y = row;
    // Verification diagonal gauche
    while (counter <= 4 && (x+counter < GRID_SIZE && y+counter < GRID_SIZE) && grid[y+counter][x+counter] == player) counter++;

    x--; y--;
    while (counter <= 4 && (x >= 0 && y >= 0) && grid[y][x] == player) {
        counter++;
        x--; y--;
    }

    return (counter >= 4) ? TRUE : FALSE;
}

/* 
 * scan_colonne(int grid[][], int player); -> int
 *      Permet d'entrée selon le joueur, quel colonne sera t-il dans la grille 
 */
int column_scanf(int player)
{
    int input;
    do {
        printf("\n[Joueur_%d] Entrez une colonne > ", player);
        scanf("%d", &input);
    } while (input > 0 && input > GRID_SIZE);

    return input-1;
}



void launch_test()
{
    int grid[GRID_SIZE][GRID_SIZE];

    init_grid(grid);
    printf("Test victoire horizontal");
    put_token(grid, 5, 0, O);
    put_token(grid, 5, 1, O);
    put_token(grid, 5, 2, O);
    put_token(grid, 5, 3, O);
    printf((win_check(grid, 5, 0, O) == TRUE) ? "Test reussie !" : "(!) Fail !");

    printf("\n");

    init_grid(grid);
    printf("Test victoire vertical");
    put_token(grid, 0, 0, X);
    put_token(grid, 1, 0, X);
    put_token(grid, 2, 0, X);
    put_token(grid, 3, 0, X);
    printf((win_check(grid, 0, 0, X) == TRUE) ? "Test reussie !" : "(!) Fail !");

    printf("\n");

    init_grid(grid);
    printf("Test victoire diagonal droite");
    put_token(grid, 0, 5, O);
    put_token(grid, 1, 4, O);
    put_token(grid, 2, 3, O);
    put_token(grid, 3, 2, O);
    printf((win_check(grid, 3, 2, O) == TRUE) ? "Test reussie !" : "(!) Fail !");

    printf("\n");

    init_grid(grid);
    printf("Test victoire diagonal gauche");
    put_token(grid, 2, 2, X);
    put_token(grid, 3, 3, X);
    put_token(grid, 4, 4, X);
    put_token(grid, 5, 5, X);
    printf((win_check(grid, 5, 5, X) == TRUE) ? "Test reussie !" : "(!) Fail !");

    printf("\n");
}
