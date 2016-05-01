#include "Polynomial.h"
using namespace std;


Node::Node(int coefficient = 0, Node* next = nullptr) : coeff(coefficient), link(next) {}

Polynomial::Polynomial() : coeffs(nullptr), degree(0) {}

Polynomial::Polynomial(const vector<int>& coefficients) : coeffs(nullptr), degree(coefficients.size()-1) {
	for(int coeff: coefficients){
		//cout << "Fuck you, Hung\n";
		coeffs = new Node(coeff, coeffs);
	}
}

Polynomial::Polynomial(const Polynomial& rhs){
	Node* right = rhs.coeffs;
	coeffs = new Node(right->coeff);
	Node* temp = coeffs;
	while(right->link != nullptr){
		right = right->link;
		temp->link = new Node(right->coeff);
		temp = temp->link;
	}
	degree = rhs.degree;
}

int Polynomial::evaluate(int xVal){
	int result = 0;
	Node* co = coeffs;
	for(int i = 0; i <= degree; ++i){
		result += co->coeff*pow(xVal, i);
		co = co->link;
	}
	return result;
}

Polynomial& Polynomial::operator=(const Polynomial& rhs){
	if(this != &rhs){
		Node* temp = coeffs;
		while(coeffs != nullptr){
			temp = coeffs->link;
			delete coeffs;
			coeffs = temp;
		}
		Node* right = rhs.coeffs;
		coeffs = new Node(right->coeff);
		temp = coeffs;
		while(right->link != nullptr){
			right = right->link;
			temp->link = new Node(right->coeff);
			temp = temp->link;
		}
		degree = rhs.degree;
	}
	return *this;
}

Polynomial& Polynomial::operator+=(const Polynomial& rhs){
	Node* l1 = coeffs;
	Node* l2 = rhs.coeffs;
	while((l1 != nullptr) && (l2 != nullptr)){
		l1->coeff += l2->coeff;
		l1 = l1->link;
		l2 = l2->link;
	}
	if(degree < rhs.degree){
		l1 = coeffs;
		while(l1->link != nullptr) l1 = l1->link;	//Bump Node to 2nd to last
		while(l2 != nullptr){
			l1->link = new Node(l2->coeff);
			++degree;
			l1 = l1->link;
			l2 = l2->link;
		}
	}
	return *this;
}

Polynomial::~Polynomial(){
	Node* temp = coeffs;
	while(coeffs != nullptr){
		temp = coeffs->link;
		delete coeffs;
		coeffs = temp;
	}
}

bool operator==(const Polynomial& lhs, const Polynomial& rhs){
	if(lhs.degree != rhs.degree) return false;
	Node* l1 = lhs.coeffs;
	Node* l2 = rhs.coeffs;
	while(l1 != nullptr){
		if(l1->coeff != l2->coeff) return false;
		l1 = l1->link;
		l2 = l2->link;
	}
	return true;
}

ostream& operator<<(ostream& os, const Polynomial& poly){
	Node* temp;
	for(int i = poly.degree; i >= 0; --i){
		temp = poly.coeffs;
		for(int j = 0; j < i; ++j){temp = temp->link;}
		if(i == 1){os << temp->coeff << "X + ";}
		else if(i == 0){os << temp->coeff;}
		else{os << temp->coeff << "X^" << i << " + ";}
	}
	os << endl;
	return os;
}
