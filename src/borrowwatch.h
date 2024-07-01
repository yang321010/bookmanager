#ifndef BORROWWATCH_H
#define BORROWWATCH_H

#include <QWidget>

namespace Ui {
class borrowWatch;
}

class borrowWatch : public QWidget
{
    Q_OBJECT

public:
    explicit borrowWatch(QWidget *parent = nullptr);
    ~borrowWatch();

private:
    Ui::borrowWatch *ui;
};

#endif // BORROWWATCH_H
