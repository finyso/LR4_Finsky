#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "median.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

QVector<int> MainWindow::parseInputArray(const QString &text) {
    QVector<int> result;
    QStringList items = text.split(QRegExp(" "), Qt::SkipEmptyParts);
    for (const QString &item : items) {
        result.append(item.toInt());
    }
    return result;
}

QString MainWindow::vectorToString(const QVector<int> &vec) {
    QStringList strList;
    for (int num : vec)
        strList << QString::number(num);
    return strList.join(", ");
}

void MainWindow::on_pushButton_clicked() {
    QVector<int> input = parseInputArray(ui->lineEdit->text());
    QVector<int> result = computeMedians(input);
    ui->textBrowser->setText("Результат: " + vectorToString(result));
}
