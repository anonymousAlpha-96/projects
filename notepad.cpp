#include "notepad.h"
#include "ui_notepad.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QFontDialog>
#include <QFont>

notepad::notepad(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::notepad)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

notepad::~notepad()
{
    delete ui;
}


void notepad::on_actionNew_triggered()
{
    file_path = "";
    ui->textEdit->setText("");
}


void notepad::on_actionOpen_triggered()
{
    QString file_name = QFileDialog::getOpenFileName(this, "File opening");
    QFile file(file_name);
    file_path = file_name;
    if(!file.open(QFile::ReadOnly|QFile::Text))
    {
        QMessageBox::warning(this," ","File not found");
        return ;
    }
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit-> setText(text);
    file.close();
}

void notepad::on_actionSave_triggered()
{
    //QString file_name = QFileDialog::getSaveFileName(this, "File saving");
    QFile file(file_path);
    if(!file.open(QFile::WriteOnly|QFile::Text))
    {
        QMessageBox::warning(this," ","File can't be saved");
        return ;
    }
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out<<text;
    file.flush();
    file.close();
}


void notepad::on_actionSave_As_triggered()
{
    QString file_name = QFileDialog::getSaveFileName(this, "File save as");
    QFile file(file_name);
    if(!file.open(QFile::WriteOnly|QFile::Text))
    {
        QMessageBox::warning(this," ","File can't be saved");
        return ;
    }
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out<<text;
    file.flush();
    file.close();
}

void notepad::on_actionExit_triggered()
{
    //ui->exit();
    QWidget::close();
}


void notepad::on_actionCopy_triggered()
{
    ui->textEdit->cut();
}


void notepad::on_actionCopy_2_triggered()
{
    ui->textEdit->copy();
}


void notepad::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}


void notepad::on_actionRedo_triggered()
{
    ui->textEdit->undo();
}


void notepad::on_actionRedo_2_triggered()
{
    ui->textEdit->redo();
}


void notepad::on_actionAbout_Notepad_triggered()
{
    QMessageBox::about(this,"Developer Info","(C)All rights reserved♥    \nDeveloped by Ankit     \nVersion v1.1");
}

void notepad::on_actionFont_Styles_triggered()
{
    bool okay;
    QFont font = QFontDialog::getFont(&okay,this);
    if(okay)
    {
        ui->textEdit->setFont(font);
    }
    else return ;
}

