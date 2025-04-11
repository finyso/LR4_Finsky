#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonSort_clicked();
    void on_pushButtonSearch_clicked();

private:
    Ui::MainWindow *ui;
    QVector<int> sortedArray;
};

#endif // MAINWINDOW_H
