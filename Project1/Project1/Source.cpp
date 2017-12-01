#include <iostream>
#include <math.h>
using namespace std;
int i,n,S,nr;
int b[]={500,200,100,50,10,5,1};

void sort(int n, int b[])
{ 
	int ok=0,aux,i; while(ok==0)
{ ok=1; for(i=0;i<=n-1;i++)
    if(b[i]<b[i+1])
    { aux=b[i]; b[i]=b[i+1];
      b[i+1]=aux; ok=0; } } }

int main()
{
cout<<"S= "; cin>>S;
if(S>4000){
	cout << "Suma prea mare" << endl;
}
else{


sort(7,b);
i=0;


while(S!=0)
{ if(S/b[i]!=0)
{ cout<<S/b[i]<<" bancnote de valoare "<<b[i]<<endl;
S=S-(S/b[i])*b[i]; }
i++; }
}
   
system("pause");
return 0;
}
