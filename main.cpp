
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

#include <QApplication>
#include "pure_cpp/encoding_test.hpp"
#include "qt_normal/mainwindow.h"
using namespace std;

int main(int argc, char *argv[])
{

    // QCoreApplication a(argc, argv);
    // encoding();

    //    auto cc = "我";
    //    std::cout << cc << std::endl;

    //    printf("%s\n", cc);
    //    printf("%s\n", cc);

    //    const char *code = "abc中文def";

    //    cout << u8"abc中文def" << endl;
    //    cout << code << endl;

    //    auto aa = QString::fromLocal8Bit(u8"我");
    //    cout << aa.toStdString() << std::endl;
    //    qDebug() << aa;
    //    qDebug() << QString(u8"你好");

    //    std::cout << aa.toLocal8Bit().data() << std::endl;

    // setlocale(LC_ALL, "");

    qt_encoding_test();
    //    const char *code = "abc中文def";

    //    cout << "abc中文def" << endl;
    //    cout << code << endl;

    //    auto s = QString("你好");
    //    qDebug() << s;
    //    cout << s.toStdString() << endl;
    //    cout << s.toLocal8Bit().data() << endl;

    //    char sa[] = "国家";
    //    char sb[] = u8"国家";

    //    char *p = (char *)sa;
    //    int i = 0;

    //    printf("sizeof(sa) is %d\n", sizeof(sa));
    //    for (; i < sizeof(sa); i++) {
    //        printf("byte: %x\n", p[i]);
    //    }
    //    printf("content start\n");
    //    printf("%s\n", sa);
    //    printf("content end\n");

    //    i = 0;
    //    p = (char *)sb;
    //    printf("sizeof(sb) is %d\n", sizeof(sb));
    //    for (; i < sizeof(sb); i++) {
    //        printf("byte: %x\n", p[i]);
    //    }
    //    printf("content start\n");
    //    printf("%s\n", sb);
    //    printf("content end\n");

    //    qDebug() << "output by qdebug sa: " << sa;
    //    qDebug() << "output by qdebug sb:" << sb;

    //    QApplication a(argc, argv);
    //    MainWindow m;
    //    m.show();

    //    return a.exec();
}
