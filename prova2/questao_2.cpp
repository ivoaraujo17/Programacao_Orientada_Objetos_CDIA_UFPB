#include <iostream>
#include <string>
using namespace std;

class Veiculo{
    private:
    protected:
        string marca;
        int ano;
        int modelo;
    public:
        /*metodo construtor e destrutor de veiculo*/
        Veiculo(const string m, int a, int mo){
            marca = m;
            ano = a;
            modelo = mo;
        }
        ~Veiculo(){
        }
        /*get e set dos atributos de veiculos*/
        int get_ano(){return ano;}
        float get_modelo(){return modelo;}
        void set_ano(int a){
            ano = a;
        }
        void set_modelo(int mo){
            modelo = mo;
        }
        /*metodo print info implementado de forma virtual puro, que torna
        a classe veiculo abstrata, condicionando as classes que herdan dela
        a construir o metodo print_info*/
        virtual void print_info() = 0;
};      

/*classe carro, construindo uma herança do (tipo de) veiculo*/
class Carro: public Veiculo{
    private:
    protected:
        int numero_portas;
    public:
        Carro(const string m, int a, int mo, int np):Veiculo(m, a, mo){
            numero_portas = np;
        }
        ~Carro(){}
        int get_numero_portas(){return numero_portas;}
        void set_numero_portas(int np){
            numero_portas = np;
        }
        /*implementação do metodo print info, obrigatorio como falado anteriomente*/
        void print_info(){
            cout << "\nVeiculo::marca: " << marca << endl;
            cout << "Veiculo::ano: " << ano << endl;
            cout << "Veiculo::modelo: " << modelo << endl;
            cout <<"Carro::Quantidade de portas: " << numero_portas << endl;
        }
};
/*classe barco, construindo uma herança do (tipo de) veiculo*/
class barco: public Veiculo{
    private:
    protected:
        float comprimento;
    public:  
        barco(const string m, int a, int mo, float c):Veiculo(m, a, mo){
            comprimento = c;
        }
        ~barco(){}
        float get_comprimento(){return comprimento;}
        void set_comprimento(float c){
            comprimento = c;
        }
        /*implementação do metodo print info, obrigatorio como falado anteriomente*/
        void print_info(){
            cout << "\nVeiculo::marca: " << marca << endl;
            cout << "Veiculo::ano: " << ano << endl;
            cout << "Veiculo::modelo: " << modelo << endl;
            cout<<"barco::comprimento:: "<<comprimento<<endl;
            cout<<endl;
        }
    };

/*classe anfibio, construindo uma herança mutua, herdando tanto de carro, 
quanto de barco*/
class anfibio : public Carro, public barco{
    private:
    public:
        anfibio(const string m, int a, int mo, int np, float c)
        :Carro(m, a, mo, np),barco(m, a, mo, c){
        }
        ~anfibio(){}
        /*implementando o metodo print info (obrigatorio) e como herda de carro
        e barco que contem os atributos marca, ano e modelo, defini de qual
        herança iria ser buscada a informação*/
        void print_info(){
            cout << "\nVeiculo::marca: " << Carro::marca << endl;
            cout << "Veiculo::ano: " << Carro::ano << endl;
            cout << "Veiculo::modelo: " << Carro::modelo << endl;
            cout <<"Carro::Quantidade de portas: " << Carro::numero_portas << endl;
            cout<<"barco::comprimento:: "<< barco::comprimento << endl;
        }
};

int main(){
    Carro civic("honda", 2015, 3, 4);
    Carro argo("fiat", 2022, 1, 4);
    barco yamaha("yamaha", 2020, 5, 10.15);
    barco titanic("titanic", 2000, 1, 150.00);
    anfibio barco_carro1("barco_Carro1", 2005, 4, 6, 15.78);
    anfibio barco_carro2("barco_carro2", 2022, 4, 8, 55.67);

    Veiculo* lista_veiculos[6];
    lista_veiculos[0] = &civic;
    lista_veiculos[1] = &argo;
    lista_veiculos[2] = &yamaha;
    lista_veiculos[3] = &titanic;
    /*aqui eu não encontrei uma forma de corrigir esse erro, diz que é ambiguo
    devido receber duas vezes da classe veiculo, porem no print info, eu 
    especifiquei de qual ele iria puxar e mesmo assim da erro*/
    lista_veiculos[4] = &barco_carro1;
    lista_veiculos[5] = &barco_carro2;

    for (int i = 0; i < 4; i++){
        lista_veiculos[i]->print_info();
    }
    barco_carro1.print_info();
    barco_carro2.print_info();
}
