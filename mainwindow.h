#pragma once

#include <QMainWindow>
#include <QListWidgetItem>
#include <QKeyEvent>
#include "filemanager.h"
#include <dialog.h>
#include <about_entity.h>
#include <form_for_move.h>
#include <QMouseEvent>
#include <QAbstractItemView>
#include <QComboBox>

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

    void addItems_to_listWidget_second(const std::vector<fs::path> paths);

    void keyPressEvent(QKeyEvent *event);

    void mousePressEvent(QMouseEvent *event);

    void Sort_by();

    void copy();

    void goBack(FileManager & filemanager,QLineEdit* lineEdit, QListWidget *listWidget);

    void addItems_to_listWidget(FileManager & filemanager, QListWidget *listWidget);

    void listWidgetGoToOtherPath(FileManager & filemanager, QListWidget *listWidget, QLineEdit *lineEdit, QListWidgetItem *item);

    void lineEdit_editingFinished(FileManager & filemanager,QLineEdit* lineEdit, QListWidget *listWidget);

    void getListWidget(QListWidget *listWidget);

    void comboBox_currentIndexChanged(FileManager & filemanager, QComboBox *comboBox, QListWidget *listWidget);

    ~MainWindow();

private slots:

    void makeMenu(const QPoint& pos);

    void showContextMenu_main(const QPoint& pos);

    void showContextMenu_second(const QPoint& pos);

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

    void on_actionSearch_triggered();

    void on_pushButton_back_2_pressed();

    void on_lineEdit_2_editingFinished();

    void checkItemChanged(QListWidgetItem *Item);

    void on_comboBox_2_currentIndexChanged();

private:
    Ui::MainWindow *ui;

    Dialog second;

    About_entity about;

    FileManager filemanager;

    FileManager filemanager_2;

    Form_for_move move_form;

    QListWidgetItem *item = nullptr;

};

