#define START_D_X 0
#define START_D_Y -1
#define DEFAULT_SNAKE_AVATAR '%'
struct snake_node {
	int x; //x is akin to column
	int y; //y is akin to row
	struct snake_node *next;
};
struct snake {
	int d_x;
	int d_y;
	char snake_avatar;
	struct snake_node *head;
};

struct snake_node* create_snake_node(int x, int y);
struct snake* init_snake(struct gameboard *board);
void free_snake(struct snake *snake);
void snake_change_dir(int dir, struct snake *snake);
void snake_out_bounds(struct snake *snake, struct gameboard *board);
void snake_move(struct snake *snake, struct gameboard *board);
