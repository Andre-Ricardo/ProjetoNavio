#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
// globais
int a,b,z;
int porto[200],x,y,n_container,peso_c[200];
int navio[4][16],navio_pesos[4][16],vagas_navio;
int pegadorcontainer;
int resposta;
float viagens;

//prototipos

int preparar_navio();
int mostrar_conteudo_navio();
int cadastro_c();
int mostrar_c();
int pegar_container();
int verificar_espaco_navio(b,a);
int carregar_navio();
int colocar_container(b,a);
int entregar_containers();
int linha();


int main()
{
        preparar_navio();
        mostrar_conteudo_navio();
        cadastro_c();
        viagens_nescessarias();
        //mostrar_c();
        for(z=0;z<viagens;z++){
            linha();
            carregar_navio();
            mostrar_conteudo_navio();
            entregar_containers();
        }
        mostrar_c();


    system("pause");
    return 0;
}
// outras
int linha(){

    printf("\n\n--------------Relatorio da entrega N:%d------------------\n\n",z+1);

}

int arredondamento1(float num){
    int num_int = num;
    if( (num - num_int) >= 0) return (num_int +1);
    else return num_int;
}

int entregar_containers(){

    int a,b;
    for(a=0;a<4;a++){
        for(b=0;b<16;b++){
            navio[a][b] = 0;
        }
    }
    printf("\n\n Ja entregamos os containers e o navio retornou \n\n");
    return 0;
}

// funcoes do navio

int verificar_espaco_navio(b,a){
    if(navio[b][a]==0){ // se não tiver container
        resposta=1; // tem espaco
    }else{
        resposta=0; // nao tem espaco
    }
    return resposta;
}

int carregar_navio(){
    for(b=0;b<4;b++){ // pula os andares
    	for(a=0;a<16;a++){   // carregar o andar do navio
            verificar_espaco_navio(b,a);
            if(resposta==1){ // se tiver espaco colocar container
    		colocar_container(b,a);
            }
        }
    }

    printf("\n Ja carregamos o navio \n");

    return 0;
}

int colocar_container(b,a){
        navio[b][a] = porto[n_container-1];
        porto[n_container-1] = 0;
        n_container-=1;
}

int preparar_navio(){

    int a,b;
    for(a=0;a<4;a++){
        for(b=0;b<16;b++){
            navio[a][b] = 0;
        }
    }
    return 0;
}

int mostrar_conteudo_navio(){

    printf("\n ----------------------------------------------------- \n");
    printf("   Navio  ");
    printf("\n ----------------------------------------------------- \n");

    int a,b;
    for(a=1;a<=4;a++){
        printf("\n Andar : %d_  ",a);
        for(b=0;b<16;b++){
            printf("(%d)",navio[a-1][b]);
        }
    }

    return 0;
}


// funcoes do porto
int viagens_nescessarias(){
    viagens=n_container/64;
    viagens=arredondamento1(viagens);
    return 0;
}

int cadastro_c(){

    x=0;
    y=0;
    printf("\n ----------------------------------------------------- \n");
    printf("   Digite o numero de containers a serem armazenados.   ");
    printf("\n ----------------------------------------------------- \n");

    scanf("%d",&n_container);

    while(x<n_container){
    porto[x] = x+1;
    //printf("Informe o peso do conteiner N %d : \n", porto[x]);
    //scanf("%d", &peso_c[x]);
    x++;
    }

    return 0;
}

int mostrar_c(){

    x=0;
    while(x<n_container){
        printf("container: %d Peso: %d \n",porto[x],peso_c[x]);
        x++;
    }

    return 0;
}
