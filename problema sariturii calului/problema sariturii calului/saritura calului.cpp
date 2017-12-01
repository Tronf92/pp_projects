#include <iostream>
using namespace std;
int n,tabla[50][50];

void afisare_tabla(int n);
void saritura(int x, int y,int pas);
int solutii=0;

void afisare_tabla(int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout <<" " <<  tabla[i][j] ;
		}
		cout << endl;
	}
}

void saritura(int x,int y,int pas){
	if ( (x<0) || (y<0) || (x>=n) || (y>=n) ){
		return ;
	}
	//verifica daca pozitia este libera
	if(tabla[x][y]!=0){
		return;//pozitia este ocupata
	}
	//pozitia libera,o ocup
	tabla[x][y]=pas;
	if(pas==n * n ){
		solutii++;
		cout << "Solutia ------- " << solutii << "-------- " << endl;
		cout << "Solutia este: " << endl;
		afisare_tabla( n);
	}
	else{
		saritura(x-1,y-2,pas+1);
		saritura(x-2,y-1,pas+1);
		saritura(x-2,y+1,pas+1);
		saritura(x-1,y+2,pas+1);
		saritura(x+1,y+2,pas+1);
		saritura(x+2,y+1,pas+1);
		saritura(x+2,y-1,pas+1);
		saritura(x+1,y-2,pas+1);
	}
	tabla[x][y]=0;
}

int main(){
	int x,y,pas=1;
	cout << "Tabla de sah este de dimensiune NxN" << endl;
	cout << "Introduceti dimensiunea tablei de sah"<< endl;
	cin >> n;
	if(n<0){
		cout << "Numarul trebuie sa fie pozitiv" << endl;
		while(n<0){
			cin >> n;
		}
	}
	cout << "Introduceti pozitia initiala a calului" << endl;
	cin >> x >> y;
	if( (x<0) && (y<0) ){
		cout << "Pozitia incorecta" << endl;
		while( x<0 || y < 0 ){
			cout << "Introduceti pozitia din nou" << endl;
			cin >> x >> y;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			tabla[i][j]=0;
		}
	}
	saritura(x,y,pas);
	system("pause");
	return 0;
}