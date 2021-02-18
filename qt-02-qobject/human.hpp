#ifndef HUMAN_HPP
#define HUMAN_HPP

#include <QObject>

class Human : public QObject
{
    Q_OBJECT
public:
    explicit Human(QObject *parent = nullptr);

private:
    int m_age;
    char m_sexSymbol;

public:
    int age();
    void setAge(int age);

    char sexSymbol();
    void setSexSymbol(char sex);

signals:

};

#endif // HUMAN_HPP
