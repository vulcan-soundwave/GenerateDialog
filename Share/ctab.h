#pragma once

#include <QWidget>

class CTab : public QWidget
{
public:
    explicit CTab(QWidget *parent = nullptr);
    virtual ~CTab();

    virtual CTab * clone() = 0;
    virtual void buildUi() = 0;
};
