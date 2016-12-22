#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFileDialog>
#include<QPixmap>
#include<QTextCodec>
#include<QMessageBox>
#include <QProgressDialog>
#include<QStatusBar>
#include<QPaintEvent>
#include<QMouseEvent>
#include<QTime>
#include<QTimer>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    index=0;
    ui->progressBar->setMaximum(4000);
    ui->progressBar->setValue(0);
    ui->label->setAlignment(Qt::AlignCenter);
    //状态栏
    ui->statusBar->showMessage(tr("welcome to Sinrain Photor"),2000);
    QLabel *permanent=new QLabel(this);
    statusBar()->setStyleSheet(QString("QStatusBar::item{border: 0px}"));
    permanent->setFrameStyle(QFrame::NoFrame|QFrame::Plain);
    permanent->setText("Sinrain Photor");
    ui->statusBar->addPermanentWidget(permanent);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::resizeEvent(QResizeEvent *)
{
     display();
}
void MainWindow::display()
{
    if(fileName.isEmpty()) return;
    QPixmap pic(fileName.at(index));
    QPixmap p=pic;
    if(pic.width()>=ui->label->width()||pic.height()>=ui->label->height())
       p = pic.scaled(QSize(ui->label->width(),ui->label->height()),Qt::KeepAspectRatio);
    ui->label->setPixmap(p);
}


void MainWindow::on_pushButton_open_clicked()
{
    fileName +=QFileDialog::getOpenFileNames(this,tr("文件对话框"),
                                                            "/",tr("图片文件(*png *jpg *gif)"));

        display();
        for(int i = 0 ; i <= 5000; ++i)
        {
            ui->progressBar->setValue(i);

            qApp->processEvents();
        }
}

void MainWindow::on_pushButton_save_clicked()
{
    ui->label->pixmap()->save(QFileDialog::getSaveFileName());
}

void MainWindow::on_pushButton_leftrevolve_clicked()
{
    const QPixmap *pixmap = ui->label->pixmap();
        QMatrix leftmatrix;
        leftmatrix.rotate(-90);
        ui->label->setPixmap(QPixmap(*pixmap).transformed(leftmatrix,Qt::SmoothTransformation));
        for(int i = 0 ; i <= 5000; ++i)
        {
            ui->progressBar->setValue(i);

            qApp->processEvents();
        }
}

void MainWindow::on_pushButton_rightrevolve_clicked()
{
    const QPixmap *pixmap = ui->label->pixmap();
        QMatrix leftmatrix;
        leftmatrix.rotate(90);
        ui->label->setPixmap(QPixmap(*pixmap).transformed(leftmatrix,Qt::SmoothTransformation));
        for(int i = 0 ; i <= 5000; ++i)
        {
            ui->progressBar->setValue(i);

            qApp->processEvents();
        }
}

void MainWindow::on_pushButton_vague_clicked()
{
    QImage im(fileName.at(index));
        QSize s=im.size();
        for(int i=0;i<s.width();i++){
            for(int j=0;j<s.height();j++){
                if((i+3)<=s.width()&(j+3)<=s.height()){
                    int r=0;
                    int g=0;
                    int b=0;
                    for(int ii=0;ii<3;ii++){
                        for(int jj=0;jj<3;jj++){
                            QColor rgb=im.pixel(i+ii,j+jj);
                            r+=rgb.red();
                            g+=rgb.green();
                            b+=rgb.blue();
                        }
                    }
                    QRgb rg=qRgb(r/9,g/9,b/9);
                    im.setPixel(i+1,j+1,rg);
                }
            }
            }
        QPixmap pic = QPixmap::fromImage(im);

        QPixmap p=pic;
        if(pic.width()>=ui->label->width()||pic.height()>=ui->label->height())
            p=pic.scaled(QSize(ui->label->width(),ui->label->height()),Qt::KeepAspectRatio);
        ui->label->setPixmap(p);
        for(int i = 0 ; i <= 5000; ++i)
        {
            ui->progressBar->setValue(i);

            qApp->processEvents();
        }
}

void MainWindow::on_pushButton_pale_clicked()
{
    QImage im(fileName.at(index));
        QSize s=im.size();
        for(int i=0;i<s.width();i++)
            for(int j=0;j<s.height();j++){
                QPoint p(i,j);
                QColor c=im.pixel(p);
                int sum=(c.red()+c.green()+c.blue())/3;
                c.setRed(sum);
                c.setGreen(sum);
                c.setBlue(sum);
                im.setPixel(p,c.rgb());

            }
        QPixmap pic = QPixmap::fromImage(im);

        QPixmap p=pic;
        if(pic.width()>=ui->label->width()||pic.height()>=ui->label->height())
            p=pic.scaled(QSize(ui->label->width(),ui->label->height()),Qt::KeepAspectRatio);
        ui->label->setPixmap(p);
        for(int i = 0 ; i <= 5000; ++i)
        {
            ui->progressBar->setValue(i);

            qApp->processEvents();
        }
}

