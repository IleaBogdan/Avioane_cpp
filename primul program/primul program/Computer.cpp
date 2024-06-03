#include "Header.h"

extern char SA[4][5][5];

int Computer_Move_1(char HH[M][N], char CH[M][N])
{
    int x, y;
    do {

        y = rand() % N;
        x = rand() % M;
    } while (CH[x][y] != '.');
    char hh = HH[x][y];
    if (hh == '.') {
        hh = '_';
    }
        CH[x][y] = hh;
        if (HH[x][y] != '.') {
            HH[x][y] = '*';
        }
        else HH[x][y] = '_';
    
    return 1;
}
int Computer_Move_2(char HH[M][N], char CH[M][N])
{
    int P[M][N];
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            P[i][j] = 0;

    for (int k = 0; k < 4; k++) {
        k++;
        k--;
        for (int i = -5; i < M; i++) {
            for (int j = -5; j < N; j++) {
                bool posibil = true;
                for (int ii = 0; ii < 5; ii++) {
                    for (int jj = 0; jj < 5; jj++) {
                        if (SA[k][ii][jj] == ' ') continue;
                        if ((i + ii >= M) || (i + ii < 0)) {
                            posibil = false;
                            break;
                        }
                        if ((j + jj >= N) || (j + jj < 0)) {
                            posibil = false;
                            break;
                        }
                        if (CH[i + ii][j + jj] != '.' && CH[i + ii][j + jj] != SA[k][ii][jj]) {
                            posibil = false;
                            break;
                        }
                    }
                    if (!posibil) break;
                }
                if (posibil) {
                    for (int ii = 0; ii < 5; ii++) {
                        for (int jj = 0; jj < 5; jj++) {
                            if (SA[k][ii][jj] == ' ') continue;
                            if ((i + ii >= M) || (i+ii<0)) break;
                            if ((j + jj >= N)||(j+jj<0)) break;
                            if (CH[i + ii][j + jj] == '.')
                                P[i + ii][j + jj] = P[i + ii][j + jj] + 1;
                        }
                    }
                }
            }
        }
    }
   /* for (int j = 0; j < N; j++) {
        for (int i = 0; i < M; i++) {
            cout << P[i][j] << " ";
            
        }
        cout << endl;
    }
    cout << endl;*/




    int x=0, y=0;
    //y = rand() % N;
    //x = rand() % M;
    int max = 0;
    for (int i=0; i<M; i++)
        for (int j = 0; j < N; j++) {
            if (max < P[i][j]) {
                max = P[i][j];
                x = i;
                y = j;
            }
        }




    char hh = HH[x][y];
    if (hh == '.') {
        hh = '_';
    }
    CH[x][y] = hh; 

    if (HH[x][y] != '.') {
        HH[x][y] = '*';
    }
    else HH[x][y] = '_';

    return 1;
}
int Computer_Move_3(char HH[M][N], char CH[M][N])
{
    int P[M][N];
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            P[i][j] = 0;

    for (int k = 0; k < 4; k++) {
        k++;
        k--;
        for (int i = -5; i < M; i++) {
            for (int j = -5; j < N; j++) {
                int posibil = 1;
                for (int ii = 0; ii < 5; ii++) {
                    for (int jj = 0; jj < 5; jj++) {
                        if (SA[k][ii][jj] == ' ') continue;
                        if ((i + ii >= M) || (i + ii < 0)) {
                            posibil = 0;
                            break;
                        }
                        if ((j + jj >= N) || (j + jj < 0)) {
                            posibil = 0;
                            break;
                        }
                        if (CH[i + ii][j + jj] != '.' && CH[i + ii][j + jj] != SA[k][ii][jj]) {
                            posibil = 0;
                            break;
                        }
                        if (CH[i + ii][j + jj] == SA[k][ii][jj]) {
                            posibil++;
                        }
                    }
                    if (posibil==0) break;
                }
                if (posibil!=0) {
                    for (int ii = 0; ii < 5; ii++) {
                        for (int jj = 0; jj < 5; jj++) {
                            if (SA[k][ii][jj] == ' ') continue;
                            if ((i + ii >= M) || (i+ii<0)) break;
                            if ((j + jj >= N) || (j+jj<0)) break;
                            if (CH[i + ii][j + jj] == '.')
                                P[i + ii][j + jj] = P[i + ii][j + jj] + posibil;
                        }
                    }
                }
            }
        }
    }
     /*for (int j = 0; j < N; j++) {
         for (int i = 0; i < M; i++) {
             cout << P[i][j] << " ";

         }
         cout << endl;
     }
     cout << endl;*/




    int x = 0, y = 0;
    //y = rand() % N;
    //x = rand() % M;
    int max = 0;
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++) {
            if (max < P[i][j]) {
                max = P[i][j];
                x = i;
                y = j;
            }
        }




    char hh = HH[x][y];
    if (hh == '.') {
        hh = '_';
    }
    CH[x][y] = hh;

    if (HH[x][y] != '.') {
        HH[x][y] = '*';
    }
    else HH[x][y] = '_';

    return 1;
}