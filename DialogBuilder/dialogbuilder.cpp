#include "dialogbuilder.h"

DialogBuilder::DialogBuilder() :
    dialog__(new CDialog)
{

}

DialogBuilder::~DialogBuilder()
{
    delete dialog__;
    dialog__ = nullptr;
}

void DialogBuilder::buildConnect()
{
    connect(dialog__->okButton, &QPushButton::clicked, this, &DialogBuilder::sl_okButton_clicked);
    connect(dialog__->cancelButton, &QPushButton::clicked, this, &DialogBuilder::sl_cancelButton_clicked);
}

void DialogBuilder::sl_okButton_clicked()
{
    dialog__->close();
}

void DialogBuilder::sl_cancelButton_clicked()
{
    dialog__->close();
}