void MainWindow::on_pushButton_origin_clicked()
{
    display();
        for(int i = 0 ; i <= 5000; ++i)
        {
            ui->progressBar->setValue(i);

            qApp->processEvents();
        }
}

void MainWindow::on_pushButton_last_clicked()
{
    if(index==0) index=fileName.size();

        --index;
        this->display();


        for(int i = 0 ; i <= 5000; ++i)
        {
            ui->progressBar->setValue(i);

            qApp->processEvents();
        }
}

void MainWindow::on_pushButton_clicked()
{
    if(index==fileName.size()-1) index=-1;
        ++index;
        this->display();
        for(int i = 0 ; i <= 5000; ++i)
        {
            ui->progressBar->setValue(i);

            qApp->processEvents();
        }
}

void MainWindow::on_pushButton_left_clicked()
{
    if(index==0) index=fileName.size();

        --index;
        this->display();


        for(int i = 0 ; i <= 5000; ++i)
        {
            ui->progressBar->setValue(i);

            qApp->processEvents();
        }
}

void MainWindow::on_pushButton_right_clicked()
{
    if(index==fileName.size()-1) index=-1;
        ++index;
        this->display();
        for(int i = 0 ; i <= 5000; ++i)
        {
            ui->progressBar->setValue(i);

            qApp->processEvents();
        }
}

void MainWindow::on_action_O_triggered()
{
    fileName +=QFileDialog::getOpenFileNames(this,tr("文件对话框"),
                                                            "/",tr("图片文件(*png *jpg *gif)"));

        display();
}

void MainWindow::on_action_last_triggered()
{
    if(index==0) index=fileName.size();

        --index;
        this->display();
}

void MainWindow::on_action_next_triggered()
{
    if(index==fileName.size()-1) index=-1;
        ++index;
        this->display();
}

void MainWindow::on_action_pale_triggered()
{
    QImage im(fileName.at(index));
        QSize s=im.size();
        for(int i=0;i<s.width();i++)
            for(int j=0;j<s.height();j++){
                QPoint p(i,j);
                QColor c=im.pixel(p);
                int sum=(c.red()+c.green()+c.blue())/3;
                c.setRed(sum);
                c.setGreen(sum);
                c.setBlue(sum);
                im.setPixel(p,c.rgb());

            }
        QPixmap pic = QPixmap::fromImage(im);

        QPixmap p=pic;
        if(pic.width()>=ui->label->width()||pic.height()>=ui->label->height())
            p=pic.scaled(QSize(ui->label->width(),ui->label->height()),Qt::KeepAspectRatio);
        ui->label->setPixmap(p);
}

void MainWindow::on_action_vague_triggered()
{
    QImage im(fileName.at(index));
        QSize s=im.size();
        for(int i=0;i<s.width();i++){
            for(int j=0;j<s.height();j++){
                if((i+3)<=s.width()&(j+3)<=s.height()){
                    int r=0;
                    int g=0;
                    int b=0;
                    for(int ii=0;ii<3;ii++){
                        for(int jj=0;jj<3;jj++){
                            QColor rgb=im.pixel(i+ii,j+jj);
                            r+=rgb.red();
                            g+=rgb.green();
                            b+=rgb.blue();
                        }
                    }
                    QRgb rg=qRgb(r/9,g/9,b/9);
                    im.setPixel(i+1,j+1,rg);
                }
            }
            }
        QPixmap pic = QPixmap::fromImage(im);

        QPixmap p=pic;
        if(pic.width()>=ui->label->width()||pic.height()>=ui->label->height())
            p=pic.scaled(QSize(ui->label->width(),ui->label->height()),Qt::KeepAspectRatio);
        ui->label->setPixmap(p);
}

void MainWindow::on_action_return_triggered()
{
    display();
}

void MainWindow::on_action_liftrevolve_triggered()
{
    const QPixmap *pixmap = ui->label->pixmap();
        QMatrix leftmatrix;
        leftmatrix.rotate(-90);
        ui->label->setPixmap(QPixmap(*pixmap).transformed(leftmatrix,Qt::SmoothTransformation));
}

void MainWindow::on_action_rightrevolve_triggered()
{
    const QPixmap *pixmap = ui->label->pixmap();
        QMatrix leftmatrix;
        leftmatrix.rotate(90);
        ui->label->setPixmap(QPixmap(*pixmap).transformed(leftmatrix,Qt::SmoothTransformation));
}

