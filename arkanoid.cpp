#include <direct.h>
#include "arkanoid.h"

Arkanoid::Arkanoid(int w, int h, char *WindowName, int IconID) 
		 : GameManager(w, h, WindowName, IconID) 
{}

void Arkanoid::start() 
{
	srand(GetTickCount());
	bgcolor = DDraw->Convert16Bit(rand() % 16, rand() % 16, rand() % 16);
	ballcount = 6;
	level = 1;

	hit     = DSound->LoadSound("data/hit.wav");
	destroy = DSound->LoadSound("data/destroy.wav");
	bash    = DSound->LoadSound("data/bash.wav");

	bgmusic = NULL;	
	
	player = new Player(DDraw);
	ball   = new Ball(player, DDraw);

	GameState = GS_MAINMENU;
	mainmenu = 0;
}

void Arkanoid::stop() 
{
	for( int c = 0; c < cols; c++ )
		for( int r = 0; r < rows; r++ )
			delete field[r][c];

	delete ball;
	bgmusic->Stop();
	delete bgmusic;
}

void Arkanoid::frame() 
{
	switch( GameState )
	{
		case GS_RUNNING :
			int c, r;
			for( c = 0; c < cols; c++ ) // redraw whole field
				for( r = 0; r < rows; r++ )
				{			
					if( field[r][c] )
						field[r][c]->Draw();
				}

			ball->Move();
			CheckHit();	// collision detection

			ball->Draw();
			player->Draw();

			HandleKeys();

			char buff[32];
			sprintf(buff, "Lives left: %d", ballcount);
			DDraw->DrawString(10, 10, buff);	

			DDraw->Swap();
			DDraw->ClearScreen(0, bgcolor);
			break;

		case GS_MAINMENU :
			//mainmenu = new MainMenu(DDraw, DInput);
//			if( mainmenu->Show() == MainMenu::QUIT )
//				Quit();
			//delete mainmenu;
			//mainmenu = 0;
			GameState = GS_RUNNING;
			LoadNextLevel(level);
			break;
	}
}

void Arkanoid::CheckHit()
{
	int c, r;
	int balldir = ball->CheckHit(r, c);
	int ballX, ballY, playerX;

	ballX = ball->GetX() + 16;
	ballY = ball->GetY();
	playerX = player->GetX();

	if( r > -1 && c > -1 && r < 24 && c < 32 )
	{
		if( balldir & DOWN && ballY > 735 ) // player hit?
		{
			if( ballX > playerX && ballX < playerX + 130 )
			{					
				DSound->Play(bash);
				ball->ChangeYDirection();
			}
			else // lose a life
			{
				ball->ChangeYDirection();
				ball->SetY(735);
				ball->SetState(STATE_STICKING);
				ballcount--;
				if( ballcount == 0 ) // game over
				{					
					LoadNextLevel(1);
					ballcount = 5;
				}
			}
		}
		else if( field[r][c] ) // do we have a hit?
		{			
			RemoveBlock(r, c);
		}
	}
}

void Arkanoid::LoadNextLevel(int lvl)
{		
	char file[MAX_PATH];
	int BlockType;

	WIN32_FIND_DATA data;
	getcwd(file, MAX_PATH);
	sprintf(file, "%s/levels/*.dat", file);
	HANDLE h = FindFirstFile(file, &data);
	levelcount = 1;
	while( FindNextFile(h, &data) ) // count the number of files in the level directory
		levelcount++;

	if( lvl > levelcount ) // start over
		lvl = 1;

	delete bgmusic;
	sprintf(file, "data/%d.mid", lvl);
	bgmusic = new Midi(DSound->GetSoundObject());
	bgmusic->LoadMidi(file);
	bgmusic->Play();

	sprintf(file, "levels/%d.dat", lvl);
	
	FILE *fp = fopen(file, "rb");
	Block::SetCount(0);
	for( int r = 0; r < 24; r++ )
		for( int c = 0; c < 32; c++ )
		{
			fread(&BlockType, sizeof(int), 1, fp);
			switch( BlockType )
			{
				case -1 :
				field[r][c] = NULL; // no block here
				break;

				case 1 :
				field[r][c] = new Block1(c * Block::height, r * Block::width, 1, DDraw);
				Block::IncCount();
				break;
				
				case 2 :
				field[r][c] = new Block2(c * Block::height, r * Block::width, 1, DDraw);
				Block::IncCount();
				break;

				case 3 :
				field[r][c] = new Block3(c * Block::height, r * Block::width, 1, DDraw);
				Block::IncCount();
				break;

				case 4 :
				field[r][c] = new Block4(c * Block::height, r * Block::width, 2, DDraw);
				Block::IncCount();
				break;

				case 5 :
				field[r][c] = new Block5(c * Block::height, r * Block::width, 2, DDraw);
				Block::IncCount();
				break;

				case 6 :
				field[r][c] = new Block6(c * Block::height, r * Block::width, 2, DDraw);
				Block::IncCount();
				break;
			}
		}

	bgcolor = DDraw->Convert16Bit(rand() % 16, rand() % 16, rand() % 16);

	fclose(fp);
	level = ++lvl;
}

void Arkanoid::HandleKeys()
{
	if( DInput->KeyDown(DIK_RIGHT) )
		player->MoveRight();
	if( DInput->KeyDown(DIK_LEFT) )
		player->MoveLeft();
	if( DInput->KeyDown(DIK_SPACE) )
		ball->SetState(STATE_NORMAL);
	if( DInput->KeyDown(DIK_ESCAPE) )
		PostQuitMessage(0);
	if( DInput->KeyDown(DIK_PAUSE) )
		PauseGame(TRUE, DIK_PAUSE);
}

void Arkanoid::RemoveBlock(int r, int c)
{
	int x = ball->GetX();
	int y = ball->GetY();

	if( r != (y >> 5) && c == (x >> 5) ) // going straight up or down?		
		ball->ChangeYDirection();
	else if( c != (x >> 5) && r == (y >> 5) )
		ball->ChangeXDirection();
	else if( r < (y >> 5) && c > (x >> 5) )
		ball->ChangeYDirection();
	else if( r < (y >> 5) && c < (x >> 5) )
		ball->ChangeXDirection();
	else
		ball->ChangeYDirection();

	if( field[r][c]->Hit() ) // returns true if hits is zero
	{
		DSound->Play(destroy);
		delete field[r][c]; // yes, delete it
		field[r][c] = NULL;
	}
	else
	{
		DSound->Play(hit);
	}

	if( Block::GetCount() == 0 )
		LoadNextLevel(level);
}

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR lpszCmdLine, int)
{
	EnumerateDevices();
	GameManager *game = new Arkanoid(1024, 768, "arkanoid", 0);
	game->MainGameLoop();

	delete game;

	return 0;
}