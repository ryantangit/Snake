#include <stdio.h>
#include "gameboard.h"



//Driver function
int main (){
	struct gameboard *board = init_board();
	while(!board->game_over){
		print_gameboard(board);
		int c = getchar();
		if (c == 'q'){
			end_game(board);
			free_board(board);
		}
		
	}
	return 0;
}
