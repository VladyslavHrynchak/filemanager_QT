#include "form_for_move.h"
#include "ui_form_for_move.h"
#include <QMenu>
#include <QString>

Form_for_move::Form_for_move(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_for_move)
{

    ui->setupUi(this);
    setFixedSize(450,680);
    ui->listWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->listWidget, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showContextMenu(QPoint)));

}

Form_for_move::~Form_for_move()
{
    delete ui;
}

void Form_for_move::addFilemanager(const  FileManager &filemanager_)
{

    this->filemanager = filemanager_;
    buff = filemanager.path.string().c_str();
    #ifdef linux
    filemanager.go_the_other_path("/home");
    #elif _WIN32
    filemanager.go_the_other_path("C:");
    #endif
    ui->lineEdit->setText(QString(filemanager.path.string().c_str()));

}

void Form_for_move::addItem()
{

    ui->listWidget->clear();

    for (int i = 0; i < filemanager.directory.entities.size(); ++i)
    {
        if(fs::is_regular_file(filemanager.directory.entities[i].path))
        {
            if(filemanager.directory.entities[i].extension == ".odt")
            {
                QListWidgetItem *item =  new QListWidgetItem(QIcon(":rec/img/odt.png"),filemanager.directory.entities[i].name.c_str());
                ui->listWidget->addItem(item);
            }
            else if(filemanager.directory.entities[i].extension == ".exe")
            {
                QListWidgetItem *item =  new QListWidgetItem(QIcon(":rec/img/exe.png"),filemanager.directory.entities[i].name.c_str());
                ui->listWidget->addItem(item);
            }
            else if(filemanager.directory.entities[i].extension == ".mp4")
            {
                QListWidgetItem *item =  new QListWidgetItem(QIcon(":rec/img/mp4.png"),filemanager.directory.entities[i].name.c_str());
                ui->listWidget->addItem(item);
            }
            else if(filemanager.directory.entities[i].extension == ".mp3")
            {
                QListWidgetItem *item =  new QListWidgetItem(QIcon(":rec/img/mp3.png"),filemanager.directory.entities[i].name.c_str());
                ui->listWidget->addItem(item);
            }
            else if(filemanager.directory.entities[i].extension == ".cpp")
            {
                QListWidgetItem *item =  new QListWidgetItem(QIcon(":rec/img/cpp.png"),filemanager.directory.entities[i].name.c_str());
                ui->listWidget->addItem(item);
            }
            else if(filemanager.directory.entities[i].extension == ".pdf")
            {
                QListWidgetItem *item =  new QListWidgetItem(QIcon(":rec/img/pdf.png"),filemanager.directory.entities[i].name.c_str());
                ui->listWidget->addItem(item);
            }
            else if(filemanager.directory.entities[i].extension == ".png")
            {
                QListWidgetItem *item =  new QListWidgetItem(QIcon(":rec/img/png.png"),filemanager.directory.entities[i].name.c_str());
                ui->listWidget->addItem(item);
            }
            else if(filemanager.directory.entities[i].extension == ".docx")
            {
                QListWidgetItem *item =  new QListWidgetItem(QIcon(":rec/img/docx.png"),filemanager.directory.entities[i].name.c_str());
                ui->listWidget->addItem(item);
            }
            else
            {
                QListWidgetItem *item =  new QListWidgetItem(QIcon(":rec/img/file.png"),filemanager.directory.entities[i].name.c_str());
                ui->listWidget->addItem(item);
            }
        }
        else
        {
            QListWidgetItem *item =  new QListWidgetItem(QIcon(":rec/img/folder.png"),filemanager.directory.entities[i].name.c_str());
            ui->listWidget->addItem(item);
        }
    }

}

void Form_for_move::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{

    filemanager.go_the_other_path(item->text().toStdString());
    ui->listWidget->clear();
    ui->lineEdit->text().clear();
    ui->lineEdit->clear();
    ui->lineEdit->setText(QString(filemanager.path.string().c_str()));
    addItem();

}

void Form_for_move::on_pushButton_back_clicked()
{

    if(filemanager.paths.size() != 1)
    {
        filemanager.path = filemanager.paths.top();
        filemanager.go_the_other_path();
        filemanager.paths.pop();
        ui->lineEdit->clear();
        ui->lineEdit->setText(QString(filemanager.path.string().c_str()));
        ui->listWidget->clear();
        addItem();
    }

}

void Form_for_move::move()
{

    filemanager.directory.paste_file_or_folder(ui->lineEdit->text().toStdString().c_str());
    ui->listWidget->clear();
    addItem();
    filemanager.go_the_other_path(buff);
    filemanager.directory.deleteFile(buff,filemanager.directory.buff_str);
}


void Form_for_move::showContextMenu(const QPoint& pos)
{

    QPoint globalPos = ui->listWidget->mapToGlobal(pos);
    QMenu myMenu;
    myMenu.addAction("Paste", this, SLOT(move()));
    myMenu.exec(globalPos);
}

