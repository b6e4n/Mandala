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
    connect(ui->slicesSlider, SIGNAL(sliderMoved(int)),this, SLOT(setSlices(int)));

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



void MainWindow::on_slicesSlider_actionTriggered(int action)
{
    paintingWidget->setSlices(action);
}

void MainWindow::on_spinBoxSlices_valueChanged(int arg1)
{
    ui->slicesSlider->setValue(arg1);
    paintingWidget->setSlices(arg1);
}

void MainWindow::on_pushButtonClear_clicked()
{
    paintingWidget->clear();
}

void MainWindow::on_horizontalSliderWidth_actionTriggered(int action)
{
    paintingWidget->setPenWidth(action);
}

void MainWindow::on_pushButtonColor_clicked()
{
    QColor newColor = QColorDialog::getColor(this->paintingWidget->penColor());
    if (newColor.isValid()) {
        paintingWidget->setPenColor(newColor);
    }
    ui->pushButtonColor->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,0"));
}

void MainWindow::on_checkBoxMulticolor_clicked(bool checked)
{
    paintingWidget->setColorGradient(checked);
}

void MainWindow::on_checkBoxMirror_clicked(bool checked)
{
    paintingWidget->setMirror(checked);
}
