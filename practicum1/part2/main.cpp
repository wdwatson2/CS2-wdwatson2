/*
	Sample driver function for dataset class. The function creates
	an instance of the class then invokes various methods to produce
	results
*/

#include <iostream>
#include <fstream>
#include "dataset.h"
using namespace std;

int main()
{
	ifstream ins;
	ins.open("dataset.txt"); 

	cout << "Invoking Constructor" << endl;
	dataset f1(ins);

	cout << "Minimum: " << f1.getmin() << endl;
	cout << "Maximum: " << f1.getmax() << endl;
	cout << "Mean: " << f1.getmean() << endl;
	cout << "Number of elements: " << f1.getnumdata() << endl;
	cout << "Std Dev: " << f1.getstddev() << endl;
	
	double* g = f1.getvalues();							// the getvalues function returns a pointer

	cout << "Print out of values: " << endl;

	for (int i = 0; i < f1.getnumdata(); i++)
		cout << g[i] << endl;

	cout << endl;
	cout << "Median: " << f1.getmedian() << endl;
	
	delete [] g;										// free the pointer once complete
	ins.close();										// close the stream
	return 0;
}

