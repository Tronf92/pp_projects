#include <iostream>
using namespace std;


int main() {
	int p,a,n,sir[100];
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> sir[i];
	}
	cin >>a;
	p=0;
	if(a<=sir[0]) p=0;
	else if (a>sir[n-1] ) p=n;
	else 
		for(int i=0;i<n;i++){
			if(p==0 && a<=sir[i]){
				p=i;
			}
		}
	cout << p;
	

	system("pause");
	return 0;
}