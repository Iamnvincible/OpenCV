#define cvQueryHistValue_1D( hist, idx0 ) ((float)cvGetReal1D( (hist)->bins, (idx0)))
//����ͼ���ļ�
//By MoreWindows (http://blog.csdn.net/MoreWindows)
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
//���ؿ���̨����
#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
int main()
{
	const char *pstrImageName = "milkyway.jpg";
	const char *pstrSaveImageName = "milkyway.jpg";
	const char *pstrWindowsSrcTitle = "ԭͼ";
	const char *pstrWindowsDstTitle = "����ͼ";
	
	double fScale = 0.314;	//���ű���
	CvSize czSize;			    //Ŀ��ͼ��ߴ�
	
	//���ļ��ж�ȡͼ��  
	IplImage *pSrcImage = cvLoadImage(pstrImageName, CV_LOAD_IMAGE_UNCHANGED);
	IplImage *pDstImage = NULL;	
	
	//����Ŀ��ͼ���С
	czSize.width = pSrcImage->width * fScale;
	czSize.height = pSrcImage->height * fScale;
	
	//����ͼ������
	pDstImage = cvCreateImage(czSize, pSrcImage->depth, pSrcImage->nChannels);
	cvResize(pSrcImage, pDstImage, CV_INTER_AREA);
	
	//��������
	cvNamedWindow(pstrWindowsSrcTitle, CV_WINDOW_AUTOSIZE);
	cvNamedWindow(pstrWindowsDstTitle, CV_WINDOW_AUTOSIZE);
	
	//��ָ����������ʾͼ��
	cvShowImage(pstrWindowsSrcTitle, pSrcImage);
	cvShowImage(pstrWindowsDstTitle, pDstImage);
	
	//�ȴ������¼�
	cvWaitKey();
	
	//����ͼƬ
	cvSaveImage(pstrSaveImageName, pDstImage);
	
	cvDestroyWindow(pstrWindowsSrcTitle);
	cvDestroyWindow(pstrWindowsDstTitle);
	cvReleaseImage(&pSrcImage);
	cvReleaseImage(&pDstImage);
	return 0;
}