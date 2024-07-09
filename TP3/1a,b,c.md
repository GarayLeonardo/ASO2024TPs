1a 
- En el codigo El tiempo total de ejecución no es completamente predecible. Aunque hay una estructura fija en las tareas (con tarea_2 y tarea_3 que tienen tiempos de espera fijos), la carga de trabajo de tarea_1 puede provocar cierta variabilidad debido a cómo el sistema operativo gestiona los hilos y la carga de CPU. El tiempo de ejecución no es completamente predecible debido a la variabilidad en la gestión de hilos por el sistema operativo, la carga del sistema y la carga intensiva de tarea_1. Esto provoca pequeñas diferencias en cada ejecución.

- sinhilos.py: El tiempo de ejecución es mucho más predecible comparado con el uso de hilos, ya que las tareas se ejecutan una tras otra sin interferencias. El tiempo total de ejecución es la suma de los tiempos individuales de cada tarea. tarea_1 depende del tiempo necesario para iterar rango veces, tarea_2 toma 1 segundo y tarea_3 toma 4 segundos.

- Los tiempos de ejecucion conhilos.py: Aproximadamente 4,05 segundos. sinnhilos.py: Aproximadamente 5,5 segundos.

1b 
- El tiempo de ejecucion no es similar, pero siempre ronda en un mismo valor, varia dependiendo el hardware.

1c 
- En la primera versión del código, los dos hilos trabajan con la variable "acumulador" sin coordinarse. Esto puede causar un problema llamado "carrera crítica", donde los hilos compiten por acceder y cambiar "acumulador", lo que lleva a resultados impredecibles.

- Al eliminar los comentarios, las acciones de sumar y restar en los hilos continúan sin coordinarse, lo que agrava el problema.
