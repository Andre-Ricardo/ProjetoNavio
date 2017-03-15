#include <stdio.h>
#include <stdlib.h>
#include <math.h>



struct ContainerPorto{
        int id_conatainer[200];
        int peso_container[200];
    };
struct Navio{
    int setores[4][16];
    int peso_setores[4][16];
};

int receberconatiner();
int verificarContainerPorto();

int main()
{
    int num;
    receberconatiner();
    num = receberconatiner();
    verificarContainerPorto(num);
    printf("%d",numa);
    return 0;
}
//Entrada de Container ao porto
int receberconatiner(){

    int ncontainer,numero;
    printf("Informe a quantidade de container a ser colocado no porto: \n");
    scanf("%d",&ncontainer);
return numero;
}
//Verifica a entrada do COntainer no porto

int verificarContainerPorto(int numContainer){
     if(numContainer >0 && numContainer<200){
            return numContainer;
        }else{
            printf("Quantidade invalida,Digite outro valor: \n");
            receberconatiner();
        }
}
