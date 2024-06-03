#include "header.h"

char CC[M][N];
char CH[M][N];
char HH[M][N];
char HC[M][N];
char SA[4][5][5];

int main()
{
    while (true) {
        system("CLS");
        int Punctaj_Calculator, Punctaj_Om;
        int nr_lovituri = 0;
        int Dificultate;
        cout << "Alegeti expertiza calculatorului." << endl << "1 = La intamplare" << endl << "2 = Probabilitati" << endl << "3 = Probabilitati mai exacte" << endl << "Expertiza = ";
        cin >> Dificultate;
        if (Dificultate != 1 && Dificultate != 2 && Dificultate != 3) {
            cout << "Expertiza incorecta!" << endl << "Alegeti expertiza calculatorului." << endl << "1 = La intamplare" << endl << "2 = Probabilitati" << endl << "3 = Probabilitati mai exacte" << endl << endl << "Epertiza = ";
            cin >> Dificultate;
        }

        srand((unsigned int)time(0));
        initializare_SA(SA);

        initializare_harta(CC);
        initializare_harta(CH);
        initializare_harta(HH);
        initializare_harta(HC);


        genereaza_aviane(HH);
        genereaza_aviane(CC);


        while (true) {
            afisare_harti(HH, HC);
            cout << endl;
            //afisare_harti(CC, CH);

            int hm;
            hm = Human_Move(HC, CC);
            if (hm == 0) break;

            /*for (int i = 1; i <= 20; i++) {
                Computer_Move_2(HH, CH);
            }*/
            if (Dificultate == 1) {
                Computer_Move_1(HH, CH);
            }
            if (Dificultate == 2) {
                Computer_Move_2(HH, CH);
            }
            if (Dificultate == 3) {
                Computer_Move_3(HH, CH);
            }

            system("CLS");
            Punctaj_Om = Calcul_Punctaj(HC);
            Punctaj_Calculator = Calcul_Punctaj(CH);

            cout << endl << "Punctaj   " << Punctaj_Om << "    " << Punctaj_Calculator << endl;
            if (Punctaj_Om == 10 * NR_AVIOANE && Punctaj_Calculator == 10 * NR_AVIOANE) {
                cout << "----- Egalitate! -----";
                break;
            }
            else if (Punctaj_Om == 10 * NR_AVIOANE) {
                cout << "----- Joc castigat! -----";
                break;
            }
            else if (Punctaj_Calculator == 10 * NR_AVIOANE) {
                cout << "----- Ai pierdut! -----";
                break;

            }
            nr_lovituri++;
            cout << "Lovituri = " << nr_lovituri << endl;
            cout << "(Pentru ajutor apasati '?')" << endl;


        }
        cout << endl;
        cout << "Vrei sa mai joci o data?" << endl;
        char rejoaca[2];
        cin >> rejoaca[0] >> rejoaca[1];
        if (((rejoaca[0] == 'N') && (rejoaca[1] == 'U')) || ((rejoaca[0] == 'N') && (rejoaca[1] == 'u')) || ((rejoaca[0] == 'n') && (rejoaca[1] == 'u')) || ((rejoaca[0] == 'n') && (rejoaca[1] == 'u'))) break;
        cout << endl;
    }




    return 0;

}
