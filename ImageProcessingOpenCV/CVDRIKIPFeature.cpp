/*********************************************************************************

   PROJECT:			CVDRIK
   FILE:			CVDRIKIPFeature.cpp
   AUTHOR:			PRITHWIJIT GUHA
   DATE:
   DESCRIPTION:		CPP File for Feature Extraction Functions

*********************************************************************************/


/*************************** OTHER INCLUDE FILES *****************************/

#include "CVDRIKImageProcessing.h"

#define EPSILON 0.0001
#define PI 3.141593


/*****************************************************************************/


/******************************************************************************

                                FUNCTIONS

******************************************************************************/


// Function for Color Negative Image Computation
// Inputs :-
//			(IplImage*) rgbImg : Pointer to the 3-Channel RGB Image
//			(IplImage*) negImg : Pointer to the 3-Channel Negative Image
// Outputs :-
//			(unsigned char) errCode : The Error Code of Execution
// Invoked As : errCode = computeNegativeImage( &rgbImg , &negImg );
unsigned char computeNegativeImage( IplImage* rgbImg , IplImage* negImg )
{
	// Check Inputs
	if( ( rgbImg->imageSize <= 0 ) || ( rgbImg->nChannels != 3 ) || ( negImg->imageSize <= 0 ) || ( negImg->nChannels != 3 ) )
	{
		// Error Code 1 : Invalid Input
		return( 1 );
	}
	
	// Check Data Size Mismatch
	if( ( rgbImg->width != negImg->width ) || ( rgbImg->height != negImg->height ) )
	{
		// Error Code 5 : Data Size Mismatch
		return( 5 );
	}
	
	// Set the Image Pixels to ZERO Intensity Values
	cvZero( negImg );
	
	// Computing the Color Negation Over Pixels
	int baseIndx = -( rgbImg->widthStep );
	for( int y = 0 ; y < ( rgbImg->height ) ; ++y )
	{
		// Update the Base Indices
		baseIndx = baseIndx + ( rgbImg->widthStep );
		
		// Set the Current Indices
		int currIndx = baseIndx - 3;
		
		// Looping Over the Columns
		for( int x = 0 ; x < ( rgbImg->width ) ; ++x )
		{
			// Update the Current Indices
			currIndx = currIndx + 3;
			
			// Computing the Color Negation
			// NOTE : Typecast the Data to "unsigned char" while Reading from the Image Array
			// NOTE : Typecast the Data to "char" while Assigning to the Image Array
			int blue = (unsigned char) rgbImg->imageData[ currIndx ];
			negImg->imageData[ currIndx ] = (char) ( 255 - blue );
			
			int green = (unsigned char) rgbImg->imageData[ currIndx + 1 ];
			negImg->imageData[ currIndx +1] = (char) ( 255 - green );
			
			int red = (unsigned char) rgbImg->imageData[ currIndx + 2 ];
			negImg->imageData[ currIndx + 2 ] = (char) ( 255 - red );
		}
	}
	
	// Error Code 0 : All Well, That Ends Well
	return( 0 );
}

unsigned char computeMonochromeImages( IplImage* rgbImg , IplImage* monImg)
{
	// Check Inputs
	if( ( rgbImg->imageSize <= 0 ) || ( rgbImg->nChannels != 3 ) || (monImg->imageSize <= 0 ) || ( monImg->nChannels != 1 ) )
	{
		// Error Code 1 : Invalid Input
		return( 1 );
	}
	
	// Check Data Size Mismatch
	if( ( rgbImg->width !=monImg->width ) || ( rgbImg->height != monImg->height ) )
	{
		// Error Code 5 : Data Size Mismatch
		return( 5 );
	}
	
	// Set the Image Pixels to ZERO Intensity Values
	cvZero( monImg );
	
	// Computing the Color Negation Over Pixels
	int baseIndx = -( rgbImg->widthStep );
	int baseIndx2= -(monImg->widthStep);
	for( int y = 0 ; y < ( rgbImg->height ) ; ++y )
	{
		// Update the Base Indices
		baseIndx = baseIndx + ( rgbImg->widthStep );
		baseIndx2 = baseIndx2 + ( monImg->widthStep );
		
		// Set the Current Indices
		int currIndx = baseIndx - 3;
		int monIndx  = baseIndx2 - 1;
		// Looping Over the Columns
		for( int x = 0 ; x < ( rgbImg->width ) ; ++x )
		{
			// Update the Current Indices
			currIndx = currIndx + 3;
			monIndx	 = monIndx +1;
			// Computing the Color Negation
			// NOTE : Typecast the Data to "unsigned char" while Reading from the Image Array
			// NOTE : Typecast the Data to "char" while Assigning to the Image Array
			int blue = (unsigned char) rgbImg->imageData[ currIndx ];
			int green = (unsigned char) rgbImg->imageData[ currIndx + 1 ];
			int red = (unsigned char) rgbImg->imageData[ currIndx + 2 ];
			monImg->imageData[ monIndx ] =(char)( (blue + green + red) /3);
			
			
		}
	}
	
	// Error Code 0 : All Well, That Ends Well
	return( 0 );
}


