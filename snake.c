#include "gameboard.h"
#include "snake.h"
#include <stdio.h>
#include <malloc.h>

struct snake_node* create_snake_node(int row, int col){
	struct snake_node *sn = (struct snake_node*)malloc(sizeof(struct snake_node));
	sn->row = row;
	sn->col = col;
	sn->next = NULL;
	return sn;
}

struct snake* init_snake(struct gameboard *board){
	struct snake *snake = (struct snake*)malloc(sizeof(struct snake));
	snake->d_row = START_D_ROW;
	snake->d_col = START_D_COL;
	snake->speed = START_SPEED;
	snake->snake_avatar = DEFAULT_SNAKE_AVATAR;
	snake->head = create_snake_node(board->ARENA_ROW / 2, board->ARENA_COL / 2);
	snake_move(snake, board);
	return snake;
}

int snake_out_bounds(struct snake* snake, struct gameboard *board){
	if((snake->head->col >= board->ARENA_COL - 1) || (snake->head->row >= board->ARENA_ROW - 1) ||
			(snake->head->col <= 0) || (snake->head->row <= 0))
		return 1;	
	return 0;
}

void snake_move(struct snake* snake, struct gameboard *board){
	struct snake_node *ref = snake->head; 	
	int last_row, last_col;
	while(NULL != ref){
		last_row = ref->row;
		last_col = ref->col;
		ref->row = (snake->speed * snake->d_row) + ref->row;	
		ref->col = (snake->speed * snake->d_col) + ref->col;
		board_change_row_col(board, ref->row, ref->col, snake->snake_avatar);
		ref = ref->next;
	}
	board_change_row_col(board, last_row, last_col, ' ');
}
