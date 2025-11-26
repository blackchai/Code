#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

cv::Mat sub_color(cv::Mat img)
{
    double value[4] = {32, 96, 160, 224};

    int rows = img.rows;
    int cols = img.cols;

    cv::Mat res = cv::Mat::zeros(rows, cols, CV_8UC3);

    for (int k = 0; k < 3; k++)
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
            {
                double val = img.at<cv::Vec3b>(i, j)[k];
                auto &n_val = res.at<cv::Vec3b>(i, j)[k];
                if (val < 64)
                    n_val = value[0];
                else if (val < 128)
                    n_val = value[1];
                else if (val < 192)
                    n_val = value[2];
                else if (val < 256)
                    n_val = value[3];
            }

    return res;
}

int main(int argc, char **argv)
{
    {
        cv::Mat img = cv::imread("../build/imori.jpg");
        if (img.empty())
        {
            std::cout << "图像读取错误！！！" << std::endl;
            return -1;
        }
        cv::Mat n_img = sub_color(img);
        {
            cv::imshow("img", img);
            cv::imshow("n_img", n_img);
            cv::waitKey(0);
            // cv::destroyAllWindows();
        }
    }

    /********************************************/
    {
        cv::Mat img = cv::imread("../build/image_1.png");
        if (img.empty())
        {
            std::cout << "图像读取错误！！！" << std::endl;
            return -1;
        }
        cv::Mat n_img = sub_color(img);
        {
            cv::imshow("img", img);
            cv::imshow("n_img", n_img);
            cv::waitKey(0);
            // cv::destroyAllWindows();
        }
    }

    return 0;
}