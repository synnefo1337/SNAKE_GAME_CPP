#include "GLOBAL.h"

void GameOver( Snake** pSnake, Manzana* pManzana, Kiwi* pKiwi, Poison* pPoison, std::vector<Coord>* pFoodLocations )
{
	std::cout << "GameOver." << std::endl;
	delete *pSnake;
	*pSnake = new Snake;

	pFoodLocations->clear( );
	( *pSnake )->GetFoodLocations( pFoodLocations );
	pManzana->SetPos( pFoodLocations );
	pKiwi->SetPos( pFoodLocations );
	pPoison->SetPos( pFoodLocations );
}

int main( int argc, char* args[] )
{	
	AdminSDL mySDL = AdminSDL();

	std::vector<Coord> foodLocations;

	Manzana* myManzana = new Manzana;

	Kiwi* myKiwi = new Kiwi;

	Poison* myPoison = new Poison;

	Snake* mySnake = new Snake;

	clock_t myTime = clock();

	//SET RANDOM SEED
	srand( time( NULL ) );
    for( int i=0; i<10; i++ )
    	srand( rand( ) % 66 * rand()+55 );
	//SET RANDOM SEED

	foodLocations.clear( );
	mySnake->GetFoodLocations( &foodLocations );

	myManzana->SetPos( &foodLocations );

	myKiwi->SetPos( &foodLocations );

	myPoison->SetPos( &foodLocations );
	
	SDL_Event myEvent;

	bool quit = false;

	bool gameOverScreen = false;

	while(!quit)
	{
		if( !gameOverScreen )
		{
		
			if( clock()-myTime >= 0.5*CLOCKS_PER_SEC )//Move every 1/2 sec
			{
				myTime = clock();
				if( mySnake->Move() == -1 )
				{
					gameOverScreen = true;
					GameOver( &mySnake, myManzana, myKiwi, myPoison, &foodLocations );
				}
			}

			if( mySnake->Overlaps() == -1 )
			{
				gameOverScreen = true;
				GameOver( &mySnake, myManzana, myKiwi, myPoison, &foodLocations );
			}

			if( mySnake->IsInSnake( myManzana->Location.x, myManzana->Location.y ) )//Comio la manzana
			{
				mySnake->Eat( &myManzana );

				//cambiar de lugar la comida

				foodLocations.clear( );

				mySnake->GetFoodLocations( &foodLocations );

				myManzana->SetPos( &foodLocations );

				myKiwi->SetPos( &foodLocations );

				myPoison->SetPos( &foodLocations );

			}

			if( mySnake->IsInSnake( myKiwi->Location.x, myKiwi->Location.y ) )//Comio la manzana
			{
				mySnake->Eat( &myKiwi );

				//cambiar de lugar la comida

				foodLocations.clear( );

				mySnake->GetFoodLocations( &foodLocations );

				myManzana->SetPos( &foodLocations );

				myKiwi->SetPos( &foodLocations );

				myPoison->SetPos( &foodLocations );

			}

			if( mySnake->IsInSnake( myPoison->Location.x, myPoison->Location.y ) )//Comio la manzana
			{
				mySnake->Eat( &myPoison );

				//cambiar de lugar la comida

				foodLocations.clear( );

				mySnake->GetFoodLocations( &foodLocations );

				myManzana->SetPos( &foodLocations );

				myKiwi->SetPos( &foodLocations );

				myPoison->SetPos( &foodLocations );

			}

			mySDL.ClearArray();
			mySDL.ScreenClear();

			mySDL.SetCell( myManzana->Location, COLOR_RED );
			mySDL.SetCell( myKiwi->Location, COLOR_GREEN );
			mySDL.SetCell( myPoison->Location, COLOR_BLUE );
			mySDL.SetSnake(mySnake->coordinates);

			mySDL.DrawGrid();
			mySDL.DrawCells();

			
		}
		else
		{
			mySDL.ScreenClear();
			mySDL.GameOverScreen();
		}

		mySDL.Render();

		while(SDL_PollEvent(&myEvent) != 0)
		{
			if(myEvent.type == SDL_QUIT)
			{
				quit = true;
			}
			else if(myEvent.type == SDL_KEYDOWN && myEvent.key.keysym.sym == SDLK_RIGHT)
			{
				mySnake->ChangeDir(DIRECTION_RIGHT);
			}
			else if(myEvent.type == SDL_KEYDOWN && myEvent.key.keysym.sym == SDLK_UP)
			{
				mySnake->ChangeDir(DIRECTION_UP);
			}
			else if(myEvent.type == SDL_KEYDOWN && myEvent.key.keysym.sym == SDLK_LEFT)
			{
				mySnake->ChangeDir(DIRECTION_LEFT);
			}
			else if(myEvent.type == SDL_KEYDOWN && myEvent.key.keysym.sym == SDLK_DOWN)
			{
				mySnake->ChangeDir(DIRECTION_DOWN);
			}
			else if(myEvent.type == SDL_KEYDOWN && myEvent.key.keysym.sym == SDLK_c)
			{
				gameOverScreen = false;
			}
			else if(myEvent.type == SDL_KEYDOWN && myEvent.key.keysym.sym == SDLK_x)
			{
				quit = true;
			}
		}
		
	}
	

	return 0;
}
