#ifndef DEGREE1_H
#define DEGREE1_H

#include <QDialog>

namespace Ui {
class degree1;
}

class degree1 : public QDialog
{
    Q_OBJECT

public:
    explicit degree1(QWidget *parent = 0);
    ~degree1();

private:
    Ui::degree1 *ui;
};

#endif // DEGREE1_H
