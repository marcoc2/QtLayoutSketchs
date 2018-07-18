#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QLabel;
class QGroupBox;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionExecuta_triggered();

    void on_actionMultiple_Canvas_triggered();

private:
    Ui::MainWindow *ui;
    QLabel* createImageLabel(const QImage& image);
    QGroupBox* createGroupBox(QLabel* imageLabel, QLabel* nameLabel);
};

#endif // MAINWINDOW_H
