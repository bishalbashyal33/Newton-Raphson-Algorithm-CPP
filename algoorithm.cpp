/*Develop an algorithmand program in C / C++ to find a real root of a polynomialequation of any d
egree given it’s co - efficients.Hint:  construct different functionsfor the evaluation of polynomial and 
it’s derivative at a given point given theco - efficients.Forndegree polynomial : 
f(x) = a0 + n∑i = 1aixif′(x) = a1 + n∑i = 2i×aixi−1wherea0is the constant term anda1, a2, . . ., 
anare the coefficients ofx, x2, . . ., xnof the polynomial equation of degreen*/




#include <iostream>
#include <math.h>
double f(int, double*, double*);
double derivf(int, double*, double*);
double rootCalc(double, double, double*);




int main() {
	std::cout << "Enter the degree of polynomial";
	int degree;
	std::cin >> degree;
	double a = 0, b = 0, e, x0 = 0,root = 0;
	double* refx0 = &x0;
	std::cout << "Enter the tolerance";
	std::cin >> e;
	std::cout << "Enter the coefficient in a0, a1 ,a2,a3 format";
    double* coef = new double[degree+1];
	for(int i = 0; i <= degree; i++) {
		std::cin >> coef[i];
		
	}

	while (f(degree, coef, &a) * f(degree, coef, &b) > 0) {
		std::cout << "Re/Enter the interval limits";
			std::cin >> a;
			std::cin>>b;
		*refx0 = (a + b) / 2;
	} 


	while (f(degree,coef,refx0) >= e) {
		root = rootCalc(f(degree, coef, refx0), derivf(degree, coef, refx0), refx0);

	}
	

	std::cout << "The root is" << root;
	delete[] coef;
	return 0;
}

double f(int degree, double *coef, double* x0) {
	double value = 0;
	for (int i = 0; i < degree + 1; i++) {
		value = value + coef[i] * pow(*x0, i);
	}
		return value;
}

double derivf(int degree, double* coef, double* x0) {
	double value = 0;
	for (int i = 1; i < degree + 1; i++) {
		value += i*coef[i] * pow(*x0, i-1);
	}
	return value;
}

double rootCalc(double f, double df, double* x0) {
	
		*x0 = *x0 - (f / df);

	return *x0;
}


	




