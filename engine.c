#include <stdio.h>
#include "gameboard.h"
#include "snake.h"


//Driver function
int main (){
	struct gameboard *board = init_board();
	struct snake *snake = init_snake(board);
	while(!board->game_over){
		print_gameboard(board);
		int c = getchar();
		
		if (c == 'q' || snake_out_bounds(snake, board)){
			end_game(board);
			free_board(board);
			free_snake(snake);
		} else if (c == 'w'){
			//TODO: Parse inputs for changing directions
			snake_move(snake, board);
		}
		
	}
	return 0;
}
