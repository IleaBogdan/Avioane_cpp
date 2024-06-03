#include "header.h"


int pozitioneaza_avion(int x, int y, char Directie, char H[M][N])
{
    if (Directie == 'V' || Directie == 'E') {
        int xx = 1;
        if (Directie == 'V')
            xx = 1;
        else xx = -1;
        if (y<2 || y > N - 3 || (xx == 1 && x > M - 4) || (xx == -1 && x < 3)) {
            return 1;
        }
        if (H[x][y] != '.' || H[x + 1 * xx][y] != '.' || H[x + 1 * xx][y + 1] != '.' || H[x + 1 * xx][y - 1] != '.'
            || H[x + 1 * xx][y + 2] != '.' || H[x + 1 * xx][y - 2] != '.' || H[x + 2 * xx][y] != '.' || H[x + 3 * xx][y] != '.' ||
            H[x + 3 * xx][y + 1] != '.' || H[x + 3 * xx][y - 1] != '.') {
            return 2;
        }
        H[x][y] = 'x';
        H[x + 1 * xx][y] = '0';
        H[x + 1 * xx][y + 1] = 'o';
        H[x + 1 * xx][y - 1] = 'o';
        H[x + 1 * xx][y + 2] = 'o';
        H[x + 1 * xx][y - 2] = 'o';
        H[x + 2 * xx][y] = '0';
        H[x + 3 * xx][y] = '0';
        H[x + 3 * xx][y + 1] = 'o';
        H[x + 3 * xx][y - 1] = 'o';


    }
    else {
        int yy = 1;
        if (Directie == 'N')
            yy = 1;
        else yy = -1;
        if (x<2 || x > M - 3 || (yy == 1 && y > N - 4) || (yy == -1 && y < 3)) {
            return 1;
        }
        if (H[x][y] != '.' || H[x][y + 1 * yy] != '.' || H[x - 1][y + 1 * yy] != '.' || H[x + 2][y + 1 * yy] != '.'
            || H[x - 2][y + 1 * yy] != '.' || H[x][y + 2 * yy] != '.' || H[x][y + 3 * yy] != '.' ||
            H[x + 1][y + 3 * yy] != '.' || H[x - 1][y + 3 * yy] != '.') {
            return 2;
        }
        H[x][y] = 'x';
        H[x][y + 1 * yy] = '0';
        H[x + 1][y + 1 * yy] = 'o';
        H[x - 1][y + 1 * yy] = 'o';
        H[x + 2][y + 1 * yy] = 'o';
        H[x - 2][y + 1 * yy] = 'o';
        H[x][y + 2 * yy] = '0';
        H[x][y + 3 * yy] = '0';
        H[x + 1][y + 3 * yy] = 'o';
        H[x - 1][y + 3 * yy] = 'o';


    }


    return 0;
}
void initializare_harta(char H[M][N])
{
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            H[i][j] = '.';
        }
    }
}
void afisare_harti(char HH[M][N], char HC[M][N])
{
    cout << "     ";
    for (int x = 0; x < M; x++) {
        char c = 'A' + x;
        cout << c << "  ";
    }
    cout << "          ";
    cout << "     ";
    for (int x = 0; x < M; x++) {
        char c = 'A' + x;
        cout << c << "  ";
    }


    cout << "\n";
    for (int y = 0; y < N; y++) {

        if (y < 10) {
            cout << " ";
        }
        cout << y << "   ";
        for (int x = 0; x < M; x++) {
            cout << HH[x][y] << "  ";
        }
        cout << "          ";
        if (y < 10) {
            cout << " ";
        }
        cout << y << "   ";
        for (int x = 0; x < M; x++) {
            cout << HC[x][y] << "  ";
        }



        cout << endl;

    }


}
void genereaza_aviane(char H[M][N])
{
    int numar_avioana_generate;
    numar_avioana_generate = 0;
    int incercari_pozitionare = M * N * M * N;

    while (NR_AVIOANE > numar_avioana_generate) {
        int x = rand() % M;
        int y = rand() % N;
        int z = rand() % 3;
        char directie = 0;
        if (z == 0) directie = 'N';
        if (z == 1) directie = 'S';
        if (z == 2) directie = 'V';
        if (z == 3) directie = 'E';
        if (pozitioneaza_avion(x, y, directie, H) == 0)
            numar_avioana_generate++;
        incercari_pozitionare--;
        if (incercari_pozitionare == 0)
            break;

    }

}
void initializare_SA(char SA[4][5][5])
{
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++) {
            SA[0][i][j] = ' ';
        }
    SA[0][2][0] = 'x';
    SA[0][2][1] = '0';
    SA[0][2][2] = '0';
    SA[0][2][3] = '0';
    SA[0][0][1] = 'o';
    SA[0][1][1] = 'o';
    SA[0][3][1] = 'o';
    SA[0][4][1] = 'o';
    SA[0][1][3] = 'o';
    SA[0][3][3] = 'o';

    for (int k = 1; k < 4; k++) {
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++) {
                SA[k][j][5 - i - 1] = SA[k - 1][i][j];
            }
    }
    /*for (int k = 0; k < 4; k++) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cout << SA[k][i][j] << "  ";
            }
            cout << endl;
        }
        cout << endl;
    }*/


}
