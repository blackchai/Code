#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

cv::Mat gaussian_filter(cv::Mat img)
{
    
}

int main(int argc,char **argv)
{   
    cv::Mat img = cv::imread("../build/imori_noise.jpg");
    if(img.empty())
    {
        std::cout<<"图像读取错误！！！"<<std::endl;
        return -1;
    }
    cv::Mat n_img = gaussian_filter(img);
    {
        cv::imshow("img",img);
        cv::imshow("n_img",n_img);
        cv::waitKey(0);
        cv::destroyAllWindows();
    }
    return 0;
}