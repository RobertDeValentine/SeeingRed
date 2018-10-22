//Author: Robert DeValentine
#include "Bitmap/bitmap.h"
#include <iostream>
#include <vector>

using namespace std;

//argc - number of arguments in command
//argv - each argument word, stored in an array
int main(int argc, char* argv[])
{
  Bitmap image;//declare bitmap named image
  if (argc==2)//ensure only one file is entered as argument
  {
    string filename;
    filename =  argv[1]; // get name of image


    image.open(filename); //opens the file into a bitmap named image
 
    if (image.isImage())//ensures we are looking at a 24 bit image
    {
      int width;
      int height;


      vector <vector <Pixel> > imagePixels = image.toPixelMatrix();// declares vec of vec named imagepixels with the bitmap filling it in
      
      width = imagePixels.size();

      height = imagePixels[0].size();
      
      cout<<filename<<" is "<<height<<" and "<<width<<" pixels wide\n";
      
      for( int row = 0; row < imagePixels.size(); row++) // goes through entire matrix
      {
        for ( int col = 0; col<imagePixels[row].size();col++)
        {
                Pixel color; //declares variable called color with Pixel data type

                color = imagePixels[row][col]; // assigns an individual pixel in the matrix to color

                color.green = 0; //removes the green
                color.blue =0; //remoces the blue

                imagePixels[row][col] = color; //puts the pixel back in shade of red

        }
      }

      image.fromPixelMatrix( imagePixels ); // converts back to bitmap

      image.save("redness.bmp"); // saves the bitmap to bmp


    }
    else
    {
      cout<<"Image file must be a bitmap with 24-bit color depth.\n";
    }
    



  }
  else
  {
    cout<<"Please Specify one image file\n";//ensures user only enters 2 arguments

  }

  return 0;
}
