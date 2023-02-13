#include <GameManager.h>
#include <EnumModes.h>
#include "block.h"
#include "ball.h"
#include "player.h"
#include "mainmenu.h"

class Arkanoid : public GameManager
{
public:
	enum GAMESTATE { GS_RUNNING, GS_MAINMENU };

	Arkanoid(int w, int h, char *WindowName, int IconID=0) ;
	
	void start(); // overridden from GameManager
	void frame();
	void stop();
	void CheckHit();
	void LoadNextLevel(int lvl);
	void RemoveBlock(int r, int c);		
	void HandleKeys();
private: 
	enum { cols=32, rows=24 };

	MainMenu *mainmenu;
	U16 bgcolor;
	Block  *field[rows][cols];
	Ball   *ball;
	Player *player;	
	int levelcount;
	Midi *bgmusic;
	int level;
	U8 ballcount;
	SoundID hit, destroy, bash;
	GAMESTATE GameState;
};