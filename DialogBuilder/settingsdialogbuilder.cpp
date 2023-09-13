#include <QHBoxLayout>
#include <QDebug>

#include "settingsdialogbuilder.h"
#include "Factory/tabfactory.hpp"
#include "ConcreteTab/basicinfotab.h"
#include "ConcreteTab/inputeventtab.h"
#include "ui_inputeventtab.h"

SettingsDialogBuilder::~SettingsDialogBuilder()
{

}

void SettingsDialogBuilder::buildTabs()
{
    tabWidget__ = new QTabWidget();

    InputEventTab::registerTab();
    CTab *prototypeInputEventTab = TabFactory::getInstance()->generateInstance("InputEventTab");

    tab1__ = prototypeInputEventTab->clone();
    tab2__ = prototypeInputEventTab->clone();

    tabWidget__->addTab(tab1__, "关联关系-1");
    tabWidget__->addTab(tab2__, "关联关系-2");

    dialog__->setTabWidget(tabWidget__);
}

void SettingsDialogBuilder::buildContent()
{
    auto table1 = dynamic_cast<InputEventTab *>(tab1__)->ui->selectedTable;
    table1->insertRow(0);
    table1->setColumnCount(2);
    table1->setHorizontalHeaderLabels({"序号", "编码"});
    table1->setItem(0, 0, new QTableWidgetItem("111"));
    table1->setItem(0, 1, new QTableWidgetItem("code_1"));

    auto table2 = dynamic_cast<InputEventTab *>(tab2__)->ui->selectedTable;
    table2->insertRow(0);
    table2->setColumnCount(2);
    table2->setHorizontalHeaderLabels({"序号", "编码"});
    table2->setItem(0, 0, new QTableWidgetItem("222"));
    table2->setItem(0, 1, new QTableWidgetItem("code_2"));
}

auto SettingsDialogBuilder::getDialog() -> CDialog *
{
    return dialog__;
}

void SettingsDialogBuilder::buildConnect()
{
    DialogBuilder::buildConnect();
}

void SettingsDialogBuilder::sl_okButton_clicked()
{
    auto table1 = dynamic_cast<InputEventTab *>(tab1__)->ui->selectedTable;
    auto table2 = dynamic_cast<InputEventTab *>(tab2__)->ui->selectedTable;

    for (int row = 0; row < table1->rowCount(); ++row) {
        qDebug() << "关联关系1：" << table1->item(row, 0)->text() << table1->item(row, 1)->text();
    }
    for (int row = 0; row < table2->rowCount(); ++row) {
        qDebug() << "关联关系2：" << table2->item(row, 0)->text() << table2->item(row, 1)->text();
    }

    DialogBuilder::sl_okButton_clicked();
}

void SettingsDialogBuilder::sl_cancelButton_clicked()
{
    DialogBuilder::sl_cancelButton_clicked();
}
