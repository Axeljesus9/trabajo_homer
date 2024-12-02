#include <iostream>
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h>

using namespace std;

int direccion_de_ip() {
    const char* ip = "127.0.0.1";  // Dirección IP del servidor (en este caso, X-Plane)
    int port = 49000;              // Puerto en el que X-Plane está escuchando

    // Crear el socket UDP
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        cerr << "Error al crear el socket." << endl;
        return EXIT_FAILURE;
    }

    // Configuración de la dirección del servidor (X-Plane)
    sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    inet_pton(AF_INET, ip, &serv_addr.sin_addr);

    // Mensaje de prueba que se enviará a X-Plane
    const char* mensaje = "DATO";  // Reemplaza con el mensaje que X-Plane espera recibir
    int mensaje_len = strlen(mensaje);

    // Enviar el mensaje
    int resultado = sendto(sockfd, mensaje, mensaje_len, 0, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    if (resultado < 0) {
        cerr << "Error al enviar datos a X-Plane." << endl;
        close(sockfd);
        return EXIT_FAILURE;
    }

    cout << "Datos enviados a X-Plane correctamente." << endl;

    // Preparación para recibir respuesta de X-Plane
    char buffer[1024];
    sockaddr_in from_addr;
    socklen_t addr_len = sizeof(from_addr);

    int bytes_received = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&from_addr, &addr_len);
    if (bytes_received < 0) {
        cerr << "Error al recibir datos de X-Plane." << endl;
        close(sockfd);
        return EXIT_FAILURE;
    }

    buffer[bytes_received] = '\0'; // Asegúrate de que los datos recibidos estén correctamente terminados
    cout << "Datos recibidos de X-Plane: " << buffer << endl;

    // Cerrar el socket
    close(sockfd);
    return 0;
}

int direccion() {
    int resultado = direccion_de_ip();

    if (resultado == EXIT_FAILURE) {
        cerr << "Error al establecer la dirección IP." << endl;
        return EXIT_FAILURE;
    }

    cout << "Programa ejecutado exitosamente." << endl;
    return 0;
}

int main() {
    return direccion(); // Ejecutar la función principal
}
