#include "gameboard.h"
#include "snake.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct snake_node* create_snake_node(int row, int col){
	struct snake_node *sn = (struct snake_node*)malloc(sizeof(struct snake_node));
	sn->row = row;
	sn->col = col;
	sn->prev = NULL;
	sn->next = NULL;
	return sn;
}

struct snake* init_snake(struct gameboard *board){
	struct snake *snake = (struct snake*)malloc(sizeof(struct snake));
	snake->d_row = START_D_ROW;
	snake->d_col = START_D_COL;
	snake->speed = START_SPEED;
	snake->dir = NORTH;
	snake->snake_avatar = DEFAULT_SNAKE_AVATAR;
	snake->head = create_snake_node(board->BOARD_ROW / 2, board->BOARD_COL / 2);
	snake->tail = snake->head;
	board_change_row_col(board, snake->head->row, snake->head->col, snake->snake_avatar);
	generate_food(board);
	return snake;
}

void snake_attach_tail(struct snake *snake, int row, int col){
	struct snake_node *new_tail = create_snake_node(row, col);
	snake->tail->next = new_tail;
	new_tail->prev = snake->tail;
	snake->tail = new_tail;
}

void free_snake(struct snake *snake){
	struct snake_node *ref = snake->head;
	struct snake_node *tmp;
	while(NULL != ref){
		tmp = ref->next;	
		free(ref);
		ref = tmp;
	}
	free(snake);
}


int snake_out_bounds(struct snake *snake, struct gameboard *board){
	return !legal_in_bound(board, snake->head->row, snake->head->col);	
}


void snake_change_dir(struct snake *snake, int dir){
	if(dir == NORTH && snake->dir != SOUTH){
		snake->d_row = -1;
		snake->d_col = 0;
		snake->dir = NORTH;
	} else if (dir == SOUTH && snake->dir != NORTH){
		snake->d_row = 1;
		snake->d_col = 0;
		snake->dir = SOUTH;
	} else if (dir == WEST && snake->dir != EAST) {
		snake->d_row = 0;
		snake->d_col = -1;
		snake->dir = WEST;
	} else if (dir == EAST && snake->dir != WEST) {
		snake->d_row = 0;
		snake->d_col = 1;
		snake->dir = EAST;
	}
}


void snake_body_move(struct snake* snake){
	struct snake_node *ref = snake->tail;
	while (ref != snake->head){
		ref->col = ref->prev->col;
		ref->row = ref->prev->row;
		ref = ref->prev;
	}
}

void snake_head_move(struct snake* snake, struct gameboard *board, int last_row, int last_col){
	snake->head->row = snake->head->row + (snake->d_row * START_SPEED);
	snake->head->col = snake->head->col + (snake->d_col * START_SPEED);
	if (board->state[snake->head->row][snake->head->col] == DEFAULT_SNAKE_AVATAR){
		strncpy(board->end_message, "Snake ate itself.", 18);
		board->game_over = 1;	
		return;
	}
	if (contain_food(board, snake->head->row, snake->head->col)){
		increase_score(board);	
		snake_attach_tail(snake, last_row, last_col);
		generate_food(board);
	} else {
		board_change_row_col(board, last_row, last_col, ' ');
	}
	board_change_row_col(board, snake->head->row, snake->head->col, snake->snake_avatar);

}

void snake_move(struct snake *snake, struct gameboard *board){
	struct snake_node *body = snake->head->next; 	
	int last_row = snake->tail->row;
	int last_col = snake->tail->col;
	snake_body_move(snake);	
	snake_head_move(snake, board, last_row, last_col);	
}

void snake_print(struct snake *snake){
	printf("Head node: %p\n", snake->head);
	printf("Tail node: %p\n", snake->tail);
	printf("Head node next: %p\n", snake->head->next);
	printf("Tail node prev: %p\n", snake->tail->prev);
}
