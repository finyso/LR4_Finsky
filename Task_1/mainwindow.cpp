#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sorts.h"
#include "search.h"
#include <QElapsedTimer>
#include <QStringList>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

QVector<int> parseInputArray(const QString& input) {
    QVector<int> result;
    for (const QString& numStr : input.split(' ', Qt::SkipEmptyParts))
        result.append(numStr.toInt());
    return result;
}

void MainWindow::on_pushButtonSort_clicked() {
    QVector<int> input = parseInputArray(ui->lineEditArray->text());
    int n = input.size();
    if (n == 0) return;

    QString output;
    QElapsedTimer timer;

    int* arrHeap = new int[n];
    std::copy(input.begin(), input.end(), arrHeap);
    timer.start();
    heapSort(arrHeap, n);
    qint64 timeHeap = timer.nsecsElapsed();
    output += "Heap Sort (" + QString::number(timeHeap) + " ns): ";
    for (int i = 0; i < n; ++i) output += QString::number(arrHeap[i]) + " ";
    output += "\n";

    int* arrQuick = new int[n];
    std::copy(input.begin(), input.end(), arrQuick);
    timer.restart();
    quickSort(arrQuick, 0, n - 1);
    qint64 timeQuick = timer.nsecsElapsed();
    output += "Quick Sort (" + QString::number(timeQuick) + " ns): ";
    for (int i = 0; i < n; ++i) output += QString::number(arrQuick[i]) + " ";
    output += "\n";

    int* arrMerge = new int[n];
    std::copy(input.begin(), input.end(), arrMerge);
    timer.restart();
    mergeSort(arrMerge, 0, n - 1);
    qint64 timeMerge = timer.nsecsElapsed();
    output += "Merge Sort (" + QString::number(timeMerge) + " ns): ";
    for (int i = 0; i < n; ++i) output += QString::number(arrMerge[i]) + " ";
    output += "\n";

    sortedArray.clear();
    for (int i = 0; i < n; ++i)
        sortedArray.append(arrMerge[i]);

    ui->textEditResults->setText(output);

    delete[] arrHeap;
    delete[] arrQuick;
    delete[] arrMerge;
}

void MainWindow::on_pushButtonSearch_clicked() {
    int digit = ui->lineEditSearch->text().toInt();
    int index = binsearch(sortedArray.data(), sortedArray.size(), digit);
    ui->labelSearchResult->setText("Индекс: " + QString::number(index));
}
