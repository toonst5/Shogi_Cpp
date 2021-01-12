#include <QApplication>
#include "game.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Shogi::game* w = new Shogi::game();
    w->show();
    w->displayMainMenu();
    return a.exec();
}
