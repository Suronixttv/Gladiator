#ifndef CARDSFRM_H
#define CARDSFRM_H

#include <QDialog>

namespace Ui {
class Cardsfrm;
}

class Cardsfrm : public QDialog
{
    Q_OBJECT

public:
    explicit Cardsfrm(QWidget *parent = nullptr);
    ~Cardsfrm();
    void setCardid(int id);

private:
    Ui::Cardsfrm *ui;
};

#endif // CARDSFRM_H
