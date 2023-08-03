/*
	The following file is a definition of a dataset class.
	Each of the methods is provided and enumerated in detail.
	
	A dataset can store an arbitary number of values which is
	not known at runtime.
	
	When an instance of this class is created a file stream which
	has been opened is associated with it.
	
	The file should be in the following of something like dataset.txt
	
	The first line is the title of the data, remaining lines have
	values - 1 to a line.
	
	The constructor should set the title and place the values into
	an array (private member values).
	
	Once data is loaded various methods can be invoked.
	
	On termination, resources should be free'd via the destructor.
*/

#include <iostream>
#include <string>
using namespace std;

class dataset 
{
	public:
		dataset(ifstream&);				// read data (double) from each line - first line is title
		~dataset();						// destruct private members
		
		char* gettitle();				// return title
		double* getvalues();				// return array of data
		
		int getnumdata() const;			// return the number of values in the data set
		double getmin() const;			// get min
		double getmax() const;			// get max
		double getmean() const;			// get mean
		double getmedian();				// get median
		double getstddev() const;		// get stddeviation of dataset
	private:
		char* title;					// title of dataset 
		double* values;		// pointer to an array of the data set
		int numvals;					// numbers of values stored in dataset. 
};  
