#pragma once
class Rational
{
private:
	int numerator, denominator;
	
public:
	//******************Constructors & Deconstructors *********************
	Rational();						//constructor takes no value.
	Rational(int);					//constructor takes one value.
	Rational(int, int);				//constructro takes tow values.
	~Rational();					//deconstructor.
	//*********************************************************************



	//*****************Accessors and Mutators*******************************
	int get_numerator()const;		//returns numerator's value.
	int get_denominator()const;		//returns denominator's value.
	double get_double_value()const; //returns the double value of the rational number.
	void set_numerator(int);		// to change numerator's value.
	void set_denominator(int);		//to change denominator's value.
	//**********************************************************************
	

	//**********************Read & Display**********************************
	void Read();					//read the fraction in a/b formla.
	void Display()const;			//display the fraction in a/b formla.
	void Displaay_reduced()const;	//display the fraction after reducing. 
	void Display_mixed_fraction()const;//display the fraction in mixed fraction  a+b/c.
	void Display_double_value()const;// displays the double value of the fraction .
	//**********************************************************************


	//***********************Arthimatic Operators***************************
	Rational operator+ (const Rational&)const;//the + operator to add tow rational numbers.
	Rational operator- (const Rational&)const;//the - operator to subtract tow rational numbers.
	Rational operator* (const Rational&)const;//the * operator to  multiply tow rational numbers.
	Rational operator/ (const Rational&)const;//the / operator to  divide tow rational numbers.
	//**********************************************************************


	//*************************Comparison operators*************************
	bool operator=  (const Rational &)const;
	bool operator!= (const Rational &)const;			
	bool operator<  (const Rational &)const;
	bool operator>  (const Rational &)const;
	bool operator<= (const Rational &)const;
	bool operator>= (const Rational &)const;
	//**********************************************************************


	//************************Invert & Reduce Functions*********************
	Rational invert ()const;              //returns the fraction inverted (a/b) -> (b/a) .
	Rational reduce ()const;			  //returns the fraction  reduced .
	//**********************************************************************


	//************************Other functions********************************
	int gcd(int, int)const;					//returns the gcd between two integer numbers.
	int get_gcd()const;						//returns the gcd between the numerator and the denominator.
	int get_lcm(Rational &)const;			//returns the lcm between denominatros of tow fractions.
	//************************************************************************


};

