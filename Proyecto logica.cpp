#include <iostream>
using namespace std;

int const filas = 4;
int const columnas = 5; 

void limpiarMatriz(bool disponibilidad[filas][columnas], float peso[filas][columnas]);
void mostrarDisponibilidad(bool disponibilidad[filas][columnas]);
void llenarMatriz(bool disponibilidad[filas][columnas], string marca[filas][columnas], float peso[filas][columnas], string puertoCarga[filas][columnas], string tipoArticulo[filas][columnas]);
void porcentaje(int acumuladorC);
void totalRecaudado(int cantidadCPuerto, string nombrePuerto, string puertoCarga[filas][columnas]);
void ordenarPuertos(int nPuertos, int cantidadCPuerto[], string nombres[]);
void marcasPremiumYEconomicas(string marca[filas][columnas]);
void buscarEmpresa(string marca[filas][columnas], string buscadorNombreEmpresa);
void promedioContenedoresPeso(float peso[filas][columnas]);
void determinarFilaConMasCarga(float peso[filas][columnas]);
void determinarColumnaConMenosCarga(float peso[filas][columnas]);
void consultaPorArticulo(string tipoArticulo[filas][columnas],string articulo);
void promedioPuertoOrigen(float peso[filas][columnas],string puertoCarga[filas][columnas],string puertoOrigen);
void marcaContenederMasPesado(float peso[filas][columnas], string marca[filas][columnas]);
void contenedorMenosPesado(float peso[filas][columnas]);

int main() {
    int nPuertos = 0;      
    cout << "Ingrese el numero de puertos " << endl;
    cin >> nPuertos;

    string nombres[nPuertos];
    for (int i = 0; i < nPuertos; i++) {
        cout << "Ingresar nombre del puerto " << endl;
        cin >> nombres[i];
    }

    bool disponibilidad[filas][columnas];
    string marca[filas][columnas];
    float peso[filas][columnas];
    string puertoCarga[filas][columnas];
    string tipoArticulo[filas][columnas];

    limpiarMatriz(disponibilidad, peso);

    int cantidadCPuerto[nPuertos];
    int acumuladorC = 0;

    for (int i = 0; i < nPuertos; i++) {
        cout << "Ingrese cantidad de contenedores " << "puerto " << nombres[i] << endl;
        cin >> cantidadCPuerto[i];
        acumuladorC = acumuladorC + cantidadCPuerto[i];

        for (int j = 1; j <= cantidadCPuerto[i]; j++) {
            mostrarDisponibilidad(disponibilidad);
            llenarMatriz(disponibilidad, marca, peso, puertoCarga, tipoArticulo);
        }
        porcentaje(cantidadCPuerto[i]);
        totalRecaudado(cantidadCPuerto[i], nombres[i], puertoCarga);
    } 

    cout << "Total contenedores ingresados " << acumuladorC << endl;

    ordenarPuertos(nPuertos, cantidadCPuerto, nombres);

    marcasPremiumYEconomicas(marca);

    string buscadorNombreEmpresa = "";
    cout << "Ingrese el nombre de la empresa a buscar " << endl;
    cin >> buscadorNombreEmpresa;
    buscarEmpresa(marca, buscadorNombreEmpresa);

    promedioContenedoresPeso(peso);

    determinarFilaConMasCarga(peso);

    determinarColumnaConMenosCarga(peso);

    string articulo = "";
    cout << "Ingrese el tipo de articulo a buscar " << endl;
    cin >> articulo;
    consultaPorArticulo(tipoArticulo,articulo);

    string puertoOrigen = "";
    cout << "Ingrese el puerto a buscar " << endl;
    cin >> puertoOrigen;
    promedioPuertoOrigen(peso,puertoCarga,puertoOrigen);
    marcaContenederMasPesado(peso, marca);
    contenedorMenosPesado(peso);
}

void limpiarMatriz(bool disponibilidad[filas][columnas], float peso[filas][columnas]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            disponibilidad[i][j] = 1;
            peso[i][j] = 0;
        }
    }
}

