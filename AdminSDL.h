class AdminSDL
{
    SDL_Window* myWindow;
    SDL_Renderer* myRenderer;
    SDL_Texture* myGameOverImg;
    int displayArray[ARRAY_WIDTH][ARRAY_HEIGHT];
public:
    void SetCell(Coord pos, int color);
    void ScreenClear();
    void Render();
    void DrawGrid();
    void ClearArray();
    void DrawCells();
    void SetSnake(std::vector<Coord> pCoordinates);
    void GameOverScreen();
    AdminSDL();
    ~AdminSDL();
};