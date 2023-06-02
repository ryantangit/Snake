
#define ARENA_COL_MARGIN 2
#define ARENA_ROW_MARGIN 2

static struct winsize *ws;
struct gameboard {
	unsigned short score;
	int game_over;
	int ARENA_COL;
	int ARENA_ROW;
	char** state;
};
struct gameboard* init_board();
void free_board(struct gameboard *board);
void generate_food();
void board_change_row_col(struct gameboard *board, int row, int col, char c);
void print_gameboard(struct gameboard *board);
void print_score();
void end_game(struct gameboard *board);

