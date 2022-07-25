#include <iostream>
#include <queue>
#include <ctime>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
	/*
		1 - 4 Minutes
	*/
	int arrTime = 0;
	int servTime = 0;
	int depTime = 0;
	int count = 0;
	ofstream fout;
	fout.open("MP2_output_CPS272.txt");

	queue<int>cust;
	queue<int> wait;

	fout << "**********************\n" << "**********************\n";
	fout << " 1 - 4 Minute Arrival Simulation " << endl;
	fout << "**********************\n" << "**********************\n";
	for (int i = 0; i < 120; i++)
	{
		arrTime = rand() % 4 + 1;
		servTime = rand() % 4 + 1;
		count++;
		cust.push(i);
		wait.push(servTime);
		fout << "Customer # " << "\t" << "Arrival Time" << "\t" << "Service Time"<< endl;
		fout << " -------------------------------------------------- " << endl;
		fout << setw(10) << count << setw(10) << arrTime << " minute(s)" << setw(5) << servTime << " minute(s)." << endl;
		fout << endl;
		depTime = rand() % 4 + 1;
		if (servTime == depTime)
		{
			fout << "Customer # " << count << "'s service has been completed. " << endl;
			fout << endl;
			cust.pop();
		}
		if (wait.front() < wait.back())
		{
			wait.pop();
		}
	}
	fout << " ---------------- " << endl;
	fout << "Maximum number of customer's in the queue: ";
	fout << cust.size();
	fout << endl;
	fout << " ---------------- " << endl;
	fout << "Longest wait time for a customer was " << wait.front() << " minute(s).";
	fout << endl;
	fout << endl;
	fout << endl;
	fout << endl;

	fout << "**********************\n" << "**********************\n";
	fout << " 1 - 3 Minute Arrival Simulation " << endl;
	fout << "**********************\n" << "**********************\n";
	/* 
		1 - 3 Minutes: 
	*/

	int arrTime2 = 0;
	int servTime2 = 0;
	int depTime2 = 0;
	int count2 = 0;

	queue<int>cust2;
	queue<int> wait2;

	for (int i = 0; i < 120; i++)
	{
		arrTime2 = rand() % 3 + 1;
		servTime2 = rand() % 4 + 1;
		count2++;
		cust2.push(i);
		wait2.push(servTime2);
		fout << "Customer # " << "\t" << "Arrival Time" << "\t" << "Service Time" << endl;
		fout << " -------------------------------------------------- " << endl;
		fout << setw(10) << count2 << setw(10) << arrTime2 << " minute(s)" << setw(5) << servTime2 << " minute(s)." << endl;
		fout << endl;
		depTime2 = rand() % 4 + 1;
		if (servTime2 == depTime2)
		{
			fout << "Customer # " << count2 << "'s service has been completed. " << endl;
			fout << endl;
			cust2.pop();
		}
		if (wait2.front() < wait2.back())
		{
			wait2.pop();
		}
	}
	fout << " ---------------- " << endl;
	fout << "Maximum number of customer's in the queue: ";
	fout << cust2.size();
	fout << endl;
	fout << " ---------------- " << endl;
	fout << "Longest wait time for a customer was " << wait2.front() << " minute(s).";
	fout << endl;

	fout.close();
	return 0;
}
