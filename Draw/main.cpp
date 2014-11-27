/*
void calcHist(
const Mat* images, 
int nimages, 
const int* channels, 
InputArray mask, 
OutputArray hist, 
int dims, 
const int* histSize, 
const float** ranges,
bool uniform=true, 
bool accumulate=false )
const Mat* images：
为输入图像的指针。
int nimages：
要计算直方图的图像的个数。此函数可以为多图像求直方图，我们通常情况下都只作用于单一图像，所以通常nimages=1。
const int* channels：
图像的通道，它是一个数组，如果是灰度图像则channels[1]={0};如果是彩色图像则channels[3]={0,1,2}；如果是只是求彩色图像第2个通道的直方图，则channels[1]={1};
IuputArray mask：
是一个遮罩图像用于确定哪些点参与计算，实际应用中是个很好的参数，默认情况我们都设置为一个空图像，即：Mat()。
OutArray hist：
计算得到的直方图
int dims：
得到的直方图的维数，灰度图像为1维，彩色图像为3维。
const int* histSize：
直方图横坐标的区间数。如果是10，则它会横坐标分为10份，然后统计每个区间的像素点总和。
const float** ranges：
这是一个二维数组，用来指出每个区间的范围。
后面两个参数都有默认值，uniform参数表明直方图是否等距，最后一个参数与多图像下直方图的显示与存储有关。
*/
#include<iostream>
#include<stdio.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv/cv.h> 
using namespace cv;
int main(  )
{
	//Mat src,gray;
	//src=imread("baboon.jpg");
	//cvtColor(src,gray,CV_RGB2GRAY);
	//int bins = 256;
	//int hist_size[] = {bins};
	//float range[] = { 0, 256 };
	//const float* ranges[] = { range};
	//MatND hist;
	//int channels[] = {0};

	//calcHist( &gray, 1, channels, Mat(), // do not use mask
	//	hist, 1, hist_size, ranges,
	//	true, // the histogram is uniform
	//	false );

	//double max_val;
	//minMaxLoc(hist, 0, &max_val, 0, 0);
	//int scale = 2;
	//int hist_height=256;
	//Mat hist_img = Mat::zeros(hist_height,bins*scale, CV_8UC3);
	//for(int i=0;i<bins;i++)
	//{
	//	float bin_val = hist.at<float>(i); 
	//	int intensity = cvRound(bin_val*hist_height/max_val);  //要绘制的高度
	//	rectangle(hist_img,Point(i*scale,hist_height-1),
	//		Point((i+1)*scale - 1, hist_height - intensity),
	//		CV_RGB(255,255,255));
	//}
	//imshow( "Source", src );
	//imshow( "Gray Histogram", hist_img );
	//////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////彩色直方图////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////
	//绘制RGB三色分量直方图

	Mat src;
	src=imread("baboon.jpg");
	int bins = 256;
	int hist_size[] = {bins};
	float range[] = { 0, 256 };
	const float* ranges[] = { range};
	MatND hist_r,hist_g,hist_b;
	int channels_r[] = {0};

	calcHist( &src, 1, channels_r, Mat(), // do not use mask
		hist_r, 1, hist_size, ranges,
		true, // the histogram is uniform
		false );

	int channels_g[] = {1};
	calcHist( &src, 1, channels_g, Mat(), // do not use mask
		hist_g, 1, hist_size, ranges,
		true, // the histogram is uniform
		false );

	int channels_b[] = {2};
	calcHist( &src, 1, channels_b, Mat(), // do not use mask
		hist_b, 1, hist_size, ranges,
		true, // the histogram is uniform
		false );
	double max_val_r,max_val_g,max_val_b;
	minMaxLoc(hist_r, 0, &max_val_r, 0, 0);
	minMaxLoc(hist_g, 0, &max_val_g, 0, 0);
	minMaxLoc(hist_b, 0, &max_val_b, 0, 0);
	int scale = 1;
	int hist_height=256;
	Mat hist_img = Mat::zeros(hist_height,bins*3, CV_8UC3);
	for(int i=0;i<bins;i++)
	{
		float bin_val_r = hist_r.at<float>(i); 
		float bin_val_g = hist_g.at<float>(i);
		float bin_val_b = hist_b.at<float>(i);
		int intensity_r = cvRound(bin_val_r*hist_height/max_val_r);  //要绘制的高度
		int intensity_g = cvRound(bin_val_g*hist_height/max_val_g);  //要绘制的高度
		int intensity_b = cvRound(bin_val_b*hist_height/max_val_b);  //要绘制的高度
		rectangle(hist_img,Point(i*scale,hist_height-1),
			Point((i+1)*scale - 1, hist_height - intensity_r),
			CV_RGB(255,0,0));

		rectangle(hist_img,Point((i+bins)*scale,hist_height-1),
			Point((i+bins+1)*scale - 1, hist_height - intensity_g),
			CV_RGB(0,255,0));

		rectangle(hist_img,Point((i+bins*2)*scale,hist_height-1),
			Point((i+bins*2+1)*scale - 1, hist_height - intensity_b),
			CV_RGB(0,0,255));

	}
	imshow( "Source", src );
	imshow( "RGB Histogram", hist_img );
	waitKey(1000000);
	return 0;
}