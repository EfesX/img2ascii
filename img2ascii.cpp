#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core/hal/interface.h>

#include <iostream>

 const cv::String keys =
    "{help usage ? |       | print this message }"
    "{size  s      |   100 | the size of the result image }"
    "{inv          |       | iverse source image }"
    "{@image       |       | path to image }"
 ;

 const cv::String symbols = "@%#*+=-:. ";
;
 const auto ratio = 255 / symbols.size();


int main(int argc, char *argv[])
{
    try {

    cv::CommandLineParser parser(argc, argv, keys);
    parser.about("The converter images to ASCII art (img2ascii) v0.1.0");

    if(parser.has("help"))
    {
        parser.printMessage();
        return 0;
    }

    cv::String img_path = parser.get<cv::String>(0);
    cv::Mat img = cv::imread(img_path, cv::IMREAD_GRAYSCALE);

    if(img.empty()) throw std::runtime_error("Image read unsuccessfully");

    cv::Size size(parser.get<int>("size"), parser.get<int>("size"));

    cv::Mat resized_img;
    cv::resize(img, resized_img, size, 0, 0, cv::INTER_AREA);

    if(parser.has("inv")) cv::bitwise_not(resized_img, resized_img);

    cv::Mat mat(resized_img);
    
    for(auto c = 0; c < size.width; c++)
    {
        for(auto r = 0; r < size.height; r++)
        {
            auto idx = symbols.size() - int(resized_img.at<uint8_t>(c, r) / ratio);
            if(idx >= symbols.size()) idx = symbols.size() - 1;
            std::cout << symbols[idx];
        }
        std::cout << "\n";
    }

    } 
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}