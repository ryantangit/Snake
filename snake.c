#include "gameboard.h"
#include "snake.h"
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
	if(dir == NORTH){
		snake->d_row = -1;
		snake->d_col = 0;
	} else if (dir == SOUTH){
		snake->d_row = 1;
		snake->d_col = 0;
	} else if (dir == WEST) {
		snake->d_row = 0;
		snake->d_col = -1;
	} else if (dir == EAST) {
		snake->d_row = 0;
		snake->d_col = 1;
	}
}

void snake_move(struct snake *snake, struct gameboard *board){
	struct snake_node *body = snake->head->next; 	
	int last_row = snake->head->row;
	int last_col = snake->head->col;
	while (NULL != body){
		last_row = body->row;
		last_col = body->col;
		body->col = body->prev->col;
		body->row = body->prev->row;
		body = body->next;
	}	
	snake->head->row = snake->head->row + (snake->d_row * START_SPEED);
	snake->head->col = snake->head->col + (snake->d_col * START_SPEED);
	if (contain_food(board, snake->head->row, snake->head->col)){
		increase_score(board);	
		snake_attach_tail(snake, last_row, last_col);
		generate_food(board);
	} else {
		board_change_row_col(board, last_row, last_col, ' ');
	}
	board_change_row_col(board, snake->head->row, snake->head->col, snake->snake_avatar);

	int debug = 1; 
	struct snake_node *debug_node = snake->head;			
	FILE* fptr;
	fptr = fopen("/home/ryan/Desktop/Snake/debug.txt", "w");
	if(debug) {
		int num = 0;
		
		while (NULL != debug_node){
			fprintf(fptr, "%d, %d, %d\n", num++, debug_node->row, debug_node->col);	
			debug_node = debug_node->next;	
		}	
	}
	fclose(fptr);

}
