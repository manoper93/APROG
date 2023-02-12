///  TRABALHO DE GRUPO 2022 APROG DE:
///  SERGIO ISIDORO - 1221709
///  JOSE SILVA     - 1221734
///  RUI FERNANDES  - 1212227

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


struct cliente {
    int numcliente;
    char nickname[12];
    char pin[6];
    char nome_completo[101];
    char numcontri[11];
    char nascimento[12];
    char nascimentodia[4],nascimentomes[4],nascimentoano[6];
    char telemovel[11];
    char morada[101];
    char nporta[12];
    char codigopostal[11];
    char codigopostalquatro[6],codigopostaltres[5];
    char cidade[101];
    char tipocliente[7];
    char cartaocredito[18];
    char cartaocreditocve[5];
    char cartaocreditovalidade[7];
    char cartaocreditovalidademes[4],cartaocreditovalidadeano[4];
};

struct artigo {
    int numeroartigo;
    char nomeartigo[101];
    char marcaartigo[101];
    char produtoartigo[101];
    char categoriaartigo[101];
    char subcategoriaartigo[101];
    char corartigo[101];
    char tamanhoartigo[101];
    char precoartigo[101];
    float relacionado;
};

struct carrinho{
    int cliente;
    int numeroartigo;
    int quantidade;
    char estado[10];
};

struct cores {
    char fimcor[10];
    char rosa[10];
    char azul[10];
    char verde[10];
    char vermelho[10];
    char amarelo[10];
};

 typedef struct{
    int num;
    float perc;
}artr;

int checkzeros(char str[]);
int checkexite(char str[],int skip, struct cores RGB);
int checknick(struct cliente C[], char stri[], int pcT, struct cores RGB);
int AnoBissexto(int ano);

//------------------------ Ao Iniciar --------------------------------
void inicializar(struct cliente C[],struct artigo A[], int *NA, int *NC, int *pcT, int *paT) {
    //--------------------------------------------------- Por Default Guardar 17 Artigos
    //Artigo 1
    A[*paT].numeroartigo = *NA;
    strcpy(A[*paT].nomeartigo, "CAMISOLA");
    strcpy(A[*paT].marcaartigo, "PUMA");
    strcpy(A[*paT].produtoartigo, "TEXTIL");
    strcpy(A[*paT].categoriaartigo, "DESPORTO");
    strcpy(A[*paT].subcategoriaartigo, "STREET");
    strcpy(A[*paT].corartigo, "PRETA");
    strcpy(A[*paT].tamanhoartigo, "M");
    strcpy(A[*paT].precoartigo, "35");
    *paT+=1;
    *NA+=1;
    //Artigo 2
    A[*paT].numeroartigo = *NA;
    strcpy(A[*paT].nomeartigo, "FATO BANHO");
    strcpy(A[*paT].marcaartigo, "ADIDAS");
    strcpy(A[*paT].produtoartigo, "TEXTIL");
    strcpy(A[*paT].categoriaartigo, "DESPORTO");
    strcpy(A[*paT].subcategoriaartigo, "PISCINA");
    strcpy(A[*paT].corartigo, "PRETA");
    strcpy(A[*paT].tamanhoartigo, "L");
    strcpy(A[*paT].precoartigo, "21");
    *paT+=1;
    *NA+=1;
    //Artigo 3
    A[*paT].numeroartigo = *NA;
    strcpy(A[*paT].nomeartigo, "CALCOES");
    strcpy(A[*paT].marcaartigo, "NIKE");
    strcpy(A[*paT].produtoartigo, "TEXTIL");
    strcpy(A[*paT].categoriaartigo, "DESPORTO");
    strcpy(A[*paT].subcategoriaartigo, "PISCINA");
    strcpy(A[*paT].corartigo, "PRETA");
    strcpy(A[*paT].tamanhoartigo, "M");
    strcpy(A[*paT].precoartigo, "34");
    *paT+=1;
    *NA+=1;
    //Artigo 4
    A[*paT].numeroartigo = *NA;
    strcpy(A[*paT].nomeartigo, "TOUCA");
    strcpy(A[*paT].marcaartigo, "ADIDAS");
    strcpy(A[*paT].produtoartigo, "PLASTICO");
    strcpy(A[*paT].categoriaartigo, "DESPORTO");
    strcpy(A[*paT].subcategoriaartigo, "PISCINA");
    strcpy(A[*paT].corartigo, "BRANCA");
    strcpy(A[*paT].tamanhoartigo, "M");
    strcpy(A[*paT].precoartigo, "15");
    *paT+=1;
    *NA+=1;
    //Artigo 5
    A[*paT].numeroartigo = *NA;
    strcpy(A[*paT].nomeartigo, "CALCAS");
    strcpy(A[*paT].marcaartigo, "NIKE");
    strcpy(A[*paT].produtoartigo, "TEXTIL");
    strcpy(A[*paT].categoriaartigo, "DESPORTO");
    strcpy(A[*paT].subcategoriaartigo, "CORRIDA");
    strcpy(A[*paT].corartigo, "PRETA");
    strcpy(A[*paT].tamanhoartigo, "L");
    strcpy(A[*paT].precoartigo, "36");
    *paT+=1;
    *NA+=1;
    //Artigo 6
    A[*paT].numeroartigo = *NA;
    strcpy(A[*paT].nomeartigo, "SAPATILHA");
    strcpy(A[*paT].marcaartigo, "NIKE");
    strcpy(A[*paT].produtoartigo, "TEXTIL");
    strcpy(A[*paT].categoriaartigo, "DESPORTO");
    strcpy(A[*paT].subcategoriaartigo, "CORRIDA");
    strcpy(A[*paT].corartigo, "PRETA");
    strcpy(A[*paT].tamanhoartigo, "41");
    strcpy(A[*paT].precoartigo, "90");
    *paT+=1;
    *NA+=1;
    //Artigo 7
    A[*paT].numeroartigo = *NA;
    strcpy(A[*paT].nomeartigo, "SAPATILHA");
    strcpy(A[*paT].marcaartigo, "PUMA");
    strcpy(A[*paT].produtoartigo, "TEXTIL");
    strcpy(A[*paT].categoriaartigo, "DESPORTO");
    strcpy(A[*paT].subcategoriaartigo, "FUTEBOL");
    strcpy(A[*paT].corartigo, "CINZA");
    strcpy(A[*paT].tamanhoartigo, "42");
    strcpy(A[*paT].precoartigo, "200");
    *paT+=1;
    *NA+=1;
    //Artigo 8
    A[*paT].numeroartigo = *NA;
    strcpy(A[*paT].nomeartigo, "CAMISA");
    strcpy(A[*paT].marcaartigo, "SACOOR");
    strcpy(A[*paT].produtoartigo, "TEXTIL");
    strcpy(A[*paT].categoriaartigo, "CLASSICO");
    strcpy(A[*paT].subcategoriaartigo, "DIARIO");
    strcpy(A[*paT].corartigo, "BRANCA");
    strcpy(A[*paT].tamanhoartigo, "L");
    strcpy(A[*paT].precoartigo, "45");
    *paT+=1;
    *NA+=1;
    //Artigo 9
    A[*paT].numeroartigo = *NA;
    strcpy(A[*paT].nomeartigo, "CINTO");
    strcpy(A[*paT].marcaartigo, "CALVINK");
    strcpy(A[*paT].produtoartigo, "PELE");
    strcpy(A[*paT].categoriaartigo, "CLASSICO");
    strcpy(A[*paT].subcategoriaartigo, "DIARIO");
    strcpy(A[*paT].corartigo, "PRETA");
    strcpy(A[*paT].tamanhoartigo, "L");
    strcpy(A[*paT].precoartigo, "60");
    *paT+=1;
    *NA+=1;
    //Artigo 10
    A[*paT].numeroartigo = *NA;
    strcpy(A[*paT].nomeartigo, "GRAVATA");
    strcpy(A[*paT].marcaartigo, "SACOOR");
    strcpy(A[*paT].produtoartigo, "TEXTIL");
    strcpy(A[*paT].categoriaartigo, "CLASSICO");
    strcpy(A[*paT].subcategoriaartigo, "DIARIO");
    strcpy(A[*paT].corartigo, "PRETA");
    strcpy(A[*paT].tamanhoartigo, "M");
    strcpy(A[*paT].precoartigo, "30");
    *paT+=1;
    *NA+=1;
    //Artigo 11
    A[*paT].numeroartigo = *NA;
    strcpy(A[*paT].nomeartigo, "CACHECOL");
    strcpy(A[*paT].marcaartigo, "TIMBERLAND");
    strcpy(A[*paT].produtoartigo, "TEXTIL");
    strcpy(A[*paT].categoriaartigo, "CLASSICO");
    strcpy(A[*paT].subcategoriaartigo, "DIARIO");
    strcpy(A[*paT].corartigo, "CASTANHA");
    strcpy(A[*paT].tamanhoartigo, "M");
    strcpy(A[*paT].precoartigo, "25");
    *paT+=1;
    *NA+=1;
    //Artigo 12
    A[*paT].numeroartigo = *NA;
    strcpy(A[*paT].nomeartigo, "SAPATILHA");
    strcpy(A[*paT].marcaartigo, "ADIDAS");
    strcpy(A[*paT].produtoartigo, "TEXTIL");
    strcpy(A[*paT].categoriaartigo, "DESPORTO");
    strcpy(A[*paT].subcategoriaartigo, "DIARIO");
    strcpy(A[*paT].corartigo, "AZUL");
    strcpy(A[*paT].tamanhoartigo, "41");
    strcpy(A[*paT].precoartigo, "90");
    *paT+=1;
    *NA+=1;
    //Artigo 13
    A[*paT].numeroartigo = *NA;
    strcpy(A[*paT].nomeartigo, "CHUTEIRAS");
    strcpy(A[*paT].marcaartigo, "NEWBALANCE");
    strcpy(A[*paT].produtoartigo, "PELE");
    strcpy(A[*paT].categoriaartigo, "DESPORTO");
    strcpy(A[*paT].subcategoriaartigo, "FUTEBOL");
    strcpy(A[*paT].corartigo, "PRETA");
    strcpy(A[*paT].tamanhoartigo, "41");
    strcpy(A[*paT].precoartigo, "120");
    *paT+=1;
    *NA+=1;
    //Artigo 14
    A[*paT].numeroartigo = *NA;
    strcpy(A[*paT].nomeartigo, "TSHIRT");
    strcpy(A[*paT].marcaartigo, "NIKE");
    strcpy(A[*paT].produtoartigo, "TEXTIL");
    strcpy(A[*paT].categoriaartigo, "DESPORTO");
    strcpy(A[*paT].subcategoriaartigo, "DIARIO");
    strcpy(A[*paT].corartigo, "BRANCA");
    strcpy(A[*paT].tamanhoartigo, "L");
    strcpy(A[*paT].precoartigo, "24");
    *paT+=1;
    *NA+=1;
    //Artigo 15
    A[*paT].numeroartigo = *NA;
    strcpy(A[*paT].nomeartigo, "TSHIRT");
    strcpy(A[*paT].marcaartigo, "NEWBALANCE");
    strcpy(A[*paT].produtoartigo, "TEXTIL");
    strcpy(A[*paT].categoriaartigo, "DESPORTO");
    strcpy(A[*paT].subcategoriaartigo, "DIARIO");
    strcpy(A[*paT].corartigo, "AMARELA");
    strcpy(A[*paT].tamanhoartigo, "M");
    strcpy(A[*paT].precoartigo, "23");
    *paT+=1;
    *NA+=1;
    //Artigo 16
    A[*paT].numeroartigo = *NA;
    strcpy(A[*paT].nomeartigo, "TSHIRT");
    strcpy(A[*paT].marcaartigo, "PUMA");
    strcpy(A[*paT].produtoartigo, "TEXTIL");
    strcpy(A[*paT].categoriaartigo, "DESPORTO");
    strcpy(A[*paT].subcategoriaartigo, "FUTEBOL");
    strcpy(A[*paT].corartigo, "PRETA");
    strcpy(A[*paT].tamanhoartigo, "L");
    strcpy(A[*paT].precoartigo, "22");
    *paT+=1;
    *NA+=1;
    //Artigo 17
    A[*paT].numeroartigo = *NA;
    strcpy(A[*paT].nomeartigo, "TSHIRT");
    strcpy(A[*paT].marcaartigo, "ADIDAS");
    strcpy(A[*paT].produtoartigo, "TEXTIL");
    strcpy(A[*paT].categoriaartigo, "DESPORTO");
    strcpy(A[*paT].subcategoriaartigo, "FUTEBOL");
    strcpy(A[*paT].corartigo, "AZUL");
    strcpy(A[*paT].tamanhoartigo, "L");
    strcpy(A[*paT].precoartigo, "21");
    *paT+=1;


    //--------------------------------------------------- Por Default Guardar 3 Clientes
    C[*pcT].numcliente = *NC;
    strcpy(C[*pcT].nickname, "SERGIO");
    strcpy(C[*pcT].pin, "1111");
    strcpy(C[*pcT].nome_completo, "SERGIO ISIDORO");
    strcpy(C[*pcT].nascimento, "01/01/1993");
    strcpy(C[*pcT].telemovel, "912345671");
    strcpy(C[*pcT].morada, "RUA DO PORTO");
    strcpy(C[*pcT].cidade, "PORTO");
    strcpy(C[*pcT].tipocliente, "ADMIN");
    strcpy(C[*pcT].codigopostal, "4123-123");
    strcpy(C[*pcT].nporta, "8");
    strcpy(C[*pcT].numcontri, "123456781");
    strcpy(C[*pcT].cartaocredito, "1234567891123456");
    strcpy(C[*pcT].cartaocreditocve, "123");
    strcpy(C[*pcT].cartaocreditovalidade, "10/22");
    *pcT+=1;
    *NC+=1;

    C[*pcT].numcliente = *NC;
    strcpy(C[*pcT].nickname, "JOSE");
    strcpy(C[*pcT].pin, "2222");
    strcpy(C[*pcT].nome_completo, "JOSE SILVA");
    strcpy(C[*pcT].nascimento, "06/12/1987");
    strcpy(C[*pcT].telemovel, "912345672");
    strcpy(C[*pcT].morada, "TRAVESSA DE BRAGA");
    strcpy(C[*pcT].cidade, "BRAGA");
    strcpy(C[*pcT].tipocliente, "NORMA");
    strcpy(C[*pcT].codigopostal, "4789-999");
    strcpy(C[*pcT].nporta, "568");
    strcpy(C[*pcT].numcontri, "123456782");
    strcpy(C[*pcT].cartaocredito, "6543211987654321");
    strcpy(C[*pcT].cartaocreditocve, "321");
    strcpy(C[*pcT].cartaocreditovalidade, "05/25");
    *pcT+=1;
    *NC+=1;

    C[*pcT].numcliente = *NC;
    strcpy(C[*pcT].nickname, "RUI");
    strcpy(C[*pcT].pin, "3333");
    strcpy(C[*pcT].nome_completo, "RUI FERNANDES");
    strcpy(C[*pcT].nascimento, "11/11/1990");
    strcpy(C[*pcT].telemovel, "912345673");
    strcpy(C[*pcT].morada, "RUA DA BOAVISTA");
    strcpy(C[*pcT].cidade, "PORTO");
    strcpy(C[*pcT].tipocliente, "GOLDE");
    strcpy(C[*pcT].codigopostal, "4052-107");
    strcpy(C[*pcT].nporta, "800");
    strcpy(C[*pcT].numcontri, "123456783");
    strcpy(C[*pcT].cartaocredito, "1234567891123456");
    strcpy(C[*pcT].cartaocreditocve, "312");
    strcpy(C[*pcT].cartaocreditovalidade, "01/27");
    *pcT+=1;
}


//------------------------- Artigos ---------------------------------
//VOID PARA REGISTAR NOVO ARTIGO
void registarartigo(struct artigo A[],int *NA, int *paT,struct cores RGB){
    int numA = *paT;

    //INCREMENTA +1 AO ULTIMO NUMERO DE ARTIGO, POR APONTADOR PORQUE ALTERA O SEU ESTADO ANTERIOR
    *NA+=1;
    //GUARDA NA VARIAVEL O NUMERO DE ARTIGO
    A[numA].numeroartigo = *NA;


    printf("\n");
    //PRINTF QUE IDENTIFICA QUAL O NUMERO DO ARTIGO A SER REGISTADO
    printf("%s Registar Artigo Numero:%s %04d\n",RGB.verde,RGB.fimcor, A[numA].numeroartigo);
    printf("\n");

    do {
        fflush(stdin);
        printf("%s *Nome Artigo:%s ",RGB.verde,RGB.fimcor);
        fgets(A[numA].nomeartigo,101,stdin);
        printf("\n");
        A[numA].nomeartigo[strcspn(A[numA].nomeartigo, "\n")] = 0;
        int direcao = checkexite(A[numA].nomeartigo,0,RGB);
        if(direcao == 2) return;
    } while(checktext(A[numA].nomeartigo,2,100) != 0);                                          //REPETE DANDO 1 SE A STRING NAO FOR SO DE CARATERES "2" OU MAIOR QUE "100" ELEMENTOS NO VETOR, ISTO COM UMA FUNCAO

    do{
        fflush(stdin);
        printf("%s *Marca:%s ",RGB.verde,RGB.fimcor);
        fgets(A[numA].marcaartigo,101,stdin);
        printf("\n");
        A[numA].marcaartigo[strcspn(A[numA].marcaartigo, "\n")] = 0;
        int direcao = checkexite(A[numA].marcaartigo,0,RGB);
        if(direcao == 2) return;
    } while(checktext(A[numA].marcaartigo,2,100) !=0);                                       //REPETE DANDO 1 SE A STRING NAO FOR SO DE CARATERES "2" OU MAIOR QUE "100" ELEMENTOS NO VETOR, ISTO COM UMA FUNCAO

    do{
        fflush(stdin);
        printf("%s *Produto:%s ",RGB.verde,RGB.fimcor);
        fgets(A[numA].produtoartigo,101,stdin);
        printf("\n");
        A[numA].produtoartigo[strcspn(A[numA].produtoartigo, "\n")] = 0;
        int direcao = checkexite(A[numA].produtoartigo,0,RGB);
        if(direcao == 2) return;
    } while(checktext(A[numA].produtoartigo,2,100) !=0);                                     //REPETE DANDO 1 SE A STRING NAO FOR SO DE CARATERES "2" OU MAIOR QUE "100" ELEMENTOS NO VETOR, ISTO COM UMA FUNCAO

    do{
        fflush(stdin);
        printf("%s *Categoria:%s ",RGB.verde,RGB.fimcor);
        fgets(A[numA].categoriaartigo,101,stdin);
        printf("\n");
        A[numA].categoriaartigo[strcspn(A[numA].categoriaartigo, "\n")] = 0;
        int direcao = checkexite(A[numA].categoriaartigo,0,RGB);
        if(direcao == 2) return;
    }  while(checktext(A[numA].categoriaartigo,2,100) != 0);                                 //REPETE DANDO 1 SE A STRING NAO FOR SO DE CARATERES "2" OU MAIOR QUE "100" ELEMENTOS NO VETOR, ISTO COM UMA FUNCAO

    do{
        fflush(stdin);
        printf("%s *Sub-Categoria:%s ",RGB.verde,RGB.fimcor);
        fgets(A[numA].subcategoriaartigo,101,stdin);
        printf("\n");
        A[numA].subcategoriaartigo[strcspn(A[numA].subcategoriaartigo, "\n")] = 0;
        int direcao = checkexite(A[numA].subcategoriaartigo,1,RGB);
        if(direcao == 2) return;
    } while(checktext(A[numA].subcategoriaartigo,2,100) != 0);                               //REPETE DANDO 1 SE A STRING NAO FOR SO DE CARATERES "2" OU MAIOR QUE "100" ELEMENTOS NO VETOR, ISTO COM UMA FUNCAO

    do{
        fflush(stdin);
        printf("%s *Cor:%s ",RGB.verde,RGB.fimcor);
        fgets(A[numA].corartigo,101,stdin);
        printf("\n");
        A[numA].corartigo[strcspn(A[numA].corartigo, "\n")] = 0;
        int direcao = checkexite(A[numA].corartigo,0,RGB);
        if(direcao == 2) return;
    } while(checktext(A[numA].corartigo,2,100) != 0);                                   //REPETE DANDO 1 SE A STRING NAO FOR SO DE CARATERES "2" OU MAIOR QUE "100" ELEMENTOS NO VETOR, ISTO COM UMA FUNCAO

    do{
        fflush(stdin);
        printf("%s *Tamanho:%s ",RGB.verde,RGB.fimcor);
        fgets(A[numA].tamanhoartigo,101,stdin);
        printf("\n");
        A[numA].tamanhoartigo[strcspn(A[numA].tamanhoartigo, "\n")] = 0;
        int direcao = checkexite(A[numA].tamanhoartigo,0,RGB);
        if(direcao == 2) return;
    } while (checktext(A[numA].tamanhoartigo,3,100) != 0);                                   //REPETE DANDO 1 SE A STRING TIVER MAIOR QUE "100" ELEMENTOS NO VETOR, PODENDO CONTER NUMEROS E CARATERES "3", ISTO COM UMA FUNCAO

    do {
        fflush(stdin);
        printf("%s *Preco (euro):%s ",RGB.verde,RGB.fimcor);
        fgets(A[numA].precoartigo,101,stdin);
        printf("\n");
        A[numA].precoartigo[strcspn(A[numA].precoartigo, "\n")] = 0;
        int direcao = checkexite(A[numA].precoartigo,0,RGB);
        if(direcao == 2) return;
    } while(checktext(A[numA].precoartigo,1,100) != 0);                                      //REPETE DANDO 1 SE A STRING NAO FOR SO DE NUMEROS "1" OU MAIOR QUE "100" ELEMENTOS NO VETOR, ISTO COM UMA FUNCAO

    *paT += 1;                                                                                  //INCREMENTA (+1) AO (TOTAL DE ARTIGOS POR APONTADOR)

    printf("\n");
    printf("%s Artigo Registado!! %s\n",RGB.verde,RGB.fimcor);
    printf("\n");

}

