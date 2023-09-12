#ifndef CDIALOG_H
#define CDIALOG_H

#include <QDialog>

#include "ConcreteTab/basicinfotab.h"
#include "ConcreteTab/inputeventtab.h"

class CDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CDialog(QWidget *parent = nullptr);
    ~CDialog();

private:
    CTab *prototypeBasicInfoTab__ = nullptr;
    CTab *prototypeInputEventTab__ = nullptr;
};

#endif // CDIALOG_H
