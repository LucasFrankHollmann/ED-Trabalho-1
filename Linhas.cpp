#include <iostream>
#include <stdio.h>
#include <stdlib.h>
 
using namespace std;
 
int **mat;
int m, n, p; //numero de linhas e colunas da matriz principal
 
class No
{
    private:
        int x, y;
        No *prox;
        No *prev;
        int ini = 0;
    public:
        No(int a, int b, int i)
        {
            x = a;
            y = b;
            ini = i;
            prox = 0;
            prev = 0;
        }
        void setProx(No *a)
        {
            prox = a;
        }
        void setPrev(No *a)
        {
            prev = a;
        }
        No *getProx()
        {
            return prox;
        }
        No *getPrev()
        {
            return prev;
        }
        int getX()
        {
            return x;
        }
        int getY()
        {
            return y;
        }
        int getIni()
        {
            return ini;
        }
};
 
class Lista
{
    private:
        No *ini;
        No *fim;
        int val;
         
    public:
        Lista(){}
        void c(int a, int b, int c, int d, int v)
        {
            val = v;
            ini = new No(a, b, 1);
            fim = new No(c, d, 1);
            ini->setProx(fim);
            fim->setPrev(ini);
        }
        
        No *search(int a, int b)
        {
            No *aux = ini;
            while(aux!=0)
            {
                if(aux->getX() == a && aux->getY() == b)
                {
                    return aux;
                }
                aux = aux->getProx();
            }
             
             
            return NULL;
        }
         
        void removeR()
        {
            No *aux2 = fim->getPrev(), *aux;
            mat[aux2->getX()-1][aux2->getY()-1]=0;
            aux = aux2->getPrev();
            free(aux2);
            aux->setProx(fim);
            fim->setPrev(aux);
             
        }
         
        void removeL()
        {
            No *aux2 = ini->getProx(), *aux;
            mat[aux2->getX()-1][aux2->getY()-1]=0;
            aux = aux2->getProx();
            free(aux2);
            aux->setPrev(ini);
            ini->setProx(aux);
             
        }
         
        void limpaLista()
        {
            No *aux = ini->getProx();
             
             
            while(ini->getProx()!=0 && aux->getIni()==0)
            {
                removeR();
                aux = ini->getProx();
            }
        }
         
        int insertR(Lista *L)
        {
            char lado[10];
            int a, b;
            No *aux2=ini, *aux = aux2;
            printf("Escolha um lado para avancar (D (direita), E(esquerda), C(cima) ou B(baixo))\n");
            scanf("%s", lado);
             
             
             
            //printf("a");
            while(aux2->getProx()!=0)
            {       
                    aux = aux2;
                    aux2 = aux2->getProx();
            }
            if(lado[0] == 'D' || lado[0] == 'd')
            {
                a = aux->getX();
                b = aux->getY()+1;
            }
            else if(lado[0] == 'B' || lado[0] == 'b')
            {
                a = aux->getX()+1;
                b = aux->getY();
            }
            else if(lado[0] == 'E' || lado[0] == 'e')
            {
                a = aux->getX();
                b = aux->getY()-1;
            }
            else if(lado[0] == 'C' || lado[0] == 'c')
            {
                a = aux->getX()-1;
                b = aux->getY();
            }
            else
            {
                return 0;
            }
            if(a == fim->getX() && b == fim->getY())
            {
                    return 1;
            }
 
            if(b>0 && b<=n && a>0 && a<=m)
            {
                //printf("%d\n\n", mat[a-1][b-1]);
                if(mat[a-1][b-1]!=0)
                {
                    No *ver = L[mat[a-1][b-1]].search(a,b);
                    if(mat[a-1][b-1]==val)
                    {
						No *aux2 = aux->getPrev();
                        if(aux2->getX()==a && aux2->getY()==b)
						{
							this->removeR();
							return 0;
						} 
						else
						{
							printf("Posicao invalida\n");
							return 0;
						}
                         
                    }
                    else if(ver->getIni()!=0)
                    {
                        printf("Posicao invalida\n");
                        return 0;
                    }
                     
                    else
                    {
                        L[mat[a-1][b-1]].limpaLista();
                    }
                }
                 
            }
            else
            {
                printf("Posicao invalida\n");
                return 0;
            }
             
            mat[a-1][b-1]=val;
            No *novo = new No(a,b,0);
             
            novo->setProx(fim);
            aux->setProx(novo);
            novo->setPrev(aux);
            fim->setPrev(novo);
             
            return 0;
        }
         
