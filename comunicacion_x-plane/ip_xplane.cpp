#include "ip_xplane.h"
#include "ip_connect_xplane.h"

ip_xplane::ip_xplane(const QString& ip, unsigned short port) {
    connection = new ip_connect_xplane(ip, port);
}

ip_xplane::~ip_xplane() {
    delete connection;
}

void ip_xplane::requestData(const QString& dataRef) {
    connection->sendRequest(dataRef);
    connection->receiveData();  // Esperar y procesar la respuesta
}
