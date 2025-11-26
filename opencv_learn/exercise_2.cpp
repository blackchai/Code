#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

cv::Mat BGR2GRAY(cv::Mat img,double b,double g,double r)
{
    int rows=img.rows;
    int cols=img.cols;

    cv::Mat res=cv::Mat::zeros(rows,cols,CV_8UC1);//CV_8UC1表示单通道灰度范围0-255

    for(int i = 0; i < rows; i++ )
        for(int j = 0; j < cols; j++ ) 
            res.at<uchar>(i,j) 
                = (double)img.at<cv::Vec3b>(i,j)[0] * b
                + (double)img.at<cv::Vec3b>(i,j)[1] * g
                + (double)img.at<cv::Vec3b>(i,j)[2] * r 
                ;

    return res;
}

int main(int argc,char **argv)
{   
    cv::Mat img = cv::imread("../build/image_1.png");
    if(img.empty())
    {
        std::cout << "图像读取错误！！！" << std::endl;
        return -1;
    }
    cv::imshow("out1",BGR2GRAY(img, 0.7152, 0.0722, 0.2126));
    cv::imshow("out2",BGR2GRAY(img, 0.0722, 0.7152, 0.2126));
    cv::imshow("out3",BGR2GRAY(img, 0.2126, 0.7152, 0.0722));
    cv::imshow("img",img);
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}