#include <stdio.h>
#include <stdlib.h>

char **mat;
int m, n;


class pedra
{
	private:
		int x, y;
		int val;
	public:
		pedra(int a, int b, int v)
		{
			x = a;
			y = b;
			val = v;
		}
		
		pedra(int v)
		{
			val = v;
		}
	
		int getX()
		{
			return x;
		}
		
		int getY()
		{
			return y;
		}
		
		int getVal()
		{
			return val;
		}

		void setPos(int a, int b)
		{
			x=a;
			y=b;
			mat[a][b]=val;
		}
		
		int verificaRemocao()
		{
				if(y == n-1 || y == 0)
				{
					return 1;
				}
				else if(mat[x][y+1]== '-' || mat[x][y-1]== '-')
				{
					return 1;
				}
				else
				{
					return 0;
				}
		}

		void removePedra()
		{	
			if(verificaRemocao())
			{
				mat[x][y] = '-';
				val = '-';
				x=-1;
				y=-1;
			}
		}
		
		int procuraPar(pedra *X)
		{
			for(int i=0;i<m*n;i++)
			{
				if(X[i].getVal()==val && (X[i].getX()!=x || X[i].getY()!=y))
				{
					return i;
				}
			}
			return 0;
		}

		int verificaPossibilidade(pedra *X)
		{
			for(int i=0;i<m*n;i++)
			{
				if(X[i].getVal()!='-')
				{
					if(X[i].verificaRemocao())
					{
						if(X[X[i].procuraPar(X)].verificaRemocao())
						{
							return 1;
						}
					}
				}
			}
			return 0;
		}
	
		int procurar(pedra *X, int a, int b)
		{
			for(int i=0;i<m*n;i++)
			{
				if(X[i].getX()==a && X[i].getY()==b)
				{
					return i;
				}
			}
			return 0;
		}
};

pedra *P;

void limpaMatriz()
{
	
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			
			mat[i][j]='-';
		}
	}
}

void printaMatriz()
{
	printf("\n\n");
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(mat[i][j]=='-')
			{
				printf("%c\t", mat[i][j]);
			}
			else
			{
				printf("%d\t ", mat[i][j]);
			}
		}
		printf("\n");
	}
	printf("\n\n");
}

void embaralhar()
{
	printf("Embaralhando...\n");
	
	int a, b;
	for(int i=0;i<m*n;i++)
	{
		if(P[i].getVal()!='-')
		{
			a = rand()%m;
			b = rand()%n;
			while(mat[a][b]!='-')
			{
				a = rand()%m;
				b = rand()%n;
			}
			P[i].setPos(a,b);
		}
	}
}

int constroiMatriz()
{
	
	printf("Escolha as dimensoes da matriz\n");
	scanf("%d %d", &m, &n);
	if((m*n)%2!=0)
	{
		printf("Tamanho invalido\n");
		return 0;
	}
	else
	{
		P = (pedra *)malloc(sizeof(pedra*)*m*n);
		
		for(int i=0;i<(m*n);i=i+2)
		{
			if(i==44)
			{
				i++;
				P[i-1] = *new pedra(i+1);
				P[i] = *new pedra(i+1);
				i--;
			}
			else
			{
				P[i] = *new pedra(i+1);
				P[i+1] = *new pedra(i+1);
			}
		}
		
		mat = (char **)malloc(sizeof(char**)*m);
		for(int i=0;i<m;i++)
		{
			mat[i] = (char *)malloc(sizeof(char*)*n);
		}
		
	}
	return 1;
}

int verificaFim()
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			
			if(mat[i][j]!='-')
			{
				return 0;
			}
		}
	}
	return 1;
}

int a1, b1, a2, b2, nn, mm;

int main()
{
	while(!constroiMatriz()){}
	limpaMatriz();
	embaralhar();
	printaMatriz();
	while(!P[1].verificaPossibilidade(P))
	{
		printf("Jogo travado\n");
		limpaMatriz();
		embaralhar();
		printaMatriz();
	}
	
	while(!verificaFim())
	{
		printf("Escolha dois pontos para remover:\n");
		scanf("%d %d", &a1, &b1);
		scanf("%d %d", &a2, &b2);
		
		a1--;
		a2--;
		b1--;
		b2--;
		
		nn = P[1].procurar(P, a1, b1);
		mm = P[1].procurar(P, a2, b2);;
		if(P[nn].getVal() == P[mm].getVal() && P[nn].getVal()!='-')
		{
			if(P[nn].verificaRemocao() && P[mm].verificaRemocao())
			{
				P[nn].removePedra();
				P[mm].removePedra();
			}
			else
			{
				printf("Posicoes invalidas\n");
			}
		}
		else
		{
			printf("Posicoes invalidas\n");
		}
		
		printaMatriz();
		while(!P[1].verificaPossibilidade(P) && !verificaFim())
		{
			printf("Jogo travado\n");
			limpaMatriz();
			embaralhar();
			printaMatriz();
		}
		
	}
	
	printf("-------------- Voce venceu O JOGO --------------\n");
	
	return 0;
}
