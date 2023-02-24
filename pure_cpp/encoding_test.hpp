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

template <typename VType>
std::string to_binary(VType value)
{
    std::bitset<sizeof(VType) * 8> bs(value);
    return bs.to_string();
}

int encoding_test()
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
    QString tmp = u8"国家";
    auto tmp_utf8 = tmp.toUtf8();
    auto data = tmp_utf8.data();
    qDebug() << "data" << data << " size of data" << sizeof(data);
    //    std::cout << "std" << sizeof(data) << std::endl;
    int number = 100;
    auto data_size = sizeof(data) - 2;
    auto total_size = number * data_size + 2;
    char *big_data = new char[total_size];
    memset(big_data, 0, total_size);
    for (int i = 0; i < number; i++) {
        memcpy(big_data + i * data_size, data, data_size);
    }
    qDebug() << "copy data" << big_data << " size of data" << sizeof(big_data);

    qDebug() << "tmp=" << tmp << endl;
    qDebug() << "toUtf8" << tmp_utf8 << "with size of: " << sizeof(tmp_utf8)
             << endl;                                 // 返回utf8编码的一串数字
    qDebug() << "toLatin1" << tmp.toLatin1() << endl; //"汉字"不在latin1字符集中，所以结果无意义
    char *p = new char[1 + strlen(tmp.toLatin1().data())];
    strcpy(p, tmp.toLatin1().data());
    for (int i = 0; p[i] != '\0'; i++) {
        printf("0x%02x ", p[i]);
    }
    printf("\n");
    delete p;
    qDebug() << "toLocal8bit" << tmp.toLocal8Bit()
             << endl; // 返回windows操作系统设置的字符集gb18030的编码
    qDebug() << "toUcs4" << tmp.toUcs4() << endl; // 返回ucs4编码组成的QVector，一个汉字占用4字节

    QFile file("test_file_big.txt");
    file.open(QFile::WriteOnly);
    file.write(data);
    file.close();
}

void encoding()
{
    char s[] = "国家";
    printf("%s", s);
    return;
}
