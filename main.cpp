/*
 Autor: Gabriel Esteban Quirós López
 Fecha: 15/6/2026
 Curso: Introduccion a la Programacion (00831)
 Proyecto: 1 - Sistema de Gestion de Prestamos "BANKRIEL"

 Descripcion:
   Este programa simula un sistema bancario para la gestion de prestamos personales.
   Incluye:
   - Login con usuario (admin) y contrasena (7777), con ocultacion de caracteres
   - Registro completo del solicitante (cedula, nombre, correo, telefono, direccion, salario)
   - Solicitud de prestamo (monto, tasa de interes, plazo 12/24/36 meses)
   - Estudio financiero (aprueba si monto <= 50% del salario)
   - Calculo de cuota mensual con metodo de cuota fija
   - Tabla de amortizacion mes a mes con ajuste de centimos
   - Generacion automatica de ID de prestamo (BK-#####-AAAA)
   - Fecha del sistema en formato dd/mm/yyyy
   - Validaciones robustas en todos los campos numericos y de texto
   - Interfaz en consola con colores y arte ASCII

 Validaciones implementadas:
   - Campos vacios (getline + .empty())
   - Numeros con decimales (punto y digitos)
   - Longitud exacta (cedula 9 digitos, telefono 8 digitos)
   - Correo con una @
   - Nombre con al menos dos apellidos
   - Direccion con provincia y canton
   - Rango de valores (salario >0, tasa 0-99.99%, monto >0)
   - Opciones de menu y respuestas S/N

 Librerias utilizadas:
   iostream, string, conio.h, ctime, cmath, iomanip
*/
#include <iostream> //esto me deja usar la libreria de iostream sin esto la computadora no entiende que significa cosas como cout, endl,
#include <string> // Esto me permite usar cadenas de caracteres en las variables y en las constantes
#include <conio.h> // Libreria para poder hacer los asteriscos cuando se escribe la clave
#include <ctime>//Permite tomar la fecha del sistema
#include <cmath>//Permite eleva un numero a una potencia
#include <iomanip>//permite controlar el formato de los decimales
using namespace std; //  esta linea me ahorra tener que escribir std:: antes de cualquier instrucción

