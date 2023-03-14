#include <iostream>

using namespace std;

class aluno{
    int matriculas;
    float cra;
    public:
        aluno(int matricula_inicial, float cra_inicial){
            matriculas = matricula_inicial;
            cra = cra_inicial;
            cout << "Aluno criado com sucesso!" << endl;
        }
        int get_matricula(){
            return matriculas;
        }
        float get_cra(){
            return cra;
        }
        void set_matricula(int nova_matricula){
            matriculas = nova_matricula;
        }
        void set_cra(float novo_cra){
            cra = novo_cra;
        }
        ~aluno(){
            cout << "aluno " << matriculas << " finalizado!" << endl;
        }
};

int main(){
    aluno a1(1012, 8.9), a2(1013, 7.8);
    cout << "matriculas aluno 1: " << a1.get_matricula() << endl;
    cout << "matriculas aluno 2: " << a2.get_matricula() << endl;
    cout << "cra aluno 1: " << a1.get_cra() << endl;
    cout << "cra aluno 2: " << a2.get_cra() << endl;
    return 0;
}
