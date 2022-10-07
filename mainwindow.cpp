#include "mainwindow.h"
#include "ui_dialog.h"
#include "ui_about_entity.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QFont>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    setFixedSize(1143,730);
    addItems_to_listWidget_main();
    addItems_to_listWidget_second();
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(100);
    ui->progressBar->hide();
    ui->listWidget_main->setEditTriggers( QAbstractItemView::SelectedClicked);
    ui->listWidget_main->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->listWidget_second->setEditTriggers( QAbstractItemView::SelectedClicked);
    ui->listWidget_second->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->listWidget_main, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showContextMenu_main(QPoint)));
    connect(ui->listWidget_second, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showContextMenu_second(QPoint)));
    connect(ui->listWidget_main, &QListWidget::itemClicked, this , &MainWindow::checkItemChanged);
    connect(ui->listWidget_second, &QListWidget::itemClicked, this , &MainWindow::checkItemChanged);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::checkItemChanged(QListWidgetItem *Item)
{
    item = Item;
}
void MainWindow::addItems_to_listWidget_main()
{
    addItems_to_listWidget(filemanager,ui->listWidget_main);
}

void MainWindow::addItems_to_listWidget_second()
{
    addItems_to_listWidget(filemanager_2,ui->listWidget_second);
}

void MainWindow::addItems_to_listWidget(FileManager & filemanager, QListWidget *listWidget)
{
    ui->progressBar->setValue(0);
    ui->progressBar->setMaximum(filemanager.directory.getEntities().size());
    ui->progressBar->show();
    if(filemanager.directory.getEntities().empty())
    {
        QListWidgetItem *item =  new QListWidgetItem();
        listWidget->addItem(item);
    }

    for (int i = 0; i < filemanager.directory.getEntities().size(); ++i)
    {
        ui->progressBar->setValue(i);

        if(fs::is_regular_file(filemanager.directory.getEntities()[i].path))
        {
            if(filemanager.directory.getEntities()[i].extension == ".odt")
            {
                QListWidgetItem *item =  new QListWidgetItem(QIcon(":rec/img/odt.png"),filemanager.directory.getEntities()[i].name.c_str());
                listWidget->addItem(item);
            }
            else if(filemanager.directory.getEntities()[i].extension == ".exe")
            {
                QListWidgetItem *item =  new QListWidgetItem(QIcon(":rec/img/exe.png"),filemanager.directory.getEntities()[i].name.c_str());
                listWidget->addItem(item);
            }
            else if(filemanager.directory.getEntities()[i].extension == ".mp4")
            {
                QListWidgetItem *item =  new QListWidgetItem(QIcon(":rec/img/mp4.png"),filemanager.directory.getEntities()[i].name.c_str());
                listWidget->addItem(item);
            }
            else if(filemanager.directory.getEntities()[i].extension == ".mp3")
            {
                QListWidgetItem *item =  new QListWidgetItem(QIcon(":rec/img/mp3.png"),filemanager.directory.getEntities()[i].name.c_str());
                listWidget->addItem(item);
            }
            else if(filemanager.directory.getEntities()[i].extension == ".cpp")
            {
                QListWidgetItem *item =  new QListWidgetItem(QIcon(":rec/img/cpp.png"),filemanager.directory.getEntities()[i].name.c_str());
                listWidget->addItem(item);
            }
            else if(filemanager.directory.getEntities()[i].extension == ".pdf")
            {
                QListWidgetItem *item =  new QListWidgetItem(QIcon(":rec/img/pdf.png"),filemanager.directory.getEntities()[i].name.c_str());
                listWidget->addItem(item);
            }
            else if(filemanager.directory.getEntities()[i].extension == ".png")
            {
                QListWidgetItem *item =  new QListWidgetItem(QIcon(":rec/img/png.png"),filemanager.directory.getEntities()[i].name.c_str());
                listWidget->addItem(item);
            }
            else if(filemanager.directory.getEntities()[i].extension == ".docx")
            {
                QListWidgetItem *item =  new QListWidgetItem(QIcon(":rec/img/docx.png"),filemanager.directory.getEntities()[i].name.c_str());
                listWidget->addItem(item);
            }
            else
            {
                QListWidgetItem *item =  new QListWidgetItem(QIcon(":rec/img/file.png"),filemanager.directory.getEntities()[i].name.c_str());
                listWidget->addItem(item);
            }
        }
        else
        {
            QListWidgetItem *item =  new QListWidgetItem(QIcon(":rec/img/folder.png"),filemanager.directory.getEntities()[i].name.c_str());
            listWidget->addItem(item);
        }

       listWidget->item(i)->setFlags(listWidget->item(i)->flags() | Qt::ItemIsEditable);
    }
    ui->progressBar->setValue(filemanager.directory.getEntities().size());
    ui->progressBar->hide();
    item = nullptr;
}


