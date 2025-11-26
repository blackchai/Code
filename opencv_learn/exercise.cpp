#include <opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

void to_grey_image();
void images_test();
void video_test();
void web_camera_test();


int main(void)
{
    // video_test();
    // web_camera_test();
    to_grey_image();
    return 0;
}




void images_test()
{
    std::string path = "../build/RM2.jpg";
    cv::Mat img = cv::imread(path);
    cv::imshow("Image", img);
    cv::waitKey(0);
}

void video_test()
{
    std::string path = "../build/test_video.mp4";
    cv::VideoCapture cap(path);
    cv::Mat img;
    while(1)
    {
        cap.read(img);
        cv::imshow("Image", img);
        cv::waitKey(20);
    }
}

void web_camera_test()
{   
    cv::VideoCapture cap(0);
    cv::Mat img;
    while(true)
    {
        cap.read(img);
        cv::imshow("image",img);
        cv::waitKey(1);
    }
}

void to_grey_image()
{
    std::string path = "../build/RM2.jpg";
    cv::Mat img = cv::imread(path);
    cv::Mat gray_img, img_blur;
    cv::cvtColor(img, gray_img, cv::COLOR_BGR2GRAY);
    cv::GaussianBlur(img, img_blur, cv::Size(7,7), 5, 0);//高斯模糊
    cv::imshow("Image",img);
    cv::imshow("Image_Gray",gray_img);
    cv::imshow("Image Blur",img_blur);
    cv::waitKey(0);
}