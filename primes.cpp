#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

bool isPrime(int n){
	if(n < 2) return false;
	for(int i = 2; i*i <= n; i++)
		if(n % i == 0)	return false;
	
	return true;
}

vector<int> brute_force(int N){
	vector<int> result;
	for(int i = 2; i <= N; i++)
		if(isPrime(i))	result.push_back(i);
	return result;
}

// Sieve of Eratosthenes
vector<int> Sieve(int upperBound){
	vector<int> numList;
	for(int i = 2; i <= upperBound; i++)	numList.push_back(i);
	
	vector<int> primeList;
	int iStart = 2;
	bool flag = true;

	while(iStart < upperBound && flag){
		// erase multiples from the list by jumping with step = iStart
		// set corresponding number to zero
		int i = iStart*2;
		while(i <= upperBound){
			numList[i] = 0;
			i = i + iStart;
		}

		// search for the next non-zero number from iStart + 1 to N
		flag = false;
		for(int j = iStart + 1; j < upperBound; j++){
			if(numList[j] != 0){
				iStart = j;
				flag = true;
				break;
			}
		}
	}
	
	// save prime numbers to primeList
	for(int i = 2; i <= upperBound; i++)
		if(numList[i] != 0)	primeList.push_back(i);

	return primeList;
}



int main() {

	vector<int> primeList = Sieve(1000);
	

	for(int i = 0; i < primeList.size(); i++){
		if((i)%10 == 0)	cout << endl;
		cout << setw(8) << primeList[i] << ' ';
	}
	cout << endl;

	return 0;
}
