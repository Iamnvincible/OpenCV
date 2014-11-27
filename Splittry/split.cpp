#include <iostream>
#include <cv.h>
//#include <highgui.hpp>
//#include<opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;
using namespace std;
bool MultiChannelBleding();
int main(){
	MultiChannelBleding();
	waitKey();

}
bool MultiChannelBleding(){
	//�������
	Mat srcImage;
	Mat logoImage;
	vector<Mat> channels;
	Mat imageBlueChannel;
	//��ɫͨ��
	//��ͼ
	//������һ��Ҫ���Ҷ�ͼ��������������������������������������������������������������������������������������
	logoImage=imread("dota_logo.jpg",0);
	srcImage=imread("dota_jugg.jpg");
	if( !logoImage.data ) { printf("Oh��no����ȡlogoImage����~�� \n"); return false; }
	if( !srcImage.data ) { printf("Oh��no����ȡsrcImage����~�� \n"); return false; }
	split(srcImage,channels);
	imageBlueChannel=channels.at(0);
	addWeighted(imageBlueChannel(Rect(400,250,logoImage.cols,logoImage.rows)),1.0,
		logoImage,0.5,0,imageBlueChannel(Rect(400,250,logoImage.cols,logoImage.rows)));	
	merge(channels,srcImage);
	namedWindow("��ɫͨ���ϲ�");
	imshow("��ɫͨ���ϲ�",srcImage);
	//=================����ɫͨ�����֡�=================
	//	��������ͨ�����-��ɫ��������
	//============================================

	//��0��������ر���
	Mat  imageGreenChannel;

	//��1�����¶���ͼƬ
	logoImage= imread("dota_logo.jpg",0);
	srcImage= imread("dota_jugg.jpg");

	if( !logoImage.data ) { printf("Oh��no����ȡlogoImage����~�� \n"); return false; }
	if( !srcImage.data ) { printf("Oh��no����ȡsrcImage����~�� \n"); return false; }

	//��2����һ����ͨ��ͼ��ת����������ͨ��ͼ��
	split(srcImage,channels);//����ɫ��ͨ��

	//��3����ԭͼ����ɫͨ�������÷��ظ�imageBlueChannel��ע�������ã��൱�����ߵȼۣ��޸�����һ����һ�����ű�
	imageGreenChannel= channels.at(1);
	//��4����ԭͼ����ɫͨ���ģ�500,250�����괦���·���һ�������logoͼ���м�Ȩ���������õ��Ļ�Ͻ���浽imageGreenChannel��
	addWeighted(imageGreenChannel(Rect(500,250,logoImage.cols,logoImage.rows)),1.0,
		logoImage,0.5,0.,imageGreenChannel(Rect(500,250,logoImage.cols,logoImage.rows)));

	//��5�������������ĵ�ͨ�����ºϲ���һ����ͨ��
	merge(channels,srcImage);

	//��6����ʾЧ��ͼ
	namedWindow("<2>��Ϸԭ��+logo��ɫͨ�� byǳī");
	imshow("<2>��Ϸԭ��+logo��ɫͨ�� byǳī",srcImage);



	//=================����ɫͨ�����֡�=================
	//	��������ͨ�����-��ɫ��������
	//============================================
	
	//��0��������ر���
	Mat  imageRedChannel;

	//��1�����¶���ͼƬ
	logoImage= imread("dota_logo.jpg",0);
	srcImage= imread("dota_jugg.jpg");

	if( !logoImage.data ) { printf("Oh��no����ȡlogoImage����~�� \n"); return false; }
	if( !srcImage.data ) { printf("Oh��no����ȡsrcImage����~�� \n"); return false; }

	//��2����һ����ͨ��ͼ��ת����������ͨ��ͼ��
	split(srcImage,channels);//����ɫ��ͨ��

	//��3����ԭͼ�ĺ�ɫͨ�����÷��ظ�imageBlueChannel��ע�������ã��൱�����ߵȼۣ��޸�����һ����һ�����ű�
	imageRedChannel= channels.at(2);
	//��4����ԭͼ�ĺ�ɫͨ���ģ�500,250�����괦���·���һ�������logoͼ���м�Ȩ���������õ��Ļ�Ͻ���浽imageRedChannel��
	addWeighted(imageRedChannel(Rect(500,250,logoImage.cols,logoImage.rows)),1.0,
		logoImage,0.5,0.,imageRedChannel(Rect(500,250,logoImage.cols,logoImage.rows)));

	//��5�������������ĵ�ͨ�����ºϲ���һ����ͨ��
	merge(channels,srcImage);

	//��6����ʾЧ��ͼ
	namedWindow("<3>��Ϸԭ��+logo��ɫͨ�� byǳī");
	imshow("<3>��Ϸԭ��+logo��ɫͨ�� byǳī",srcImage);
	return true;
}
