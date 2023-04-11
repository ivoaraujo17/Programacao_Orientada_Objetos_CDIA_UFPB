#include <iostream>

using namespace std;

class Motor{
    private:
        float tamanho;
        int serial;
    public:
        Motor(float tam, int ser){
            tamanho = tam;
            serial = ser;
            cout << "\nMotor zero km criado!\n";
        }
        void set_tamanho(float tam){
            tamanho = tam;
        }
        void set_serial(int ser){
            serial = ser;
        }
        float get_tamanho(){
            return tamanho;
        }
        int get_serial(){
            return serial;
        }
        ~Motor(){
            cout << "\nBateu o motor!\n";
        }
};

class Freio{
    private:
        int abs;
        float temperatura;
    public:
        Freio(int abs_carro, float temperatura_freio){
            abs = abs_carro;
            temperatura = temperatura_freio;
            cout << "\nFreio criado, pastilha nova\n";
        }
        void set_abs(float abs_carro){
            abs = abs_carro;
        }
        void set_torque(int temperatura_freio){
            temperatura = temperatura_freio;
        }
        float get_abs(){
            return abs;
        }
        int get_torque(){
            return temperatura;
        }
        ~Freio(){
            cout << "\nFreio desgastado!\n";
        }
};

class Pneu{
    private:
        int aro;
        float pressao;
    public:
        Pneu(int roda = 0, float press = 0.0){
            aro = roda;
            pressao = press;
            cout << "\nPneu criado\n";
        }
        void set_aro(int roda){
            aro = roda;
        }
        void set_pressao(float press){
            pressao = press;
        }
        int get_aro(){
            return aro;
        }
        float get_pressao(){
            return pressao;
        }
        ~Pneu(){
            cout << "\nPneu careca\n";
        }
};


class Carro{
    private:
        int num_portas;
        int ano_fabricacao;
        Motor* motor;
        Freio* freio;
        Pneu* pneu;
    public:
        Carro(int num_p, int ano_f,
        float tam, int ser, 
        int abs_carro, float temperatura_freio,
        int aro, float pressao, int qtd_pneus){
            num_portas = num_p;
            ano_fabricacao = ano_f;

            motor = new Motor(tam, ser);
            freio = new Freio(abs_carro, temperatura_freio);
            pneu = new Pneu[qtd_pneus];
            for(int i=0; i < qtd_pneus; i++){
                pneu[i].set_aro(aro);
                pneu[i].set_pressao(pressao);
            }
        }
        ~Carro(){
            delete motor;
            delete freio;
            delete[] pneu;
        }
};

int main(){
    Carro c1(4,2022, 2000,13325352,1,80,17,37,4);
}