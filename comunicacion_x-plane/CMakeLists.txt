cmake_minimum_required(VERSION 3.16)

# Definir el nombre del proyecto
project(ComunicacionXPlane VERSION 1.0)

# Configurar C++14 (o la versión que prefieras)
set(CMAKE_CXX_STANDARD 14)

# Encontrar la instalación de Qt (asegúrate de tener Qt instalado y configurado)
find_package(Qt6 REQUIRED COMPONENTS Core Network)

# Incluir los directorios de encabezados
include_directories(
    ${CMAKE_SOURCE_DIR}
)

# Agregar los archivos fuente
set(SOURCES
    main.cpp
    ip_connect_xplane.cpp
    ip_xplane.cpp
    XPlaneManager.cpp
    DataProcessor.cpp
)

# Agregar los archivos de encabezado
set(HEADERS
    ip_connect_xplane.h
    ip_xplane.h
    XPlaneManager.h
    DataProcessor.h
)

# Crear el ejecutable
add_executable(ComunicacionXPlane ${SOURCES} ${HEADERS})

# Vincular con las bibliotecas de Qt necesarias
target_link_libraries(ComunicacionXPlane Qt6::Core Qt6::Network)

# Si es necesario, habilita CMake para generar un proyecto de Qt con el comando `qt6_wrap_cpp`
# qt6_wrap_cpp(MOC_SOURCES ${HEADERS})

# Configura el directorio de construcción
set(CMAKE_AUTOMOC ON)
