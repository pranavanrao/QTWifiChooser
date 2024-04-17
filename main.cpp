#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QDebug>
#include <QMap>
#include <algorithm>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget w;

    // Define and populate the QMap with some unsorted data
    QMap<QString, int> data;
    data.insert("ACT WiFi", 25);
    data.insert("Airtel WiFi", 70);
    data.insert("Hathway WiFi", 35);
    data.insert("Lacal WiFi", 50);
    data.insert("Jio WiFi", 80);

    // Sort the QMap by its values in descending order
    QList<QString> keys = data.keys();
    std::sort(keys.begin(), keys.end(), [&data](const QString &key1, const QString &key2) {
        return data.value(key1) > data.value(key2); // Note the '>' for descending order
    });

    QVBoxLayout mainLayout(&w);

    // Create QPushButton widgets to display the sorted data
    for (const auto &key : keys) {
        QPushButton *button = new QPushButton(QString::number(data.value(key)) + " : " + key);
        mainLayout.addWidget(button);
        QObject::connect(button, &QPushButton::clicked, [key]() {
            qDebug() << "Button" << key << "clicked!";
        });
    }

    w.setLayout(&mainLayout);
    w.show();

    return app.exec();
}
