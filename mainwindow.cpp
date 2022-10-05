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
    setFixedSize(1143,680);
    ui->splitter->setSizes(QList<int>() << 50 << 200);
    addItems_to_listWidget_main();
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(100);
    ui->progressBar->hide();
    ui->listWidget_second->setEditTriggers( QAbstractItemView::SelectedClicked);
    ui->listWidget_second->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->listWidget_second, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showContextMenu(QPoint)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addItems_to_listWidget_main()
{

    for (int i = 0; i < filemanager.directory.entities.size(); ++i)
    {
        if(fs::is_regular_file(filemanager.directory.entities[i].path))
        {
            QListWidgetItem *item =  new QListWidgetItem(QIcon(":rec/img/file.png"),filemanager.directory.entities[i].name.c_str());
            ui->listWidget_main->addItem(item);
        }
        else
        {
            QListWidgetItem *item =  new QListWidgetItem(QIcon(":rec/img/folder.png"),filemanager.directory.entities[i].name.c_str());
            ui->listWidget_main->addItem(item);
        }
    }

}

void MainWindow::addItems_to_listWidget_second()
{

    Sort_by();
    ui->progressBar->setValue(0);
    ui->progressBar->setMaximum(filemanager.directory.entities.size());
    ui->progressBar->show();

    for (int i = 0; i < filemanager.directory.entities.size(); ++i)
    {
        ui->progressBar->setValue(i);

        if(fs::is_regular_file(filemanager.directory.entities[i].path))
        {
            if(filemanager.directory.entities[i].extension == ".odt")
            {
                QListWidgetItem *item =  new QListWidgetItem(QIcon(":rec/img/odt.png"),filemanager.directory.entities[i].name.c_str());
                ui->listWidget_second->addItem(item);
            }
            else if(filemanager.directory.entities[i].extension == ".exe")
            {
                QListWidgetItem *item =  new QListWidgetItem(QIcon(":rec/img/exe.png"),filemanager.directory.entities[i].name.c_str());
                ui->listWidget_second->addItem(item);
            }
            else if(filemanager.directory.entities[i].extension == ".mp4")
            {
                QListWidgetItem *item =  new QListWidgetItem(QIcon(":rec/img/mp4.png"),filemanager.directory.entities[i].name.c_str());
                ui->listWidget_second->addItem(item);
            }
            else if(filemanager.directory.entities[i].extension == ".mp3")
            {
                QListWidgetItem *item =  new QListWidgetItem(QIcon(":rec/img/mp3.png"),filemanager.directory.entities[i].name.c_str());
                ui->listWidget_second->addItem(item);
            }
            else if(filemanager.directory.entities[i].extension == ".cpp")
            {
                QListWidgetItem *item =  new QListWidgetItem(QIcon(":rec/img/cpp.png"),filemanager.directory.entities[i].name.c_str());
                ui->listWidget_second->addItem(item);
            }
            else if(filemanager.directory.entities[i].extension == ".pdf")
            {
                QListWidgetItem *item =  new QListWidgetItem(QIcon(":rec/img/pdf.png"),filemanager.directory.entities[i].name.c_str());
                ui->listWidget_second->addItem(item);
            }
            else if(filemanager.directory.entities[i].extension == ".png")
            {
                QListWidgetItem *item =  new QListWidgetItem(QIcon(":rec/img/png.png"),filemanager.directory.entities[i].name.c_str());
                ui->listWidget_second->addItem(item);
            }
            else if(filemanager.directory.entities[i].extension == ".docx")
            {
                QListWidgetItem *item =  new QListWidgetItem(QIcon(":rec/img/docx.png"),filemanager.directory.entities[i].name.c_str());
                ui->listWidget_second->addItem(item);
            }
            else
            {
                QListWidgetItem *item =  new QListWidgetItem(QIcon(":rec/img/file.png"),filemanager.directory.entities[i].name.c_str());
                ui->listWidget_second->addItem(item);
            }
        }
        else
        {
            QListWidgetItem *item =  new QListWidgetItem(QIcon(":rec/img/folder.png"),filemanager.directory.entities[i].name.c_str());
            ui->listWidget_second->addItem(item);
        }

        ui->listWidget_second->item(i)->setFlags(ui->listWidget_second->item(i)->flags() | Qt::ItemIsEditable);
    }
    ui->progressBar->setValue(filemanager.directory.entities.size());
    ui->progressBar->hide();

}

