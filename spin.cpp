#include <fstream>
#include <math.h>
#include <iostream>

using namespace std;

void spin(){
	double i[12], f[12], er_i[12], er_f[12];
	double r = 6.25*pow(10,-2); //m raio das bobinas
	double er_r = 0.005*pow(10,-2);
	double mi = 9.274009417125356*pow(10,-24); //Am² ou 5.788*pow(10,−9); //eV/G
	double mu = 1.256*pow(10,−6); //TmA^-¹ ou H/m é a permeabilidade do vácuo
	double h = 6.626069*pow(10,-34); //Js
	double j = 0.7155417527999327;
	int N=320; //nº de espiras
	int k=0;
	ifstream ler;
	ofstream arquivo("resultados_spin.txt", ofstream::app);
	ler.open("dados_spin.txt");
	if (!ler.is_open()){
		cout<<"Nao Abriu"<<endl;
	}else{
		cout<<"Abriu"<<endl;
	}
	
	B = (mu*mi*j*N)/(2*r);
	while (!ler.eof()){
		ler i[k] >> f[k];
		
		//f[k] = B*i[k];
		
		//cálculo dos erros:
		er_i[k] = 0.5*((0.02*i[k]) + 0.05);
		//er_f[k] =;
		n++;
		arquivo << "Erro de i: " << er_i[k] << '\n'; // << "Erro de f: " << er_f[k] << '\n';
	}
	ler.close();
	arquivo.close();
	
	t=new TGraph(11, i, f);
	t->Draw("A*");
	t->SetMarkerStyle(21);
	t->SetMarkerColor(4);
	t->GetXaxis()->SetTitle("Corrente (A) ");
	t->GetYaxis()->SetTitle("#ni (MHz) ");
	
}