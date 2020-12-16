#include "mainwindow.h"

#include <QApplication>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{

    const char* test3 = "abc";
    const string test4 = "abc";

    cout << test3 << endl;
    cout << *test3 << endl;
    cout << test4 << endl;
    cout << sizeof (test3) << endl;
    cout << sizeof (test4) << endl;
    cout << "************\n";

    const int test5[] = {1, 3 ,5};
    const int* test7 = test5;

    cout << test5 << endl;
    cout << test7 << endl;
    cout << test7[0] << endl;
    cout << sizeof (test7) << endl;
    cout << sizeof (test7[0]) << endl;
    cout << "************" << endl;
    cout << *test7 << endl;

    const char* test1[] = {
        "abc",
        "def",
        "ohg",
        "asdf"
    };

    const string test2[] = {
        "abc",
        "def",
        "ohg",
        "asdf"
    };

    int x = sizeof (test1)/sizeof(test1[0]);
    cout << sizeof(test1) << endl;
    cout << sizeof(test1[0]) << endl;
    cout << test1 << endl;
    cout << *test1 << endl;
    cout << test1[0] << endl;
    cout << *test1[0] << endl;
    cout << x << endl;
    cout << "*************\n";
    x = sizeof (test2)/sizeof(test2[0]);
    cout << sizeof(test2) << endl;
    cout << sizeof(test2[0]) << endl;
    cout << test2 << endl;
    cout << *test2 << endl;
    cout << test2[0] << endl;
    cout << x << endl;


    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
