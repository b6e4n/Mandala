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
    void setPenWidth(int newPenWidth) {paintingWidget->setPenWidth(newPenWidth);}


    void on_spinBoxSlices_valueChanged(int arg1);

    void on_pushButtonClear_clicked();

    void on_pushButtonColor_clicked();

    void on_checkBoxMulticolor_clicked(bool checked);

    void on_checkBoxMirror_clicked(bool checked);

    void on_actionAbout_triggered();

    void on_pushButtonUndo_clicked();

    void on_actionSave_2_triggered();

    void on_pushButtonRedo_clicked();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_slicesSlider_sliderMoved(int position);

private:
    Ui::MainWindow *ui;
    PaintingWidget* paintingWidget;
};

#endif // MAINWINDOW_H
