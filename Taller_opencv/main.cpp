#include "opencv2\opencv.hpp"
#include "opencv2\highgui.hpp"
#include <opencv2/objdetect.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <iostream>
#include <iomanip>
#include <time.h>
#include "Detector.hpp"
#include "Persona.hpp"
#include "LinkedList.hpp"

using namespace cv;
using namespace std;
int main() {

	// Create video capturing object
	// 0 opens default camera, otherwise filename as argument
	cv::VideoCapture video("C:/Users/Brayann/Downloads/people_walking2.mp4");
    

	// verifica que el video este abierto
	if (!video.isOpened()) return -1;

	// For saving the frame
	//cv::Mat frame;
    
    //frame es la imagen
    //detector.toggleMode();
    //cout << detector.modeName() << endl;//lineas copiadas de detectPeople

	

	
    cv::Mat frame;
	Detector detector;
	LinkedList lista;//creamos la lista enlazada

	// Loop through available frames
	while (video.read(frame)) {
		
		//detector.toggleMode();
		//cout << detector.modeName();
        vector<Persona> found = detector.detect(frame);//lista de personas identificadas con el opencv
        for (vector<Persona>::iterator i = found.begin(); i != found.end(); ++i)
        {	
		
            Persona &p = *i;//el algoritmo detecta a mas de una persona y los introduce en un vector , luego found[i] iterara en el for
			lista.insertarPrimer(&p);
            cout << "(" << p.getXCentro() << ", " << p.getYCentro() << ")" << endl;
          
            rectangle(frame, cv::Point(p.getXComienzo(), p.getYComienzo()), cv::Point(p.getXFin(), p.getYFin()), cv::Scalar(0, 255, 0), 2);
            circle(frame, cv::Point(p.getXCentro(), p.getYCentro()), 3, cv::Scalar(0, 0, 255), 3);
            circle(frame, cv::Point(p.getXComienzo(), p.getYComienzo()), 3, cv::Scalar(255, 0, 255), 2);
            circle(frame, cv::Point(p.getXFin(), p.getYFin()), 3, cv::Scalar(0, 255, 255), 2);
			
		}   
		    
        //fin codigo de for para detectar a las personas
		// Display the frame
		cv::imshow("Video feed", frame);
		
		// Write video frame to output
		//..output.write(frame);

		// For breaking the loop
		if (cv::waitKey(38) >= 0) break;
		
	} // end while (video.read(frame))

	// Release video capture and writer
	//...output.release();
	video.release();

	// Destroy all windows
	cv::destroyAllWindows();

	return 0;

}