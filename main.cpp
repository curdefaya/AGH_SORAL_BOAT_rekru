#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std; 

class Ksztalt {
public:
    string Rodzaj;
    int Wymiar;
    int Kolejnosc;

    Ksztalt() : Rodzaj(""), Wymiar(0), Kolejnosc(0) {}

    Ksztalt(string a, int b, int c) { 
        Rodzaj = a; 
        Wymiar = b; 
        Kolejnosc = c; 
    }

    void rysowanie() const {
        if (Rodzaj == "Square") {
            for (int i = 0; i < Wymiar; i++) {
                for (int j = 0; j < Wymiar; j++) {
                    if (i == 0 || i == Wymiar - 1 || j == 0 || j == Wymiar - 1) {
                        cout << "#";
                    } else {
                        cout << " ";
                    }
                }
                cout << "\n";
            }
        } 
        else if (Rodzaj == "Circle") {
            for (int i = 0; i < Wymiar; i++) {
                for (int j = 0; j < Wymiar; j++) {
                    cout << "#";
                }
                cout << "\n";
            }
        } 
        else if (Rodzaj == "Triangle") {
            for (int i = 1; i <= Wymiar; i++) {
                for (int j = 0; j < i; j++) {
                    cout << "#";
                }
                cout << "\n";
            }
        } 
        else {
            for (int i = 0; i < Wymiar; i++) {
                cout << "#\n";
            }
        }
        cout << "\n"; 
    }
};

bool sprawdzKsztalty(const Ksztalt& a, const Ksztalt& b) {
    return a.Kolejnosc < b.Kolejnosc;
}

int main() {
    ifstream odczyt("dane.txt");
    
    if (!odczyt.is_open()) {
        cerr << "nie otwarto pliku" << endl;
        return 1;
    }

    int n;
    odczyt >> n;
    vector<Ksztalt> ksztalty;

    for (int i = 0; i < n; i++) {
        string rodzaj;
        int wymiar, kolejnosc;
        odczyt >> rodzaj >> wymiar >> kolejnosc;
        ksztalty.push_back(Ksztalt(rodzaj, wymiar, kolejnosc));
    }
    
    odczyt.close();

    sort(ksztalty.begin(), ksztalty.end(), sprawdzKsztalty);

    for (const auto& k : ksztalty) {
        k.rysowanie();
    }

    return 0;
}