int main() // Inicio de proyecto 1 para el aprendizaje de c++
{
const string VERDE="\033[32m";
const string RESET="\033[0m";
const string ROJO="\033[31m";
const string CIAN="\033[36m";
const string AZUL="\033[34m";
const string usuario_correcto="admin";
const string clave_correcta="7777";
int consecutivoPrestamo=10,opcionPlazo=0,plazoMeses=0,telefono=0,cedula=0,Intentos=0,OpcionMenu, contadorPuntos=0;
double cuotaMensual=0.0,tasaMensual=0.0,interesAnual=0.0,montoPrestamo=0.0,salario=0.0;
string claveIngresada="",usuarioIngresado="",fechaRegistro="",idPrestamo="",direccion="",telefonoEntrada="",correo="",nombre="",cedulaEntrada="",MenuEntrada="",salarioEntrada="",solicitudEntrada,tasaEntrada,plazoEntrada,respuestaEntrada="";
bool cedulaNumeros=false, primeraOpcion=false,segundaOpcion=false,terceraOpcion=false,plazoValido=false,telefonoNumeros=false,salarioNumeros,SolicitudNumeros=false,plazoNumeros=false,tasaNumeros=false;

 do { // Sección de login
cout<<AZUL<<"                                           ______________"<<endl;
cout<<"                                          |  _________   |"<<endl;
cout<<RESET<<"=== Login ==="<<AZUL<<"                             | |BANKRIEL    |"<<endl;
cout <<"                                          | |_________   |"<<endl;
cout<<"                                          |______________|"<<RESET<<endl;
cout<<"\033[A         Usuario: ";
getline(cin, usuarioIngresado);

cout<<"         Clave: ";
claveIngresada="";
char caracter;
while (true) {
    caracter=_getch();
    if (caracter==13){
        break;
    }
    else if (caracter==8){
        if (claveIngresada.length()>0){
            claveIngresada.pop_back();
            cout<<"\b \b";
        }
    }
    else {
        claveIngresada += caracter;
        cout<<"*";
    }
    /*
    primero el bucle se asegura de que claveIngresada este vacio, luego se crea la variable caracter para usar mas adelante
    al poner un true adentro del while se crea un bucle infinito hasta que suceda algo que rompa el bucle con el break
    como _getch registra la ultima tecla que se pulso, con el codigo ASCII, el numero 13 representa el enter
    por lo cual en cuanto el usuario presiona enter se procede con el break que rompe el bucle del while inicial
    si la linea 28 no registra un enter entonces se revisa si es un backspace el cual es 8 en codigo ASCII si es asi se procede a revisar si
    ya se escribio algo en la cadena de la clave, si es el caso entonces se borra el ultimo caracter capturado por la linea 28
    y se borran los asteriscos primero moviendo el cursor un espacio atras con \b luego reemplazando el asterisco con un espacio en blanco
    y luego volviendo a mover el cursos un espacio hacia atrás
    si no se registra ni un enter ni un backspace, entonces se imprime en pantalla un asterisco y se almacena ese caracter en
    la cadena de claveIngresada
    */
}
cout<<endl;
if (usuarioIngresado==usuario_correcto && claveIngresada==clave_correcta) // el doble simbolo && es como el and en PSeint, el doble igual se usa para comparar las variables entre si
{
    system("cls");
    cout<<endl<<endl<<"Datos correctos, Bienvenido(a) "<<endl;
    break;
}
else
{
    Intentos++;
    cout<<ROJO<<"Datos invalidos, intente de nuevo. Intentos fallidos = "<<Intentos<<RESET<<endl<<endl;

}
 } while(Intentos<3);

if (Intentos==3)
    cout<< "Has superado el limite de intentos acceso bloqueado"<<endl;





if (Intentos<3){
do {
cout<<AZUL<<"                                           ______________"<<endl;
cout<<"                                          |  _________   |"<<endl;
cout<<RESET<<" Bienvenido(a)"<<AZUL<<"                            | |BANKRIEL    |"<<endl;
cout<<"                                          | |_________   |"<<endl;
cout<<"                                          |______________|"<<endl<<RESET;
cout<<"1. Datos del solicitante"<<endl;
cout<<"2. Solicitar prestamo"<<endl;
cout<<"3. Realizar estudio"<<endl;
cout<<"4. Reporte de pagos"<<endl<<endl;
cout<<CIAN<<"5. Salir"<<RESET<<endl;
cout<<"\033[A\033[A                           "<<VERDE<<"["<<RESET<<" "<<VERDE<<"]"<<RESET<<"\b\b";
cout<<"6. Mensaje de bienvenida";
OpcionMenu=0;
getline(cin, MenuEntrada);
if(MenuEntrada.empty()){
        cout<<"Entrada invalida, intente de nuevo"<<endl;
        continue;
}
bool esNumero=true;
for (char c: MenuEntrada){
    if (c<'0'||c>'9'){
        esNumero=false;
        break;
    }
}
if (!esNumero){
    cout<<"Entrada invalida, intente de nuevo"<<endl;
    continue;
}
OpcionMenu=stoi(MenuEntrada);
if (OpcionMenu<1||OpcionMenu>6){
    cout<<"Entrada invalida, intente de nuevo"<<endl;
    continue;
}

switch(OpcionMenu){
case 1:
    cout<<endl<<CIAN<<"DATOS DEL SOLICITANTE"<<RESET<<endl<<endl;
    while (true){//validacion del numero de identificacion
        cedulaNumeros=true;


    cout<<endl<<"Digite su numero de identificacion (9 digitos): ";
    getline(cin, cedulaEntrada);
    if (cedulaEntrada.empty()){
        cout<<"Datos invalidos, intente de nuevo"<<endl;
        continue;
    }
    for (char c:cedulaEntrada){
        if (c<'0'||c>'9') {
            cedulaNumeros=false;
            break;
        }
    }
    if(!cedulaNumeros){
        cout<<"Datos invalidos, intente de nuevo"<<endl;
        continue;
    }
    cedula=stoi(cedulaEntrada);
    if (cedula < 100000000||cedula>999999999){//            si cin recibe un dato que no deberia, o si el numero no esta dentro del rango entonces
        cout<<"Datos invalidos, intente de nuevo"<<endl; // se sigue con lo que esta adentro de las llaves

    }else{
    break;
    }
    }
    while (true){//validacion del nombre completo con espacios
    cout<<"Digite su nombre completo: ";
    getline(cin, nombre); //lee lo que el usuario escribe espacio incluidos
    if (nombre.empty()){ //revisa que el usuario haya escrito algo
        cout << "Datos invalidos, intente de nuevo"<<endl;
        continue;
    }
    int ContadorEspacios=0;
    for (size_t i=0; i<nombre.length(); i++){
            if (nombre [i]== ' '){
                    ContadorEspacios++;
            }
    }
    if (ContadorEspacios <2) {
        cout <<"Datos invalidos, intente de nuevo"<<endl<<endl;
    } else{
    break;
    }
    }
    while (true){//validacion del correo string sin espacios
    cout<<"Digite su correo electronico: ";
    cin >>correo;
    if (cin.fail() ||correo.empty()){
        cout << "Datos invalidos, intente de nuevo"<<endl<<endl;
        cin.clear();
        cin.ignore(10000, '\n');
        continue;
    }
    int contadorArrobas =0;
    for (size_t i=0;i<correo.length();i++){
        if (correo[i]=='@'){
            contadorArrobas++;
    }
    }
    if (contadorArrobas!=1){
        cout<<"Datos invalidos, intente de nuevo"<<endl<<endl;
        cin.clear();
        cin.ignore(10000, '\n');
    }else{
        cin.ignore(10000, '\n');
        break;
    }
    }
    while (true){//validacion del numero de telefono sin espacios
    telefonoNumeros=true;
    cout<<"Digite su numero de telefono: ";
    getline(cin, telefonoEntrada);
    if (telefonoEntrada.empty()){
        cout<<"Datos invalidos, intente de nuevo"<<endl;
    continue;
    }
    for (char c : telefonoEntrada) {if
        (c<'0'||c>'9'){
        telefonoNumeros=false;
        break;
        }
     }
     if (!telefonoNumeros){
        cout<<"Datos invalidos, intente de nuevo."<<endl;
        continue;
     }
     telefono = stoi(telefonoEntrada);
     if (telefono<10000000||telefono>99999999){
        cout<<"Datos invalidos, intente de nuevo."<<endl;
     }else{
     break;}
    }
    while (true){//validacion de la direccion
    cout<<"Digite su direccion de domicilio: ";
    getline(cin, direccion);
    if (direccion.empty()){
        cout<<"Datos invalidos, intente de nuevo"<<endl<<endl;
        continue;
    }
    int EspaciosDireccion=0;
    for (size_t i=0; i<direccion.length();i++){
       if (direccion [i]== ' '){
        EspaciosDireccion++;
       }
    }
    if (EspaciosDireccion <1) {
        cout<<"Datos invalidos, intente de nuevo"<<endl<<endl;
    } else{
    break;
    }
    }
    while (true){//validacion del salario
    salarioNumeros=true;
    contadorPuntos=0;
    cout<<"Digite su salario mensual: ";
    getline(cin, salarioEntrada);
    if (salarioEntrada.empty()){
        cout<<"Datos invalidos, intente de nuevo."<<endl;
        continue;
    }
    for (char c:salarioEntrada){
        if(c=='.'){contadorPuntos++;}
        else if (c<'0'||c>'9'){
        salarioNumeros=false;
        break;
        }
    }
    if (!salarioNumeros||contadorPuntos>1){
        cout<<"Datos invalidos, intente de nuevo."<<endl;
        continue;
    }
    salario=stod(salarioEntrada);
    if (salario<=0){
        cout<<"Datos invalidos, intente de nuevo."<<endl;
    }else{
    break;}
}




    cout<<endl<<VERDE<<"Datos capturados correctamente."<<RESET<<endl;
    cout<<"Numero de identificacion (9 digitos): "<<cedula<<endl;
    cout<<"Nombre completo: "<<nombre<<endl;
    cout<<"Correo electronico: "<<correo<<endl;
    cout<<"Telefono: "<<telefono<<endl;
    cout<<"Direccion de domicilio: "<<direccion<<endl;
    cout<<fixed<<setprecision(2);
    cout<<"Salario mensual: "<<salario<<endl;
    primeraOpcion=true;

    break;
case 2: {
    cout<<endl;
    if (primeraOpcion==false){
        cout<<"Debe completar la informacion del solicitante"<<endl<<endl;
        break;
        }

    while(true){//validacion del monto del prestamo
     SolicitudNumeros=true;
     contadorPuntos=0;
    cout<<CIAN<<"Solicitante: "<<RESET<<nombre<<endl;
    cout<<CIAN<<"Identificacion: "<<RESET<<cedula<<endl;
    cout<<"Monto del prestamo: ";
    getline(cin, solicitudEntrada);

    if (solicitudEntrada.empty()){
        cout<<"Datos invalidos, intente de nuevo."<<endl;
        continue;
    }
    for (char c:solicitudEntrada){
    if (c=='.'){
            contadorPuntos++;
    } else if (c<'0'||c>'9'){
        SolicitudNumeros=false;
        break;
        }
    }
    if (!SolicitudNumeros||contadorPuntos>1){
        cout<<"Datos invalidos, intente de nuevo."<<endl;
        continue;
    }
    montoPrestamo=stod(solicitudEntrada);
    if (montoPrestamo<=0){
        cout<<"Datos invalidos, intente de nuevo."<<endl;
    }else{
    break;
    }
        }

    while(true){//validacion del interes anual
    tasaNumeros=true;
    contadorPuntos=0;
    cout<<"Tasa anual en%(ej. 12.7): ";
    getline(cin, tasaEntrada);

    if (tasaEntrada.empty()){
        cout<<"Datos invalidos, inente de nuevo."<<endl;
        continue;
    }
    for (char c:tasaEntrada){
            if (c=='.'){
                contadorPuntos++;
            } else if (c<'0'||c>'9'){
                tasaNumeros=false;
        break;
        }

    }
    if (!tasaNumeros||contadorPuntos>1){
        cout<<"Datos invalidos, intente de nuevo."<<endl;
        continue;
    }
    interesAnual=stod(tasaEntrada);
    if (interesAnual<0||interesAnual>=100){
        cout<<"Datos invalidos, intente de nuevo."<<endl;
    }else{
    break;
    }
        }
plazoValido=false;
while (plazoValido==false) { //escoger cuantos meses dura el prestamo
    cout<<CIAN<<"Indique el plazo del prestamo (en meses)"<<RESET<<endl;
    cout<<"1) 12 meses"<<endl;
    cout<<"2) 24 meses"<<endl;
    cout<<"3) 36 meses"<<endl;
    cout<<CIAN<<"opcion [1-3]: "<<RESET;
    getline(cin, plazoEntrada);
    if (plazoEntrada.empty()){
        cout<<"Opcion invalida, vuelva a intentarlo"<<endl<<endl;
        continue;
    }

    plazoNumeros=true;
    for (char c:plazoEntrada){
        if (c<'0'||c>'9'){
            plazoNumeros=false;
            break;
        }
    }
    if (!plazoNumeros){
        cout<<"Opcion invalida, vuelva a intentarlo"<<endl<<endl;
        continue;
    }
    opcionPlazo= stoi(plazoEntrada);
    switch(opcionPlazo){
case 1:
    plazoMeses=12;
    plazoValido=true;
    break;
case 2:
    plazoMeses=24;
    plazoValido=true;
    break;
case 3:
    plazoMeses=36;
    plazoValido=true;
    break;

default:
    cout<<"Opcion invalida, vuelva a intentarlo"<<endl<<endl;
    break;
    }
}
/*extraccion del tiempo del sistema
La computadora cuenta el tiempo en segundos transcurridos. Específicamente,
cuenta cuántos segundos han pasado desde el 1 de enero de 1970 hasta el milisegundo actual
(a esto en informática se le llama el Tiempo Unix).
*/
time_t tiempoActual= time(0);// time_t es tipo de variable y time(0) revisa la hora del sistema y se guarda en tiempoActual
tm* fechaEstructura= localtime(&tiempoActual);//tm* es la estructura con los espacios para guardar los datos por año, mes y dia
//localtime toma los segundos guardados en tiempoActual y lo reparte en fechaEstructura
int dia =fechaEstructura->tm_mday; //tm_day anota la fecha de hoy en la variable dia
int mes = fechaEstructura->tm_mon+1;//en c++ enero es el mes 0 entonces se le suma 1 para que encaje con la realidad
int year= fechaEstructura->tm_year +1900;
/*tm_year solo cuenta los años que han pasado desde 1900 entonces en este caso
si no se le suma 1900 el valor de fechaEstructura quedaria en 126, porque 2026-1900=126,
entonces simplemente volviendo a sumarle 1900 a esta ecuacion nos queda 126+1900=2026
de esta forma el valor de fechaEstructura termina siendo 2026
*/

fechaRegistro=(dia<10 ? "0" : "") + to_string(dia)+"/"+
              (mes<10 ? "0" : "") + to_string(mes)+"/"+
              to_string(year);
             /*el signo de pregunta con los puntos dobles funcionan como un if y un else pero en una sola linea
             el signo de pregunta pregunta ¿la fecha actual es menos de 10? si esto es verdad, escribe un 0 luego
             los dos puntos revisan que si esta ultima condicion no es verdad entonces no se escribe nada
             posteriormente se pasan estos datos tipo int a string para de esa manera poder separarlos con una
             barra diagonal */
string ceros= "";
if (consecutivoPrestamo <10) ceros="0000";
else if (consecutivoPrestamo <100) ceros="000";
else if (consecutivoPrestamo <1000) ceros="00";
else if (consecutivoPrestamo <10000)ceros="0";
else ceros="";

idPrestamo="BK-"+ceros+to_string(consecutivoPrestamo)+"-"+to_string(year);

cout<<endl<<VERDE<<"prestamo registrado con exito"<<RESET<<endl;
cout<<CIAN<<"ID: "<<idPrestamo<<RESET<<endl;
cout<<"Fecha de registro: "<<fechaRegistro<<endl;
cout<<"=========================================="<<endl<<endl;
consecutivoPrestamo++;
segundaOpcion=true;
break;
}
case 3:{
    if (primeraOpcion==false){
        cout<<"Debe completar los datos del solicitante primero"<<endl<<endl;
        break;
    }
    if (segundaOpcion==false){
    cout<<"Debe completar los datos del prestamo primero"<<endl<<endl;
    break;
    }
    double mitadSalario;
    mitadSalario=salario*0.50;
    if (montoPrestamo>mitadSalario){
        cout<<"Prestamo denegado."<<endl;
        cout<<"El monto solicitado ("<<fixed <<setprecision(2)<< montoPrestamo
        <<")supera el 50% de su salario (" <<mitadSalario<<")."<<endl<<endl;
        break;
    }
tasaMensual=(interesAnual)/(100*12);

if (tasaMensual==0){
    cuotaMensual=montoPrestamo/plazoMeses;
}else{
cuotaMensual=montoPrestamo*(tasaMensual/(1.0-pow(1.0+tasaMensual, -plazoMeses)));
}
cout<<fixed<<setprecision(2);
cout<<AZUL<<"R E A L I Z A R  E S T U D I O"<<endl;
cout<<CIAN<<"Solicitante: "<<RESET<<nombre<<endl;
cout<<CIAN<<"Identificacion: "<<RESET<<cedula<<endl;
cout<<CIAN<<"Salario mensual: "<<RESET<<salario<<endl;
cout<<CIAN<<"===== Resultado del estudio ====="<<RESET<<endl;
cout<<"Monto solicitado: "<<montoPrestamo<<endl;
cout<<"Estado: APROBADO"<<endl;
cout<<"plazo del prestamo: "<<plazoMeses<<" meses"<<endl;
cout<<"tasa de interes: "<< interesAnual<<"% anual"<<endl;
cout<<"Cuota mensual: CRC "<<cuotaMensual<<endl;
respuestaEntrada="";
char respuestaUsuario=' ';
while (true){
    cout<<CIAN<<"Desea aceptar el prestamo?(S/N): "<<RESET;
    getline(cin, respuestaEntrada);
    if (respuestaEntrada.empty()){
        cout<<"Respuesta invalida, vuelva a intentarlo."<<endl<<endl;
        continue;
    }
    respuestaUsuario=toupper(respuestaEntrada[0]);
    if ((respuestaUsuario!='S'&&respuestaUsuario!='N')||respuestaEntrada.length()>1){
        cout<<"Respuesta invalida, vuelva a intentarlo."<<endl<<endl;
    }else{
        break;
    }
}

if (respuestaUsuario=='S'){
    cout<<"\nVer reporte y volver al menu"<<endl<<endl;
}else{
cout<<"\nPrestamo rechazado por el usuario. Volviendo al menu principal"<<endl<<endl;}

terceraOpcion=true;
break;
}
case 4:{
    if (terceraOpcion==false){
        cout<<"Debe realizar primero el estudio del prestamo"<<endl<<endl;
        break;
    }
    cout<<VERDE<<"\n=========================================="<<endl;
    cout<<"          REPORTE DE PAGOS - BANKRIEL"<<endl;
    cout<<"=========================================="<<endl;
    cout<<"Fecha analisis  : "<<fechaRegistro<<endl;
    cout<<"Nombre completo : "<<nombre<<endl;
    cout<<"identificacion  : "<<cedula<<endl;
    cout<<"monto           : "<<fixed<<setprecision(2)<<montoPrestamo<<" CRC"<<endl;
    cout<<"Plazo           : "<<plazoMeses<<" meses"<<endl;
    cout<<"Estado          : Aprobado"<<endl;
    double tasaMensualPorcentaje=tasaMensual*100;
    cout<<"Tasa anual      : "<<fixed<<setprecision(2)<<interesAnual<<"% anual"<<"(tasa mensual: "<<setprecision(6)<<tasaMensualPorcentaje<<"%)"<<endl;
    cout<<"Cuota           : "<<cuotaMensual<<" CRC"<<endl;
    cout<<"============================================"<<endl;
    cout<<"Mes\tCuota\t\tInteres\t\tAmortizacion\tSaldo Pendiente"<<endl;
    cout<<"-----------------------------------------------------------------------"<<endl;

    double saldoActual=montoPrestamo;
    double interesMes=0.0;
    double amortizacionMes=0.0;
    double cuotaActual=cuotaMensual;

    cout<<"0\t0.00\t\t0.00\t\t0.00\t\t" <<saldoActual<<endl;

    for (int mes=1; mes <= plazoMeses; mes++){
        interesMes=saldoActual*tasaMensual;
        if (mes==plazoMeses){
            amortizacionMes=saldoActual;
            cuotaActual=amortizacionMes+interesMes;
            saldoActual=0.00;
        }else{
            amortizacionMes=cuotaActual-interesMes;
            saldoActual=saldoActual-amortizacionMes;
        }
        cout<<mes<<"\t"
            <<fixed<<setprecision(2)
            <<cuotaActual<<"\t\t"
            <<interesMes<<"\t\t"
            <<amortizacionMes<<"\t\t"
            <<saldoActual<<endl;
    }
    cout<<"-----------------------------------------------------------------------"<<endl;
    cout<<"Nota: El ultimo mes puede ajustar los centimos para cerrar saldo en 0."<<RESET<<endl;
    cout<<"Fin del reporte."<<endl<<endl;
    break;
}
case 5:
    cout<<"Gracias por usar Bankriel"<<endl;
    break;
    case 6:
        cout<<"Bienvenido a Bankriel"<<endl;
        break;

default:
    cout<<"Opcion invalida, vuelva a intentarlo"<<endl;

    break;
}
}while(OpcionMenu!=5);
}
    return 0; // indica que el programa terminó. Este 0 es el del int del inicio del programa según gemini en el mundo de la programación devolver un 0 significa que todo salió con el programa
}
