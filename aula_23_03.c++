#include <iostream>

using namespace std;

class coisa{
    int x;
    public:
        coisa(){
            cout << "\ncoisa criada!\n";
        }
        ~coisa(){
            cout << "\ncoisa destruida\n";
        }
        int get_x(){
            return x;
        }
        void set_x(int v){
            x = v;
        }
};

void muda_coisa(coisa* c){
    cout << "\nendereco: " << c << endl;
    c->set_x(1000);
}

int main(){
    coisa co;
    muda_coisa(&co);
    cout << "\nvalor: " << co.get_x();
    return 1;
}