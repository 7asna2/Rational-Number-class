#include "Rational.h"
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

//************************constructors and Deconstructors**********************
Rational::Rational()                                                         
{                                                                            
	set_numerator(0);                                                        
	set_denominator(1);                                                      
}
Rational::Rational(int num)
{
	numerator = num;
	//set_numerator(num);
	//set_denominator(1);
}
Rational::Rational(int num, int denum){
	numerator = num;
	denominator = denum;
	//set_numerator(num);
	//set_denominator(denum);
}
Rational::~Rational()
{
}
//****************************************************************************



//************************Accessors and Mutators******************************
int Rational::get_denominator()const{
	return denominator;
}
int Rational::get_numerator()const{
	return numerator;
}
double Rational::get_double_value()const{
	return (double)get_numerator() / get_denominator();
}
void Rational::set_denominator(int denum)throw (int){
	try{
		denominator = denum;
		if (denum == 0)
			throw 20;
	}
	catch (int e){
		throw;
	}
}
void Rational::set_numerator(int num){
	numerator = num;
}
//****************************************************************************



//**********************Read and Display functions*****************************
void Rational::Read(){
	
	char operator1;
	cin >> numerator>> operator1 >> denominator;
	while
		(operator1 != '/')
	{

		cout << "Error! please enter /" << endl;
		cin >> numerator>> operator1 >> denominator;
	}

	/*
	int num, denum;
	char operator1;
	do{
		try {
			cin >> num >> operator1 >> denum;
			if (operator1 != '/')
				throw(2);
			set_numerator(num);
			set_denominator(denum);
			break;
		}
		catch (int e){
			if (e == 20)
				cout << "you cant divide by Zero !!\n";
			if (e == 2)
				cout << "you must use operator '/'to enter Rational number \n ";
		}
		catch (...) {
			cout << "you must enter the rational number in this formla 'a/b'\n while a & b integer numbers\n";
		}
	} while (true);*/
	
}
void Rational::Display()const{
	if (!get_numerator())
		cout << 0;
	else
	if (get_denominator() == 1)
		cout << get_numerator();
	else{
		int a = get_numerator(), b = get_denominator();
		if ((a<0 && b <0) || (a>0 && b >0))
			cout << abs(a) << "/" << abs(b);
		else
			cout << "-" <<abs(a) << "/" << abs(b);
	}
}

void Rational::Displaay_reduced()const{
	reduce().Display();
}

void Rational::Display_mixed_fraction()const{
	int integer = get_numerator() / get_denominator();
	Rational rational (get_numerator() % get_denominator(), get_denominator());
	if (integer!=0)
		cout << integer;
	if ((double)rational.get_numerator() / rational.get_denominator() > 0 && integer!=0)
	{
		cout << "+";
	}
	if ((double)rational.get_numerator() / rational.get_denominator() != 0)
		rational.Display();
	

}
void Rational::Display_double_value()const{
	cout << get_double_value();
}

//****************************************************************************************



//**************************Arthimatic Operators******************************************
Rational Rational::operator*( const Rational & Rational1)const{
	return Rational(numerator*Rational1.get_numerator(),denominator*Rational1.get_denominator());
}

Rational Rational::operator/(const Rational & Rational1)const{
	Rational Rational2 = Rational1.invert();
	return Rational(numerator*Rational2.get_numerator(), denominator*Rational2.get_denominator());
}

Rational Rational::operator+(const Rational & Rational1)const{
	return Rational(   (numerator*Rational1.get_denominator() + denominator*Rational1.get_numerator() ),  denominator*Rational1.get_denominator() );
}

Rational Rational::operator-(const Rational & Rational1)const{
	return Rational(   (numerator*Rational1.get_denominator() - denominator*Rational1.get_numerator() ) , denominator*Rational1.get_denominator() );
}
//********************************************************************************



//************************Comparison operators************************************
bool Rational :: operator = (const Rational & Rational1)const{
	Rational R1 = reduce() , R2 =Rational1.reduce();
	return ((R1.get_numerator() == R2.get_numerator()) && (R1.get_denominator() == R2.get_denominator()));
	
}

bool Rational :: operator< (const Rational & Rational1)const{
	double r1 = (double)get_numerator() / get_denominator();
	double r2 = (double)Rational1.get_denominator()/Rational1.get_denominator();

	return (r1 < r2);
}

bool Rational :: operator> (const Rational & Rational1)const{
	double r1 = (double)get_numerator() / get_denominator();
	double r2 = (double)Rational1.get_denominator() / Rational1.get_denominator();

	return (r1 > r2);
}

bool Rational :: operator>= (const Rational & Rational1)const{
	double r1 = (double)get_numerator() / get_denominator();
	double r2 = (double)Rational1.get_denominator() / Rational1.get_denominator();

	return (r1 >= r2);
}

bool Rational :: operator<= (const Rational & Rational1)const{
	double r1 = (double)get_numerator() / get_denominator();
	double r2 = (double)Rational1.get_denominator() / Rational1.get_denominator();

	return (r1 <= r2);
}
//********************************************************************************



//**************************Invert************************************************
Rational Rational::invert()const{
	return Rational(get_denominator(), get_numerator());
}
//********************************************************************************

//*************************Reduce*************************************************
Rational Rational::reduce()const{
	int GCD = get_gcd();
	return Rational(get_numerator() / GCD, get_denominator() / GCD);
}
//********************************************************************************

//********************* get the gcd between the numerator and denominator*********
int Rational :: get_gcd()const
{
	int x = get_denominator();
	int y = get_numerator();
	if (x < y)
		swap(x, y);
	return gcd(x, y);
}
//*********************************************************************************
//************************get the lcm between 2 fractions denmominators************
int Rational::get_lcm(Rational & Rational1) const {
	int a = get_denominator();
	int b = Rational1.get_denominator();
	return (a*b) / gcd(abs(a), abs(b));
}
//*********************************************************************************
//*****************function to get the gcd between 2 integers**********************
int Rational::gcd(int num1,int num2)const{
		return num2 == 0 ? num1 : gcd(num2, num1 % num2);
}
//*********************************************************************************
