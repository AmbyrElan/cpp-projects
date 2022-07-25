#pragma once
#include <iostream>
#include <fstream>

using namespace std;

template <typename T>
class miniStack
{
private:
	T* ptr;
	int counter;
	int length;
public:
	miniStack(int s = 0);
	bool empty() const;
	int size() const;
	void push(const T& item);
	void pop();
	T& top();
	miniStack<T>& operator=(const miniStack<T>& rhs);

	void palindrome();
	void multibaseOutput();
	bool balance(string line);

};

template<typename T>
miniStack<T>::miniStack(int s)
{
	if (s > 0)
		length = s;
	else
		length = 10;
	ptr = new T[length];
	counter = -1;
}

template<typename T>
bool miniStack<T>::empty() const  //check if stack is empty
{
	return counter == -1;
}

template<typename T>
int miniStack<T>::size() const //size of stack>
{
	return counter + 1;
}

template<typename T>
void miniStack<T>::push(const T& item)  //adds element to the stack
{
	counter++;
	ptr[counter] = item;
}

template<typename T>
void miniStack<T>::pop()  //remove element from the top 
{ 
	if (empty())
		throw exception("Stack is empty");
	counter--;
}

template<typename T>
T& miniStack<T>::top()  //look at element at the top of the stack
{
	if (empty())
		throw exception("Stack is empty");
	return ptr[counter];
}

template<typename T>
miniStack<T>& miniStack<T>::operator=(const miniStack<T>& rhs)  //assign or compare stacks
{
	if (rhs.empty())
		this->counter = 1;

	delete[] this->ptr;
	this->length = rhs.length;
	this->ptr = new T[length];
	this->counter = rhs.counter;

	for (int i = 0; i <= counter; i++)
		this->ptr[i] = rhs.ptr[i];
	return *this;
}

template<typename T>
void miniStack<T>::palindrome()
{
	string s, s2;

	cout << "Enter a string: " << endl;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		this->push(s[i]);
	}
	cout << "Enter a second string: " << endl;
	cin >> s2;
	for (size_t j = s2.length() - 1; j > 0; j--)
	{
		this->push(s2[j]);
	}
	cout << s << "#" << s2 << endl;

	int i = 0;
	size_t j = s2.size() - 1;

	for (i; i < j; i++)
	{
		if (s[i] != s2[j])
		{
			cout << "Patterns DO NOT match. " << endl;
			exit(0);
		}
		else
		{
			j--;
		}
	}
	if (i == j)
		cout << "Patterns match!" << endl;
}

template<typename T>
void miniStack<T>::multibaseOutput()
{
	int dec = 0;
	T r = 0;

	cout << "Enter a decimal number: " << endl;
	cin >> dec;
	cout << "The hexidecimal conversion is: ";
	while (dec > 0)
	{
		r = dec % 16;
		dec = dec / 16;
		this->push(r);
		cout << hex << r;
	}
	cout << endl;
}

template<typename T>
bool miniStack<T>::balance(string line)
{
	string fname;
	miniStack<char> p;
	char a = ' ';

	cout << "Enter a filename: " << endl;
	cin >> fname;

	ifstream file(fname);

	if (file.is_open())
	{
		//getline(file, line)
		
			for (int i = 0; i < line.length(); i++)
			{
				if (line[i] == '(' || line[i] == '[' || line[i] == '{')
				{
					p.push(line[i]);
					continue;
				}
				
				if (p.empty())
				{
					return false;
				}

				switch (line[i])
				{
					case ')':
						a = p.top();
						p.pop();
						if (a == '{' || a == '[')
							return false;
						break;

					case '}':
						a = p.top();
						p.pop();
						if (a == '(' || a == '[')
							return false;
						break;

					case ']':
						a = p.top();
						p.pop();
						if (a == '(' || a == '{')
							return false;
						break;
				}
			}
	}
	return (p.empty());
}
