		#include <iostream>
#include <fstream>
#define INVALID -1
using namespace std;

int dx[8]={-1 , -2, -2, -1, 1, 2, 2, 1};
int dy[8]={-2, -1, 1, 2, 2, -2, -1, 1};
int N;
int tabla[64][2];
FILE *f;

void tiparire();
void back();
void tiparire();
void initializare();

void tiparire(int N){
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			cout << tabla[i][j] << " " ;
		}
		cout << endl;
	}
}

void initializare(int N){
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			tabla[i][j]=INVALID;
		}
	}
}

void back(){
	int k=0,pe_tabla,continuare,i;
	int delta_l,delta_c;
	int sol=0;
	    
    while (k >= 0)
    {
          /* Incercam sa plasam mutarea "k" a 
             calului in fiecare casuta a tablei 
             de joc, pe rand. Evaluam la fiecare
             alegere functia "Continuare". Ne 
             oprim fie atunci cand am incercat 
             toate casutele de pe tabla, fie
             atunci cand gasim o casuta unde 
             functia "Continuare" returneaza 
             "true". */
          do
          {
              /* Aici alegem urmatorul element 
                 din multimea "C[k]". Daca elementul 
                 "c[k]" este setat pe INVALID, 
                 inseamna ca inca nu am ales nici 
                 un element din multimea curenta, 
                 deci alegem primul element (plasam 
                 calul in casuta de la linia 0 si 
                 coloana 0). */
              if (tabla[k][0] == INVALID)
              {
                  tabla[k][0] = 0;
                  tabla[k][1] = 0;
                  pe_tabla = 1;
              }
              /* Daca elementul "c[k]" nu este setat 
                 pe invalid, inseamna ca deja am ales 
                 o casuta din multimea "C[k]". Acum 
                 alegem urmatoarea casuta de pe tabla.
                 Cu alte cuvinte incercam sa plasam 
                 calul in urmatoarea casuta. Daca este 
                 posibil incercam sa ramanem pe aceeasi 
                 linie si sa ne deplasam cu o coloana 
                 spre dreapta. */
              else if (tabla[k][1] < N-1)
              {
                  tabla[k][1]++;
                  pe_tabla = 1;
              }
              /* Daca cumva eram chiar la ultima casuta 
                 din linie, atunci alegem prima casuta 
                 din linia urmatoare. Ne asiguram ca nu 
                 eram cumva si pe ultima linie a 
                 tablei, caz in care am epuizat toate 
                 casutele. */
              else if (tabla[k][0] < N-1)
              {
                  tabla[k][1] = 0;
                  tabla[k][0]++;
                  pe_tabla = 1;
              }
              /* Daca eram pe ultima linie a tablei, 
                 atunci am epuizat toate casutele. 
                 Marcam acest lucru setand variabila 
                 "pe_tabla" pe 0. */
              else
              {
                  pe_tabla = 0;
              }
              
              /* Daca casuta "c[k]" aleasa este valida 
                 (se afla pe tabla de joc), atunci 
                 trecem la calculul functiei 
                 "Continuare". */ 
              if (pe_tabla)
              {
                  /* Daca suntem la prima mutare a 
                     calului, atunci mutarea este 
                     valida oriunde ar fi ea pe 
                     tabla. */
                  if (k == 0)
                      continuare = 1;
                  /* Daca nu suntem la prima mutare, 
                     atunci trebuie sa facem o serie 
                     de verificari. */
                  else
                  {
                    /* In primul rand verificam daca 
                       de la pozitia precedenta a 
                       calului pe tabla ("c[k-1]") 
                       se poate ajunge in pozitia
                       aleasa acum printr-o mutare. 
                    */
                    delta_l = abs(tabla[k-1][0]-tabla[k][0]);
                    delta_c = abs(tabla[k-1][1]-tabla[k][1]);
                    continuare = (((delta_l == 1) && 
                                   (delta_c == 2)) ||
                                  ((delta_l == 2) && 
                                   (delta_c == 1)));
    
                    /* Si apoi verificam daca nu 
                       cumva s-a mai trecut prin 
                       casuta aleasa acum. */                  
                    for (i=0; continuare && (i<k); i++)
                    {
                        if ((tabla[i][0] == tabla[k][0]) && 
                            (tabla[i][1] == tabla[k][1]))
                            continuare = 0;
                    }
                  }
              }    
              /* Daca casuta "c[k]" aleasa este in 
                 afara tablei de sah, atunci functia 
                 "Continuare" va returna automat 
                 "false". */
              else
              {
                  continuare = 0;
              }
          }
          while (!continuare && pe_tabla);

          /* Daca am obtinut rezultat pozitiv in urma 
             verificarilor de "Continuare", atunci
             consideram piesa asezata la pozitia "c[k]"
             si continuam cautarea. */                   
          if (continuare)
          {    
              /* Daca s-a parcurs toata tabla de sah
                 atuntablai afisam solutia. */
              if (k == N*N - 1)
              {
                    for (i=0; i<N*N; i++)
                        printf("(%d,%d) ", tabla[i][0], 
                                        tabla[i][1]);
                    printf("\n");
                    sol++;
              }
              /* Daca nu s-a parcurs inca toata tabla 
                 atunci trecem cu un pas inainte pe
                 calea de cautare. */
              else
              {
                  k++;
              }
          }
          
          /* Daca casuta aleasa nu este valida, atunci 
             marcam elementul "c[k]" cu INVALID si 
             revenim cu un pas inapoi pe calea de 
             cautare. */
          else
          {
              tabla[k][0] = INVALID;
              tabla[k][1] = INVALID;
              k--;
          }
    }

	cout << "nr de solutii " << sol << endl;
}
		
int main(){
	int i,j,sir[100][100];
	cout << "Introduceti marimea tablei de sah(o tabla de sah este de forma NxN)" << endl;
	cin >> N;
	initializare(N);
	back();
	tiparire(N);




	system("pause");
	return 0;
}