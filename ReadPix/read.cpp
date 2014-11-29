#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include<imgproc.hpp>
#include <iostream>
using namespace std;
using namespace cv;
int main(){
	system("color 2E");
	int temp;
	Mat srcimage=imread("Yosemite.jpg");
	FILE *fp=NULL;
	if((fp=fopen("a.txt","w+"))==NULL)return -1;
	for(int x=0;x<srcimage.rows;++x){
		for(int y=0;y<srcimage.cols;++y){
			//printf("<%d,%d>",x,y);
			fprintf(fp,"<%d,%d>-<",x,y);
			for(int c=2;c>=0;--c){
					temp=srcimage.at<Vec3b>(x,y)[c];
					fprintf(fp,"%d ",temp);
			}
			fprintf(fp,"> ");
		}
		fprintf(fp,"\n");
	}
	printf("Íê³É");
	fclose(fp);
	//waitKey(10000);
	getchar();
	return 0;
}