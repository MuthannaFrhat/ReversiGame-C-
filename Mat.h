
#ifndef MYVECTOR_H
#define MYVECTOR_H
class Mat
{

    private:
        char** mat;
        int size;


    public:

        explicit Mat(int _size);
        ~Mat();
        void SetColor(int row,char column,char color);
        char GetColor(int row,char column);
        bool ValidateMove(int row, char column, char color);
        void FlipDisks(int row, char column, char color);
        bool HasValidMoves(char color);


    int getsize() const;
        void print();








};
#endif // MYVECTOR_H

