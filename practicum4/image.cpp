/*
	public:

	private:
		struct pixel{
			unsigned int r;
			unsigned int g;
			unsigned int b;
		};

		pixel* picmap;
		int xdim, ydim;
		bool status;
*/

#include "image.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <cmath>

using namespace std;

const int MAX = 128;

image::image()
{
    // xdim = 0;  
    // ydim = 0;
    
	picmap = new pixel[2000*2000]; //dynamically allocating pixel array with the default dimensions

	if (picmap == NULL)
	{
		cout << "allocation unsuccessful" << endl;
		exit(1);
	}

	status = true; //initializing to true. once loadfile is evoked this will switch to false.
}

image::~image()
{
	delete[] picmap;
	// delete[] scaledpic;
}

void image::openfile(char filename[])
{
	ifstream ins;
	char buffer[MAX];                // global temp vars to store stuff
    int garbage;
    char c;
    int x,y;

    ins.open(filename, ios::in);

    if (ins.fail())                    // check if file opened
	{
		cout << "failed to open ppm file" << endl;
		exit(1);
	}



    ins >> buffer;                    // read image header and get dimensions
    ins >> buffer >> x >> y >> garbage;

    xdim = x;
    ydim = y;

    ins.get(c);                    // get unwanted newline

    // now read the pixels into picmap one by one
    for (int i = 0; i < ydim; i++)
    {
        for (int y = 0; y < xdim; y++)
        {
            ins.read((char*)(picmap + i * xdim + y), sizeof(pixel)); //possibly wrong way to read into picmap
        }
    }


    ins.close();
	status = false;
}

void image::scaleimage(int factor) //not scaling properly
{
	xdim = xdim * factor;
	ydim = ydim * factor;
	
	pixel * scaledpic = new pixel[xdim * ydim];

    for (int z = 0; z < ydim; z++)
    {
        for (int i = 0; i < factor; i++)
        {
            for (int y = 0; y < xdim; y++)
            {
                for (int a = 0; a < factor; a++)
                {
					*(scaledpic + z * xdim + factor*y + a) = *(picmap + z *xdim + y); 
                }
            }
        }
    }

	picmap = scaledpic;
}

void image::writeimage(char filename[])
{
    ofstream ofs;
    ofs.open(filename, ios::out | ios::binary);

    if (ofs.fail())
    {
		cout << "unable to write to file" << endl;
		exit(1);
	}

    // write header information.
    
    ofs << "P6" << endl << "#." << endl << (xdim) << " " << (ydim) << endl << "255" << endl;

    // write image.

    for(int i = 0; i < ydim; i++)
    {
        for(int j = 0; j < xdim; j++)
        {
            ofs.write((char*)&*(picmap + i * xdim + j), sizeof(pixel));
        }
    }

    ofs.close();

}

