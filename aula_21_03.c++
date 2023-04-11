#include <iostream>

using namespace std;

#define QTD_NOTAS 3

class curso{
    int codigo;
    float duracao;
    public:
        curso(int c, int d): codigo(c), duracao(d){
            cout << "\ncurso criado!\n";
        }
        ~curso(){
            cout << "\ncurso deletado!\n";
        }
        void set_codigo(int c){
            codigo = c;
        }
        int get_codigo(){
            return codigo;
        }
        void set_duracao(float d){
            duracao = d;
        }
        float get_duracao(){
            return duracao;
        }
        void print_info(){
            cout << "\nCurso : " << codigo << " duracao: " << duracao << endl;
        }
};

class aluno{
    private:
        int matricula;
        float notas[QTD_NOTAS];
        int cod_curso;
        curso c;
    public:
        aluno(int mat, int cod_c, float* nota_aluno, curso cc):c(cc){
            matricula = mat;
            cod_curso = cod_c;
            for (int i=0; i < 3; i++){
                notas[i] = nota_aluno[i];
            }
            cout << "\nAluno criado!\n";
        }
        aluno(int mat, int cod_c, float* nota_aluno, int cc, float dc):c(cc, dc){
            matricula = mat;
            cod_curso = cod_c;
            for (int i=0; i < 3; i++){
                notas[i] = nota_aluno[i];
            }
            cout << "\nAluno criado!\n";
       }
       ~aluno(){
            cout << "\nAluno deletado\n";
       }
       void set_matricula(int mat){
            matricula = mat;
       }
       void set_cod_curso(int cod_c){
            cod_curso = cod_c;
       }
       void print_info(){
            cout << "Matricula: " << matricula << endl;
            cout << "Codigo curso: " << cod_curso << endl;
            for (int i = 0; i < 3; i++){
                if (i != 2){
                    cout << notas[i] << " | ";
                }
                else{
                    cout << notas[i] << endl;
                }
            c.print_info();
            }
       }
};

class disciplina{
    private:
        int codigo;
    public:
        disciplina(int cod_disciplina){
            codigo = cod_disciplina;
            cout << "\nDisciplina criada!\n";
        }
};

class professor{
    private:
        int siape;
        int cod_titulacao;
    public:
        professor(int cod_siape, int titulacao){
            siape = cod_siape;
            cod_titulacao = titulacao;
        }
};

class turma{
    private:
        int codigo;
        professor prof_turma;
        disciplina disciplina_turma;
        aluno alunos[30];
};


int main(){
    float notas_aluno[3] = {8.0, 7.6, 9.0};
    aluno ivo(1020,123,notas_aluno, 3311, 4.0);
    ivo.print_info();
    return 0;
}