void MainWindow::addItems_to_listWidget_second(const std::vector<fs::path> paths)
{
    for (int i = 0; i < paths.size(); ++i)
    {

        if(fs::is_regular_file(paths[i]))
        {
            if(paths[i].extension() == ".odt")
            {
                QListWidgetItem *item =  new QListWidgetItem(QIcon(":rec/img/odt.png"),paths[i].filename().string().c_str());
                ui->listWidget_second->addItem(item);
            }
            else if(paths[i].extension() == ".exe")
            {
                QListWidgetItem *item =  new QListWidgetItem(QIcon(":rec/img/exe.png"),paths[i].filename().string().c_str());
                ui->listWidget_second->addItem(item);
            }
            else if(paths[i].extension() == ".mp4")
            {
                QListWidgetItem *item =  new QListWidgetItem(QIcon(":rec/img/mp4.png"),paths[i].filename().string().c_str());
                ui->listWidget_second->addItem(item);
            }
            else if(paths[i].extension() == ".mp3")
            {
                QListWidgetItem *item =  new QListWidgetItem(QIcon(":rec/img/mp3.png"),paths[i].filename().string().c_str());
                ui->listWidget_second->addItem(item);
            }
            else if(paths[i].extension() == ".cpp")
            {
                QListWidgetItem *item =  new QListWidgetItem(QIcon(":rec/img/cpp.png"),paths[i].filename().string().c_str());
                ui->listWidget_second->addItem(item);
            }
            else if(paths[i].extension() == ".pdf")
            {
                QListWidgetItem *item =  new QListWidgetItem(QIcon(":rec/img/pdf.png"),paths[i].filename().string().c_str());
                ui->listWidget_second->addItem(item);
            }
            else if(paths[i].extension() == ".png")
            {
                QListWidgetItem *item =  new QListWidgetItem(QIcon(":rec/img/png.png"),paths[i].filename().string().c_str());
                ui->listWidget_second->addItem(item);
            }
            else if(paths[i].extension() == ".docx")
            {
                QListWidgetItem *item =  new QListWidgetItem(QIcon(":rec/img/docx.png"),paths[i].filename().string().c_str());
                ui->listWidget_second->addItem(item);
            }
            else
            {
                QListWidgetItem *item =  new QListWidgetItem(QIcon(":rec/img/file.png"),paths[i].filename().string().c_str());
                ui->listWidget_second->addItem(item);
            }
        }
        else
        {
            QListWidgetItem *item =  new QListWidgetItem(QIcon(":rec/img/folder.png"),paths[i].filename().string().c_str());
            ui->listWidget_second->addItem(item);
        }
    }
}

void MainWindow::on_listWidget_main_itemDoubleClicked(QListWidgetItem *item)
{
    ui->comboBox->setCurrentIndex(0);
    listWidgetGoToOtherPath(filemanager,ui->listWidget_main,ui->lineEdit,item);

}

void MainWindow::on_listWidget_second_itemDoubleClicked(QListWidgetItem *item)
{
    ui->comboBox_2->setCurrentIndex(0);
    listWidgetGoToOtherPath(filemanager_2,ui->listWidget_second,ui->lineEdit_2,item);
}

