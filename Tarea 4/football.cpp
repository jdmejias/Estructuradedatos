//JHON DEIBY MEJIAS
//8964584
//football.cpp
// En general, la complejidad es O(NMlogN), esto se debe a que el código realiza dos bucles principales, donde N es la cantidad de equipos y M es la cantidad de partidos, sin embargo, la función sort tiene una complejidad O(NlogN), lo cual con esto ultimo hace que el programa tenga una complejidad superior.
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//funcion para que me ordene y no  afecte las mayusculas
        string pasar_minusculas(const string& palabra) {
        string result = "";
        for (auto it = palabra.begin(); it != palabra.end(); ++it) {
            char itera = *it;
            if (itera >= 'A' && itera <= 'Z') {
                itera += 'a' - 'A';
            }
            result += itera;
        }
        return result;
    }
//cree una clase para crear mas facil los equipos con un vector
class Equipos {
public:
        string nombre;
        int puntos;
        int partidosjugados;
        int golesafavor;
        int golesencontra;
        int diferencia;
        double porcentaje;

        Equipos(string nombre){
            this-> nombre = nombre;
            puntos=0;
            partidosjugados=0;
            golesafavor=0;
            golesencontra=0;
            diferencia=0;
            porcentaje=0.00;}
            //sobrecargar el operador para ordenar
            bool operator <(const Equipos& equipo) const {
                bool ans = 1;
                if (puntos != equipo.puntos) {
                    ans = puntos > equipo.puntos;
                } else if (diferencia != equipo.diferencia) {
                    ans = diferencia > equipo.diferencia;
                } else if (golesafavor != equipo.golesafavor) {
                    ans = golesafavor > equipo.golesafavor;
                } else {
                    // Convertir ambos nombres a minúsculas antes de comparar
                    string minusculas = pasar_minusculas(nombre);
                    string minusculasxd = pasar_minusculas(equipo.nombre);
                    ans = minusculas < minusculasxd;
                }
                return ans;
            }
   
    };

