#include "xplanemanager.h"

XPlaneManager::XPlaneManager(const QString& ip, unsigned short port) {
    xplaneConnection = new ip_xplane(ip, port);
}

void XPlaneManager::getAircraftSpeed() {
    // Solicitar la velocidad del avión (DataRef)
    xplaneConnection->requestData("sim/flightmodel/position/indicated_airspeed");
}
