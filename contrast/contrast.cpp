#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
//#include<imgproc.hpp>
#include <iostream>
using namespace std;
using namespace cv;
static void ContrastAndBright(int,void *);
int g_nContrastValue;
int g_nbrightValue;
Mat g_srcImage,g_dstImage;
int main(){
	system("color 5E");
	//读图
	g_srcImage=imread("..\\OpenCVV\\pic.jpg");
	if(!g_srcImage.data){printf("nononono");return false;}
	g_dstImage=Mat::zeros(g_srcImage.size(),g_srcImage.type());
	//设定对比度和亮度初值
	g_nContrastValue=80;
	g_nbrightValue=20;
	//创建窗口
	namedWindow("效果图",1);
	//创建轨迹条
	createTrackbar("对比度:","效果图",&g_nContrastValue,300,ContrastAndBright);
	createTrackbar("亮度:","效果图",&g_nbrightValue,200,ContrastAndBright);
	//调用回调函数
	ContrastAndBright(g_nContrastValue,0);
	ContrastAndBright(g_nbrightValue,0);
	//输出一些帮助信息
	cout<<endl<<"\t调整滚动条观察图像效果\n"
		<<"按下 g 程序退出\n"
		<<"";
	while(char(waitKey(1))!='g'){}
	return 0;
}
//改变图像对比度和亮度的回调函数
static void ContrastAndBright(int ,void*){
	//namedWindow("原始图",1);
	//三个寻欢执行运算g_dstImage(i,j)=a*g_srcImage(i,j)+b;
	for(int y=0;y<g_srcImage.rows;y++){
		for(int x=0;x<g_srcImage.cols;x++){
			//printf("<%d,%d><",y,x);
			for(int c=2;c>=0;c--){
				g_dstImage.at<Vec3b>(y,x)[c]=
					saturate_cast<uchar>((g_nContrastValue*0.01)*(g_srcImage.at<Vec3b>(y,x)[c])+g_nbrightValue);
				//printf("%d ",g_srcImage.at<Vec3b>(y,x)[c]);
			}
			//printf(">\n");
		}
	}
	//显示图像
	imshow("原始图",g_srcImage);
	imshow("效果图",g_dstImage);
}
