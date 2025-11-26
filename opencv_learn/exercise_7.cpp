#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

cv::Mat Average_Pooling(cv::Mat img)
{
    int rows = img.rows;
    int cols = img.cols;
    cv::Mat n_img = cv::Mat::zeros(rows, cols, CV_8UC3);

    int r = 8;
    int channels = img.channels();
    
    for (int k = 0; k < channels; k ++ )
        for (int i = 0; i < rows; i += r)
            for (int j = 0; j < cols; j += r)
            {
                double ave = 0;
                for (int di = 0; di < r && i + di < rows; di++)
                    for (int dj = 0; dj < r && j + dj < cols; dj++)
                        ave += img.at<cv::Vec3b>(i + di, j + dj)[k];
                ave /= (double)(r * r);
                for (int di = 0; di < r && i + di < rows; di++)
                    for (int dj = 0; dj < r && j + dj < cols; dj++)
                        n_img.at<cv::Vec3b>(i + di, j + dj)[k] = ave;
            }
    
    return n_img;
}

int main(int argc, char **argv)
{
    cv::Mat img = cv::imread("../build/image_1.png");
    if (img.empty())
    {
        std::cout << "图像读取错误！！" << std::endl;
        return -1;
    }
    cv::Mat n_img = Average_Pooling(img);
    {
        cv::imshow("img", img);
        cv::imshow("n_img", n_img);
        cv::waitKey(0);
        cv::destroyAllWindows();
    }
    return 0;
}