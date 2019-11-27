#ifndef KEYEVENTDISPATCHER_H
#define KEYEVENTDISPATCHER_H

#include <QObject>
#include <QKeyEvent>

class KeyEventDispatcher : public QObject
{
    Q_OBJECT
public:
    explicit KeyEventDispatcher(QObject *parent = 0);
signals:
    
public slots:
    QObject * getFocusItem(){return m_focusItem;}
    void setFocusItem(QObject *focusItem);
    void sendKeyToFocusItem(const QString &keyText);
    void sendKeyMove(const int key, const int modifier);

private:
    QObject *m_focusItem;
    QList<QWidget* > m_objList;
};

#endif // KEYEVENTDISPATCHER_H
