#pragma once

#include "DialogBuilder/dialogbuilder.h"
#include "Share/ctab.h"

class SettingsDialogBuilder : public DialogBuilder
{
    Q_OBJECT

public:
    SettingsDialogBuilder() = default;
    virtual ~SettingsDialogBuilder() override;

    virtual void buildTabs() override;
    virtual void buildContent() override;
    virtual void buildConnect() override;
    virtual CDialog *getDialog() override;

public slots:
    virtual void sl_okButton_clicked() override;
    virtual void sl_cancelButton_clicked() override;

private:
    QTabWidget *tabWidget__;

    CTab *tab1__ = nullptr;
    CTab *tab2__ = nullptr;
};
