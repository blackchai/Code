#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

cv::Mat BGR_to_RGB(cv::Mat img)
{
    int cols = img.cols;
    int rows = img.rows;

    cv::Mat res=cv::Mat::zeros(rows,cols,CV_8UC3);

    for(int k=0;k<3;k++)
        for(int i=0;i<rows;++i)
            for(int j=0;j<cols;j++)
                res.at<cv::Vec3b>(i,j)[k]=img.at<cv::Vec3b>(i,j)[2-k];

    return res;
}

int main(int argc, char **argv)
{
    cv::Mat img=cv::imread("../build/image_1.png",cv::IMREAD_COLOR);

    if(img.empty())
    {
        std::cout<<"图像读取错误！！！"<<std::endl;
        return -1;
    }

    cv::Mat out_img=BGR_to_RGB(img);

    cv::imshow("out",out_img);
    cv::imshow("img",img);
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}