#include <iostream>
#include <string>

#define MAX_ALUNOS 10
#define MAX_AULAS 10
using namespace std;

class pessoa{
    private:
        string nome;
        int idade;
        string cpf;

    public:
        pessoa(const string& n, int i, const string& c){
            nome =n;
            idade = i;
            cpf = c;
        }
        string get_nome(){
            return nome;
        }
        /*aqui iria ser criados os gets e sets dos atributos*/
};

/*na classe instrutor usei herança visto que ele é um tipo de pessoa*/
class instrutor : public pessoa{
    private: 
        float salario;
    
    public:
        instrutor(const string& n, int i, const string& c, float s):pessoa(n,i,c){
            salario = s;
        }
        /*aqui continuaria os gets e sets*/
};

/*aluno também vai hedar de pessoa, pois é um objeto do tipo de*/
class aluno : public pessoa{
    private:
        float mensalidade;

    public:
        aluno(const string& n, int i, const string& c, float m):pessoa(n,i,c){
            mensalidade = m;
        }
};

/*ja a classe aula vai ser construida composta de instrutor e aluno, todo parte, um
instrutor faz parte de uma ou mais aulas, assim como os alunos*/
class aula{
    private:
        string nome;
        string horario;
        float duracao;
        instrutor* instrutor1;
        aluno* alunos[MAX_ALUNOS];
        int qtd_alunos;
    public:
        /*como utilizei alocação do vetor de alunos fixo, não e necessario construir
        o metodo destrutor*/
        aula(const string& n, const string& h, float d, instrutor* inst){
            nome = n;
            horario = h;
            duracao = d;
            instrutor1 = inst;
            qtd_alunos = 0;
        }
        void print_info(){
            cout << "\nNome da Aula: " << nome;
            cout << "\nHorario: " << horario;
            cout << "\nDuracao: " << duracao;
            cout << "\nInstrutor: " << instrutor1->get_nome();
            cout << "\nLista de alunos da aula";
            for(int i = 0; i < qtd_alunos; i++){
                cout << "\n" << alunos[i]->get_nome();
            }
        }
        void adicionar_aluno(aluno* a){
            if (qtd_alunos > MAX_ALUNOS){
                cout << "A aula atingiu o limite de alunos";
            }
            else{
                alunos[qtd_alunos] = a;
                qtd_alunos += 1;
            }
        }
        /*aqui teria os metodos de remover aluno, e get e sets da classe aula*/
};

/*classe academia vai ser construida através da composicao de varias aulas*/
class academia{
    private:
        aula* aulas[MAX_AULAS];
        int qtd_aulas;
    public:
        /*como utilizei alocação do vetor de aula fixo, não e necessario construir
        o metodo destrutor*/
        academia(){
            qtd_aulas = 0;
        }

        void adicionar_aula(aula* a){
            if (qtd_aulas > MAX_AULAS){
                cout << "\nA academia atingiu o numero maximo de aulas";
            }
            else{
                aulas[qtd_aulas] = a;
                qtd_aulas += 1;
                cout << "\naula adicionada com sucesso!";
            }
        }
        void listar_aulas(){
            for(int i=0; i < qtd_aulas; i++){
                aulas[i]->print_info();
            }
        }
        /*aqui iria ser criado o metodo de remover aulas, gets e sets*/              
};

int main(){
    /*criando o instrututor da aula*/
    instrutor instrutor_aula("Joao", 35, "123456789-00", 5000.0);
    /*Criando os aluno*/
    aluno aluno1("Maria", 25, "987654321-00", 1000.0);
    aluno aluno2("Pedro", 30, "555444333-00", 1200.0);
    aluno aluno3("Ana", 20, "111222333-00", 1500.0);

    /*criando a aula*/
    aula aula1("Pilates", "10:00", 1.5, &instrutor_aula);

    /*adicionando os alunos na aula*/
    aula1.adicionar_aluno(&aluno1);
    aula1.adicionar_aluno(&aluno2);
    aula1.adicionar_aluno(&aluno3);

    // Criando objeto academia
    academia academia1;

    // Adicionando aula na academia
    academia1.adicionar_aula(&aula1);

    // Listando informações das aulas na academia
    academia1.listar_aulas();
    return 0;
}
