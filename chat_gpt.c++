#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Pessoa {
  private:
    string nome;
    int idade;
    string cpf;
    string telefone;
  
  public:
    Pessoa(string n, int i, string c, string t) {
      nome = n;
      idade = i;
      cpf = c;
      telefone = t;
    }

    string getNome() {
      return nome;
    }

    void setNome(string n) {
      nome = n;
    }

    int getIdade() {
      return idade;
    }

    void setIdade(int i) {
      idade = i;
    }

    string getCpf() {
      return cpf;
    }

    void setCpf(string c) {
      cpf = c;
    }

    string getTelefone() {
      return telefone;
    }

    void setTelefone(string t) {
      telefone = t;
    }
};

class Aluno : public Pessoa {
  private:
    string nomeCurso;
    string codigo;
  
  public:
    Aluno(string n, int i, string c, string t, string nc, string cod) : Pessoa(n, i, c, t) {
      nomeCurso = nc;
      codigo = cod;
    }

    string getNomeCurso() {
      return nomeCurso;
    }

    void setNomeCurso(string nc) {
      nomeCurso = nc;
    }

    string getCodigo() {
      return codigo;
    }

    void setCodigo(string cod) {
      codigo = cod;
    }
};

class Professor : public Pessoa {
  private:
    string matriculaSiape;
    string formacao;
  
  public:
    Professor(string n, int i, string c, string t, string ms, string f) : Pessoa(n, i, c, t) {
      matriculaSiape = ms;
      formacao = f;
    }

    string getMatriculaSiape() {
      return matriculaSiape;
    }

    void setMatriculaSiape(string ms) {
      matriculaSiape = ms;
    }

    string getFormacao() {
      return formacao;
    }

    void setFormacao(string f) {
      formacao = f;
    }
};
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ... Definição das classes Pessoa, Aluno e Professor ...

int main() {
  // Criando objetos do tipo Pessoa
  Pessoa p1("Joao Silva", 25, "123.456.789-00", "(11) 1234-5678");
  Pessoa p2("Maria Souza", 30, "987.654.321-00", "(11) 9876-5432");

  // Imprimindo informações das pessoas
  cout << "Nome: " << p1.getNome() << endl;
  cout << "Idade: " << p1.getIdade() << endl;
  cout << "CPF: " << p1.getCpf() << endl;
  cout << "Telefone: " << p1.getTelefone() << endl;

  cout << endl;

  cout << "Nome: " << p2.getNome() << endl;
  cout << "Idade: " << p2.getIdade() << endl;
  cout << "CPF: " << p2.getCpf() << endl;
  cout << "Telefone: " << p2.getTelefone() << endl;

  // Criando objeto do tipo Aluno
  Aluno a1("Joao Silva", 25, "123.456.789-00", "(11) 1234-5678", "Engenharia", "12345");

  // Imprimindo informações do aluno
  cout << endl;
  cout << "Nome: " << a1.getNome() << endl;
  cout << "Idade: " << a1.getIdade() << endl;
  cout << "CPF: " << a1.getCpf() << endl;
  cout << "Telefone: " << a1.getTelefone() << endl;
  cout << "Curso: " << a1.getNomeCurso() << endl;
  cout << "Código: " << a1.getCodigo() << endl;

  // Criando objeto do tipo Professor
  Professor prof("Maria Souza", 30, "987.654.321-00", "(11) 9876-5432", "12345", "Doutorado");

  // Imprimindo informações do professor
  cout << endl;
  cout << "Nome: " << prof.getNome() << endl;
  cout << "Idade: " << prof.getIdade() << endl;
  cout << "CPF: " << prof.getCpf() << endl;
  cout << "Telefone: " << prof.getTelefone() << endl;
  cout << "Matrícula SIAPE: " << prof.getMatriculaSiape() << endl;
  cout << "Formação: " << prof.getFormacao() << endl;

  return 0;
}

