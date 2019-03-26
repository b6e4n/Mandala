#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "paintingwidget.h"

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
    void setSlices(int nb) {paintingWidget->setSlices(nb);}
    void penColor();
    void clear() {paintingWidget->clear();}

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
    void on_horizontalSlider_3_actionTriggered(int action);


    void on_checkBox_2_clicked(bool checked);

    void on_doubleSpinBox_valueChanged(double arg1);

    void on_horizontalSlider_actionTriggered(int action);

private:
    Ui::MainWindow *ui;
    PaintingWidget* paintingWidget;
};

#endif // MAINWINDOW_H
