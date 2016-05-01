#include <vector>
#include <iostream>

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
struct Node{
	Node(int coefficient, Node* next);
	int coeff;
	Node* link;
};

class Polynomial{
	friend std::ostream& operator<<(std::ostream& os, const Polynomial& poly);
	friend bool operator==(const Polynomial& lhs, const Polynomial& rhs);
public:
	Polynomial();
	Polynomial(const std::vector<int>& coefficients);
	Polynomial(const Polynomial& rhs);
	int evaluate(int xVal);
	Polynomial& operator=(const Polynomial& rhs);
	Polynomial& operator+=(const Polynomial& rhs);
	~Polynomial();
private:
	Node* coeffs;
	int degree;
};

int pow(int base, int exp);
bool operator!=(const Polynomial& lhs, const Polynomial& rhs);
Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs);

#endif
