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
