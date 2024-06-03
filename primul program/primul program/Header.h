#pragma once
#include <iostream>
//#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <stdlib.h>
#include <conio.h>

using namespace std;

const int M = 10;
const int N = 10;
const int NR_AVIOANE = 3;

int pozitioneaza_avion(int x, int y, char Directie, char H[M][N]);
void initializare_harta(char H[M][N]);
void afisare_harti(char HH[M][N], char HC[M][N]);
void genereaza_aviane(char H[M][N]);
int Human_Move(char HC[M][N], char CC[M][N]);
int Computer_Move_1(char HH[M][N], char CH[M][N]);
int Computer_Move_2(char HH[M][N], char CH[M][N]);
void initializare_SA(char SA[4][5][5]);
int Calcul_Punctaj(char H[M][N]);
int Computer_Move_3(char HH[M][N], char CH[M][N]);