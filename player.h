#ifndef __PLAYER_H_
#define __PLAYER_H_

#include <easydraw.h>

class Player
{
public:
	Player(EASYDRAW *DDraw);
	void Draw();
	void MoveLeft();
	void MoveRight();
	S16 GetX() { return x; }
private:
	EASYDRAW *DDraw;
	ImageID image;
	S16 x;	
	U16 speed;
};

#endif