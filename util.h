//https://stackoverflow.com/questions/7469139/what-is-the-equivalent-to-getch-getche-in-linux
void initTermios(int echo);
void resetTermios(void);
char getch_(int echo);
char getch(void);
char getche(void);
//https://stackoverflow.com/questions/29335758/using-kbhit-and-getch-on-linux
int kbhit();
//https://stackoverflow.com/questions/1157209/is-there-an-alternative-sleep-function-in-c-to-milliseconds
int msleep(long msec);