unsigned char computeEdgeMap( IplImage* rgbImg , IplImage* monImg)
{
	// Check Inputs
	if( ( rgbImg->imageSize <= 0 ) || ( rgbImg->nChannels != 3 ) || (monImg->imageSize <= 0 ) || ( monImg->nChannels != 1 ) )
	{
		// Error Code 1 : Invalid Input
		return( 1 );
	}
	
	// Check Data Size Mismatch
	if( ( rgbImg->width !=monImg->width ) || ( rgbImg->height != monImg->height ) )
	{
		// Error Code 5 : Data Size Mismatch
		return( 5 );
	}
	
	// Set the Image Pixels to ZERO Intensity Values
	cvZero( monImg );
	
	// Computing the Color Negation Over Pixels
	int baseIndx = -( rgbImg->widthStep );
	int baseIndx2= -(monImg->widthStep);
	for( int y = 0 ; y < ( rgbImg->height ) ; ++y )
	{
		// Update the Base Indices
		baseIndx = baseIndx + ( rgbImg->widthStep );
		baseIndx2 = baseIndx2 + ( monImg->widthStep );
		
		// Set the Current Indices
		int currIndx = baseIndx - 3;
		int monIndx  = baseIndx2 - 1;
		// Looping Over the Columns
		for( int x = 0 ; x < ( rgbImg->width ) ; ++x )
		{
			// Update the Current Indices
			currIndx = currIndx + 3;
			monIndx	 = monIndx +1;
			// Computing the Color Negation
			// NOTE : Typecast the Data to "unsigned char" while Reading from the Image Array
			// NOTE : Typecast the Data to "char" while Assigning to the Image Array
			int blue = (unsigned char) rgbImg->imageData[ currIndx ];
			int green = (unsigned char) rgbImg->imageData[ currIndx + 1 ];
			int red = (unsigned char) rgbImg->imageData[ currIndx + 2 ];
			monImg->imageData[ monIndx ] =(char)( (blue + green + red) /3);
			
			
		}
	}
	int mean=0;
	baseIndx2= 0;
	for( int y = 0 ; y < ( monImg->height )-1 ; ++y )
	{
		// Update the Base Indices
		
		baseIndx2 = baseIndx2 + ( monImg->widthStep );
		
		// Set the Current Indices
	
		int monIndx  = baseIndx2;
		// Looping Over the Columns
		for( int x = 0 ; x < ( monImg->width )-1 ; ++x )
		{
			// Update the Current Indices
			
			monIndx	 = monIndx +1;
			// Computing the Gradient
			// NOTE : Typecast the Data to "unsigned char" while Reading from the Image Array
			// NOTE : Typecast the Data to "char" while Assigning to the Image Array
			int x_back = (0.5)*(unsigned char) monImg->imageData[ monIndx-1 ];
			int x_forw = (0.5)*(unsigned char) monImg->imageData[ monIndx + 1 ];
			int y_forw = (0.5)*(unsigned char) monImg->imageData[ monIndx + ( monImg->widthStep )];
			int y_back = (0.5)*(unsigned char) monImg->imageData[ monIndx - ( monImg->widthStep )];
			
			monImg->imageData[ monIndx ] =(char)(sqrt(((x_forw-x_back))^2+((y_forw-y_back))^2));
			mean= mean+  monImg->imageData[monIndx];
			
			
		}
	}
	mean = mean/((monImg->height -1 )*(monImg->width -1));
	//printf("%d", mean);

	baseIndx2= -(monImg->widthStep);
	for( int y = 1 ; y < ( monImg->height )-1 ; ++y )
	{
		// Update the Base Indices
		
		baseIndx2 = baseIndx2 + ( monImg->widthStep );
		
		// Set the Current Indices
	
		int monIndx  = baseIndx2 - 1;
		// Looping Over the Columns
		for( int x = 1 ; x < ( monImg->width )-1 ; ++x )
		{
			// Update the Current Indices
			
			monIndx	 = monIndx +1;
			int val = (unsigned char) monImg->imageData[ monIndx ];
			if(val>=10){
			monImg->imageData[ monIndx ] =(char)(255);
			}
			else
			{
				monImg->imageData[ monIndx ] =(char)(0);
			}
			
			
			
		}
	}


	
	// Error Code 0 : All Well, That Ends Well
	return( 0 );
}

