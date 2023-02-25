/*!
    @file        encoding_test.hpp
    @brief       测试CPP字符编码、以及字符输出
    @details     详细说明
    // 测试运行环境：
    // wsl + gcc6.3.0(或gcc，改文件后缀就行)
    // windows 10 + VS2017 + qt5.12.1
    // 说明，在注释中说的编码E59BBD，是按照打印结果从低字节到高字节排练，并不一定和实际
    // 的编码大小端一致。

    // 使用的测试数据：国家
    // utf-8编码: 0xE5 0x9B 0xAF (e59bbd)	0xE5 0xAE 0xB6 (e5aeb6)
    // gbk(gb18030)编码，即windows下的ANSI: b9fa bcd2
    @sa          是see also的意思，填写与本文件有关的内容
    @author      LJH
    @date        2023-02-22 16:53:25
    @version     v1.0
    @remark      人工智能与仿真实验室
    @copyright   Copyright By AI&Simulaiton Lab, All Rights Reserved
*/

#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <wchar.h>
#include <locale.h>
#include <fstream>

#include <string>
#include <bitset>

#include <QString>
#include <QDebug>
#include <QFile>
#include <iostream>
#include <QTextStream>
#include <QDataStream>
#include <QTextCodec>

using namespace std;
void cpp_encoding_test()
{
    char sa[] = "国家";
    char sb[] = u8"国家";

    char *p = (char *)sa;
    int i = 0;

    printf("sizeof(sa) is %d\n", sizeof(sa));
    for (; i < sizeof(sa); i++) {
        printf("byte: %x\n", p[i]);
    }
    printf("content start\n");
    printf("%s\n", sa);
    printf("content end\n");

    i = 0;
    p = (char *)sb;
    printf("sizeof(sb) is %d\n", sizeof(sb));
    for (; i < sizeof(sb); i++) {
        printf("byte: %x\n", p[i]);
    }
    printf("content start\n");
    printf("%s\n", sb);
    printf("content end\n");

    qDebug() << "output by qdebug sa: " << sa;
    qDebug() << "output by qdebug sb:" << sb;

    ofstream output("output/output_sa.txt");
    output << sa;
    output.close();

    ofstream output1("output/output_sb.txt");
    output1 << sb;
    output1.close();
}

template <typename VType>
std::string to_binary(VType value)
{
    std::bitset<sizeof(VType) * 8> bs(value);
    return bs.to_string();
}

