/*
	Class Definition for an image (image.h).

	Refer to practicum specification for details.

    Created by Antoun, Sherine on 9/14/21.
    
*/

#ifndef IMAGE
#define IMAGE  

#include <iostream>

class image 
{
	public:
		image();
		~image();
		void openfile(char filename[]);
		void scaleimage(int factor);
		void writeimage(char filename[]);
	private:
		struct pixel{
			unsigned int r;
			unsigned int g;
			unsigned int b;
		};

		pixel* picmap;
		int xdim, ydim;
		bool status;
};


#endif

