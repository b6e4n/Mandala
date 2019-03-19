#include "paintingwidget.h"
#include <QGridLayout>
#include <QMouseEvent>
PaintingWidget::PaintingWidget(QWidget * parent) : QWidget(parent) {
}

void PaintingWidget::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    painter.drawImage(0,0, img);
}

void PaintingWidget::resizeEvent(QResizeEvent *event) {
    if (width() > img.width() || height() > img.height()) {
        int newWidth = qMax(width(), img.width());
        int newHeight = qMax(height(), img.height());
        resizeImage(&img, QSize(newWidth, newHeight));
        update();
    }
    QWidget::resizeEvent(event);
}

void PaintingWidget::resizeImage(QImage *img, const QSize &newSize) {
    if (img->size() == newSize) {
        return;
    }
    QImage newImg(newSize, QImage::Format_RGB32);
    newImg.fill(qRgb(255, 255, 255));
    QPainter painter(&newImg);
    painter.drawImage(QPoint(0, 0), *img);
    *img = newImg;
}

void PaintingWidget::mousePressEvent(QMouseEvent *event) {
        lastPoint = event->pos();
        drawing = true;
}

void PaintingWidget::mouseMoveEvent(QMouseEvent *event) {
    if (drawing) {
        drawLineTo(event->pos());
    }
}

void PaintingWidget::mouseReleaseEvent(QMouseEvent *event) {
        drawLineTo(event->pos());
        drawing = false;
}

void PaintingWidget::drawLineTo(const QPoint &endPoint) {
    QPainter painter(&img);
    painter.setPen(QPen(Qt::SolidLine));
    painter.drawLine(lastPoint, endPoint);
    update();
    lastPoint = endPoint;
}
