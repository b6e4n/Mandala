#ifndef PAINTINGWIDGET_H
#define PAINTINGWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QImage>

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
    void setPenColor(const QColor &newColor) {myPenColor = newColor;}
    void setPenWidth(const int &newPenWidth) {myPenWidth = newPenWidth;}
    void setColorGradient(const bool &b) {colorGradient = b;}
    QColor penColor() { return myPenColor; }
    void setSlices(int nb) {slice = nb;}
    void clear();



private:
    QImage img;
    bool drawing;
    QPoint lastPoint;
    int slice;
    QColor myPenColor;
    int myPenWidth;
    bool mirror;
    bool colorGradient;
};

#endif // PAINTINGWIDGET_H
