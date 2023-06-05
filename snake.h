#define START_D_ROW -1
#define START_D_COL 0
#define START_SPEED 1
#define DEFAULT_SNAKE_AVATAR '%'

enum direction {NORTH, SOUTH, WEST, EAST};
struct snake_node {
	int row; 
	int col; 
	//TODO: considering a 2-d boolean exists for food generation.
	struct snake_node *prev;
	struct snake_node *next;
};
struct snake {
	int d_row;
	int d_col;
	int speed;
	enum direction dir;
	char snake_avatar;
	struct snake_node *head;
	struct snake_node *tail;
};

struct snake_node* create_snake_node(int row, int col);
struct snake* init_snake(struct gameboard *board);
void snake_attach_tail(struct snake *snake, int row, int col);
void free_snake(struct snake *snake);
void snake_change_dir(struct snake *snake, int dir);
int snake_out_bounds(struct snake *snake, struct gameboard *board);
void snake_body_move(struct snake *snake);
void snake_head_move(struct snake* snake, struct gameboard *board, int last_row, int last_col);
void snake_move(struct snake *snake, struct gameboard *board);
void snake_print(struct snake *snake);
