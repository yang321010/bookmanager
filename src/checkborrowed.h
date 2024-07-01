#ifndef CHECKBORROWED_H
#define CHECKBORROWED_H

#include <QWidget>

namespace Ui {
class checkborrowed;
}

class checkborrowed : public QWidget
{
    Q_OBJECT

public:
    explicit checkborrowed(QWidget *parent = nullptr);
    ~checkborrowed();

private slots:
    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::checkborrowed *ui;
};

#endif // CHECKBORROWED_H
