#include <opencv/cv.hpp>
#include <opencv/cxcore.hpp>
#include <opencv/highgui.h>
#include <iostream>
#include <vector>
using namespace cv;
using namespace std;


int DELAY_CAPTION = 1500;
int DELAY_BLUR = 100;
int MAX_KERNEL_LENGTH = 31;
Mat src; Mat dst;
char window_name[] = "Filter Demo 1";
int display_dst(int delay)
{
	imshow(window_name, dst);
	int c = waitKey(delay);
	if (c >= 0) { return -1; }
	return 0;
}
int display_caption(char *caption) {
	dst = Mat::zeros(src.size(), src.type());
	putText(dst,caption,Point(src.cols/4,src.rows/2),
		FONT_HERSHEY_COMPLEX, 1, Scalar(255, 255, 255));
	imshow(window_name, dst);
	int c = waitKey(1500);
	if (c >= 0) { return -1; }
	return 0;
}
int main() {
	namedWindow(window_name, WINDOW_AUTOSIZE);
	cvNamedWindow(window_name, WINDOW_AUTOSIZE);
	src = imread("test.jpg", IMREAD_COLOR);
	if (display_caption("Orignal image")!= 0) return 0;

	for (int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2)
	{
		blur(src, dst, Size(i, i), Point(-1,-1));
		display_dst(DELAY_BLUR);
	}
	for (int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2)
	{
		GaussianBlur(src, dst, Size(i, i), 0, 0);
		if (display_dst(DELAY_BLUR) != 0) { return 0; }
	}

	for (int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2)
	{
		medianBlur(src, dst, i);
		if (display_dst(DELAY_BLUR) != 0) { return 0; }
	}


}

//blur GaussianBlur  medianBlur bilateralFilter

/*
����þ� ����:
- ����(Gaussian noise)�� �����ϱ� ���� ������ ���� (Low-pass filter)
- ���޽� ����(0, 255)�� �����ϴµ� ������

�̵�� ����:
- ���� ������ �����ϰ� ������ �������� ���� ���ϰ� ����
- �ſ� �ѷ��� ��⸦ ���� ������ �̿��� ȭ�ҵ�� �����ϵ��� ����� ����Ǵ� ȭ�Ұ��� ����
��ó  :http://forum.falinux.com/zbxe/index.php?document_srl=549330&mid=lecture_tip
*/