#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QScrollArea>
#include <QLabel>
#include <QGroupBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QLabel* MainWindow::createImageLabel(const QImage& image)
{
    QLabel* result = new QLabel(this);
    result->setBackgroundRole(QPalette::Base);
    result->setScaledContents(true);
    result->setPixmap(QPixmap::fromImage(image));

    return  result;
}

QGroupBox* MainWindow::createGroupBox(QLabel* imageLabel,
                                     QLabel* nameLabel)
{
    QGroupBox* groupBox = new QGroupBox(this);
    groupBox->setStyleSheet("QGroupBox{border:2px solid gray;border-radius:5px;margin-top: 1ex;}"
                            "QGroupBox::title{subcontrol-origin: margin;subcontrol-position:top center;padding:0 3px;}");

    // Make groupBox owner of layout "vBox"
    QVBoxLayout* vBox = new QVBoxLayout(groupBox);

    vBox->addWidget(imageLabel);
    vBox->addWidget(nameLabel);

    return groupBox;
}

void MainWindow::on_actionExecuta_triggered()
{
    QScrollArea* scrollArea = new QScrollArea(this);

    // Make scrollArea owner of layout
    ui->layoutRight->addWidget(scrollArea);

    // Add an empty widget to the left layout
    ui->layoutLeft->addWidget(new QScrollArea());

    QImage* image = new QImage("/home/marco/Pictures/o9o0_10.jpg");

    QGroupBox* groupBox = new QGroupBox(this);

    // Make groupBox owner of layout "vBox"
    QVBoxLayout* vBox = new QVBoxLayout(groupBox);

    vBox->addWidget(createGroupBox(createImageLabel(*image),
                                   new QLabel("Marco")));
    vBox->addWidget(createGroupBox(createImageLabel(*image),
                                   new QLabel("Marco 2")));
    vBox->addWidget(createGroupBox(createImageLabel(*image),
                                   new QLabel("Marco 3")));

    scrollArea->setWidget(groupBox);
}

