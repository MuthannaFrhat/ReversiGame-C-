#include "Game.h"
#include "Player.h"
#include "iostream"
using namespace std;

Game::Game() {
    mat = new Mat(8);
    mat->SetColor(4, 'E', 'B');
    mat->SetColor(5, 'E', 'W');
    mat->SetColor(4, 'D', 'W');
    mat->SetColor(5, 'D', 'B');
    p1 = new Player('B');
    p2 = new Player('W');

}

void Game::PrintBoard() {
    mat->print();
}

bool Game::IsFull() {
    for (int row = 1; row <= mat->getsize(); ++row) {
        for (char column = 'A'; column < 'A' + mat->getsize(); ++column) {
            if (mat->GetColor(row, column) == 'O') {
                return false;
            }
        }
    }
    return true;
}

void Game::Play() {
    char currentPlayer = 'B';
    string lastInputB = "", lastInputW = "";


    while (!GameOver()) {

        if (!(lastInputB == "PASS" && lastInputW == "PASS")) {
            PrintBoard();
        }

        cout << currentPlayer << ":\n";
        string input;
        cin >> input;

        if (input == "QUIT") {
            if (currentPlayer == 'B') {
                cout << "B: QUIT\n";
                cout << "W wins the game.\n";
            } else {
                cout << "W: QUIT\n";
                cout << "B wins the game.\n";
            }
            return;
        }

        if (input == "PASS") {
            if (currentPlayer == 'B') {
                lastInputB = "PASS";
                cout << "B: PASS\n";
            } else {
                lastInputW = "PASS";
                cout << "W: PASS\n";
            }

            if (lastInputB == "PASS" && lastInputW == "PASS") {
                break;
            }

            currentPlayer = (currentPlayer == 'B') ? 'W' : 'B';
            continue;
        }

        if (currentPlayer == 'B') lastInputB = "";
        else lastInputW = "";

        if (input.length() != 2 ||
            input[0] < 'A' || input[0] > 'H' ||
            input[1] < '1' || input[1] > '8') {
            cerr << "Invalid move; the game awaits a valid move.\n";
            continue;
        }

        char column = input[0];
        int row = stoi(input.substr(1));

        if (row < 1 || row > mat->getsize() || column < 'A' || column >= 'A' + mat->getsize()) {
            cerr << "Invalid move; the game awaits a valid move.\n";
            continue;
        }

        if (!mat->ValidateMove(row, column, currentPlayer)) {
            cerr << "Invalid move; the game awaits a valid move.\n";
            continue;
        }

        mat->FlipDisks(row, column, currentPlayer);
        if (currentPlayer == 'B') {
            p1->AddPoints(1);
            currentPlayer = 'W';
        } else {
            p2->AddPoints(1);
            currentPlayer = 'B';
        }
    }

    AnnounceWinner();
}


void Game::AnnounceWinner() {

    int blackPoints = p1->GetPoints();
    int whitePoints = p2->GetPoints();

    if (blackPoints > whitePoints) {
        cout << "B wins the game.\n";
    } else if (whitePoints > blackPoints) {
        cout << "W wins the game.\n";
    } else {
        cout << "The game ends in a tie.\n";
    }
}

bool Game::GameOver() {
    return IsFull() || (!mat->HasValidMoves('B') && !mat->HasValidMoves('W'));
}