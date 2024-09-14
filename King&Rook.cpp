#include <iostream>
#include <vector>
#include <string>
using namespace std;

class ChessPiece
{
protected:
    int rank;
    int file;
    string color;

public:
    ChessPiece(int rank, int file, string color)
    {
        this->rank = rank;
        this->file = file;
        this->color = color;
    }

    int getRank()
    {
        return rank;
    }

    int getFile()
    {
        return file;
    }

    string getColor()
    {
        return color;
    }

    virtual bool isValidMove(int destRank, int destFile)
    {
        return false;
    }
};

class King : public ChessPiece
{
public:
    King(int rank, int file, string color) : ChessPiece(rank, file, color) {}

    bool isValidMove(int destRank, int destFile)
    {
        int rankDiff = abs(destRank - rank);
        int fileDiff = abs(destFile - file);

        // A King can move one square in any direction
        if (rankDiff <= 1 && fileDiff <= 1)
        {
            return true;
        }

        return false;
    }
};

class Rook : public ChessPiece
{
public:
    Rook(int rank, int file, string color) : ChessPiece(rank, file, color) {}

    bool isValidMove(int destRank, int destFile)
    {
        // Rook can move any number of squares in a straight line horizontally or vertically

        // Check if the destination rank or file is the same as the current rank or file
        if (destRank == rank || destFile == file)
        {
            return true;
        }

        return false;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<ChessPiece *> pieces;
    for (int i = 0; i < n; i++)
    {
        string type;
        int rank, file;
        string color;

        cin >> type >> rank >> file >> color;

        if (type == "king")
        {
            pieces.push_back(new King(rank, file, color));
        }
        else if (type == "rook")
        {
            pieces.push_back(new Rook(rank, file, color));
        }
    }

    int k;
    cin >> k;

    while (k-- > 0)
    {
        int idx, destRank, destFile;
        cin >> idx >> destRank >> destFile;

        cout << pieces[idx]->isValidMove(destRank, destFile) << endl;
    }

    // Clean up dynamically allocated memory
    for (ChessPiece *piece : pieces)
    {
        delete piece;
    }

    return 0;
}
