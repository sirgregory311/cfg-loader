#ifndef _MENU_H_
#define _MENU_H_

/* Prototypes */
void Menu_Device(void);
void Menu_Format(void);
void Menu_Install(void);
void Menu_Remove(void);
void Menu_Boot(void);
s32 __Menu_GetEntries(void);
void Menu_Loop(void);
void Menu_Options(void);
void Menu_Partition(bool must_select);
void Handle_Home(int disable_screenshot);
void Online_Update();
void Download_Titles();
void Menu_Cheats();
int  Menu_PrintWait();
bool Menu_Confirm(char *msg);

extern struct discHdr *gameList;
extern s32 gameCnt, gameSelected, gameStart;
extern s32 all_gameCnt;

struct Menu
{
	int num_opt;
	int current;
	int line_count;
	char *active;
	int active_size;
};

void menu_init(struct Menu *m, int num_opt);
void menu_begin(struct Menu *m);
int  menu_mark(struct Menu *m);
void menu_move(struct Menu *m, int buttons);

void menu_init_active(struct Menu *m, char *active, int active_size);
void menu_jump_active(struct Menu *m);
void menu_move_cap(struct Menu *m);
void menu_move_wrap(struct Menu *m);
void menu_move_adir(struct Menu *m, int dir);
void menu_move_active(struct Menu *m, int buttons);

#define MENU_MARK() menu_mark(&menu)

void printf_(char *fmt, ...);
void printf_x(char *fmt, ...);
void printf_h(char *fmt, ...);

#endif
