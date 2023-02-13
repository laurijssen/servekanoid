#ifndef __BALL_H_
#define __BALL_H_

#include <easydraw.h>
#include "player.h"

// direction bits
#define UP    0x00000001
#define DOWN  0x00000002
#define RIGHT 0x00000004
#define LEFT  0x00000008

#define STATE_STICKING 0x00000001
#define STATE_NORMAL   0x00000002

class Ball
{
public:
	Ball(Player *player, EASYDRAW *DDraw);
	void Move();
	void Draw();
	int  CheckHit(int &r, int &c);
	void ChangeYDirection();
	void ChangeXDirection();
	void SetDirection(int dir) { this->dir = dir; }
	int GetDirection() { return dir; }
	int GetState() { return state; }
	void SetState(int state) { this->state = state; }
	void SetXSpeed(S16 xs) { xspeed = xs; }
	void SetYSpeed(S16 ys) { yspeed = ys; }
	S16 GetX() { return x; }
	S16 GetY() { return y; }
	void SetX(S16 x) { this->x = x; }
	void SetY(S16 y) { this->y = y; }	
private:
	EASYDRAW *DDraw; // there will only be one ball so it doesn't have to be static	
	ImageID image;
	Player *player;
	S16 x, y;
	S16 w, h;
	S16 xspeed, yspeed;
	int dir; // bits will be set according to direction (see macro's at the top)
	int state; // the different states of the ball
};

#endif