#include <mysql.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	
	int err;
	MYSQL_RES *resultado;
	MYSQL_ROW row;
	
	
	MYSQL *conn;
	conn = mysql_init(NULL);
	if(conn == NULL){
		printf("Error al crear la conexion con la base de datos:%u%s\n", mysql_errno(conn), mysql_error(conn));
		exit(1);
	}
	
	conn = mysql_real_connect (conn, "localhost", "root", "mysql", "UNO", 0, NULL, 0);
	if(conn == NULL)
	{
		printf("Error al inicializar la conexion con la base de datos: %u %s\n", mysql_errno(conn), mysql_error(conn));
		exit(1);
	}
	
    // Devuelve el color de una carta en funcion de su Identificador
	char consulta[400];
    int identificador;
	strcpy(consulta,"\0"); // asegurar que la variable está vacía
	printf("Dame el Identificador de la Carta que quieres buscar: %s\n");
    scanf ("%u", identificador);

	strcat (consulta,  "SELECT Color FROM Cartas WHERE Identificador ='");
	strcat (consulta,  identificador);
	strcat (consulta,  "';");

	printf("consulta:  %s\n", consulta);
	
	err = mysql_query(conn, consulta);
	
	if(err!=0){
		return -1;
		exit(1);
	}
	
	resultado = mysql_store_result (conn); // Devuelve el Color de la Carta
	row = mysql_fetch_row (resultado);
	printf("%s\n", row[0]);
}