// Andre, Douglas , Felipe , Leticia

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
// globais
int a,b,z,i,j;
int porto[200],x,y,n_container,peso_c[200],aux;
int navio[4][16],navio_pesos[4][16],vagas_navio;
int pegadorcontainer,peso_lado_a,peso_lado_b;
int resposta,diferensa_pesos;
float viagens;


//prototipos

int preparar_navio();
int mostrar_conteudo_navio();
int cadastro_c();
int mostrar_c();
int pegar_container();
int verificar_espaco_navio();
int carregar_navio();
int colocar_container();
int entregar_containers();
int linha();
int gera_pesos();
int mostra_pesos_porto();
int organizar_navio();
int teste_equilibrio();
int pesa_lado_a();
int pesa_lado_b();
int negativo_para_positivo();
int reorganizar_navio();
int funcoes_pesos();


int main(){
        gera_pesos();
        preparar_navio();
        mostrar_conteudo_navio();
        cadastro_c();
        viagens_nescessarias();
        //mostrar_c();
        for(z=0;z<viagens;z++){
            linha();
            carregar_navio();
            organizar_navio();
            teste_de_equilibrio();
            mostrar_conteudo_navio();
            entregar_containers();
        }
        mostrar_c();


    system("pause");
    return 0;
}
// outras
int organizar_navio(){
        for(a=0;a<16;a++){
            for( i=0; i<4; i++ ){
                  for( j=i+1; j<4; j++ ){
                       if( navio_pesos[i][a] < navio_pesos[j][a] ){
                           aux = navio_pesos[i][a];
                           navio_pesos[i][a] = navio_pesos[j][a] ;
                           navio_pesos[j][a]  = aux;
                       }
                  }
            }
        }
           printf("\n Organizado com sucesso! \n");
}

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
            navio_pesos[a][b] = 0;
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
    for(b=0;b<4;b++){
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
        colocar_peso_container(b,a);
}

int colocar_peso_container(b,a){
        navio_pesos[b][a] = peso_c[n_container-1];
        peso_c[n_container-1] = 0;
        n_container-=1;
}

int preparar_navio(){

    int a,b;
    for(a=0;a<4;a++){
        for(b=0;b<16;b++){
            navio[a][b] = 0;
            navio_pesos[a][b] = 0;
        }
    }
    return 0;
}

int mostrar_conteudo_navio(){

    printf("\n ----------------------------------------------------- \n");
    printf("   Navio  ");
    printf("\n ----------------------------------------------------- \n");

    int a,b;
    for(a=4;a>=1;a--){
        printf("\n Setor : %d  ",a);
        for(b=0;b<16;b++){
            printf("[%d]",navio[a-1][b]);
        }
    }

    printf("\n ----------------------------------------------------- \n");
    printf("   Pesos dos containers _ Diferenca: %d",diferensa_pesos);
    printf("\n ----------------------------------------------------- \n");


    for(a=4;a>=1;a--){
        printf("\n Setor : %d  ",a);
        for(b=0;b<16;b++){
            printf("[%d]",navio_pesos[a-1][b]);
        }
    }

    return 0;
}
// setores
int funcoes_pesos(){
    pesa_lado_a();
    pesa_lado_b();
    diferensa_pesos = peso_lado_a - peso_lado_b;
    diferensa_pesos*=-1;
    return 0;
}

int teste_de_equilibrio(){
        funcoes_pesos();
    if(diferensa_pesos>15){
        printf(" O navio nao pode partir pois esta em desequilibrio em %d  toneladas estamos reorganizando ", diferensa_pesos);
       // z= 10;
       do{
            for(x=0;x<16;x++){
            reorganizar_navio();
            }
            funcoes_pesos();
       }while(diferensa_pesos>10000);
    }else{
        printf(" O navio esta OK e pode partir %d", diferensa_pesos);
    }
 return 0;
}

int reorganizar_navio(){
    for(a=0;a<4;a++){
        srand(rand());
        aux = navio[a][rand()%15];
        navio[a][rand()%15] = navio[a][(rand()%15)-1];
    }
    return 0;
}

int pesa_lado_a(){
    peso_lado_a = 0;
    for(a=0;a<4;a++){
            for(b=0;b<8;b++){
                if(navio[b][a]!=0){
                   peso_lado_a += navio_pesos[a][b];
                }
           }
    }
    return 0;
}

int pesa_lado_b(){
    peso_lado_b = 0;
    for(a=0;a<4;a++){
            for(b=8;b<16;b++){
                if(navio[a][b]!=0){
                   peso_lado_b += navio_pesos[a][b];
                }
           }
    }
    return 0;
}

// funcoes do porto

int gera_pesos(){
    for(x=0;x<200;x++){
        srand(rand());
        peso_c[x] = 1 + rand()%15;
    }
}

int mostra_pesos_porto(){
    for(x=0;x<200;x++){
        printf("Peso %d : %d \n",x+1,peso_c[x]);
    }
    return 0;
}

int viagens_nescessarias(){
    viagens=n_container/64;
    viagens=arredondamento1(viagens);
    return 0;
}

int cadastro_c(){
	do{

    x=0;
    y=0;
    printf("\n ----------------------------------------------------- \n");
    printf("   Digite o numero de containers a serem armazenados.   ");
    printf("\n ----------------------------------------------------- \n");

    scanf("%d",&n_container);
    system("cls");
	}while(n_container<0 && n_container>=200);

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
