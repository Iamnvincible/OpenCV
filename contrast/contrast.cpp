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
	//��ͼ
	g_srcImage=imread("..\\OpenCVV\\pic.jpg");
	if(!g_srcImage.data){printf("nononono");return false;}
	g_dstImage=Mat::zeros(g_srcImage.size(),g_srcImage.type());
	//�趨�ԱȶȺ����ȳ�ֵ
	g_nContrastValue=80;
	g_nbrightValue=20;
	//��������
	namedWindow("Ч��ͼ",1);
	//�����켣��
	createTrackbar("�Աȶ�:","Ч��ͼ",&g_nContrastValue,300,ContrastAndBright);
	createTrackbar("����:","Ч��ͼ",&g_nbrightValue,200,ContrastAndBright);
	//���ûص�����
	ContrastAndBright(g_nContrastValue,0);
	ContrastAndBright(g_nbrightValue,0);
	//���һЩ������Ϣ
	cout<<endl<<"\t�����������۲�ͼ��Ч��\n"
		<<"���� g �����˳�\n"
		<<"";
	while(char(waitKey(1))!='g'){}
	return 0;
}
//�ı�ͼ��ԱȶȺ����ȵĻص�����
static void ContrastAndBright(int ,void*){
	//namedWindow("ԭʼͼ",1);
	//����Ѱ��ִ������g_dstImage(i,j)=a*g_srcImage(i,j)+b;
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
	//��ʾͼ��
	imshow("ԭʼͼ",g_srcImage);
	imshow("Ч��ͼ",g_dstImage);
}
