#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

cv::Mat _2Value(cv::Mat img)
{
    int rows = img.rows;
    int cols = img.cols;
    double b = 0.0722, g = 0.7152, r = 0.2126;

    cv::Mat res = cv::Mat::zeros(rows, cols, CV_8UC1);

    for(int i = 0; i < rows; i++ )
        for(int j = 0; j < cols; j++ )
        {
            double gray_degree = (double)img.at<cv::Vec3b>(i,j)[0] * b
                               + (double)img.at<cv::Vec3b>(i,j)[1] * g
                               + (double)img.at<cv::Vec3b>(i,j)[2] * r 
                               ;
            res.at<uchar>(i,j) = gray_degree < 128.0 ? 0 : 255;
        }
    
    return res;
}

int main(int argc, char **argv)
{
    cv::Mat img = cv::imread("../build/image_1.png");
    if(img.empty()){
        std::cout << "图像读取错误！！！" << std::endl;
        return -1;
    }
    cv::imshow("out",_2Value(img));
    cv::imshow("img",img);
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}