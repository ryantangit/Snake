#include "gameboard.h"
#include <malloc.h>
#include <stdio.h>
#include <sys/ioctl.h>


struct gameboard* init_board(){
	ws = (struct winsize*)malloc(sizeof(struct winsize));
	ioctl(0, TIOCGWINSZ, ws);
	struct gameboard *board = (struct gameboard*)malloc(sizeof(struct gameboard));
	board->ARENA_HEIGHT = ws->ws_row - ARENA_HEIGHT_MARGIN;
	board->ARENA_WIDTH = ws->ws_col - ARENA_WIDTH_MARGIN;
	board->game_over = 0;
	board->state = (char**)malloc(sizeof(char*) * board->ARENA_HEIGHT);
	for (int i = 0; i < board->ARENA_HEIGHT; i++){
		board->state[i] = (char*)malloc(sizeof(char) * board->ARENA_WIDTH);
		for (int j = 0; j < board->ARENA_WIDTH; j++){
			board->state[i][j] = ' ';
		}
	}
	return board;
}

void free_board(struct gameboard *board){
	free(ws);	
	for (int i = 0; i < board->ARENA_HEIGHT; i++){
		free(board->state[i]);
	}
	free(board->state);
	free(board);
}

void print_gameboard(struct gameboard *board){
	printf("\e[2J");
	for (int i = 0; i < board->ARENA_HEIGHT; i++){
		putchar('|');
		for (int j = 1; j < board->ARENA_WIDTH; j++){
			if (i == 0) {
				putchar('@');	
			} else if(i == board->ARENA_HEIGHT - 1) {
				putchar('@');	
			} else {
				printf("%c", board->state[i][j]);
			}
		}
		printf("|\n");
	}	
}

void end_game(struct gameboard *board){
	printf("%s\n", "End of the game");
	board->game_over = 1;
}