void MainWindow::on_actionMaker_triggered()
{
    QMessageBox::about(this,tr("Maker"),
                       tr("SinPhotor 1.01"));
}

void MainWindow::on_pushButton_start_clicked()
{
    QTime t;
    t.start();
    while(1){
        if(t.elapsed()%5000==0){if(index==fileName.size()-1) index=-1;
            ++index;
            this->display();

        }
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    const QPixmap *pixmap = ui->label->pixmap();
        QMatrix leftmatrix;
        leftmatrix.rotate(-90);
        ui->label->setPixmap(QPixmap(*pixmap).transformed(leftmatrix,Qt::SmoothTransformation));
        for(int i = 0 ; i <= 5000; ++i)
        {
            ui->progressBar->setValue(i);

            qApp->processEvents();
        }
}

void MainWindow::on_pushButton_3_clicked()
{
    const QPixmap *pixmap = ui->label->pixmap();
        QMatrix leftmatrix;
        leftmatrix.rotate(90);
        ui->label->setPixmap(QPixmap(*pixmap).transformed(leftmatrix,Qt::SmoothTransformation));
        for(int i = 0 ; i <= 5000; ++i)
        {
            ui->progressBar->setValue(i);

            qApp->processEvents();
        }
}

void MainWindow::on_pushButton_4_clicked()
{
    QImage im(fileName.at(index));
        QSize s=im.size();
        for(int i=0;i<s.width();i++)
            for(int j=0;j<s.height();j++){
                QPoint p(i,j);
                QColor c=im.pixel(p);
                int sum=(c.red()+c.green()+c.blue())/3;
                c.setRed(sum);
                c.setGreen(sum);
                c.setBlue(sum);
                im.setPixel(p,c.rgb());

            }
        QPixmap pic = QPixmap::fromImage(im);

        QPixmap p=pic;
        if(pic.width()>=ui->label->width()||pic.height()>=ui->label->height())
            p=pic.scaled(QSize(ui->label->width(),ui->label->height()),Qt::KeepAspectRatio);
        ui->label->setPixmap(p);
        for(int i = 0 ; i <= 5000; ++i)
        {
            ui->progressBar->setValue(i);

            qApp->processEvents();
        }
}

void MainWindow::on_pushButton_5_clicked()
{
    QImage im(fileName.at(index));
        QSize s=im.size();
        for(int i=0;i<s.width();i++){
            for(int j=0;j<s.height();j++){
                if((i+3)<=s.width()&(j+3)<=s.height()){
                    int r=0;
                    int g=0;
                    int b=0;
                    for(int ii=0;ii<3;ii++){
                        for(int jj=0;jj<3;jj++){
                            QColor rgb=im.pixel(i+ii,j+jj);
                            r+=rgb.red();
                            g+=rgb.green();
                            b+=rgb.blue();
                        }
                    }
                    QRgb rg=qRgb(r/9,g/9,b/9);
                    im.setPixel(i+1,j+1,rg);
                }
            }
            }
        QPixmap pic = QPixmap::fromImage(im);

        QPixmap p=pic;
        if(pic.width()>=ui->label->width()||pic.height()>=ui->label->height())
            p=pic.scaled(QSize(ui->label->width(),ui->label->height()),Qt::KeepAspectRatio);
        ui->label->setPixmap(p);
        for(int i = 0 ; i <= 5000; ++i)
        {
            ui->progressBar->setValue(i);

            qApp->processEvents();
        }
}

void MainWindow::on_pushButton_6_clicked()
{
    display();
        for(int i = 0 ; i <= 5000; ++i)
        {
            ui->progressBar->setValue(i);

            qApp->processEvents();
        }
}

void MainWindow::on_action_triggered()
{
    ui->dockWidget->show();}

void MainWindow::on_pushButton_7_clicked()
{
    QImage im(fileName.at(index));
        QSize s=im.size();
        for(int i = 0; i <s.width() ; i++)
                for(int j = 0; j <s.height() ; j++)
                {
                  QRgb value=im.pixel(i,j);
                  int rgb = (qRed(value)+qGreen(value)+qBlue(value))/3;
                  if (rgb > 127)
                  {
                    rgb = 255;
                  }else
                  {
                    rgb = 0;
                  }
                  im.setPixel(i,j,qRgb(rgb,rgb,rgb));
                }
        QPixmap pic = QPixmap::fromImage(im);

        QPixmap p=pic;
        if(pic.width()>=ui->label->width()||pic.height()>=ui->label->height())
            p=pic.scaled(QSize(ui->label->width(),ui->label->height()),Qt::KeepAspectRatio);
        ui->label->setPixmap(p);
}
