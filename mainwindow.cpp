#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "DialogBuilder/settingsdialogbuilder.h"
#include "DialogBuilder/basicinfodialogbuilder.h"
#include "DialogBuilder/editinfodialogbuilder.h"
#include "Director/dialogdirector.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // settings dialog
    DialogDirector *director = new DialogDirector(new SettingsDialogBuilder());

    CDialog *dialog = director->getDialog();
    dialog->setWindowTitle("关联关系");
    dialog->resize(800, 600);
    dialog->exec();

    // basic info dialog
    director->setDialogBuilder(new BasicInfoDialogBuilder());

    dialog = director->getDialog();
    dialog->setWindowTitle("基础信息");
    dialog->resize(800, 600);
    dialog->exec();

    // edit info dialog
    director->setDialogBuilder(new EditInfoDialogBuilder());

    dialog = director->getDialog();
    dialog->setWindowTitle("新增/编辑信息");
    dialog->resize(400, 300);
    dialog->exec();
}

MainWindow::~MainWindow()
{
    delete ui;
}
