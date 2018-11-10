#include "mainwindow.h"
#include "piece.h"
#include "frame.h"

#include <QApplication>
#include <QHBoxLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    auto *horizontalLayout = new QHBoxLayout(&w);
    horizontalLayout->addWidget(new Frame);
	w.setWindowTitle("Maci sakk");
    w.show();

    return QApplication::exec();
}