int wchar_encoding_test()
{
    // 此语句重要，在win7 + vs2012和
    //  ubuntu 12.04测试结果一致，只要打印wchar_t字符，均加此语句，否则出错。
    setlocale(LC_ALL, "");

    /******************  case 1  **********************************/
    // 文件utf-8编码, 字符串不加L
    // ubuntu : ws是utf-8编码: 如"国"：E59BBD; 打印结果：国家
    // windows: ws是ansi编码: 如"国"：b9fa; 打印结果: 国家
    //    char ws[] = "国家";
    //    char *p = (char *)ws;
    //    int i = 0;

    //    printf("sizeof(ws) is %d\n", sizeof(ws));
    //    for (; i < sizeof(ws); i++){
    //        printf("byte: %x\n", p[i]);
    //    }
    //    printf("content start\n");
    //    printf("%s\n", ws);
    //    printf("content end\n");

    /******************  case 2  **********************************/
    // 2: 文件ansi编码, 字符串不加L
    // ubuntu : ws是ansi编码，如"国"：b9fa; 打印结果：无，出错
    // windows: ws是ansi编码: 如"国"：b9fa; 打印结果: 国家
    /*   	char ws[] = "国家";
    char *p = (char *)ws;
    int i = 0;

    //setlocale(LC_ALL, "zh_CN.UTF-8");
    printf("sizeof(ws) is %d\n", sizeof(ws));
    for (; i < sizeof(ws); i++){
        printf("byte: %x\n", p[i]);
    }
    printf("content start: %s\n", ws);
    printf("content end\n");  */

    /******************  case 3  **********************************/
    // 3: 文件utf-8编码, 字符串加L, 必须采用wchar_t, 用char编译器报错, 用wprintf打印
    // ubuntu : ws是ucs-4编码，如"国"：0x000056fd; 打印结果：国家
    // windows: ws是ucs-2编码: 如"国"：0x56fd; 打印结果: 国家
    /* 	wchar_t ws[] = L"国家";
    char *p = (char *)ws;
    int i = 0;

    wprintf(L"sizeof(ws) is %d\n", sizeof(ws));
    for (; i < sizeof(ws); i++){
        wprintf(L"byte: %x\n", p[i]);
    }
    wprintf(L"wprintf content start:\n");  //必须用wprintf, 且wprintf和printf不能同时使用.
    wprintf(L"%ls\n", ws);
    wprintf(L"content end\n");    */

    /******************  case 4  **********************************/
    // 4: 文件utf-8编码, 字符串加L, 必须采用wchar_t, 用char编译器报错, 用printf打印
    // ubuntu : ws是ucs-4编码，如"国"：0x000056fd; 打印结果：国家
    // windows: ws是ucs-2编码: 如"国"：0x56fd; 打印结果: 国家
    //    wchar_t ws[] = L"国家";
    //    char *p = (char *)ws;
    //    int i = 0;

    //    printf("sizeof(ws) is %d\n", sizeof(ws));
    //    for (; i < sizeof(ws); i++){
    //        std::string s = to_binary(p[i]);
    //        printf("byte b: %s\n", s.c_str());
    //        printf("byte x: %x\n", p[i]);

    //    }

    //    printf("printf content start:\n");  //wprintf和printf不能同时使用.
    //    printf("%ls\n", ws);
    //    printf("content end\n");

    /******************  case 5  **********************************/
    // 5: 文件ansi编码, 字符串加L, 必须采用wchar_t, 用char编译器报错
    // ubuntu : 编译不通过
    // windows: ws是ucs-2编码: 如"国"：0x56fd; 打印结果: 国家
    //    wchar_t ws[] = L"国家"; // 文件ansi编码，ws是unicode编码: 如国：56fd
    //    char *p = (char *)ws;
    //    int i = 0;

    //    wprintf(L"sizeof(ws) is %d\n", sizeof(ws));
    //    for (; i < sizeof(ws); i++){
    //        wprintf(L"byte: %x\n", p[i]);
    //    }
    //    wprintf(L"wprintf content start:\n");  //必须用wprintf, 且wprintf和printf不能同时使用.
    //    wprintf(L"%ls\n", ws);
    //    wprintf(L"content end\n");

    /******************  case 6  **********************************/
    // 6: QStrign 文件utf8编码， 字符串加u8
    // 6: QString 文件utf-8编码, 字符串加L, 必须采用wchar_t, 用char编译器报错, 用printf打印
    // ubuntu : ws是ucs-4编码，如"国"：0x000056fd; 打印结果：国家
    // windows: ws是ucs-2编码: 如"国"：0x56fd; 打印结果: 国家
    int *t_i = new int(1);
    qDebug() << "int data" << t_i << " size of data" << sizeof(t_i);

    /******************  case 文件    **********************************/
    //    QString s = u8"中国";
    //    std::cout << s.toUtf8().toStdString() << std::endl;

    //    std::ifstream ifile("test_file_big.txt");
    //    std::wstring res;
    //    if (ifile) {
    //        wchar_t wc;
    //        while (!ifile.eof()) {
    //            ifile.read((char *)(&wc), 2);
    //            res = res + wc;
    //        }
    //    }
    //    std::wcout << res << std::endl;
    //    ifile.close();
    return 0;
}

void qt_encoding_test()
{
    QString str = u8"国家"; // 和aa对比

    // 通过序列化查看内部的数据编码
    QFile file("output/qt_test.txt");
    file.open(QFile::WriteOnly);
    QDataStream ostream(&file);

    ostream << str;

    // 测试以下接口：toLatin1、toUtf8、toLocal8Bit、toUcs4
    auto latin1 = str.toLatin1();
    qDebug() << "toLatin1" << latin1
             << "with size of: " << latin1.size(); // "汉字"不在latin1字符集中，所以结果无意义

    auto utf8 = str.toUtf8();
    qDebug() << "toUtf8" << utf8 << "with size of: " << (utf8.size()); // 返回utf8编码的一串数字

    auto local8bit = str.toLocal8Bit();
    qDebug() << "toLocal8Bit" << local8bit << "with size of: "
             << (local8bit.size()); // 返回windows操作系统设置的字符集gb2312的编码

    auto ucs4 = str.toUcs4();
    qDebug() << "toUcs4" << ucs4
             << "with size of: " << (ucs4.size()); // 返回ucs4编码组成的QVector，一个汉字占用4字节

    ostream << "\n";
    ostream << latin1 << "\n";
    ostream << utf8 << "\n";
    ostream << local8bit << "\n";
    ostream << ucs4 << "\n";

    file.flush();
    file.close();
}
