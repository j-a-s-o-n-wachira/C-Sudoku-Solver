// A simple sudoku solver that uses the back-tracking algorithm

#include <stdio.h>
#include <stdbool.h>
#define N 9

// Looks for empty positions
bool find_empty(int grid[N][N], int *row, int *col){
	for(*row = 0;*row < N;(*row)++){
		for(*col = 0;*col < N; (*col)++){
			if(grid[*row][*col] == 0){
				return true;
			}

		}

	}
	return false;


}

// Checks if the current placement is a valid entry
bool is_valid(int grid[N][N], int row, int col){
	//Check if valid in row 
	for(int i=0;i<N;i++){
		if(grid[row][i] == grid[row][col] && i != col){
			return false;
		}
	}	
	
	// Check if valid in column 
	for(int j=0;j<N;j++){
		if(grid[j][col] == grid[row][col] && j != row){
			return false;
		}
		
	}
	
	// Check if valid in sub-grid
	int box_x = (col / 3)*3;
	int box_y = (row / 3)*3;
	for(int i=box_y;i<box_y+3;i++){
		for(int j=box_x;j<box_x;j++){
			if(grid[i][j] == grid[row][col]){
				if(i == row && j == col){
					continue;
				}
				return false;
			}
		}
	}
		
	return true;

}

// Prints the board
void print(int grid[N][N]){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			printf("%d ", grid[i][j]);
			if(j == 8){
				printf("\n");
			}
		
		}
	}
}

// Recursively solves the puzzle
bool solve(int grid[N][N]){
	int row, col;
	
	//Base case if all cells are filled
	if(!find_empty(grid, &row, &col)){
		return true;
	}

	for(int k = 1;k <= N;k++){
		grid[row][col] = k;
		if(is_valid(grid, row, col)){
			if(solve(grid)){
				return true;
			}
		}
		grid[row][col] = 0;
	}

	//No solution found
	return false;
}




int main(){
	int grid[N][N] = { { 5, 3, 0, 0, 7, 0, 0, 0, 0 },
                       { 6, 0, 0, 1, 9, 5, 0, 0, 0 },
                       { 0, 9, 8, 0, 0, 0, 0, 6, 0 },
                       { 8, 0, 0, 0, 6, 0, 0, 0, 3 },
                       { 4, 0, 0, 8, 0, 3, 0, 0, 1 },
                       { 7, 0, 0, 0, 2, 0, 0, 0, 6 },
                       { 0, 6, 0, 0, 0, 0, 2, 8, 0 },
                       { 0, 0, 0, 4, 1, 9, 0, 0, 5 },
                       { 0, 0, 0, 0, 8, 0, 0, 7, 9 } };
	
	printf("Initial Sudoku\n");
	print(grid);
	if(solve(grid)){
		printf("_________________________\n\nSolved Sudoku:\n");
		print(grid);
		return 0;
	}
	printf("No solution exists\n");
	return 1;
}





 





