/*
 * ImageConverter.h declares a class for
 *  various image conversion operations.
 *
 *  Author:  Joel Adams, CS112 @ Calvin College.
 *  Name: Ben (bee6), Heon Jae (hk238)
 *  Created: March 2015
 *  Revised: November 2016.
 *  Revised for TSGL-2: November 2020.
 */

#ifndef IMAGECONVERTER_H_
#define IMAGECONVERTER_H_

#include <tsgl.h>     // Canvas, ColorInt, etc.
#include <iostream>   // cout, cerr, ...
#include <string>     // string
#include <omp.h>      // OpenMP functions
#ifdef _WIN32
  #include <windows.h>
#else
  #include <unistd.h>    // sleep()
#endif

using namespace tsgl;
using namespace std;

class ImageConverter {
public:
    ImageConverter(const std::string& imageFileName, int width, int height);
    ~ImageConverter();
    void run();

    // process image
    void invertImage();
    void invertImage2();
    void invertImage3();

private:
    Canvas  myCanvas0;
    int     myWidth;
    int     myHeight;
    string  myImageFileName;

    #ifdef _WIN32  // for Windows only; ignored on Linux
    void sleep(unsigned seconds) { Sleep(seconds * 1000); }
    #endif
};


#endif /* IMAGECONVERTER_H_ */
