#ifndef TP1_H
#define TP1_H

#define LONGITUD_CODIGO 13
#define MAX_CADENA 100
#define INICIO 0
#define MEDIO 6
#define FIN 12
#define REPRESENTACION_G 'G'
#define REPRESENTACION_L 'L'
#define REPRESENTACION_R 'R'
#define SEPARADOR '|'
#define BLANCO 'W'
#define NEGRO 'B'
#define CARACTER_0 '0'
#define CARACTER_1 '1'

#define MASCARA 0x01

#define MSJ_INGRESAR_CODIGO "Ingrese el codigo numerico"

#define MSJ_ERROR_SALIDA "El programa se cerrara."
#define MSJ_ERROR_CANTIDAD_DIGITOS "Error: La cantidad de digitos ingresada es incorrecta"
#define MSJ_ERROR_CARGA_DATOS "Error: Alguno de los valores ingresados es incorrecto"
#define MSJ_ERROR_REDUNDANCIA "Error: El valor de la cifra de redundancia es incorrecto"
#define MSJ_VALORES_DEFECTO "Se tomaran los valores por defecto"

#define ANCHO 380
#define ALTO 190
#define LONGITUD_CORRECTA_CADENA_B_W 95
#define PORCENTAJE_ALTO 0.8

#define ENCABEZADO "P1"
#define COMENTARIO '#'
#define COMENTARIO_P1 "La imagen es de"
#define COMENTARIO_P2 "de ancho por"
#define COMENTARIO_P3 "de alto"

typedef unsigned int uint;

typedef enum
{
    OK,
    ERROR_CANTIDAD_DIGITOS,
    ERROR_CARGA_DATOS,
    ERROR_VALOR_REDUNDANCIA
} status_t;

typedef enum
{
    CERO,
    UNO,
    DOS,
	TRES,
	CUATRO,
	CINCO,
	SEIS,
	SIETE,
	OCHO,
	NUEVE
} digitos_t;

typedef enum
{
    PRIMER_DIGITO_CERO,
    PRIMER_DIGITO_UNO,
	PRIMER_DIGITO_DOS,
	PRIMER_DIGITO_TRES,
	PRIMER_DIGITO_CUATRO,
	PRIMER_DIGITO_CINCO,
	PRIMER_DIGITO_SEIS,
	PRIMER_DIGITO_SIETE,
	PRIMER_DIGITO_OCHO,
	PRIMER_DIGITO_NUEVE
} primer_digito_t;

const uint BoW (digitos_t digito);
const uint representacion_doce_digitos (primer_digito_t primer_digito);
void pedir_codigo_numerico(char codigo[]);
void pedir_dimensiones(char aux_ancho[], char aux_alto[]);
status_t validar_codigo(char cadena[]);
int generar_redundancia (char cadena[]);
void definir_codificacion(char c[], uint n);
void generar_cadena_B_W(char const codigo[], char const codificacion[], char cadena_b_w[]);
status_t validar_dimensiones(char const aux_ancho[], char const aux_alto[]);

void generar_cadena_bordes (char cadena_bordes[]);
status_t convertir_bw_a_01(char cadena_codificada[]);
void imprimir_encabezado_pbm (uint ancho, uint alto);
void asignar_dimensiones (char const aux_ancho[], char const aux_alto[], uint *ancho, uint *alto);
void imprimir_barras(char valor[],uint cantidad, uint altura);

void pedir_codigo_numerico(char codigo[])
{
    /* Se encarga de pedir por STDIN el codigo de barras y darle el formato correspondiente
      quitando el '\n' que deja el fgets y reemplazandolo por '\0' */

    fgets(codigo, MAX_CADENA, stdin);
	if(codigo[strlen(codigo)-1]=='\n')
		codigo[strlen(codigo)-1]='\0';
}

void pedir_dimensiones(char aux_ancho[], char aux_alto[])
{
	fgets(aux_ancho,MAX_CADENA,stdin);
	if (aux_ancho[strlen(aux_ancho)-1]=='\n')
		aux_ancho[strlen(aux_ancho)-1]='\0';
	fgets(aux_alto, MAX_CADENA, stdin);
    if (aux_alto[strlen(aux_alto)-1]=='\n')
        aux_alto[strlen(aux_alto)-1]='\0';
}

#endif
