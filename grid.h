
#define GRID_SIZE 6
#define EMPTY 0
#define O 1
#define X 2


void init_grid(int grid[GRID_SIZE][GRID_SIZE]);
void display_grid(int grid[GRID_SIZE][GRID_SIZE]);
int column_height(int grid[GRID_SIZE][GRID_SIZE], int column);
int put_token(int grid[GRID_SIZE][GRID_SIZE], int column, int row, int player);

