#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class funcionario
{
	private:
		char nome[20], sobrenome[20], categoria[20];
		int code, cpf, tempo, filhos;
		double salBase, salFinal;
		
	public:
		funcionario(char *n, char *sn, char *c, int cd, int fpc, int time, int f, int sal1, int sal2)
		{
			
			strcpy(nome, n);
			strcpy(sobrenome, sn);
			strcpy(categoria, c);
			code = cd;
			cpf = fpc;
			tempo = time;
			filhos = f;
			salBase = sal1;
			salFinal = sal2;
		}
		
		int getTempo()
		{
			return tempo;
		}		
		char *getNome()
		{
			return nome;
		}
		char *getSobrenome()
		{
			return sobrenome;
		}
		char *getCategoria()
		{
			return categoria;
		}
		int getCode()
		{
			return code;
		}
		int getCpf()
		{
			return cpf;
		}
		int getFilhos()
		{
			return filhos;
		}
		double getSalBase()
		{
			return salBase;
		}
		double getSalFinal()
		{
			return salFinal;
		}
		void setSalFinal(double a)
		{
			salFinal = a;
		}
		
		
		void printaInfo()
		{
			printf("Nome: %s\n", nome);
			printf("Sobrenome: %s\n", sobrenome);
			printf("Categoria: %s\n", categoria);
			printf("Codigo: %d\n", code);
			printf("CPF: %d\n", cpf);
			printf("Quantidade de filhos: %d\n", filhos);
			printf("Tempo na empresa (meses): %d\n", tempo);
			printf("Salario base: %lf\n", salBase);
			printf("Salario final: %lf\n", salFinal);
		}
		template <class X>
		void ferias(X a)
		{
			printf("Faltam %d meses para o funcionario entrar em ferias\n", 11-(a.getTempo()%12));
		}
	
		double calculaSalario()
		{
			return 0;
		}

};

class motorista:public funcionario
{
	private:
		char habilitacao;
		int corridas, horas;
	
		friend motorista compra(motorista, int);
	public:
	motorista(char *n, char *sn, char *c, int cd, int fpc, int time, int f, int sal1, int sal2, char hab, int cor, int hr):funcionario(n,sn,c,cd,fpc,time,f,sal1,sal2)
	{
		habilitacao = hab;
		corridas = cor;
		horas = hr;
	}

	void printaInfo()
		{
			printf("Nome: %s\n", getNome());
			printf("Sobrenome: %s\n", getSobrenome());
			printf("Categoria: %s\n", getCategoria());
			printf("Codigo: %d\n", getCode());
			printf("CPF: %d\n", getCpf());
			printf("Quantidade de filhos: %d\n", getFilhos());
			printf("Tempo na empresa (meses): %d\n", getTempo());
			printf("Salario base: %lf\n", getSalBase());
			printf("Salario final: %lf\n", getSalFinal());
			printf("Habilitacao: %c\n", habilitacao);
			printf("Numero de corridas: %d\n", corridas);
			printf("Horas em transito: %d\n", horas);
		}

	double calculaSalario()
	{
		double bonus=1;
		if(corridas>=100)
		{
			bonus+=0.10;
		}
		if(habilitacao == 'D' && horas >= 160)
		{
			bonus+=0.50;
		}
		else if (habilitacao == 'C' && horas >= 180)
		{
			bonus+=0.40;
		}
		setSalFinal(getSalBase()*bonus);
		return getSalBase()*bonus;
	}

};

class R_estoque:public funcionario
{
	private:
		int T_carga, n_cargas;
	
	public:
	R_estoque(char *n, char *sn, char *c, int cd, int fpc, int time, int f, int sal1, int sal2, int tc, int nc):funcionario(n,sn,c,cd,fpc,time,f,sal1,sal2)
	{
		T_carga = tc;
		n_cargas = nc;
	}

	void printaInfo()
		{
			printf("Nome: %s\n", getNome());
			printf("Sobrenome: %s\n", getSobrenome());
			printf("Categoria: %s\n", getCategoria());
			printf("Codigo: %d\n", getCode());
			printf("CPF: %d\n", getCpf());
			printf("Quantidade de filhos: %d\n", getFilhos());
			printf("Tempo na empresa (meses): %d\n", getTempo());
			printf("Salario base: %lf\n", getSalBase());
			printf("Salario final: %lf\n", getSalFinal());
			printf("Toneladas carregadas: %d\n", T_carga);
			printf("Numero de cargas: %d\n", n_cargas);
		}

