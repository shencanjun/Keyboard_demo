#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QInputMethodEvent>
#include <QCoreApplication>
#include <QKeyEvent>
#include <QPointer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //this->installEventFilter(this);

    keyTimer = new QTimer(this);
    keyTimer->setInterval(300);
    connect(this->keyTimer, &QTimer::timeout, this, &MainWindow::updataTimer);

    keyboard = new KeyboardForm();
    widget = new QWidget;
    widget->setParent(this);
    keyboard->setParent(widget);
    connect(keyboard, &KeyboardForm::sendKeyhide, this, &MainWindow::hideWidget);
    connect(keyboard, SIGNAL(sendKeyToFocusItem(QString)), &keyEventDispatcher, SLOT(sendKeyToFocusItem(QString)));
    connect(keyboard, &KeyboardForm::sendKeyMove, &keyEventDispatcher, &KeyEventDispatcher::sendKeyMove);
    //connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::sendKeyMove);

    int higt = keyboard->height()/2 + 65;

    widget->setGeometry(0, (this->height() - higt) - 30,
                            this->width(), higt);

    keyboard->setGeometry(0, 0 - keyboard->height()/2 + 65 ,
                          this->width(), keyboard->height());
    ui->pushButton->setFocus();
    keyboard->show();
    widget->hide();

    requestHide = false;
    resizewin = false;
    resizeback = false;
    lineList = this->findChildren<QLineEdit *>();

    keyTimer->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::hideWidget()
{
    requestHide = true;
    widget->hide();
    //updateWinGeometry();
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if(event->type() == QEvent::KeyPress){
        qDebug()<<event->type();
    }

    if(event->type() == QEvent::KeyRelease){
        qDebug()<<event->type();
    }
}


void MainWindow::updataTimer()
{
    //QLineEdit *lineedit;
    currentitem=QApplication::focusWidget();

    if(currentitem != NULL)
    {
        if(currentitem->inherits("QLineEdit")){
            //qDebug()<<"It is QLineEdit";
            keyEventDispatcher.setFocusItem(currentitem);
            updateWinGeometry();
            if(!requestHide){
                ///qDebug()<<"111111111";
                keyboard->show();
                widget->show();
            }
            else {
                ///qDebug()<<"222222222";
                currentitem->clearFocus();
                requestHide = false;
            }
        }
        else {
            widget->hide();
        }
    }
}

void MainWindow::updateWinGeometry()
{
    int cy = currentitem->y();
    int hi = currentitem->height();
    int higt = keyboard->height()/2 + 65;
    if( currentitem == ui->lineEdit_3 || currentitem == ui->lineEdit_4){
        if(!resizewin){
            oldWinSize.setWidth(this->width());
            oldWinSize.setHeight(this->height());
            this->resize(this->width(),this->height() + ((cy+hi) - (widget->y()))+20);
            resizewin = true;
            resizeback = false;

            this->widget->setGeometry(0, ((this->height() - higt) - 30),
                                      this->width(), higt);

        }
    }
    else if(currentitem == ui->lineEdit || currentitem == ui->lineEdit_2){
        if(!resizeback && !oldWinSize.isEmpty())
        {
            this->resize(oldWinSize);
            resizeback = true;
            resizewin = false;

            this->widget->setGeometry(0, ((this->height() - higt) - 30),
                                      this->width(), higt);
        }

    }
}


void MainWindow::havelabel(const QString str)
{

}

void MainWindow::sendKeyMove()
{
    QPointer<QWidget> w = focusWidget();

    if (!w)
        return;

    QKeyEvent *keyPress;

    keyPress = new QKeyEvent(QEvent::KeyPress, Qt::Key_Tab, Qt::NoModifier, QString());

    QCoreApplication::sendEvent(currentitem, keyPress);

}
