# Conceptos de SO

## Tipos de Kernel y sus diferencias:

**Monolítico:**

En un kernel monolítico, todas las funciones del sistema operativo se ejecutan en el mismo espacio de memoria y comparten el mismo espacio de direcciones. El núcleo contiene todos los servicios del sistema operativo, como la gestión de memoria, el sistema de archivos y los controladores de dispositivo.

Ventajas: Mayor eficiencia y rendimiento, ya que las funciones están muy integradas y pueden ejecutarse de manera más rápida.
Desventajas: Menor modularidad y flexibilidad. Un error en una parte del núcleo puede afectar a todo el sistema.

**Microkernel:**

En un kernel microkernel, solo las funciones esenciales se ejecutan en el espacio del núcleo, mientras que los servicios adicionales se implementan como procesos separados que se ejecutan en el espacio del usuario. Los servicios se comunican entre sí a través de mecanismos de intercambio de mensajes.
Ventajas: Mayor modularidad y flexibilidad. Un fallo en un servicio no afecta al núcleo, lo que mejora la estabilidad del sistema.
Desventajas: Puede haber una sobrecarga de comunicación entre los servicios, lo que podría afectar al rendimiento.

**Híbrido:**

Descripción: Combina características de los kernels monolíticos y microkernels. Algunas funciones esenciales pueden ejecutarse en el espacio del kernel, mientras que otras se implementan como procesos en el espacio del usuario.

## User vs Kernel Mode:

**User Mode (Modo Usuario):**

En este modo, los programas de aplicación y los usuarios interactúan con el sistema operativo y ejecutan sus procesos. Sin acceso directo a recursos de hardware y ciertas instrucciones críticas.

**Kernel Mode (Modo Kernel):**

En este modo, el sistema operativo tiene acceso completo a los recursos del hardware y puede ejecutar instrucciones privilegiadas. Se utiliza para realizar tareas críticas del sistema y gestionar recursos.

Diferencias:

Privilegios: El modo kernel tiene privilegios más elevados y acceso directo a hardware, mientras que el modo usuario tiene restricciones y no puede acceder directamente a ciertos recursos.

Acceso a Hardware: El modo kernel permite el acceso directo al hardware, lo que permite la gestión eficiente de recursos y la ejecución de instrucciones privilegiadas.

Protección: La separación entre modos proporciona protección contra acciones no autorizadas y errores en programas de usuario que podrían afectar la estabilidad del sistema.

## Interruptions vs Traps:

**Interrupciones (Interrupts):**

Son eventos externos al flujo normal de ejecución del programa que requieren atención inmediata del sistema operativo. Pueden ser generadas por hardware (por ejemplo, un temporizador, una interrupción de E/S) o por software (por ejemplo, una señal).

Manejo: La CPU suspende temporalmente la ejecución del programa actual, guarda su estado actual y ejecuta un controlador de interrupciones para manejar el evento. Después, el control se devuelve al programa interrumpido.

**Trampas (Traps):**

También conocidas como excepciones, son eventos generados internamente por el programa en ejecución. Pueden ser el resultado de errores de programación, como la división por cero, o de operaciones que requieren acceso privilegiado.

Manejo: Similar a las interrupciones, la CPU guarda el estado actual y ejecuta un manejador de trampas. Después de manejar la trampa, el control se devuelve al programa, pero sin la suspensión completa de su ejecución.

En resumen, las interrupciones son eventos externos que requieren atención inmediata, mientras que las trampas son eventos generados internamente por el programa en ejecución. Ambas se manejan mediante la transferencia de control a rutinas específicas de manejo.

