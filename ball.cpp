#include "ball.h"

Ball::Ball(Player *player, EASYDRAW *DDraw)
{	
	this->DDraw = DDraw;
	this->player = player;
	x = 50, y = 735, w = 16, h = 16, xspeed = 7, yspeed = -7;
	dir = UP | RIGHT;
	state = STATE_STICKING; // keep the ball stick the player
	image = DDraw->CreateImage(16, 16, 0, "data/ball.bmp");
	DDraw->SetColorKey(DDraw->Convert16Bit(31, 0, 31), image);
}

void Ball::Draw()
{
	DDraw->DrawImage(x, y, image, DDBLT_KEYSRC);
}

void Ball::Move()
{	
	if( state & STATE_STICKING )
	{
		x = player->GetX() + 64;
		return;
	}

	x += xspeed;
	if( xspeed >= 0 ) // goin to the right?
	{
		if( x > 1012 )
			ChangeXDirection();
	}
	else // ok, left then
	{
		if( x < 6 )
			ChangeXDirection();
	}

	y += yspeed;
	if( yspeed >= 0 ) // going down?
	{		
		if( y > 746 )
			ChangeYDirection();
	}
	else 
	{	
		if( y < 6 ) // aha, goin up, but are you at the top?
			ChangeYDirection(); // yes, go down again
	}

	if( xspeed >= 0 )
		dir = RIGHT;
	else 
		dir = LEFT;

	if( yspeed >= 0 )
		dir |= DOWN;
	else
		dir |= UP;
}

int Ball::CheckHit(int &r, int &c)
{
	if( dir & UP ) 
	{
		if( dir & LEFT )
		{
			r = max(0, (y - yspeed) >> 5); // divide 32 (minor optimization)
			c = max(0, (x - xspeed) >> 5);
		}
		else
		{
			r = min(23, (y - yspeed) >> 5);
			c = min(31, (x + xspeed) >> 5);
		}
	}
	else
	{
		if( dir & RIGHT )
		{
			r = min(23, (y + yspeed) >> 5);
			c = min(31, (x + xspeed) >> 5);
		}
		else
		{
			r = max(0, (y - yspeed) >> 5);
			c = max(0, (x - xspeed) >> 5);
		}
	}

	return dir;
}

void Ball::ChangeYDirection()
{
	yspeed = -yspeed;
}

void Ball::ChangeXDirection()
{
	xspeed = -xspeed;
}