//------------------------------------------------------------------------------------------------------------------------------------------

unsigned char blurImage( IplImage* rgbImg , IplImage* blurredImg, int windowSize )
{
	// Check Inputs
	if( ( rgbImg->imageSize <= 0 ) || ( rgbImg->nChannels != 3 ) || ( blurredImg->imageSize <= 0 ) || ( blurredImg->nChannels != 3 ) )
	{
		// Error Code 1 : Invalid Input
		return( 1 );
	}
	
	// Check Data Size Mismatch
	if( ( rgbImg->width != blurredImg->width ) || ( rgbImg->height != blurredImg->height ) )
	{
		// Error Code 5 : Data Size Mismatch
		return( 5 );
	}
	
	cvSet(blurredImg, CV_RGB(0,0,0));
	//int baseIndx = -( rgbImg->widthStep );
	int baseIndx = (windowSize/2-1)*(rgbImg->widthStep);
	for( int y = windowSize/2 ; y < ( rgbImg->height ) - windowSize/2 ; ++y )
	{
		// Update the Base Indices
		baseIndx = baseIndx + ( rgbImg->widthStep );
		
		// Set the Current Indices
		int currIndx = baseIndx + 3*(windowSize/2-1);
		
		// Looping Over the Columns
		for( int x = windowSize/2 ; x < ( rgbImg->width ) - windowSize/2 ; ++x )
		{
			// Update the Current Indices
			currIndx = currIndx +3;
			int div=(windowSize*windowSize);

			int temp_base= currIndx- ((rgbImg->widthStep))*(windowSize/2+1);//- 3*windowSize/2;
			int temp_avg=0;

			for (int i = 0; i < windowSize; ++i)
			{
				temp_base=temp_base+ (rgbImg->widthStep);

				int temp_curr= temp_base -(windowSize/2+1)*3;
				for (int j = 0; j < windowSize; ++j)
				{
					temp_curr=temp_curr+3;
					int tmp= (unsigned char) rgbImg->imageData[temp_curr];
					temp_avg= temp_avg+tmp;

				}
				
			}

			temp_avg=temp_avg/div;
			blurredImg->imageData[ currIndx ] = (char) (temp_avg );
			//Green Channel
			currIndx++;
			temp_base= currIndx- ((rgbImg->widthStep))*(windowSize/2+1);
			temp_avg=0;
			for (int i = 0; i < windowSize; ++i)
			{
				temp_base=temp_base+ (rgbImg->widthStep);

				int temp_curr= temp_base -(windowSize/2+1)*3;
				for (int j = 0; j < windowSize; ++j)
				{
					temp_curr=temp_curr+3;
					int tmp= (unsigned char) rgbImg->imageData[temp_curr];
					temp_avg= temp_avg+tmp;

				}
				
			}
			temp_avg=temp_avg/div;
			blurredImg->imageData[ currIndx ] = (char) (temp_avg );

			//Red Channel
			currIndx++;
			temp_base= currIndx- ((rgbImg->widthStep))*(windowSize/2+1);
			temp_avg=0;
			for (int i = 0; i < windowSize; ++i)
			{
				temp_base=temp_base+ (rgbImg->widthStep);

				int temp_curr= temp_base -(windowSize/2+1)*3;
				for (int j = 0; j < windowSize; ++j)
				{
					temp_curr=temp_curr+3;
					int tmp= (unsigned char) rgbImg->imageData[temp_curr];
					temp_avg= temp_avg+tmp;

				}
				
			}
			temp_avg=temp_avg/div;
			blurredImg->imageData[ currIndx ] = (char) (temp_avg );	

			currIndx=currIndx-2;		
		}
	}
	
	// Error Code 0 : All Well, That Ends Well
	return( 0 );
}


