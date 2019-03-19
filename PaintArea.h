#ifndef PAINTAREA_H
#define PAINTAREA_H

#include <QWidget>

class PaintArea : public QWidget {

public:
    PaintArea(QWidget *parent);
    void resizeImage(QImage *image, const QSize &newSize);
    void print();

protected:
    void mouseMoveEvent(QMouseEvent *event) ;
    void mousePressEvent(QMouseEvent *event) ;
    void mouseReleaseEvent(QMouseEvent *event) ;
    void paintEvent(QPaintEvent *event) ;
    void resizeEvent(QResizeEvent *event) ;


private:
    void drawLineTo(const QPoint &endPoint);
    bool modified;
    bool scribbling;
    int myPenWidth;
    QColor myPenColor;
    QImage image;
    QPoint lastPoint;
};

#endif // PAINTAREA_H