        int insertL(Lista *L)
        {
            char lado[10];
            int a, b;
            No *aux2=fim, *aux = aux2;
            printf("Escolha um lado para avancar (D (direita), E(esquerda), C(cima) ou B(baixo))\n");
            getchar();
            scanf("%s", lado);
             
             
             
            //printf("a");
            while(aux2->getPrev()!=0)
            {       
                    aux = aux2;
                    aux2 = aux2->getPrev();
            }
            if(lado[0] == 'D' || lado[0] == 'd')
            {
                a = aux->getX();
                b = aux->getY()+1;
            }
            else if(lado[0] == 'B' || lado[0] == 'b')
            {
                a = aux->getX()+1;
                b = aux->getY();
            }
            else if(lado[0] == 'E' || lado[0] == 'e')
            {
                a = aux->getX();
                b = aux->getY()-1;
            }
            else if(lado[0] == 'C' || lado[0] == 'c')
            {
                a = aux->getX()-1;
                b = aux->getY();
            }
            else
            {
                return 0;
            }
            if(a == ini->getX() && b == ini->getY())
            {
                    return 1;
            }
 
            if(b>0 && b<=n && a>0 && a<=m)
            {
                printf("%d\n\n", mat[a-1][b-1]);
                if(mat[a-1][b-1]!=0)
                {
                    No *ver = L[mat[a-1][b-1]].search(a,b);
                    if(mat[a-1][b-1]==val)
                    {
						No *aux2 = aux->getPrev();
                        if(aux2->getX()==a && aux2->getY()==b)
						{
							this->removeL();
							return 0;
						} 
						else
						{
							printf("Posicao invalida\n");
							return 0;
						}
                    }
                    else if(ver->getIni()!=0)
                    {
                        printf("Posicao invalida\n");
                        return 0;
                    }
                     
                    else
                    {
                        L[mat[a-1][b-1]].limpaLista();
                    }
                }
                 
            }
            else
            {
                printf("Posicao invalida\n");
                return 0;
            }
             
            mat[a-1][b-1]=val;
            No *novo = new No(a,b,0);
             
            novo->setPrev(ini);
            aux->setPrev(novo);
            novo->setProx(aux);
            ini->setProx(novo);
             
            return 0;
        }
         
        void printLista()
        {
            No *aux = ini;
             
            while(aux!=0)
            {       
				cout << aux->getX() <<"  "<< aux->getY() << endl;
				aux = aux->getProx();
            }
        }
        
        int listaCheia()
        {
			No *aux = ini->getProx();
			
			if(((ini->getX() + ini->getY()) - (aux->getX() + aux->getY()))!=1 && ((ini->getX() + ini->getY()) - (aux->getX() + aux->getY()))!=-1)
			{
				return 0;
			} 
			
			aux = fim->getPrev();
			
			if(((fim->getX() + fim->getY()) - (aux->getX() + aux->getY()))!=1 && ((fim->getX() + fim->getY()) - (aux->getX() + aux->getY()))!=-1)
			{
				return 0;
			}
			return 1;
		}
     
};
 
Lista *L;

