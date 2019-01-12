#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

int main() {
	//读取图片文件
	Mat src = imread("view.jpg",1);
	Mat des;
	Mat imgray;
	if (src.empty()) {
		printf("文件不存在。。。");
		return -1;
	}
	resize(src, des, Size(src.rows / 4, src.cols / 4), 0, 0, CV_INTER_LINEAR);
	//printf("%d %d", src.rows, src.cols);
	namedWindow("new", CV_WINDOW_AUTOSIZE);
	cvtColor(des, imgray, COLOR_BGR2GRAY);
	//imshow("old picture", src);
	blur(imgray, imgray, Size(3, 3));
	threshold(imgray, imgray, 70, 110);
	//Canny(imgray, imgray, 70, 110);
	imshow("canny", imgray);

	//imshow("gray", imgray);

	waitKey(0);

	return 0;
}