#ifndef INSERTBOOK_H
#define INSERTBOOK_H

#include <QWidget>

namespace Ui {
class InsertBook;
}

class InsertBook : public QWidget
{
    Q_OBJECT

public:
    explicit InsertBook(QWidget *parent = nullptr);
    ~InsertBook();

private slots:
    void on_pushButton_clicked();

private:
    Ui::InsertBook *ui;
};

#endif // INSERTBOOK_H
