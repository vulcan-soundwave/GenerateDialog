#include <QHBoxLayout>
#include <QDebug>

#include "basicinfodialogbuilder.h"
#include "Factory/tabfactory.hpp"
#include "ConcreteTab/basicinfotab.h"
#include "ConcreteTab/inputeventtab.h"
#include "ui_basicinfotab.h"

BasicInfoDialogBuilder::~BasicInfoDialogBuilder()
{

}

void BasicInfoDialogBuilder::buildTabs()
{
    tabWidget__ = new QTabWidget();

    BasicInfoTab::registerTab();
    CTab *prototypeBasicInfoTab = TabFactory::getInstance()->generateInstance("BasicInfoTab");

    tab1__ = prototypeBasicInfoTab->clone();
    tab2__ = prototypeBasicInfoTab->clone();

    tabWidget__->addTab(tab1__, "基础信息-1");
    tabWidget__->addTab(tab2__, "基础信息-2");

    dialog__->setTabWidget(tabWidget__);
}

void BasicInfoDialogBuilder::buildContent()
{
    auto tab1 = dynamic_cast<BasicInfoTab *>(tab1__)->ui;
    tab1->label->setText("基础信息-1");

    auto tab2 = dynamic_cast<BasicInfoTab *>(tab2__)->ui;
    tab2->label->setText("基础信息-2");
}

auto BasicInfoDialogBuilder::getDialog() -> CDialog *
{
    return dialog__;
}

void BasicInfoDialogBuilder::buildConnect()
{
    DialogBuilder::buildConnect();
}

void BasicInfoDialogBuilder::sl_okButton_clicked()
{
    auto tab1 = dynamic_cast<BasicInfoTab *>(tab1__)->ui;
    auto tab2 = dynamic_cast<BasicInfoTab *>(tab2__)->ui;

    qDebug() << "基础信息1：" << tab1->label->text();
    qDebug() << "基础信息2：" << tab2->label->text();

    DialogBuilder::sl_okButton_clicked();
}

void BasicInfoDialogBuilder::sl_cancelButton_clicked()
{
    DialogBuilder::sl_cancelButton_clicked();
}

