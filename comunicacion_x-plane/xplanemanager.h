#ifndef XPLANEMANAGER_H
#define XPLANEMANAGER_H

#include "ip_xplane.h"

class XPlaneManager {
public:
    XPlaneManager(const QString& ip, unsigned short port);
    void getAircraftSpeed();

private:
    ip_xplane* xplaneConnection;
};

#endif // XPLANEMANAGER_H
