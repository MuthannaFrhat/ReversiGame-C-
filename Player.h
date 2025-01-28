
#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H
class Player
{
private:


    int points;
public:
    explicit Player(char _name);

    void AddPoints(int num);
    int GetPoints() const;


};
#endif //EX2_PLAYER_H
