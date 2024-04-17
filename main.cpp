#include "widget.h"

#include <QApplication>
#include <QMap>
#include <QString>
#include <QDebug>
#include <QPushButton>
#include <QVBoxLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget w;

    QMap<QString, int> data;

    data.insert("ACT WiFi", 25);
    data.insert("Airtel WiFi", 30);
    data.insert("Hathway WiFi", 35);
    data.insert("Lacal WiFi", 50);
    data.insert("Jio WiFi", 80);

    QMap<int, QString> sortedData;
    for (auto it = data.constBegin(); it != data.constEnd(); ++it) {
        sortedData.insert(it.value(), it.key());
    }

    QVBoxLayout mainLayout(&w);

    qDebug() << "All data:";

    for (auto it = sortedData.constBegin(); it != sortedData.constEnd(); ++it) {
        QPushButton *button = new QPushButton(it.value() + ": " + QString::number(it.key()), &w);
        mainLayout.addWidget(button);
    }

    w.setLayout(&mainLayout);

    w.show();

    return a.exec();
}
