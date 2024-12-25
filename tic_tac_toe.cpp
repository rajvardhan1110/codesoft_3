#include <iostream>
using namespace std;

char b[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char p = 'X';

void d() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
}

bool c() {
    for (int i = 0; i < 3; i++) {
        if (b[i][0] == b[i][1] && b[i][1] == b[i][2]) return true;
        if (b[0][i] == b[1][i] && b[1][i] == b[2][i]) return true;
    }
    if (b[0][0] == b[1][1] && b[1][1] == b[2][2]) return true;
    if (b[0][2] == b[1][1] && b[1][1] == b[2][0]) return true;
    return false;
}

void t() {
    int m;
    cout << "Player " << p << ", enter position: ";
    cin >> m;
    int r = (m - 1) / 3, c = (m - 1) % 3;
    if (b[r][c] != 'X' && b[r][c] != 'O') {
        b[r][c] = p;
        p = (p == 'X') ? 'O' : 'X';
    } else {
        cout << "Invalid move! Try again.\n";
        t();
    }
}

int main() {
    int mv = 0;
    d();
    while (mv < 9) {
        t();
        d();
        if (c()) {
            cout << "Player " << ((p == 'X') ? 'O' : 'X') << " wins!\n";
            return 0;
        }
        mv++;
    }
    cout << "It's a draw!\n";
    return 0;
}
