#pragma once
#include <QWidget>

namespace Ui {
class About_entity;
}

class About_entity : public QWidget
{
    Q_OBJECT

public:
    explicit About_entity(QWidget *parent = nullptr);
    ~About_entity();

    void reset_all();
    Ui::About_entity *ui;
};


