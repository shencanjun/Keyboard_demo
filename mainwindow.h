#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QKeyEvent>
#include "keyboardform.h"
#include "keyeventdispatcher.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    bool eventFilter(QObject *obj, QEvent *event);
    void updataTimer();
    void hideWidget();
    void updateWinGeometry();
    void havelabel(const QString str);
    void sendKeyMove();

private:
    Ui::MainWindow *ui;
    KeyboardForm *keyboard;
    KeyEventDispatcher keyEventDispatcher;
    QWidget *widget;
    QTimer *keyTimer;
    QTimer *geoTimer;
    QWidget *currentitem;
    QList<QLineEdit *> lineList;
    bool requestHide;
    bool resizewin;
    bool resizeback;

    QSize oldWinSize;
};

#endif // MAINWINDOW_H
