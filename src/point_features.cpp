
//OpenCV
#include "opencv2/opencv.hpp"
#include "opencv2/core.hpp"
#include "opencv2/features2d.hpp"

//std
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std; // Per estalviar codi
//consts
const unsigned int MIN_NUM_FEATURES = 300; //minimum number of point fetaures
float factor;  //numero entre 0.0 i 1.0 que permet modificar la mascarà, variant així l'area total de la imatge on es busquen els keypoints.

int main(int argc, char *argv[])
{
    cv::VideoCapture camera; //OpenCV video capture object
    cv::Mat image; //OpenCV image object
	  int cam_id; //camera id . Associated to device number in /dev/videoX
    cv::Ptr<cv::ORB> orb_detector = cv::ORB::create(); //ORB point feature detector
    orb_detector->setMaxFeatures(MIN_NUM_FEATURES);
    std::vector<cv::KeyPoint> point_set; //set of point features
    cv::Mat descriptor_set; //set of descriptors, for each feature there is an associated descriptor

	//check user args
	switch(argc)
	{
		case 1: //no argument provided, so try /dev/video0
			cam_id = 0;
			break;
		case 2: //an argument is provided. Get it and set cam_id
			cam_id = atoi(argv[1]);
			break;
		default:
			std::cout << "Invalid number of arguments. Call program as: webcam_capture [video_device_id]. " << std::endl;
			std::cout << "EXIT program." << std::endl;
			break;
	}

  //Es demana a l'usuari que introdueixi un valor pel paràmetre factor
  cout<<"Introduce a number between 0.0 and 1.0 to determine the size of the scanning area: "; cin>>factor;


  //advertising to the user
	std::cout << "Opening video device " << cam_id << std::endl;

    //open the video stream and make sure it's opened
    if( !camera.open(cam_id) )
	{
        std::cout << "Error opening the camera. May be invalid device id. EXIT program." << std::endl;
        return -1;
    }

    //Process loop. Capture and point feature extraction. User can quit pressing a key
    while(1)
	{
		//Read image and check it. Blocking call up to a new image arrives from camera.
        if(!camera.read(image))
		{
            std::cout << "No image" << std::endl;
            cv::waitKey();
        }

    //**************** Find ORB point fetaures and descriptors ****************************

        //clear previous points
        point_set.clear();

        //Es defineix la mascara en funció del paràmetre "factor"
        cv::Mat mask(cv::Mat::zeros(image.size(),CV_8U));
        mask(cv::Rect(0,0,image.cols*factor,image.rows*factor))=1;


        //detect and compute(extract) features, el segon argument fa referencia a la mascara previament definida
        orb_detector->detectAndCompute(image, mask, point_set, descriptor_set);

        //draw points on the image
        cv::drawKeypoints( image, point_set, image, 255, cv::DrawMatchesFlags::DEFAULT );

    //********************************************************************

        //show image
        cv::imshow("Output Window", image);

		//Waits 30 millisecond to check if 'q' key has been pressed. If so, breaks the loop. Otherwise continues.
    	if( (unsigned char)(cv::waitKey(30) & 0xff) == 'q' ) break;
    }
}
