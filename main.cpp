
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

// #include "cpp/encoding_test.hpp"
// #include "qt_normal/mainwindow.h"
#include <iostream>
#include "cpp_alg/list/removeElements.hpp"

int main(int argc, char *argv[])
{
    // binary_search();
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);

    ListNode *result = removeElements(head, 3);
    while (result != nullptr)
    {
        std::cout << result->val << " ";
        result = result->next;
    }
    std::cout << std::endl;
    return 0;

    //    QApplication a(argc, argv);
    //    MainWindow m;
    //    m.show();

    //    return a.exec();
}