int **constroiMatriz()
{
    int **mat, x, y, x1, y1;
    printf("Insira o tamanho da matriz:\n");
    scanf("%d %d", &m, &n);
    if (m < 1 || n < 1) //verifica o tamanho;
    { 
     printf ("Erro: Tamanho invalido\n");
     return (NULL);
    }
    // aloca as linhas da matriz 
    mat = (int**) malloc(m*sizeof(int**));
    if (mat == NULL) 
    {
        printf ("Erro: Memoria Insuficiente\n");
        return (NULL);
    }
    for(int i=0;i<m;i++)
    {
        mat[i] = (int*) malloc(n*sizeof(int*));
        if (mat[i] == NULL) 
        {
            printf ("Erro: Memoria Insuficiente\n");
            return (NULL);
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            mat[i][j]=0;
            //printf("%d ", mat[i][j]);
        }
        //printf("\n");
    }
    printf("Insira a quantidade de pares de pontos iniciais:\n");
    scanf("%d", &p);
     
    if (p < 1 || p > (m*n)/2) //verifica a quantidade de pares iniciais;
    { 
     printf ("Erro: Quantidade invalida de pontos iniciais\n");
     return (NULL);
    }
     
    L = (Lista *)malloc(sizeof(Lista)*(p+1));
     
    for(int i=1;i<=p;i++)
    {
        printf("Par %d:\n", i);
         
         
        x=0;
        y=0;
        while(x<1 || x>m || y<1 || y>n || mat[x-1][y-1]!=0)
        {
            printf("    Ponto 1: ");
            scanf("%d", &x);
            scanf("%d", &y);
            if(x<1 || x>m || y<1 || y>n || mat[x-1][y-1]!=0)
                printf("Erro: ponto invalido\n");
        }
        mat[x-1][y-1]=i;
        x1=0;
        y1=0;
        while(x1<1 || x1>m || y1<1 || y1>n || mat[x1-1][y1-1]!=0)
        {
            printf("    Ponto 2: ");
            scanf("%d", &x1);
            scanf("%d", &y1);
            if(x1<1 || x1>m || y1<1 || y1>n || mat[x1-1][y1-1]!=0)
                printf("Erro: ponto invalido\n");
        }
        mat[x1-1][y1-1]=i;
         
         
        L[i].c(x,y,x1,y1,i);
    }
    printf("Matriz inicial:\n\n");
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            //mat[i][j]=0;
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    return mat;
}
 
int winCondition()
{
	for(int i=1;i<=p;i++)
	{
		if(!L[i].listaCheia())
		{
			return 0;
		}
	}
	for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
			if(mat[i][j]==0)
			{
				return 0;
			}
		}
	}
	
	
    return 1;
}
 
void oJogo()
{
    int px, py;
    while(!winCondition())
    {
		
		
        while(1)
        {
            printf("Escolha um ponto para começar a preencher: ");
            scanf("%d %d", &px, &py);
             
             
            if(px<=0 || px>m || py<=0 || py>n)
            {
                printf("Posicao invalida\n");
            }
            else if(mat[px-1][py-1]!=0)
            {
				if(L[mat[px-1][py-1]].listaCheia())
				{
					L[mat[px-1][py-1]].limpaLista();
				}
                No *aux = L[mat[px-1][py-1]].search(px,py);
                if(aux->getIni()==0)
                {
                    printf("Posicao invalida\n");
                }
                else if(aux->getIni()==1)
                {
                    if(aux->getProx()==0)
                    {
                        while(!L[mat[px-1][py-1]].insertL(L))
                        {
                            for(int i=0;i<m;i++)
                            {
                                for(int j=0;j<n;j++)
                                {
                                    printf("%d ", mat[i][j]);
                                }
                                printf("\n");
                            }
                        }
                    }
                    else
                    {
                        while(!L[mat[px-1][py-1]].insertR(L))
                        {
                            for(int i=0;i<m;i++)
                            {
                                for(int j=0;j<n;j++)
                                {
                                    printf("%d ", mat[i][j]);
                                }
                                printf("\n");
                            }
                        }
                    }
                    break;
                }
            }
            else
            {
                printf("Posicao invalida\n");
            }
        }
    }
    printf("-------------- Voce venceu O JOGO --------------\n");
}
 
int main()
{
    while(mat==NULL)
    {
        mat = constroiMatriz();
    }
     
    oJogo();
 
return 0;
}
