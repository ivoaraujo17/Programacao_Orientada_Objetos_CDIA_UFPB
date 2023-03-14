#include <stdio.h>


class conta
{
private:
    int numero;
    int agencia;
    char nome[50];
    char cpf[11];

public:
    bool definir_num_conta(int num){
        if ((num >= 1000) && (num <=100000)){
            numero = num;
            return true;
        }
        else{
            return false;
        }
    }

    bool definir_agencia(int num){
        if ((num >= 1000) && (num <=100000)){
            agencia = num;
            return true;
        }
        else{
            return false;
        }
    }
    
    int get_num_conta(){
        return numero;
    }

    int get_num_agencia(){
        return agencia;;
    }
};


int main(){
    conta cont;
    cont.definir_num_conta(2456);
    cont.definir_agencia(8756);
    printf("%i  %i", cont.get_num_conta(), cont.get_num_agencia());
    return 0;
}