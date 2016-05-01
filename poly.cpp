#include <iostream>
#include <vector>
#include "Polynomial.h"
using namespace std;

int main(){
	Polynomial p1({1,2,3});
	Polynomial p2({1, 2, 1});
//	Polynomial p3({});
//	cout << p1;
	cout << p2;
//	cout << p3;
	p1=p2;
//	cout << p1;
//	cout << p2;
	cout << pow(2, 3) << endl << pow(3, 2) << endl << pow(10, 3) << endl;
	cout << p2.evaluate(2);
}

int pow(int base, int exp){
	int result = base;
	if(exp == 0) return 1;
	else if(exp != 1){
		for(int i = 0; i < exp-1; ++i){
			result*=base;
		}
	}
	return result;
}

bool operator!=(const Polynomial& lhs, const Polynomial& rhs){
	return !(lhs == rhs);
}

Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs){
	Polynomial result(lhs);
	return result += rhs;
}
