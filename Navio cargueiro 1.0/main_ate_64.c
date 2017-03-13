#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// globais
int a,b;
int porto[200],x,y,n_container,peso_c[200];
int navio[4][16],navio_pesos[4][16],vagas_navio;
int pegadorcontainer,pos_p;
int resposta;

//prototipos

int preparar_navio();
int mostrar_conteudo_navio();
int cadastro_c();
int mostrar_c();
int pegar_container();
int verificar_espaco_navio(b,a);
int carregar_navio();
int colocar_container(b,a);


int main()
{
        preparar_navio();
        mostrar_conteudo_navio();
        cadastro_c();
        //mostrar_c();

        carregar_navio();
        mostrar_conteudo_navio();
        mostrar_c();


    system("pause");
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
            }else{
            printf(" Ja foram colocados todos os containers ");
            }
        }
    }
    //possivelmente uma mensagem que todos os containers foram colocados.
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

    int a,b;
    for(a=1;a<=4;a++){
        printf("\n Andar : %d_ ",a);
        for(b=0;b<16;b++){
            printf("(%d)",navio[a-1][b]);
        }
    }

    return 0;
}


// funcoes do porto
int cadastro_c(){

    x=0;
    y=0;

    printf("\nDigite o numero de containers a serem armazenados.\n");
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
