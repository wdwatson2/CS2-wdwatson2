/*
	Driver function to test image class.

	Created by Antoun, Sherine on 9/14/21.

*/

#include <iostream>
#include "image.h"

using namespace std;

const int MAX = 128;

int main() 
{
	image* myimage = new image();

    char filename[MAX];
    
    cout << "Enter a name of a PPM file: " << endl;
    cin >> filename;

	myimage->openfile(filename);

	myimage->scaleimage(2);

	myimage->writeimage("mario-gang_test1.ppm");


	return 0;
}

