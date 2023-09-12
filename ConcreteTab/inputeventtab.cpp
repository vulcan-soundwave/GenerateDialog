#include "inputeventtab.h"
#include "ui_inputeventtab.h"

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

auto InputEventTab::clone() -> CTab *
{
    return new InputEventTab( *this );
}

void InputEventTab::buildUi()
{
    ui->setupUi(this);
}
