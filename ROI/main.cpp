#include<iostream>
#include<stdio.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <cv.h>
using namespace std;
using namespace cv;
bool ROI_AddImage()
{
       //【1】读入图像
       Mat srcImage1= imread("dota_pa.jpg");
       Mat logoImage= imread("dota_logo.jpg");
       if(!srcImage1.data ) { printf("你妹，读取srcImage1错误~！ \n"); return false; }
       if(!logoImage.data ) { printf("你妹，读取logoImage错误~！ \n"); return false; }
 
       //【2】定义一个Mat类型并给其设定ROI区域
       Mat imageROI= srcImage1(Rect(110,150,logoImage.cols,logoImage.rows));
 
       //【3】加载掩模（必须是灰度图）
       Mat mask= imread("dota_logo.jpg",0);
 
       //【4】将掩膜拷贝到ROI
       logoImage.copyTo(imageROI,mask);
 
       //【5】显示结果
       namedWindow("<1>利用ROI实现图像叠加示例窗口");
       imshow("<1>利用ROI实现图像叠加示例窗口",srcImage1);
       return true;
}
bool LinearBlending(){
	//定义局部变量
	vector<int>compression_params;
	compression_params.push_back(9);
	double alphaValue=0.5;
	double betaValue;
	Mat srcimage1,srcimage2,dstImage;
	//读取图像
	srcimage1=imread("1.jpg");
	srcimage2=imread("2.jpg");
	if(!srcimage1.data){printf("图片1读取错误");return false;}
	if(!srcimage2.data){printf("图片2读取错误");return false;}
	betaValue=1-alphaValue;
	addWeighted(srcimage1,alphaValue,srcimage2,betaValue,0.0,dstImage);
	namedWindow("原图");
	imshow("原图",srcimage1);
	namedWindow("效果图");
	imshow("效果图",dstImage);
	imwrite("blending.jpg",dstImage,compression_params);
	return true;
}
bool ROI_LinearBleding(){
	Mat imagedest=imread("1.jpg",1);
	Mat imagefrom=imread("dota_logo.jpg",1);
	if(!imagedest.data){printf("图片1读取错误");return false;}
	if(!imagefrom.data){printf("图片2读取错误");return false;}
	Mat imageROI=imagedest(Rect(420,215,imagefrom.cols,imagefrom.rows));
	addWeighted(imageROI,0.5,imagefrom,0.5,0.0,imageROI);
	namedWindow("结果");
	imshow("结果",imagedest);
	return true;	
}
int main(){
	//LinearBlending();
	system("color 5E");
	printf("哈哈哈哈哈");
	ROI_AddImage();
	ROI_LinearBleding();
	waitKey();
}