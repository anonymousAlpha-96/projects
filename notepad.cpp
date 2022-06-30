#include "notepad.h"
#include "ui_notepad.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QFontDialog>
#include <QFont>
#include <QColorDialog>
#include <QColor>
#include <QPrinter>
#include <QPrintDialog>

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

//new functionality
void notepad::on_actionNew_triggered()
{
    file_path = "";
    ui->textEdit->setText("");
}

//open functionality
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

//save functionality
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

//save as functionality
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

//exit/close notepad functionality
void notepad::on_actionExit_triggered()
{
    //ui->exit();
    QWidget::close();
}

//cut functionality
void notepad::on_actionCopy_triggered()
{
    ui->textEdit->cut();
}

//copy functionality
void notepad::on_actionCopy_2_triggered()
{
    ui->textEdit->copy();
}

//paste functionality
void notepad::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

//undo functionality
void notepad::on_actionRedo_triggered()
{
    ui->textEdit->undo();
}

//redo functionality
void notepad::on_actionRedo_2_triggered()
{
    ui->textEdit->redo();
}

//about functionality
void notepad::on_actionAbout_Notepad_triggered()
{
    QMessageBox::about(this,"Developer Info","(C)All rights reserved♥    \nDeveloped by Ankit     \nVersion v1.2");
}

//fonts functionality
void notepad::on_actionFont_Styles_triggered()
{
    bool okay;
    QFont font = QFontDialog::getFont(&okay,this);
    if(okay)
    {
        ui->textEdit->setFont(font);
    }
    else return;
}

//text color functionality
void notepad::on_actionColors_triggered()
{
    QColor color = QColorDialog::getColor(Qt::blue,this, "Select your fav color ");
    if(color.isValid())
    {
        ui->textEdit->setTextColor(color);
    }
    else return;
}

//background color functionality
void notepad::on_actionBackground_Color_triggered()
{
    QColor color = QColorDialog::getColor(Qt::yellow,this,"select background color");
    if(color.isValid())
    {
        ui->textEdit->setTextBackgroundColor(color);
    }
}

//Change the editor color
void notepad::on_actionChange_Editor_Color_triggered()
{
    QColor color = QColorDialog::getColor(Qt::black,this,"Chnage editor color");
    if(color.isValid())
    {
        ui->textEdit->setPalette(QPalette(color));
    }
}

//print options are provided to the user
void notepad::on_actionPrint_triggered()
{
    QPrinter printer;
    printer.setPrinterName("HP 1021");
    QPrintDialog dialog(&printer, this);
    if(dialog.exec() == QDialog::Rejected)return ;
    ui->textEdit->print(&printer);
}

