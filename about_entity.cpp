#include "about_entity.h"
#include "ui_about_entity.h"

About_entity::About_entity(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::About_entity)
{

    ui->setupUi(this);
}


About_entity::~About_entity()
{

    delete ui;
}


void About_entity::reset_all()
{

    ui->about_right_1->clear();
    ui->about_right_2->clear();
    ui->about_right_3->clear();
    ui->about_right_4->clear();
    ui->label->clear();
    ui->label_2->clear();
    ui->label_3->clear();
    ui->label_4->clear();
}

