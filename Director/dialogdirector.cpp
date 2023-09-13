#include "dialogdirector.h"

DialogDirector::DialogDirector(DialogBuilder *dialogBuilder)
{
    dialogBuilder__ = dialogBuilder;
}
DialogDirector::~DialogDirector()
{
    delete dialogBuilder__;
    dialogBuilder__ = nullptr;
}

void DialogDirector::setDialogBuilder(DialogBuilder *dialogBuilder)
{
    dialogBuilder__ = dialogBuilder;
}

auto DialogDirector::getDialog() -> CDialog *
{
    dialogBuilder__->buildTabs();
    dialogBuilder__->buildContent();
    dialogBuilder__->buildConnect();

    return dialogBuilder__->getDialog();
}
