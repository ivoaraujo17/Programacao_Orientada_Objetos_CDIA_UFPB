#include <iostream>


using namespace std;

class pessoa{
    private:
        string nome;
        int idade;
    public:
        /*construtor da classe pessoa, recebendo os parametros de nome e idade*/
        pessoa(const string c, int i){
            nome = c;
            idade = i;
        }
        /*set e gets dos atributos da classe pessoa*/
        void set_nome(const string c){
            nome = c;
        }
        void set_idade(int i){
            idade = i;
        }
        string get_nome(){return nome;}
        int get_idade(){return idade;}
        /*print info virtual para chamar o print info da classe filho quando 
        for requisitada a partir de um objeto que herda de pessoa*/
        virtual void print_info(){
            cout << "\nPessoa::nome: " << nome << endl;
            cout << "Pessoa::idade: " << idade << endl;
        }
};

/*funcionario herdando de pessoa, criando uma herança do (tipo de) pessoa  */
class funcionario : public pessoa{
    private:
        float salario;
        int cargo;
        static int qtd_funcionario;
    public:
        /*construtor de funcionario, passando os paramentros necessarios
        para o construtor da classe pessoa*/
        funcionario(const string n, int i, float s, int c):pessoa(n, i){
            salario = s;
            cargo = c;
            qtd_funcionario ++;
        }
        /*get e set dos atributos de funcionarios*/
        void set_salario(float s){
            salario = s;
        }
        void set_cargo(int c){
            cargo = c;
        }
        float get_salario(){return salario;}
        int get_cargo(){return cargo;}
        /*print info que vai chamar o print info de pessoa, para exibir as
        informações relacionadas a pessoa, e logo em seguida exibir as informaçoes
        relaciondas ao funcionario*/
        void print_info(){
            pessoa::print_info();
            cout << "Funcionario::salario: " << salario << endl;
            cout << "Funcionario::cargo: " << cargo << endl;
        }
        /*metodo estatico para obter a quantidade de funcionario criado*/
        static int get_qtd_funcionarios(){return qtd_funcionario;}
};

/*gerente herda de funcionario, criando um herança do (tipo de) funcionario
e por consequencia um tipo de pessoa*/
class gerente : public funcionario{
    private:
        int setor;

    public:
        /*metodo construtor de gerente, passando os paramentros necessaerios
        para o construtor de funcionario, que por sua vez chamara o construtor
        de pessoa*/
        gerente(const string n, int i, float s, int c, int se):funcionario(n,i,s,c){
            setor = se;
        }
        /*get e set dos atributos de gerente*/
        void set_setor(int se){
            setor = se;
        }
        int get_setor(){return setor;}
        /*print info, que chama o print infor de funcionario, que por sua
        vez chama o de pesssoa, e apos exibir as informações de pessoa e 
        funcionario, exibi as informações relacionadas ao gerente*/
        void print_info(){
            funcionario::print_info();
            cout << "Gerente::setor: " << setor << endl;
        }
};


int funcionario::qtd_funcionario = 0;

int main(){
    /*criando 1 pessoa, 2 funcionarios, e 2 gerentes*/
    pessoa x("pessoa x", 25);
    funcionario ivo("ivo", 21, 2200.00, 5);
    funcionario bidu("bidu", 37, 12575.50, 18);
    gerente bruno("bruno", 35, 18400.99, 20, 2);
    gerente gilberto("gilberto", 38, 15000.35, 7, 1);
    
    /*adicionando em vetor de ponteiro para pessoa*/
    pessoa* lista_pessoas[5];
    lista_pessoas[0] = &x;
    lista_pessoas[1] = &ivo;
    lista_pessoas[2] = &bidu;
    lista_pessoas[3] = &bruno;
    lista_pessoas[4] = &gilberto;

    /*buscando a quantidade de funcionarios criados*/
    cout << "Quantidade de funcionarios: " << funcionario::get_qtd_funcionarios();
    /*chamando o print info de cada instancia*/
    for (int i=0; i<5; i++){
        lista_pessoas[i]->print_info();
    }
    return 0;
}