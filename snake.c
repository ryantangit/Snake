#include "gameboard.h"
#include "snake.h"
#include <stdio.h>
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
	snake_move(snake, board);
	generate_food(board);
	return snake;
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
	struct snake_node *ref = snake->head; 	
	int encountered_food = 0;
	//Head moves
	//For remaining node:
	//    set col/row to previous node
	//If head ate food:
	//    increase score
	//    create new node, attach prev node
}
