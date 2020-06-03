#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

char **M = NULL;
int m, n;

void waitFor(long int a) //espera por 'a' milissegundos;
{
	long int b = clock();
	while(clock()-b < a*1000){}
}

class no
{
	private:
		no *prox = NULL;
		int x, y;
	public:
		no(){}
		
		
		//sets e gets -----------------------------------
		void setX(int a)
		{
			x = a;
		}
		void setY(int a)
		{
			y = a;
		}
		void setProx(no *a)
		{
			prox = a;
		}
		
		int getX()
		{
			return x;
		}
		
		int getY()
		{
			return y;
		}
		
		no *getProx()
		{
			return prox;
		}
		//---------------------------------------------------------------------------------------------------------------

		


};

class fila
{
	private:
		no *first = NULL;
	public:
		fila(){}
		
		void inserir(int x, int y)
		{
			no *aux = first;
			no *aux2 = new no;
			if(first == NULL)
			{
				aux2->setX(x);
				aux2->setY(y);
				
				first=aux2;
			}
			else
			{
				while(aux->getProx()!=NULL)
				{
					aux = aux->getProx();
				}
				aux2->setX(x);
				aux2->setY(y);
				aux->setProx(aux2);
			}
		}
		
		void retirar()
		{
			if(first!=NULL)
			{
				
				if(first->getProx()!=NULL)
				{
					no *aux = first;
					first = first->getProx();
					free(aux);
				}
				else
				{
					first = NULL;
				}
				
			}
		}
		
		void imprimeFila(long int time)
		{
			no *aux = first;
			if(first!=NULL)
			{
				while(aux != NULL)
				{
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
					for(int i=0;i<=n;i++)
					{
						if(i==0)
						{
							printf("\t ");
						}
						else
						{
							printf("%d ", i);
						}
					}
					printf("\n");
					for(int i=0;i<m;i++)
					{
						for(int j=0;j<(n+1);j++)
						{
							if(j==0)
							{
								printf("%d\t ", i+1);
							}
							else if(i == aux->getX() && j-1 == aux->getY())
							{
								printf("X ");
							}
							else
							{
								printf("- ");
							}
						}
						printf("\n");
					}
					waitFor(time);
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
					aux = aux->getProx();
				}
			}
			else
			{
				printf("Fila vazia\n");
			}
		}

		void formaFila(int n)
		{
			if(first==NULL)
			{
					int a, b;
					for(int i=0;i<n;i++)
					{
						a = rand()%m;
						b = rand()%n;
						while(M[a][b] != '-')
						{
							a = rand()%m;
							b = rand()%n;
						}
						inserir(a,b);
						M[a][b] = 'X';
					}
			}
		}
		
		void limpaFila()
		{
			while(first!=NULL)
			{
				retirar();
			}
		}

		int procurar(int a, int b)
		{
			
			if(first!=NULL)
			{
				no *aux = first;
				while(aux!=NULL)
				{
					if(aux->getX()==a && aux->getY()==b)
					{
						return 1;
					}
					aux = aux->getProx();
				}
			}
			return 0;
		}

		int validaEntrada(int a, int b)
		{
			if(procurar(a,b))
			{
				if(first->getX() == a && first->getY() == b)
				{
					retirar();
					return 1;
				}
				else
				{
					printf("Errado! A posição inserida está na ordem errada\n");
					waitFor(1000);
					return 0;
				}
			}
			else
			{
				printf("Errado! A posição inserida não foi exibida\n");
				waitFor(1000);
				return 0;
			}
		}
	
		int filaVazia()
		{
			if(first==NULL)
			{
				return 1;
			}
			return 0;
		}
};

char **controiMatriz()
{
	char **mat;

	printf("Escolha as dimensões da matriz\n");
	scanf("%d %d", &m, &n);
	if(m < 1 || n < 1)
	{
		printf("Tamanho invalido\n\n");
		return 0;
	}
	mat = (char**)malloc(sizeof(char**)*m);
	if(mat==NULL)
	{
		printf ("Erro: Memoria Insuficiente\n\n");
		return 0;
	}
	for(int i=0; i<m;i++)
	{
		mat[i] = (char*)malloc(sizeof(char*)*n);
		if(mat[i]==NULL)
		{
			printf ("Erro: Memoria Insuficiente\n\n");
			return 0;
		}
		memset(mat[i], '-', sizeof(char)*n);
	}
	
	
	return mat;
}

int aa, bb;

int main()
{
	
	while(!M)
	{
			M = controiMatriz();
	}
	
	printf("\n");
	
	fila a;
	
	a.formaFila(5);
	a.imprimeFila(2000);
	while(!a.filaVazia())
	{
		printf("Insira uma posição: ");
		scanf("%d %d", &aa, &bb);
		if(!a.validaEntrada(aa-1,bb-1))
		{
			a.limpaFila();
			a.formaFila(5);
			a.imprimeFila(2000);
		}
	}
	printf("\n\n-------------- Voce venceu O JOGO --------------\n");
	
	return 0;
}
