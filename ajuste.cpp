#include <fstream>
#include <math.h>
#include <iostream>

using namespace std;


void ajuste(){
	double x[12], y[12];
	ifstream ler;
	
	ler.open("dados_ze.txt");
	
	if (!ler.is_open()){
		cout<<"Nao Abriu"<<endl;
	}
	else{
		cout<<"Abriu"<<endl;
	}
	
	
	for (int k=0; k<12; k++){
		ler >> x[k] >> y[k];
	}
	ler.close();
	//TGraph *g1 = new TGraph(10, B_mt ,f);
	TGraph *h1 = new TGraph(11, x, y);
	h1->SetMarkerStyle(20);
	h1->SetMarkerColor(4);
	h1->GetYaxis()->SetTitle("f (Hz)");
	h1->GetXaxis()->SetTitle("i (A)");
	h1->Fit("pol1");
	h1->Draw("AP");
	
	double q = 50*0.001;
	double D = 9*0.00001;
	double h = 10, raiz = sqrt(2*3.14), sigma = sqrt(3600*D*2);
	double ex = exp(-100/(pow(sigma,2)));
	double c = (q*ex)/(raiz*sigma);
	
	cout << c << endl;
	
}