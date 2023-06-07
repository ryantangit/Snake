#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "gameboard.h"
#include "snake.h"
#include "util.h"



//Driver function
int main (){
	struct gameboard *board = init_board();
	struct snake *snake = init_snake(board);
	enum direction direction = NORTH;
	while(!board->game_over){
		print_gameboard(board);
		if(kbhit() != 0){	
			int c = getch();	
			if (c == 'q' || snake_out_bounds(snake, board)){
				end_game(board);
				free_board(board);
				free_snake(snake);
				break;
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
		}
		snake_move(snake, board);
		msleep(300);	
		//snake_print(snake);
	}
	return 0;
}
