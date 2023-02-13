#include "block.h"

EASYDRAW *Block::DDraw = NULL;

const U8 Block::width = 32;
const U8 Block::height = 32;

int Block::Count = 0;

Block::Block(U16 x, U16 y, U8 hits)
{
	this->x = x, this->y = y, this->hits = hits;	
}

Block::~Block()
{
	DecCount();
}

bool Block::Hit()
{
	return --hits == 0;
}

ImageID Block1::image = -1;

Block1::Block1(U16 x, U16 y, U8 hits, EASYDRAW *DDraw) : Block(x, y, hits)
{
	this->DDraw = DDraw; // static member of Block

	if( image == -1 )
		image = DDraw->CreateImage(width, height, 0, "data/block1.bmp");

	DDraw->SetColorKey(DDraw->Convert16Bit(31, 0, 31), image);
}

void Block1::Draw()
{
	DDraw->DrawImage(x, y, image, DDBLT_KEYSRC);
}

ImageID Block2::image = -1;

Block2::Block2(U16 x, U16 y, U8 hits, EASYDRAW *DDraw) : Block(x, y, hits)
{
	this->DDraw = DDraw; // static member of Block

	if( image == -1 )
		image = DDraw->CreateImage(width, height, 0, "data/block2.bmp");

	DDraw->SetColorKey(DDraw->Convert16Bit(31, 0, 31), image);
}

void Block2::Draw()
{
	DDraw->DrawImage(x, y, image, DDBLT_KEYSRC);
}

ImageID Block3::image = -1;

Block3::Block3(U16 x, U16 y, U8 hits, EASYDRAW *DDraw) : Block(x, y, hits)
{
	this->DDraw = DDraw; // static member of Block

	if( image == -1 )
		image = DDraw->CreateImage(width, height, 0, "data/block3.bmp");		

	DDraw->SetColorKey(DDraw->Convert16Bit(31, 0, 31), image);
}

void Block3::Draw()
{
	DDraw->DrawImage(x, y, image, DDBLT_KEYSRC);
}

ImageID Block4::image = -1;

Block4::Block4(U16 x, U16 y, U8 hits, EASYDRAW *DDraw) : Block(x, y, hits)
{
	this->DDraw = DDraw; // static member of Block

	if( image == -1 )
		image = DDraw->CreateImage(width, height, 0, "data/block4.bmp");		

	DDraw->SetColorKey(DDraw->Convert16Bit(31, 0, 31), image);
}

void Block4::Draw()
{
	DDraw->DrawImage(x, y, image, DDBLT_KEYSRC);
}

ImageID Block5::image = -1;

Block5::Block5(U16 x, U16 y, U8 hits, EASYDRAW *DDraw) : Block(x, y, hits)
{
	this->DDraw = DDraw; // static member of Block

	if( image == -1 )
		image = DDraw->CreateImage(width, height, 0, "data/block5.bmp");

	DDraw->SetColorKey(DDraw->Convert16Bit(31, 0, 31), image);
}

void Block5::Draw()
{
	DDraw->DrawImage(x, y, image, DDBLT_KEYSRC);
}

ImageID Block6::image = -1;

Block6::Block6(U16 x, U16 y, U8 hits, EASYDRAW *DDraw) : Block(x, y, hits)
{
	this->DDraw = DDraw; // static member of Block

	if( image == -1 )
		image = DDraw->CreateImage(width, height, 0, "data/block6.bmp");

	DDraw->SetColorKey(DDraw->Convert16Bit(31, 0, 31), image);
}

void Block6::Draw()
{
	DDraw->DrawImage(x, y, image, DDBLT_KEYSRC);
}