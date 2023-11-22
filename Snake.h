class Snake
{
    int direction;
    int len;
public:
    std::vector<Coord> coordinates;
    void Eat( Manzana** pManzana );
    void Eat( Kiwi** pKiwi );
    void Eat( Poison** pPoison );
    void GetFoodLocations( std::vector<Coord>* pLocations );
    bool IsInSnake( int i, int j );
    void ChangeDir( int pDir );
    int Move();
    int Overlaps();
    void Reset();
    Snake();
    ~Snake();

};