void mostrarDisponibilidad(bool disponibilidad[filas][columnas]) {
    cout << "Disponibilidad " << endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << disponibilidad[i][j] << " ";
        }
        cout << endl;
    }
}

void llenarMatriz(bool disponibilidad[filas][columnas], string marca[filas][columnas], float peso[filas][columnas], string puertoCarga[filas][columnas], string tipoArticulo[filas][columnas]) {
    bool cordenadaV = false;
    int coordenadaFila = 0;
    int coordenadaColumna = 0;

    while (cordenadaV == false) {
        cout << "Ingrese la coordenada de la fila " << endl;
        cin >> coordenadaFila;
        cout << "Ingrese la coordenada de la columna " << endl;
        cin >> coordenadaColumna;
        if (coordenadaFila >= 0 && coordenadaColumna >= 0 && coordenadaFila < filas &coordenadaColumna < columnas && disponibilidad[coordenadaFila][coordenadaColumna== 1]) {
            disponibilidad[coordenadaFila][coordenadaColumna] = 0;
            cordenadaV = true;
        } else {
            cout << "Verifica tus coordenadas " << endl;
        }
    }

    cout << "Ingrese marca " << endl;
    cin >> marca[coordenadaFila][coordenadaColumna];
    cout << "Ingrese peso " << endl;
    cin >> peso[coordenadaFila][coordenadaColumna];
    cout << "Ingrese puerto de carga " << endl;
    cin >> puertoCarga[coordenadaFila][coordenadaColumna];
    cout << "Ingrese tipo " << endl;
    cin >> tipoArticulo[coordenadaFila][coordenadaColumna];
}

void porcentaje(int acumuladorC) {
    float porcentaje = (acumuladorC*100) / (filas*columnas);
    cout << "El porcentaje es de " << porcentaje << endl;
}

void totalRecaudado(int cantidadCPuerto, string nombrePuerto, string puertoCarga[filas][columnas]) {
    int total = 0;

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (puertoCarga[i][j] == nombrePuerto) {
                if ((i == 1 || i == 2) && (j == 1 || j == 2 || j == 3)) {
                    total = total + 300;
                } else {
                    total = total + 100;
                }
            }
        }
    }

    cout << "El total recaudado es de " << total << endl;
}


void ordenarPuertos(int nPuertos, int cantidadCPuerto[], string nombres[]) {
    for (int i = 0; i < nPuertos; i++) {
        for (int j = 0; j < nPuertos; j++) {
            if (cantidadCPuerto[i] > cantidadCPuerto[j]) {
                int aux = cantidadCPuerto[i];
                cantidadCPuerto[i] = cantidadCPuerto[j];
                cantidadCPuerto[j] = aux;
                
                string aux2 = nombres[i];
                nombres[i] = nombres[j];
                nombres[j] = aux2;
            }
        }
    }
    
    for (int i = 0; i < nPuertos; i++) {
        cout << "El puerto " << nombres[i] << " tiene " << cantidadCPuerto[i] << " contenedores" << endl;
    }
}

void marcasPremiumYEconomicas(string marca[filas][columnas]) {
    string economicas = "";
    string premium = "";

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (marca[i][j] != "") {
                if ((i == 1 || i == 2) && (j == 1 || j == 2 || j == 3)) {
                    premium = premium + ", " + marca[i][j];
                } else {
                    economicas = economicas + ", " + marca[i][j];
                }
            }
        }
    }

    cout << "Las sigueintes marcas son de la zona economica " << economicas << endl; 
    cout << "Las sigueintes marcas son de la zona premium " << premium << endl; 
}

void buscarEmpresa(string marca[filas][columnas], string buscadorNombreEmpresa) {
    int valorPagar = 0;
    int contadorZonaEconomica = 0;
    int contadorZonaPremium = 0;

    for(int i = 0; i < filas; i++) {
        for(int j = 0; j < columnas; j++) {
            if(marca[i][j] == buscadorNombreEmpresa) {
                if( i == 1 || i == 2 && j == 1 || j == 2 || j == 3) {
                    contadorZonaPremium = contadorZonaPremium + 1;
                    valorPagar = valorPagar + 300;
                } else {
                    contadorZonaEconomica = contadorZonaEconomica + 1;
                    valorPagar = valorPagar + 100;
                }
            }
        }
    }

    cout << "La marca tiene " << contadorZonaEconomica << " contenedores en economicas" << endl;
    cout << "La marca tiene " << contadorZonaPremium << " contenedores en premium" << endl;
    cout << "El valor a pagar es " << valorPagar << endl;
}

