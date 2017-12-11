// Akshat Bordia, Roll No 11010848
// Purpose : Computing Monochrome Images and Displaying them 

// Include Standard C/C++ Header Files Here
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

// Include OpenCV Header Files Here
#include <cv.h>
#include <highgui.h>
#include <cvaux.h>
#include <cxcore.h>

// Include CVDRIK Header Files Here
#include "../../CVDRIK/CVDRIKMisc/CVDRIKMisc.h"
#include "../../CVDRIK/CVDRIKMisc/CVDRIKMisc.cpp"
#include "../../CVDRIK/CVDRIKImageProcessing/CVDRIKImageProcessing.h"
#include "../../CVDRIK/CVDRIKImageProcessing/CVDRIKIPFeature.cpp"


// The Main Code
int main( int argc , char** argv )
{


	// Opening the Parameter File for Reading
	FILE* fp;
	fp = fopen( "PETS2000_ComputeNegImg.txt" , "r" );

	//checkPoint( 1 );

	// Reading the Parameter File : Image File Information
	char paramNameString[100] , eqString[3] , headerString[100];
	fscanf( fp , "%s" , headerString );
	char inpImgPath[100];
	fscanf( fp , "%s%s%s" , paramNameString , eqString , inpImgPath );
	char inpImgBaseName[100];
	fscanf( fp , "%s%s%s" , paramNameString , eqString , inpImgBaseName );
	char inpImgFormat[5];
	fscanf( fp , "%s%s%s" , paramNameString , eqString , inpImgFormat );
	int imgStartNum;
	fscanf( fp , "%s%s%d" , paramNameString , eqString , &imgStartNum );
	int imgEndNum;
	fscanf( fp , "%s%s%d" , paramNameString , eqString , &imgEndNum );
	int zeroPaddingFormatSize;
	fscanf( fp , "%s%s%d" , paramNameString , eqString , &zeroPaddingFormatSize );
	int maxZeroPaddingImgIndx;
	fscanf( fp , "%s%s%d" , paramNameString , eqString , &maxZeroPaddingImgIndx );
	char roiImgName[500];
	fscanf( fp , "%s%s%s" , paramNameString , eqString , roiImgName );

	// Closing Parameter File
	fclose( fp );

	// Load the First Image
	// This also helps in acquiring Image Dimensions
	char imgName[500];
	constructImageName( inpImgPath , inpImgBaseName , imgStartNum , inpImgFormat , zeroPaddingFormatSize , maxZeroPaddingImgIndx , imgName );
	IplImage* frameData = NULL;
	frameData = cvLoadImage( imgName );
	int width = frameData->width;
	int height = frameData->height;

	// Release the Image
	cvReleaseImage( &frameData );

	// Allocate Memory for the Monochrome Image
	IplImage* monImg = NULL;
	monImg = cvCreateImage( cvSize( width , height ) , IPL_DEPTH_8U , 1 );

	// Create the Windows for Displaying Images
	cvNamedWindow( "frameData" , CV_WINDOW_AUTOSIZE );
	cvResizeWindow( "frameData" , width , height );
	cvNamedWindow( "Monochrome Image" , CV_WINDOW_AUTOSIZE );
	cvResizeWindow("Monochrome Image", width , height );

	
	double fps = 0.0;
	for( int imgCount = imgStartNum ; imgCount <= imgEndNum ; ++imgCount )
	{
		// Show Frame Number
		printf( "\n\n************************************" );
		printf( "\n\n Processing Frame %d \n\n" , imgCount );

		// Prepare the Input Image Name
		constructImageName( inpImgPath , inpImgBaseName , imgCount , inpImgFormat , zeroPaddingFormatSize , maxZeroPaddingImgIndx , imgName );

		// Read the Current Frame
		IplImage* rgbImg = 0x00;
		rgbImg = cvLoadImage( imgName );
		if( !rgbImg )
		{
    		// Continue to Next Image
			printf( "\n\n Can not read frame number %d \n\n" , imgCount );
			continue;
		}

		// Compute the Negative Image
		unsigned char erc = computeMonochromeImages( rgbImg , monImg );
		if( erc != 0 )
		{
			printf( "\n\n Error Code = %d \n\n" , erc );
			getchar();
		}

		// Showing the Results
		cvShowImage( "frameData" , rgbImg );
		cvShowImage( "Monochrome Image" , monImg );

		// Wait for some time...
		cvWaitKey( 20 );

		// Cleaning Memory
		cvReleaseImage( &rgbImg );
	}

	// Clening Memory : Destroying the Windows
	cvDestroyWindow( "frameData" );
	cvDestroyWindow( "monImg" );

	// Cleaning Memory : Images
	cvReleaseImage( &monImg );

	// Error Code 0 : All Well, That Ends Well
	return( 0 );
}

