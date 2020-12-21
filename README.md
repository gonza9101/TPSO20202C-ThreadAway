<h1>UTN Facultad Regional Buenos Aires</h1>
<h2>Sistemas Operativos</h2>
<h2>Equipo Thread Away</h2>

<h4>Descripción</h4>

Trabajo Práctico PedidOS Ya! de la materia Sistemas Operativos desarrollado en lenguaje C durante el 2do cuatrimestre del año 2020,
el cual, cuenta con diferentes módulos implementados en un entorno distribuido simulando un sistema de pedidos con un manejo adecuado de los recursos.

<h4>Módulos:</h4>
<ul>
  <li>Cliente: proceso encargado de realizar solicitudes de consulta y selección de restaurantes, y creación de pedidos y platos.</li>
  <li>Cliente: proceso encargado de realizar solicitudes de consulta y selección de restaurantes, y creación de pedidos y platos.</li>
  <li>App: proceso planificador de pedidos y asignación de repartidores según algortimos FIFO, SJF S/D y HRRN.</li>
  <li>Comanda: proceso simulador de memoria y swap con un esquema de segmentación paginada.</li>
  <li>Restaurante: proceso planificador de platos y asignacion de cocineros según algoritmos FIFO y RR.</li>
  <li>Sindicato: proceso simulador de Filesystem encargado de administrar archivos para el manejo de restaurantes, pedidos, platos y recetas bajo un esquema enlazado.</li>
</ul>

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
<ul>
  <li>vi .bashrc</li>
  <li>Ir al final de todo y presionar la tecla "i" para que permita ingresar texto</li>
  <li>Pegar el siguiente texto: export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:~/Repositorios/tp-2020-2c-Thread-Away/shared/Debug/</li>
  <li>Escape (para cancelar el INSERTAR)</li>
  <li>:wq + enter</il>
</ul>

<h4>PASO 1</h4>
<ul>
  <li>mkdir Repositorios</li>
</ul>

<h4>PASO 2</h4>
<ul>
  <li>cd Repositorios</li>
</ul>

<h4>PASO 3</h4>
<ul>
  <li>vi deploy.sh</li>
  (Copiar el contenido de este link: https://github.com/sisoputnfrba/tp-2020-2c-Thread-Away/blob/master/deploy.sh)
  <li>Pegar con click derecho</li>
</ul>

<h4>PASO 4</h4>
<ul>
  <li>Escape (para cancelar el INSERTAR)</li>
  <li>:wq + enter</li>
</ul>

<h4>PASO 5</h4>
<ul>
  <li>chmod 777 deploy.sh</li>
</ul>

<h4>PASO 6</h4>
<ul>
  <li>./deploy.sh -t=/home/utnso/Repositorios -d=shared -p=app -p=comanda -p=cliente -p=restaurante -p=sindicato tp-2020-2c-Thread-Away</li>
</ul>