//----------------------------------------------------------------------------------------------------------------------------------
unsigned char changeDetection( IplImage* rgbImg ,IplImage* rgbImg_prev, IplImage* outputImg, IplImage* erodeImg, IplImage* dilatedImg,  int threshold )
{
	// Check Inputs
	if( ( rgbImg->imageSize <= 0 ) || ( rgbImg->nChannels != 3 ) || ( outputImg->imageSize <= 0 ) || ( outputImg->nChannels != 1 ) )
	{
		// Error Code 1 : Invalid Input
		return( 1 );
	}
	
	// Check Data Size Mismatch
	if( ( rgbImg->width != outputImg->width ) || ( rgbImg->height != outputImg->height ) )
	{
		// Error Code 5 : Data Size Mismatch
		return( 5 );
	}
	
	// Set the Image Pixels to ZERO Intensity Values
	cvZero( outputImg);
	cvZero( erodeImg );
	cvZero( dilatedImg);
	// Computing the Color Negation Over Pixels
	int baseIndx = -( rgbImg->widthStep );
	int baseIndx2= -(outputImg->widthStep);
	for( int y = 0 ; y < ( rgbImg->height ) ; ++y )
	{
		// Update the Base Indices
		baseIndx = baseIndx + ( rgbImg->widthStep );
		baseIndx2= baseIndx2 + (outputImg->widthStep);
		
		// Set the Current Indices
		int currIndx = baseIndx - 3;
		int currIndx2= baseIndx2-1;
		
		// Looping Over the Columns
		for( int x = 0 ; x < ( rgbImg->width ) ; ++x )
		{
			// Update the Current Indices
			currIndx = currIndx + 3;
			currIndx2= currIndx2+ 1;
			
			int blue = (unsigned char) rgbImg->imageData[ currIndx ];
			int blue_prev =(unsigned char) rgbImg_prev->imageData[currIndx];
			int tmp1= abs(blue-blue_prev);

			//negImg->imageData[ currIndx ] = (char) ( 255 - blue );
			
			int green = (unsigned char) rgbImg->imageData[ currIndx + 1 ];
			int green_prev= (unsigned char) rgbImg_prev->imageData[currIndx+1];
			int tmp2= abs(green - green_prev);

			//negImg->imageData[ currIndx +1] = (char) ( 255 - green );
			
			int red = (unsigned char) rgbImg->imageData[ currIndx + 2 ];
			int red_prev= (unsigned char) rgbImg_prev->imageData[currIndx+2];
			int tmp3= abs(red-red_prev);
			//negImg->imageData[ currIndx + 2 ] = (char) ( 255 - red );

			if(tmp1>=threshold||tmp2>=threshold||tmp3>=threshold){
				outputImg->imageData[currIndx2] = (char) (255);
			}
		}
	}
	cvErode(outputImg,erodeImg,NULL,1);
	//cvDilate(erodeImg, dilatedImg, NULL, 1);
	/*int windowSize=3;
	baseIndx = (windowSize/2-1)*(outputImg->widthStep);
	for( int y = windowSize/2 ; y < ( outputImg->height ) - windowSize/2 ; ++y )
	{
		// Update the Base Indices
		baseIndx = baseIndx + ( outputImg->widthStep );
		
		// Set the Current Indices
		int currIndx = baseIndx + 1*(windowSize/2-1);
		
		// Looping Over the Columns
		for( int x = windowSize/2 ; x < ( outputImg->width ) - windowSize/2 ; ++x )
		{
			// Update the Current Indices
			currIndx = currIndx +1;
			//int div=(windowSize*windowSize);

			int temp_base= currIndx- ((outputImg->widthStep))*(windowSize/2+1);//- 3*windowSize/2;
			int temp_avg=0;

			for (int i = 0; i < windowSize; ++i)
			{
				temp_base=temp_base+ (outputImg->widthStep);

				int temp_curr= temp_base -(windowSize/2+1)*1;
				for (int j = 0; j < windowSize; ++j)
				{
					temp_curr=temp_curr+1;
					int tmp= (unsigned char) outputImg->imageData[temp_curr];
					temp_avg = tmp +temp_avg;
					//printf("%d\n",  tmp);

				}
				
			}
			//printf("%d\n", temp_avg );
			if(temp_avg > 0.4*(9)*(temp_avg)){
				erodeImg->imageData[currIndx] = (char) (255);

			}
			
			
			
			
		}
	}  */
	
	// Error Code 0 : All Well, That Ends Well
	return( 0 );
}
//----------------------------------------------------------------------------------------------------------------------------------------
unsigned char cornerDetection( IplImage* rgbImg , IplImage* cornerImg, int threshold)
{
	if( ( rgbImg->imageSize <= 0 ) || ( rgbImg->nChannels != 3 ) || ( cornerImg->imageSize <= 0 ) || ( cornerImg->nChannels != 3 ) )
	{
		// Error Code 1 : Invalid Input
		return( 1 );
	}
	
	// Check Data Size Mismatch
	if( ( rgbImg->width != cornerImg->width ) || ( rgbImg->height != cornerImg->height ) )
	{
		// Error Code 5 : Data Size Mismatch
		return( 5 );
	}
	
	cvSet(cornerImg, CV_RGB(0,0,0));
	//int baseIndx = -( rgbImg->widthStep );
	int windowSize=3;
	int baseIndx = (windowSize/2-1)*(rgbImg->widthStep);
	for( int y = windowSize/2 ; y < ( rgbImg->height ) - windowSize/2 ; ++y )
	{
		// Update the Base Indices
		baseIndx = baseIndx + ( rgbImg->widthStep );
		
		// Set the Current Indices
		int currIndx = baseIndx + 3*(windowSize/2-1);
		
		// Looping Over the Columns
		for( int x = windowSize/2 ; x < ( rgbImg->width ) - windowSize/2 ; ++x )
		{
			// Update the Current Indices
			currIndx = currIndx +3;
			int div=(windowSize*windowSize);

			int temp_base= currIndx- ((rgbImg->widthStep))*(windowSize/2+1);//- 3*windowSize/2;
			int temp_avg=0;

			for (int i = 0; i < windowSize; ++i)
			{
				temp_base=temp_base+ (rgbImg->widthStep);

				int temp_curr= temp_base -(windowSize/2+1)*3;
				for (int j = 0; j < windowSize; ++j)
				{
					temp_curr=temp_curr+3;
					int tmp= (unsigned char) rgbImg->imageData[temp_curr];
					temp_avg= temp_avg+tmp;

				}
				
			}

			temp_avg=temp_avg/div;
			cornerImg->imageData[ currIndx ] = (char) (temp_avg );
			//Green Channel
			currIndx++;
			temp_base= currIndx- ((rgbImg->widthStep))*(windowSize/2+1);
			temp_avg=0;
			for (int i = 0; i < windowSize; ++i)
			{
				temp_base=temp_base+ (rgbImg->widthStep);

				int temp_curr= temp_base -(windowSize/2+1)*3;
				for (int j = 0; j < windowSize; ++j)
				{
					temp_curr=temp_curr+3;
					int tmp= (unsigned char) rgbImg->imageData[temp_curr];
					temp_avg= temp_avg+tmp;

				}
				
			}
			temp_avg=temp_avg/div;
			cornerImg->imageData[ currIndx ] = (char) (temp_avg );

			//Red Channel
			currIndx++;
			temp_base= currIndx- ((rgbImg->widthStep))*(windowSize/2+1);
			temp_avg=0;
			for (int i = 0; i < windowSize; ++i)
			{
				temp_base=temp_base+ (rgbImg->widthStep);

				int temp_curr= temp_base -(windowSize/2+1)*3;
				for (int j = 0; j < windowSize; ++j)
				{
					temp_curr=temp_curr+3;
					int tmp= (unsigned char) rgbImg->imageData[temp_curr];
					temp_avg= temp_avg+tmp;

				}
				
			}
			temp_avg=temp_avg/div;
			cornerImg->imageData[ currIndx ] = (char) (temp_avg );	

			currIndx=currIndx-2;		
		}
	}
	
	// Error Code 0 : All Well, That Ends Well
	return( 0 );


	

}