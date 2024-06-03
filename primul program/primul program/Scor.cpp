#include "Header.h"


int Calcul_Punctaj(char H[M][N])
{
	int Punctaj = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (H[i][j] != '.' && H[i][j] != '_') {
				Punctaj++;
			}
		}
		
	}
	return Punctaj;
}