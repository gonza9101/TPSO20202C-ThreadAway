<h1>UTN Facultad Regional Buenos Aires</h1>
<h2>Sistemas Operativos</h2>
<h2>Equipo Thread Away</h2>

<h4>Descripción</h4>

Trabajo Práctico PedidOS Ya! de la materia Sistemas Operativos desarrollado en lenguaje C durante el 2do cuatrimestre del año 2020,
el cual, cuenta con diferentes módulos implementados en un entorno distribuido simulando un sistema de pedidos con un manejo adecuado de los recursos.

<h4>Módulos:</h4>
- Cliente: proceso encargado de realizar solicitudes de consulta y selección de restaurantes, y creación de pedidos y platos.
- App: proceso planificador de pedidos y asignación de repartidores según algortimos FIFO, SJF S/D y HRRN.
- Comanda: proceso simulador de memoria y swap con un esquema de segmentación paginada.
- Restaurante: proceso planificador de platos y asignacion de cocineros según algoritmos FIFO y RR.
- Sindicato: proceso simulador de Filesystem encargado de administrar archivos para el manejo de restaurantes, pedidos, platos y recetas bajo un esquema enlazado.

<h4>Disclaimer shared</h4>

Para hacer que ejecute el programa con la shared linkeada, cerrar todas las terminales y abrir una terminal nueva, 
poner el sig. comando para editar el .bashrc (o usar el editor de preferencia)
leafpad .bashrc

copiar y pegar la sig linea a lo ultimo: 
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:~/Repositorios/tp-2020-2c-Thread-Away/shared/Debug/

Con esto, cada vez que ejecuten el programa desde consola, se podra encontrar la shared object para ejecutar.
Tener en cuenta que esto se debe hacer tambien en las VM pruebas y en la entrega final (usando otro editor).

En cuanto a las entregas finales, upload al repo los archivos makefile, objects.mk y sources.mk
de cada proyecto, a fin de poder compilar en otras VMs.

<h3>Pasos para Deploy:</h3>

<h4>PASO 0</h4>
- vi .bashrc
- Ir al final de todo y presionar la tecla "i" para que permita ingresar texto
- Pegar el siguiente texto: <br>
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:~/Repositorios/tp-2020-2c-Thread-Away/shared/Debug/
- Escape (para cancelar el INSERTAR)
- :wq + enter

<h4>PASO 1</h4>
- mkdir Repositorios

<h4>PASO 2</h4>
- cd Repositorios

<h4>PASO 3</h4>
- vi deploy.sh
(Copiar el contenido de este link: https://github.com/sisoputnfrba/tp-2020-2c-Thread-Away/blob/master/deploy.sh)
- Pegar con click derecho

<h4>PASO 4</h4>
- Escape (para cancelar el INSERTAR)
- :wq + enter

<h4>PASO 5</h4>
- chmod 777 deploy.sh

<h4>PASO 6</h4>
- ./deploy.sh -t=/home/utnso/Repositorios -d=shared -p=app -p=comanda -p=cliente -p=restaurante -p=sindicato tp-2020-2c-Thread-Away
