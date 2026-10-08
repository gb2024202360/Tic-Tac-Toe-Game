#include <iostream>
using namespace std;
char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};
void displayBoard() {
    cout << "\n";
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n";
    cout << "---|---|---\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n";
    cout << "---|---|---\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n";
}
bool checkWin(char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player &&
            board[i][1] == player &&
            board[i][2] == player)
            return true;
        if (board[0][i] == player &&
            board[1][i] == player &&
            board[2][i] == player)
            return true;
    }
    if (board[0][0] == player &&
        board[1][1] == player &&
        board[2][2] == player)
        return true;
    if (board[0][2] == player &&
        board[1][1] == player &&
        board[2][0] == player)
        return true;
    return false;
}
int main() {
    int choice;
    char player = 'X';
    for (int turn = 0; turn < 9; turn++) {
        displayBoard();
        cout << "\nPlayer " << player << ", enter a position (1-9): ";
        cin >> choice;
        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;
        if (choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "Invalid move! Try again.\n";
            turn--;
            continue;
        }
        board[row][col] = player;
        if (checkWin(player)) {
            displayBoard();
            cout << "\nPlayer " << player << " wins!\n";
            return 0;
        }
        if (player == 'X')
            player = 'O';
        else
            player = 'X';
    }
    displayBoard();
    cout << "\nIt's a draw!\n";
    return 0;
}
