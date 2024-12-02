#ifndef CONNECT_XPLANE_H
#define CONNECT_XPLANE_H

#include "XPlaneManager.h"
#include "DataProcessor.h"

class Connect_XPlane
{
public:
    Connect_XPlane();
    void startConnection(const QString& host, int port);
    void stopConnection();
    void requestData();

private:
    XPlaneManager *xplaneManager;
    DataProcessor *dataProcessor;
};

#endif // CONNECT_XPLANE_H
