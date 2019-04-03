#include "paintingwidget.h"
#include <QGridLayout>
#include <QMouseEvent>
#include <QInputDialog>
#include <QDebug>
#include <iostream>

PaintingWidget::PaintingWidget(QWidget * parent) : QWidget(parent) {
    myPenColor = Qt::blue;
    myPenWidth = 4;
    slice = 4;
    mirror = false;
    colorGradient = false;
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
        stack.push_back(img);
        index=stack.size();

}

void PaintingWidget::drawLineTo(const QPoint &endPoint) {
    QPainter painter(&img);
    painter.setPen(QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));

    int h = myPenColor.hslHue();
    int s = myPenColor.hslSaturation();
    int l = myPenColor.lightness();
    int a = myPenColor.alpha();
    QColor tmp(myPenColor);
    for (int i=0; i<slice; i++) {
        if (colorGradient) {
            tmp.setHsl((h+i*360/slice)%360,s,l,a);
            painter.setPen(QPen(tmp, myPenWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
        }
        painter.drawLine(lastPoint, endPoint);
        painter.translate(img.width()/2,img.height()/2);
        painter.rotate(360/slice);
        painter.translate(-img.width()/2,-img.height()/2);
    }
    if (mirror) {
        int x1 = width()-lastPoint.x();
        int x2 = width()-endPoint.x();
        lastPoint.setX(x1);
        QPoint endPoint2(endPoint);
        endPoint2.setX(x2);
        painter.translate(img.width()/2,img.height()/2);
        painter.rotate(-360*((int)((slice+1)/4))/slice);
        painter.translate(-img.width()/2,-img.height()/2);
        for (int i=0; i<slice; i++) {
            if (colorGradient) {
                tmp.setHsl((h+i*360/slice)%360,s,l,a);
                painter.setPen(QPen(tmp, myPenWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
            }
            painter.drawLine(lastPoint, endPoint2);
            painter.translate(img.width()/2,img.height()/2);
            painter.rotate(+360/slice);
            painter.translate(-img.width()/2,-img.height()/2);
        }
    }

    update();

    lastPoint = endPoint;

}

void PaintingWidget::clear() {
    img.fill(qRgb(255, 255, 255));
    update();
}


void PaintingWidget::undo(){

    if(index<=0){
        this->clear();
        stack.clear();
        stack.push_back(img);
        index=1;

    } else{
        index=index-1;
        img=stack[index];
        update();
    }
}

void PaintingWidget::redo(){
    if(index<stack.size()){
        img=stack[index];
        update();
        index++;
    } else{
        img=stack.last();
        update();
    }
}

void PaintingWidget::save_picture(){
    QString name=QInputDialog::getText(this,"Save File","Nommez votre image");

    img.save("./Images/"+name,"png");
}
