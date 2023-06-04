#include <stdio.h>
#include "gameboard.h"
#include "snake.h"


//Driver function
int main (){
	struct gameboard *board = init_board();
	struct snake *snake = init_snake(board);
	enum direction direction;
	while(!board->game_over){
		print_gameboard(board);
		int c = getchar();
		
		if (c != '\n'){
			if (c == 'q' || snake_out_bounds(snake, board)){
				end_game(board);
				free_board(board);
				free_snake(snake);
			} else if (c == 'w'){
				direction = NORTH;
			} else if (c == 'a'){
				direction = WEST;
			} else if (c == 'd'){
				direction = EAST;
			} else if (c == 's'){
				direction = SOUTH;
			} 
			snake_change_dir(snake, direction);	
			snake_move(snake, board);
			}
	}
	return 0;
}
