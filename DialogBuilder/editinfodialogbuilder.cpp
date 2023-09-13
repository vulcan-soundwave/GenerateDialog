#include <QHBoxLayout>
#include <QDebug>

#include "editinfodialogbuilder.h"
#include "Factory/tabfactory.hpp"
#include "ConcreteTab/editinfotab.h"
#include "ui_editinfotab.h"

EditInfoDialogBuilder::~EditInfoDialogBuilder()
{

}

void EditInfoDialogBuilder::buildTabs()
{
    EditInfoTab::registerTab();
    CTab *prototypeEditInfoTab = TabFactory::getInstance()->generateInstance("EditInfoTab");

    tab__ = prototypeEditInfoTab->clone();

    dialog__->setMainWidget(tab__);
}

void EditInfoDialogBuilder::buildContent()
{
    auto tab = dynamic_cast<EditInfoTab *>(tab__)->ui;
    tab->lineEdit->setText("编码");
    tab->textEdit->setText("描述");
}

auto EditInfoDialogBuilder::getDialog() -> CDialog *
{
    return dialog__;
}

void EditInfoDialogBuilder::buildConnect()
{
    DialogBuilder::buildConnect();
}

void EditInfoDialogBuilder::sl_okButton_clicked()
{
    auto tab = dynamic_cast<EditInfoTab *>(tab__)->ui;
    tab->lineEdit->setText("编码");
    tab->textEdit->setText("描述");

    qDebug() << "新增/编辑信息：" << tab->lineEdit->text() << tab->textEdit->placeholderText();

    DialogBuilder::sl_okButton_clicked();
}

void EditInfoDialogBuilder::sl_cancelButton_clicked()
{
    DialogBuilder::sl_cancelButton_clicked();
}

