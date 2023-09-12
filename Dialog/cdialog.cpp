#include "cdialog.h"
#include "ui_inputeventtab.h"
#include "ui_basicinfotab.h"

#include <QHBoxLayout>
#include <QTabWidget>

#include "Factory/tabfactory.hpp"

CDialog::CDialog(QWidget *parent) :
    QDialog(parent)
{
    this->resize(800, 600);

    QTabWidget *tabWidget = new QTabWidget();
    QHBoxLayout *horizontalLayout = new QHBoxLayout(this);
    horizontalLayout->addWidget(tabWidget);
    horizontalLayout->setMargin(0);

    BasicInfoTab::registerTab();
    InputEventTab::registerTab();
    prototypeBasicInfoTab__ = TabFactory::getInstance()->generateInstance("BasicInfoTab");
    prototypeInputEventTab__ = TabFactory::getInstance()->generateInstance("InputEventTab");

    CTab *tab_1 = prototypeBasicInfoTab__->clone();
    CTab *tab_2 = prototypeBasicInfoTab__->clone();
    CTab *tab_3 = prototypeInputEventTab__->clone();
    CTab *tab_4 = prototypeInputEventTab__->clone();

    tabWidget->addTab(tab_1, "基础信息-1");
    tabWidget->addTab(tab_3, "关联关系-1");
    tabWidget->addTab(tab_2, "基础信息-2");
    tabWidget->addTab(tab_4, "关联关系-2");
}

CDialog::~CDialog()
{

}
