#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QTime>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void display();
    ~MainWindow();
protected:
    void resizeEvent(QResizeEvent *);


private slots:
    void on_pushButton_open_clicked();

    void on_pushButton_save_clicked();

    void on_pushButton_leftrevolve_clicked();

    void on_pushButton_rightrevolve_clicked();

    void on_pushButton_vague_clicked();

    void on_pushButton_pale_clicked();

    void on_pushButton_origin_clicked();

    void on_pushButton_last_clicked();

    void on_pushButton_clicked();

    void on_pushButton_left_clicked();

    void on_pushButton_right_clicked();

    void on_action_O_triggered();

    void on_action_last_triggered();

    void on_action_next_triggered();

    void on_action_pale_triggered();

    void on_action_vague_triggered();

    void on_action_return_triggered();

    void on_action_liftrevolve_triggered();

    void on_action_rightrevolve_triggered();

    void on_actionMaker_triggered();

    void on_pushButton_start_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_action_triggered();

    void on_pushButton_7_clicked();

private:
    QStringList fileName;
    Ui::MainWindow *ui;
    int index;
    QTime t;
};

#endif // MAINWINDOW_H
