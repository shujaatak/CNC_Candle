#include "frmmain.h"
#include "ui_frmmain.h"

frmMain::frmMain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::frmMain)
{
    ui->setupUi(this);

    // TODO: Add maximum dock widgets width calculation
    ui->dockFile->setMaximumWidth(250);
    ui->dockMachine->setMaximumWidth(250);

    loadSettings();
}

frmMain::~frmMain()
{
    saveSettings();

    delete ui;
}

void frmMain::saveSettings()
{
    QSettings set(qApp->applicationDirPath() + "/settings.ini", QSettings::IniFormat);

    set.setValue("frmMain/Geometry", this->saveGeometry());
    set.setValue("frmMain/State", this->saveState());

    // Save central window settings
    ui->wdtCentral->saveSettings();
}

void frmMain::loadSettings()
{
    QSettings set(qApp->applicationDirPath() + "/settings.ini", QSettings::IniFormat);

    this->restoreGeometry(set.value("frmMain/Geometry").toByteArray());
    this->restoreState(set.value("frmMain/State").toByteArray());

    // Load central window settings
    ui->wdtCentral->loadSettings();
}
