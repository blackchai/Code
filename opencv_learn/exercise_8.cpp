#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <algorithm>

cv::Mat max_pooling(cv::Mat img)
{
    int rows = img.rows;
    int cols = img.cols;

    int channels = img.channels();
    int r = 8;

    cv::Mat res = cv::Mat::zeros(rows, cols, CV_8UC3);

    for (int k = 0; k < channels; k++)
        for (int i = 0; i < rows; i += r)
            for (int j = 0; j < cols; j += r)
            {
                double maxv = 0;
                for (int di = 0; di < r && i + di < rows; di++)
                    for (int dj = 0; dj < r && j + dj < cols; dj++)
                        maxv = std::max(maxv, (double)img.at<cv::Vec3b>(i + di, j + dj)[k]);
                for (int di = 0; di < r && i + di < rows; di++)
                    for (int dj = 0; dj < r && j + dj < cols; dj++)
                        res.at<cv::Vec3b>(i + di, dj + j)[k] = maxv;
            }

    return res;
}

cv::Mat average_pooling(cv::Mat img)
{
    int rows = img.rows;
    int cols = img.cols;
    cv::Mat n_img = cv::Mat::zeros(rows, cols, CV_8UC3);

    int r = 8;
    int channels = img.channels();

    for (int k = 0; k < channels; k++)
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

int main(int argc, const char *argv[])
{
    cv::Mat img = cv::imread("image_1.png");

    cv::imshow("max_Pooling", max_pooling(img));
    cv::imshow("average_Pooling", average_pooling(img));
    cv::imshow("img", img);
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}