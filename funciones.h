#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

//Funcion del menu principal
void funcion_menu(int &opcion_jugador);


//Funcion para escribir los nombres de los jugadores y guardarlos en main
void funcion_nombres(string &jugador1, string &jugador2);

//Funciones para decidir quien inicia la partida
void dados_inicio(int vec[],int cant);
int suma_dados(int vec[],int cant);
int dado_mayor(int vec[],int cant);

//Funcion para ver informacion del turno
void informacion(string jugador1,string jugador2,int ronda,int trufas_totales1,int trufas_totales2,int trufas_ronda,int lanzamientos);

//Funcion para ver quien inicia la partida
void funcion_arranque(string nombre1, string nombre2,int cant,int dado1[],int dado2[], int &bandera);

//Funcion para guardar quien inicia en su lugar
void funcion_nombre_lugar(string &nombre_lugar1, string &nombre_lugar2,
                          string nombre1, string nombre2,int bandera);

//Funcion para cuando son 2 dados
void funcion_de_dados(int dado[],int cant,int &lanzamientos);

//Funcion para analizar los dados
void funcion_analizada_dados(int dado[],int cant,int &trufas_ronda,int &trufas,int &trufastotales1,
                             int &trufastotales2,int &barro,int &bandera_turno,int &oinks,int &primo,
                             int &puntos_victoria_primo,int &bandera_primo);

//Funcion para aumentar la cantidad de dados
void funcion_cantidad_dados(int trufas_totales1,int trufas_totales2,int acu_trufas1,int acu_trufas2,
                            int &bandera_trufas,int barro,int &cantidad);

//Funcion para continuaro o finalizar turno
void funcion_continuar_turno(int &bandera_turno);

//Funcion para mostrar trufas ganas de turno
void mostrar_trufas(int trufas);

//Funcion para pasar las trufas a puntos de victoria

void funcion_puntos_victoria(int matris1[5][2],int matris2[5][2],int trufas_totales1,int trufas_totales2,
                             int vec_lanzamientos1[5],int vec_lanzamientos2[5],
                             int contador_oinks1,int contador_oinks2,int puntos_victoria_primo,int primos1,int primos2);
//Funcion para decidir al ganador
void funcion_ganador(int matris1[5][2],int matris2[5][2],string nombre1,string nombre2,int &ganador,string &nombre_ganador);

//Funcion para mostrar las estadisticas
void funcion_estadisticas(int ganador,string ganador_nombre,int vector_estadisticas[3],
                          string vector_nombre[3]);
//funcion para mostrar los creditos
void funcion_creditos();

#endif // FUNCIONES_H_INCLUDED
