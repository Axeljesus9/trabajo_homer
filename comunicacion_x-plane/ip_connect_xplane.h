#ifndef IP_CONNECT_XPLANE_H
#define IP_CONNECT_XPLANE_H

#include <QObject>
#include <QUdpSocket>

class ip_connect_xplane : public QObject {
    Q_OBJECT

public:
    ip_connect_xplane(const QString& ip, unsigned short port);
    ~ip_connect_xplane();

    void connect();
    void disconnect();
    void sendRequest(const QString& dataRef);  // Solicitar un DataRef
    void receiveData();  // Recibir datos de X-Plane

private:
    QString ipAddress;
    unsigned short port;
    QUdpSocket* socket;
};

#endif // IP_CONNECT_XPLANE_H
