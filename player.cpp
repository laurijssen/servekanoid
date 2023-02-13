#include "player.h"

Player::Player(EASYDRAW *DDraw) 
{ 
	x = 10; 
	this->DDraw = DDraw; 
	speed = 12;
	image = DDraw->CreateImage(128, 32, 0, "data/bar.bmp");
	DDraw->SetColorKey(DDraw->Convert16Bit(31, 0, 31), image);
}

void Player::Draw()
{
	DDraw->DrawImage(x, 735, image, DDBLT_KEYSRC);
}

void Player::MoveLeft()
{
	if( x > speed )
		x -= speed;
}

void Player::MoveRight()
{
	if( x < 896 - speed )
		x += speed;
}
