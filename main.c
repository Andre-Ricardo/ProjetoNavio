#include <stdio.h>
#include <stdlib.h>
// globais

int porto[200],x,y,n_container,peso_c[200];
int navio[4][16],navio_pesos[4][16],vagas_navio;

//prototipos

int preparar_navio();
int mostrar_conteudo_navio();
int cadastro_c();
int mostrar_c();

//prototipos

int main()
{
        preparar_navio();
        mostrar_conteudo_navio();
        cadastro_c();
        mostrar_c();
        
        carregar_navio();
        mostrar_conteudo_navio();
        mostrar_c();
        

    system("pause");
    return 0;
}

// funcoes do navio

int carregar_navio(){

    if(n_container<vagas_navio){
        // pensando
    }else{
    	int a,b;
    //	for(a=sizeof(porto);;a--){
    	for(a=0;a<n_container;a++){
    		navio[0][a] = porto[a];
    		porto[a] = 0;
		}
    }

    return 0;
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
    printf("Informe o peso do conteiner N %d : \n", porto[x]);
    scanf("%d", &peso_c[x]);
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
