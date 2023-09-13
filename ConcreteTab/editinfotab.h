#pragma once

#include "Share/ctab.h"

namespace Ui {
class EditInfoTab;
}

class EditInfoTab : public CTab
{
public:
    explicit EditInfoTab(QWidget *parent = nullptr);
    virtual ~EditInfoTab() override;

    EditInfoTab(EditInfoTab const &tab);
    static void registerTab(QWidget *parent = nullptr);

    virtual CTab * clone() override;
    virtual void buildUi() override;

public:
    Ui::EditInfoTab *ui;
};
