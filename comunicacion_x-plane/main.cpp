#include <QCoreApplication>
#include "xplanemanager.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    // Establecer la dirección IP y el puerto de X-Plane
    QString ip = "127.0.0.1"; // Dirección de ejemplo
    unsigned short port = 49000;  // Puerto de X-Plane

    // Crear el gestor de X-Plane
    XPlaneManager manager(ip, port);

    // Solicitar la velocidad del avión
    manager.getAircraftSpeed();

    return a.exec();
}
