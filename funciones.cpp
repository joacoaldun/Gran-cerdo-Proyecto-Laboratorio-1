#include "bibliotecas.h"
#include "funciones.h"



//Funcion donde muestro el menu de opciones
void funcion_menu(int &opcion_jugador)
{



    cout<<"GRAN CERDO"<<endl;

    cout<<endl<<"------------------------------"<<endl;

    cout<<"1- JUGAR"<<endl;

    cout <<"2- ESTADÍSTICA" << endl;

    cout<<"3- CERDITOS"<<endl;

    cout<<endl<<"----------------------"<<endl;

    cout<<"0- SALIR"<<endl;


    cout<<endl<<"INGRESE SU OPCION: ";

    cin>>opcion_jugador;

    int bandera_filtro;
    bandera_filtro=0;
    while(bandera_filtro==0)
    {
        if(opcion_jugador==0||opcion_jugador==1||opcion_jugador==2||opcion_jugador==3)
        {
            bandera_filtro=1;
        }
        else
        {
            cout<<endl<<"Ingreso incorrecto, las opciones validas son 0, 1, 2 y 3, intente nuevamente: ";
            cin>>opcion_jugador;
            cout<<endl;
        }
    }


}

//Funcion para escribir lo nombres de los jugadores y guardarlos en main

void funcion_nombres(string &jugador1, string &jugador2)
{

    setlocale(LC_ALL, "spanish");
    cout<<endl<<"Ingrese el nombre del primer jugador/jugadora: ";
    cin.ignore();
    getline(cin,jugador1);


    cout<<endl<<"Ingrese el nombre del segundo jugador/jugadora: ";
    getline(cin,jugador2);



}




//Funciones para decidir quien inicia la partida

void dados_inicio(int vec[],int cant)
{




    for(int i=0; i<cant; i++)
    {
        vec[i]=(rand()%6)+1;
        cout<<endl<<"un "<<vec[i]<<" en el dado "<<i+1<<"    ";
    }



}
//Funcion para sumar los dados para decidir quien inicia
int suma_dados(int vec[],int cant)
{
    int sumador_dados;
    sumador_dados=0;
    for(int i=0; i<cant; i++)
    {

        sumador_dados+=vec[i];


    }

    return sumador_dados;

}
//Funcion para que es caso de empate gane el dado de mayor valor
int dado_mayor(int vec[],int cant)
{

    int maximo;

    maximo=vec[0];
    //Obtengo el maximo del primer vector
    for(int i=0; i<cant; i++)
    {

        if(maximo<vec[i])
        {
            maximo=vec[i];

        }

    }

    return maximo;
}

// Funcion para ver informacion del turno
void informacion(string jugador1,string jugador2,int ronda,int trufas_totales1,int trufas_totales2,int trufas_ronda,int lanzamientos)
{
    cout<<endl<<endl<<"GRAN CERDO";
    cout<<endl<<"--------------------------------------------------------"<<endl;
    cout<<endl<<jugador1<<": "<<trufas_totales1<<" trufas acumuladas"<<"        "<<jugador2<<": "<<trufas_totales2<<" trufas acumuladas"<<endl;
    cout<<endl;

    cout<<endl<<"TURNO DE "<<jugador1<<endl<<
        "+------------------------+"<<endl<<
        "| RONDAS #"<<ronda+1<<"              |"<<endl<<
        "| TRUFAS DE LA RONDA: "<<trufas_ronda<<"  |"<<endl<<
        "| LANZAMIENTOS: "<<lanzamientos<<"        |"<<endl<<
        "+------------------------+";
}

//funcion para decidir quien arranca la partida

