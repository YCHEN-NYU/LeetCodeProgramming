/*

题目：利用条件运算符的嵌套来完成此题：学习成绩>=90分的同学用A表示，60
-89分之间的用B表示，60分以下的用C表示。
*/

#include <iostream>
using namespace std;

char grade_to_ABC(int grade) {
	if(grade >= 90)	return 'A';
	else if(grade >= 60)	return 'B';
	else return 'C';
}


int main(){
	int grade;
	cout << "grade = ";
	if(!(cin>>grade))	
		cout << "Invalid input" << endl;
	else 
		if(grade < 0 || grade > 100)
			cout << "grade < 0 or grade > 100" << endl;
		else
			cout << grade << " <-> " << grade_to_ABC(grade) << endl;

}