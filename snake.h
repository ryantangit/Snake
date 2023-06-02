#define START_D_ROW -1
#define START_D_COL 0
#define START_SPEED 1
#define DEFAULT_SNAKE_AVATAR '%'
struct snake_node {
	int row; //x is akin to column
	int col; //y is akin to row
	struct snake_node *next;
};
struct snake {
	int d_row;
	int d_col;
	int speed;
	char snake_avatar;
	struct snake_node *head;
};

struct snake_node* create_snake_node(int row, int col);
struct snake* init_snake(struct gameboard *board);
void free_snake(struct snake *snake);
void snake_change_dir(struct snake *snake, int dir);
int snake_out_bounds(struct snake *snake, struct gameboard *board);
void snake_move(struct snake *snake, struct gameboard *board);