void funcion_arranque(string nombre1, string nombre2,int cant,int dado1[],int dado2[], int &bandera)
{
    int resultado_dados_1;
    int resultado_dados_2;
    while(bandera==0)
    {
        cout<<endl<<"En la tirada para definir quien cominza "<<nombre1<<" a obtenido: "<<endl;

        dados_inicio(dado1,cant);

        resultado_dados_1=suma_dados(dado1,cant);

        cout<<endl<<endl<<"Con una suma de "<<resultado_dados_1<<endl;

        cout<<endl<<"------------"<<endl;

        cout<<endl<<" Y "<<nombre2<< " a obtenido: "<<endl;

        dados_inicio(dado2,cant);

        resultado_dados_2=suma_dados(dado2,cant);

        cout<<endl<<endl<<"Con una suma de "<<resultado_dados_2<<endl;



        if(resultado_dados_1>resultado_dados_2)
        {
            cout<<endl<<"La partida la inicia "<<nombre1<<" por obtener mas puntos"<<endl;
            bandera=1;
        }
        else if(resultado_dados_1<resultado_dados_2)
        {
            cout<<endl<<"La partida la inicia "<<nombre2<<" por obtener mas puntos"<<endl;
            bandera=2;
        }
        else if(resultado_dados_1==resultado_dados_2)
        {
            cout<<endl<<"Los resultados son iguales, por lo cual el que tenga el dado de mayor valor inicia"<<endl;
            bandera=0;
            //guardo el mayor dado de cada jugador en variables
            int maximo1,maximo2;

            maximo1=dado_mayor(dado1,cant);
            maximo2=dado_mayor(dado2,cant);

            if(maximo1>maximo2)
            {
                cout<<endl<<"La partida la inicia "<<nombre1<<" por obtener el dado mas grande"<<endl;
                bandera=1;
            }

            else if(maximo2>maximo1)
            {
                cout<<endl<<"La partida la inicia "<<nombre2<<" por obtener el dado mas grande"<<endl;
                bandera=2;
            }
            else
            {
                cout<<endl<<"Los resultados son iguales, por lo cual deben volver a tirar"<<endl;
                bandera=0;
            }


        }


    }



}


//Funcion para guardar quien inicia en su lugar
void funcion_nombre_lugar(string &nombre_lugar1, string &nombre_lugar2,string nombre1, string nombre2,int bandera)
{

    if(bandera==1)
    {

        nombre_lugar1=nombre1;
        nombre_lugar2=nombre2;
    }
    else if(bandera==2)
    {
        nombre_lugar1=nombre2;
        nombre_lugar2=nombre1;

    }


}
//Funcion para las tiradas de dados y las rondas

void funcion_de_dados(int dado[],int cant,int &lanzamientos)
{

    lanzamientos++;
    cout<<endl<<endl<<"LANZAMIENTO #"<<lanzamientos<<endl<<endl;
    for(int i=0; i<cant; i++)
    {
        dado[i]=(rand()%6)+1;
        cout<<"UN "<<dado[i]<<" ";

    }
    cout<<endl;
}

