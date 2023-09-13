#pragma once

#include "Share/cdialog.h"

class DialogBuilder : public QWidget
{
    Q_OBJECT

public:
    DialogBuilder();
    virtual ~DialogBuilder();

    virtual void buildTabs() = 0;
    virtual void buildContent() = 0;
    virtual void buildConnect();
    virtual CDialog *getDialog() = 0;

public slots:
    virtual void sl_okButton_clicked();
    virtual void sl_cancelButton_clicked();

public:
    CDialog *dialog__;
};
