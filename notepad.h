#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class notepad; }
QT_END_NAMESPACE

class notepad : public QMainWindow
{
    Q_OBJECT

public:
    notepad(QWidget *parent = nullptr);
    ~notepad();

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_As_triggered();

    void on_actionExit_triggered();

    void on_actionCopy_triggered();

    void on_actionCopy_2_triggered();

    void on_actionPaste_triggered();

    void on_actionRedo_triggered();

    void on_actionRedo_2_triggered();

    void on_actionAbout_Notepad_triggered();

private:
    Ui::notepad *ui;
    QString file_path;

};
#endif // NOTEPAD_H
