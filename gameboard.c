#include "gameboard.h"
#include <malloc.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <time.h>

struct gameboard* init_board(){
	ws = (struct winsize*)malloc(sizeof(struct winsize));
	ioctl(0, TIOCGWINSZ, ws);
	struct gameboard *board = (struct gameboard*)malloc(sizeof(struct gameboard));
	board->BOARD_ROW = ws->ws_row - BOARD_ROW_MARGIN;
	board->BOARD_COL = ws->ws_col - BOARD_COL_MARGIN;
	board->game_over = 0;
	board->state = (char**)malloc(sizeof(char*) * board->BOARD_ROW);
	for (int i = 0; i < board->BOARD_ROW; i++){
		board->state[i] = (char*)malloc(sizeof(char) * board->BOARD_COL);
		for (int j = 0; j < board->BOARD_COL; j++){
			board->state[i][j] = ' ';
		}
	}
	return board;
}

void free_board(struct gameboard *board){
	free(ws);	
	for (int i = 0; i < board->BOARD_ROW; i++){
		free(board->state[i]);
	}
	free(board->state);
	free(board);
}

void board_change_row_col(struct gameboard *board, int row, int col, char c){
	board->state[row][col] = c;	
}

void increase_score(struct gameboard *board){
	board->score++;
}

void generate_food(struct gameboard *board){
	srandom(time(NULL));
	int rand_row, rand_col;
	do {
		rand_row = rand() % board->BOARD_ROW;
		rand_col = rand() % board->BOARD_COL;
	} while (!legal_in_bound(board, rand_row, rand_col) && board->state[rand_row][rand_col] != DEFAULT_SNAKE_AVATAR);	
	board_change_row_col(board, rand_row, rand_col, BOARD_FOOD_AVATAR);
}

int legal_in_bound(struct gameboard *board, int row, int col){
	if((col >= board->BOARD_COL - 1) || (row >= board->BOARD_ROW - 1) ||
			(col <= 0) || (row <= 0)){
		strncpy(board->end_message, "Out of bounds.", 17);	
		return 0;	
	}
	return 1;	
}

int contain_food(struct gameboard *board, int row, int col){
	return board->state[row][col] == BOARD_FOOD_AVATAR;
}

void print_gameboard(struct gameboard *board){
	printf("\e[2J");
	printf("score: %3d          q-quit        wasd-move\n", board->score);
	for (int i = 0; i < board->BOARD_ROW; i++){
		putchar('|');
		for (int j = 1; j < board->BOARD_COL - 1; j++){
			if (i == 0) {
				putchar('-');	
			} else if(i == board->BOARD_ROW - 1) {
				putchar('-');	
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


