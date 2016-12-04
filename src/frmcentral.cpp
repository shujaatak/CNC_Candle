#include "frmcentral.h"
#include "ui_frmcentral.h"

frmCentral::frmCentral(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::frmCentral)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::Widget);

    QMainWindow::setCorner(Qt::BottomRightCorner, Qt::RightDockWidgetArea);
    QMainWindow::setCorner(Qt::BottomLeftCorner, Qt::LeftDockWidgetArea);

    // TODO: Remove test graphics
    QGraphicsScene *scene = new QGraphicsScene();

    scene->addEllipse(-50, -50, 100, 100);
    scene->addLine(-50, -50, 50, 50);

    scene->setSceneRect(-100, -100, 200, 200);
    ui->graphicsView->setScene(scene);
}

frmCentral::~frmCentral()
{
    delete ui;
}

void frmCentral::saveSettings()
{
    QSettings set(qApp->applicationDirPath() + "/settings.ini", QSettings::IniFormat);

    set.setValue("frmCentral/State", this->saveState());
}

void frmCentral::loadSettings()
{
    QSettings set(qApp->applicationDirPath() + "/settings.ini", QSettings::IniFormat);

    this->restoreState(set.value("frmCentral/State").toByteArray());
}
