#ifndef BOOKRETRIVAL_H
#define BOOKRETRIVAL_H

#include <QWidget>

namespace Ui {
class bookRetrival;
}

class bookRetrival : public QWidget
{
    Q_OBJECT

public:
    explicit bookRetrival(QWidget *parent = nullptr);
    ~bookRetrival();

private slots:
    void on_retrival2_clicked();

    void on_retirval1_clicked();

    void on_pushButton_clicked();

    void on_search_clicked();

private:
    Ui::bookRetrival *ui;
};

#endif // BOOKRETRIVAL_H
