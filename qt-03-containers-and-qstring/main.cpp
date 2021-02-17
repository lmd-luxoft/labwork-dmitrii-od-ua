#include <QCoreApplication>
#include <QDebug>
#include <QStack>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<QString> names;
    names << "Mary" << "Ann" << "Charlynn" << "Marylynn" << "Margaret"
          << "Kate" << "Rose" << "Gwendolyn";


    // TODO: using Java-style iterators print the longest name from the list
    // use QString::arg to output message with this name

    QListIterator<QString> javaIterator(names);
    QString longestName;
    while(javaIterator.hasNext())
    {
        QString  currentName = javaIterator.next();
        if( longestName.length() < currentName.length() )
        {
            longestName = currentName;
        }
    }
    QString output("Longest name: %1");
    qDebug() << output.arg(longestName);

    QString shortestName;
    for( auto & i : names )
    {
        if( shortestName.isEmpty() || shortestName.length() > i.length())
        {
           shortestName = i;
        }
    }
    qDebug() << shortestName.prepend("Shortest name: ");

    QStringList namesList;
    foreach( QString name, names )
    {
        namesList.push_back(name);
    }
    qDebug() << namesList.join(',');

    // print all names in reverse order
    // TODO: 1. Using QStack

    QStack<QString> reverseNames;
    for( QList<QString>::reverse_iterator i = names.rbegin(); i != names.rend(); ++i )
    {
        reverseNames.push_back(*i);
    }
    qDebug() << reverseNames.join(',');

    // TODO: 2. Using other QList
    QList<QString> reverse(names.rbegin(), names.rend());
    qDebug() << reverse.join(',');

    // TODO: 3. Without other containers
    for( QList<QString>::reverse_iterator i = names.rbegin(); i != names.rend(); ++i )
    {
        qDebug() << *i <<',';
    }

    QMap<int, QString> map;
    for(auto elem : map)
    {

    }

    return a.exec();
}
