#ifndef IP_XPLANE_H
#define IP_XPLANE_H

#include "ip_connect_xplane.h"

class ip_xplane {
public:
    ip_xplane(const QString& ip, unsigned short port);
    ~ip_xplane();

    void requestData(const QString& dataRef);  // Solicitar datos a X-Plane

private:
    ip_connect_xplane* connection;
};

#endif // IP_XPLANE_H
