#ifndef BOOLCAL_H
#define BOOLCAL_H

#include <QMainWindow>
#include<Qstring>
#include<string>
#include <QTextEdit>
#include <stack>
#include <QMessageBox>
#include <map>
using namespace std;

namespace Ui {
class boolcal;
}

class boolcal : public QMainWindow
{
    Q_OBJECT

public:
    explicit boolcal(QWidget *parent = 0);
    ~boolcal();
    //char s1[100];
    char s2[100];
private slots:
    void on_pushButton_clear_clicked();

    void on_pushButton_backspace_clicked();

    void on_pushButton_equal_clicked();

    void on_pushButton_v_clicked();

    void on_pushButton_F_clicked();

    void on_pushButton_huo_clicked();

    void on_pushButton_yu_clicked();

    void on_pushButton_La_clicked();

    void on_pushButton_Ra_clicked();

    void on_pushButton_fei_clicked();

    int precedence(char op);//运算符优先级比较

    void stringjudge(char* s);//非法字符判断

    void houzhui(char* s1,char *s2);//中缀表达式转化为后缀表达式

    int calculate(char* s2);//计算

    int operation(string str);//string类型转化为char*型



private:
    Ui::boolcal *ui;
    QTextEdit* edit;
};

#endif // BOOLCAL_H
