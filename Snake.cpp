#include "GLOBAL.h"


int Snake::Move()
{
    std::vector<Coord>::iterator it;
    Coord temp;

    if(direction == DIRECTION_RIGHT)
    {
        temp.x = coordinates[0].x+1;
        temp.y = coordinates[0].y;
    }
    else if(direction == DIRECTION_DOWN)
    {
        temp.x = coordinates[0].x;
        temp.y = coordinates[0].y+1;

    }
    else if(direction == DIRECTION_LEFT)
    {
        temp.x = coordinates[0].x-1;
        temp.y = coordinates[0].y;
    }
    else if(direction == DIRECTION_UP)
    {
        temp.x = coordinates[0].x;
        temp.y = coordinates[0].y-1;
    }

    if(temp.x >= ARRAY_WIDTH || temp.y >= ARRAY_HEIGHT || temp.x < 0 || temp.y < 0)
    {
        //Reset();
        //Snake out of bounds
        return -1;
    }

    it = coordinates.begin( );
    coordinates.insert( it, temp );

    while(coordinates.size() > len)//remove excess snake dots
    {
        coordinates.pop_back( );
    }

    return 0;
}

int Snake::Overlaps()//si la serpiente esta sobre si misma devuelve -1.
{
    for( int i=1; i<coordinates.size(); i++ )
    {
        if( coordinates[i].x == coordinates[0].x && //coordiantes[0] es la cabeza de la serpiente.
            coordinates[i].y == coordinates[0].y )
        {
            return -1;
        }
    }
    return 0;
}

bool Snake::IsInSnake( int i, int j )//devuelve true si la posicion esta ocupada por la serpiente, si no devuelve false.
{
    for( int x=0; x<coordinates.size(); x++ )
    {
        if( coordinates[x].x == i && coordinates[x].y == j )
        {
            return true;
        }
    }
    return false;
}

void Snake::Eat( Manzana** pManzana )
{
    delete *pManzana;
    *pManzana = new Manzana;
    len += ( **pManzana ).score;
    //std::cout << "Snake length: " << len << std::endl;
}

void Snake::Eat( Kiwi** pKiwi )
{
    delete *pKiwi;
    *pKiwi = new Kiwi;
    len += ( **pKiwi ).score;
    //std::cout << "Snake length: " << len << std::endl;
}

void Snake::Eat( Poison** pPoison )
{
    delete *pPoison;
    *pPoison = new Poison;
    len += ( **pPoison ).score;
    if(len<1)//dont let length of snake be less than 1
    {
        len=1;
    }
    //std::cout << "Snake length: " << len << std::endl;
}

void Snake::GetFoodLocations( std::vector<Coord>* pLocations ) //devuelve en un vector todas las posibles posiciones de la comida manzana/kiwi/veneno.
{
    Coord temp;
    for( int i=0; i<ARRAY_WIDTH; i++ )
    {
        for( int j=0; j<ARRAY_HEIGHT; j++ )
        {
            if(!IsInSnake( i, j ))
            {
                temp.x = i;
                temp.y = j;
                pLocations->push_back( temp );
            }
        }
    }
}

void Snake::ChangeDir(int pDir)
{
    direction = pDir;
}

void Snake::Reset()
{
    coordinates.clear();
    std::vector<Coord>::iterator it;
    Coord temp;
    len = SNAKE_START_LENGTH;
    direction = DIRECTION_RIGHT;

    it = coordinates.begin();
    temp.x = 0;
    temp.y = 0;
    coordinates.insert(it,temp);

    it = coordinates.begin();
    temp.x = 1;
    temp.y = 0;
    coordinates.insert(it,temp);

    it = coordinates.begin();
    temp.x = 2;
    temp.y = 0;
    coordinates.insert(it,temp);
}

Snake::Snake()
{
    Reset();
}

Snake::~Snake()
{

}