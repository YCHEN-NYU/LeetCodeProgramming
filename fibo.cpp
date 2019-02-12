#include <iostream>
#include <vector>
using namespace std;


void fibo(int n, vector<int> & arr){
	if(n == 0 || n == 1){
		arr[n] = 1;
	}
	else {
			arr[n] = arr[n - 1] + arr[n - 2];
	}
}

int fibo(int n){
	if(n == 0 || n == 1)
		return 1;
	else 
		return fibo(n - 1) + fibo(n - 2);
}




int main() {
	int n = 10;
	vector<int> arr;
	for(int i = 0; i < n; i++)	arr.push_back(0);

	for(int i = 0; i < n; i++){
		fibo(i, arr);
		cout << "fibo(" << i << ") = " << arr[i] << endl;
	}
}