//Funcion para analizar los dados
void funcion_analizada_dados(int dado[],int cant,int &trufas_ronda,int &trufas,int &trufastotales1,int &trufastotales2,int &barro,
                             int &bandera_turno,int &oinks, int &primo,
                             int &puntos_victoria_primo,int &bandera_primo)
{
    //Si son 2 dados los trato de esta manera
    if(cant == 2)
    {
        int cont_ases;
        cont_ases=0;
        for(int i=0; i<cant; i++)
        {

            if(dado[i]==1)
            {
                cont_ases++;
            }



        }
        if(cont_ases==0)
        {
            if(dado[0]!=dado[1])
            {
                trufas=dado[0]+dado[1];
                bandera_turno=0;
            }
            else
            {
                trufas=(dado[0]+dado[1])*2;

                bandera_turno=2;
                oinks++;
            }
            if(primo==0){
            int contador_primos1;
            int contador_primos2;
            contador_primos1=0;
            contador_primos2=0;
            for(int i=1;i<=6;i++){
                if(dado[0]%i==0){
                    contador_primos1++;
                }
                if(dado[1]%i==0){
                    contador_primos2++;
                }
            }
            if(contador_primos1 ==2 && contador_primos2==2){
                primo=1;
                puntos_victoria_primo=5;
                bandera_primo=1;
                cout<<endl<<"HAS OBTENIDO DOS PRIMOS Y SUMADO 5 PUNTOS DE VICTORIA"<<endl;
            }
            }


        }

        if(cont_ases==1)
        {
            trufas_ronda=0;
            bandera_turno=1;
            trufas=0;
        }
        else if(cont_ases==2)
        {
            cout<<endl<<"Te has hundido en el barro y perdido todas las trufas que tenias acumuladas"<<endl;

            barro=1;
            trufastotales1=0;
            trufas_ronda=0;
            bandera_turno=1;
            trufas=0;
        }

    }
    //Si son 3 dados
    if(cant==3)
    {

        //Me fijo si hay ASES en los dados
        int cont_ases;
        cont_ases=0;
        for(int i=0; i<cant; i++)
        {


            if(dado[i]==1)
            {
                cont_ases++;
            }
        }
        //si no hay ASES analizo y sumo los dados
        if(cont_ases==0)
        {
            int cont_iguales,iguales;
            cont_iguales=0;
            iguales=dado[0];
            for(int i=0; i<cant; i++)
            {
                if(iguales==dado[i])
                {
                    cont_iguales++;
                }


            }
            if(cont_iguales<3)
            {
                int acu_dados;
                acu_dados=0;
                for(int i=0; i<cant; i++)
                {
                    acu_dados+=dado[i];

                }
                trufas=acu_dados;
                bandera_turno=0;
            }
            else if(cont_iguales==3)
            {
                int acu_dados;
                acu_dados=0;
                for(int i=0; i<cant; i++)
                {
                    acu_dados+=dado[i];

                }
                trufas=acu_dados*2;
                bandera_turno=2;
                oinks++;
            }

            if(primo==0){
            int contador_primos1;
            int contador_primos2;
            int contador_primos3;
            contador_primos1=0;
            contador_primos2=0;
            contador_primos3=0;
            for(int i=1;i<=6;i++){
                if(dado[0]%i==0){
                    contador_primos1++;
                }
                if(dado[1]%i==0){
                    contador_primos2++;
                }
                if(dado[2]%i==0){
                    contador_primos3++;
                }
            }
            if(contador_primos1 ==2 && contador_primos2==2 && contador_primos3==2){
                primo=1;
                puntos_victoria_primo=7;
                 bandera_primo=1;
                cout<<endl<<"HAS OBTENIDO 3 PRIMOS Y SUMADO 7 PUNTOS DE VICTORIA"<<endl;
            }
            }

        }




        //Si hay un as, le quito las trufas ganadas en la ronda
        if(cont_ases==1)
        {
            trufas_ronda=0;
            bandera_turno=1;
            trufas=0;
        }
        //Si hay 2 ASES le quito toda sus trufas
        else if(cont_ases==2)
        {
            cout<<endl<<"Te has hundido en el barro y perdido todas las trufas que tenias acumuladas"<<endl;

            barro=1;
            trufastotales1=0;
            trufas_ronda=0;
            bandera_turno=1;
            trufas=0;
        }
        //Si son 3 ASES le doy todas las trufas al rival.
        else if(cont_ases==3)
        {

            cout<<endl<<"Te has hundido en el barro con 3 ases, todas tus trufas pasan para el otro jugador"<<endl;

            barro=1;
            trufastotales2+=trufastotales1+trufas_ronda;
            trufastotales1=0;
            trufas_ronda=0;
            bandera_turno=1;
            trufas=0;

        }


    }

}
//Funcion para determinar la cantidad de dados
void funcion_cantidad_dados(int trufas_totales1,int trufas_totales2,int acu_trufas1,int acu_trufas2,int &bandera_trufas,int barro,int &cantidad)
{

    if(( (trufas_totales1+acu_trufas1)>50 && (trufas_totales2+acu_trufas2)>50) || barro==1)
    {
        bandera_trufas=1;

    }


    if(bandera_trufas==1)
    {
        cantidad=3;
    }


}

//Funcion para determinar si continua o no el turno
void funcion_continuar_turno(int &bandera_turno)
{
    char decidir;
    int bandera_permiso;
    bandera_permiso=0;
    if(bandera_turno==1)
    {
        cout<<endl<<"Perdiste tu turno"<<endl;

    }
    else if(bandera_turno==2)
    {

        cout<<endl<<"Estas obligado a volver a tirar"<<endl;
    }
    else if(bandera_turno==0)
    {

        cout<<endl<<"¿Continuar? (S/N) "<<endl;
        cin>>decidir;
        decidir=toupper(decidir);
        while(bandera_permiso==0)
        {


            if(decidir == 'S' || decidir =='N')
            {
                bandera_permiso=1;
                cin.get();

            }

            else
            {
                cout<<endl<<"Opcion invalida, solo S o N son posibles"<<endl;
                cout<<endl<<"¿Continuar? (S/N) "<<endl;
                cin>>decidir;
                decidir=toupper(decidir);
                bandera_permiso=0;
            }


        }
        if(decidir=='S' )
        {
            bandera_turno=0;
        }
        else if(decidir=='N')
        {
            bandera_turno=1;
        }

    }


}