//VOID PARA MOSTRAR UM SO ARTIGO INDICADO NA VARIAVEL (pa)
void mostrarartigo(struct artigo A[], int pa, struct cores RGB){

    //MOSTRA A INFORMACAO NA STRING INDICADA [pa]
    printf("%s |------------------------------------%s\n",RGB.verde,RGB.fimcor);
    printf("%s | Numero do Artigo:%s %04d\n",RGB.verde,RGB.fimcor, A[pa].numeroartigo);
    printf("%s | Nome do Artigo:%s   %s\n",RGB.verde,RGB.fimcor, A[pa].nomeartigo);
    printf("%s | Marca do Artigo:%s  %s\n",RGB.verde,RGB.fimcor, A[pa].marcaartigo);
    printf("%s | Produto:%s          %s\n",RGB.verde,RGB.fimcor, A[pa].produtoartigo);
    printf("%s | Categoria:%s        %s\n",RGB.verde,RGB.fimcor, A[pa].categoriaartigo);
    printf("%s | Sub-Categoria:%s    %s\n",RGB.verde,RGB.fimcor, A[pa].subcategoriaartigo);
    printf("%s | Cor:%s              %s\n",RGB.verde,RGB.fimcor, A[pa].corartigo);
    printf("%s | Tamanho:%s          %s\n",RGB.verde,RGB.fimcor, A[pa].tamanhoartigo);
    printf("%s | Preco:%s            %s euros\n",RGB.verde,RGB.fimcor, A[pa].precoartigo);
}

//VOID PARA MOSTRAR TODOS OS ARTIGOS
void mostrarlistaartigos(struct artigo A[], int paT, struct cores RGB){
    printf("\n");
    //PRINTF COM INDICADOR DE TOTAL DE ARTIGOS
    printf("%s Lista Total Artigos:%s %d\n",RGB.azul,RGB.fimcor, paT);
    printf("\n");

    for (int i=0; i < paT; i++) {
        //MOSTRA A INFORMACAO NA STRING INDICADA [i]
        printf("%s |------------------------------------%s\n",RGB.verde,RGB.fimcor);
        printf("%s | Numero do Artigo:%s %04d\n",RGB.verde,RGB.fimcor, A[i].numeroartigo);
        printf("%s | Nome do Artigo:%s   %s\n",RGB.verde,RGB.fimcor, A[i].nomeartigo);
        printf("%s | Marca do Artigo:%s  %s\n",RGB.verde,RGB.fimcor, A[i].marcaartigo);
        printf("%s | Produto:%s          %s\n",RGB.verde,RGB.fimcor, A[i].produtoartigo);
        printf("%s | Categoria:%s        %s\n",RGB.verde,RGB.fimcor, A[i].categoriaartigo);
        printf("%s | Sub-Categoria:%s    %s\n",RGB.verde,RGB.fimcor, A[i].subcategoriaartigo);
        printf("%s | Cor:%s              %s\n",RGB.verde,RGB.fimcor, A[i].corartigo);
        printf("%s | Tamanho:%s          %s\n",RGB.verde,RGB.fimcor, A[i].tamanhoartigo);
        printf("%s | Preco:%s            %s euro/s\n",RGB.verde,RGB.fimcor, A[i].precoartigo);
        printf("\n");
    }
}

//VOID PARA REMOVER UM SO ARTIGO INDICADO NA VARIAVEL (re_numartigo)
void removerartigo(struct artigo A[], int *paT, int re_numartigo, struct cores RGB){

    for (int i = 0; i < *paT-1; i++) {                                                          //INCREMENTA (i++) ATE AO (TOTAL DE ARTIGOS - 1 POR APONTADOR)
        if (i == re_numartigo) {                                                                //QUANDO (i) FOR IGUAL A VARIAVEL DO NUMERO ARTGIO INDICADA
            A[i] = A[i+1];                                                                      //COPIA PARA O ELEMENTO INFERIOR [i] O ELEMENTO SUPERIOR [i+1]
        } else if (i > re_numartigo) {                                                          //SENAO SE O (i) FOR MAIOR QUE O INDICADO)
            A[i] = A[i+1];                                                                      //COPIA PARA O ELEMENTO INFERIOR [i] O ELEMENTO SUPERIOR [i+1]
        }
    }

    *paT -= 1;                                                                                  //DECREMENTA (-1) AO (TOTAL DE ARTIGOS POR APONTADOR)                                                                             //VARIAVEL QUE DECLARA QUE ELIMINOU ARTIGO POR APONTADOR

    printf("\n");
    printf("%s Artigo Removido!! %s\n",RGB.vermelho,RGB.fimcor);

}


