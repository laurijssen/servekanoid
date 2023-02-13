#ifndef __BLOCK_H_
#define __BLOCK_H_

#include <easydraw.h>
#include <utils.h>

class Block
{
public:
	static const U8 width;
	static const U8 height;	

	Block(U16 x, U16 y, U8 hits);
	virtual ~Block();
	
	virtual void Draw() = 0; // pure
	bool Hit();
	static void SetCount(int c) { Count = c; }
	static int GetCount() { return Count; }
	static void IncCount() { Count++; }
	static void DecCount() { Count--; }

protected:
	static EASYDRAW *DDraw;
	static int Count;
	U16 hits;
	U16 x, y;	
};

class Block1 : public Block
{
public:	
	Block1(U16 x, U16 y, U8 hits, EASYDRAW *DDraw);
	void Draw();
private:
	static ImageID image;
};

class Block2 : public Block
{
public:	
	Block2(U16 x, U16 y, U8 hits, EASYDRAW *DDraw);
	void Draw();
private:
	static ImageID image;
};

class Block3 : public Block
{
public:	
	Block3(U16 x, U16 y, U8 hits, EASYDRAW *DDraw);
	void Draw();
private:
	static ImageID image;
};

class Block4 : public Block
{
public:	
	Block4(U16 x, U16 y, U8 hits, EASYDRAW *DDraw);
	void Draw();
private:
	static ImageID image;
};

class Block5 : public Block
{
public:	
	Block5(U16 x, U16 y, U8 hits, EASYDRAW *DDraw);
	void Draw();
private:
	static ImageID image;
};

class Block6 : public Block
{
public:	
	Block6(U16 x, U16 y, U8 hits, EASYDRAW *DDraw);
	void Draw();
private:
	static ImageID image;
};

#endif