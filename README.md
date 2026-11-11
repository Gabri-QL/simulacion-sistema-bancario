#BANKRIEL - Sistema de Gestión de Préstamos

![C++](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Platform](https://img.shields.io/badge/Platform-Console-lightgrey?style=for-the-badge)
![Status](https://Academic-Project-blue?style=for-the-badge)

Proyecto académico desarrollado en C++ orientada a simular las operaciones esenciales de un sistema de gestión y estudio financiero de préstamos personales en un entorno de consola interactivo.

---

##  Características Principales

* **Seguridad y Autenticación:** Sistema de inicio de sesión con enmascaramiento de contraseña en tiempo real mediante asteriscos (`*`) utilizando `conio.h`.
* **Registro de Solicitantes:** Captura y validación estricta de datos personales (cédula de 9 dígitos, nombre completo con validación de apellidos, correo electrónico con formato `@`, teléfono de 8 dígitos, dirección y salario).
* **Evaluación Financiera:** Algoritmo de análisis crediticio que aprueba o deniega la solicitud basándose en si el monto supera el 50% del salario mensual registrado.
* **Cálculo de Cuotas y Amortización:** Generación automática de cuotas fijas utilizando matemáticas financieras (`pow`) y una tabla de amortización detallada mes a mes con ajuste de céntimos para el cierre exacto de saldos.
* **Identificadores Únicos:** Generación automatizada de IDs de préstamo bajo un formato estructurado (`BK-#####-AAAA`) y control de fechas del sistema mediante la librería `ctime`.
* **Robustez en Validaciones:** Manejo avanzado de entradas mediante cadenas (`getline`) combinadas con algoritmos de verificación para evitar caídas del programa ante datos erróneos.

---

##  Tecnologías y Librerías Utilizadas

El programa fue desarrollado en **C++** aprovechando librerías estándar del lenguaje y de control de consola:
* `<iostream>`: Entrada y salida estándar de datos en consola.
* `<string>`: Manipulación y análisis de cadenas de texto.
* `<conio.h>`: Captura de caracteres en tiempo de ejecución (`_getch()`).
* `<ctime>`: Extracción de la fecha y hora actual del sistema.
* `<cmath>`: Operaciones matemáticas avanzadas (potencias para tasas de interés).
* `<iomanip>`: Control de formato y decimales en los reportes monetarios (`setprecision`).

---

## Guía de Instalación y Ejecución

Siga estos pasos para compilar y ejecutar el proyecto en su computadora:

1. **Clona el repositorio** o descarga los archivos fuente (`main.cpp`):
   ```bash
   git clone [https://github.com/tu-usuario/nombre-de-tu-repositorio.git](https://github.com/tu-usuario/nombre-de-tu-repositorio.git)
