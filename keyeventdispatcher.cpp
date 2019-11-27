#include <QInputMethodEvent>
#include <QCoreApplication>
#include <QKeyEvent>
#include "keyeventdispatcher.h"

KeyEventDispatcher::KeyEventDispatcher(QObject *parent) :
    QObject(parent),m_focusItem(0)
{
}

void KeyEventDispatcher::setFocusItem(QObject *focusItem)
{
    m_focusItem = focusItem;
}

void KeyEventDispatcher::sendKeyToFocusItem(const QString &keyText)
{
    if (!m_focusItem)
    {
        return;
    }

    if (keyText == QString("\x7F"))     //Backspace <--
    {
        QCoreApplication::sendEvent(m_focusItem, new QKeyEvent(QEvent::KeyPress, Qt::Key_Backspace, Qt::NoModifier));
        QCoreApplication::sendEvent(m_focusItem, new QKeyEvent(QEvent::KeyRelease, Qt::Key_Backspace, Qt::NoModifier));
    }
    else if (keyText == QString("\n"))
    {
        QCoreApplication::sendEvent(m_focusItem, new QKeyEvent(QEvent::KeyPress, Qt::Key_Return, Qt::NoModifier));
        QCoreApplication::sendEvent(m_focusItem, new QKeyEvent(QEvent::KeyRelease, Qt::Key_Return, Qt::NoModifier));
    }
    else if (keyText == QString("&&"))
    {
        QCoreApplication::sendEvent(m_focusItem, new QKeyEvent(QEvent::KeyPress, 0, Qt::NoModifier, "&"));
        QCoreApplication::sendEvent(m_focusItem, new QKeyEvent(QEvent::KeyRelease, 0, Qt::NoModifier, "&"));
    }
    else
    {
        QCoreApplication::sendEvent(m_focusItem, new QKeyEvent(QEvent::KeyPress, 0, Qt::NoModifier, keyText));
        QCoreApplication::sendEvent(m_focusItem, new QKeyEvent(QEvent::KeyRelease, 0, Qt::NoModifier, keyText));
    }
}

void KeyEventDispatcher::sendKeyMove(const int key, const int modifier)
{

    if (!m_focusItem)
        return;

    QKeyEvent *keyPress;

    if(modifier == Qt::NoModifier){
        keyPress = new QKeyEvent(QEvent::KeyPress, key, Qt::NoModifier, QString());
    }
    else if(modifier == Qt::ShiftModifier){
        keyPress = new QKeyEvent(QEvent::KeyPress, key, Qt::ShiftModifier, QString());
    }
    else {
        keyPress = new QKeyEvent(QEvent::KeyPress, key, Qt::NoModifier, QString());
    }

    QCoreApplication::sendEvent(m_focusItem, keyPress);
}
