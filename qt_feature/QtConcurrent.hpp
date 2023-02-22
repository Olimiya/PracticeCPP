//#include "mainwindow.h"
//#include <QApplication>
//#include <QDebug>
//#include <QDir>
//#include <QFileDialog>
//#include <QFile>
//#include <QStandardPaths>
//#include <algorithm>
//#include <qglobal.h>
//#include <QTextCodec>
//#include <string>
////#include <vld.h>
//#include <QProcess>
// using namespace std;

// int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

//    QFont font("Microsoft Yahei", 11);
//    a.setFont(font);

//    auto p = "D:";
//    auto n = "/000/";
//    QDir dir(p);
//    if(!dir.exists(n))
//        dir.mkdir(n);
//    return a.exec();
//}

////// QtConcurrent模块 QFuture的一个示例
////#include <QtWidgets>
////#include <QtConcurrent>

////#include <functional>

////using namespace QtConcurrent;

////int main(int argc, char **argv)
////{
////    QApplication app(argc, argv);

////    const int iterations = 200;

////    QVector<int> vector;
////    for (int i = 0; i < iterations; ++i)
////        vector.append(i);

////    QProgressDialog dialog;
//////    dialog.setAutoClose(false);
////    dialog.setLabelText(QString("Progressing using %1
///thread(s)...").arg(QThread::idealThreadCount()));

////        // QFutureWatcher用来监视一个QFuture，通过信号-槽机制
////    QFutureWatcher<void> futureWatcher;
////    QObject::connect(&futureWatcher, &QFutureWatcher<void>::finished, &dialog,
///&QProgressDialog::reset); /    QObject::connect(&dialog, &QProgressDialog::canceled,
///&futureWatcher, &QFutureWatcher<void>::cancel); /    QObject::connect(&futureWatcher,
///&QFutureWatcher<void>::progressRangeChanged, &dialog, &QProgressDialog::setRange); /
///QObject::connect(&futureWatcher, &QFutureWatcher<void>::progressValueChanged,  &dialog,
///&QProgressDialog::setValue);

////    // 假装这里有复杂的计算
////    std::function<void(int&)> spin = [](int &iteration) {
////        const int work = 1000 * 1000 * 40;
////        volatile int v = 0;
////        for (int j = 0; j < work; ++j)
////            ++v;

////        qDebug() << "iteration" << iteration << "in thread" << QThread::currentThreadId();
////    };

////        // QFuture用来表征异步运算的未来的结果。
////        // 可以看出，我们是先使用QFutureWatcher连接信号，再将实际的QFuture对象注入
////        //
///map函数从线程池申请最佳的线程个数对容器中每一个项目用指定的函数并行地计算，并就地修改。线程启动之时就返回一个QFuture。
////    futureWatcher.setFuture(QtConcurrent::map(vector, spin));

////    // 显示进度条，并开启事件循环
////    dialog.exec();

////        // 让主线程不要过早的结束，等待线程完成对vector的处理后再结束。类似pthread_join()
////    futureWatcher.waitForFinished();

////    qDebug() << "Canceled?" << futureWatcher.future().isCanceled();

////    std::function<QString(const QString&)> hello = [](const QString& name)
////    {
////        qDebug() << "Hello" << name << "from" << QThread::currentThread();
////        return name;
////    };
////    QFuture<QString> f1 = run(hello, QString("Alice"));
////    QFuture<QString> f2 = run(hello, QString("Bob"));
////    f1.waitForFinished();
////    f2.waitForFinished();
////    qDebug() << f1.result() << f2.result();
////}
