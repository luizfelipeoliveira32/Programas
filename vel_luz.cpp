#include <fstream>

using namespace std;

int vel_luz(){
	
	double x[4], y[4];
	double ex = 0.0005;
	int n = 0;
	
	ifstream ler("dados2.txt");
	
	if(ler.is_open()){
		
		cout << "Abriu";
	
	}else{
		
		cout << "Houve algum erro";
		
	}
	
	while (n<4){
		
		ler >> x[n] >> y[n];
		
		n++;
	}
	
	TGraph *g = new TGraph(4,x,y);
	
	g->SetMarkerStyle(21);
	//g->SetMarkerColor(3);
	g->GetXaxis()->SetTitle("t(s)");
	g->GetYaxis()->SetTitle("s(m)");
	g->SetTitle("Distancia x Tempo");
	g->Fit("pol1");
	g->SetLineColor(3);
	g->GetFunction("pol1")->SetLineColor(g->GetLineColor());
	g->Draw("AP");
	
	return 0;
}