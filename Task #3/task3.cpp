#include <iostream>
using namespace std;

void Paint(int i, int j, char** picture, int M, int N) {
    for (int m = -1; m < 2; m++) {
        for (int n = -1; n < 2; n++) {
            if (i + m >= 0 && i + m < M && j + n >= 0 && j + n < N &&
                (picture[i + m][j + n] == '.' || picture[i + m][j + n] == 'P')) {
                picture[i + m][j + n] = 'X';
                Paint(i + m, j + n, picture, M, N);
            }
        }
    }
    return;
}

int main() {
    int M = 8;
    int N = 10;
    char** picture = new char*[M];
    for (int i = 0; i < M; i++) {
        picture[i] = new char[N];
    }
    int counter = 0;
    string a = "XX..XX..XXXXXXXXXXXXXX..XX..XXXXXXX...XXXX......XXXX..P...XXXX..XX..XXXXXXXXXXXX";
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            picture[i][j] = a[counter];
            counter++;
            cout << picture[i][j];
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (picture[i][j] == 'P') {
                Paint(i, j, picture, M, N);
            }
        }
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << picture[i][j];
        }
        cout << endl;
    }

    for (int i = 0; i < M; i++) {
        delete[] picture[i];
    }
    delete[] picture;

    return 0;
}
