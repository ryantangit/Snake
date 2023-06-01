
struct snake_node {
	int x;
	int y;
	struct snake_node *next;
};
struct snake {
	int d_x;
	int d_y;
	struct snake_node *head;
};
struct snake* init_snake();
struct snake_node* create_snake_node(int x, int y);
void change_dir(int dir, struct snake *snake);
void update_state(struct snake *snake, struct gameboard *board);
void free_snake(struct snake *snake);
