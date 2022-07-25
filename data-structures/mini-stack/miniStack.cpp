#include <iostream>
#include <istream>
#include <string>
#include "miniStack.h"
using namespace std;

int main()
{
	/* 
		Palindrome
	*/
	miniStack<char> pal;
	pal.palindrome();

	/*
		Hexidecimal Conversion
	*/
	miniStack<int> hex;
	hex.multibaseOutput();

	/*
		Balanced Parenthesis
	*/
	string line;
	miniStack<bool> fcheck;
	if (fcheck.balance(line))
		cout << "Balanced parenthesis." << endl;
	else
		cout << "Unbalanced parenthesis." << endl;

	return 0;
}
