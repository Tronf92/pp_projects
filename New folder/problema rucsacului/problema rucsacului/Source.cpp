#include <iostream>
#include <fstream>
using namespace std;
 
ifstream f("rucsac.in");
ofstream g("rucsac.out");
ofstream h("rucsacmid.out");

int o[100],N,M;
float val[100],greu[100],x[100],Gr=400.;
 
void  citeste(){
    int i;
    f >>N>>M;
    for (i=0;i<N;i++){
        o[i]=i;
        f>>val[i]>>greu[i];
    }
    f.close();
}
 
void sort(){
    int i,aux,schimb;
    do{
        schimb=0;
        for (i=0;i<N;i++){
            if (val[o[i]]/greu[o[i]]<val[o[i+1]]/greu[o[i+1]]){
                aux=o[i];
                o[i]=o[i+1];
                o[i+1]=aux;
                schimb=1;
            }
		}
    }while (schimb);

	for(i=0;i<N;i++){
		h << o[i] << " "<<val[o[i]] << " " << greu[o[i]] << endl;
	}
}

 
void rezolva(){
    int i;
	while(Gr>=0){
		for (i=0;i<N ;i++){
			if (Gr>=greu[o[i]]){
			x[i]=o[i];
			Gr-=greu[o[i]];
			g << i+1 <<"=" << x[i] <<" " << greu[o[i]] << endl;
			g << "gr " << Gr << endl;
			}

		}
		
	}
	
}
 
void afisare(){
    int i;
    for (i=0;i<N;i++){
        
			
		
	}
    g.close();
}
 
int main(){
    citeste();
    sort();
    rezolva();
	system("pause");
    return 0;
}