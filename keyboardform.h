#ifndef KEYBOARDFROM_H
#define KEYBOARDFROM_H

#include <QDialog>
#include "googlepinyin.h"

class QLineEdit;
class QLabel;
class QVBoxLayout;

class KeyboardForm : public QDialog
{
    Q_OBJECT
public:
    explicit KeyboardForm(QWidget *parent = 0);
    ~KeyboardForm(){}

signals:
    void sendKeyToFocusItem(const QString &keyText);
    void sendKeyhide();
    void sendKeyMove(const int key, const int modifier);

public slots:
    void letterClicked();
    void numClicked();
    void hanziClicked();
    void setText(QString str);
    void shiftClicked();
    void changeInputMode();
    void changeSymbol();
    void space();
    void enter();
    void backSpace();
    void prevPage();
    void nextPage();
    void changeStyle();
    void hideWidget();
    void moveFouceDown();
    void moveFouceUp();

private:
    void displayHanzi();

private:
    QWidget *m_enter;               // 输入面板
    QWidget *m_pyFrm;               // 拼音面板
    QWidget *m_btnFrm;              // 按键面板
    QLineEdit *m_labPyText;         // 显示拼音
    QLabel *m_linepyEdit;           //输入框
    QString m_cachePinYin;          // 真实拼音缓存
    QPushButton *b_lastFocus;       //上一个焦点
    QPushButton *b_nextFocus;       //下一个焦点


    QList<QPushButton*> m_listHanzi;
    QList<QPushButton*> m_listCharsBtns; // A-Z Symbol
    QList<QLabel*> m_listLine;

    QVBoxLayout *m_mainLayout;
    QPushButton *m_btnChange;
    QPushButton *m_btnShift;
    QPushButton *m_btnSymbol;
    QPushButton *m_btnSpace; // 显示切换输入法

    enum InputMode{ImEn, ImCn, ImNum};
    InputMode m_inputMode;
    bool m_shiftKey;
    int m_hanziPageCnt, m_curHanziPage;
    GooglePinyin m_pinyin;
};
#endif // KEYBOARDFROM_H