	double calculaSalario()
	{
		double bonus=1;
		
		bonus+=0.03*T_carga;
		
		if(n_cargas >= 250)
		{
			bonus+=0.35;
		}
		setSalFinal(getSalBase()*bonus);
		return getSalBase()*bonus;
	}

	void cargaDescarga(int peso)
	{
		T_carga+=peso;
		n_cargas++;
	}

};

class vendedor:public funcionario
{
	private:
		double valor_vendido;
		int vendas;
	
	public:
	vendedor(char *n, char *sn, char *c, int cd, int fpc, int time, int f, int sal1, int sal2, double vv, int v):funcionario(n,sn,c,cd,fpc,time,f,sal1,sal2)
	{
		valor_vendido = vv;
		vendas = v;
	}

	void printaInfo()
		{
			printf("Nome: %s\n", getNome());
			printf("Sobrenome: %s\n", getSobrenome());
			printf("Categoria: %s\n", getCategoria());
			printf("Codigo: %d\n", getCode());
			printf("CPF: %d\n", getCpf());
			printf("Quantidade de filhos: %d\n", getFilhos());
			printf("Tempo na empresa (meses): %d\n", getTempo());
			printf("Salario base: %lf\n", getSalBase());
			printf("Salario final: %lf\n", getSalFinal());
			printf("Valor total das vendas: %lf\n", valor_vendido);
			printf("Numero de vendas: %d\n", vendas);
		}

	double calculaSalario()
	{
		double bonus=0;
		
		if(vendas >= 300)
		{
			bonus+=0.20 ;
		}
		else
		{
			bonus+=0.15;
		}
		setSalFinal(getSalBase()+(valor_vendido*bonus));
		return (getSalBase()+(valor_vendido*bonus));
	}
	
	void efetuaVenda(double valordavenda)
	{
		valor_vendido+=valordavenda;
		vendas++;
	}

};

class gerente:public funcionario
{
	private:
		int funcionarios;
	
	public:
	gerente(char *n, char *sn, char *c, int cd, int fpc, int time, int f, int sal1, int sal2, int func):funcionario(n,sn,c,cd,fpc,time,f,sal1,sal2)
	{
		funcionarios = func;
	}

	void printaInfo()
		{
			printf("Nome: %s\n", getNome());
			printf("Sobrenome: %s\n", getSobrenome());
			printf("Categoria: %s\n", getCategoria());
			printf("Codigo: %d\n", getCode());
			printf("CPF: %d\n", getCpf());
			printf("Quantidade de filhos: %d\n", getFilhos());
			printf("Tempo na empresa (meses): %d\n", getTempo());
			printf("Salario base: %lf\n", getSalBase());
			printf("Salario final: %lf\n", getSalFinal());
			printf("Numero de funcionarios gerenciados: %d\n", funcionarios);
		}

	double calculaSalario()
	{
		double bonus=1;
		
		bonus+=0.03*funcionarios;

		setSalFinal(getSalBase()*bonus);
		return getSalBase()*bonus;
	}

};


motorista compra(motorista x, int min)
{
	x.horas+=min/60;
	x.corridas++;
	
	return x;
}

int main()
{
	motorista a("Joao", "da Silva", "motorista", 1, 191, 5, 2, 1200, 1200, 'D', 120, 230);
	a = compra(a, 80);
	a.calculaSalario();
	a.printaInfo();
	a.ferias(a);
	
	printf("\n");
	
	R_estoque b("Jorge", "da Silva", "R. de estoque", 2, 192, 4, 3, 1100, 1100, 210, 150);
	b.cargaDescarga(3);
	b.calculaSalario();
	b.printaInfo();
	b.ferias(b);
	
	printf("\n");
	
	vendedor c("Marcos", "da Silva", "vendedor", 3, 193, 15, 0, 2000, 2000, 1500, 100);
	c.efetuaVenda(50);
	c.calculaSalario();
	c.printaInfo();
	c.ferias(c);
	
	printf("\n");
	
	gerente d("Jailson", "Mendes", "gerente", 4, 190, 33, 2, 5000, 5000, 26);
	d.calculaSalario();
	d.printaInfo();
	d.ferias(d);
	
	printf("\n");
	return 0;
}