//------------------------ Clientes --------------------------------------------------------------------------------------------
//VOID PARA REGISTAR NOVO CLIENTE
void registarcliente(struct cliente C[], int *NC, int *pcT,struct cores RGB, int tipo){
    int numC = *pcT, num = 0, num2 = 0, num3 = 0;
    int dias[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    char nick[12];

    //INCREMENTA +1 AO ULTIMO NUMERO DE CLIENTES, POR APONTADOR PORQUE ALTERA O SEU ESTADO ANTERIOR
    *NC+=1;
    //GUARDA NA VARIAVEL O NUMERO DE CLIENTES
    C[numC].numcliente = *NC;

    //PRINTF QUE IDENTIFICA QUAL O NUMERO DO ARTIGO A SER REGISTADO
    printf("%s Cliente Numero:%s %04d\n",RGB.verde,RGB.fimcor, C[numC].numcliente);
    printf("\n");

    do {
        fflush(stdin);
        printf("%s *Nickname:%s ",RGB.verde,RGB.fimcor);
        fgets(nick,13,stdin);
        nick[strcspn(nick, "\n")] = 0;
        printf("\n");
        int direcao = checkexite(nick,0,RGB);
        if(direcao == 2) return;
    } while (checktext(nick,2,11) != 0 || checknick(C,nick,*pcT,RGB) != 0);
    strcpy(C[numC].nickname,nick);

    do{
        fflush(stdin);
        printf("%s *Pin (4 digitos):%s ",RGB.verde,RGB.fimcor);
        fgets(C[numC].pin,6,stdin);
        printf("\n");
        C[numC].pin[strcspn(C[numC].pin, "\n")] = 0;
        int direcao = checkexite(C[numC].pin,0,RGB);
        if(direcao == 2) return;
        } while (checktext(C[numC].pin,4,4) != 0);                                            //REPETE DANDO 1 SE A STRING NAO FOR SO DE NUMEROS MAS ESPECIAL "4" PORQUE TEM QUE TER "4" ELEMENTOS NO VETOR, ISTO COM UMA FUNCAO

    do {
        fflush(stdin);
        printf("%s *Nome e Apelido:%s ",RGB.verde,RGB.fimcor);
        fgets(C[numC].nome_completo,101,stdin);
        printf("\n");
        C[numC].nome_completo[strcspn(C[numC].nome_completo, "\n")] = 0;
        int direcao = checkexite(C[numC].nome_completo,0,RGB);
        if(direcao == 2) return;
    } while (checktext(C[numC].nome_completo,2,100) != 0);                                 //REPETE DANDO 1 SE A STRING NAO FOR SO DE CARATERES "2" OU MAIOR QUE "100" ELEMENTOS NO VETOR, ISTO COM UMA FUNCAO

    do{
        fflush(stdin);
        printf("%s *N.Contribuinte (9 digitos):%s ",RGB.verde,RGB.fimcor);
        fgets(C[numC].numcontri,11,stdin);
        printf("\n");
        C[numC].numcontri[strcspn(C[numC].numcontri, "\n")] = 0;
        int direcao = checkexite(C[numC].numcontri,0,RGB);
        if(direcao == 2) return;
    } while (checktext(C[numC].numcontri,4,9) != 0);                                           //REPETE DANDO 1 SE A STRING NAO FOR SO DE NUMEROS MAS ESPECIAL "4" PORQUE TEM QUE TER "9" ELEMENTOS NO VETOR, ISTO COM UMA FUNCAO

//------------------------------------------------------------------------------------ Inicio de Nascimento
    printf("%s *Nascimento%s \n",RGB.verde,RGB.fimcor);
        do{
            fflush(stdin);
            printf("%s  *Ano:%s ",RGB.verde,RGB.fimcor);
            fgets(C[numC].nascimentoano,6,stdin);
            C[numC].nascimentoano[strcspn(C[numC].nascimentoano, "\n")] = 0;
            int direcao = checkexite(C[numC].nascimentoano,0,RGB);
            if(direcao == 2) return;
            num3 = atoi(C[numC].nascimentoano);
        } while (checktext(C[numC].nascimentoano,1,4) != 0 || num3 < 1 || num3 > 9999 || checkzeros(C[numC].nascimentoano) != 0);       //(REPETE DANDO 1 SE A STRING NAO FOR SO DE NUMEROS MAS ESPECIAL "4" PORQUE TEM QUE TER "4" ELEMENTOS NO VETOR, ISTO COM UMA FUNCAO) OU (NUM MENOR QUE 1000) OU (NUM MAIOR QUE 3000)
        if(AnoBissexto(num3)==1) dias[1] = 29;
        if(AnoBissexto(num3)==0) dias[1] = 28;
        do{
            fflush(stdin);
            printf("%s  *Mes:%s ",RGB.verde,RGB.fimcor);
            fgets(C[numC].nascimentomes,4,stdin);
            C[numC].nascimentomes[strcspn(C[numC].nascimentomes, "\n")] = 0;
            int direcao = checkexite(C[numC].nascimentomes,0,RGB);
            if(direcao == 2) return;
            num2 = atoi(C[numC].nascimentomes);
        } while (checktext(C[numC].nascimentomes,1,2) != 0 || num2 < 1 || num2 > 12 || checkzeros(C[numC].nascimentomes) != 0);         //(REPETE DANDO 1 SE A STRING NAO FOR SO DE NUMEROS "1" OU MAIOR QUE "2" ELEMENTOS NO VETOR, ISTO COM UMA FUNCAO) OU (NUM MENOR QUE 1) OU (NUM MAIOR QUE 12)
        do{
            fflush(stdin);
            printf("%s  *Dia:%s ",RGB.verde,RGB.fimcor);
            fgets(C[numC].nascimentodia,4,stdin);
            C[numC].nascimentodia[strcspn(C[numC].nascimentodia, "\n")] = 0;
            int direcao = checkexite(C[numC].nascimentodia,0,RGB);
            if(direcao == 2) return;
            num = atoi(C[numC].nascimentodia);
        } while (checktext(C[numC].nascimentodia,1,2) != 0 || num  < 1 || num  > dias[num2-1] || checkzeros(C[numC].nascimentodia) != 0);   //(REPETE DANDO 1 SE A STRING NAO FOR SO DE NUMEROS "1" OU MAIOR QUE "2" ELEMENTOS NO VETOR, ISTO COM UMA FUNCAO) OU (NUM MENOR QUE 1) OU (NUM MAIOR QUE O ELEMENTO DA VARIAVEL (dias))
        strcpy(C[numC].nascimento,"\0");
        if(num < 10) strcat(C[numC].nascimento,"0");
        strcat(C[numC].nascimento,C[numC].nascimentodia);
        strcat(C[numC].nascimento,"/");
        if(num2 < 10) strcat(C[numC].nascimento,"0");
        strcat(C[numC].nascimento,C[numC].nascimentomes);
        strcat(C[numC].nascimento,"/");
        if(num3 < 1000) strcat(C[numC].nascimento,"0");
        if(num3 < 100) strcat(C[numC].nascimento,"0");
        if(num3 < 10) strcat(C[numC].nascimento,"0");
        strcat(C[numC].nascimento,C[numC].nascimentoano);
        printf("%s  *Data de Nascimento:%s %s \n",RGB.verde,RGB.fimcor,C[numC].nascimento);
        printf("\n");
//------------------------------------------------------------------------------------ Fim de Nascimento

    do{
        fflush(stdin);
        printf("%s - Introduza -1 para nao preencher - %s \n",RGB.amarelo,RGB.fimcor);
        printf("%s Telemovel (9 digitos):%s ",RGB.verde,RGB.fimcor);
        fgets(C[numC].telemovel,11,stdin);
        printf("\n");
        C[numC].telemovel[strcspn(C[numC].telemovel, "\n")] = 0;
        int direcao = checkexite(C[numC].telemovel,1,RGB);
        if(direcao == 1){
            strcpy(C[numC].telemovel,"");
            break;
        } else if(direcao == 2) return;
    } while (checktext(C[numC].telemovel,4,9) != 0);                                           //REPETE DANDO 1 SE A STRING NAO FOR SO DE NUMEROS MAS ESPECIAL "4" PORQUE TEM QUE TER "9" ELEMENTOS NO VETOR, ISTO COM UMA FUNCAO

    do{
        fflush(stdin);
        printf("%s *Morada:%s ",RGB.verde,RGB.fimcor);
        fgets(C[numC].morada,101,stdin);
        printf("\n");
        C[numC].morada[strcspn(C[numC].morada, "\n")] = 0;
        int direcao = checkexite(C[numC].morada,0,RGB);
        if(direcao == 2) return;
    } while (checktext(C[numC].morada,3,100) != 0);                                            //REPETE DANDO 1 SE A STRING NAO FOR SO DE CARATERES "2" OU MAIOR QUE "100" ELEMENTOS NO VETOR, ISTO COM UMA FUNCAO

    do{
        fflush(stdin);
        printf("%s ->*Numero de porta:%s ",RGB.verde,RGB.fimcor);
        fgets(C[numC].nporta,12,stdin);
        printf("\n");
        C[numC].nporta[strcspn(C[numC].nporta, "\n")] = 0;
        int direcao = checkexite(C[numC].nporta,0,RGB);
        if(direcao == 2) return;
    } while (checktext(C[numC].nporta,3,10) != 0);                                             //REPETE DANDO 1 SE A STRING TIVER MAIOR QUE "10" ELEMENTOS NO VETOR, PODENDO CONTER NUMEROS E CARATERES "3", ISTO COM UMA FUNCAO

//------------------------------------------------------------------------------------ Inicio de Codigo Postal
        printf("%s ->*Codigo Postal%s \n",RGB.verde,RGB.fimcor);
        do{
            fflush(stdin);
            printf("%s    >*(****-000):%s ",RGB.verde,RGB.fimcor);
            fgets(C[numC].codigopostalquatro,6,stdin);
            C[numC].codigopostalquatro[strcspn(C[numC].codigopostalquatro, "\n")] = 0;
            int direcao = checkexite(C[numC].codigopostalquatro,0,RGB);
            if(direcao == 2) return;
            num = atoi(C[numC].codigopostalquatro);
        } while (checktext(C[numC].codigopostalquatro,1,4) != 0 || num < 1 || num > 9999 || checkzeros(C[numC].codigopostalquatro) != 0);     //(REPETE DANDO 1 SE A STRING NAO FOR SO DE NUMEROS "1" OU MAIOR QUE "4" ELEMENTOS NO VETOR, ISTO COM UMA FUNCAO) OU (NUM MENOR QUE 1) OU (NUM MAIOR QUE 9999)
        do{
            fflush(stdin);
            printf("%s    >*(%4d-***):%s ",RGB.verde,num,RGB.fimcor);
            fgets(C[numC].codigopostaltres,5,stdin);
            C[numC].codigopostaltres[strcspn(C[numC].codigopostaltres, "\n")] = 0;
            int direcao = checkexite(C[numC].codigopostaltres,0,RGB);
            if(direcao == 2) return;
            num2 = atoi(C[numC].codigopostaltres);
        } while (checktext(C[numC].codigopostaltres,1,3) != 0 || num2  < 1 || num2  > 999 || checkzeros(C[numC].codigopostaltres) != 0);    //(REPETE DANDO 1 SE A STRING NAO FOR SO DE NUMEROS "1" OU MAIOR QUE "3" ELEMENTOS NO VETOR, ISTO COM UMA FUNCAO) OU (NUM MENOR QUE 1) OU (NUM MAIOR QUE 999)
        strcpy(C[numC].codigopostal,"\0");
        if(num < 1000) strcat(C[numC].codigopostal,"0");
        if(num < 100) strcat(C[numC].codigopostal,"0");
        if(num < 10) strcat(C[numC].codigopostal,"0");
        strcat(C[numC].codigopostal,C[numC].codigopostalquatro);
        strcat(C[numC].codigopostal,"-");
        if(num2 < 100) strcat(C[numC].codigopostal,"0");
        if(num2 < 10) strcat(C[numC].codigopostal,"0");
        strcat(C[numC].codigopostal,C[numC].codigopostaltres);
        printf("%s  >*Codigo Postal:%s %s \n",RGB.verde,RGB.fimcor,C[numC].codigopostal);
        printf("\n");

//------------------------------------------------------------------------------------ Fim de Codigo Postal
    do{
        fflush(stdin);
        printf("%s ->*Cidade:%s ",RGB.verde,RGB.fimcor);
        fgets(C[numC].cidade,101,stdin);
        printf("\n");
        C[numC].cidade[strcspn(C[numC].cidade, "\n")] = 0;
        int direcao = checkexite(C[numC].cidade,0,RGB);
        if(direcao == 2) return;
    } while (checktext(C[numC].cidade,2,100) != 0);                                            //REPETE DANDO 1 SE A STRING NAO FOR SO DE CARATERES "2" OU MAIOR QUE "100" ELEMENTOS NO VETOR, ISTO COM UMA FUNCAO

    if(numC == 0 || tipo == 0){
        do{
            fflush(stdin);
            printf("%s *Tipo de cliente ( NORMA / GOLDE / ADMIN):%s ",RGB.verde,RGB.fimcor);
            fgets(C[numC].tipocliente,6,stdin);
            printf("\n");
            C[numC].tipocliente[strcspn(C[numC].tipocliente, "\n")] = 0;
            int direcao = checkexite(C[numC].tipocliente,0,RGB);
            if(direcao == 2) return;
        } while (checktext(C[numC].tipocliente,5,5) != 0);                                         //REPETE DANDO 1 SE A STRING NAO FOR SO DE CARATERES MAS ESPECIAL "5" PORQUE TEM QUE TER "5" ELEMENTOS NO VETOR, ISTO COM UMA FUNCAO
    } else {
        strcpy(C[numC].tipocliente,"NORMA");
    }

    do{
        fflush(stdin);
        printf("%s *Cartao Credito (16 digitos):%s ",RGB.verde,RGB.fimcor);
        fgets(C[numC].cartaocredito,18,stdin);
        printf("\n");
        C[numC].cartaocredito[strcspn(C[numC].cartaocredito, "\n")] = 0;
        int direcao = checkexite(C[numC].cartaocredito,0,RGB);
        if(direcao == 2) return;
    } while (checktext(C[numC].cartaocredito,4,16) != 0);                                      //REPETE DANDO 1 SE A STRING NAO FOR SO DE NUMEROS MAS ESPECIAL "4" PORQUE TEM QUE TER "16" ELEMENTOS NO VETOR, ISTO COM UMA FUNCAO

    do{
        fflush(stdin);
        printf("%s ->*Cartao Credito CVE (3 digitos):%s ",RGB.verde,RGB.fimcor);
        fgets(C[numC].cartaocreditocve,5,stdin);
        printf("\n");
        C[numC].cartaocreditocve[strcspn(C[numC].cartaocreditocve, "\n")] = 0;
        int direcao = checkexite(C[numC].cartaocreditocve,0,RGB);
        if(direcao == 2) return;
    }  while (checktext(C[numC].cartaocreditocve,4,3) != 0);                                   //REPETE DANDO 1 SE A STRING NAO FOR SO DE NUMEROS MAS ESPECIAL "4" PORQUE TEM QUE TER "3" ELEMENTOS NO VETOR, ISTO COM UMA FUNCAO

//--------------------------------------------------------------------------------------------- Inicio de Cartao Credito Data Validade
    printf("%s ->*Cartao Credito Data Validade%s \n",RGB.verde,RGB.fimcor);
    do{
        fflush(stdin);
        printf("%s                          >*Mes:%s ",RGB.verde,RGB.fimcor);
        fgets(C[numC].cartaocreditovalidademes,4,stdin);
        C[numC].cartaocreditovalidademes[strcspn(C[numC].cartaocreditovalidademes, "\n")] = 0;
        int direcao = checkexite(C[numC].cartaocreditovalidademes,0,RGB);
        if(direcao == 2) return;
        num2 = atoi(C[numC].cartaocreditovalidademes);
    } while (checktext(C[numC].cartaocreditovalidademes,1,2) != 0 || num2 < 1 || num2 > 12 || checkzeros(C[numC].cartaocreditovalidademes) != 0);//(REPETE DANDO 1 SE A STRING NAO FOR SO DE NUMEROS "1" OU MAIOR QUE "2" ELEMENTOS NO VETOR, ISTO COM UMA FUNCAO) OU (NUM MENOR QUE 1) OU (NUM MAIOR QUE 12)
    do{
        fflush(stdin);
        printf("%s                          >*Ano:%s ",RGB.verde,RGB.fimcor);
        fgets(C[numC].cartaocreditovalidadeano,4,stdin);
        C[numC].cartaocreditovalidadeano[strcspn(C[numC].cartaocreditovalidadeano, "\n")] = 0;
        int direcao = checkexite(C[numC].cartaocreditovalidadeano,0,RGB);
        if(direcao == 2) return;
        num = atoi(C[numC].cartaocreditovalidadeano);
    } while (checktext(C[numC].cartaocreditovalidadeano,1,2) != 0 || num < 0 || num > 99);                                      //(REPETE DANDO 1 SE A STRING NAO FOR SO DE NUMEROS "1" OU MAIOR QUE "2" ELEMENTOS NO VETOR, ISTO COM UMA FUNCAO) OU (NUM MENOR QUE 0) OU (NUM MAIOR QUE 99)
    strcpy(C[numC].cartaocreditovalidade,"\0");
    if(num2 < 10) strcat(C[numC].cartaocreditovalidade,"0");
    strcat(C[numC].cartaocreditovalidade,C[numC].cartaocreditovalidademes);
    strcat(C[numC].cartaocreditovalidade,"/");
    if(num < 10) strcat(C[numC].cartaocreditovalidade,"0");
    sprintf(C[numC].cartaocreditovalidadeano, "%d", num);
    strcat(C[numC].cartaocreditovalidade,C[numC].cartaocreditovalidadeano);
    printf("%s                >*Data Validade:%s %s\n",RGB.verde,RGB.fimcor,C[numC].cartaocreditovalidade);
    printf("\n");
//------------------------------------------------------------------------------------ Fim de Cartao Credito Data Validade

    *pcT += 1;                                                                                                                  //INCREMENTA (+1) AO (TOTAL DE CLIENTES POR APONTADOR)

    printf("\n");
    printf("%s Cliente Registado!! %s\n",RGB.verde,RGB.fimcor);
    printf("\n");
}

//VOID PARA MOSTRAR UM SO CLINTE INDICADO NA VARIAVEL (pc)
void mostrarcliente(struct cliente C[],int pc,struct cores RGB){

    //MOSTRA A INFORMACAO NA STRING INDICADA [pc]
    printf("%s |-----------------------------------------%s\n",RGB.verde,RGB.fimcor);
    printf("%s | Cliente numero:%s      %04d \n",RGB.verde,RGB.fimcor, C[pc].numcliente);
    printf("%s | Nickname:%s            %s \n",RGB.verde,RGB.fimcor, C[pc].nickname);
    printf("%s | Pin (4 Digitos):%s     %s \n",RGB.verde,RGB.fimcor, C[pc].pin);
    printf("%s | Nome Completo:%s       %s \n",RGB.verde,RGB.fimcor, C[pc].nome_completo);
    printf("%s | Numero Contribuinte:%s %s \n",RGB.verde,RGB.fimcor, C[pc].numcontri);
    printf("%s | Nascimento:%s          %s \n",RGB.verde,RGB.fimcor, C[pc].nascimento);
    printf("%s | Telemovel:%s           %s \n",RGB.verde,RGB.fimcor, C[pc].telemovel);
    printf("%s | Morada:%s              %s \n",RGB.verde,RGB.fimcor, C[pc].morada);
    printf("%s | Numero da porta:%s     %s \n",RGB.verde,RGB.fimcor, C[pc].nporta);
    printf("%s | Codigo Postal:%s       %s \n",RGB.verde,RGB.fimcor, C[pc].codigopostal);
    printf("%s | Cidade:%s              %s \n",RGB.verde,RGB.fimcor, C[pc].cidade);
    printf("%s | Tipo Cliente:%s        %s \n",RGB.verde,RGB.fimcor, C[pc].tipocliente);
    printf("%s | Cartao Credito:%s      %s \n",RGB.verde,RGB.fimcor, C[pc].cartaocredito);
    printf("%s |  -> CVE:%s             %s \n",RGB.verde,RGB.fimcor, C[pc].cartaocreditocve);
    printf("%s |  -> Validade:%s        %s \n",RGB.verde,RGB.fimcor, C[pc].cartaocreditovalidade);
    printf("\n");
}

//VOID PARA MOSTRAR TODOS OS CLIENTES
void mostrarlistaclientes(struct cliente C[],int pcT,struct cores RGB){
    printf("\n");
    //PRINTF COM INDICADOR DE TOTAL DE CLIENTES
    printf("%s Lista Total Clientes:%s %d\n",RGB.azul,RGB.fimcor, pcT);
    printf("\n");

    for (int i = 0; i < pcT; i++) {
        //MOSTRA A INFORMACAO NA STRING INDICADA [i]
        printf("%s |-----------------------------------------%s\n",RGB.verde,RGB.fimcor);
        printf("%s | Cliente numero:%s      %04d \n",RGB.verde,RGB.fimcor, C[i].numcliente);
        printf("%s | Nickname:%s            %s \n",RGB.verde,RGB.fimcor, C[i].nickname);
        printf("%s | Pin (4 Digitos):%s     %s \n",RGB.verde,RGB.fimcor, C[i].pin);
        printf("%s | Nome Completo:%s       %s \n",RGB.verde,RGB.fimcor, C[i].nome_completo);
        printf("%s | Numero Contribuinte:%s %s \n",RGB.verde,RGB.fimcor, C[i].numcontri);
        printf("%s | Nascimento:%s          %s \n",RGB.verde,RGB.fimcor, C[i].nascimento);
        printf("%s | Telemovel:%s           %s \n",RGB.verde,RGB.fimcor, C[i].telemovel);
        printf("%s | Morada:%s              %s \n",RGB.verde,RGB.fimcor, C[i].morada);
        printf("%s | Numero da porta:%s     %s \n",RGB.verde,RGB.fimcor, C[i].nporta);
        printf("%s | Codigo Postal:%s       %s \n",RGB.verde,RGB.fimcor, C[i].codigopostal);
        printf("%s | Cidade:%s              %s \n",RGB.verde,RGB.fimcor, C[i].cidade);
        printf("%s | Tipo Cliente:%s        %s \n",RGB.verde,RGB.fimcor, C[i].tipocliente);
        printf("%s | Cartao Credito:%s      %s \n",RGB.verde,RGB.fimcor, C[i].cartaocredito);
        printf("%s |  -> CVE:%s             %s \n",RGB.verde,RGB.fimcor, C[i].cartaocreditocve);
        printf("%s |  -> Validade:%s        %s \n",RGB.verde,RGB.fimcor, C[i].cartaocreditovalidade);
        printf("\n");
    }
}

//VOID PARA REMOVER UM SO CLINTE INDICADO NA VARIAVEL (re_numcliente)
void removercliente(struct cliente C[], int *pcT, int re_numcliente, struct cores RGB){

    for (int i = 0; i < *pcT-1; i++) {                                                          //INCREMENTA (i++) ATE AO (TOTAL DE CLIENTES - 1 POR APONTADOR)
        if (i == re_numcliente) {                                                               //QUANDO (i) FOR IGUAL A VARIAVEL DO NUMERO ARTGIO INDICADA
            C[i] = C[i+1];                                                                      //COPIA PARA O ELEMENTO INFERIOR [i] O ELEMENTO SUPERIOR [i+1]
        } else if (i > re_numcliente) {                                                         //SENAO SE O (i) FOR MAIOR QUE O INDICADO)
            C[i] = C[i+1];                                                                      //COPIA PARA O ELEMENTO INFERIOR [i] O ELEMENTO SUPERIOR [i+1]
        }
    }

    *pcT -= 1;                                                                                  //DECREMENTA (-1) AO (TOTAL DE ARTIGOS POR APONTADOR)

    printf("\n");
    printf("%s Cliente Removido!! %s\n",RGB.vermelho,RGB.fimcor);
}


//------------------------- Tools ----------------------------------------------
//INT PARA NAO PERMITIR ZEROS
int checkzeros(char str[]){
    int ret = -1, i = 0;
    char intnum[10], numero[10];

    for(i; i <= 10; i++){
        strcpy(numero,"");
        sprintf(intnum, "%d", i);
        strcat(numero,intnum);

        if(strcmp(str,numero) == 0) ret = 0;

        strcpy(numero,"");
        strcat(numero,"0");
        sprintf(intnum, "%d", i);
        strcat(numero,intnum);

        if(strcmp(str,numero) == 0) ret = 1;

        strcpy(numero,"");
        strcat(numero,"00");
        sprintf(intnum, "%d", i);
        strcat(numero,intnum);

        if(strcmp(str,numero) == 0) ret = 2;
    }

    for(i; i <= 100; i++){
        strcpy(numero,"");
        sprintf(intnum, "%d", i);
        strcat(numero,intnum);

        if(strcmp(str,numero) == 0) ret = 0;

        strcpy(numero,"");
        strcat(numero,"0");
        sprintf(intnum, "%d", i);
        strcat(numero,intnum);

        if(strcmp(str,numero) == 0) ret = 3;

        strcpy(numero,"");
        strcat(numero,"00");
        sprintf(intnum, "%d", i);
        strcat(numero,intnum);

        if(strcmp(str,numero) == 0) ret = 4;
    }

    for(i; i <= 1000; i++){
        strcpy(numero,"");
        sprintf(intnum, "%d", i);
        strcat(numero,intnum);

        if(strcmp(str,numero) == 0) ret = 0;

        strcpy(numero,"");
        strcat(numero,"0");
        sprintf(intnum, "%d", i);
        strcat(numero,intnum);

        if(strcmp(str,numero) == 0) ret = 5;

    }

    for(i; i <= 9999; i++){
        strcpy(numero,"");
        sprintf(intnum, "%d", i);
        strcat(numero,intnum);

        if(strcmp(str,numero) == 0) ret = 0;
    }

    return ret;
}

//INT PARA SAIR NOS LOCAIS SEM IDICACAO DE "0"
int checkexite(char str[],int skip, struct cores RGB){
    int ret = -1;

    if(strcmp(str,"-1") == 0 && skip == 1){
        printf("%s Desistiu desta parte!! %s\n\n",RGB.vermelho,RGB.fimcor);
        ret = 1;
    }

    if(strcmp(str,"-2") == 0){
        printf("%s retrocedeu o Menu!! %s\n\n",RGB.vermelho,RGB.fimcor);
        ret = 2;
    }

    return ret;
}

//METE OS CARATERES EM MAIUSCULO
void StringUpper(char string[]) {
	int i = 0;

	while (string[i] != '\0')
	{
    	if (string[i] >= 'a' && string[i] <= 'z') {
        	string[i] = string[i] - 32;
    	}
      	i++;
	}
}

//VERIFICA O NICKNAME DE MANEIRA A NAO REPETIR O MESMO
int checknick(struct cliente C[], char stri[], int pcT, struct cores RGB){
    int jatem = 0;

    StringUpper(stri);

    for (int i = 0; i < pcT; i++) {
        if (strcmp(C[i].nickname,stri) == 0) {
            jatem = 1;
        }
    }

    if(jatem == 1) printf("%s Ja existe o mesmo nome, tente outro!! %s\n\n",RGB.vermelho,RGB.fimcor);

    return jatem;
}

//BISSEXTO NA DATA DE NASCIMENTO
int AnoBissexto(int ano){
    return(ano%400==0 || (ano%100!=0 && ano%4==0));
}

//DEFINICAO DO "OPCAO"
int opcaoIntegerOnly(int pesquisa, char texto, int limite, int diferente){
    int num = 0, let = 0, opcao = -1;
    char ch[5];

    do {
        if(pesquisa == 0) printf(" *Opcao: "); // imprime " opcao: " se funcao EX:(0,0,*,*)
        if(pesquisa != 0) printf("%c",texto); // imprime o TEXTO que definir se na funcao EX:(1,char,*,*)

        fflush(stdin);
        fgets(ch,5,stdin);
        ch[strcspn(ch, "\n")] = 0;

        for (int i = 0; i < strlen(ch); i++) {
            // Contador so de Carateres
            if (isalpha(ch[i]) != 0) let++;
        }

        for (int i = 0; i < strlen(ch); i++) {
            // Contador so de numeros
            if (isdigit(ch[i]) != 0) num++;
        }

        opcao = atoi(ch);

        if (let == 0 && num > 0) {
            if(opcao >= 0 && opcao <= limite && diferente == 0) break; // limite (*,*,100,*) e diferente "==" EX:(*,*,*,0)
            if(opcao == limite && diferente != 0) break; // limite (*,*,100,*) e diferente "==" EX:(*,*,*,1)
        }

        let=0;
        num=0;
    } while (1);

    return (opcao);
}

//VERIFICA O TEXTO/NUMEROS SE ESTAO DENTRO DO PADRAO DEFINIDO
int checktext(char str[], int modo, int limite){
    int num = 0, let = 0, ret = -1;

    for (int i = 0; i < strlen(str); i++) {
        // Contador so de Carateres
        if (isalpha(str[i]) != 0) let++;
    }

    for (int i = 0; i < strlen(str); i++) {
        // Contador so de numeros
        if (isdigit(str[i]) != 0) num++;
    }

    if (let > 0) StringUpper(str); //Coloca minusculas em maiusculas

    if(modo == 1){ //So numeros com limite EX:(*,1,10,0)
        if(num > 0 && let == 0 && num <= limite){
            ret = 0;
        } else {
            ret = 1;
        }
    }

    if(modo == 2){ //So Carateres com limite EX:(*,2,10,0)
        if(let > 0 && num == 0 && let <= limite){
            ret = 0;
        } else {
            ret = 2;
        }
    }

    if(modo == 3){ //Misto com limite EX:(*,3,100,0)
        if(num+let > 0 && num+let <= limite){
            ret = 0;
        } else {
            ret = 3;
        }
    }

    if(modo == 4){ //So numeros com limite igual ao definido na funcao EX:(*,4,100,0)
        if(num > 0 && let == 0 && num == limite){
            ret = 0;
        } else {
            ret = 4;
        }
    }

    if(modo==5){ //So letras com limite igual ao definido na funcao EX:(*,5,100,0)
        if(num == 0 && let > 0 && let == limite){
            ret = 0;
        } else {
            ret = 4;
        }
    }

    if(let == 0 && num == 0){ // Repetir sse vazio
        ret = 5;
    }

    return ret;
}


//------------------------- Clientes / Artigos ---------------------------------
//VOID QUE PERMITE PESQUISAR CLIENTES E ARTIGOS (PESQUISA NORMA / EDITAR / ELIMINAR)
void pesquisar(struct cliente C[], struct artigo A[], int pcT, int paT, int *menu_editar, int *pc, int *pa, int opcaoexterna,struct cores RGB) {
    int opcao = -1, encontrado = 0;
    char modText[101], pesqnome[101], pesqnum[101], pesqnumA[101];

    if(opcaoexterna == 4 || opcaoexterna == 6) {
        strcpy(modText, "Eliminar");
    } else {
        strcpy(modText, "Editar");
    }

    //--------------------- Pesquisa normal Cliente/Artigo
    if(opcaoexterna == 1 || opcaoexterna == 2) { //-------------------------------------------------------- Por acabar

        //---------- Pesquisa normal para Clientes
        if(opcaoexterna == 1) {
            printf("%s Pesquisar Cliente: %s \n",RGB.azul,RGB.fimcor);
            printf("%s 1  -> Numero Contribuinte %s \n",RGB.verde,RGB.fimcor);
            printf("%s 2  -> Nome Cliente %s \n",RGB.verde,RGB.fimcor);
            printf("%s 0  -> Sair do Menu de Pesquisa de Cliente %s \n",RGB.amarelo,RGB.fimcor);

            opcao = opcaoIntegerOnly(0,0,2,0);

            switch(opcao) {
            case 0:
                printf("\n%s Saiu do Menu Pesquisa de Cliente!! %s \n\n",RGB.vermelho,RGB.fimcor);
                break;

            case 1:
                printf("\n");
                do {
                    fflush(stdin);
                    printf("%s Pesquisar Cliente por Numero Contribuinte: %s",RGB.azul,RGB.fimcor);
                    fgets(pesqnum,11,stdin);
                    pesqnum[strcspn(pesqnum, "\n")] = 0;
                    int direcao = checkexite(pesqnum,0,RGB);
                    if(direcao == 2) return;
                } while (checktext(pesqnum,4,9) != 0);

                for (int i = 0; i < pcT; i++) {
                    if (strcmp(C[i].numcontri, pesqnum) == 0) {
                        printf("\n"); printf("%s Este numero de contribuinte associado: %s\n",RGB.azul,RGB.fimcor);
                        mostrarcliente(C,i,RGB);
                        printf("\n");
                        encontrado=1;
                    }
                }

                if(encontrado == 0){
                    printf("%s Numero de Contribuinte nao associado!! %s \n",RGB.vermelho,RGB.fimcor);
                    encontrado=0;
                }

                break;

            case 2:
                printf("\n");
                do {
                    fflush(stdin);
                    printf("%s Pesquisar Cliente por Nome: %s",RGB.azul,RGB.fimcor);
                    fgets(pesqnome,101,stdin);
                    pesqnome[strcspn(pesqnome, "\n")] = 0;
                    int direcao = checkexite(pesqnome,0,RGB);
                    if(direcao == 2) return;
                } while (checktext(pesqnome,2,100) != 0);

                for (int i = 0; i < pcT; i++) {
                    if (strcmp(C[i].nome_completo, pesqnome) == 0) {
                        printf("%s Nome Cliente esta associado: %s \n",RGB.verde,RGB.fimcor);
                        mostrarcliente(C,i,RGB);
                        printf("\n");
                        encontrado=1;
                    }
                }

                if(encontrado == 0){
                    printf("%s Nome de Cliente nao associado!! %s \n",RGB.vermelho,RGB.fimcor);
                    encontrado=0;
                }

                break;
            }
        }

        //---------- Pesquisa normal para Artigos
        if(opcaoexterna == 2) {
            printf("\n");
            printf("%s Pesquisa de Artigos: %s \n",RGB.azul,RGB.fimcor);
            printf("%s 1  -> Numero do Artigo %s \n",RGB.verde,RGB.fimcor);
            printf("%s 0  -> Sair do Menu de Pesquisa de Artigo %s \n",RGB.amarelo,RGB.fimcor);

            opcao = opcaoIntegerOnly(0,0,1,0);

            switch(opcao) {
            case 0:
                printf("\n%s Saiu do Menu Pesquisa de Artigo!! %s \n\n",RGB.vermelho,RGB.fimcor);
                break;

            case 1:
                printf("\n");
                do {
                    fflush(stdin);
                    printf("%s Artigo com Numero: %s",RGB.azul,RGB.fimcor);
                    fgets(pesqnumA,101,stdin);
                    pesqnumA[strcspn(pesqnumA, "\n")] = 0;
                    int direcao = checkexite(pesqnumA,0,RGB);
                    if(direcao == 2) return;
                } while (checktext(pesqnumA,1,100) != 0 || atoi(pesqnumA) >= paT);

                for (int i = 0; i < paT; i++) {
                    if (atoi(pesqnumA) == A[i].numeroartigo) {
                        printf("\n"); printf("%s Numero de Artigo associado: %s\n",RGB.verde,RGB.fimcor);
                        mostrarartigo(A,i,RGB);
                        encontrado=1;
                    }
                }

                if(encontrado == 0) {
                    printf("%s Numero de Artigo nao associado!! %s \n",RGB.vermelho,RGB.fimcor);
                    encontrado=0;
                }

                break;
            }
        }
    }


    //--------------------- Pesquisar para o menu editar/eliminar Cliente
    if(opcaoexterna == 3 || opcaoexterna == 4) {
        printf("\n");
        printf("%s Pesquisa de Cliente para %s por: %s \n",RGB.azul,modText,RGB.fimcor);
        printf("%s 1  -> Numero Contribuinte %s \n",RGB.verde,RGB.fimcor);
        printf("%s 2  -> Nome Cliente %s \n",RGB.verde,RGB.fimcor);
        printf("%s 0  -> Sair do Menu de Pesquisa de Cliente %s \n",RGB.amarelo,RGB.fimcor);

        opcao = opcaoIntegerOnly(0,0,2,0);

        switch(opcao) {
        case 0:
            printf("\n%s Saiu do Menu Pesquisa para %s Cliente!! %s \n\n",RGB.azul,modText,RGB.fimcor);
            break;

        case 1:
            printf("\n");
            do {
                fflush(stdin);
                printf("%s %s Cliente com Numero Contribuinte: %s",RGB.azul,modText,RGB.fimcor);
                fgets(pesqnum,11,stdin);
                pesqnum[strcspn(pesqnum, "\n")] = 0;
                int direcao = checkexite(pesqnum,0,RGB);
                if(direcao == 2) return;
            } while (checktext(pesqnum,4,9) != 0);

            for (int i = 0; i < pcT; i++) {
                if (strcmp(C[i].numcontri, pesqnum) == 0) {
                    printf("\n"); printf("%s Numero de Contribuinte associado: %s\n",RGB.verde,RGB.fimcor);
                    mostrarcliente(C,i,RGB);
                    encontrado=1;
                    *menu_editar=1;
                    *pc=i;
                }
            }

            if(encontrado == 0){
                 printf("%s Numero de Contribuinte nao associado!! %s \n",RGB.vermelho,RGB.fimcor);
                 encontrado=0;
                *menu_editar=0;
            }

            break;

        case 2:
            printf("\n");
            do {
                fflush(stdin);
                printf("%s Pesquisar Cliente por Nome: %s",RGB.azul,RGB.fimcor);
                fgets(pesqnome,101,stdin);
                pesqnome[strcspn(pesqnome, "\n")] = 0;
                int direcao = checkexite(pesqnome,0,RGB);
                if(direcao == 2) return;
            } while (checktext(pesqnome,2,100) != 0);

            for (int i = 0; i < pcT; i++) {
                if (strcmp(C[i].nome_completo, pesqnome) == 0) {
                    printf("\n"); printf("%s Nome Cliente associado: %s \n",RGB.azul,RGB.fimcor);
                    mostrarcliente(C,i,RGB);
                    encontrado=1;
                    *menu_editar=1;
                    *pc=i;
                }
            }

            if(encontrado == 0){
                printf("%s Nome de Cliente nao associado!! %s \n",RGB.vermelho,RGB.fimcor);
                encontrado=0;
                *menu_editar=0;
            }

            break;
        }

    }

    //--------------------- Pesquisar para o menu editar/eliminar Artigo
    if(opcaoexterna == 5 || opcaoexterna == 6) {
        printf("\n");
        printf("%s Pesquisa de Artigos para %s por: %s \n",RGB.azul,modText,RGB.fimcor);
        printf("%s 1  -> Numero do Artigo %s \n",RGB.verde,RGB.fimcor);
        printf("%s 0  -> Sair do Menu de Pesquisa de Cliente %s \n",RGB.amarelo,RGB.fimcor);

        opcao = opcaoIntegerOnly(0,0,1,0);

        switch(opcao) {
        case 0:
            printf("\n%s Saiu do Menu Pesquisa para %s Artigo!! %s \n\n",RGB.azul,modText,RGB.fimcor);
            break;

        case 1:
            printf("\n");
            do {
                fflush(stdin);
                printf("%s %s Artigo com Numero: %s",RGB.azul,modText,RGB.fimcor);
                fgets(pesqnumA,101,stdin);
                pesqnumA[strcspn(pesqnumA, "\n")] = 0;
                int direcao = checkexite(pesqnumA,0,RGB);
                if(direcao == 2) return;
            } while (checktext(pesqnumA,1,100) != 0 || atoi(pesqnumA) >= paT);

            for (int i = 0; i < paT; i++) {
                if (atoi(pesqnumA) == A[i].numeroartigo) {
                    printf("\n"); printf("%s Numero de Artigo associado: %s\n",RGB.azul,RGB.fimcor);
                    mostrarartigo(A,i,RGB);
                    encontrado=1;
                    *menu_editar=2;
                    *pa=i;
                }
            }

            if(encontrado == 0) {
                printf("%s Numero de Artigo nao associado!! %s \n",RGB.vermelho,RGB.fimcor);
                encontrado=0;
                *menu_editar=0;
            }
            break;
        }
    }
}

//VOID PARA EDITAR CLIENTE / ARTIGO
void editar(struct cliente C[],struct artigo A[], int pcT, int paT, int *pc, int *pa, int *menu_editar,struct cores RGB,int tipo) {
    int opcao = 0, num = 0, num2 = 0, num3 = 0;
    int dias[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    char last[101];

    printf("\n");

    //-------------------- Editar Clientes
    if(*pc != -1 && *menu_editar == 1) {
        printf("%s Menu Editar Cliente:%s %04d\n",RGB.azul,RGB.fimcor, C[*pc].numcliente);
        printf("%s 1  -> Nickname %s \n",RGB.verde,RGB.fimcor);
        printf("%s 2  -> Pin %s \n",RGB.verde,RGB.fimcor);
        printf("%s 3  -> Nome Cliente %s \n",RGB.verde,RGB.fimcor);
        printf("%s 4  -> Numero de Contribuinte %s \n",RGB.verde,RGB.fimcor);
        printf("%s 5  -> Data de Nascimento %s \n",RGB.verde,RGB.fimcor);
        printf("%s 6  -> Telemovel %s \n",RGB.verde,RGB.fimcor);
        printf("%s 7  -> Morada %s \n",RGB.verde,RGB.fimcor);
        printf("%s 8  -> -Numero de Porta %s \n",RGB.verde,RGB.fimcor);
        printf("%s 9  -> -Codigo Postal %s \n",RGB.verde,RGB.fimcor);
        printf("%s 10  -> -Cidade %s \n",RGB.verde,RGB.fimcor);
        printf("%s 11 -> Tipo de Cliente %s \n",RGB.verde,RGB.fimcor);
        printf("%s 12 -> Cartao de Credito %s \n",RGB.verde,RGB.fimcor);
        printf("%s 13 -> -Cartao de Credito CVE %s \n",RGB.verde,RGB.fimcor);
        printf("%s 14 -> -Cartao de Credito Validade %s \n",RGB.verde,RGB.fimcor);
        printf("%s 0  -> Sair do Menu Editar Cliente %s \n",RGB.amarelo,RGB.fimcor);

        opcao = opcaoIntegerOnly(0,0,14,0);

        switch(opcao) {

        case 0:
            printf("\n");
            printf("%s Saiu do Menu Editar Cliente! %s \n",RGB.vermelho,RGB.fimcor);
            printf("\n");
            break;

        case 1:
            printf("\n");
            strcpy(last,C[*pc].nickname);
            do {
                fflush(stdin);
                printf("%s Antigo:%s %s\n",RGB.azul,RGB.fimcor,last);
                printf("%s *Nickname:%s ",RGB.verde,RGB.fimcor);
                fgets(C[*pc].nickname,13,stdin);
                C[*pc].nickname[strcspn(C[*pc].nickname, "\n")] = 0;
                int direcao = checkexite(C[*pc].nickname,0,RGB);
                if(direcao == 2){
                        strcpy(C[*pc].nickname,last);
                        return;
                }
                printf("\n");
            } while (checktext(C[*pc].nickname,2,11) != 0 || checknick(C,last,pcT,RGB) != 0);
            break;

        case 2:
            printf("\n");
            strcpy(last,C[*pc].pin);

            do {
                fflush(stdin);
                printf("%s Antigo:%s %s\n",RGB.azul,RGB.fimcor,last);
                printf("%s *Pin (4 digitos):%s ",RGB.verde,RGB.fimcor);
                fgets(C[*pc].pin,6,stdin);
                C[*pc].pin[strcspn(C[*pc].pin, "\n")] = 0;
                int direcao = checkexite(C[*pc].pin,0,RGB);
                if(direcao == 2){
                        strcpy(C[*pc].pin,last);
                        return;
                }
                printf("\n");
            } while (checktext(C[*pc].pin,4,4) != 0);
            break;

        case 3:
            printf("\n");
            strcpy(last,C[*pc].nome_completo);
            do {
                fflush(stdin);
                printf("%s Antigo:%s %s\n",RGB.azul,RGB.fimcor,last);
                printf("%s *Nome e Apelido:%s ",RGB.verde,RGB.fimcor);
                fgets(C[*pc].nome_completo,101,stdin);
                C[*pc].nome_completo[strcspn(C[*pc].nome_completo, "\n")] = 0;
                int direcao = checkexite(C[*pc].nome_completo,0,RGB);
                if(direcao == 2){
                        strcpy(C[*pc].nome_completo,last);
                        return;
                }
                printf("\n");
            } while (checktext(C[*pc].nome_completo,2,100) != 0);
            break;

        case 4:
            printf("\n");
            strcpy(last,C[*pc].numcontri);
            do {
                fflush(stdin);
                printf("%s Antigo:%s %s\n",RGB.azul,RGB.fimcor,last);
                printf("%s *N.Contribuinte (9 digitos):%s ",RGB.verde,RGB.fimcor);
                fgets(C[*pc].numcontri,10,stdin);
                C[*pc].numcontri[strcspn(C[*pc].numcontri, "\n")] = 0;
                int direcao = checkexite(C[*pc].numcontri,0,RGB);
                if(direcao == 2){
                        strcpy(C[*pc].numcontri,last);
                        return;
                }
                printf("\n");
            } while (checktext(C[*pc].numcontri,4,9) != 0);
            break;

        case 5:
            printf("\n");
            strcpy(last,C[*pc].nascimento);
            printf("%s Antigo:%s %s\n",RGB.azul,RGB.fimcor,last);
            strcpy(C[*pc].nascimento,"\0");
            printf("%s *Nascimento%s \n",RGB.verde,RGB.fimcor);
            do{
                fflush(stdin);
                printf("%s  *Ano:%s ",RGB.verde,RGB.fimcor);
                fgets(C[*pc].nascimentoano,5,stdin);
                C[*pc].nascimentoano[strcspn(C[*pc].nascimentoano, "\n")] = 0;
                int direcao = checkexite(C[*pc].nascimentoano,0,RGB);
                if(direcao == 2){
                        strcpy(C[*pc].nascimento,last);
                        return;
                }
                num3 = atoi(C[*pc].nascimentoano);
            } while (checktext(C[*pc].nascimentoano,1,4) != 0 || num3 < 1 || num3 > 9999 || checkzeros(C[*pc].nascimentoano) != 0);
            if(AnoBissexto(num3)==1) dias[1] = 29;
            if(AnoBissexto(num3)==0) dias[1] = 28;
            do{
                fflush(stdin);
                printf("%s  *Mes:%s ",RGB.verde,RGB.fimcor);
                fgets(C[*pc].nascimentomes,3,stdin);
                C[*pc].nascimentomes[strcspn(C[*pc].nascimentomes, "\n")] = 0;
                int direcao = checkexite(C[*pc].nascimentomes,0,RGB);
                if(direcao == 2){
                        strcpy(C[*pc].nascimento,last);
                        return;
                }
                num2 = atoi(C[*pc].nascimentomes);
            } while (checktext(C[*pc].nascimentomes,1,2) != 0 || num2 < 1 || num2 > 12 || checkzeros(C[*pc].nascimentomes) != 0);
            do{
                fflush(stdin);
                printf("%s  *Dia:%s ",RGB.verde,RGB.fimcor);
                fgets(C[*pc].nascimentodia,3,stdin);
                C[*pc].nascimentodia[strcspn(C[*pc].nascimentodia, "\n")] = 0;
                int direcao = checkexite(C[*pc].nascimentodia,0,RGB);
                if(direcao == 2){
                        strcpy(C[*pc].nascimento,last);
                        return;
                }
                num = atoi(C[*pc].nascimentodia);
            } while (checktext(C[*pc].nascimentodia,1,2) != 0 || num  < 1 || num  > dias[num2-1] || checkzeros(C[*pc].nascimentodia) != 0);
            strcpy(C[*pc].nascimento,"\0");
            if(num < 10) strcat(C[*pc].nascimento,"0");
            strcat(C[*pc].nascimento,C[*pc].nascimentodia);
            strcat(C[*pc].nascimento,"/");
            if(num2 < 10) strcat(C[*pc].nascimento,"0");
            strcat(C[*pc].nascimento,C[*pc].nascimentomes);
            strcat(C[*pc].nascimento,"/");
            if(num3 < 1000) strcat(C[*pc].nascimento,"0");
            if(num3 < 100) strcat(C[*pc].nascimento,"0");
            if(num3 < 10) strcat(C[*pc].nascimento,"0");
            strcat(C[*pc].nascimento,C[*pc].nascimentoano);
            printf("%s  *Data de Nascimento:%s %s \n",RGB.verde,RGB.fimcor,C[*pc].nascimento);
            printf("\n");
            break;

        case 6:
            printf("\n");
            strcpy(last,C[*pc].telemovel);
            do {
                fflush(stdin);
                printf("%s - Introduza -1 para nao preencher - %s \n",RGB.amarelo,RGB.fimcor);
                printf("%s Antigo:%s %s\n",RGB.azul,RGB.fimcor,last);
                printf("%s Telemovel (9 digitos):%s ",RGB.verde,RGB.fimcor);
                fgets(C[*pc].telemovel,10,stdin);
                C[*pc].telemovel[strcspn(C[*pc].telemovel, "\n")] = 0;
                int direcao = checkexite(C[*pc].telemovel,0,RGB);
                if(direcao == 1){
                    strcpy(C[*pc].telemovel,"");
                    break;
                }
                if(direcao == 2){
                        strcpy(C[*pc].telemovel,last);
                        return;
                }
                printf("\n");
            } while (checktext(C[*pc].telemovel,4,9) != 0);
            break;

        case 7:
            printf("\n");
            strcpy(last,C[*pc].morada);
            do {
                fflush(stdin);
                printf("%s Antigo:%s %s\n",RGB.azul,RGB.fimcor,last);
                printf("%s *Morada:%s ",RGB.verde,RGB.fimcor);
                fgets(C[*pc].morada,101,stdin);
                C[*pc].morada[strcspn(C[*pc].morada, "\n")] = 0;
                int direcao = checkexite(C[*pc].morada,0,RGB);
                if(direcao == 2){
                        strcpy(C[*pc].morada,last);
                        return;
                }
                printf("\n");
            } while (checktext(C[*pc].morada,3,100) != 0);
            break;

        case 8:
            printf("\n");
            strcpy(last,C[*pc].nporta);
            do {
                fflush(stdin);
                printf("%s Antigo:%s %s\n",RGB.azul,RGB.fimcor,last);
                printf("%s ->*Numero de porta:%s ",RGB.verde,RGB.fimcor);
                fgets(C[*pc].nporta,11,stdin);
                C[*pc].nporta[strcspn(C[*pc].nporta, "\n")] = 0;
                int direcao = checkexite(C[*pc].nporta,0,RGB);
                if(direcao == 2){
                        strcpy(C[*pc].nporta,last);
                        return;
                }
                printf("\n");
            } while (checktext(C[*pc].nporta,3,10) != 0);
            break;

        case 9:
            printf("\n");
            strcpy(last,C[*pc].codigopostal);
            printf("%s Antigo:%s %s\n",RGB.azul,RGB.fimcor,last);
            strcpy(C[*pc].codigopostal,"\0");
            printf("%s ->*Codigo Postal%s \n",RGB.verde,RGB.fimcor);
            do{
                fflush(stdin);
                printf("%s    >*(****-000):%s ",RGB.verde,RGB.fimcor);
                fgets(C[*pc].codigopostalquatro,5,stdin);
                C[*pc].codigopostalquatro[strcspn(C[*pc].codigopostalquatro, "\n")] = 0;
                int direcao = checkexite(C[*pc].codigopostalquatro,0,RGB);
                if(direcao == 2){
                        strcpy(C[*pc].codigopostal,last);
                        return;
                }
                num = atoi(C[*pc].codigopostalquatro);
            } while (checktext(C[*pc].codigopostalquatro,1,4) != 0 || num < 1 || num > 9999 || checkzeros(C[*pc].codigopostalquatro) != 0);
            do{
                fflush(stdin);
                printf("%s    >*(%4d-***):%s ",RGB.verde,num,RGB.fimcor);
                fgets(C[*pc].codigopostaltres,4,stdin);
                C[*pc].codigopostaltres[strcspn(C[*pc].codigopostaltres, "\n")] = 0;
                int direcao = checkexite(C[*pc].codigopostaltres,0,RGB);
                if(direcao == 2){
                        strcpy(C[*pc].codigopostal,last);
                        return;
                }
                num2 = atoi(C[*pc].codigopostaltres);
            } while (checktext(C[*pc].codigopostaltres,1,3) != 0 || num2  < 1 || num2  > 999 || checkzeros(C[*pc].codigopostaltres) != 0);
            strcpy(C[*pc].codigopostal,"\0");
            if(num < 1000) strcat(C[*pc].codigopostal,"0");
            if(num < 100) strcat(C[*pc].codigopostal,"0");
            if(num < 10) strcat(C[*pc].codigopostal,"0");
            strcat(C[*pc].codigopostal,C[*pc].codigopostalquatro);
            strcat(C[*pc].codigopostal,"-");
            if(num2 < 100) strcat(C[*pc].codigopostal,"0");
            if(num2 < 10) strcat(C[*pc].codigopostal,"0");
            strcat(C[*pc].codigopostal,C[*pc].codigopostaltres);
            printf("%s  >Codigo Postal:%s %s \n",RGB.verde,RGB.fimcor,C[*pc].codigopostal);
            printf("\n");
            break;

        case 10:
            printf("\n");
            strcpy(last,C[*pc].cidade);
            do {
                fflush(stdin);
                printf("%s Antigo:%s %s\n",RGB.azul,RGB.fimcor,last);
                printf("%s -*Cidade:%s ",RGB.verde,RGB.fimcor);
                fgets(C[*pc].cidade,101,stdin);
                C[*pc].cidade[strcspn(C[*pc].cidade, "\n")] = 0;
                int direcao = checkexite(C[*pc].cidade,0,RGB);
                if(direcao == 2){
                        strcpy(C[*pc].cidade,last);
                        return;
                }
                printf("\n");
            } while (checktext(C[*pc].cidade,2,100) != 0);
            break;

        case 11:
            printf("\n");
            strcpy(last,C[*pc].tipocliente);
            if(tipo == 0){
                do {
                    fflush(stdin);
                    printf("%s Antigo:%s %s\n",RGB.azul,RGB.fimcor,last);
                    printf("%s *Tipo de cliente ( NORMA / GOLDE / ADMIN):%s ",RGB.verde,RGB.fimcor);
                    fgets(C[*pc].tipocliente,6,stdin);
                    C[*pc].tipocliente[strcspn(C[*pc].tipocliente, "\n")] = 0;
                    int direcao = checkexite(C[*pc].tipocliente,0,RGB);
                    if(direcao == 2){
                            strcpy(C[*pc].tipocliente,last);
                            return;
                    }
                    printf("\n");
                } while (checktext(C[*pc].tipocliente,5,5) != 0);
            } else {
                printf("%s Contacte o Administrador para possivel alteracao!! %s \n",RGB.vermelho,RGB.fimcor);
            }
            break;

        case 12:
            printf("\n");
            strcpy(last,C[*pc].cartaocredito);
            do {
                fflush(stdin);
                printf("%s Antigo:%s %s\n",RGB.azul,RGB.fimcor,last);
                printf("%s *Cartao Credito (16 digitos):%s ",RGB.verde,RGB.fimcor);
                fgets(C[*pc].cartaocredito,17,stdin);
                C[*pc].cartaocredito[strcspn(C[*pc].cartaocredito, "\n")] = 0;
                int direcao = checkexite(C[*pc].cartaocredito,0,RGB);
                if(direcao == 2){
                        strcpy(C[*pc].cartaocredito,last);
                        return;
                }
                printf("\n");
            } while (checktext(C[*pc].cartaocredito,4,16) != 0);
            break;

        case 13:
            printf("\n");
            strcpy(last,C[*pc].cartaocreditocve);
            do {
                fflush(stdin);
                printf("%s Antigo:%s %s\n",RGB.azul,RGB.fimcor,last);
                printf("%s ->*Cartao Credito CVE (3 digitos):%s ",RGB.verde,RGB.fimcor);
                fgets(C[*pc].cartaocreditocve,4,stdin);
                C[*pc].cartaocreditocve[strcspn(C[*pc].cartaocreditocve, "\n")] = 0;
                int direcao = checkexite(C[*pc].cartaocreditocve,0,RGB);
                if(direcao == 2){
                        strcpy(C[*pc].cartaocreditocve,last);
                        return;
                }
                printf("\n");
            }  while (checktext(C[*pc].cartaocreditocve,4,3) != 0);
            break;

        case 14:
            printf("\n");
            strcpy(last,C[*pc].cartaocreditovalidade);
            printf("%s Antigo:%s %s\n",RGB.azul,RGB.fimcor,last);
            strcpy(C[*pc].cartaocreditovalidade,"\0");
            printf("%s ->*Cartao Credito Data Validade%s \n",RGB.verde,RGB.fimcor);
            do{
                fflush(stdin);
                printf("%s                          >Mes:%s ",RGB.verde,RGB.fimcor);
                fgets(C[*pc].cartaocreditovalidademes,3,stdin);
                C[*pc].cartaocreditovalidademes[strcspn(C[*pc].cartaocreditovalidademes, "\n")] = 0;
                int direcao = checkexite(C[*pc].cartaocreditovalidademes,0,RGB);
                if(direcao == 2){
                        strcpy(C[*pc].cartaocreditovalidade,last);
                        return;
                }
                num2 = atoi(C[*pc].cartaocreditovalidademes);
            } while (checktext(C[*pc].cartaocreditovalidademes,1,2) != 0 || num2 < 1 || num2 > 12 || checkzeros(C[*pc].cartaocreditovalidademes) != 0);
            do{
                fflush(stdin);
                printf("%s                          >Ano:%s ",RGB.verde,RGB.fimcor);
                fgets(C[*pc].cartaocreditovalidadeano,3,stdin);
                C[*pc].cartaocreditovalidadeano[strcspn(C[*pc].cartaocreditovalidadeano, "\n")] = 0;
                int direcao = checkexite(C[*pc].cartaocreditovalidadeano,0,RGB);
                if(direcao == 2){
                        strcpy(C[*pc].cartaocreditovalidade,last);
                        return;
                }
                num = atoi(C[*pc].cartaocreditovalidadeano);
            } while (checktext(C[*pc].cartaocreditovalidadeano,1,2) != 0 || num < 0 || num > 99);
            strcpy(C[*pc].cartaocreditovalidade,"\0");
            if(num2 < 10) strcat(C[*pc].cartaocreditovalidade,"0");
            strcat(C[*pc].cartaocreditovalidade,C[*pc].cartaocreditovalidademes);
            strcat(C[*pc].cartaocreditovalidade,"/");
            if(num < 10) strcat(C[*pc].cartaocreditovalidade,"0");
            sprintf(C[*pc].cartaocreditovalidadeano, "%d", num);
            strcat(C[*pc].cartaocreditovalidade,C[*pc].cartaocreditovalidadeano);
            printf("%s                >Data Validade:%s %s\n",RGB.verde,RGB.fimcor,C[*pc].cartaocreditovalidade);
            printf("\n");
            break;
        }
    }

    //-------------------- Editar Artigos
    if(*pa != -1 && *menu_editar == 2) {
        printf("%s Menu Editar Artigo:%s %04d\n",RGB.azul,RGB.fimcor, A[*pa].numeroartigo);
        printf("%s 1  -> Nome %s \n",RGB.verde,RGB.fimcor);
        printf("%s 2  -> Marca %s \n",RGB.verde,RGB.fimcor);
        printf("%s 3  -> Produto %s \n",RGB.verde,RGB.fimcor);
        printf("%s 4  -> Categoria %s \n",RGB.verde,RGB.fimcor);
        printf("%s 5  -> Sub-Categoria %s \n",RGB.verde,RGB.fimcor);
        printf("%s 6  -> Cor %s \n",RGB.verde,RGB.fimcor);
        printf("%s 7  -> Tamanho%s \n",RGB.verde,RGB.fimcor);
        printf("%s 8  -> Preco %s \n",RGB.verde,RGB.fimcor);
        printf("%s 0  -> Sair do Menu Editar Artigo %s \n",RGB.amarelo,RGB.fimcor);

        opcao = opcaoIntegerOnly(0,0,8,0);

        switch(opcao) {
        case 0:
            printf("%s Saiu do Menu Editar Artigo! %s \n",RGB.vermelho,RGB.fimcor);
            printf("\n");
            break;

        case 1:
            strcpy(last,A[*pa].nomeartigo);
            do {
                fflush(stdin);
                printf("%s Antigo:%s %s\n",RGB.azul,RGB.fimcor,last);
                printf("%s *Nome Artigo:%s ",RGB.verde,RGB.fimcor);
                fgets(A[*pa].nomeartigo,101,stdin);
                A[*pa].nomeartigo[strcspn(A[*pa].nomeartigo, "\n")] = 0;
                int direcao = checkexite(A[*pa].nomeartigo,0,RGB);
                if(direcao == 2){
                        strcpy(A[*pa].nomeartigo,last);
                        return;
                }
                printf("\n");
            }while(checktext(A[*pa].nomeartigo,2,100) != 0);                                          //REPETE DANDO 1 SE A STRING NAO FOR SO DE CARATERES "2" OU MAIOR QUE "100" ELEMENTOS NO VETOR, ISTO COM UMA FUNCAO
            break;

        case 2:
            strcpy(last,A[*pa].marcaartigo);
            do {
                fflush(stdin);
                printf("%s Antigo:%s %s\n",RGB.azul,RGB.fimcor,last);
                printf("%s *Marca:%s ",RGB.verde,RGB.fimcor);
                fgets(A[*pa].marcaartigo,101,stdin);
                A[*pa].marcaartigo[strcspn(A[*pa].marcaartigo, "\n")] = 0;
                int direcao = checkexite(A[*pa].marcaartigo,0,RGB);
                if(direcao == 2){
                        strcpy(A[*pa].marcaartigo,last);
                        return;
                }
                printf("\n");
            } while(checktext(A[*pa].marcaartigo,2,100) !=0);                                       //REPETE DANDO 1 SE A STRING NAO FOR SO DE CARATERES "2" OU MAIOR QUE "100" ELEMENTOS NO VETOR, ISTO COM UMA FUNCAO
            break;

        case 3:
            strcpy(last,A[*pa].produtoartigo);
            do {
                fflush(stdin);
                printf("%s Antigo:%s %s\n",RGB.azul,RGB.fimcor,last);
                printf("%s *Produto:%s ",RGB.verde,RGB.fimcor);
                fgets(A[*pa].produtoartigo,101,stdin);
                A[*pa].produtoartigo[strcspn(A[*pa].produtoartigo, "\n")] = 0;
                int direcao = checkexite(A[*pa].produtoartigo,0,RGB);
                if(direcao == 2){
                        strcpy(A[*pa].produtoartigo,last);
                        return;
                }
                printf("\n");
            } while(checktext(A[*pa].produtoartigo,2,100) != 0);                                     //REPETE DANDO 1 SE A STRING NAO FOR SO DE CARATERES "2" OU MAIOR QUE "100" ELEMENTOS NO VETOR, ISTO COM UMA FUNCAO
            break;

        case 4:
            strcpy(last,A[*pa].categoriaartigo);
            do {
                fflush(stdin);
                printf("%s Antigo:%s %s\n",RGB.azul,RGB.fimcor,last);
                printf("%s *Categoria:%s ",RGB.verde,RGB.fimcor);
                fgets(A[*pa].categoriaartigo,101,stdin);
                A[*pa].categoriaartigo[strcspn(A[*pa].categoriaartigo, "\n")] = 0;
                int direcao = checkexite(A[*pa].categoriaartigo,0,RGB);
                if(direcao == 2){
                        strcpy(A[*pa].categoriaartigo,last);
                        return;
                }
                printf("\n");
            }  while(checktext(A[*pa].categoriaartigo,2,100) != 0);                                 //REPETE DANDO 1 SE A STRING NAO FOR SO DE CARATERES "2" OU MAIOR QUE "100" ELEMENTOS NO VETOR, ISTO COM UMA FUNCAO
            break;

        case 5:
            strcpy(last,A[*pa].subcategoriaartigo);
            do {
                fflush(stdin);
                printf("%s Antigo:%s %s\n",RGB.azul,RGB.fimcor,last);
                printf("%s *Sub-Categoria:%s ",RGB.verde,RGB.fimcor);
                fgets(A[*pa].subcategoriaartigo,101,stdin);
                A[*pa].subcategoriaartigo[strcspn(A[*pa].subcategoriaartigo, "\n")] = 0;
                int direcao = checkexite(A[*pa].subcategoriaartigo,0,RGB);
                if(direcao == 2){
                        strcpy(A[*pa].subcategoriaartigo,last);
                        return;
                }
                printf("\n");
            } while(checktext(A[*pa].subcategoriaartigo,2,100) != 0);                               //REPETE DANDO 1 SE A STRING NAO FOR SO DE CARATERES "2" OU MAIOR QUE "100" ELEMENTOS NO VETOR, ISTO COM UMA FUNCAO
            break;

        case 6:
            strcpy(last,A[*pa].corartigo);
            do {
                fflush(stdin);
                printf("%s Antigo:%s %s\n",RGB.azul,RGB.fimcor,last);
                printf("%s *Cor:%s ",RGB.verde,RGB.fimcor);
                fgets(A[*pa].corartigo,101,stdin);
                A[*pa].corartigo[strcspn(A[*pa].corartigo, "\n")] = 0;
                int direcao = checkexite(A[*pa].corartigo,0,RGB);
                if(direcao == 2){
                        strcpy(A[*pa].corartigo,last);
                        return;
                }
                printf("\n");
            } while(checktext(A[*pa].corartigo,2,100) != 0);                                   //REPETE DANDO 1 SE A STRING NAO FOR SO DE CARATERES "2" OU MAIOR QUE "100" ELEMENTOS NO VETOR, ISTO COM UMA FUNCAO
            break;

        case 7:
            strcpy(last,A[*pa].tamanhoartigo);
            do {
                fflush(stdin);
                printf("%s Antigo:%s %s\n",RGB.azul,RGB.fimcor,last);
                printf("%s *Tamanho:%s ",RGB.verde,RGB.fimcor);
                fgets(A[*pa].tamanhoartigo,101,stdin);
                A[*pa].tamanhoartigo[strcspn(A[*pa].tamanhoartigo, "\n")] = 0;
                int direcao = checkexite(A[*pa].tamanhoartigo,0,RGB);
                if(direcao == 2){
                        strcpy(A[*pa].tamanhoartigo,last);
                        return;
                }
                printf("\n");
            } while (checktext(A[*pa].tamanhoartigo,3,100) != 0);                                   //REPETE DANDO 1 SE A STRING TIVER MAIOR QUE "100" ELEMENTOS NO VETOR, PODENDO CONTER NUMEROS E CARATERES "3", ISTO COM UMA FUNCAO
            break;

        case 8:
            strcpy(last,A[*pa].precoartigo);
            do {
                fflush(stdin);
                printf("%s Antigo:%s %s\n",RGB.azul,RGB.fimcor,last);
                printf("%s *Preco (euro):%s ",RGB.verde,RGB.fimcor);
                fgets(A[*pa].precoartigo,101,stdin);
                A[*pa].precoartigo[strcspn(A[*pa].precoartigo, "\n")] = 0;
                int direcao = checkexite(A[*pa].precoartigo,0,RGB);
                if(direcao == 2){
                        strcpy(A[*pa].precoartigo,last);
                        return;
                }                                                            //GUARDA A INFORMACAO NA STRING
                printf("\n");
            } while(checktext(A[*pa].precoartigo,1,100) != 0);                                      //REPETE DANDO 1 SE A STRING NAO FOR SO DE NUMEROS "1" OU MAIOR QUE "100" ELEMENTOS NO VETOR, ISTO COM UMA FUNCAO
            break;

        }
    }
    *menu_editar = 0;
}


//------------------------- Login ---------------------------------
void login(struct cliente C[],int pcT,int *tipo,int *pc,struct cores RGB){
    char nick[101], pin[6];
    int check = -1, opcao = -1;



    do{
        printf("\n          %sLogin%s               \n",RGB.azul,RGB.fimcor);
        check=0;
        do {
            fflush(stdin);
            printf("%s | Nickname --------> %s",RGB.verde,RGB.fimcor);
            fgets(nick,101,stdin);
            nick[strcspn(nick, "\n")] = 0;
            int direcao = checkexite(nick,0,RGB);
            if(direcao == 2) return;
        } while (checktext(nick,2,100) != 0);

        do {
            fflush(stdin);
            printf("%s | Pin (4 Digitos) -> %s",RGB.verde,RGB.fimcor);
            fgets(pin,6,stdin);
            pin[strcspn(pin, "\n")] = 0;
            int direcao = checkexite(pin,0,RGB);
            if(direcao == 2) return;
        } while (checktext(pin,1,4) != 0);

        for (int i = 0; i < pcT; i++){
            if (strcmp(C[i].nickname, nick) == 0 && strcmp(C[i].pin, pin) == 0 ) {  //COMPARA NICK E PIN
                if (strcmp(C[i].tipocliente, "ADMIN") == 0) *tipo = 0;              //COMPARA SE ADMIN
                if (strcmp(C[i].tipocliente, "ADMIN") != 0) *tipo = 1;              //COMPARA SENAO E NORMA OU GOLDE
                *pc = i;
                check = 1;
            }
        }

        //REPETIR SE ERRADO
        if(check==0){
            printf("%s >> Login errado!! << %s \n",RGB.vermelho,RGB.fimcor);
            printf("\n");
            printf("%s 1  -> Login %s \n",RGB.verde,RGB.fimcor);
            printf("%s 0  -> Sair do Login %s \n",RGB.amarelo,RGB.fimcor);
            opcao = opcaoIntegerOnly(0,0,1,0);
            if (opcao==0) break;
        }

    } while (check != 1);
}


//------------------------ Carrinho ----------------------------------------------
//VOID ADICIONAR AO CARRINHO
void adicionarcarrinho(struct carrinho CAR[],int pc, int *ACAR, int paT, int limitequantidades, struct cores RGB){
    int novo = 1;
    char art[101], qua[101];

    if(*ACAR >= 0) *ACAR += 1; //MAIS UM ARTIGO NO CARRINHO
    printf("\n");

    do {
        fflush(stdin);
        printf("%s Adicionar ao carrinho o artigo com numero:%s ",RGB.azul,RGB.fimcor);
        fgets(art,101,stdin);
        art[strcspn(art, "\n")] = 0;
        printf("\n");
        int direcao = checkexite(art,0,RGB);
        if(direcao == 2) return;
    } while(checktext(art,1,100) != 0 || atoi(art) < 1 ||  atoi(art) > paT);

    do {
        fflush(stdin);
        printf("%s Indique quantidade de unidades do artigo numero deseja:%s ",RGB.azul,RGB.fimcor);
        fgets(qua,101,stdin);
        qua[strcspn(qua, "\n")] = 0;
        int direcao = checkexite(qua,0,RGB);
        if(direcao == 2) return;
        printf("\n");
    } while(checktext(qua,1,100) != 0 || atoi(qua) < 1 ||  atoi(qua) > limitequantidades);

    //PARA NAO REPETIR O MESMO ARTIGO
    for (int i = 0; i < *ACAR; i++) {
        if(CAR[i].cliente == pc && strcmp(CAR[i].estado,"NAO PAGO") == 0){
            if(CAR[i].numeroartigo == atoi(art) && CAR[i].quantidade == atoi(qua)){
                novo = 0;
                printf("%s Artigo ja adicionado com quantidade igual!! %s \n\n",RGB.amarelo,RGB.fimcor);
            } else if(CAR[i].numeroartigo == atoi(art) && CAR[i].quantidade != atoi(qua)){
                CAR[i].quantidade = atoi(qua);
                novo = 0;
                printf("%s Artigo ja adicionado com quantidade atualizada!! %s \n\n",RGB.amarelo,RGB.fimcor);
            }
        }
    }

    //REPETIDO NO CARRINHO DECREMENTA O QUE INCREMENTOU (NAO ADICIONOU ARTIGO NOVO PORQUE E O MESMO)
    if(novo == 0) *ACAR -= 1;

    //NOVO ARTIGO NO CARRINHO
    if(novo == 1){
        CAR[*ACAR].cliente = pc;
        CAR[*ACAR].numeroartigo = atoi(art);
        CAR[*ACAR].quantidade = atoi(qua);
        strcpy(CAR[*ACAR].estado,"NAO PAGO");
        printf("%s Artigo adicionado ao carrinho!! %s\n\n",RGB.verde,RGB.fimcor);
    }
}

//VOID EDITAR QUANTIDADE DO ARTIGO SÓ SE DISPONIVEL NO CARRINHO
void editarcarrinho(struct carrinho CAR[],int pc, int ACAR, int paT, int limitequantidades, struct cores RGB){
    int ed_numeroartigo = -1, editarqua = 0, i = 0;
    char editarart[101], quaed[101];

    printf("\n");

    for (int i = 0; i < ACAR+1; i++) {
        if (CAR[i].cliente == pc && strcmp(CAR[i].estado,"NAO PAGO") == 0) {
            editarqua = 1;
            break;
        }
    }

    if(editarqua == 1){
        do {
            fflush(stdin);
            printf("%s Numero de Artigo para editar quantidade no carrinho:%s ",RGB.azul,RGB.fimcor);
            fgets(editarart,101,stdin);
            editarart[strcspn(editarart, "\n")] = 0;
            printf("\n");
        } while(checktext(editarart,1,100) != 0 || atoi(editarart) < 1 || atoi(editarart) > paT);

        ed_numeroartigo = atoi(editarart);

       for (i; i < ACAR+1; i++) {
        if (CAR[i].cliente == pc && strcmp(CAR[i].estado,"NAO PAGO") == 0 && CAR[i].numeroartigo == ed_numeroartigo ) {
            break;
        }
       }


        if(CAR[i].numeroartigo == ed_numeroartigo){
            do {
                fflush(stdin);
                printf("%s Artigo numero:%s %d\n",RGB.azul,RGB.fimcor,CAR[i].numeroartigo);
                printf("%s Quantidade:%s ",RGB.verde,RGB.fimcor);
                fgets(quaed,101,stdin);
                quaed[strcspn(quaed, "\n")] = 0;
                int direcao = checkexite(quaed,0,RGB);
                if(direcao == 2) return;
                printf("\n");
            } while(checktext(quaed,1,100) != 0 || atoi (quaed) < 1 || atoi(quaed) > limitequantidades);
            CAR[i].quantidade = atoi(quaed);
            printf("%s Artigo atualizado!! %s\n",RGB.verde,RGB.fimcor);
        } else {
            printf("%s Artigo nao disponivel no carrinho!! %s \n\n",RGB.vermelho,RGB.fimcor);
        }

    } else {
        printf("%s Nao tem Artigos no carrinho!! %s \n\n",RGB.vermelho,RGB.fimcor);
    }
}

//VOID QUE MOSTRA OS ARTIGOS NO CARRINHO
void mostrarartigoscarrinho(struct carrinho CAR[],int pc, int ACAR,struct artigo A[], struct cores RGB){
    float precototal = 0;
    int artigo = 0, temartigo = 0, count = 0;

    for (int i = 0; i < ACAR+1; i++) {
        if(CAR[i].cliente == pc && strcmp(CAR[i].estado,"NAO PAGO") == 0){
        temartigo = 1;
        count++;
        }
    }

    if(temartigo == 0){
        printf("\n");
        printf("%s Nao existe Artigos no Carrinho!! %s\n",RGB.vermelho,RGB.fimcor);
    } else {

        printf("%s No Carrinho existe:%s %d %sArtigos%s \n",RGB.azul,RGB.fimcor,count,RGB.azul,RGB.fimcor);                                //PRINTF COM INDICADOR DE TOTAL DE ARTIGOS
        printf("\n");

        for (int i = 0; i < ACAR+1; i++) {
            if(CAR[i].cliente == pc && strcmp(CAR[i].estado,"NAO PAGO") == 0){
                artigo = (CAR[i].numeroartigo)-1;
                printf("%s |-----------------------------------------%s\n",RGB.verde,RGB.fimcor);
                printf("%s | Numero do Artigo:%s %04d\n",RGB.verde,RGB.fimcor, A[artigo].numeroartigo);                //MOSTRA A INFORMACAO NA STRING INDICADA [i]
                printf("%s | Nome do Artigo:%s   %s\n",RGB.verde,RGB.fimcor, A[artigo].nomeartigo);                      //MOSTRA A INFORMACAO NA STRING INDICADA [i]
                printf("%s | Marca do Artigo:%s  %s\n",RGB.verde,RGB.fimcor, A[artigo].marcaartigo);                    //MOSTRA A INFORMACAO NA STRING INDICADA [i]
                printf("%s | Produto:%s          %s\n",RGB.verde,RGB.fimcor, A[artigo].produtoartigo);                          //MOSTRA A INFORMACAO NA STRING INDICADA [i]
                printf("%s | Categoria:%s        %s\n",RGB.verde,RGB.fimcor, A[artigo].categoriaartigo);                      //MOSTRA A INFORMACAO NA STRING INDICADA [i]
                printf("%s | Sub-Categoria:%s    %s\n",RGB.verde,RGB.fimcor, A[artigo].subcategoriaartigo);               //MOSTRA A INFORMACAO NA STRING INDICADA [i]
                printf("%s | Cor:%s              %s\n",RGB.verde,RGB.fimcor, A[artigo].corartigo);                                  //MOSTRA A INFORMACAO NA STRING INDICADA [i]
                printf("%s | Tamanho:%s          %s\n",RGB.verde,RGB.fimcor, A[artigo].tamanhoartigo);                          //MOSTRA A INFORMACAO NA STRING INDICADA [i]
                printf("%s | Preco:%s            %0.2f euro/s\n",RGB.verde,RGB.fimcor, atof(A[artigo].precoartigo));                       //MOSTRA A INFORMACAO NA STRING INDICADA [i]
                printf("%s | Quantidade:%s       %d\n",RGB.verde,RGB.fimcor, CAR[i].quantidade);
                printf("%s | Estado da compra:%s %s\n",RGB.verde,RGB.fimcor, CAR[i].estado);
                printf("\n");

                precototal += atof(A[artigo].precoartigo) * CAR[i].quantidade;
            }
        }
        printf("%s |-----------------------------------------|%s\n",RGB.amarelo,RGB.fimcor);
        printf("%s |    preco total:%s    %10.2f euro/s    %s|%s  \n",RGB.amarelo,RGB.fimcor, precototal, RGB.amarelo,RGB.fimcor);
        printf("%s |-----------------------------------------|%s\n",RGB.amarelo,RGB.fimcor);
    }
}

//VOID QUE REMOVE ARTIGO DO CARRINHO
void removercarrinho(struct carrinho CAR[], int *ACAR, int pc, int paT, struct cores RGB){
    int re_numeroartigo = -1, i = 0, editarqua = 0, remove = 0;
    char removerart[101];

    printf("\n");

    for (int g = 0; g < *ACAR+1; g++) {
        if (CAR[g].cliente == pc && strcmp(CAR[g].estado,"NAO PAGO") == 0) {
            remove = 1;
            break;
        }
    }

    if(remove == 1){

        do {
            fflush(stdin);
            printf("%s Remover do carrinho o artigo com numero:%s ",RGB.azul,RGB.fimcor);
            fgets(removerart,101,stdin);
            removerart[strcspn(removerart, "\n")] = 0;
            int direcao = checkexite(removerart,0,RGB);
            if(direcao == 2) return;
            printf("\n");
        } while(checktext(removerart,1,100) != 0  || atoi(removerart) < 1 || atoi(removerart) > paT);

        re_numeroartigo = atoi(removerart);

        for (int j = 0; j < *ACAR+1; j++) {
            if (CAR[j].numeroartigo == re_numeroartigo && CAR[j].cliente == pc  && strcmp(CAR[j].estado,"NAO PAGO") == 0) {
                editarqua = 1;
                break;
            }
        }

        if(editarqua == 1){
            for (i; i < *ACAR+1; i++) {
                if (CAR[i].numeroartigo == re_numeroartigo && CAR[i].cliente == pc && strcmp(CAR[i].estado,"NAO PAGO") == 0) {
                    for(int j = i; j < *ACAR; j++) CAR[j] = CAR[j+1];
                    printf("%s Artigo Removido!! %s\n",RGB.vermelho,RGB.fimcor);
                    *ACAR -= 1;
                }
            }
        }

        if(editarqua == 0) printf("%s Artigo nao disponivel no carrinho!! %s \n\n",RGB.vermelho,RGB.fimcor);

    } else {
        printf("%s Nao tem Artigos no carrinho!! %s \n\n",RGB.vermelho,RGB.fimcor);
    }
}

//VOID QUE MOSTRA OS PAGOS E NAO PAGOS DE TODOS OS CLIENTES
void mostrartodosartigoscarrinho(struct carrinho CAR[],struct cliente C[],int pc, int ACAR,struct artigo A[], struct cores RGB){
    int artigo = 0, count = 0, temartigo = 0;;

    for (int i = 1; i < ACAR+1; i++) {
        if (strcmp(CAR[i].estado,"NAO PAGO") == 0 || strcmp(CAR[i].estado,"PAGO") == 0){
            temartigo = 1;
            count++;
        }
    }

    if(temartigo == 0){
        printf("\n");
        printf("%s Nao existe Artigos PAGOS / NAO PAGOS!! %s\n",RGB.vermelho,RGB.fimcor);
    } else {

        printf("\n");
        printf("%s A Lista de Artigos PAGOS / NAO PAGOS existe:%s %d %sArtigos%s \n",RGB.azul,RGB.fimcor,count,RGB.azul,RGB.fimcor);                                 //PRINTF COM INDICADOR DE TOTAL DE ARTIGOS
        printf("\n");

        for (int i = 1; i < ACAR+1; i++) {
            artigo = (CAR[i].numeroartigo)-1;
            printf("%s |-----------------------------------------%s\n",RGB.verde,RGB.fimcor);
            printf("%s | Nome do Cliente:%s   %s\n",RGB.amarelo,RGB.fimcor, C[CAR[i].cliente].nome_completo);
            printf("%s | Numero de Cliente:%s %04d\n",RGB.amarelo,RGB.fimcor, CAR[i].cliente);
            printf("%s | Numero do Artigo:%s  %04d\n",RGB.verde,RGB.fimcor, A[artigo].numeroartigo);                //MOSTRA A INFORMACAO NA STRING INDICADA [i]
            printf("%s | Nome do Artigo:%s    %s\n",RGB.verde,RGB.fimcor, A[artigo].nomeartigo);                      //MOSTRA A INFORMACAO NA STRING INDICADA [i]
            printf("%s | Marca do Artigo:%s   %s\n",RGB.verde,RGB.fimcor, A[artigo].marcaartigo);                    //MOSTRA A INFORMACAO NA STRING INDICADA [i]
            printf("%s | Produto:%s           %s\n",RGB.verde,RGB.fimcor, A[artigo].produtoartigo);                          //MOSTRA A INFORMACAO NA STRING INDICADA [i]
            printf("%s | Categoria:%s         %s\n",RGB.verde,RGB.fimcor, A[artigo].categoriaartigo);                      //MOSTRA A INFORMACAO NA STRING INDICADA [i]
            printf("%s | Sub-Categoria:%s     %s\n",RGB.verde,RGB.fimcor, A[artigo].subcategoriaartigo);               //MOSTRA A INFORMACAO NA STRING INDICADA [i]
            printf("%s | Cor:%s               %s\n",RGB.verde,RGB.fimcor, A[artigo].corartigo);                                  //MOSTRA A INFORMACAO NA STRING INDICADA [i]
            printf("%s | Tamanho:%s           %s\n",RGB.verde,RGB.fimcor, A[artigo].tamanhoartigo);                          //MOSTRA A INFORMACAO NA STRING INDICADA [i]
            printf("%s | Preco:%s             %0.2f euro/s\n",RGB.verde,RGB.fimcor, atof(A[artigo].precoartigo));                       //MOSTRA A INFORMACAO NA STRING INDICADA [i]
            printf("%s | Quantidade:%s        %d\n",RGB.verde,RGB.fimcor, CAR[i].quantidade);
            printf("%s | Estado da compra:%s  %s\n",RGB.verde,RGB.fimcor, CAR[i].estado);
            printf("\n");
        }
    }
}

//VOID QUE MOSTRA OS NAO PAGOS DE TODOS OS CLIENTES
void mostrartodosartigoscarrinhonaopagos(struct carrinho CAR[],struct cliente C[],int pc, int ACAR,struct artigo A[], struct cores RGB){
    int artigo = 0, temartigo = 0, count = 0;

    for (int i = 1; i < ACAR+1; i++) {
        if (strcmp(CAR[i].estado,"NAO PAGO") == 0){
            temartigo = 1;
            count++;
        }
    }

    if(temartigo == 0){
        printf("\n");
        printf("%s Nao existe Artigos NAO PAGOS!! %s\n",RGB.vermelho,RGB.fimcor);
    } else {

        printf("\n");
        printf("%s A Lista de Artigos NAO PAGOS existe:%s %d %sArtigos%s \n",RGB.azul,RGB.fimcor,count,RGB.azul,RGB.fimcor);                                    //PRINTF COM INDICADOR DE TOTAL DE ARTIGOS
        printf("\n");

        for (int i = 1; i < ACAR+1; i++) {
            if (strcmp(CAR[i].estado,"NAO PAGO") == 0){
                artigo = (CAR[i].numeroartigo)-1;
                printf("%s |-----------------------------------------%s\n",RGB.verde,RGB.fimcor);
                printf("%s | Nome do Cliente:%s   %s\n",RGB.amarelo,RGB.fimcor, C[CAR[i].cliente].nome_completo);
                printf("%s | Numero de Cliente:%s %04d\n",RGB.amarelo,RGB.fimcor, CAR[i].cliente);
                printf("%s | Numero do Artigo:%s  %04d\n",RGB.verde,RGB.fimcor, A[artigo].numeroartigo);                //MOSTRA A INFORMACAO NA STRING INDICADA [i]
                printf("%s | Nome do Artigo:%s    %s\n",RGB.verde,RGB.fimcor, A[artigo].nomeartigo);                      //MOSTRA A INFORMACAO NA STRING INDICADA [i]
                printf("%s | Marca do Artigo:%s   %s\n",RGB.verde,RGB.fimcor, A[artigo].marcaartigo);                    //MOSTRA A INFORMACAO NA STRING INDICADA [i]
                printf("%s | Produto:%s           %s\n",RGB.verde,RGB.fimcor, A[artigo].produtoartigo);                          //MOSTRA A INFORMACAO NA STRING INDICADA [i]
                printf("%s | Categoria:%s         %s\n",RGB.verde,RGB.fimcor, A[artigo].categoriaartigo);                      //MOSTRA A INFORMACAO NA STRING INDICADA [i]
                printf("%s | Sub-Categoria:%s     %s\n",RGB.verde,RGB.fimcor, A[artigo].subcategoriaartigo);               //MOSTRA A INFORMACAO NA STRING INDICADA [i]
                printf("%s | Cor:%s               %s\n",RGB.verde,RGB.fimcor, A[artigo].corartigo);                                  //MOSTRA A INFORMACAO NA STRING INDICADA [i]
                printf("%s | Tamanho:%s           %s\n",RGB.verde,RGB.fimcor, A[artigo].tamanhoartigo);                          //MOSTRA A INFORMACAO NA STRING INDICADA [i]
                printf("%s | Preco:%s             %0.2f euro/s\n",RGB.verde,RGB.fimcor, atof(A[artigo].precoartigo));                       //MOSTRA A INFORMACAO NA STRING INDICADA [i]
                printf("%s | Quantidade:%s        %d\n",RGB.verde,RGB.fimcor, CAR[i].quantidade);
                printf("%s | Estado da compra:%s  %s\n",RGB.verde,RGB.fimcor, CAR[i].estado);
                printf("\n");
            }
        }
    }
}

//VOID QUE MOSTRA OS PAGOS DE TODOS OS CLIENTES
void mostrartodosartigoscarrinhopagos(struct carrinho CAR[],struct cliente C[],int pc, int ACAR,struct artigo A[], struct cores RGB, int cli){
    int artigo = 0, temartigo = 0, count = 0;

    for (int i = 1; i < ACAR+1; i++) {
        if (strcmp(CAR[i].estado,"PAGO") == 0 && cli == 0 || strcmp(CAR[i].estado,"PAGO") == 0 && cli == 1 && CAR[i].cliente == pc){
            temartigo = 1;
            count++;
        }
    }

    if(temartigo == 0){

        if(cli == 0){
            printf("\n");
            printf("%s Nao existe Artigos PAGOS!! %s\n",RGB.vermelho,RGB.fimcor);
        } else {
            printf("\n");
            printf("%s Nao existe Pedidos!! %s\n",RGB.vermelho,RGB.fimcor);
        }

    } else {

        if(cli == 0){
            printf("\n");
            printf("%s A Lista de Artigos PAGOS existe:%s %d %sArtigos%s \n",RGB.azul,RGB.fimcor,count,RGB.azul,RGB.fimcor);
            printf("\n");
        } else {
            printf("\n");
            printf("%s Nos meus Pedidos existe:%s %d %sArtigos%s \n",RGB.azul,RGB.fimcor,count,RGB.azul,RGB.fimcor);
            printf("\n");
        }

        for (int i = 1; i < ACAR+1; i++) {
            if (strcmp(CAR[i].estado,"PAGO") == 0 && cli == 0 || strcmp(CAR[i].estado,"PAGO") == 0 && cli == 1 && CAR[i].cliente == pc){
                artigo = (CAR[i].numeroartigo)-1;
                printf("%s |-----------------------------------------%s\n",RGB.verde,RGB.fimcor);
                printf("%s | Nome do Cliente:%s   %s\n",RGB.amarelo,RGB.fimcor, C[CAR[i].cliente].nome_completo);
                printf("%s | Numero de Cliente:%s %04d\n",RGB.amarelo,RGB.fimcor, CAR[i].cliente);
                printf("%s | Numero do Artigo:%s  %04d\n",RGB.verde,RGB.fimcor, A[artigo].numeroartigo);                //MOSTRA A INFORMACAO NA STRING INDICADA [i]
                printf("%s | Nome do Artigo:%s    %s\n",RGB.verde,RGB.fimcor, A[artigo].nomeartigo);                      //MOSTRA A INFORMACAO NA STRING INDICADA [i]
                printf("%s | Marca do Artigo:%s   %s\n",RGB.verde,RGB.fimcor, A[artigo].marcaartigo);                    //MOSTRA A INFORMACAO NA STRING INDICADA [i]
                printf("%s | Produto:%s           %s\n",RGB.verde,RGB.fimcor, A[artigo].produtoartigo);                          //MOSTRA A INFORMACAO NA STRING INDICADA [i]
                printf("%s | Categoria:%s         %s\n",RGB.verde,RGB.fimcor, A[artigo].categoriaartigo);                      //MOSTRA A INFORMACAO NA STRING INDICADA [i]
                printf("%s | Sub-Categoria:%s     %s\n",RGB.verde,RGB.fimcor, A[artigo].subcategoriaartigo);               //MOSTRA A INFORMACAO NA STRING INDICADA [i]
                printf("%s | Cor:%s               %s\n",RGB.verde,RGB.fimcor, A[artigo].corartigo);                                  //MOSTRA A INFORMACAO NA STRING INDICADA [i]
                printf("%s | Tamanho:%s           %s\n",RGB.verde,RGB.fimcor, A[artigo].tamanhoartigo);                          //MOSTRA A INFORMACAO NA STRING INDICADA [i]
                printf("%s | Preco:%s             %0.2f euro/s\n",RGB.verde,RGB.fimcor, atof(A[artigo].precoartigo));                       //MOSTRA A INFORMACAO NA STRING INDICADA [i]
                printf("%s | Quantidade:%s        %d\n",RGB.verde,RGB.fimcor, CAR[i].quantidade);
                printf("%s | Estado da compra:%s  %s\n",RGB.verde,RGB.fimcor, CAR[i].estado);
                printf("\n");
            }
        }
    }
}

//VOID FAZER O CHECKUP DA COMPRA DOS ARTIGOS DO CARRINHO
void checkout(struct carrinho CAR[],struct artigo A[],struct cliente C[],int ACAR,int pc, int paT,int *pagar, struct cores RGB) {
    float precototal = 0, portes = 20, promo = 20, total = 0, numax = 0;
    int opcao = -1, artigo = -1, check = 0, ct1 = 0;
    artr rel[101];
    for (int g = 0; g < ACAR+1; g++) {
        if (CAR[g].cliente == pc && strcmp(CAR[g].estado,"NAO PAGO") == 0) {
            check = 1;
            break;
        }
    }

    if(check == 1){
        printf("\n");
        printf("%s |-------------------------------------|%s \n",RGB.verde,RGB.fimcor);
        printf("%s |          Detalhe da compra          |%s\n",RGB.verde,RGB.fimcor);
        printf("%s |-------------------------------------|%s \n",RGB.verde,RGB.fimcor);
        printf("%s |-                                   -|%s\n",RGB.verde,RGB.fimcor);

        for (int i = 0; i < ACAR+1; i++) {
            if(CAR[i].cliente == pc && strcmp(CAR[i].estado,"NAO PAGO") == 0){
                artigo = (CAR[i].numeroartigo)-1;
                printf("%s | Numero do Artigo:%s %-16.04d  %s|%s \n",RGB.verde,RGB.fimcor, A[artigo].numeroartigo, RGB.verde,RGB.fimcor);
                printf("%s | Artigo:%s           %-16.16s  %s|%s \n",RGB.verde,RGB.fimcor, A[artigo].nomeartigo, RGB.verde,RGB.fimcor);
                printf("%s | Marca do Artigo:%s  %-16.16s  %s|%s \n",RGB.verde,RGB.fimcor, A[artigo].marcaartigo, RGB.verde,RGB.fimcor);
                printf("%s | Produto:%s          %-16.16s  %s|%s \n",RGB.verde,RGB.fimcor, A[artigo].produtoartigo, RGB.verde,RGB.fimcor);
                printf("%s | Categoria:%s        %-16.16s  %s|%s \n",RGB.verde,RGB.fimcor, A[artigo].categoriaartigo, RGB.verde,RGB.fimcor);
                printf("%s | Sub-Categoria:%s    %-16.16s  %s|%s \n",RGB.verde,RGB.fimcor, A[artigo].subcategoriaartigo, RGB.verde,RGB.fimcor);
                printf("%s | Cor:%s              %-16.16s  %s|%s \n",RGB.verde,RGB.fimcor, A[artigo].corartigo, RGB.verde,RGB.fimcor);
                printf("%s | Tamanho:%s          %-16.16s  %s|%s \n",RGB.verde,RGB.fimcor, A[artigo].tamanhoartigo);
                printf("%s | Preco:%s            %-16.2f  %s|%s \n",RGB.verde,RGB.fimcor, atof(A[artigo].precoartigo), RGB.verde,RGB.fimcor);
                printf("%s | Quantidade:%s       %-16d  %s|%s \n",RGB.verde,RGB.fimcor, CAR[i].quantidade, RGB.verde,RGB.fimcor);
                printf("%s |-                                   -|%s\n",RGB.verde,RGB.fimcor);
                precototal += atof(A[artigo].precoartigo) * CAR[i].quantidade;
            }
        }
        printf("%s |-------------------------------------|%s \n",RGB.verde,RGB.fimcor);

        if (strcmp(C[pc].tipocliente, "GOLDE") != 0 && precototal < 100) {
            promo=0;
            total = precototal + portes;
        } else if (strcmp(C[pc].tipocliente, "GOLDE") != 0 && precototal > 100){
            total = precototal;
        }

        if (strcmp(C[pc].tipocliente, "GOLDE") == 0) {
            total = precototal;
        }

 //--------------------------- Artigos Relacionados ----------------------------------

        for (int i = 0; i < paT; i++){
            A[i].relacionado = 0;
            for (int i = 0; i < ACAR+1; i++){
                if(CAR[i].cliente == pc && strcmp(CAR[i].estado,"NAO PAGO") == 0){
                    artigo = -1;
                    artigo = (CAR[i].numeroartigo)-1;
                    for (int i = 0; i < paT ; i++){
                        if(strcmp(A[artigo].nomeartigo,A[i].nomeartigo) == 0){
                        A[i].relacionado += 5;
                        }
                        if(strcmp(A[artigo].categoriaartigo,A[i].categoriaartigo) == 0){
                        A[i].relacionado += 25;
                        }
                        if(strcmp(A[artigo].subcategoriaartigo,A[i].subcategoriaartigo) == 0){
                        A[i].relacionado += 35;
                        }
                        if(strcmp(A[artigo].marcaartigo,A[i].marcaartigo) == 0){
                        A[i].relacionado += 20;
                        }
                        if(strcmp(A[artigo].produtoartigo,A[i].produtoartigo) == 0){
                        A[i].relacionado += 15;
                        }
                        if(strcmp(A[artigo].corartigo,A[i].corartigo) == 0){
                        A[i].relacionado += 15;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < ACAR+1; i++){
            int aprel = 0;
            aprel = CAR[i].numeroartigo;
            if (i != 0) A[aprel-1].relacionado = 0;
        }

        ct1 = 0;
        for(int i = 0; i < paT ; i++){
            if(A[i].relacionado >= numax){
                numax = A[i].relacionado;
            }
        }
        for(int i = 0; i < paT ; i++){
            if(A[i].relacionado == numax){
                A[i].relacionado = 100.0;
            }
            else A[i].relacionado = ((A[i].relacionado*100.0)/numax);
        }


        for(int i = 0; i < paT ; i++){
            if(A[i].relacionado > 0){ //Pode ser atribuida uma percentagem apartir da qual o artigo relacionado � mostrado
                rel[ct1].num = A[i].numeroartigo;
                rel[ct1].perc = A[i].relacionado;
                ct1++;
            }
            else{
                rel[ct1].num = -1;
                rel[ct1].perc = -1;
            }
        }

        int h = 0, f = 0;
        float s = 0;
        for (int i = 0 ; i < ct1 ; i++){
            for (h = i+1 ; h < ct1 ; h++){
                if (rel[i].perc < rel[h].perc){
                    s = rel[i].perc;
                    rel[i].perc = rel[h].perc;
                    rel[h].perc = s;
                    f = rel[i].num;
                    rel[i].num = rel[h].num;
                    rel[h].num = f;
                }
            }
        }
        int artrel1 = -1;
        int artrel2 = -1;
        artrel1 += (rel[0].num);
        artrel2 += (rel[1].num);
//--------------------------------------------------FIM DOS ARTIGOS RELACIONADOS-----------------------------------------------------------


        printf("%s | Artigos Relacionados com a compra:  |%s \n",RGB.verde,RGB.fimcor);
        printf("%s |                                     |%s \n",RGB.verde,RGB.fimcor);
        if(artrel1 != -2){
        printf("%s | Artigo:%s           %-16.16s  %s|%s \n",RGB.verde,RGB.fimcor, A[artrel1].nomeartigo, RGB.verde,RGB.fimcor);
        printf("%s | Marca do Artigo:%s  %-16.16s  %s|%s \n",RGB.verde,RGB.fimcor, A[artrel1].marcaartigo, RGB.verde,RGB.fimcor);
        printf("%s | Produto:%s          %-16.16s  %s|%s \n",RGB.verde,RGB.fimcor, A[artrel1].produtoartigo, RGB.verde,RGB.fimcor);
        printf("%s | Categoria:%s        %-16.16s  %s|%s \n",RGB.verde,RGB.fimcor, A[artrel1].categoriaartigo, RGB.verde,RGB.fimcor);
        printf("%s | Sub-Categoria:%s    %-16.16s  %s|%s \n",RGB.verde,RGB.fimcor, A[artrel1].subcategoriaartigo, RGB.verde,RGB.fimcor);
        printf("%s | Cor:%s              %-16.16s  %s|%s \n",RGB.verde,RGB.fimcor, A[artrel1].corartigo, RGB.verde,RGB.fimcor);
        printf("%s |                                     |%s \n",RGB.verde,RGB.fimcor);
        printf("%s | Relacao de compra:%s   %-12.0f   %s|%s \n",RGB.verde,RGB.fimcor, A[artrel1].relacionado, RGB.verde,RGB.fimcor);
        printf("%s |                                     |%s \n",RGB.verde,RGB.fimcor);
        }
        else{
            printf("%s |Nao existem mais artigos relacionados|%s \n",RGB.verde,RGB.fimcor);
        }
        if(artrel2 != -2){
        printf("%s | Artigo:%s           %-16.16s  %s|%s \n",RGB.verde,RGB.fimcor, A[artrel2].nomeartigo, RGB.verde,RGB.fimcor);
        printf("%s | Marca do Artigo:%s  %-16.16s  %s|%s \n",RGB.verde,RGB.fimcor, A[artrel2].marcaartigo, RGB.verde,RGB.fimcor);
        printf("%s | Produto:%s          %-16.16s  %s|%s \n",RGB.verde,RGB.fimcor, A[artrel2].produtoartigo, RGB.verde,RGB.fimcor);
        printf("%s | Categoria:%s        %-16.16s  %s|%s \n",RGB.verde,RGB.fimcor, A[artrel2].categoriaartigo, RGB.verde,RGB.fimcor);
        printf("%s | Sub-Categoria:%s    %-16.16s  %s|%s \n",RGB.verde,RGB.fimcor, A[artrel2].subcategoriaartigo, RGB.verde,RGB.fimcor);
        printf("%s | Cor:%s              %-16.16s  %s|%s \n",RGB.verde,RGB.fimcor, A[artrel2].corartigo, RGB.verde,RGB.fimcor);
        printf("%s |                                     |%s \n",RGB.verde,RGB.fimcor);
        printf("%s | Relacao de compra:%s   %-12.0f   %s|%s \n",RGB.verde,RGB.fimcor, A[artrel2].relacionado, RGB.verde,RGB.fimcor);
        printf("%s |                                     |%s \n",RGB.verde,RGB.fimcor);
        }
        else{
            printf("%s |Nao existem mais artigos relacionados|%s \n",RGB.verde,RGB.fimcor);
        }
        printf("%s |                                     |%s \n",RGB.verde,RGB.fimcor);
        printf("%s |-------------------------------------|%s \n",RGB.verde,RGB.fimcor);
        printf("%s |     v  Confirmacao do pedido  v     |%s \n",RGB.verde,RGB.fimcor);
        printf("%s |                                     |%s \n",RGB.verde,RGB.fimcor);
        printf("%s | Total dos Artigos:%s %10.2f       %s|%s \n",RGB.verde,RGB.fimcor, precototal, RGB.verde,RGB.fimcor);
        printf("%s | Portes:%s            %10.2f       %s|%s \n",RGB.verde,RGB.fimcor, portes, RGB.verde,RGB.fimcor);
        printf("%s | Promocao aplicada:%s %10.2f       %s|%s \n",RGB.verde,RGB.fimcor, promo, RGB.verde,RGB.fimcor);
        printf("%s | Total:%s             %10.2f       %s|%s \n",RGB.verde,RGB.fimcor, total, RGB.verde,RGB.fimcor);
        printf("%s |-------------------------------------|%s \n",RGB.verde,RGB.fimcor);
        printf("%s |     DESEJA EFETUAR O PAGAMENTO?     |%s \n",RGB.verde,RGB.fimcor);
        printf("%s |                                     |%s \n",RGB.verde,RGB.fimcor);
        printf("%s |-            1  -> SIM              -|%s \n",RGB.verde,RGB.fimcor);
        printf("%s |-            0  -> NAO              -|%s \n",RGB.amarelo,RGB.fimcor);
        printf("%s |-------------------------------------|%s \n",RGB.verde,RGB.fimcor);
        printf("\n");

        opcao = opcaoIntegerOnly(0,0,1,0);

        if (opcao == 1) {
            *pagar = 1;
        } else {
            printf("%s Checkup Cancelado!! %s \n",RGB.vermelho,RGB.fimcor);
        }
    } else {
        printf("\n %s Nao tem Artigos no carrinho!! %s \n",RGB.vermelho,RGB.fimcor);
    }
}

//VOID FAZER O PAGAMENTO COM BASE NO CHECKUP
void pagamento(struct carrinho CAR[],struct cliente C[],int ACAR, int pc,int *pagar, struct cores RGB) {
    int opcao = -1;

    printf("\n");
    printf("%s |-------------------------------------|%s \n",RGB.verde,RGB.fimcor);
    printf("%s |      v  Dados de pagamento  v       |%s \n",RGB.verde,RGB.fimcor);
    printf("%s |                                     |%s \n",RGB.verde,RGB.fimcor);
    printf("%s | Nome:%s     %-24.24s  %s|%s \n",RGB.verde,RGB.fimcor, C[pc].nome_completo, RGB.verde,RGB.fimcor);
    printf("%s | Morada:%s   %-24.24s  %s|%s \n",RGB.verde,RGB.fimcor, C[pc].morada, RGB.verde,RGB.fimcor);
    printf("%s | N.Porta:%s  %-24.24s  %s|%s \n",RGB.verde,RGB.fimcor, C[pc].nporta, RGB.verde,RGB.fimcor);
    printf("%s | C.Postal:%s %-24.24s  %s|%s \n",RGB.verde,RGB.fimcor, C[pc].codigopostal, RGB.verde,RGB.fimcor);
    printf("%s | Cidade:%s   %-24.24s  %s|%s \n",RGB.verde,RGB.fimcor, C[pc].cidade, RGB.verde,RGB.fimcor);
    printf("%s |                                     |%s \n",RGB.verde,RGB.fimcor);
    printf("%s | Cartao:%s   %-16.16s          %s|%s \n",RGB.verde,RGB.fimcor, C[pc].cartaocredito, RGB.verde,RGB.fimcor);
    printf("%s | CVE:%s      %-16.16s          %s|%s \n",RGB.verde,RGB.fimcor, C[pc].cartaocreditocve, RGB.verde,RGB.fimcor);
    printf("%s | Validade:%s %-16.16s          %s|%s \n",RGB.verde,RGB.fimcor, C[pc].cartaocreditovalidade, RGB.verde,RGB.fimcor);
    printf("%s |-------------------------------------|%s \n",RGB.verde,RGB.fimcor);
    printf("%s |      DESEJA CONCLUIR PAGAMENTO?     |%s \n",RGB.verde,RGB.fimcor);
    printf("%s |                                     |%s \n",RGB.verde,RGB.fimcor);
    printf("%s |-            1  -> SIM              -|%s \n",RGB.verde,RGB.fimcor);
    printf("%s |-            0  -> NAO              -|%s \n",RGB.amarelo,RGB.fimcor);
    printf("%s |-------------------------------------|%s \n",RGB.verde,RGB.fimcor);

    opcao = opcaoIntegerOnly(0,0,1,0);

    if (opcao == 1) {
        printf("%s Pagamento efetuado com sucesso!! %s \n",RGB.verde,RGB.fimcor);

        for(int i = 0; i < ACAR+1; i++){
            if(CAR[i].cliente == pc && strcmp(CAR[i].estado,"NAO PAGO") == 0){
                strcpy(CAR[i].estado, "PAGO");
            }
        }

    } else {
        printf("%s Pagamento cancelado!! %s \n",RGB.vermelho,RGB.fimcor);
    }
    *pagar = 0;
}


//--------------------------- Main ----------------------------------
//VOID MAIN
void main(){
    fflush(stdin);
    int menu_editar = 0, opcaoexterna = 0, opcao = -1,check = -1, terminar = 0;

    struct cliente C[100];
    int pc = -1, pcT = 0, NC=1, tipo = -1;

    struct artigo A[100];
    int pa = -1, paT = 0, NA = 1;

    struct cores RGB;
    int cores = 0;

    struct carrinho CAR[1000];
    int ACAR = 0, limitequantidades = 100, pagar = -1;


    inicializar(C,A,&NA,&NC,&pcT,&paT);

//----------------------------------------------------------------------------------------------- Compatibilidade com cores???
    printf(" |-------------------------------------------------------------------|\n");
    printf(" |       !! TODOS CARATERES intruduzidos ficam em MAIUSCULO !!       |\n");
    printf(" |                                                                   |\n");
    printf(" |  TESTE: \033[0;32m -> Este texto contem cor se for compativel <-\033[0m            |\n");
    printf(" |                                                                   |\n");
    printf(" |                  TERMINAL Compativel com CORES???                 |\n");
    printf(" |                                                                   |\n");
    printf(" |                      1  -> SIM - Loja v2.0                        |\n");
    printf(" |                      0  -> NAO - Loja v1.0                        |\n");
    printf(" |-------------------------------------------------------------------|\n");

    cores = opcaoIntegerOnly(0,0,1,0);

    if(cores == 1){
        strcpy(RGB.fimcor, "\033[0m");
        strcpy(RGB.rosa, "\033[0;35m");
        strcpy(RGB.azul, "\033[0;36m");
        strcpy(RGB.verde, "\033[0;32m");
        strcpy(RGB.vermelho, "\033[0;31m");
        strcpy(RGB.amarelo, "\033[0;33m");
    } else {
        strcpy(RGB.fimcor, "");
        strcpy(RGB.rosa, "");
        strcpy(RGB.azul, "");
        strcpy(RGB.verde, "");
        strcpy(RGB.vermelho, "");
        strcpy(RGB.amarelo, "");
    }

//----------------------------------------------------------------------------------------------- INICIO DO PROGRAMA STORE
    do{
        printf("\n");
        printf(" |-------------------------------------------------------------------|\n");
        printf(" |                  %sBEM VINDO AO PROGRAMA STORE!!!%s                   |\n",RGB.rosa,RGB.fimcor);
        printf(" |                                                                   |\n");
        printf(" | %sIntroduza ( -2 ) para Retorceder o Menu se ( 0 ) nao for indicado%s |\n",RGB.amarelo,RGB.fimcor);
        printf(" |                         %s* = Obrigatorio%s                           |\n",RGB.amarelo,RGB.fimcor);
        printf(" |-------------------------------------------------------------------|\n");



        //mostrarlistaartigos(A,paT); // se quiser saber de default os Artigos que tem no boot
        //mostrarlistaclientes(C,pcT); // se quiser saber de default os Clientes que tem no boot

        //----------------------------------------------------------------------------------------------- LOGIN
        do{
            pc = -1;
            tipo = -1;
            check = -1;
            printf("\n");
            printf("%s Menu: %s\n",RGB.azul,RGB.fimcor);
            printf("%s 1  -> Login %s\n",RGB.verde,RGB.fimcor);
            printf("%s 2  -> Registar %s\n",RGB.verde,RGB.fimcor);
            printf("%s 0  -> Terminar Programa Store %s\n",RGB.amarelo,RGB.fimcor);

            opcao = opcaoIntegerOnly(0,0,2,0);

            switch(opcao) {
                case 0:
                    printf("\n");
                    printf("%s Terminou o Programa Store %s\n",RGB.vermelho,RGB.fimcor);
                    check = 1;
                    break;

                case 1:
                    login(C,pcT,&tipo,&pc,RGB);
                    if(pc != -1) check = 1;
                    break;

                case 2:
                    printf("\n");
                    registarcliente(C,&NC,&pcT,RGB,tipo);
                    break;
            }
        } while (check != 1);

        //----------------------------------------------------------------------------------------------- NORMA/GOLDE
        while(tipo > 0) {
            terminar=0;

            printf("\n");
            printf("%s Menu: %s \n",RGB.azul,RGB.fimcor);
            printf("%s 1  -> Area Clientes %s \n",RGB.verde,RGB.fimcor);
            printf("%s 2  -> Carrinho %s \n",RGB.verde,RGB.fimcor);
            printf("%s 0  -> Terminar Programa Store %s \n",RGB.amarelo,RGB.fimcor);

            opcao = opcaoIntegerOnly(0,0,2,0);

            switch(opcao) {
                case 0:
                    printf("\n");
                    printf("%s Terminou Programa Store!! %s \n",RGB.vermelho,RGB.fimcor);
                    terminar = 1;
                    break;

                //----------------------- Area Clientes ------------------------
                case 1:
                    printf("\n");
                    printf("%s Area de Clientes %s \n",RGB.azul,RGB.fimcor);
                    printf("%s 1  -> Editar Cliente %s \n",RGB.verde,RGB.fimcor);
                    printf("%s 0  -> Sair da Area Clientes %s \n",RGB.amarelo,RGB.fimcor);

                    opcao = opcaoIntegerOnly(0,0,1,0);

                    switch(opcao) {
                        case 0:
                            printf("\n");
                            printf("%s Saiu da Area Clientes %s \n",RGB.vermelho,RGB.fimcor);
                            break;

                        case 1:
                            printf("\n");
                            mostrarcliente(C,pc,RGB);
                            menu_editar = 1;
                            editar(C,A,pcT,paT,&pc,&pa,&menu_editar,RGB,tipo);
                            break;
                    }
                break;

                case 2:

                    printf("\n");
                    printf("%s Carrinho %s \n",RGB.azul,RGB.fimcor);
                    printf("%s 1  -> Meu carrinho %s \n",RGB.verde,RGB.fimcor);
                    printf("%s 2  -> Lista de Artigos %s \n",RGB.verde,RGB.fimcor);
                    printf("%s 3  -> Adicionar Artigo %s \n",RGB.verde,RGB.fimcor);
                    printf("%s 4  -> Editar Artigo %s \n",RGB.verde,RGB.fimcor);
                    printf("%s 5  -> Remover Artigo %s \n",RGB.verde,RGB.fimcor);
                    printf("%s 6  -> Fazer checkout %s \n",RGB.verde,RGB.fimcor);
                    printf("%s 7  -> Meus Pedidos %s \n",RGB.verde,RGB.fimcor);
                    printf("%s 0  -> Sair da Area Artigos %s \n",RGB.amarelo,RGB.fimcor);
                    printf("\n");

                    opcao = opcaoIntegerOnly(0,0,7,0);

                    switch(opcao){
                        case 0:
                            printf("%s Saiu da Area Artigos %s \n",RGB.vermelho,RGB.fimcor);
                            break;
                        case 1:
                            mostrarartigoscarrinho(CAR,pc,ACAR,A,RGB);
                            break;

                        case 2:
                            mostrarlistaartigos(A,paT,RGB);
                            break;

                        case 3:
                            do{
                                adicionarcarrinho(CAR,pc,&ACAR,paT,limitequantidades,RGB);
                                printf("%s Adicionar outro Artigo ao Carrinho? %s \n",RGB.verde,RGB.fimcor);
                                printf("%s 1  -> SIM %s \n",RGB.verde,RGB.fimcor);
                                printf("%s 0  -> NAO %s \n",RGB.amarelo,RGB.fimcor);
                                opcao = opcaoIntegerOnly(0,0,1,0);
                            } while (opcao != 0);
                            break;

                        case 4:
                            do{
                                editarcarrinho(CAR,pc,ACAR,paT,limitequantidades,RGB);
                                printf("%s Editar outro Artigo do Carrinho? %s \n",RGB.verde,RGB.fimcor);
                                printf("%s 1  -> SIM %s \n",RGB.verde,RGB.fimcor);
                                printf("%s 0  -> NAO %s \n",RGB.amarelo,RGB.fimcor);
                                opcao = opcaoIntegerOnly(0,0,1,0);
                            } while (opcao != 0);
                            break;

                        case 5:
                            do{
                                removercarrinho(CAR,&ACAR,pc,paT,RGB);
                                printf("%s Eliminar outro Artigo do Carrinho? %s \n",RGB.verde,RGB.fimcor);
                                printf("%s 1  -> SIM %s \n",RGB.verde,RGB.fimcor);
                                printf("%s 0  -> NAO %s \n",RGB.amarelo,RGB.fimcor);
                                opcao = opcaoIntegerOnly(0,0,1,0);
                            } while (opcao != 0);
                            break;

                        case 6:
                            checkout(CAR,A,C,ACAR,pc,paT,&pagar,RGB);

                            if(pagar == 1){
                                pagamento(CAR,C,ACAR,pc,&pagar,RGB);
                            }
                        break;

                        case 7:
                            mostrartodosartigoscarrinhopagos(CAR,C,pc,ACAR,A,RGB,1);
                            break;
                    }
                break;
            }
        if(terminar == 1) break;
        }


        //----------------------------------------------------------------------------------------------- ADMIN
        while(tipo == 0) {
            terminar=0;

            printf("\n");
            printf("%s Menu: %s \n",RGB.azul,RGB.fimcor);
            printf("%s 1  -> Area Clientes %s \n",RGB.verde,RGB.fimcor);
            printf("%s 2  -> Area Artigos %s \n",RGB.verde,RGB.fimcor);
            printf("%s 3  -> Ver Artigos PAGOS / NAO PAGOS %s \n",RGB.verde,RGB.fimcor);
            printf("%s 4  -> Ver Artigos NAO PAGOS %s \n",RGB.verde,RGB.fimcor);
            printf("%s 5  -> Ver Artigos PAGOS %s \n",RGB.verde,RGB.fimcor);
            printf("%s 0  -> Terminar Programa Store %s \n",RGB.amarelo,RGB.fimcor);

            opcao = opcaoIntegerOnly(0,0,5,0);

            switch(opcao) {
                case 0:
                    printf("\n");
                    printf("%s Terminou Programa Store!! %s \n",RGB.vermelho,RGB.fimcor);
                    terminar = 1;
                    break;

                //----------------------- Area Clientes ------------------------
                case 1:
                    printf("\n");
                    printf("%s Area de Clientes %s \n",RGB.azul,RGB.fimcor);
                    printf("%s 1  -> Lista de Clientes %s \n",RGB.verde,RGB.fimcor);
                    printf("%s 2  -> Pesquisar Clientes %s \n",RGB.verde,RGB.fimcor);
                    printf("%s 3  -> Registar Cliente %s \n",RGB.verde,RGB.fimcor);
                    printf("%s 4  -> Editar Cliente %s \n",RGB.verde,RGB.fimcor);
                    printf("%s 5  -> Remover Cliente %s \n",RGB.verde,RGB.fimcor);
                    printf("%s 0  -> Sair da Area Clientes %s \n",RGB.amarelo,RGB.fimcor);

                    opcao = opcaoIntegerOnly(0,0,5,0);

                    switch(opcao) {
                        case 0:
                            printf("\n");
                            printf("%s Saiu da Area Clientes %s \n",RGB.vermelho,RGB.fimcor);
                            break;

                        case 1:
                            printf("\n");
                            mostrarlistaclientes(C,pcT,RGB);
                            break;

                        case 2:
                            do{
                                printf("\n");
                                opcaoexterna=1;
                                pesquisar(C,A,pcT,paT,&menu_editar,&pc,&pa,opcaoexterna,RGB);
                                printf("%s Pesquisar outro Cliente? %s \n",RGB.verde,RGB.fimcor);
                                printf("%s 1  -> SIM %s \n",RGB.verde,RGB.fimcor);
                                printf("%s 0  -> NAO %s \n",RGB.amarelo,RGB.fimcor);
                                opcao = opcaoIntegerOnly(0,0,1,0);
                            } while (opcao != 0);
                            break;

                        case 3:
                            do{
                                printf("\n");
                                registarcliente(C,&NC,&pcT,RGB,tipo);
                                printf("%s Adicionar outro Cliente? %s \n",RGB.verde,RGB.fimcor);
                                printf("%s 1  -> SIM %s \n",RGB.verde,RGB.fimcor);
                                printf("%s 0  -> NAO %s \n",RGB.amarelo,RGB.fimcor);
                                opcao = opcaoIntegerOnly(0,0,1,0);
                            } while (opcao != 0);
                            break;

                        case 4:
                            do{
                                printf("\n");
                                opcaoexterna=3;
                                pesquisar(C,A,pcT,paT,&menu_editar,&pc,&pa,opcaoexterna,RGB);

                                if(menu_editar == 1) {
                                    printf("%s Deseja Editar Cliente? %s \n",RGB.azul,RGB.fimcor);
                                    printf("%s 1  -> SIM %s \n",RGB.verde,RGB.fimcor);
                                    printf("%s 0  -> NAO %s \n",RGB.amarelo,RGB.fimcor);

                                    opcao = opcaoIntegerOnly(0,0,1,0);

                                    if (opcao == 1) {
                                        editar(C,A,pcT,paT,&pc,&pa,&menu_editar,RGB,tipo);
                                    }
                                }
                                printf("%s Editar outro Cliente? %s \n",RGB.verde,RGB.fimcor);
                                printf("%s 1  -> SIM %s \n",RGB.verde,RGB.fimcor);
                                printf("%s 0  -> NAO %s \n",RGB.amarelo,RGB.fimcor);
                                opcao = opcaoIntegerOnly(0,0,1,0);
                            } while (opcao != 0);
                            break;

                        case 5:
                            do{
                                printf("\n");
                                opcaoexterna=4;
                                pesquisar(C,A,pcT,paT,&menu_editar,&pc,&pa,opcaoexterna,RGB);

                                if(menu_editar == 1) {
                                    printf("%s Deseja Eliminar Cliente? %s \n",RGB.azul,RGB.fimcor);
                                    printf("%s 1  -> SIM %s \n",RGB.verde,RGB.fimcor);
                                    printf("%s 0  -> NAO %s \n",RGB.amarelo,RGB.fimcor);

                                    opcao = opcaoIntegerOnly(0,0,1,0);

                                    if (opcao == 1) {
                                        removercliente(C,&pcT,pc,RGB);
                                    }
                                }
                                printf("%s Eliminar outro Cliente? %s \n",RGB.verde,RGB.fimcor);
                                printf("%s 1  -> SIM %s \n",RGB.verde,RGB.fimcor);
                                printf("%s 0  -> NAO %s \n",RGB.amarelo,RGB.fimcor);
                                opcao = opcaoIntegerOnly(0,0,1,0);
                            } while (opcao != 0);
                            break;
                    }
                    break;

                //----------------------- Area Artigos ------------------------
                case 2:
                    printf("\n");
                    printf("%s Area de Artigos %s \n",RGB.azul,RGB.fimcor);
                    printf("%s 1  -> Lista de Artigos %s \n",RGB.verde,RGB.fimcor);
                    printf("%s 2  -> Pesquisar Artigos %s \n",RGB.verde,RGB.fimcor);
                    printf("%s 3  -> Registar Artigo %s \n",RGB.verde,RGB.fimcor);
                    printf("%s 4  -> Editar Artigo %s \n",RGB.verde,RGB.fimcor);
                    printf("%s 5  -> Remover Artigo %s \n",RGB.verde,RGB.fimcor);
                    printf("%s 0  -> Sair da Area Artigos %s \n",RGB.amarelo,RGB.fimcor);

                    opcao = opcaoIntegerOnly(0,0,5,0);

                    switch(opcao) {
                        case 0:
                            printf("\n");
                            printf("%s Saiu da Area Artigos %s \n",RGB.vermelho,RGB.fimcor);
                            break;

                        case 1:
                            mostrarlistaartigos(A,paT,RGB);
                            break;

                        case 2:
                            do{
                                printf("\n");
                                opcaoexterna=2;
                                pesquisar(C,A,pcT,paT,&menu_editar,&pc,&pa,opcaoexterna,RGB);
                                printf("%s Pesquisar outro Cliente? %s \n",RGB.verde,RGB.fimcor);
                                printf("%s 1  -> SIM %s \n",RGB.verde,RGB.fimcor);
                                printf("%s 0  -> NAO %s \n",RGB.amarelo,RGB.fimcor);
                                opcao = opcaoIntegerOnly(0,0,1,0);
                            } while (opcao != 0);
                            break;

                        case 3:
                            do{
                                printf("\n");
                                registarartigo(A,&NA,&paT,RGB);
                                printf("%s Adicionar outro Artigo? %s \n",RGB.verde,RGB.fimcor);
                                printf("%s 1  -> SIM %s \n",RGB.verde,RGB.fimcor);
                                printf("%s 0  -> NAO %s \n",RGB.amarelo,RGB.fimcor);
                                opcao = opcaoIntegerOnly(0,0,1,0);
                            } while (opcao != 0);
                            break;

                        case 4:
                            do{
                                printf("\n");
                                opcaoexterna=5;
                                pesquisar(C,A,pcT,paT,&menu_editar,&pc,&pa,opcaoexterna,RGB);

                                if(menu_editar == 2) {
                                    printf("%s Deseja Editar Artigo? %s \n",RGB.azul,RGB.fimcor);
                                    printf("%s 1  -> SIM %s \n",RGB.verde,RGB.fimcor);
                                    printf("%s 0  -> NAO %s \n",RGB.amarelo,RGB.fimcor);

                                    opcao = opcaoIntegerOnly(0,0,1,0);

                                    if (opcao == 1) {
                                        editar(C,A,pcT,paT,&pc,&pa,&menu_editar,RGB,tipo);
                                    }
                                }
                                printf("%s Editar outro Artigo? %s \n",RGB.verde,RGB.fimcor);
                                printf("%s 1  -> SIM %s \n",RGB.verde,RGB.fimcor);
                                printf("%s 0  -> NAO %s \n",RGB.amarelo,RGB.fimcor);
                                opcao = opcaoIntegerOnly(0,0,1,0);
                            } while (opcao != 0);
                            break;

                        case 5:
                            do{
                                printf("\n");
                                opcaoexterna=6;
                                pesquisar(C,A,pcT,paT,&menu_editar,&pc,&pa,opcaoexterna,RGB);

                                if(menu_editar == 2) {
                                    printf("%s Deseja Eliminar Artigo? %s \n",RGB.azul,RGB.fimcor);
                                    printf("%s 1  -> SIM %s \n",RGB.verde,RGB.fimcor);
                                    printf("%s 0  -> NAO %s \n",RGB.amarelo,RGB.fimcor);

                                    opcao = opcaoIntegerOnly(0,0,1,0);

                                    if (opcao == 1) {
                                        removerartigo(A,&paT,pa,RGB);
                                    }
                                }
                                printf("%s Eliminar outro Artigo? %s \n",RGB.verde,RGB.fimcor);
                                printf("%s 1  -> SIM %s \n",RGB.verde,RGB.fimcor);
                                printf("%s 0  -> NAO %s \n",RGB.amarelo,RGB.fimcor);
                                opcao = opcaoIntegerOnly(0,0,1,0);
                            } while (opcao != 0);
                            break;
                    }
                    break;

                case 3:
                    mostrartodosartigoscarrinho(CAR,C,pc,ACAR,A,RGB);
                    break;

                case 4:
                    mostrartodosartigoscarrinhonaopagos(CAR,C,pc,ACAR,A,RGB);
                    break;

                case 5:
                    mostrartodosartigoscarrinhopagos(CAR,C,pc,ACAR,A,RGB,0);
                    break;

            }
        if(terminar==1) break;
        }

    }while(1);

}

