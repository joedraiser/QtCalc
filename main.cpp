#include "./ui_MainWindow.h"
#include "callermainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    CallerMainWindow window(nullptr);
    Ui::MainWindow caller;
    caller.setupUi(&window);
    window.result = caller.Q_LINE_3;
    window.first_q_line = caller.Q_LINE_1;
    window.second_q_line = caller.Q_LINE_2;
    window.current_q_line = caller.Q_LINE_1;
    window.resize(480, 640);
    window.show();
    return QApplication::exec();
}
