#include<iostream>
#include<stdio.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2\opencv.hpp>
#include <opencv/cv.h> 

using namespace cv;
using namespace std;
int main(){
	system("color 5E");
	Mat image1;
	Mat image2;
	vector<Mat> channels;
	Mat ColorChannel;
	image1=imread("..\\Splittry\\dota_logo.jpg",0);
	image2=imread("..\\op03\\girl.jpg");
//	
//		namedWindow("split");
//	imshow("split",image2);
//	split(image2,channels);
//	ColorChannel=channels.at(0);
//	for(int i=0;i<image1.rows;++i){
//			printf("<%d>",i);
//		printf("\n");
//	}
//		/*addWeighted(imageBlueChannel(Rect(500,250,logoImage.cols,logoImage.rows)),1.0,
//		logoImage,0.5,0,imageBlueChannel(Rect(500,250,logoImage.cols,logoImage.rows)));
//*/
//
//	addWeighted(ColorChannel(Rect(100,200,image1.cols,image1.rows)),1.0,image1,0.5,0,
//		ColorChannel(Rect(100,200,image1.cols,image1.rows)));
//	merge(channels,image2);
//	namedWindow("split");
//	imshow("split",image2);
	    IplImage *img=cvLoadImage("..\\op03\\girl.jpg",1);
    CvScalar s;
    for(int i=0;i<img->height;i++){
        for(int j=0;j<img->width;j++){
        s=cvGet2D(img,i,j); // get the (i,j) pixel value
        printf("B=%f, G=%f, R=%f ",s.val[0],s.val[1],s.val[2]);
        s.val[0]=111;
        s.val[1]=111;
        s.val[2]=111;
        cvSet2D(img,i,j,s);//set the (i,j) pixel value
        }
    }
    cvNamedWindow("Image",1); 



    cvShowImage("Image",img);
    cvWaitKey(0); //等待按键 

    cvDestroyWindow( "Image" );//销毁窗口
    cvReleaseImage( &img ); //释放图像 

	waitKey();

}