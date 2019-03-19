#ifndef PAINTINGWIDGET_H
#define PAINTINGWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QImage>
#include "renderarea.h"

#include <QCheckBox>
#include <QComboBox>
#include <QLabel>
#include <QSpinBox>
#include <QSpinBox>

class RenderArea;

class PaintingWidget : public QWidget {

public:
    PaintingWidget(QWidget * parent);
    void paintEvent(QPaintEvent*);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void drawLineTo(const QPoint &endPoint);
    void resizeEvent(QResizeEvent *event);
    void resizeImage(QImage *img, const QSize &newSize);

private slots:
private:
    QImage img;
    bool drawing;
    QPoint lastPoint;
};

#endif // PAINTINGWIDGET_H
