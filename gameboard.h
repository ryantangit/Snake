
#define BOARD_COL_MARGIN 2
#define BOARD_ROW_MARGIN 2
#define BOARD_FOOD_AVATAR 'O'
static struct winsize *ws;
struct gameboard {
	unsigned short score;
	int game_over;
	int BOARD_COL;
	int BOARD_ROW;
	char** state;
};
struct gameboard* init_board();
void free_board(struct gameboard *board);
void generate_food(struct gameboard *board);
int contain_food(struct gameboard *board, int row, int col);
void increase_score(struct gameboard *board);
void board_change_row_col(struct gameboard *board, int row, int col, char c);
void print_gameboard(struct gameboard *board);
void print_score();
void end_game(struct gameboard *board);

