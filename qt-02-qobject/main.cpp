#include <QCoreApplication>
#include <QDebug>
#include "human.hpp"

void printTreeInfo(QObject *parent)
{
    // TODO: print here info about all nodes
    qDebug() << parent->objectName();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Human* parent = new Human;
    parent->setObjectName("Lucas Grey");
    parent->setAge(54);
    parent->setSexSymbol('M');

    Human* maryGrey = new Human(parent);
    maryGrey->setObjectName("Mary Grey");
    maryGrey->setAge(28);
    maryGrey->setSexSymbol('F');

    parent->dumpObjectTree();
	
    printTreeInfo(parent);
    printTreeInfo(maryGrey);

    Human* human = qobject_cast<Human*>(parent);

    qDebug() << parent->objectName()
             << "age:" << human->age()
             << "sex:" << human->sexSymbol();

    for( int i = 0; i < human->children().length(); ++i )
    {
        printTreeInfo(human->children().at(i));
    }

    delete parent;

    return a.exec();
}
