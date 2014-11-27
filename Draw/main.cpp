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
const Mat* images��
Ϊ����ͼ���ָ�롣
int nimages��
Ҫ����ֱ��ͼ��ͼ��ĸ������˺�������Ϊ��ͼ����ֱ��ͼ������ͨ������¶�ֻ�����ڵ�һͼ������ͨ��nimages=1��
const int* channels��
ͼ���ͨ��������һ�����飬����ǻҶ�ͼ����channels[1]={0};����ǲ�ɫͼ����channels[3]={0,1,2}�������ֻ�����ɫͼ���2��ͨ����ֱ��ͼ����channels[1]={1};
IuputArray mask��
��һ������ͼ������ȷ����Щ�������㣬ʵ��Ӧ�����Ǹ��ܺõĲ�����Ĭ��������Ƕ�����Ϊһ����ͼ�񣬼���Mat()��
OutArray hist��
����õ���ֱ��ͼ
int dims��
�õ���ֱ��ͼ��ά�����Ҷ�ͼ��Ϊ1ά����ɫͼ��Ϊ3ά��
const int* histSize��
ֱ��ͼ��������������������10��������������Ϊ10�ݣ�Ȼ��ͳ��ÿ����������ص��ܺ͡�
const float** ranges��
����һ����ά���飬����ָ��ÿ������ķ�Χ��
����������������Ĭ��ֵ��uniform��������ֱ��ͼ�Ƿ�Ⱦ࣬���һ���������ͼ����ֱ��ͼ����ʾ��洢�йء�
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
	//	int intensity = cvRound(bin_val*hist_height/max_val);  //Ҫ���Ƶĸ߶�
	//	rectangle(hist_img,Point(i*scale,hist_height-1),
	//		Point((i+1)*scale - 1, hist_height - intensity),
	//		CV_RGB(255,255,255));
	//}
	//imshow( "Source", src );
	//imshow( "Gray Histogram", hist_img );
	//////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////��ɫֱ��ͼ////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////
	//����RGB��ɫ����ֱ��ͼ

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
		int intensity_r = cvRound(bin_val_r*hist_height/max_val_r);  //Ҫ���Ƶĸ߶�
		int intensity_g = cvRound(bin_val_g*hist_height/max_val_g);  //Ҫ���Ƶĸ߶�
		int intensity_b = cvRound(bin_val_b*hist_height/max_val_b);  //Ҫ���Ƶĸ߶�
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