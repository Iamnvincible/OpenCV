#include<iostream>
#include<stdio.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>



using namespace cv;
int main()
{
	// ����һ��ͼƬ����Ϸԭ����
	Mat img=imread("milkyway.jpg",IMWRITE_PNG_STRATEGY_FIXED  );
	// ����һ����Ϊ "��Ϸԭ��"����
	imwrite("E:\\aa.jpg",img);
	namedWindow("pic",WINDOW_NORMAL);
	// �ڴ�������ʾ��Ϸԭ��
	imshow("pic",img);
	// �ȴ�6000 ms�󴰿��Զ��ر�
	//printf("%d",(int)img.row);
	
	waitKey(60000);

}