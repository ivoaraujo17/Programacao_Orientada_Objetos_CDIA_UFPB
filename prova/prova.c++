#include <iostream>
#include <string>

#define MAX_CONTAS 10
using namespace std;

class conta{
    /*Considere uma classe Conta que possui os atributos numero, saldo e titular.*/
    int numero;
    float saldo;
    string titular;

    public:
        conta(int n, double s, const string& t) {
        numero = n;
        saldo = s;
        titular = t;
        }
        void depositar(float valor){
            if (valor <= 0){
                cout << "\nImpossivel depositar um valor 0 ou negativo!";
            }
            else{
                saldo += valor;
                cout << "\nDeposito de R$" << valor << " realizado com sucesso!";
            }
        }
        void sacar(float valor){
            if (valor <= 0) {
                cout << "\nO valor a ser sacado deve ser positivo!" << endl;
            }
            else if (valor > saldo) {
                cout << "\nSaldo insuficiente para realizar o saque!" << endl;
                cout << "\nSaldo atual: R$" << saldo;
            }
            else{
                saldo -= valor;
                cout << "\nSaque realizado com sucesso!";
                cout << "\nSaldo atual: R$" << saldo;
            }
        }
        float get_saldo(){
            return saldo;
        }
        void print_info(){
            cout << "\nNumero da conta: " << numero;
            cout << "\nSaldo: " << saldo;
            cout << "\nTitular: " << titular;
        }
        /*Aqui continuaria os gets e sets dos atributos*/
};

/*Criando conta corrente que será um tipo de conta, logo usa-se herença*/
class conta_corrente : public conta{
    float limite;
    public:
        conta_corrente(int n, float s, const string& t, float l):conta(n,s,t){
            limite = l;
        }
        void sacar(float valor){
            if (valor <= 0){
                cout << "\nImpossível sacar valor negativo";
            }
            else if (get_saldo() + limite >= valor) {
                conta::sacar(valor);
            }
            else {
                cout << "\nSaldo e limite insuficientes para saque" << endl;
                cout << "\nSaldo atual R$" << get_saldo();
                cout << "\nLimite R$" << limite;
            }
        /*Aqui continuaria o get e set do atributo limite para posteriomente fazer
        a mudança do mesmo*/
    }
};

/*conta poupanca também vai ser um tipo de conta, também vai hedar os atributos
e metodos assim como a conta corrente*/
class conta_poupanca : public conta{
    float rendimento;
    public:
        conta_poupanca(int n, float s, const string& t, float r):conta(n,s,t){
            rendimento = r;
        }

};

/*ja a classe banco vai ser compostas por conta, pois as contas faz parte de um 
banco, mais um banco não é um tipo de conta, então a relacao aqui é todo parte*/
class banco{
    private:
        conta* contas[MAX_CONTAS];
        int tam_lis_contas;
    public:
        banco(){
            tam_lis_contas = 0;
        }
        void adicionar_conta(conta* c){
            if (tam_lis_contas > MAX_CONTAS){
                cout << "\nBanco atingiu o numero maximo de contas";
            }
            else{
                contas[tam_lis_contas] = c;
                tam_lis_contas += 1;
            }
        }
        void lista_contas(){
            for (int i = 0; i<tam_lis_contas; i++){
                contas[i]->print_info();
            }
        }
        /*Aqui construiria o metodo de remover conta*/
};

int main() {
    /*criando um banco, posteriomente poderia ser alterado para passar o numero
    maximo de contas do banco, mas pelo tempo optei por deixar fixo*/
    banco banco;
    /*criando as contas corrente e poupança, passando os atributos da classe conta
    também pois vai ser chamada no metodo contrutor e na meu programa não quis
    contruir metodo padrao*/
    conta_corrente contaCorrente(1, 4000, "Joao", 1000);
    conta_poupanca contaPoupanca(2, 2000, "Maria", 0.05);

    /*adiciona as contas no banco*/
    banco.adicionar_conta(&contaCorrente);
    banco.adicionar_conta(&contaPoupanca);

    cout << "Informacoes das contas:" << endl;
    /*Aqui será pecorrido o vetor de contas chamando o print_info de contas
    que sera exibido os atributos da classe conta, como numero da conta 
    saldo e titular*/
    banco.lista_contas();

    contaCorrente.depositar(500);
    contaCorrente.sacar(1500);

    contaPoupanca.depositar(1000);
    contaPoupanca.sacar(600);
    
    cout << endl << "Informacoes das contas apos operacoes:" << endl;
    /*Aqui será pecorrido o vetor de contas chamando o print_info de contas
    que sera exibido os atributos da classe conta, como numero da conta 
    saldo e titular*/
    banco.lista_contas();
    return 0;
}