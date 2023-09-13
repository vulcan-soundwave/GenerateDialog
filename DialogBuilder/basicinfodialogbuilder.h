#pragma once

#include "DialogBuilder/dialogbuilder.h"
#include "Share/ctab.h"

class BasicInfoDialogBuilder : public DialogBuilder
{
    Q_OBJECT

public:
    BasicInfoDialogBuilder() = default;
    virtual ~BasicInfoDialogBuilder() override;

    virtual void buildTabs() override;
    virtual void buildContent() override;
    virtual void buildConnect() override;
    virtual CDialog *getDialog() override;

public slots:
    virtual void sl_okButton_clicked() override;
    virtual void sl_cancelButton_clicked() override;

private:
    CTab *tab1__ = nullptr;
    CTab *tab2__ = nullptr;
};