int main() {
    int can_equipos=0;
    int partidos=0;
    int local;
    int visitante;
    vector<int> igualados;
    string nojugo= "N/A";
    string nameequipos;
    string match[3];
    vector<Equipos> candidatos;
    vector<string> repetidos;
    scanf("%d %d",&can_equipos,&partidos); 
    while(can_equipos!=0 && partidos!=0){
        int i=0;
        candidatos.clear();
        igualados.clear();
        repetidos.clear();
        // Esto de repetido lo hice por unos casos de prueba, pero no era necesario.
        //Colocar en el vector los equipos que introduzca si son repeditos colocar el nombre en un vector repetido
        for(int i=0; i<can_equipos;i++){ 
            cin >> nameequipos; 
            bool repetido = false; 
            for(vector<Equipos>::iterator it = candidatos.begin(); it != candidatos.end(); it++) { 
                if(it->nombre == nameequipos){ 
                    repetido = true; 
                    repetidos.push_back(it->nombre); 
                } 
            } 
            if(!repetido) 
                candidatos.push_back(Equipos(nameequipos)); 
        } 
        
        //Dar los puntos a cada equipo
        for(int i=0; i<partidos;i++){
            cin >> match[0] >> local >> match[1] >> visitante >> match[2];
            if (local > visitante){
                for(vector<Equipos>::iterator it = candidatos.begin(); it != candidatos.end(); it++) {
                    if (it->nombre == match[0]) {
                        it->puntos += 3;
                        it->partidosjugados += 1;
                        it->golesafavor += local;
                        it->golesencontra += visitante;
                        it->diferencia = it->golesafavor - it->golesencontra;
                        it->porcentaje =((it->puntos)*100.00/(it->partidosjugados*3.00));
                    }
                    else if (it->nombre == match[2]) {
                        it->puntos += 0;
                        it->partidosjugados += 1;
                        it->golesafavor += visitante;
                        it->golesencontra += local;
                        it->diferencia = it->golesafavor - it->golesencontra;
                        it->porcentaje =((it->puntos)*100.00/(it->partidosjugados*3.00));
                    }
            
                }
            }
            else if (local < visitante) {
                for(vector<Equipos>::iterator it = candidatos.begin(); it != candidatos.end(); it++) {
                    if (it->nombre == match[0]) {
                        it->puntos += 0;
                        it->partidosjugados += 1;
                        it->golesafavor += local;
                        it->golesencontra += visitante;
                        it->diferencia = it->golesafavor - it->golesencontra;
                        it->porcentaje =((it->puntos)*100.00/(it->partidosjugados*3.00));
                    }
                    else if (it->nombre == match[2]) {
                        it->puntos += 3;
                        it->partidosjugados += 1;
                        it->golesafavor += visitante;
                        it->golesencontra += local;
                        it->diferencia = it->golesafavor - it->golesencontra;
                        it->porcentaje =((it->puntos)*100.00/(it->partidosjugados*3.00));
                    }
                }
            }
            else {
                for(vector<Equipos>::iterator it = candidatos.begin(); it != candidatos.end(); it++) {
                    if (it->nombre == match[0]) {
                        it->puntos += 1;
                        it->partidosjugados += 1;
                        it->golesafavor += local;
                        it->golesencontra += visitante;
                        it->diferencia = it->golesafavor - it->golesencontra;
                        it->porcentaje =((it->puntos)*100.00/(it->partidosjugados*3.00));
                    }
                    else if (it->nombre == match[2]) {
                        it->puntos += 1;
                        it->partidosjugados += 1;
                        it->golesafavor += local;
                        it->golesencontra += visitante;
                        it->diferencia = it->golesafavor - it->golesencontra;
                        it->porcentaje =((it->puntos)*100.00/(it->partidosjugados*3.00));
                    }
                    
                }
            }    }
            //añadir al vector los repetidos.
        for(vector<string>::iterator it = repetidos.begin(); it != repetidos.end(); it++) { 
            candidatos.insert(candidatos.end(), Equipos(*it)); 
        } 

        //ordenar el vector
        sort(candidatos.begin(), candidatos.end());
        //cree un vector igualados, con el objetivo de identificar cuales posiciones estan empatadas
        for(vector<Equipos>::iterator it = candidatos.begin(); it != candidatos.end(); it++) {
            if (it->puntos== ((it-1)->puntos) && it->diferencia==((it-1)->diferencia) && it->golesafavor==((it-1)->golesafavor)) {
                igualados.push_back(1);
            }
            else{
                igualados.push_back(0);
            }
            }
        //cree dos casos, uno donde hay equipos que no juegan para poder imprimir el N/A y el otro if es para imprimir los numeros de la posicion del equipo
        for(vector<Equipos>::iterator it = candidatos.begin(); it != candidatos.end(); it++) {
            if(it->partidosjugados!=0){
                if (igualados[i] == 0) {
                    printf("%2d%s %15s %3d %3d %3d %3d %3d %6.2f\n", i+1, ".", candidatos[i].nombre.c_str(), candidatos[i].puntos, candidatos[i].partidosjugados, candidatos[i].golesafavor, candidatos[i].golesencontra, candidatos[i].diferencia, candidatos[i].porcentaje);
                }
                else {
                    printf("%19s %3d %3d %3d %3d %3d %6.2f\n", candidatos[i].nombre.c_str(), candidatos[i].puntos, candidatos[i].partidosjugados, candidatos[i].golesafavor, candidatos[i].golesencontra, candidatos[i].diferencia, candidatos[i].porcentaje);
                }
                }
            else{
                if (igualados[i] == 0) {
                    printf("%2d%s %15s %3d %3d %3d %3d %3d %6s\n", i+1, ".", candidatos[i].nombre.c_str(), candidatos[i].puntos, candidatos[i].partidosjugados, candidatos[i].golesafavor, candidatos[i].golesencontra, candidatos[i].diferencia, nojugo.c_str());
                }
                else {
                    printf("%19s %3d %3d %3d %3d %3d %6s\n", candidatos[i].nombre.c_str(), candidatos[i].puntos, candidatos[i].partidosjugados, candidatos[i].golesafavor, candidatos[i].golesencontra, candidatos[i].diferencia, nojugo.c_str());
                }
            }
            i++; 
        }           
        cout << endl;
        scanf("%d %d",&can_equipos,&partidos); 

        }
    return 0;
}   