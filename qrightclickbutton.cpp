#include "qrightclickbutton.h"

qrightclickbutton::qrightclickbutton(QWidget *parent) : QPushButton(parent)
{

}

void qrightclickbutton::mousePressEvent(QMouseEvent *e){
    if(e->button()==Qt::RightButton){
        emit rightClicked(); }else if (e->button()==Qt::LeftButton ){

        emit clicked();

}

}

