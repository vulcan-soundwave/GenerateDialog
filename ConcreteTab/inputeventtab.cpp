#include "inputeventtab.h"
#include "ui_inputeventtab.h"

#include "Factory/tabfactory.hpp"

InputEventTab::InputEventTab(QWidget *parent) :
    CTab(parent),
    ui(new Ui::InputEventTab)
{
    buildUi();
}

InputEventTab::~InputEventTab()
{
    delete ui;
}

InputEventTab::InputEventTab(InputEventTab const &tab)
{
    ui = tab.ui;

    buildUi();
}

void InputEventTab::registerTab(QWidget *parent)
{
    TabFactory::getInstance()->registerTab("InputEventTab", [=]() {
        return new InputEventTab(parent);
    });
}

auto InputEventTab::clone() -> CTab *
{
    return new InputEventTab( *this );
}

void InputEventTab::buildUi()
{
    ui->setupUi(this);
}
