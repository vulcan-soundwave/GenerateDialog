#include "cdialog.h"
#include "ui_inputeventtab.h"
#include "ui_basicinfotab.h"

#include <QHBoxLayout>
#include <QTabWidget>

CDialog::CDialog(QWidget *parent) :
    QDialog(parent)
{
    this->resize(800, 600);

    QTabWidget *tabWidget = new QTabWidget();
    QHBoxLayout *horizontalLayout = new QHBoxLayout(this);
    horizontalLayout->addWidget(tabWidget);
    horizontalLayout->setMargin(0);

    Ui::BasicInfoTab *tab_1 = new Ui::BasicInfoTab();
    Ui::InputEventTab *tab_2 = new Ui::InputEventTab();

    QWidget *widget_1 = new QWidget();
    QWidget *widget_2 = new QWidget();

    tab_1->setupUi(widget_1);
    tab_2->setupUi(widget_2);

    tabWidget->addTab(widget_1, "基础信息");
    tabWidget->addTab(widget_2, "关联关系");
}

CDialog::~CDialog()
{

}
