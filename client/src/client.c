#include "client.h"

int main(void)
{
	/*---------------------------------------------------PARTE 2-------------------------------------------------------------*/

	int conexion;
	char* ip;
	char* puerto;
	char* valor;

	t_log* logger;
	t_config* config;

	/* ---------------- LOGGING ---------------- */

	logger = log_create("tp0.log", "logger", true, log_level_from_string("info"));
	if(logger == NULL){
		exit(3);
	}

	// Usando el logger creado previamente
	// Escribi: "Hola! Soy un log"
	
	/* ---------------- ARCHIVOS DE CONFIGURACION ---------------- */

	config = config_create("cliente.config");
	if(config == NULL){
		exit(3);
	}

	// Usando el config creado previamente, leemos los valores del config y los 
	// dejamos en las variables 'ip', 'puerto' y 'valor'

	// Compruebo y obtengo la ip de la config
	if(config_has_property(config, "IP")){
		log_info(logger, "IP se encuentra en la config.");
		ip = config_get_string_value(config, "IP");
	}
	else{
		log_info(logger, "IP no se encuentra en la config, saliendo del programa.");
		exit(3);
	}

	// Compruebo y obtengo el puerto de la config
	if(config_has_property(config, "PUERTO")){
		log_info(logger, "PUERTO se encuentra en la config.");
		puerto = config_get_string_value(config, "PUERTO");
	}
	else{
		log_info(logger, "PUERTO no se encuentra en la config, saliendo del programa.");
		exit(3);
	}

	// Compruebo y obtengo el valor de la config
	if(config_has_property(config, "CLAVE")){
		log_info(logger, "CLAVE se encuentra en la config.");
		valor = config_get_string_value(config, "CLAVE");
	}
	else{
		log_info(logger, "CLAVE no se encuentra en la config, saliendo del programa.");
		exit(3);
	}

	
	// Loggeamos el valor de config
	log_info(logger, valor);

	/* ---------------- LEER DE CONSOLA ---------------- */

	

	/*---------------------------------------------------PARTE 3-------------------------------------------------------------*/

	// ADVERTENCIA: Antes de continuar, tenemos que asegurarnos que el servidor esté corriendo para poder conectarnos a él

	// Creamos una conexión hacia el servidor
	conexion = crear_conexion(ip, puerto);

	// Enviamos al servidor el valor de CLAVE como mensaje
	enviar_mensaje(valor, conexion);

	// Armamos y enviamos el paquete
	paquete(conexion);

	terminar_programa(conexion, logger, config);

	/*---------------------------------------------------PARTE 5-------------------------------------------------------------*/
	// Proximamente
}

t_log* iniciar_logger(void)
{
	t_log* nuevo_logger;

	return nuevo_logger;
}

t_config* iniciar_config(void)
{
	t_config* nuevo_config;

	return nuevo_config;
}

void leer_consola(t_log* logger)
{
	char* leido;

	// La primera te la dejo de yapa
	leido = readline("> ");

	// El resto, las vamos leyendo y logueando hasta recibir un string vacío


	// ¡No te olvides de liberar las lineas antes de regresar!

}

void paquete(int conexion)
{
	// Ahora toca lo divertido!
	char* leido;
	t_paquete* paquete;

	// Leemos y esta vez agregamos las lineas al paquete


	// ¡No te olvides de liberar las líneas y el paquete antes de regresar!
	
}

void terminar_programa(int conexion, t_log* logger, t_config* config)
{
	/* Y por ultimo, hay que liberar lo que utilizamos (conexion, log y config) 
	  con las funciones de las commons y del TP mencionadas en el enunciado */

	  log_destroy(logger);
	  config_destroy(config);
	  liberar_conexion(conexion);
}
