#include <fstream>
#include <math.h>
#include <iostream>

using namespace std;


void pendulo(){
	double x, y;
	ifstream ler;
	
	ler.open("flavia.txt");
	
	if (!ler.is_open()){
		cout<<"Nao Abriu"<<endl;
	}
	else{
		cout<<"Abriu"<<endl;
	}
	TNtuple *ntuple = new TNtuple("ntuple","","x:y");
	TCanvas *canvas = new TCanvas("Canvas","",900,600);
	
	
	while(!ler.eof()){
		ler >> x >> y;

		ntuple->Fill(x,y);
	}
	ler.close();

	ntuple->Draw("y:x>>h1","","");
	TH1F *h1 = ((TH1F *)(gDirectory->FindObject("h1")));
	h1->SetMarkerStyle(20);
	h1->SetMarkerColor(4);
	h1->SetXTitle("x");
	h1->SetYTitle("y");
	h1->Fit("pol1", "W");
	h1->Draw();
}