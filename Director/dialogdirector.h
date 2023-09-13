#pragma once
#include "DialogBuilder/dialogbuilder.h"

class DialogDirector
{
public:
    DialogDirector(DialogBuilder *);
    ~DialogDirector();
    void setDialogBuilder(DialogBuilder *);
    auto getDialog() -> CDialog *;

private:
    DialogBuilder *dialogBuilder__ = nullptr;
};
