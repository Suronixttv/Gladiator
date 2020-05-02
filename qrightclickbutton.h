#ifndef QRIGHTCLICKBUTTON_H
#define QRIGHTCLICKBUTTON_H

#include <QPushButton>
#include <QMouseEvent>

class qrightclickbutton : public QPushButton
{
    Q_OBJECT

public:
    explicit qrightclickbutton(QWidget *parent = 0);

private slots:
    void mousePressEvent(QMouseEvent *e);


signals:
    void rightClicked();
    void clicked();

public slots:
};

#endif // QRIGHTCLICKBUTTON_H
