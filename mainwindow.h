#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QKeyEvent>
#include "filemanager.h"
#include <dialog.h>
#include <about_entity.h>
#include <form_for_move.h>
#include <QMouseEvent>
#include <QAbstractItemView>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);

    void addItems_to_listWidget_main();

    void addItems_to_listWidget_second();

    void keyPressEvent(QKeyEvent *event);

    void mousePressEvent(QMouseEvent *event);

    void Sort_by();

    void copy();

    ~MainWindow();

private slots:

    void showContextMenu(const QPoint& pos);

    void on_listWidget_main_itemDoubleClicked(QListWidgetItem *item);

    void on_listWidget_second_itemDoubleClicked(QListWidgetItem *item);

    void on_pushButton_back_pressed();

    void on_lineEdit_editingFinished();

    void on_actionCreate_2_triggered();

    void on_comboBox_currentIndexChanged();

    void create_folder();

    void create_file();

    void info_about_entities();

    void info_about_space_on_computer();

    void on_actionfile_create_triggered();

    void on_actionfolder_create_triggered();


    void move();

private:
    Ui::MainWindow *ui;

    Dialog second;

    About_entity about;

    FileManager filemanager;

    Form_for_move move_form;
};
#endif
