#include <iostream>
#include <iomanip>
using namespace std;

int main() {

	for(int i = 1; i <= 9; i++){
		cout << setw(4) << i-1;
		if(i%3 == 0) cout << endl;
	}

	return 0;
}
		
