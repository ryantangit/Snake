
#define ARENA_WIDTH_MARGIN 2
#define ARENA_HEIGHT_MARGIN 2

static int ARENA_WIDTH;
static int ARENA_HEIGHT;
static struct winsize *ws;
struct gameboard {
	unsigned short score;
	int game_over;
	char** state;
};
struct gameboard* init_board();
void free_board(struct gameboard *board);
void generate_food();
void print_gameboard(struct gameboard *board);
void print_score();
void end_game(struct gameboard *board);

