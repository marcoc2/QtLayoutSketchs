#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QScrollArea>
#include <QLabel>
#include <QGroupBox>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>

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


void MainWindow::on_actionMultiple_Canvas_triggered()
{
    ui->gridLayout->removeItem(ui->horizontalLayout);

    QGraphicsView* view1 = new QGraphicsView(centralWidget());
    view1->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    view1->setResizeAnchor(QGraphicsView::NoAnchor);
    QGraphicsView* view2 = new QGraphicsView(centralWidget());
    view2->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    view2->setResizeAnchor(QGraphicsView::NoAnchor);
    QGraphicsView* view3 = new QGraphicsView(centralWidget());
    view3->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    view3->setResizeAnchor(QGraphicsView::NoAnchor);
    QGraphicsView* view4 = new QGraphicsView(centralWidget());
    view4->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    view4->setResizeAnchor(QGraphicsView::NoAnchor);

    // Create scene
    QGraphicsScene* scene = new QGraphicsScene();

    // Create pixmap item (image)
    QGraphicsPixmapItem* pixmapItem = new QGraphicsPixmapItem();
    // (Re)Learn how to add image as resource
    QImage image("/home/marco/workspace/QtLayoutSketchs/images/vivillon.png");
    pixmapItem->setPixmap(QPixmap::fromImage(image));

    // Add image to the scene
    scene->addItem(pixmapItem);
    scene->setSceneRect(image.rect());

    // Set scene to the first Graphics View
    view1->setScene(scene);
    view1->fitInView(scene->sceneRect(),
                     Qt::AspectRatioMode::KeepAspectRatio);

    ui->gridLayout->addWidget(view1, 0, 0);
    ui->gridLayout->addWidget(view2, 0, 1);
    ui->gridLayout->addWidget(view3, 1, 0);
    ui->gridLayout->addWidget(view4, 1, 1);
}
