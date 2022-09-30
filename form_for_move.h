#ifndef FORM_FOR_MOVE_H
#define FORM_FOR_MOVE_H
#include <QListWidget>
#include <QWidget>
#include <QKeyEvent>
#include "filemanager.h"

namespace Ui {
class Form_for_move;
}

class Form_for_move : public QWidget
{
    Q_OBJECT

public:
    explicit Form_for_move(QWidget *parent = nullptr);

    ~Form_for_move();

    void addItem();

    void addFilemanager(const  FileManager &filemanager_);

private slots:

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_pushButton_back_clicked();

    void showContextMenu(const QPoint& pos);

    void move();

private:
    std::string buff;

    Ui::Form_for_move *ui;

    FileManager filemanager;
};

#endif // FORM_FOR_MOVE_H
