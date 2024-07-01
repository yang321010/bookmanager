#ifndef BACKBOOK_H
#define BACKBOOK_H

#include <QWidget>

namespace Ui {
class backbook;
}

class backbook : public QWidget
{
    Q_OBJECT

public:
    explicit backbook(QWidget *parent = nullptr);
    ~backbook();

private slots:
    void on_CardNo_textChanged(const QString &arg1);

    void on_pushButton_clicked();

private:
    Ui::backbook *ui;
};

#endif // BACKBOOK_H
