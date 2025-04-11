#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <sstream>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pushButtonGenerate_clicked() {
    generateData();
    displayMatrices();
}

void MainWindow::generateData() {
    data.clear();
    for (int i = 0; i < 3; ++i) {
        Vector<int> left;
        Vector<IntDoublePair> right;

        for (int j = 0; j < 4; ++j) {
            left.push_back(i * 10 + j);
            right.push_back(IntDoublePair(j, j + 0.5));
        }

        data.push_back(RowType(left, right));
    }
}

void MainWindow::displayMatrices() {
    std::stringstream ssLeft, ssRight;

    for (size_t i = 0; i < data.size(); ++i) {
        Vector<int>& left = data[i].first;
        Vector<IntDoublePair>& right = data[i].second;

        for (size_t j = 0; j < left.size(); ++j) {
            ssLeft << left[j] << " ";
        }
        ssLeft << "\n";

        for (size_t j = 0; j < right.size(); ++j) {
            ssRight << "(" << right[j].first << "," << right[j].second << ") ";
        }
        ssRight << "\n";
    }

    ui->labelMatrix1->setText(QString::fromStdString(ssLeft.str()));
    ui->labelMatrix2->setText(QString::fromStdString(ssRight.str()));
}