//Funcion para mostrar trufas ganas de turno
void mostrar_trufas(int trufas)
{

    if(trufas==0)
    {
        cout<<endl<<"¡NO SUMASTE TRUFAS!"<<endl;
    }
    else if(trufas !=0)
    {

        cout<<endl<<"¡SUMASTE "<<trufas<<" TRUFAS!"<<endl;
    }


}

//Funcion para pasar las trufas a puntos de victoria

void funcion_puntos_victoria(int matris1[5][2],int matris2[5][2],int trufas_totales1,int trufas_totales2,
                             int vec_lanzamientos1[5],int vec_lanzamientos2[5],
                             int contador_oinks1,int contador_oinks2,int puntos_victoria_primo,int primos1,int primos2)
{
    for(int i=0; i<5; i++)
    {
        for(int x=0; x<2; x++)
        {
            matris1[i][x]=0;
            matris2[i][x]=0;
        }
    }

//saco quien tuvo mas trufas en total
    matris1[0][1]=trufas_totales1;
    matris2[0][1]=trufas_totales2;

    if(trufas_totales1>trufas_totales2)
    {
        matris1[0][0]=5;
        matris2[0][0]=0;

    }
    else if(trufas_totales2>trufas_totales1)
    {
        matris2[0][0]=5;
        matris1[0][0]=0;
    }
    else if(trufas_totales1==trufas_totales2)
    {
        matris1[0][0]=5;
        matris2[0][0]=5;
    }


//saco los puntos de victoria cada 50 trufas
    matris1[1][0]= trufas_totales1/50;
    matris2[1][0]=trufas_totales2/50;


    matris1[1][1]=trufas_totales1-(trufas_totales1%50);
    matris2[1][1]=trufas_totales2-(trufas_totales2%50);

//multiplico los oinks de cada jugador por 2 para obtener los puntos de victoria
    matris1[2][0]=contador_oinks1*2;
    matris2[2][0]=contador_oinks2*2;

    matris1[2][1]=contador_oinks1;
    matris2[2][1]=contador_oinks2;

//saco el cerdo codicioso(el que tuvo mas lanzamientos)
    int maximo1;
    int maximo2;
    maximo1=vec_lanzamientos1[0];
    maximo2=vec_lanzamientos2[0];

    for(int i=0; i<5; i++)
    {

        if(maximo1<=vec_lanzamientos1[i])
        {
            maximo1=vec_lanzamientos1[i];
        }

        if(maximo2<=vec_lanzamientos2[i])
        {
            maximo2=vec_lanzamientos2[i];
        }


    }
    matris1[3][1]=maximo1;
    matris2[3][1]=maximo2;

    if(maximo1>maximo2)
    {
        matris1[3][0]=3;
    }
    else if(maximo2>maximo1)
    {
        matris2[3][0]=3;
    }
    else if(maximo1==maximo2)
    {
        matris1[3][0]=3;
        matris2[3][0]=3;
    }

    //para obtener los puntos de los primos
    if(primos1==1){
            matris1[4][0]=puntos_victoria_primo;


    }
    else if(primos2==1){
        matris2[4][0]=puntos_victoria_primo;

    }

}

