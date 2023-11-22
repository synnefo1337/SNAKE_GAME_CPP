const int SCREEN_WIDTH = 700;
const int SCREEN_HEIGHT = 700;

const int ARRAY_WIDTH = 25;
const int ARRAY_HEIGHT = 25;

const int COLOR_WHITE = 0;
const int COLOR_BLACK = 1;
const int COLOR_RED = 2;
const int COLOR_GREEN = 3;
const int COLOR_BLUE = 4;
const int COLOR_YELLOW = 5;

const int DIRECTION_RIGHT = 0;
const int DIRECTION_DOWN = 1;
const int DIRECTION_LEFT = 2;
const int DIRECTION_UP = 3;

const int SNAKE_START_LENGTH = 3;

#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include "Coord.h"
#include "Food.h"
#include "Manzana.h"
#include "Kiwi.h"
#include "Poison.h"
#include "AdminSDL.h"
#include "Snake.h"