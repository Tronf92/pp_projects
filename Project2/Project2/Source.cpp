#include <iostream>
using namespace std;

int x(int i){
	
	if(i<0){
		return 1;
	}
	
	return x(i-1)+x(i-2);
}

int main(){
	cout << x(3);
	
	system("pause");
	return 0;

}