void MainWindow::listWidgetGoToOtherPath(FileManager & filemanager, QListWidget *listWidget, QLineEdit *lineEdit, QListWidgetItem *item)
{
    if(!filemanager.directory.getSearch_directories().empty())
    {
        filemanager.path = filemanager.directory.getSearch_directories()[0].parent_path();
        filemanager.go_the_other_path(filemanager.directory.getSearch_directories()[0].filename().string());
        filemanager.directory.getSearch_directories().clear();
    }
    else
    {
        filemanager.go_the_other_path(item->text().toStdString());
    }

    listWidget->clear();
    lineEdit->clear();
    lineEdit->setText(QString(filemanager.path.string().c_str()));

    (listWidget->objectName() == "listWidget_main") ? addItems_to_listWidget_main() : addItems_to_listWidget_second();
}

void MainWindow::on_pushButton_back_pressed()
{
   goBack(filemanager,ui->lineEdit,ui->listWidget_main);
}

void MainWindow::on_pushButton_back_2_pressed()
{
    goBack(filemanager_2,ui->lineEdit_2,ui->listWidget_second);
}

void MainWindow::goBack(FileManager & filemanager,QLineEdit* lineEdit, QListWidget *listWidget)
{
    if(!filemanager.getPaths_for_button_back().empty())
    {
        filemanager.path = filemanager.getPaths_for_button_back().top();
        filemanager.go_the_other_path();
        filemanager.getPaths_for_button_back().pop();
        lineEdit->clear();
        lineEdit->setText(QString(filemanager.path.string().c_str()));
        listWidget->clear();
        (listWidget->objectName() == "listWidget_main") ? addItems_to_listWidget_main() : addItems_to_listWidget_second();
     }
}

void MainWindow::on_lineEdit_editingFinished()
{

    item=nullptr;
    lineEdit_editingFinished(filemanager,ui->lineEdit,ui->listWidget_main);

}

void MainWindow::on_lineEdit_2_editingFinished()
{
    item=nullptr;
   lineEdit_editingFinished(filemanager_2,ui->lineEdit_2,ui->listWidget_second);

}

void MainWindow::lineEdit_editingFinished(FileManager & filemanager,QLineEdit* lineEdit, QListWidget *listWidget)
{
    if(lineEdit->text().toStdString()[0] == '/')
    {
        filemanager.path = lineEdit->text().toStdString();
        filemanager.go_the_other_path();
        listWidget->clear();
        (listWidget->objectName() == "listWidget_main") ? addItems_to_listWidget_main() : addItems_to_listWidget_second();
    }
}

void MainWindow::on_actionCreate_2_triggered()
{
    create_folder();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(item != nullptr)
    {
         QListWidget *listWidget = nullptr;
         FileManager *filemanager_temp = nullptr;


        if(item->listWidget()->objectName() == "listWidget_main")
        {
            filemanager_temp = &filemanager;
            listWidget = ui->listWidget_main;
        }
        else
        {
            filemanager_temp = &filemanager_2;
            listWidget = ui->listWidget_second;
        }
       if(event->key() == Qt::Key_Delete)
       {
            QMessageBox::StandardButton reply = QMessageBox::question(this,"","Do you want to delete?",QMessageBox::Yes | QMessageBox::No);
            if(reply == QMessageBox::Yes)
            {
                (filemanager_temp->directory.deleteFile(filemanager_temp->path,listWidget->currentItem()->text().toStdString())) ? QMessageBox::information(this,"","File was deleted") :QMessageBox::critical(this,"Error","Deletion error!!! Try again.");
                listWidget->clear();
                (listWidget->objectName() == "listWidget_main") ? addItems_to_listWidget_main() : addItems_to_listWidget_second();
            }
            else
            {
                return;
            }
        }
        if(event->type() == QKeyEvent::KeyPress)
        {
            if(event->matches(QKeySequence::Copy))
            {
                copy();
            }
            else if (event->matches(QKeySequence::Paste))
            {
                listWidget->clear();
                filemanager_temp->directory.paste_file_or_folder(filemanager_temp->path);
                (listWidget->objectName() == "listWidget_main") ? addItems_to_listWidget_main() : addItems_to_listWidget_second();
            }
            else if (event->matches(QKeySequence::Save))
            {
                filemanager_temp->directory.rename_file_or_folder(filemanager_temp->path,filemanager_temp->directory.getEntities()[listWidget->currentRow()].name.c_str(), listWidget->currentItem()->text().toStdString());
                listWidget->clear();
                (listWidget->objectName() == "listWidget_main") ? addItems_to_listWidget_main() : addItems_to_listWidget_second();
            }
        }
    }
}

