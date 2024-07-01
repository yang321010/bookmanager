#ifndef MULTIBOOKINSERT_H
#define MULTIBOOKINSERT_H

#include <QWidget>

namespace Ui {
class multibookinsert;
}

class multibookinsert : public QWidget
{
    Q_OBJECT

public:
    explicit multibookinsert(QWidget *parent = nullptr);
    ~multibookinsert();

private slots:


    void on_fileimport_clicked();

    void on_multipleinsert_clicked();

    void on_clear_clicked();

private:
    Ui::multibookinsert *ui;
};

#endif // MULTIBOOKINSERT_H
