//
// Created by Evgenii.Korchagov on 25.06.2022.
//

#ifndef TEST_CALLERMAINWINDOW_H
#define TEST_CALLERMAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QLineEdit>
#include <string>
#include <cstdio>

class CallerMainWindow : public QMainWindow
{
    Q_OBJECT
private:
    float num1;
    float num2;
    bool isDot = false;
    bool newCalc = false;
    float (CallerMainWindow::*operation)(float, float) = nullptr;
    char resultBuf[50];
public:
    QLineEdit* result = nullptr;
    QLineEdit* first_q_line = nullptr;
    QLineEdit* second_q_line = nullptr;
    QLineEdit* current_q_line = nullptr;

    float makeAddition(float num1, float num2)
    {
        return num1+num2;
    }

    float makeSubtraction(float num1, float num2)
    {
        return num1-num2;
    }

    float makeMultiplication(float num1, float num2)
    {
        return num1*num2;
    }

    float makeDivision(float num1, float num2)
    {
        if(num2==(float)0)
            throw std::invalid_argument("ERROR");
        else
            return num1/num2;
    }

    CallerMainWindow(QWidget *parent = nullptr) : QMainWindow(parent) {};

public slots:
    void add0()
    {
        if(newCalc)
        {
            first_q_line->setText("");
            second_q_line->setText("");
            result->setText("");
            newCalc= false;
        }
        current_q_line->setText(current_q_line->text() + "0");
    };
    void add1()
    {
        if(newCalc)
        {
            first_q_line->setText("");
            second_q_line->setText("");
            result->setText("");
            newCalc=false;
        }
        current_q_line->setText(current_q_line->text() + "1");
    };
    void add2()
    {
        if(newCalc)
        {
            first_q_line->setText("");
            second_q_line->setText("");
            result->setText("");
            newCalc=false;
        }
        current_q_line->setText(current_q_line->text() + "2");
    };
    void add3()
    {
        if(newCalc)
        {
            first_q_line->setText("");
            second_q_line->setText("");
            result->setText("");
            newCalc=false;
        }
        current_q_line->setText(current_q_line->text() + "3");
    };
    void add4()
    {
        if(newCalc)
        {
            first_q_line->setText("");
            second_q_line->setText("");
            result->setText("");
            newCalc=false;
        }
        current_q_line->setText(current_q_line->text() + "4");
    };
    void add5()
    {
        if(newCalc)
        {
            first_q_line->setText("");
            second_q_line->setText("");
            result->setText("");
            newCalc=false;
        }
        current_q_line->setText(current_q_line->text() + "5");
    };
    void add6()
    {
        if(newCalc)
        {
            first_q_line->setText("");
            second_q_line->setText("");
            result->setText("");
            newCalc=false;
        }
        current_q_line->setText(current_q_line->text() + "6");
    };
    void add7()
    {
        if(newCalc)
        {
            first_q_line->setText("");
            second_q_line->setText("");
            result->setText("");
            newCalc=false;
        }
        current_q_line->setText(current_q_line->text() + "7");
    };
    void add8()
    {
        if(newCalc)
        {
            first_q_line->setText("");
            second_q_line->setText("");
            result->setText("");
            newCalc=false;
        }
        current_q_line->setText(current_q_line->text() + "8");
    };
    void add9()
    {
        if(newCalc)
        {
            first_q_line->setText("");
            second_q_line->setText("");
            result->setText("");
            newCalc=false;
        }
        current_q_line->setText(current_q_line->text() + "9");
    };
    void makeCalculation()
    {
        num1=std::stof(first_q_line->text().toStdString());
        num2=std::stof(second_q_line->text().toStdString());
        try
        {
            num1=(this->*operation)(num1, num2);
            std::sprintf (resultBuf, "%f", num1);
            result->setText(resultBuf);
        }
        catch(const std::invalid_argument &e)
        {
            result->setText("ERROR!");

            isDot=false;
            newCalc=true;
            current_q_line=first_q_line;
        }

        isDot=false;
        newCalc=true;
        current_q_line=first_q_line;
    };
    void addDot() {
        if(!isDot&&current_q_line->text()!=nullptr)
        {
            current_q_line->setText(current_q_line->text() + ".");
            isDot=true;
        }
    };
    void reset()
    {
        isDot=false;
        newCalc=true;
        CallerMainWindow::operation= nullptr;
        current_q_line=first_q_line;
        first_q_line->setText("");
        second_q_line->setText("");
        result->setText("");
    };
    void addtion() {
        current_q_line = second_q_line;
        isDot = false;
        CallerMainWindow::operation=&CallerMainWindow::makeAddition;
    };
    void subtraction() {
        current_q_line = second_q_line;
        isDot = false;
        CallerMainWindow::operation=&CallerMainWindow::makeSubtraction;
    };
    void division() {
        current_q_line = second_q_line;
        isDot = false;
        CallerMainWindow::operation=&CallerMainWindow::makeDivision;
    };
    void multiplication() {
        current_q_line = second_q_line;
        isDot = false;
        CallerMainWindow::operation=&CallerMainWindow::makeMultiplication;
    };
};

#endif //TEST_CALLERMAINWINDOW_H
