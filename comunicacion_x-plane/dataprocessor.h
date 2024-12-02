#ifndef DATAPROCESSOR_H
#define DATAPROCESSOR_H

#include <QString>
#include <QByteArray>

class DataProcessor {
public:
    static float processData(const QByteArray& data); // Para convertir el DataRef recibido en un valor flotante.
};

#endif // DATAPROCESSOR_H
