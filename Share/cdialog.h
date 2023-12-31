#pragma once

#include <QDialog>
#include <QTabWidget>
#include <QPushButton>

class CDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CDialog(QWidget *parent = nullptr);
    ~CDialog();

    void setMainWidget(QWidget *);

public:
    QPushButton *okButton;
    QPushButton *cancelButton;
};
