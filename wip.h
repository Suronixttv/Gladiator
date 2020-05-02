#ifndef WIP_H
#define WIP_H

#include <QDialog>

namespace Ui {
class Wip;
}

class Wip : public QDialog
{
    Q_OBJECT

public:
    explicit Wip(QWidget *parent = nullptr);
    ~Wip();

private slots:
    void on_pushButton_clicked();



private:
    Ui::Wip *ui;
};

#endif // WIP_H
