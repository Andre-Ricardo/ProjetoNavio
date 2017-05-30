#include <stdio.h>
#include <stdlib.h>

int linha,coluna,reservando,tamanhostring;
int cadeiras[6][12];
int a,b,r,cli;
char digitando[100];

typedef struct {
    char nome[50];
    int fileira;
    int coluna;
    int horarioEntrada;
    int horarioFim;
    char filme[50];
    int meia;
    }dados;

dados *dadoscliente;
void alocar_espaco_clientes();
void salvar_dados_int();
void salvar_dados_char();
void listar_filmes();
int msg_reserva();
int esvaziar_cadeiras();
int mostrar_cadeiras();
void reservar_cadeira();
void pergunta();
void limpa_hud();

int main()
{   cli = 0;
    alocar_espaco_clientes();
    esvaziar_cadeiras();
    do{
    mostrar_cadeiras();
    listar_filmes();
    msg_reserva();
    reservar_cadeira(linha,coluna);
    pergunta();
    limpa_hud();
    cli++;
    }while(r!=1);



    return 0;
}
void alocar_espaco_clientes(){
            dadoscliente = (int *) malloc(72 * sizeof(dados));
            if (!dadoscliente){
            printf ("** Erro: Memoria Insuficiente **\n");
            exit;
            }else{
            printf ("** Memoria Alocada com Sucesso **\n");
            }
}

void salvar_dados_char(char digitado[50]){
            FILE *historico;
            historico = fopen("historico.txt", "a+");
            fprintf(historico, " %s", digitado);
            fclose(historico);
}

void salvar_dados_int(int digitado){
            FILE *historico;
            historico = fopen("historico.txt", "a+");
            fprintf(historico, " %d", digitado);
            fclose(historico);
}

void limpa_hud(){
        system("cls");
}

void reservar_cadeira(int z,int y){
    cadeiras[z-1][y-1] = cli+1;

}

void pergunta(){
    printf("\nDigite 1 para fechar o programa e 0 para continuar a reservar.");
    scanf("%d",&r);
    if(r>1){
        limpa_hud();
        pergunta();
    }
}

int msg_reserva(){
        printf("\nDigite a linha da cadeira desejada : ");
        scanf("%d",&linha);
        salvar_dados_int(linha);

        printf("\nDigite a coluna da cadeira desejada : ");
        scanf("%d",&coluna);
        salvar_dados_int(coluna);

         fflush(stdin);
        printf("\nDigite o nome do cliente : ");
        gets(dadoscliente[cli].nome);
        salvar_dados_char(dadoscliente[cli].nome);

        printf("\ncliente paga meia? [1-S/2-N] : ");
        scanf("%d",&dadoscliente[cli].meia);
        if(dadoscliente[cli].meia == 1){
                salvar_dados_char("Meia");
        }else{
                salvar_dados_char("Inteira");
        }

    return 0;
}

int esvaziar_cadeiras(){
    for(a=0;a<6;a++){
        for(b=0;b<12;b++){
            cadeiras[a][b] = 0;
        }
    }
return 0;
}

int mostrar_cadeiras(){
	printf("\n =================================================\n");
	printf("            =               Filme : %s        \n");
  	printf("\n =================================================\n");
    printf("            =[__________________________________]=\n");
    printf("            =               Colunas              =\n");
    printf("            ======================================\n");
    printf("            = 1  2  3  4  5  6  7  8  9 10 11 12 =\n");
    printf(" =================================================\n");
    for(a=0;a<6;a++){
     printf("Fileira : %d ",a+1);
        for(b=0;b<12;b++){
            printf("[%d]",cadeiras[a][b]);
        }
    printf("\n");
    }
    printf(" =================================================\n");

return 0;
}


void listar_filmes(){

    char url[]="filme.txt";
	char ch;
	FILE *arq;

	arq = fopen(url, "r");
	if(arq == NULL)
	    printf("Erro, nao foi possivel abrir o arquivo\n");
	else
	    while( (ch=fgetc(arq))!= EOF )
		putchar(ch);
	fclose(arq);
    }
