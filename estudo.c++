#include <iostream>
#include <string>

#define MAX_FUNC 10
#define MAX_DEPART 10

using namespace std;

class Funcionario{
    private:
        string nome;
        string cpf;
        int idade;
        float salario;
    public:
        Funcionario(const string& n, const string& c, int i, float s){
            nome = n;
            cpf = c;
            idade = i;
            salario = s;
        }
        void print_info(){
            cout << "\n======================================\n";
            cout << "Nome: " << nome << endl;
            cout << "Idade: " << idade << endl;
            cout << "Salario: " << salario << endl;
            cout << "Cpf: " << cpf << endl;
            cout << "\n======================================\n";
        }
        void set_salario(float s){
            salario = s;
        }
        float get_salario(){
            return salario;
        }
};  

class Departamento{
    private:
        string nome;
        int codigo;
        Funcionario* funcionarios[MAX_FUNC];
        int qtd_func;
    public:
        Departamento(const string& n, int c){
            nome = n;
            codigo = c;
            qtd_func = 0;
        }
        void add_funcionario(Funcionario* f, int i){
            if (qtd_func < MAX_FUNC){
                funcionarios[i] = f;
                qtd_func += 1;
            }
            else{
                cout << "Departamento::add_funcionario() ERROR!\n";
            }
        }
        Funcionario* get_funcionario(int i){
            return funcionarios[i];
        }
        void print_info(){
            cout << "\n======================================\n";
            cout << "Nome: " << nome << endl;
            cout << "Codigo: " << codigo << endl;
            cout << "Qtd_Funcionarios" << qtd_func << endl;
            for (int i = 0; i<100;i++){
                funcionarios[i]->print_info();
                cout << "-------" << endl;
            }
            cout << "\n======================================\n";
        }
};

class Empresa{
    private:
        string nome;
        string cnpj;
        Departamento* departamentos[MAX_DEPART];
        int qtd_dep;
    public:
        Empresa(const string& n, const string& c){
            nome = n;
            cnpj = c;
            qtd_dep = 0;
        }
        void add_departamento(Departamento* d, int i){
            if (qtd_dep < MAX_DEPART){
                departamentos[i] = d;
                qtd_dep += 1;
            }
            else{
                cout << "Empresa::add_derpatamento() ERROR!\n";
            }
        }
        Departamento* get_departamento_codigo(){
            for (int i = 0; i<qtd_dep, i++){

            }
        }
        void print_info(){
            cout << "\n======================================\n";
            cout << "Nome: " << nome << endl;
            cout << "Cnpj: " << cnpj << endl;
            cout << "Qtd_departamento" << qtd_dep << endl;
            
            for (int i = 0; i<100;i++){
                departamentos[i]->print_info();
            }
            cout << "\n======================================\n";
        } 
};

int main(){
    Empresa codepyvision("CodepyVision", "1988.12739.12883-98");
    Departamento data_scince("Data_Science", 1324);
    Departamento performance("Performance e projetos estrtégicos", 1623);

    Funcionario ivo("Ivo", "125757684746", 22, 2450);
    Funcionario f1("f1", "25657863", 25, 2463);
    Funcionario f2("f2", "35467567", 28, 3556);
    Funcionario f3("f3", "1346465768", 21, 5341);
    Funcionario f4("f4", "1535789754", 24, 4556);

    codepyvision.add_departamento(&data_scince, 0);
    codepyvision.add_departamento(&performance, 1);

    data_scince.add_funcionario(&ivo, 0);
    data_scince.add_funcionario(&f1, 1);
    data_scince.add_funcionario(&f2, 2);

    performance.add_funcionario(&f3, 3);
    performance.add_funcionario(&f4, 4);



    ivo.print_info();
}