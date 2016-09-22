#include <QCoreApplication>
#include <QTextStream>
#include <QDebug>
#include <QMetaEnum>
#include <AppstreamQt/database.h>

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);

    QTextStream cout(stdout, QIODevice::WriteOnly);
    QTextStream cerr(stderr, QIODevice::WriteOnly);

    Appstream::Database db;
    if (!db.open()) {
        cerr << "couldn't open\n";
        return 1;
    }

    const auto compo = db.componentById(app.arguments().last());
    if (!compo.isValid()) {
        cerr << "couldn't find " << app.arguments().last() << '\n';
        return 2;
    }
    cout << "name: " << compo.name() << '\n';
    cout << "urls:\n";

    const auto enumerator = Appstream::Component::staticMetaObject.enumerator(Appstream::Component::staticMetaObject.indexOfEnumerator("UrlKind"));

    auto urls = compo.urls();
    for(auto it = urls.constBegin(); it != urls.constEnd(); ++it) {
        cout << it.key() << ' ' << enumerator.valueToKey(it.key()) << ": " << it.value().toDisplayString() << '\n';
    }
    return 0;
}
