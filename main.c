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
    num = receberconatiner();
    verificarContainerPorto(num);
    printf("%d",num);
    return 0;
}
//Entrada de Container ao porto
int receberconatiner(){

    int ncontainer;
    printf("Informe a quantidade de container a ser colocado no porto: \n");
    scanf("%d",&ncontainer);
return ncontainer;
}
//Verifica a entrada do COntainer no porto

int verificarContainerPorto(int numContainer){
    int num;
     if(numContainer >0 && numContainer<200){
            num = numContainer;
            return num;
        }else{
            printf("Quantidade invalida,Digite outro valor: \n");
            receberconatiner();
        }
}
