#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QtSql/QSql>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_StartBtn_clicked();

    void on_actionQuit_triggered();

    void on_worldeLable_clicked();

    void on_actionHowToPlay_triggered();

    void on_actionAEZAKEMI_triggered();

    void on_label_sec_linkActivated(const QString &link);

    void on_SubmitBtn_clicked();

    void on_StartOverBtn_clicked();

    void on_listWidget_currentRowChanged(int currentRow);

private:
    Ui::MainWindow *ui;



};
#endif // MAINWINDOW_H


