#define MAGICKCORE_QUANTUM_DEPTH 8
//#define MAGICKCORE_HDRI_ENABLE 8

#include <iostream>
#include <Magick++.h>

using namespace std;
using namespace Magick;

int main(int argc, char **argv)
{
	InitializeMagick(*argv);

	// Construct the image object. Seperating image construction from the 
	// the read operation ensures that a failure to read the image file 
	// doesn't render the image object useless. 
	Image image;
	try {
		// Read a file into image object 
		image.read("test.png");

		// Crop the image to specified size (width, height, xOffset, yOffset)
		image.crop(Geometry(100, 100, 100, 100));

		// Write the image to a file 
		image.write("x.gif");
	}
	catch (Exception &error_)
	{
		cout << "Caught exception: " << error_.what() << endl;
		return 1;
	}
	return 0;
}

