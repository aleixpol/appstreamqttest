#include <QCoreApplication>
#include <QTextStream>
#include <QDebug>
#include <AppstreamQt/database.h>

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);

//     QTextStream cout(stdout, QIODevice::WriteOnly);
    QTextStream cerr(stderr, QIODevice::WriteOnly);

    Appstream::Database db;
    if (!db.open()) {
        cerr << "couldn't open\n";
        return 1;
    }

    const auto compo = db.componentById(app.arguments().first());
    qDebug() << "name: " << compo.name() << '\n';
    qDebug() << "homepage: " << compo.urls();
    return 0;
}