void MainWindow::copy()
{
    (item->listWidget()->objectName() == "listWidget_main") ? filemanager.directory.copy_file_or_folder(filemanager.path,ui->listWidget_main->currentItem()->text().toStdString()) : filemanager_2.directory.copy_file_or_folder(filemanager_2.path,ui->listWidget_second->currentItem()->text().toStdString());
}

void MainWindow::move()
{
    if(item!=nullptr)
    {
        copy();

        if(item->listWidget()->objectName() == "listWidget_main")
        {
            move_form.addFilemanager(filemanager);
            move_form.addItem();
            move_form.show();
            ui->listWidget_main->clear();
            addItems_to_listWidget_main();

        }
        else
        {
            move_form.addFilemanager(filemanager_2);
            move_form.addItem();
            move_form.show();
            ui->listWidget_second->clear();
            addItems_to_listWidget_second();
        }
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::RightButton )
    {
        info_about_entities();
    }
}

void MainWindow::Sort_by()
{
    if(ui->comboBox->currentText() == "none")
    {
        return;
    }
    else if(ui->comboBox->currentText() == "name")
    {
        ui->listWidget_second->clear();
        filemanager.directory.Sort("by name");
    }
    else if(ui->comboBox->currentText() == "size")
    {
        ui->listWidget_second->clear();
        filemanager.directory.Sort("by size");
    }
}

void MainWindow::comboBox_currentIndexChanged(FileManager & filemanager, QComboBox *comboBox, QListWidget *listWidget)
{
    if(comboBox->currentText() != "none")
    {
        if(comboBox->currentText() == "name")
        {
            listWidget->clear();
            filemanager.directory.Sort("by name");
            (listWidget->objectName() == "listWidget_main") ? addItems_to_listWidget_main() : addItems_to_listWidget_second();
        }
        else
        {
            ui->listWidget_second->clear();
            filemanager.directory.Sort("by size");
            (listWidget->objectName() == "listWidget_main") ? addItems_to_listWidget_main() : addItems_to_listWidget_second();;
        }
    }
}

void MainWindow::on_comboBox_currentIndexChanged()
{
    comboBox_currentIndexChanged(filemanager,ui->comboBox,ui->listWidget_main);
}

void MainWindow::on_comboBox_2_currentIndexChanged()
{
    comboBox_currentIndexChanged(filemanager_2,ui->comboBox_2,ui->listWidget_second);
}

void MainWindow::create_folder()
{
    if(item != nullptr)
    {
        QListWidget *listWidget;
        FileManager *filemanager_copy;
        if(item->listWidget()->objectName() == "listWidget_main")
        {
            filemanager_copy = &filemanager;
            listWidget = ui->listWidget_main;
        }
        else
        {
            filemanager_copy = &filemanager_2;
            listWidget = ui->listWidget_second;
        }
        second.ui->lineEdit->text().clear();
        second.setModal(true);
        second.ui->label->setText(QString("Enter name of folder"));
        second.exec();
        string name = second.ui->lineEdit->text().toStdString();

        if(!name.empty())
        {
            if(!filemanager_copy->directory.addFolder(filemanager_copy->path, name))
            {
                QMessageBox::critical(this,"Error", "Error adding folder");
            }

            listWidget->clear();
            (listWidget->objectName() == "listWidget_main") ? addItems_to_listWidget_main() : addItems_to_listWidget_second();
        }
        item = nullptr;
    }
}

void MainWindow::create_file()
{
    if(item != nullptr)
    {
        QListWidget *listWidget;
        FileManager *filemanager_copy;
        if(item->listWidget()->objectName() == "listWidget_main")
        {
            filemanager_copy = &filemanager;
            listWidget = ui->listWidget_main;
        }
        else
        {
            filemanager_copy = &filemanager_2;
            listWidget = ui->listWidget_second;
        }
        second.setModal(true);
        second.ui->label->setText(QString("Enter name of file"));
        second.exec();
        string name = second.ui->lineEdit->text().toStdString();

        if(!name.empty())
        {
            if(!filemanager_copy->directory.addFile(filemanager_copy->path, name))
            {
                QMessageBox::critical(this,"Error", "Error adding file");
            }

            listWidget->clear();
            (listWidget->objectName() == "listWidget_main") ? addItems_to_listWidget_main() : addItems_to_listWidget_second();
        }
        item = nullptr;
    }
}

