#include "Mat.h"
#include "Player.h"
class Game{
private:

    Player *p1;
    Player *p2;
    Mat* mat;
public:
    Game();
    void PrintBoard();
    void Play();
    bool IsFull();
    bool GameOver();
    void AnnounceWinner();



};