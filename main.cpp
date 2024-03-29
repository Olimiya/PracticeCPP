
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

#include "cpp/encoding_test.hpp"
// #include "qt_normal/mainwindow.h"
#include <iostream>
#include "cpp_alg/list/removeElements.hpp"
#include "cpp/template_test.hpp"

void cB(TSTopicContextPtr pdata)
{
    std::cout << "hello world" << std::endl;
    return;
}

int main(int argc, char *argv[])
{
    // binary_search();
    auto ptr = boost::shared_ptr<TSTopicContext>(new TSTopicContext());
    cB(ptr);

    return 0;

    //    QApplication a(argc, argv);
    //    MainWindow m;
    //    m.show();

    //    return a.exec();
}
