#ifndef WINDOWARM_H
#define WINDOWARM_H

#include <QDialog>

namespace Ui {
class WindowARM;
}

class WindowARM : public QDialog
{
    Q_OBJECT

public:
    explicit WindowARM(QWidget *parent = nullptr);
    ~WindowARM();

private:
    Ui::WindowARM *ui;
};

#endif // WINDOWARM_H
