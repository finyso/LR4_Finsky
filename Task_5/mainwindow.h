#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "vector.h"
#include "pair.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonGenerate_clicked();

private:
    Ui::MainWindow *ui;

    using IntDoublePair = Pair<int, double>;
    using RowType = Pair<Vector<int>, Vector<IntDoublePair>>;
    Vector<RowType> data;

    void generateData();
    void displayMatrices();
};

#endif // MAINWINDOW_H
