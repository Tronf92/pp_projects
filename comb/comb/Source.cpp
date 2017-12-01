#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>



int x[200],n,p,nr=1;
char tab[100];
/*int valid(int k) {
    int j;
 for( j=1;j<k&&x[j-1]<k;j++)
		 if(x[j]==x[k])
			 return 0;
	 return 1;
 }*/
void afiseaza(){
    int j;
    printf ("\n Solutia nr %d: ",nr++);
    for (j=1;j<=p;j++) printf ("%c ",x[j]);
}
void comb(int k,int f) {
int i=0;

	  for(k;k<=tab[n-1];k++)
		 {	     
			 x[i]=k;
			 i++;
			 if(i==p)
                    afiseaza();
             else
				 comb(k+1,p);
			 
		 }
		 
}

int main() {
    int k,f;
    printf("Introduceti n un numar natural <=200:");
    scanf("%d",&n);
    printf("Introduceti p <=200:");
    scanf("%d",&p);
    printf("Introduceti intervalul:\n");
    scanf("%s",&tab);
    k=tab[0];
	f=tab[n-1];
    printf("%d",k);
    comb(k,f);
	system("pause");
}
