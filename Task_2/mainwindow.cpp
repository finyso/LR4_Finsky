#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sort.h"
#include "pow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pushButtonSortSearch_clicked() {
    QVector<int> arr;
    for (QString s : ui->lineEditArray->text().split(QRegExp(" "), Qt::SkipEmptyParts))
        arr.append(s.toInt());

    int searchValue = ui->lineEditSearch->text().toInt();
    ui->textBrowser->clear();

    interpolationSort(arr, ui->textBrowser);

    int index = interpolationSearch(arr, searchValue) + 1;
    int powmod = binpow(index, arr.size());

    if (index != -1)
        ui->textBrowser->append("Элемент найден на позиции: " + QString::number(index) +
                                "\nИндекс ^ длина по модулю: " + QString::number(powmod));
    else
        ui->textBrowser->append("Элемент не найден");
}
