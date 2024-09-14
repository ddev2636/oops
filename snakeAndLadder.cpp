#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>

using namespace std;

class Board {
public:
    int size;
    map<int, int> snakes;
    map<int, int> ladders;

    Board(int size) : size(size) {}

    void addSnake(int start, int end) {
        snakes[start] = end;
    }

    void addLadder(int start, int end) {
        ladders[start] = end;
    }

    int getNewPosition(int currentPosition) {
        if (snakes.find(currentPosition) != snakes.end()) {
            return snakes[currentPosition];
        }
        if (ladders.find(currentPosition) != ladders.end()) {
            return ladders[currentPosition];
        }
        return currentPosition;
    }
};

class Player {
public:
    string name;
    int position;

    Player(string name) : name(name), position(0) {}

    void move(int steps, Board &board) {
        int newPosition = position + steps;
        if (newPosition <= board.size) {
            newPosition = board.getNewPosition(newPosition);
            position = newPosition;
        }
    }

    bool hasWon(int boardSize) {
        return position == boardSize;
    }
};

class Dice {
public:
    int roll() {
        return (rand() % 6) + 1;
    }
};

class Game {
public:
    Board board;
    vector<Player> players;
    Dice dice;
    queue<Player*> turnQueue;

    Game(Board board, vector<Player> players) : board(board), players(players) {
        srand(time(0));
        for (Player &player : players) {
            turnQueue.push(&player);
        }
    }

    void play() {
        while (true) {
            Player *currentPlayer = turnQueue.front();
            turnQueue.pop();
            int diceRoll = dice.roll();
            cout << currentPlayer->name << " rolled a " << diceRoll << endl;
            currentPlayer->move(diceRoll, board);
            cout << currentPlayer->name << " moved to " << currentPlayer->position << endl;

            if (currentPlayer->hasWon(board.size)) {
                cout << currentPlayer->name << " wins!" << endl;
                break;
            }

            turnQueue.push(currentPlayer);
        }
    }
};

int main() {
    Board board(100);
    board.addSnake(99, 5);
    board.addLadder(2, 98);

    Player player1("Alice");
    Player player2("Bob");
    vector<Player> players = {player1, player2};

    Game game(board, players);
    game.play();

    return 0;
}
