#include "notepad.h"

#include <QApplication>
#include <iostream>
#include "boost/filesystem.hpp"

namespace fs = boost::filesystem;

int main(int argc, char *argv[])
{
    QApplication EditorApp(argc, argv);
    Notepad Editor;
    Editor.show();

    fs::path a = fs::system_complete(argv[0]).parent_path();
    std::cout << a << std::endl;

    return EditorApp.exec();
}
