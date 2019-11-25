#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    keyboard = new KeyboardForm();
    keyboard->setParent(ui->widget);

    int higt = keyboard->height()/2 + 40;

    ui->widget->setGeometry((this->width()-keyboard->width())/2, (this->height() - higt) - 30,
                            keyboard->width(), higt);

    keyboard->setGeometry(0, 0 - keyboard->height()/2 + 40 ,
                          keyboard->width(), keyboard->height());
    keyboard->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
