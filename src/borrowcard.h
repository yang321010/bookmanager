#ifndef BORROWCARD_H
#define BORROWCARD_H

#include <QWidget>

namespace Ui {
class borrowCard;
}

class borrowCard : public QWidget
{
    Q_OBJECT

public:
    explicit borrowCard(QWidget *parent = nullptr);
    ~borrowCard();

private slots:
    void on_add_clicked();

    void on_delete_2_clicked();

private:
    Ui::borrowCard *ui;
};

#endif // BORROWCARD_H
