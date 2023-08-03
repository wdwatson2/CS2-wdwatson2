/*
	Class file for dataset.cpp
*/

#include <iostream>
#include <fstream>
#include <math.h>
#include <cstring>
#include <algorithm>
#include "dataset.h"

using namespace std;

const int MAX = 128;

dataset::dataset(ifstream& ins)
{
/*
The constructor takes a file input stream that has already been opened by the caller. The first line of the text
file is a sequence of characters representing the subject. The remainder of the file is data. Refer to the
example provided (dataset.txt). During construction it is unknown how many values are to be read in.
As a consequence of this, the constructor needs to allocate memory on the heap for the array values – use a
large value for this. The constructor should also store how many values were read in (numvals) and the
subject (title). If an error occurs in the constructor i.e. space was unable to be allocated on the heap –
invoke the exit function call to make your program terminate.
*/
	title = new char[MAX];//allocating space for the title

	if(title == NULL){//checking to make sure allocation was successful
		cout << "title could not be allocated" << endl;
		exit(1);
	}

	ins.getline(title, MAX, '\n');//reading in title

	values = new double[1000];//allocating space for values

	if(values == NULL){
		cout << "values could not be allocated" << endl; 
		exit(1);
	}

	int counter = 0; //will count how many values are read in
	double temp;

	while(ins >> temp){//reading in data untill stream empty
		values[counter] = temp;
		counter++;
	}
	numvals = counter;//numvals	
} 
 
dataset::~dataset()
{
	// this function should destroy all dynamic members associated with this class
	// instance.
	// delete[] val;
	// delete[] temp;
	delete[] values;
	delete[] title;
}

char* dataset::gettitle()
{
	// this function should return a pointer to an C string representing a title.
	// Please remember the concept of data hiding when writing this function.
	char* temp;
	temp = new char[strlen(title) + 1];
	strcpy(temp, title);

	return temp;
}

double* dataset::getvalues()
{
	// this function should return a pointer to an array representing the dataset.
	// Please remember the concept of data hiding when writing this function.
	double* val;
	val = new double[numvals];
	for(int i = 0; i < numvals; i++){
		val[i] = values[i];
	}

	return val;
}

// function returns number of values

int dataset::getnumdata() const
{
	return numvals;
}

// function finds the minimum value in the set and returns it to the caller.

double dataset::getmin() const
{
	double min = -1;
	
	for (int i = 0; i < numvals; i++)
	{
		if (i == 0)
			min = values[i];
		else
		{
			if (values[i] < min)
				min = values[i];
		}
	}
	return min;
}

// function finds the maximum value in the set and returns it to the caller.

double dataset::getmax() const
{
	double max = -1;
	
	for (int i = 0; i < numvals; i++)
	{
		if (i == 0)
			max = values[i];
		else
		{
			if (values[i] > max)
				max = values[i];
		}
	}
	return max;
}

// function computes the mean and returns it to the caller.

double dataset::getmean() const
{
	double total;
	
	for (int i = 0; i < numvals; i++)
		total += values[i];
		
	return (total / numvals);
}

// function computes median

double dataset::getmedian()
{
	// write the function to compute the median - median is the middle value if the size 
	// of the set is odd OR the average of the two middle values if even.
	// To do this, the set must be orderd.

	sort(values, values+numvals);//sorting values in ascending order

	if(numvals%2 == 0){
		//even
		double avg = (values[numvals/2] + values[numvals/2 + 1])/2; //calc the avg of medians
		return avg;
	}
	else{
		//odd
		return values[numvals/2]; //the median
	}
	
}

// function computes std deviation

double dataset::getstddev() const
{
	double sum = 0;
	
	if (numvals == -1)
		return -1;
		
	for (int i = 0; i < numvals; i++)
	{
		double value_dev = values[i] - getmean();
		value_dev = value_dev * value_dev;
		sum += value_dev;
	}
	
	return (sqrt(sum / numvals));
}

