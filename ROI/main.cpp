#include<iostream>
#include<stdio.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <cv.h>
using namespace std;
using namespace cv;
bool ROI_AddImage()
{
       //��1������ͼ��
       Mat srcImage1= imread("dota_pa.jpg");
       Mat logoImage= imread("dota_logo.jpg");
       if(!srcImage1.data ) { printf("���ã���ȡsrcImage1����~�� \n"); return false; }
       if(!logoImage.data ) { printf("���ã���ȡlogoImage����~�� \n"); return false; }
 
       //��2������һ��Mat���Ͳ������趨ROI����
       Mat imageROI= srcImage1(Rect(110,150,logoImage.cols,logoImage.rows));
 
       //��3��������ģ�������ǻҶ�ͼ��
       Mat mask= imread("dota_logo.jpg",0);
 
       //��4������Ĥ������ROI
       logoImage.copyTo(imageROI,mask);
 
       //��5����ʾ���
       namedWindow("<1>����ROIʵ��ͼ�����ʾ������");
       imshow("<1>����ROIʵ��ͼ�����ʾ������",srcImage1);
       return true;
}
bool LinearBlending(){
	//����ֲ�����
	vector<int>compression_params;
	compression_params.push_back(9);
	double alphaValue=0.5;
	double betaValue;
	Mat srcimage1,srcimage2,dstImage;
	//��ȡͼ��
	srcimage1=imread("1.jpg");
	srcimage2=imread("2.jpg");
	if(!srcimage1.data){printf("ͼƬ1��ȡ����");return false;}
	if(!srcimage2.data){printf("ͼƬ2��ȡ����");return false;}
	betaValue=1-alphaValue;
	addWeighted(srcimage1,alphaValue,srcimage2,betaValue,0.0,dstImage);
	namedWindow("ԭͼ");
	imshow("ԭͼ",srcimage1);
	namedWindow("Ч��ͼ");
	imshow("Ч��ͼ",dstImage);
	imwrite("blending.jpg",dstImage,compression_params);
	return true;
}
bool ROI_LinearBleding(){
	Mat imagedest=imread("1.jpg",1);
	Mat imagefrom=imread("dota_logo.jpg",1);
	if(!imagedest.data){printf("ͼƬ1��ȡ����");return false;}
	if(!imagefrom.data){printf("ͼƬ2��ȡ����");return false;}
	Mat imageROI=imagedest(Rect(420,215,imagefrom.cols,imagefrom.rows));
	addWeighted(imageROI,0.5,imagefrom,0.5,0.0,imageROI);
	namedWindow("���");
	imshow("���",imagedest);
	return true;	
}
int main(){
	//LinearBlending();
	system("color 5E");
	printf("����������");
	ROI_AddImage();
	ROI_LinearBleding();
	waitKey();
}