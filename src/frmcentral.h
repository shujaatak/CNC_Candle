#ifndef FRMCENTRAL_H
#define FRMCENTRAL_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QSettings>

namespace Ui {
class frmCentral;
}

class frmCentral : public QMainWindow
{
    Q_OBJECT

public:
    explicit frmCentral(QWidget *parent = 0);
    ~frmCentral();

public slots:
    void saveSettings();
    void loadSettings();

private slots:

private:
    Ui::frmCentral *ui;
};

#endif // FRMCENTRAL_H
