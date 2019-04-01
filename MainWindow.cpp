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


void MainWindow::on_pushButton_clicked() {
    paintingWidget->clear();
}

void MainWindow::on_pushButton_2_clicked() {
    QColor newColor = QColorDialog::getColor(this->paintingWidget->penColor());
    if (newColor.isValid()) {
        paintingWidget->setPenColor(newColor);
    }
    ui->pushButton_2->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,0"));
}

void MainWindow::on_horizontalSlider_3_actionTriggered(int action) {
    paintingWidget->setPenWidth(action);
}



void MainWindow::on_checkBox_2_clicked(bool checked) {
    paintingWidget->setColorGradient(checked);
}


void MainWindow::on_horizontalSlider_actionTriggered(int action) {
    paintingWidget->setSlices(action);
}

void MainWindow::on_spinBox_valueChanged(int arg1) {
    ui->horizontalSlider->setValue(arg1);
    paintingWidget->setSlices(arg1);
}

void MainWindow::on_checkBox_3_clicked(bool checked) {
    paintingWidget->setMirror(checked);
}
