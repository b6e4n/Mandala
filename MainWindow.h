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

private:
    Ui::MainWindow *ui;
    PaintingWidget* paintingWidget;
};

#endif // MAINWINDOW_H
