#include "boolcal.h"
#include "ui_boolcal.h"

boolcal::boolcal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::boolcal)
{
    ui->setupUi(this);
    edit=ui->textEdit;
    setWindowTitle(tr("Cal++ release by ZGW"));
    this->setStyleSheet("background-color:khaki;");
}

boolcal::~boolcal()
{
    delete ui;
}

void boolcal::on_pushButton_clear_clicked()
{
    edit->setText("");
}

void boolcal::on_pushButton_backspace_clicked()
{
    QString text = edit->toPlainText();
    QString s = text.mid(0, text.size()-1);
    edit->setText("");
    edit->insertPlainText(s);
    if(text.isEmpty())
        edit->setText("");
}
bool error=0;
void boolcal::on_pushButton_equal_clicked()
{
    QString text = edit->toPlainText();
    string str = text.toStdString();
    int s = operation(str);
    QString result;
    result = QString::number(s);
    if(error == 0 && result=="1")
        edit->insertPlainText("=V");
    else if(error==0 && result=="0")
        edit->insertPlainText("=F");
    else
        edit->setText("");
}


void boolcal::on_pushButton_v_clicked()
{
    edit->insertPlainText("V");
}

void boolcal::on_pushButton_F_clicked()
{
    edit->insertPlainText("F");
}

void boolcal::on_pushButton_huo_clicked()
{
    edit->insertPlainText("|");
}

void boolcal::on_pushButton_yu_clicked()
{
    edit->insertPlainText("*");
}

void boolcal::on_pushButton_La_clicked()
{
    edit->insertPlainText("(");
}

void boolcal::on_pushButton_Ra_clicked()
{
    edit->insertPlainText(")");
}

void boolcal::on_pushButton_fei_clicked()
{
    edit->insertPlainText("!");
}
int boolcal::precedence(char op)
{
    switch(op)
        {
            case '|':
                return 1;
            case '*':
                return 2;
            case '!':
                return 3;
            case '(':
            case '\0'://结束标识符
            default:
                return 0;
        }
}
void boolcal::stringjudge(char*s)
{
    int i=0;
        while(s[i] !=0)
        {
            switch(s[i])
            {
                case'|':case'*':case'!':
                case'(':case')':case 'V':
                case'F':
                    break;
                default:;

            }
            i++;
        }
        return;
}
void boolcal::houzhui(char*s1,char*s2)
{
        stack<char> s;
        s.push('\0');
        int i=0,j=0;
        char ch=s1[i];
        stringjudge(s1);
        while(ch !='\0')
        {
            if(ch==' ')
                ch=s1[++i];
            else if(ch=='(')
            {
                s.push('(');
                ch=s1[++i];
            }
            else if(ch==')')
            {
                while(s.top()!='(')
                {
                    s2[j++]=s.top();
                    s.pop();
                }
                s.pop();
                ch=s1[++i];
            }
            else if(ch=='|' || ch=='*' || ch=='!')
            {
                char w=s.top();
                while(precedence(w)>=precedence(ch))
                {
                    s2[j++]=w;
                    s.pop();
                    w=s.top();
                }
                s.push(ch);
                ch=s1[++i];

            }
            else
            {
                while(ch=='V' || ch=='F')
                {
                    //zhuanhua(ch);
                    s2[j++]=ch;
                    ch=s1[++i];
                }
                s2[j++]=' ';
            }
        }
        ch=s.top();
        s.pop();

        while(ch !='\0')
        {
            s2[j++]=ch;
            ch=s.top();
            s.pop();
        }
        s2[j++]='\0';
}
int boolcal::calculate(char* s2)
{
        stack<int> sd;
        while(!sd.empty())
        {
            sd.pop();
        }
        int i=0;
        int num;
        int n1,n2,n3;
        while(s2[i] != '\0')
        {
            //num=0;
            if(s2[i]=='V' || s2[i]=='F')
            {
                if(s2[i]=='V')
                    num=1;
                else
                    num=0;
                sd.push(num);
                i++;
            }
            /*
            if(s2[i]=='V')
            {
                num=1;
                sd.push(num);
                i++;
            }
            if(s2[i]=='F')
            {
                num=0;
                i++;
                sd.push(num);
            }*/
            else if(s2[i]==' ')
                i++;
            else if(s2[i]=='|')
            {
                n1=sd.top();
                sd.pop();
                n2=sd.top();
                sd.pop();
                n3=n1||n2;
                sd.push(n3);
                i++;
            }
            else if(s2[i]=='*')
            {
                n1=sd.top();
                sd.pop();
                n2=sd.top();
                sd.pop();
                n3=n1&&n2;
                sd.push(n3);
                i++;
            }
            else if(s2[i]=='!')
            {
                n1=sd.top();
                sd.pop();
                sd.push(!n1);
                i++;
            }



        }
        if(sd.size()!=1)
        {
            QString error1 = QString("有多余的(!");
            QMessageBox::warning(this, tr("Error"), error1);
            error=1;
            return 0;
    }
        return sd.top();
}
int boolcal::operation(string str)
{
    int lcount=0;
    int rcount=0;
    const int len=str.length();
    for(int j=0;j<len;j++)
    {

        if ((str[j] == 'V' || str[j] == 'F') && (str[j+1]=='V' || str[j+1]=='F'))
        {
            QString error1 = QString("逻辑真值不能相连");
            QMessageBox::warning(this, tr("Error"), error1);
            error=1;
            return 0;
        }
        if((str[j] =='*' || str[j] == '|' ) && (str[j+1]=='*' || str[j+1] == '|' || str[j+1] == '!'))
        {
            QString error1 = QString("运算符错误");
            QMessageBox::warning(this, tr("Error"), error1);
            error=1;
            return 0;
        }
        if(str[j]=='(')
            lcount++;
        if(str[j]==')')
            rcount++;
    }
    if(lcount != rcount)
    {
        QString error = QString("括号不匹配!");
        QMessageBox::warning(this, tr("Error"), error);
        error=1;
        return 0;
    }
    char *c;
    //const int len=str.length();
    c=new char[len+1];
    strcpy(c,str.c_str());
    /*if (c[0] != 'V' || c[0] != 'F' || c[0] != '!' || c[0] != '(')
    {
        QString error = QString("表达式第一位不正确");
        QMessageBox::warning(this, tr("Error"), error);
        return 0;
    }*/
    houzhui(c,s2);
    return calculate(s2);
}
