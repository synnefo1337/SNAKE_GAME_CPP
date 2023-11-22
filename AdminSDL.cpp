#include "GLOBAL.h"


AdminSDL::AdminSDL( )
{

    SDL_Init(SDL_INIT_VIDEO);
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
    myWindow = SDL_CreateWindow("Conways game of life", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    myRenderer = SDL_CreateRenderer(myWindow, -1, SDL_RENDERER_ACCELERATED);

    int imgFlags = IMG_INIT_PNG;
    IMG_Init( imgFlags );

//cargar imagen de game over.
    SDL_Surface* mySurface = IMG_Load( "img/GAME_OVER_SCREEN.png" );
    myGameOverImg = SDL_CreateTextureFromSurface( myRenderer, mySurface );
    SDL_FreeSurface( mySurface );
}

AdminSDL::~AdminSDL( )
{
    SDL_DestroyTexture( myGameOverImg );
	SDL_DestroyRenderer( myRenderer );
	SDL_DestroyWindow( myWindow );
	myWindow = NULL;
	myRenderer = NULL;
    myGameOverImg = NULL;

    IMG_Quit();
	SDL_Quit();
}

void AdminSDL::GameOverScreen( )
{
    SDL_RenderCopy( myRenderer, myGameOverImg, NULL, NULL );
}

void AdminSDL::SetCell(Coord pos, int color)
{
    displayArray[pos.x][pos.y] = color;
}

void AdminSDL::DrawGrid( )
{
    SDL_SetRenderDrawColor( myRenderer, 0, 0, 0, 0 );
    for(int i=0; i<ARRAY_WIDTH; i++){
        double multX = (double)i/ARRAY_WIDTH;
        int posX = (int)(multX*SCREEN_WIDTH);
        SDL_RenderDrawLine(myRenderer, posX,0, posX,SCREEN_HEIGHT);
    }

    for(int j=0; j<ARRAY_HEIGHT; j++){
        double multY = (double)j/ARRAY_HEIGHT;
        int posY = (int)(multY*SCREEN_HEIGHT);
        SDL_RenderDrawLine(myRenderer, 0,posY, SCREEN_WIDTH,posY);
    }
}

void AdminSDL::ClearArray()
{
    for(int i = 0; i < ARRAY_WIDTH; i++)
    {
        for(int j = 0; j < ARRAY_HEIGHT; j++)
        {
            displayArray[i][j] = COLOR_WHITE;
        }
    }
}

void AdminSDL::SetSnake(std::vector<Coord> pCoordinates)//Celdas para renderizar
{
    SetCell( pCoordinates[0], COLOR_YELLOW );
    for(int i=1; i<pCoordinates.size(); i++)
    {
        SetCell( pCoordinates[i], COLOR_BLACK );
    }
}

void AdminSDL::DrawCells()
{
    int cellSizeX = SCREEN_WIDTH/ARRAY_WIDTH;
    int cellSizeY = SCREEN_HEIGHT/ARRAY_HEIGHT;
    for(int i = 0; i < ARRAY_WIDTH; i++){
        for(int j = 0; j < ARRAY_HEIGHT; j++){
            if( displayArray[i][j] == COLOR_BLACK ||
                displayArray[i][j] == COLOR_RED ||
                displayArray[i][j] == COLOR_GREEN ||
                displayArray[i][j] == COLOR_BLUE ||
                displayArray[i][j] == COLOR_YELLOW )
            {
                double multY = (double)j/ARRAY_HEIGHT;
                int posY = (int)(multY*SCREEN_HEIGHT);
                
                double multX = (double)i/ARRAY_WIDTH;
                int posX = (int)(multX*SCREEN_WIDTH);
                
                SDL_Rect fillRect = { posX, posY, cellSizeX, cellSizeY};
                if( displayArray[i][j] == COLOR_BLACK )
                {
                    SDL_SetRenderDrawColor( myRenderer, 0,0,0,0 );
                }
                else if( displayArray[i][j] == COLOR_RED )
                {
                    SDL_SetRenderDrawColor( myRenderer, 0xFF,0,0,0 );
                }
                else if( displayArray[i][j] == COLOR_GREEN )
                {
                    SDL_SetRenderDrawColor( myRenderer, 0,0xFF,0,0 );
                }
                else if( displayArray[i][j] == COLOR_BLUE )
                {
                    SDL_SetRenderDrawColor( myRenderer, 0,0,0xFF,0 );
                }
                else if( displayArray[i][j] == COLOR_YELLOW )
                {
                    SDL_SetRenderDrawColor( myRenderer, 0xBB,0xBB,0,0 );
                }

                SDL_RenderFillRect( myRenderer, &fillRect );

                //white outline
                SDL_SetRenderDrawColor( myRenderer, 0xFF,0xFF,0xFF,0xFF);
                SDL_RenderDrawRect( myRenderer, &fillRect);
            }
        }
    }
}

void AdminSDL::ScreenClear()
{
    SDL_SetRenderDrawColor( myRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
	SDL_RenderClear( myRenderer );
}

void AdminSDL::Render()
{
    SDL_RenderPresent( myRenderer );
}