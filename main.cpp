
/*!
    @file        main.cpp
    @brief       启动函数
    @details     其他测试代码编写完成后，在main中include代码，进行测试。
    @sa          是see also的意思，填写与本文件有关的内容
    @author      LJH
    @date        2023-02-22 16:46:24
    @version     v1.0
    @remark      人工智能与仿真实验室
    @copyright   Copyright By AI&Simulaiton Lab, All Rights Reserved
*/

#include <QCoreApplication>
#include "pure_cpp/encoding_test.hpp"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    encoding_test();

    return a.exec();
}
