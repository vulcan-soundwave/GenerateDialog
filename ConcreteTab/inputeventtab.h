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

    virtual CTab *clone() override;
    virtual void buildUi() override;

private:
    Ui::InputEventTab *ui;
};
