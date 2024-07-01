#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

namespace Ui {
class mainwindow;
}

class mainwindow : public QWidget
{
    Q_OBJECT

public:
    explicit mainwindow(QWidget *parent = nullptr);
    ~mainwindow();

private slots:
    void on_bookadd_currentIndexChanged(int index);

    void on_bookretrival_clicked();

    void on_borrowcard_clicked();

    void on_borrow_currentIndexChanged(int index);

    void on_admin_currentIndexChanged(int index);

    void on_exitlogin_clicked();

private:
    Ui::mainwindow *ui;
};

#endif // MAINWINDOW_H