void  MainWindow::addItems_to_listWidget_second(const std::vector<fs::path> paths)
{

    for (int i = 0; i < paths.size(); ++i)
    {
        ui->progressBar->setValue(i);

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

    #ifdef linux
    filemanager.path = "/home";
    #elif _WIN32
    filemanager.path = "C:";
    #endif
    filemanager.go_the_other_path(item->text().toStdString());
    ui->listWidget_second->clear();
    ui->lineEdit->clear();
    ui->lineEdit->setText(QString(filemanager.path.string().c_str()));
    addItems_to_listWidget_second();

}

void MainWindow::on_listWidget_second_itemDoubleClicked(QListWidgetItem *item)
{

    if(!filemanager.directory.search_directories.empty())
    {
        filemanager.path = filemanager.directory.search_directories[0].parent_path();
        filemanager.go_the_other_path(filemanager.directory.search_directories[0].filename().string());
        filemanager.directory.search_directories.clear();
    }
    else
    {
     filemanager.go_the_other_path(item->text().toStdString());
    }
     ui->listWidget_second->clear();
     ui->lineEdit->clear();
     ui->lineEdit->setText(QString(filemanager.path.string().c_str()));
     addItems_to_listWidget_second();

}

void MainWindow::on_pushButton_back_pressed()
{

    if(filemanager.paths.size() != 1)
    {
        filemanager.path = filemanager.paths.top();
        filemanager.go_the_other_path();
        filemanager.paths.pop();
        ui->lineEdit->clear();
        ui->lineEdit->setText(QString(filemanager.path.string().c_str()));
        ui->listWidget_second->clear();
        addItems_to_listWidget_second();
    }

}

void MainWindow::on_lineEdit_editingFinished()
{
    if(ui->lineEdit->text().toStdString()[0] == '/')
    {
        filemanager.path = ui->lineEdit->text().toStdString();
        filemanager.go_the_other_path();
        ui->listWidget_second->clear();
        addItems_to_listWidget_second();
    }

}


void MainWindow::on_actionCreate_2_triggered()
{

    create_file();

}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
   if(event->key() == Qt::Key_Delete)
   {
        QMessageBox::StandardButton reply = QMessageBox::question(this,"","Do you want to delete?",QMessageBox::Yes | QMessageBox::No);
        if(reply == QMessageBox::Yes)
        {
            filemanager.directory.deleteFile(filemanager.path,ui->listWidget_second->currentItem()->text().toStdString());
            ui->listWidget_second->clear();
            addItems_to_listWidget_second();
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
            ui->listWidget_second->clear();
            filemanager.directory.paste_file_or_folder(filemanager.path);
            addItems_to_listWidget_second();
        }
        else if (event->matches(QKeySequence::Save))
        {
            filemanager.directory.rename_file_or_folder(filemanager.path,filemanager.directory.entities[ui->listWidget_second->currentRow()].name.c_str(), ui->listWidget_second->currentItem()->text().toStdString());
            ui->listWidget_second->clear();
            addItems_to_listWidget_second();
        }
   }

}

void MainWindow::copy()
{

    filemanager.directory.copy_file_or_folder(filemanager.path,ui->listWidget_second->currentItem()->text().toStdString());

}

