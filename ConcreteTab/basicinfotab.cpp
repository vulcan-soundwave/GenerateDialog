#include "basicinfotab.h"
#include "ui_basicinfotab.h"

BasicInfoTab::BasicInfoTab(QWidget *parent) :
    CTab(parent),
    ui(new Ui::BasicInfoTab)
{
    buildUi();
}

BasicInfoTab::~BasicInfoTab()
{
    delete ui;
}

BasicInfoTab::BasicInfoTab(BasicInfoTab const& tab)
{
    ui = tab.ui;

    buildUi();
}

auto BasicInfoTab::clone() -> CTab *
{
    return new BasicInfoTab( *this );
}

void BasicInfoTab::buildUi()
{
    // 加载ui文件
    ui->setupUi(this);
}
