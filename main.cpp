#include "bibliotecas.h"

#include "funciones.h"

int main()
{

    //Bandera para elegir las opciones del menu
    int bandera_filtro=1;
    int contador_estadisticas=0;
    int ganador,vector_estadisticas[3]= {};

    string nombre_ganador,vector_estadisticas_nombre[3]= {};
    ganador=0;

    while(bandera_filtro!=0)
    {

        setlocale(LC_ALL, "spanish");//Funcion que nos permite usar caracteres del español

        //LLamo a la Funcion donde muestro el menu de opciones

        funcion_menu(bandera_filtro);

        //Empiezo a dividir el codigo, si bandera filtro es igual 1(jugar)
        //me pide los nombre de los participicantes

        if(bandera_filtro==1)
        {
            cout<<endl<<"---------------------------------------------"<<endl;

            // Creo las variables de ambos jugadores como strings;
            string nombre_jugador_1,nombre_jugador_2;

            //LLamo a la funcion que define los nombres
            funcion_nombres(nombre_jugador_1,nombre_jugador_2);

            cout<<endl<<"Presione enter para tirar los dados para decidir quien inicia"<<endl;
            cin.get();

            //Defino quien inicia la partida
            const int cantidad_dados=2;
            int dados_jugador_1[cantidad_dados],dados_jugador_2[cantidad_dados];
            int bandera_de_turno;
            bandera_de_turno=0;
            cout<<endl<<"---------------------------------------------"<<endl;

            //Activo el generador de numero random
            srand(time(NULL));

            //Funcion para decidir quien arranca la partida
            funcion_arranque(nombre_jugador_1,nombre_jugador_2,cantidad_dados,dados_jugador_1,
                             dados_jugador_2,bandera_de_turno);


            cout<<endl<<"----------------------------------------"<<endl;
            string jugador_1, jugador_2;
            int i;
            char si_o_no;
            int cont_lanzamientos_1,cont_lanzamientos_2;
            int cont_oinks_1, cont_oinks_2,bandera_lanzamiento;
            int cant=2,acu_trufas_1,acu_trufas_2,trufas1,trufas2;
            int caida_barro,vec_dados[2];
            int trufas_totales_1,trufas_totales_2;
            int bandera_dados;
            int vector_lanzamientos1[5]= {},vector_lanzamientos2[5]= {};
            int bandera_primo;
            int puntos_victoria_primo;
            int bandera_primos1,bandera_primos2;
            bandera_primos1=0;
            bandera_primos2=0;
            puntos_victoria_primo=0;
            bandera_primo=0;

            funcion_nombre_lugar(jugador_1,jugador_2,nombre_jugador_1,
                                 nombre_jugador_2,bandera_de_turno);

            trufas_totales_1=0;
            trufas_totales_2=0;
            acu_trufas_1=0;
            acu_trufas_2=0;
            caida_barro=0;
            cont_lanzamientos_1=0;
            cont_lanzamientos_2=0;
            cont_oinks_1=0;
            cont_oinks_2=0;

            bandera_dados=0;

            for(i=0; i<5; i++)
            {

                bandera_lanzamiento=0;
                cont_lanzamientos_1=0;
                while(bandera_lanzamiento==0 || bandera_lanzamiento==2)
                {
                    cout<<endl<<"-------------------------------------------"<<endl;
                    cout<<endl<<jugador_1<<" presione enter para tirar los dados";
                    cin.get();
                    //Funcion para ver informacion del turno
                    informacion(jugador_1,jugador_2,i,trufas_totales_1,trufas_totales_2,
                                acu_trufas_1,cont_lanzamientos_1);

                    //Funcion para aumentar la cantidad de dados
                    funcion_cantidad_dados(trufas_totales_1,trufas_totales_2,acu_trufas_1,
                                           acu_trufas_2,bandera_dados,caida_barro,cant);

                    //Funcion para las tiradas de dados y las rondas
                    funcion_de_dados(vec_dados,cant,cont_lanzamientos_1);

                    //Funcion para analizar los dados
                    funcion_analizada_dados(vec_dados,cant,acu_trufas_1,
                                            trufas1,trufas_totales_1,trufas_totales_2,
                                            caida_barro,bandera_lanzamiento,cont_oinks_1,bandera_primo,
                                            puntos_victoria_primo,bandera_primos1);

                    //Funcion para mostrar trufas ganas de turno
                    mostrar_trufas(trufas1);
                    acu_trufas_1+=trufas1;

                    //Funcion para determinar si continua o no el turno
                    funcion_continuar_turno(bandera_lanzamiento);

                }
                vector_lanzamientos1[i]=cont_lanzamientos_1;
                trufas_totales_1+=acu_trufas_1;
                acu_trufas_1=0;
                bandera_lanzamiento=0;


                while(bandera_lanzamiento==0 || bandera_lanzamiento==2)
                {
                    cout<<endl<<"-------------------------------------------"<<endl;
                    cout<<endl<<jugador_2<<" presione enter para tirar los dados";
                    cin.get();

                    //Funcion para ver informacion del turno
                    informacion(jugador_2,jugador_1,i,trufas_totales_2,trufas_totales_1,acu_trufas_2,
                                cont_lanzamientos_2);
                    //Funcion para aumentar la cantidad de dados
                    funcion_cantidad_dados(trufas_totales_1,trufas_totales_2,acu_trufas_1,
                                           acu_trufas_2,bandera_dados,caida_barro,cant);

                    //Funcion para las tiradas de dados y las rondas
                    funcion_de_dados(vec_dados,cant,cont_lanzamientos_2);

                    //Funcion para analizar los dados
                    funcion_analizada_dados(vec_dados,cant,acu_trufas_2,
                                            trufas2,trufas_totales_2,trufas_totales_1,
                                            caida_barro,bandera_lanzamiento,cont_oinks_2,bandera_primo,
                                            puntos_victoria_primo,bandera_primos2);

                    //Funcion para mostrar trufas ganas de turno
                    mostrar_trufas(trufas2);

                    acu_trufas_2+=trufas2;

                    //Funcion para determinar si continua o no el turno
                    funcion_continuar_turno(bandera_lanzamiento);

                }
                vector_lanzamientos2[i]=cont_lanzamientos_2;
                cont_lanzamientos_2=0;


                trufas_totales_2+=acu_trufas_2;
                acu_trufas_2=0;

            }
            int matris_puntos1[5][2];
            int matris_puntos2[5][2];




            //Funcion para sumar puntos de victoria.
            funcion_puntos_victoria(matris_puntos1,matris_puntos2,trufas_totales_1,trufas_totales_2,
                                    vector_lanzamientos1,vector_lanzamientos2,
                                    cont_oinks_1,cont_oinks_2,puntos_victoria_primo,bandera_primos1,bandera_primos2);
            //Funcion para mostrar ganador
            funcion_ganador(matris_puntos1,matris_puntos2,jugador_1,jugador_2,ganador,nombre_ganador);


        }
        if(bandera_filtro==2)
        {

            funcion_estadisticas(ganador,nombre_ganador,vector_estadisticas,
                                 vector_estadisticas_nombre);

        }
        if(bandera_filtro==3)
        {
            funcion_creditos();
        }


    }
    return 0;
}

