
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <vector>
#include <map>
#include <chrono>
#include <random>
#include <cstdlib>
#include <cctype>
#include <chrono>
#include <list>

using std::string;
using std::cout;

using std::vector;
using std::map;
using std::mt19937;

typedef std::uniform_int_distribution<int>  int_distribution;
using hrClock = std::chrono::high_resolution_clock;

struct zmogus {
    string vardas, pavarde;
};

char lytis() {
    mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
    int_distribution dist(0, 1);

    if (0 == dist(mt)) {
        return 'v';
    }
    else {
        return 'm';
    }
}

int rand_number() {
    mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
    int_distribution dist(1, 10);

    return dist(mt);
}

zmogus gen_map(char lytis) {

    mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
    int_distribution dist(100, 109);

    zmogus a;
    if (lytis == 'v') {
        map<int, string> vardai, pavardes;
        vardai[100] = "Vytautas";
        vardai[101] = "Tomas";
        vardai[102] = "Lukas";
        vardai[103] = "Deividas";
        vardai[104] = "Mantas";
        vardai[105] = "Petras";
        vardai[106] = "Jonas";
        vardai[107] = "Dominykas";
        vardai[108] = "Darius";
        vardai[109] = "Simas";

        a.vardas = vardai[dist(mt)];

        pavardes[200] = "Kazlauskas";
        pavardes[201] = "Petrauskas";
        pavardes[202] = "Jankauskas";
        pavardes[203] = "Ramanauskas";
        pavardes[204] = "Urbonas";
        pavardes[205] = "Venclovas";
        pavardes[206] = "Vasiliauskas";
        pavardes[207] = "Pocius";
        pavardes[208] = "Paulauskas";
        pavardes[209] = "Navickas";

        a.pavarde = pavardes[dist(mt) + 100];
    }
    else {
        map<int, string> vardai, pavardes;
        vardai[100] = "Monika";
        vardai[101] = "Toma";
        vardai[102] = "Luka";
        vardai[103] = "Irma";
        vardai[104] = "Lina";
        vardai[105] = "Kristina";
        vardai[106] = "Jovita";
        vardai[107] = "Dominyka";
        vardai[108] = "Ona";
        vardai[109] = "Egle";

        a.vardas = vardai[dist(mt)];

        pavardes[200] = "Kazlauskaite";
        pavardes[201] = "Petrauskaite";
        pavardes[202] = "Jankauskaite";
        pavardes[203] = "Ramanauskaite";
        pavardes[204] = "Urbonaite";
        pavardes[205] = "Venclovaite";
        pavardes[206] = "Vasiliauskaite";
        pavardes[207] = "Povilaite";
        pavardes[208] = "Paulauskaite";
        pavardes[209] = "Navickaite";

        a.pavarde = pavardes[dist(mt) + 100];

    }

    return a;
}
void generator_of_students(int students, string file_name) {
    std::ofstream myfile;
    myfile.open(file_name);

    for (int i = 1; i < students + 1; i++) {
        char lytis_char = lytis();
        myfile << gen_map(lytis_char).vardas << " " << gen_map(lytis_char).pavarde;
        for (int j = 0; j < 5; j++) {
            myfile << " ";
            myfile << rand_number();
        }
        myfile << " " << rand_number();
        myfile << "\n";
    }
    myfile.close();

}
int main() {

    cout << "Generuojame 1000 irasu\n";
    generator_of_students(1000, "studentai_1k.txt");

    cout << "Generuojame 10000 irasu\n";
    generator_of_students(10000, "studentai_10k.txt");

    cout << "Generuojame 100000 irasu\n";
    generator_of_students(100000, "studentai_100k.txt");

    cout << "Generuojame 1000000 irasu\n";
    generator_of_students(1000000, "studentai_1kk.txt");

    cout << "Generuojame 10000000 irasu\n";
    generator_of_students(10000000, "studentai_10kk.txt");

    return 0;
}
