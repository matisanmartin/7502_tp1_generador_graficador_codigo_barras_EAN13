#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "tp1.h"

int main(void)
{
        uint ancho, alto, cantidad;
        char cadena_b_w[MAX_CADENA], cadena_bordes[MAX_CADENA];
        char aux_ancho[MAX_CADENA], aux_alto[MAX_CADENA];
        
        pedir_codigo_numerico(cadena_b_w);
        pedir_dimensiones(aux_ancho, aux_alto);
		generar_cadena_bordes(cadena_bordes);
        if(convertir_bw_a_01(cadena_b_w)!=OK)
        {
			fputc('\n',stderr);
			fputs(MSJ_ERROR_SALIDA,stderr);
			fputc('\n',stderr);
			return EXIT_FAILURE;
		}
		asignar_dimensiones(aux_ancho,aux_alto, &ancho,&alto);
        imprimir_encabezado_pbm(ancho-ancho%LONGITUD_CORRECTA_CADENA_B_W,alto);
        cantidad=ancho/LONGITUD_CORRECTA_CADENA_B_W;
        imprimir_barras(cadena_b_w, cantidad, alto*PORCENTAJE_ALTO);
        imprimir_barras(cadena_bordes,cantidad,alto*(1-PORCENTAJE_ALTO));
        return EXIT_SUCCESS;
}

void generar_cadena_bordes (char cadena_bordes[])
{
	size_t i;
	
	for(i=0;i<LONGITUD_CORRECTA_CADENA_B_W;i++){
		if(i==0||i==2||i==46||i==48||i==92||i==94)
			cadena_bordes[i]=CARACTER_1;
		else
			cadena_bordes[i]=CARACTER_0;
	}
		cadena_bordes[i]='\0';
}

status_t convertir_bw_a_01(char cadena_codificada[])
{
    size_t i=0;
    
    if (strlen(cadena_codificada)!=95)
    {
		fputs(MSJ_ERROR_CANTIDAD_DIGITOS,stderr);
		return ERROR_CANTIDAD_DIGITOS;
	}
    for(i=0;i<95;i++)
    {
        if(cadena_codificada[i]==BLANCO)
        {
            cadena_codificada[i]=CARACTER_0;
        }
        else
        { 
			if(cadena_codificada[i]==NEGRO)
			{
				cadena_codificada[i]=CARACTER_1;
			}
			else 
			{
			fputs(MSJ_ERROR_CARGA_DATOS,stderr);
			return ERROR_CARGA_DATOS;
			} 
		}       
	}
    cadena_codificada[i]='\0';
    return OK;
}

void imprimir_encabezado_pbm (uint ancho, uint alto)
{
    puts(ENCABEZADO);
    putchar('\n');
    printf("%i %i \n",ancho,alto);
    printf("%c %s %i %s %i %s \n",COMENTARIO,COMENTARIO_P1,ancho,COMENTARIO_P2,alto,COMENTARIO_P3);
}
void asignar_dimensiones (char const aux_ancho[], char const aux_alto[], uint *ancho, uint *alto)
{
	char *temp;
	
	*ancho=strtol(aux_ancho,&temp,10);
	if(*temp||*ancho<95)
	{
		*ancho=ANCHO;
	}
	*alto=strtol(aux_alto,&temp,10);
	if (*temp||*alto<95)
	{
		*alto=ALTO;
	}
}
void imprimir_barras(char valor[],uint cantidad, uint altura)
{
	size_t i,j,h;
	
	for(i=0;i<altura+1;i++)
    {
		for(j=0;j<strlen(valor);j++)
		{
			for(h=0;h<cantidad;h++)
			{
				putchar(valor[j]);
			}
		}
	}
}
