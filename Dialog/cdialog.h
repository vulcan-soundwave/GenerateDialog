#ifndef CDIALOG_H
#define CDIALOG_H

#include <QDialog>

class CDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CDialog(QWidget *parent = nullptr);
    ~CDialog();
};

#endif // CDIALOG_H
