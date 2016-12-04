#ifndef FRMMAIN_H
#define FRMMAIN_H

#include <QMainWindow>
#include <QSettings>

namespace Ui {
class frmMain;
}

class frmMain : public QMainWindow
{
    Q_OBJECT

public:
    explicit frmMain(QWidget *parent = 0);
    ~frmMain();    

private slots:
    void saveSettings();
    void loadSettings();

private:
    Ui::frmMain *ui;
};

#endif // FRMMAIN_H
