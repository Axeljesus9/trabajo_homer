#include "DataProcessor.h"
#include <QDebug>

float DataProcessor::processData(const QByteArray& data) {

    bool ok;
    float value = QString(data).toFloat(&ok);
    if (ok) {
        return value;
    } else {
        qDebug() << "Error al procesar los datos.";
        return 0.0f;
    }
}
