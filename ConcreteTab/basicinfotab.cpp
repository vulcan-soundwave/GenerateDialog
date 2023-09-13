#include "basicinfotab.h"
#include "ui_basicinfotab.h"

#include "Factory/tabfactory.hpp"

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
    ui = new Ui::BasicInfoTab;

    buildUi();
}

void BasicInfoTab::registerTab(QWidget *parent)
{
    TabFactory::getInstance()->registerTab("BasicInfoTab", [=]() {
        return new BasicInfoTab(parent);
    });
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
