#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

double calcularPromedio(double temperaturas[], int n) {
    double suma = 0.0;
    for (int i = 0; i < n; i++) {
        suma += temperaturas[i];
    }
    return suma / n;
}

int encontrarMesMaximo(double temperaturas[], int n) {
    int indiceMax = 0;
    double max = temperaturas[0];
    for (int i = 1; i < n; i++) {
        if (temperaturas[i] > max) {
            max = temperaturas[i];
            indiceMax = i;
        }
    }
    return indiceMax;
}

double encontrarMaximo(double temperaturas[], int n) {
    double max = temperaturas[0];
    for (int i = 1; i < n; i++) {
        if (temperaturas[i] > max) {
            max = temperaturas[i];
        }
    }
    return max;
}

double calcularDesviacionEstandar(double temperaturas[], int n) {
    double promedio = calcularPromedio(temperaturas, n);
    double sumaCuadrados = 0.0;
    
    for (int i = 0; i < n; i++) {
        sumaCuadrados += pow(temperaturas[i] - promedio, 2);
    }
    
    return sqrt(sumaCuadrados / n);
}

int departamentoMayorPromedio(double promedios[], int n) {
    int indiceMax = 0;
    for (int i = 1; i < n; i++) {
        if (promedios[i] > promedios[indiceMax]) {
            indiceMax = i;
        }
    }
    return indiceMax;
}

void encontrarMaximoGlobal(double santander[], double guajira[], double narino[], 
                          int n, double &maxTemp, int &mesDep, int &departamento) {
    maxTemp = santander[0];
    mesDep = 0;
    departamento = 0;
    
    for (int i = 0; i < n; i++) {
        if (santander[i] > maxTemp) {
            maxTemp = santander[i];
            mesDep = i;
            departamento = 0;
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (guajira[i] > maxTemp) {
            maxTemp = guajira[i];
            mesDep = i;
            departamento = 1;
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (narino[i] > maxTemp) {
            maxTemp = narino[i];
            mesDep = i;
            departamento = 2;
        }
    }
}

int main() {
    const int MESES = 12;
    const int DEPARTAMENTOS = 3;
    
    double santander[MESES];
    double guajira[MESES];
    double narino[MESES];
    
    string nombresDep[DEPARTAMENTOS] = {"Santander", "Guajira", "Narino"};
    string nombresMeses[MESES] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio",
                                  "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};
    
    cout << "========================================\n";
    cout << "  SISTEMA ONM - OBSERVATORIO NACIONAL\n";
    cout << "       DE METEOROLOGIA\n";
    cout << "========================================\n\n";
    
    cout << "Ingrese las 12 temperaturas mensuales para SANTANDER:\n";
    for (int i = 0; i < MESES; i++) {
        cout << nombresMeses[i] << ": ";
        cin >> santander[i];
    }
    
    cout << "\nIngrese las 12 temperaturas mensuales para GUAJIRA:\n";
    for (int i = 0; i < MESES; i++) {
        cout << nombresMeses[i] << ": ";
        cin >> guajira[i];
    }
    
    cout << "\nIngrese las 12 temperaturas mensuales para NARINO:\n";
    for (int i = 0; i < MESES; i++) {
        cout << nombresMeses[i] << ": ";
        cin >> narino[i];
    }
    
    double promedioSantander = calcularPromedio(santander, MESES);
    double promedioGuajira = calcularPromedio(guajira, MESES);
    double promedioNarino = calcularPromedio(narino, MESES);
    
    double todas[36];
    for (int i = 0; i < MESES; i++) {
        todas[i] = santander[i];
        todas[i + MESES] = guajira[i];
        todas[i + 2*MESES] = narino[i];
    }
    double promedioNacional = calcularPromedio(todas, 36);
    
    int mesMasCalienteSantander = encontrarMesMaximo(santander, MESES);
    int mesMasCalienteGuajira = encontrarMesMaximo(guajira, MESES);
    int mesMasCalienteNarino = encontrarMesMaximo(narino, MESES);
    
    double maxSantander = encontrarMaximo(santander, MESES);
    double maxGuajira = encontrarMaximo(guajira, MESES);
    double maxNarino = encontrarMaximo(narino, MESES);
    double promedioPicos = (maxSantander + maxGuajira + maxNarino) / 3.0;
    
    double promedios[DEPARTAMENTOS] = {promedioSantander, promedioGuajira, promedioNarino};
    int depMayorPromedio = departamentoMayorPromedio(promedios, DEPARTAMENTOS);
    
    double tempMaxGlobal;
    int mesMaxGlobal, depMaxGlobal;
    encontrarMaximoGlobal(santander, guajira, narino, MESES, tempMaxGlobal, mesMaxGlobal, depMaxGlobal);
    
    double desvEstandarSantander = calcularDesviacionEstandar(santander, MESES);
    double desvEstandarGuajira = calcularDesviacionEstandar(guajira, MESES);
    double desvEstandarNarino = calcularDesviacionEstandar(narino, MESES);
    
    cout << fixed << setprecision(2);
    cout << "\n========================================\n";
    cout << "          INFORME DE RESULTADOS\n";
    cout << "========================================\n\n";
    
    cout << "1. PROMEDIOS ANUALES POR DEPARTAMENTO:\n";
    cout << "   - Santander: " << promedioSantander << " °C\n";
    cout << "   - Guajira: " << promedioGuajira << " °C\n";
    cout << "   - Narino: " << promedioNarino << " °C\n\n";
    
    cout << "2. PROMEDIO NACIONAL: " << promedioNacional << " °C\n\n";
    
    cout << "3. MES MAS CALIENTE POR DEPARTAMENTO:\n";
    cout << "   - Santander: " << nombresMeses[mesMasCalienteSantander] 
         << " (" << santander[mesMasCalienteSantander] << " °C)\n";
    cout << "   - Guajira: " << nombresMeses[mesMasCalienteGuajira] 
         << " (" << guajira[mesMasCalienteGuajira] << " °C)\n";
    cout << "   - Narino: " << nombresMeses[mesMasCalienteNarino] 
         << " (" << narino[mesMasCalienteNarino] << " °C)\n\n";
    
    cout << "4. PROMEDIO DE LOS PICOS: " << promedioPicos << " °C\n\n";
    
    cout << "5. DEPARTAMENTO CON MAYOR PROMEDIO ANUAL: " 
         << nombresDep[depMayorPromedio] << "\n\n";
    
    cout << "6. TEMPERATURA MAXIMA ANUAL GLOBAL: " << tempMaxGlobal << " °C\n";
    cout << "   Departamento: " << nombresDep[depMaxGlobal] << "\n";
    cout << "   Mes: " << nombresMeses[mesMaxGlobal] << "\n\n";
    
    cout << "7. DESVIACION ESTANDAR POR DEPARTAMENTO:\n";
    cout << "   - Santander: " << desvEstandarSantander << " °C\n";
    cout << "   - Guajira: " << desvEstandarGuajira << " °C\n";
    cout << "   - Narino: " << desvEstandarNarino << " °C\n\n";
    
    cout << "========================================\n";
    
    return 0;
}