//Funcion para decidir al ganador
void funcion_ganador(int matris1[5][2],int matris2[5][2],string nombre1,string nombre2,
                     int &ganador,string &nombre_ganador)
{
    cout<<endl<<"GRAN CERDO"<<endl;
    cout<<endl<<"-----------------------------------------------------------------"<<endl<<endl;



    cout<<endl<<"HITO                    "<<nombre1<<"                        "<<nombre2<<endl;
    cout<<endl<<"----------------------------------------------------------------------------"<<endl;
    cout<<endl<<"Mas trufas en total   "<<matris1[0][0]<<" PDV ("<<matris1[0][1]<<" trufas)       "<<matris2[0][0]<<" PDV ("<<matris2[0][1]<<" trufas)"<<endl;
    cout<<endl<<"cada 50 trufas        "<<matris1[1][0]<<" PDV ("<<matris1[1][1]<<" trufas)       "<<matris2[1][0]<<" PDV ("<<matris2[1][1]<<" trufas)"<<endl;
    cout<<endl<<"Oinks                 "<<matris1[2][0]<<" PDV ("<<matris1[2][1]<<" Oinks )        "<<matris2[2][0]<<" PDV ("<<matris2[2][1]<<" Oinks )"<<endl;
    cout<<endl<<"Cerdo codicioso       "<<matris1[3][0]<<" PDV ("<<matris1[3][1]<<" Lanzamientos)     "<<matris2[3][0]<<" PDV ("<<matris2[3][1]<<" Lanzamientos)"<<endl;
    cout<<endl<<"HUMCERDO PRIMO        "<<matris1[4][0]<<" PDV                             "<<matris2[4][0]<<" PDV "<<endl;
    cout<<endl<<"---------------------------------------------------------------------------------"<<endl;

    int acu1,acu2;
    acu1=0;
    acu2=0;
    for(int i=0; i<5; i++)
    {

        acu1+= matris1[i][0];
        acu2+=matris2[i][0];
    }
    cout<<endl<<"Total                    "<<acu1<<" PDV                      "<<acu2<<" PDV"<<endl;

    if (acu1>acu2)
    {
        ganador=acu1;
        nombre_ganador=nombre1;
    }
    else if(acu2>acu1)
    {
        ganador=acu2;
        nombre_ganador=nombre2;
    }

    if(acu1>acu2 || acu2>acu1)
    {
        cout<<endl<<"GANADOR: "<<nombre_ganador<<" con "<<ganador<<" puntos de victoria"<<endl;
    }
    else if(acu1 == acu2)
    {

        cout<<endl<<"HUBO UN EMPATE, POR LO TANTO NO HAY GANADOR"<<endl;
    }


    int bandera_filtro;
    bandera_filtro=0;
    string oink;
    cout<<endl<<"Ingrese Oink para continuar: ";
    cin>>oink;



    while(bandera_filtro==0)
    {

        if(oink == "Oink")
        {
            bandera_filtro=1;
        }
        else if(oink != "Oink")
        {
            cout<<endl<<"Debe ingresar Oink para continuar, intente nuevamente: ";
            cin>>oink;
            bandera_filtro=0;
        }

    }

    cout<<endl<<endl<<"-----------------------------------------------"<<endl<<endl;

}
//Funcion para mostrar las estadisticas
void funcion_estadisticas(int ganador,string ganador_nombre,int vector_estadisticas[3],
                          string vector_nombre[3])
{

    if(vector_estadisticas[0]==0)
    {
        vector_nombre[0]=ganador_nombre;
        vector_estadisticas[0]=ganador;

    }

    else if(vector_estadisticas[0]!=0)
    {
        for(int i=3; i>=0; i--)
        {
            if(ganador>vector_estadisticas[i])
            {
                vector_estadisticas[i+1]=vector_estadisticas[i];
                vector_nombre[i+1]=vector_nombre[i];
                vector_estadisticas[i]=ganador;
                vector_nombre[i]=ganador_nombre;


            }


        }
    }

    cout<<endl<<"-----------------------------------------------------"<<endl;
    cout<<endl<<"ESTADISTICAS"<<endl;

    cout<<endl<<"LOS 3 JUGADORES CON EL PUNTAJE MAS ALTO SON: "<<endl;
    int contador;
    contador=0;
    for(int i=0; i<3; i++)
    {
        if(vector_estadisticas[i]!=0)
        {
            contador++;

            cout<<endl<<"#"<<contador<<" "<<vector_nombre[i]<<" con "<<vector_estadisticas[i]<<" Puntos de victoria"<<endl;
        }
    }


    cout<<endl<<endl<<"---------------------------------------------------------------"<<endl<<endl;
}

//Funcion para mostrar los creditos
void funcion_creditos()
{
    cout<<endl<<"---------------------------------------------------"<<endl;

    cout<<endl<<"GRUPO DICE"<<endl;

    cout<<endl<<"PARTICIPANTE: "<<endl;
    cout<<endl<<"-ALDUNCIN JOAQUIN MANUEL, LEGAJO 25778"<<endl;



    cout<<endl<<"-------------------------------------------------------"<<endl;
}
