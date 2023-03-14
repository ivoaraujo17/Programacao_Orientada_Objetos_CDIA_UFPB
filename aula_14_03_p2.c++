#include <iostream>
using namespace std;

class ponto{
    int x;
    int y;

    public:
    ponto(int xx = 0, int yy = 0){
        x = xx;
        y = yy;
    }
};

class canvas{
    int qtd_pontos;
    ponto* pontos;
    //ponto** pontos;
    public:
    canvas(int q){
        qtd_pontos = q;
        pontos = new ponto[q];
        cout << "\nCanvas criado!\n";
    }
};


int main(){
    cout << "\ncanvas star\n";
    canvas c(10);
    cout << "\ncanvas end\n";

}