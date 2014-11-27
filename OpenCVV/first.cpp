#include<iostream>
#include<stdio.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>



using namespace cv;
int main()
{
	// 读入一张图片（游戏原画）
	Mat img=imread("milkyway.jpg",IMWRITE_PNG_STRATEGY_FIXED  );
	// 创建一个名为 "游戏原画"窗口
	imwrite("E:\\aa.jpg",img);
	namedWindow("pic",WINDOW_NORMAL);
	// 在窗口中显示游戏原画
	imshow("pic",img);
	// 等待6000 ms后窗口自动关闭
	//printf("%d",(int)img.row);
	
	waitKey(60000);

}