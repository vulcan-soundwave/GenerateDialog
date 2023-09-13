#include <QHBoxLayout>

#include "cdialog.h"

CDialog::CDialog(QWidget *parent) :
    QDialog(parent)
{

}

CDialog::~CDialog()
{

}

void CDialog::setMainWidget(QWidget *widget)
{
    okButton = new QPushButton("确定", this);
    cancelButton = new QPushButton("取消", this);
    QHBoxLayout *horizontalLayout_bottom = new QHBoxLayout();
    QHBoxLayout *horizontalLayout_button = new QHBoxLayout();
    QSpacerItem *horizontalSpacer_button = new QSpacerItem(768, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    QVBoxLayout *verticalLayout_overall = new QVBoxLayout(this);

    horizontalLayout_button->addWidget(okButton);
    horizontalLayout_button->addWidget(cancelButton);

    horizontalLayout_bottom->addItem(horizontalSpacer_button);
    horizontalLayout_bottom->addLayout(horizontalLayout_button);
    horizontalLayout_bottom->setContentsMargins(-1, -1, 9, 9);

    verticalLayout_overall->addWidget(widget);
    verticalLayout_overall->addLayout(horizontalLayout_bottom);
    verticalLayout_overall->setMargin(0);
}
