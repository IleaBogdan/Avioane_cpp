#include "Header.h"
int Human_Move(char HC[M][N], char CC[M][N])
{
    int x, y;
    char cod[100];
    while (true) {
        cout << endl << "Introduceti coordonta:";
        cin >> cod;
        //cout << endl;
        if (strcmp(cod, "?") == 0) {
            cout << "Coordonatele se introduc cu litera si cifra (A3).";
            cout << "Pentru incheierea jocului trebuie sa fie doborate toate avioanele in cap sau sa se introduca End.";
        }
        if (strcmp(cod, "End") == 0) {
            cout << "Joc Terminat";
            return 0;
        }
        if (cod[0] < 'A' || ('A' + M - 1) < cod[0]) {
            cout << "Coordonata gresita";
            continue;
        }

        y = atoi(cod + 1);
        if (y<0 || y>(N - 1)) {
            cout << "Coordonata gresita";
            continue;
        }
        x = cod[0] - 'A';
        //cout << x << ' ' << y<< ' '<< CC[x][y]<< endl<<endl;
        char cc = CC[x][y];
        if (cc == '.') {
            cc = '_';
        }
        HC[x][y] = cc;
        break;
    }
    return 1;
}