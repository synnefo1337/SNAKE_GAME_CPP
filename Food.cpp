#include "GLOBAL.h"

void Food::SetPos( std::vector<Coord>* pFoodLocations )
{

    int arrayLength = pFoodLocations->size();
    int randomNum = rand() % arrayLength;
    Location.x = ( *pFoodLocations )[ randomNum ].x;
    Location.y = ( *pFoodLocations )[ randomNum ].y;
    pFoodLocations->erase( pFoodLocations->begin() + randomNum );
}