void MainWindow::move()
{

    copy();
    move_form.addFilemanager(filemanager);
    move_form.addItem();
    move_form.show();
    ui->listWidget_second->clear();
    addItems_to_listWidget_second();

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
        filemanager.directory.sort_by_name();
    }
    else if(ui->comboBox->currentText() == "size")
    {
        ui->listWidget_second->clear();
        filemanager.directory.sort_by_size();
    }

}

void MainWindow::on_comboBox_currentIndexChanged()
{

    if(ui->comboBox->currentText() != "none")
    {
        if(ui->comboBox->currentText() == "name")
        {
            ui->listWidget_second->clear();
            filemanager.directory.sort_by_name();
            addItems_to_listWidget_second();
        }
        else
        {
            ui->listWidget_second->clear();
            filemanager.directory.sort_by_size();
            addItems_to_listWidget_second();
        }
    }

}

void MainWindow::create_folder()
{

    second.setModal(true);
    second.ui->label->setText(QString("Enter name of folder"));
    second.exec();
    string name = second.ui->lineEdit->text().toStdString();

    if(!name.empty())
    {
        filemanager.directory.addFolder(filemanager.path, name);
        ui->listWidget_second->clear();
        addItems_to_listWidget_second();
    }

}
void MainWindow::create_file()
{

    second.setModal(true);
    second.ui->label->setText(QString("Enter name of file"));
    second.exec();
    string name = second.ui->lineEdit->text().toStdString();

    if(!name.empty())
    {
        filemanager.directory.addFile(filemanager.path, name);
        ui->listWidget_second->clear();
        addItems_to_listWidget_second();
    }

}

void MainWindow::info_about_entities()
{

    about.reset_all();
    std::filesystem::path path;
    bool isAddPath = false;
    while (!isAddPath)
    {
        try
        {
            path = filemanager.path;

            path /= ui->listWidget_second->currentItem()->text().toStdString();
            if (!fs::exists(path))
            {

                  throw std::logic_error("You enter wrong name");
            }
            if (fs::is_regular_file(path))
            {
                about.ui->label->setText(QString("name: "));
                about.ui->label_2->setText(QString("path: "));
                about.ui->label_3->setText(QString("size: "));
                about.ui->label_4->setText(QString("extension: "));

                about.ui->about_right_1->setText(QString(path.filename().string().c_str()));
                about.ui->about_right_2->setText(QString(filemanager.path.string().c_str()));
                about.ui->about_right_3->setText(QString::number(filemanager.directory.size_of_folder(filemanager.path)));
                about.ui->about_right_4->setText(QString(path.extension().string().c_str()));
            }
            else
            {
                about.ui->label->setText(QString("name: "));
                about.ui->label_2->setText(QString("path: "));
                about.ui->label_3->setText(QString("size: "));

                about.ui->about_right_1->setText(QString(path.filename().string().c_str()));
                about.ui->about_right_2->setText(QString(filemanager.path.string().c_str()));
                about.ui->about_right_3->setText(QString::number(filemanager.directory.size_of_folder(filemanager.path)));
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

void MainWindow::showContextMenu(const QPoint& pos)
{

    QPoint globalPos = ui->listWidget_second->mapToGlobal(pos);

    QMenu myMenu;

    myMenu.addAction("Create file", this, SLOT(create_file()));
    myMenu.addAction("Create folder", this, SLOT(create_folder()));
    myMenu.addAction("Move", this, SLOT(move()));
    myMenu.addAction("Properties", this, SLOT(info_about_entities()));
    myMenu.addAction("Disk", this, SLOT(info_about_space_on_computer()));

    myMenu.exec(globalPos);

}

void MainWindow::info_about_space_on_computer()
{

    about.reset_all();

    #ifdef linux
    const auto& root = fs::path("/");
    #elif _WIN32
    const auto& root = fs::path("C:");
    #endif

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
    filemanager.directory.find_file(ui->lineEdit->text().toStdString());
    addItems_to_listWidget_second(filemanager.directory.search_directories);
    ui->lineEdit->text().clear();

}

