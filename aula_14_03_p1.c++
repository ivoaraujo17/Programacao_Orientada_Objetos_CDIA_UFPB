#include <iostream>
using namespace std;

class turma{
    int codigo;
    int* matriculas;
    int qtd_matricula;

    public:
    turma(int c, int q){
        codigo = c;
        qtd_matricula = q;
        matriculas = (int*)malloc(q*sizeof(int));
        cout << "Turma criada!\n";
    }

    int add_matricula(int m, int pos){
        if (pos >= qtd_matricula){
            return -1;
        }
        else{
            matriculas[pos] = m;
            return pos;
        }
    }

    int get_matricula(int pos){
        if (pos >= qtd_matricula){
            return -1;
        }
        else{
            return matriculas[pos];
        }
    }

    int get(){
        return codigo;
    }

    void set_codigo(int c){
        codigo = c;
    }

    int get_qtd_matricula(){
        return qtd_matricula;
    }

    void set_qtd_matricula(int q){
        int* new_mat = (int*)malloc(q*sizeof(int));
        if (q>qtd_matricula){
            for (int i = 0; i < qtd_matricula; i++){
                new_mat[i] = matriculas[i];
            }
        }
        else{
            for (int i = 0; i<q; i++){
                new_mat[i] = matriculas[i];
            }
        }
        matriculas = new_mat;
        qtd_matricula = q;
    }

    void display(){
        for (int i = 0; i < qtd_matricula; i++){
            cout << "|" << matriculas[i] << "|\n";
        }
    }

    ~turma(){
        free(matriculas);
        cout << "\nTurma finalizada!";
    }
};


int main(){
    turma t(1011, 30);
    t.add_matricula(1324, 0);
    t.add_matricula(4563, 1);
    t.display();
    t.set_qtd_matricula(10);
    t.display();
}