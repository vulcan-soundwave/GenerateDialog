#include "editinfotab.h"
#include "ui_editinfotab.h"

#include "Factory/tabfactory.hpp"

EditInfoTab::EditInfoTab(QWidget *parent) :
    CTab(parent),
    ui(new Ui::EditInfoTab)
{
    buildUi();
}

EditInfoTab::~EditInfoTab()
{
    delete ui;
}

EditInfoTab::EditInfoTab(EditInfoTab const& tab)
{
    ui = new Ui::EditInfoTab;

    buildUi();
}

void EditInfoTab::registerTab(QWidget *parent)
{
    TabFactory::getInstance()->registerTab("EditInfoTab", [=]() {
        return new EditInfoTab(parent);
    });
}

auto EditInfoTab::clone() -> CTab *
{
    return new EditInfoTab( *this );
}

void EditInfoTab::buildUi()
{
    // 加载ui文件
    ui->setupUi(this);
}

