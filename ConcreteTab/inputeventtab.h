#pragma once

#include "Share/ctab.h"

namespace Ui {
class InputEventTab;
}

class InputEventTab : public CTab
{
public:
    explicit InputEventTab(QWidget *parent = nullptr);
    virtual ~InputEventTab() override;

    InputEventTab(InputEventTab const &tab);
    static void registerTab(QWidget *parent = nullptr);

    virtual CTab *clone() override;
    virtual void buildUi() override;

public:
    Ui::InputEventTab *ui;
};
