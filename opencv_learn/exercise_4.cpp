#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui/highgui.hpp>


cv::Mat _2Value(cv::Mat img)
{
    int rows=img.rows;
    int cols=img.cols;
    double b = 0.0722, g = 0.7152, r = 0.2126;

    cv::Mat grey_img=cv::Mat::zeros(rows,cols,CV_8UC1);//CV_8UC1表示单通道灰度范围0-255

    for(int i = 0; i < rows; i++ )
        for(int j = 0; j < cols; j++ ) 
            grey_img.at<uchar>(i,j) 
                    = (double)img.at<cv::Vec3b>(i,j)[0] * b
                    + (double)img.at<cv::Vec3b>(i,j)[1] * g
                    + (double)img.at<cv::Vec3b>(i,j)[2] * r 
                    ;

    int thrshd=0 ;
    double max_v = 0;

    for(int k = 0; k < 255; k++ )
    {
        double w0 = 0, M0 = 0, M1 = 0, w1 = 0;
        int cnt0 = 0, cnt1 = 0;
        for(int i = 0; i < rows; i++ )
            for(int j = 0; j < cols; j++ )
            {
                double grey_val = (double)grey_img.at<uchar>(i,j);
                if(grey_val < k)cnt0++, M0 += grey_val;
                else cnt1++, M1 += grey_val;
            }
        w0 = (double)cnt0/((double)cols * (double)rows);
        w1 = (double)cnt1/((double)cols * (double)rows);
        M0 /= (double)cnt0;
        M1 /= (double)cnt1;

        double v=w0 * (1 - w0) * (M0 - M1) * (M0 - M1);
        if(v > max_v)
        {
            max_v = v;
            thrshd = k;
        }
    }

    cv::Mat res = cv::Mat::zeros(rows, cols, CV_8UC1);

    for(int i = 0; i < rows; i++ )
        for(int j = 0; j < cols; j++ )
        {
            double gray_degree = (double)grey_img.at<uchar>(i,j);
            res.at<uchar>(i,j) = gray_degree < thrshd ? 0 : 255;
        }
    
    return res;
}

void cmp(cv::Mat grey_img, int thrshd1)
{
    int rows = grey_img.rows;
    int cols = grey_img.cols;
    std::cout<<"当threshold == "<<thrshd1<<"时,val == ";
    double w0 = 0, M0 = 0, M1 = 0, w1 = 0;
    int cnt0 = 0, cnt1 = 0;
    for(int i = 0; i < rows; i++ )
        for(int j = 0; j < cols; j++ )
        {
            double grey_val = (double)grey_img.at<uchar>(i,j);
            if(grey_val < thrshd1)cnt0++, M0 += grey_val;
            else cnt1++, M1 += grey_val;
        }
    w0 = (double)cnt0/((double)cols * (double)rows);
    w1 = (double)cnt1/((double)cols * (double)rows);
    M0 /= (double)cnt0;
    M1 /= (double)cnt1;

    double v=w0 * w1 * (M0 - M1) * (M0 - M1);
    std::cout<<v<<std::endl;
}

int main(int argc, char **argv)
{   
    cv::Mat img = cv::imread("../build/img2.png");
    if(img.empty()){
        std::cout << "图像读取错误！！！" << std::endl;
        return -1;
    }
    int rows=img.rows;
    int cols=img.cols;
    double b = 0.0722, g = 0.7152, r = 0.2126;

    cv::Mat grey_img=cv::Mat::zeros(rows,cols,CV_8UC1);//CV_8UC1表示单通道灰度范围0-255

    for(int i = 0; i < rows; i++ )
        for(int j = 0; j < cols; j++ ) 
            grey_img.at<uchar>(i,j) 
                    = (double)img.at<cv::Vec3b>(i,j)[0] * b
                    + (double)img.at<cv::Vec3b>(i,j)[1] * g
                    + (double)img.at<cv::Vec3b>(i,j)[2] * r 
                    ;

    cmp(grey_img, 124);
    cmp(grey_img, 125);
    cmp(grey_img, 126);
    cmp(grey_img, 127);
    
    // {
    //     cv::imshow("grey_img", grey_img);
    //     cv::imshow("img",img);
    //     cv::waitKey(0);
    //     cv::destroyAllWindows();
    // }

    return 0;
}