void promedioContenedoresPeso(float peso[filas][columnas]){
    float suma = 0;
    float totalContenedores = 0;
    float promedio = 0;

    for(int i = 0; i < filas; i++) {
        for(int j = 0; j < columnas; j++) {
            if(peso[i][j] != 0) {
                suma = suma + peso[i][j];
                totalContenedores = totalContenedores + 1;
            }
        }
    }

    promedio = suma / totalContenedores;

    cout << "El promedio es de " << promedio << endl;
}

void determinarFilaConMasCarga(float peso[filas][columnas]){
    int sumaValores = 0;
    int pesoFila = INT_MIN;
    int filaCarga = -1;

    for (int i = 0; i < filas; i++) {
        sumaValores = 0;
        for (int j = 0; j < columnas; j++) {
            sumaValores =  sumaValores + peso[i][j];
        }
        if (sumaValores > pesoFila && sumaValores != 0) {
            pesoFila = sumaValores;
            filaCarga = i;
        }
    }
    
    cout << "La fila mas carga es la " << filaCarga << endl;
}

void determinarColumnaConMenosCarga(float peso[filas][columnas]){
    int sumaValores = 0;
    int pesoFila = INT_MAX;
    int columnaCarga = -1;

    for (int j = 0; j < columnas; j++) {
        sumaValores = 0;
        for (int i = 0; i < filas; i++) {
            sumaValores =  sumaValores + peso[i][j];
        }
        if (sumaValores < pesoFila && sumaValores != 0) {
            pesoFila = sumaValores;
            columnaCarga = j;
        }
        
    }
    
    cout << "la columna con menos carga es la " << columnaCarga << endl;
}

void consultaPorArticulo(string tipoArticulo[filas][columnas],string articulo){
    int contadorContenedoresArticulo = 0;

    for(int i = 0; i < filas; i++) {
        for(int j = 0; j < columnas; j++) {
            if(tipoArticulo[i][j]==articulo){
                contadorContenedoresArticulo = contadorContenedoresArticulo + 1;
            }
        }
    }

    cout << "El articulo tiene " << contadorContenedoresArticulo << " contenedores" << endl; 
}

void promedioPuertoOrigen(float peso[filas][columnas],string puertoCarga[filas][columnas],string puertoOrigen){
    int contadorTotalContenedores = 0;
    int suma = 0;
    float promedio = 0;
    for(int i = 0; i < filas; i++) {
        for(int j = 0; j < columnas; j++) {
            if(puertoCarga[i][j]==puertoOrigen){
                suma = suma + peso[i][j];
                contadorTotalContenedores = contadorTotalContenedores + 1;
            }
        }
    }

    promedio = suma / contadorTotalContenedores;

    cout << "El promedio de peso ingresado es de " << promedio << endl; 
}

void marcaContenederMasPesado(float peso[filas][columnas], string marca[filas][columnas]) {
    string marcaMasPesada = "";
    float pesoMasPesado = __FLT_MIN__;
    for(int i = 0; i < filas; i++) {
        for(int j = 0; j < columnas; j++) {
            if(peso[i][j] > pesoMasPesado){
                pesoMasPesado = peso[i][j];
                marcaMasPesada = marca[i][j];               
            }
        }
    }

    cout << "La marca con mas peso es la " << marcaMasPesada << endl;
}

void contenedorMenosPesado(float peso[filas][columnas]) {
    float pesoMenor = __FLT_MAX__;
    for(int i = 0; i < filas; i++) {
        for(int j = 0; j < columnas; j++) {
            if(peso[i][j] < pesoMenor && peso[i][j] != 0){
                pesoMenor = peso[i][j];           
            }
        }
    }

    cout << "El peso menos pesado" << pesoMenor<< endl;
}
