#include "gameboard.h"
#include "snake.h"
#include <stdio.h>
#include <malloc.h>

struct snake_node* create_snake_node(int x, int y){
	struct snake_node *sn = (struct snake_node*)malloc(sizeof(struct snake_node));
	sn->x = x;
	sn->y = y;
	sn->next = NULL;
	return sn;
}

struct snake* init_snake(struct gameboard *board){
	struct snake *snake = (struct snake*)malloc(sizeof(struct snake));
	snake->d_x = START_D_X;
	snake->d_y = START_D_Y;
	snake->snake_avatar = DEFAULT_SNAKE_AVATAR;
	snake->head = create_snake_node(board->ARENA_WIDTH / 2, board->ARENA_HEIGHT / 2);
	return snake;
}