void MainWindow::info_about_entities()
{
    FileManager *filemanager_info;
    if(item->listWidget()->objectName() == "listWidget_main")
    {
        filemanager_info = &filemanager;
    }
    else
    {
        filemanager_info = &filemanager_2;
    }

    about.reset_all();
    std::filesystem::path path;
    bool isAddPath = false;
    while (!isAddPath)
    {
        try
        {
            path = filemanager_info->path;

            path /= ui->listWidget_second->currentItem()->text().toStdString();

            if (fs::is_regular_file(path))
            {
                about.ui->label->setText(QString("name: "));
                about.ui->label_2->setText(QString("path: "));
                about.ui->label_3->setText(QString("size: "));
                about.ui->label_4->setText(QString("extension: "));

                about.ui->about_right_1->setText(QString(path.filename().string().c_str()));
                about.ui->about_right_2->setText(QString(filemanager.path.string().c_str()));
                about.ui->about_right_3->setText(QString::number(filemanager.directory.size_of_folder(path)));
                about.ui->about_right_4->setText(QString(path.extension().string().c_str()));
            }
            else
            {
                about.ui->label->setText(QString("name: "));
                about.ui->label_2->setText(QString("path: "));
                about.ui->label_3->setText(QString("size: "));

                about.ui->about_right_1->setText(QString(path.filename().string().c_str()));
                about.ui->about_right_2->setText(QString(filemanager.path.string().c_str()));
                about.ui->about_right_3->setText(QString::number(filemanager.directory.size_of_folder(path)));
            }

            about.show();
            isAddPath = true;
        }
        catch (const std::exception& ex)
        {
            return;
        }

    }
}

void MainWindow::makeMenu(const QPoint& pos)
{
    QMenu myMenu;

    myMenu.addAction("Create file", this, SLOT(create_file()));
    myMenu.addAction("Create folder", this, SLOT(create_folder()));
    myMenu.addAction("Move", this, SLOT(move()));
    myMenu.addAction("Properties", this, SLOT(info_about_entities()));
    myMenu.addAction("Disk", this, SLOT(info_about_space_on_computer()));

    myMenu.exec(pos);
}

void MainWindow::showContextMenu_main(const QPoint& pos)
{
    if(item != nullptr)
    {
        QPoint globalPos = ui->listWidget_main->mapToGlobal(pos);

        makeMenu(globalPos);
    }

}

void MainWindow::showContextMenu_second(const QPoint& pos)
{
    if(item != nullptr)
    {
        QPoint globalPos = ui->listWidget_second->mapToGlobal(pos);

        makeMenu(globalPos);
    }
}

void MainWindow::info_about_space_on_computer()
{

    about.reset_all();
    const auto& root = fs::path("/");
    const auto& space = fs::space(root);

    about.ui->label->setText(QString("Disk"));
    about.ui->label_2->setText(QString("Total:"));
    about.ui->label_3->setText(QString("Free:"));
    about.ui->label_4->setText(QString("Aviable:"));

    about.ui->about_right_2->setText(QString::number(space.capacity / 1024 / 1024 / 1024)+ QString(" GB"));
    about.ui->about_right_3->setText(QString::number(space.free / 1024 / 1024 / 1024)+ QString(" GB"));
    about.ui->about_right_4->setText(QString::number(space.available / 1024 / 1024 / 1024)+ QString(" GB"));

    about.show();

}


void MainWindow::on_actionfile_create_triggered()
{
    create_file();
}

void MainWindow::on_actionfolder_create_triggered()
{

    create_folder();
}

void MainWindow::on_actionSearch_triggered()
{

    ui->listWidget_second->clear();
    filemanager_2.directory.find_file(ui->lineEdit_2->text().toStdString());
    addItems_to_listWidget_second(filemanager_2.directory.getSearch_directories());
    ui->lineEdit_2->text().clear();

}

