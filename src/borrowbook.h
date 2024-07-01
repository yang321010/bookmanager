#ifndef BORROWBOOK_H
#define BORROWBOOK_H

#include <QWidget>

namespace Ui {
class borrowbook;
}

class borrowbook : public QWidget
{
    Q_OBJECT

public:
    explicit borrowbook(QWidget *parent = nullptr);
    ~borrowbook();

private slots:
    //void on_pushButton_clicked();

    void on_borrow_clicked();

    void on_lookstore_clicked();

private:
    Ui::borrowbook *ui;
};

#endif // BORROWBOOK_H
