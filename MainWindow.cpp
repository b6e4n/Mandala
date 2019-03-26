#include "MainWindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    paintingWidget = ui->paintingWidget;
    connect(ui->actionColor, SIGNAL(triggered()), this, SLOT(penColor()));
    connect(ui->actionClear, SIGNAL(triggered()), this, SLOT(clear()));
    connect(ui->horizontalSlider, SIGNAL(sliderMoved(int)),this, SLOT(setSlices(int)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::penColor() {
    QColor newColor = QColorDialog::getColor(this->paintingWidget->penColor());
    if (newColor.isValid()) {
        paintingWidget->setPenColor(newColor);
    }
}


void MainWindow::on_pushButton_clicked()
{
    paintingWidget->clear();
}

void MainWindow::on_pushButton_2_clicked()
{
    QColor newColor = QColorDialog::getColor(this->paintingWidget->penColor());
    if (newColor.isValid()) {
        paintingWidget->setPenColor(newColor);
    }
}
