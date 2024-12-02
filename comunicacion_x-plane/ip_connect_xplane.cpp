#include "ip_connect_xplane.h"
#include <QHostAddress>
#include <QByteArray>
#include <QDebug>
#include "dataprocessor.h"

ip_connect_xplane::ip_connect_xplane(const QString& ip, unsigned short port)
    : ipAddress(ip), port(port), socket(nullptr) {
    socket = new QUdpSocket(this);
}

ip_connect_xplane::~ip_connect_xplane() {
    disconnect();  // Asegúrate de desconectar correctamente
}

void ip_connect_xplane::connect() {
    socket->connectToHost(QHostAddress(ipAddress), port);
    if (socket->waitForConnected()) {
        qDebug() << "Conectado a X-Plane";
    } else {
        qDebug() << "Error al conectar a X-Plane";
    }
}

void ip_connect_xplane::disconnect() {
    if (socket && socket->state() == QAbstractSocket::ConnectedState) {
        socket->disconnectFromHost();
        qDebug() << "Desconectado de X-Plane";
    }
}

void ip_connect_xplane::sendRequest(const QString& dataRef) {
    QByteArray requestData;
    requestData.append(dataRef.toUtf8());  // Convertir el QString a QByteArray

    socket->write(requestData);
    socket->flush();
    qDebug() << "Comando enviado a X-Plane: " << dataRef;
}

void ip_connect_xplane::receiveData() {
    if (socket->hasPendingDatagrams()) {
        QByteArray data;
        data.resize(socket->pendingDatagramSize());
        QHostAddress sender;
        quint16 senderPort;

        socket->readDatagram(data.data(), data.size(), &sender, &senderPort);

        qDebug() << "Datos recibidos de X-Plane: " << data;
    }
}
