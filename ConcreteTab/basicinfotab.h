#pragma once

#include "Share/ctab.h"

namespace Ui {
class BasicInfoTab;
}

class BasicInfoTab : public CTab
{
public:
    explicit BasicInfoTab(QWidget *parent = nullptr);
    virtual ~BasicInfoTab() override;

    BasicInfoTab(BasicInfoTab const &tab);

    virtual CTab * clone() override;
    virtual void buildUi() override;

private:
    Ui::BasicInfoTab *ui;
};
