#include <stdio.h>
#include <TFile.h>
#include <TLorentzVector.h>
#include <iostream>
#include<fstream>
#include<string>
#include <cstring>
#include <THStack.h>
#include <TMath.h>
using namespace std;
using namespace RooFit;

void analise(){
   // Declaration of leaf types
   Double_t        N_PV;
   Double_t        N_mu;
   Double_t        N_lambda;
   Double_t        p_mu1;
   Double_t        p_mu2;
   Double_t        pT_mu1;
   Double_t        pT_mu2;
   Double_t        eta_mu1;
   Double_t        eta_mu2;
   Double_t        phi_mu1;
   Double_t        phi_mu2;
   Double_t        normalizedChi2_mu1;
   Double_t        normalizedChi2_mu2;
   Double_t        chi2_mu1;
   Double_t        chi2_mu2;
   Double_t        ndof_mu1;
   Double_t        ndof_mu2;
   Double_t        X_mumu;
   Double_t        Y_mumu;
   Double_t        Z_mumu;
   Double_t        PsiMass;
   Double_t        p_mumu;
   Double_t        pT_mumu;
   Double_t        eta_mumu;
   Double_t        phi_mumu;
   Double_t        Lxy_mumu;
   Double_t        rapidity_mumu;
   Double_t        normalizedChi2_mumu;
   Double_t        chi2_mumu;
   Double_t        ndof_mumu;
   Double_t        X_Lambda0;
   Double_t        Y_Lambda0;
   Double_t        Z_Lambda0;
   Double_t        Lambda0Mass;
   Double_t        p_Lambda0;
   Double_t        pT_Lambda0;
   Double_t        eta_Lambda0;
   Double_t        phi_Lambda0;
   Double_t        rapidity_Lambda0;
   Double_t        normalizedChi2_Lambda0;
   Double_t        chi2_Lambda0;
   Double_t        ndof_Lambda0;
   Double_t        LambdaBMass;
   Double_t        p_LambdaB;
   Double_t        pT_LambdaB;
   Double_t        eta_LambdaB;
   Double_t        phi_LambdaB;
   Double_t        rapidity_LambdaB;
   Double_t        angle;
   Double_t        normalizedChi2_pv;
   Double_t        chi2_pv;
   Double_t        ndof_pv;
   Double_t        NEvent;
   Double_t        NRun;

   // List of branches
   TBranch        *b_N_PV;   //!
   TBranch        *b_N_mu;   //!
   TBranch        *b_N_lambda;   //!
   TBranch        *b_p_mu1;   //!
   TBranch        *b_p_mu2;   //!
   TBranch        *b_pT_mu1;   //!
   TBranch        *b_pT_mu2;   //!
   TBranch        *b_eta_mu1;   //!
   TBranch        *b_eta_mu2;   //!
   TBranch        *b_phi_mu1;   //!
   TBranch        *b_phi_mu2;   //!
   TBranch        *b_normalizedChi2_mu1;   //!
   TBranch        *b_normalizedChi2_mu2;   //!
   TBranch        *b_chi2_mu1;   //!
   TBranch        *b_chi2_mu2;   //!
   TBranch        *b_ndof_mu1;   //!
   TBranch        *b_ndof_mu2;   //!
   TBranch        *b_X_mumu;   //!
   TBranch        *b_Y_mumu;   //!
   TBranch        *b_Z_mumu;   //!
   TBranch        *b_PsiMass;   //!
   TBranch        *b_p_mumu;   //!
   TBranch        *b_pT_mumu;   //!
   TBranch        *b_eta_mumu;   //!
   TBranch        *b_phi_mumu;   //!
   TBranch        *b_Lxy_mumu;   //!
   TBranch        *b_rapidity_mumu;   //!
   TBranch        *b_normalizedChi2_mumu;   //!
   TBranch        *b_chi2_mumu;   //!
   TBranch        *b_ndof_mumu;   //!
   TBranch        *b_X_Lambda0;   //!
   TBranch        *b_Y_Lambda0;   //!
   TBranch        *b_Z_Lambda0;   //!
   TBranch        *b_Lambda0Mass;   //!
   TBranch        *b_p_Lambda0;   //!
   TBranch        *b_pT_Lambda0;   //!
   TBranch        *b_eta_Lambda0;   //!
   TBranch        *b_phi_Lambda0;   //!
   TBranch        *b_rapidity_Lambda0;   //!
   TBranch        *b_normalizedChi2_Lambda0;   //!
   TBranch        *b_chi2_Lambda0;   //!
   TBranch        *b_ndof_Lambda0;   //!
   TBranch        *b_LambdaBMass;   //!
   TBranch        *b_p_LambdaB;   //!
   TBranch        *b_pT_LambdaB;   //!
   TBranch        *b_eta_LambdaB;   //!
   TBranch        *b_phi_LambdaB;   //!
   TBranch        *b_rapidity_LambdaB;   //!
   TBranch        *b_angle;   //!
   TBranch        *b_normalizedChi2_pv;   //!
   TBranch        *b_chi2_pv;   //!
   TBranch        *b_ndof_pv;   //!
   TBranch        *b_NEvent;   //!
   TBranch        *b_NRun;   //!
   
   ifstream ler;
   vector<string> arquivo;
   string aux;
   int n=0;
   
   bool cut_kv; //cut in kinematics variables
   bool cut_tv; //cut
   bool cut_PsiMass;
   bool cut_L0Mass;
   bool cut_LBMass;
   bool cut_Psi2SMass;
   bool cut_JPsi;
   bool cut_L0;
   bool cut_eta;
   bool cut_normchi2;
   
//   ler.open("MC_JPsi.txt");
   ler.open("dados.txt");
   //ler.open("MC_Mumu.txt");
   //ler.open("JPsi_JPsiPiPiPPi.txt");
//   ler.open("datasets.txt");
   
   if (!ler.is_open()){
	   cout << "Nao foi possivel abrir";
    }else{
		while (ler >> aux){
			arquivo.push_back(aux);
			cout << arquivo[n] << endl;
			++n;
		}
	}

	ler.close();

//Histogramas:
//Massas antes dos cortes:
	TH1F *histo_JPsiMass = new TH1F("histo_JPsiMass", "", 140., 2.7, 4.1);
	histo_JPsiMass->GetXaxis()->SetTitle("m_{J/#psi} (GeV/c^{2})");
	histo_JPsiMass->GetYaxis()->SetTitle("Eventos");
	histo_JPsiMass->SetMarkerStyle(21);
	histo_JPsiMass->SetMarkerColor(9);

	TH1F *histo_L0Mass = new TH1F("histo_L0Mass", "", 60., 1.09, 1.15);
	histo_L0Mass->GetXaxis()->SetTitle("m_{#Lambda^{0}} (GeV/c^{2})");
	histo_L0Mass->GetYaxis()->SetTitle("Eventos");
	histo_L0Mass->SetMarkerStyle(21);
	histo_L0Mass->SetMarkerColor(30);

	TH1F *histo_LambdaBMass = new TH1F("histo_LambdaBMass" , "" , 80., 5.2, 6.0);
	histo_LambdaBMass->GetXaxis()->SetTitle("m_{#Lambda_{b}} (GeV/c^{2})");
	histo_LambdaBMass->GetYaxis()->SetTitle("Eventos");
	histo_LambdaBMass->SetMarkerStyle(21);
	histo_LambdaBMass->SetFillColor(30);

	TH1F *histo_MumuMass = new TH1F("histo_MumuMass", "", 140., 2.7, 4.1);
	histo_MumuMass->GetXaxis()->SetTitle("m_{#mu^{+}#mu^{-}} (GeV/c^{2})");
	histo_MumuMass->GetYaxis()->SetTitle("Eventos");
	histo_MumuMass->SetMarkerStyle(21);
	histo_MumuMass->SetMarkerColor(9);

//Massa depois dos cortes
	TH1F *h_PsiMass = new TH1F("PsiMass", "", 140., 2.7, 4.1); 
	h_PsiMass->GetXaxis()->SetTitle("m_{J/#psi} (GeV/c^{2})");
	h_PsiMass->GetYaxis()->SetTitle("Eventos");
	h_PsiMass->SetMarkerStyle(21);
	h_PsiMass->SetMarkerColor(9);

	TH1F *h_PsiMass1 = new TH1F("PsiMass1", "", 40., 2.9, 3.3);
	h_PsiMass1->GetXaxis()->SetTitle("m_{J/#psi} (GeV/c^{2})");
	h_PsiMass1->GetYaxis()->SetTitle("Eventos");
	h_PsiMass1->SetMarkerStyle(21);
	h_PsiMass1->SetMarkerColor(9);

	TH1F *h_PsiMass2 = new TH1F("PsiMass2", "", 40., 3.5, 3.9);
	h_PsiMass2->GetXaxis()->SetTitle("m_{#psi(2S)} (GeV/c^{2})");
	h_PsiMass2->GetYaxis()->SetTitle("Eventos");
	h_PsiMass2->SetMarkerStyle(21);
	h_PsiMass2->SetMarkerColor(9);
	
	TH1F *h_Lambda0Mass = new TH1F("Lambda0Mass", "", 60., 1.09, 1.15); 
	h_Lambda0Mass->GetXaxis()->SetTitle("m_{#Lambda^{0}} (GeV/c^{2})");
	h_Lambda0Mass->GetYaxis()->SetTitle("Eventos");
	h_Lambda0Mass->SetMarkerStyle(21);
	h_Lambda0Mass->SetMarkerColor(30);

	TH1F *h_LambdaBMass = new TH1F("h_LambdaBMass" , "" , 80., 5.2, 6.0);
	h_LambdaBMass->GetXaxis()->SetTitle("m_{#Lambda_{b}} (GeV/c^{2})");
	h_LambdaBMass->GetYaxis()->SetTitle("Eventos");
	h_LambdaBMass->SetMarkerStyle(21);
	h_LambdaBMass->SetMarkerColor(3);

	TH1F *h_LambdaBMass2 = new TH1F("h_LambdaBMass2" , "" , 80., 5.2, 6.0);
	h_LambdaBMass2->GetXaxis()->SetTitle("m_{#Lambda_{b}} (GeV/c^{2})");
	h_LambdaBMass2->GetYaxis()->SetTitle("Eventos");
	h_LambdaBMass2->SetMarkerStyle(21);
	h_LambdaBMass2->SetMarkerColor(45);

//Variaveis de cortes:
	TH1F *h_Lxy = new TH1F("Lxy", "Significancia" , 20., 20., 500.);
	h_Lxy->GetXaxis()->SetTitle("S_{xy}");
	h_Lxy->GetYaxis()->SetTitle("Eventos");
	h_Lxy->SetMarkerStyle(21);
	h_Lxy->SetFillColor(kRed);

	TH1F *h_cos = new TH1F("cos", "cos(#theta)", 100., -1., 1.);
	h_cos->SetMarkerStyle(21);
	h_cos->SetFillColor(kMagenta);
	h_cos->GetXaxis()->SetTitle("cos(#theta)");
	h_cos->GetYaxis()->SetTitle("Eventos");
	
	TH1F *h_PsiPt = new TH1F("h_PsiPt", "p_{T} do J/#psi", 50., 0., 50.);
	h_PsiPt->GetXaxis()->SetTitle("p^{T}_{J/#psi} (GeV)");
	h_PsiPt->GetYaxis()->SetTitle("Eventos");
	h_PsiPt->SetFillColor(kYellow);
	h_PsiPt->SetMarkerStyle(21);
	
	TH1F *h_PsiPtMC = new TH1F("h_PsiPtMC", "", 50., 0., 50.);
	h_PsiPtMC->SetFillColor(kRed);

	TH1F *h_mu1Pt = new TH1F("h_mu1Pt", "p_{T} do #mu", 50., 0., 50.);
	h_mu1Pt->GetXaxis()->SetTitle("p^{T}_{#mu} (GeV)");
	h_mu1Pt->GetYaxis()->SetTitle("Eventos");
	h_mu1Pt->SetFillColor(kGreen);
	h_mu1Pt->SetMarkerStyle(21);
	
	TH1F *h_Lambda0Pt = new TH1F("h_Lambda0Pt", "p_{T} do #Lambda^{0}", 25., 0., 25.);
	h_Lambda0Pt->GetXaxis()->SetTitle("p^{T}_{#Lambda^{0}} (GeV)");
	h_Lambda0Pt->GetYaxis()->SetTitle("Eventos");
	h_Lambda0Pt->SetMarkerStyle(21);
	h_Lambda0Pt->SetFillColor(kBlue);
	
	TH1F *h_LambdaBPt = new TH1F("h_LambdaBPt", "p_{T} do #Lambda_{b}", 30., 0., 30.);
	h_LambdaBPt->GetXaxis()->SetTitle("p^{T}_{#Lambda_{b}} (GeV)");
	h_LambdaBPt->GetYaxis()->SetTitle("Eventos");
	h_LambdaBPt->SetMarkerStyle(21);
	h_LambdaBPt->SetFillColor(kOrange);

	TH1F *h_NormChi2Mumu = new TH1F("h_NormChi2Mumu", "", 100., 0., 10.);
	h_NormChi2Mumu->GetXaxis()->SetTitle("Normalized Chi2 de J/#psi");
	h_NormChi2Mumu->GetYaxis()->SetTitle("Eventos");
	h_NormChi2Mumu->SetMarkerStyle(21);
	h_NormChi2Mumu->SetMarkerColor(kMagenta);
	
	TH1F *h_NormChi2Lambda = new TH1F("h_NormChi2Lambda", "", 70., 0., 7.);
	h_NormChi2Lambda->GetXaxis()->SetTitle("Normalized Chi2 de #Lambda^{0}");
	h_NormChi2Lambda->GetYaxis()->SetTitle("Eventos");
	h_NormChi2Lambda->SetMarkerStyle(21);
	h_NormChi2Lambda->SetMarkerColor(kMagenta);
	
	TH1F *h_NormChi2PV = new TH1F("h_NormChi2PV", "", 100., 0., 10.);
	h_NormChi2PV->GetXaxis()->SetTitle("Normalized Chi2 de PV");
	h_NormChi2PV->GetYaxis()->SetTitle("Eventos");
	h_NormChi2PV->SetMarkerStyle(21);
	h_NormChi2PV->SetMarkerColor(kMagenta);
	
	TH1F *h_NormChi2Muon = new TH1F("h_NormChi2Muon", "", 40., 0., 4.);
	h_NormChi2Muon->GetXaxis()->SetTitle("Normalized Chi2 de #mu");
	h_NormChi2Muon->GetYaxis()->SetTitle("Eventos");
	h_NormChi2Muon->SetMarkerStyle(21);
	h_NormChi2Muon->SetMarkerColor(kMagenta);
	
	TH1F *Run2011 = new TH1F("Run2011", "m_{#Lambda_{b}} com dados de 2011", 150., 4.5, 6.0);
	Run2011->GetXaxis()->SetTitle("m_{#Lambda_{b}} (GeV/c^{2})");
	Run2011->GetYaxis()->SetTitle("Eventos");
	Run2011->SetFillColor(kRed);
	
	TH1F *Run2012 = new TH1F("Run2012", "m_{#Lambda_{b}} com dados de 2012", 150., 4.5, 6.0);
	Run2012->GetXaxis()->SetTitle("m_{#Lambda_{b}} (GeV/c^{2})");
	Run2012->GetYaxis()->SetTitle("Eventos");
	Run2012->SetFillColor(kBlue);
	
	TH1F *h_PsiRapidity = new TH1F("h_PsiRapidity", "", 60., -3., 3.);

	TH1F *h_LambdaBRapidity = new TH1F("h_LambdaBRapidity", "", 60., -3.0, 3.0);	

	TH1F *h_PsiP = new TH1F("h_PsiP", "", 50., 0., 50.);
	h_PsiP->GetXaxis()->SetTitle("p_{J/#psi} (GeV)");
	h_PsiP->GetYaxis()->SetTitle("Eventos");
	h_PsiP->SetFillColor(kYellow);
	h_PsiP->SetMarkerStyle(21);

	TH1F *h_mu1P = new TH1F("h_mu1P", "", 50., 0., 50.);
	h_mu1P->GetXaxis()->SetTitle("p_{#mu} (GeV)");
	h_mu1P->GetYaxis()->SetTitle("Eventos");
	h_mu1P->SetFillColor(kGreen);
	h_mu1P->SetMarkerStyle(21);
	
	TH1F *h_Lambda0P = new TH1F("h_Lambda0P", "", 12., 0., 12.);
	h_Lambda0P->GetXaxis()->SetTitle("p_{#Lambda^{0}} (GeV)");
	h_Lambda0P->GetYaxis()->SetTitle("Eventos");
	h_Lambda0P->SetMarkerStyle(21);
	h_Lambda0P->SetFillColor(kBlue);
	
	TH1F *h_LambdaBP = new TH1F("h_LambdaBP", "", 20., 0., 20.);
	h_LambdaBP->GetXaxis()->SetTitle("p_{#Lambda_{b}} (GeV)");
	h_LambdaBP->GetYaxis()->SetTitle("Eventos");
	h_LambdaBP->SetMarkerStyle(21);
	h_LambdaBP->SetFillColor(kOrange);
	
	for (int m=0; m<arquivo.size(); m++){
		TFile *f = new TFile(arquivo[m].c_str(), "read");
		TTree *tree = (TTree*)f->Get("demo/T");
			
		if (!     tree){ return;
		}else{
		cout << "abrindo o arquivo " << arquivo[m].c_str() << endl;
		}
		
		tree->SetMakeClass(1);
		tree->SetBranchAddress("N_PV", &N_PV, &b_N_PV);
        tree->SetBranchAddress("N_mu", &N_mu, &b_N_mu);
        tree->SetBranchAddress("N_lambda", &N_lambda, &b_N_lambda);
        tree->SetBranchAddress("p_mu1", &p_mu1, &b_p_mu1);
        tree->SetBranchAddress("p_mu2", &p_mu2, &b_p_mu2);
        tree->SetBranchAddress("pT_mu1", &pT_mu1, &b_pT_mu1);
        tree->SetBranchAddress("pT_mu2", &pT_mu2, &b_pT_mu2);
        tree->SetBranchAddress("eta_mu1", &eta_mu1, &b_eta_mu1);
        tree->SetBranchAddress("eta_mu2", &eta_mu2, &b_eta_mu2);
        tree->SetBranchAddress("phi_mu1", &phi_mu1, &b_phi_mu1);
        tree->SetBranchAddress("phi_mu2", &phi_mu2, &b_phi_mu2);
        tree->SetBranchAddress("normalizedChi2_mu1", &normalizedChi2_mu1, &b_normalizedChi2_mu1);
        tree->SetBranchAddress("normalizedChi2_mu2", &normalizedChi2_mu2, &b_normalizedChi2_mu2);
        tree->SetBranchAddress("chi2_mu1", &chi2_mu1, &b_chi2_mu1);
        tree->SetBranchAddress("chi2_mu2", &chi2_mu2, &b_chi2_mu2);
        tree->SetBranchAddress("ndof_mu1", &ndof_mu1, &b_ndof_mu1);
        tree->SetBranchAddress("ndof_mu2", &ndof_mu2, &b_ndof_mu2);
        tree->SetBranchAddress("X_mumu", &X_mumu, &b_X_mumu);
        tree->SetBranchAddress("Y_mumu", &Y_mumu, &b_Y_mumu);
        tree->SetBranchAddress("Z_mumu", &Z_mumu, &b_Z_mumu);
        tree->SetBranchAddress("PsiMass", &PsiMass, &b_PsiMass);
        tree->SetBranchAddress("p_mumu", &p_mumu, &b_p_mumu);
        tree->SetBranchAddress("pT_mumu", &pT_mumu, &b_pT_mumu);
        tree->SetBranchAddress("eta_mumu", &eta_mumu, &b_eta_mumu);
        tree->SetBranchAddress("phi_mumu", &phi_mumu, &b_phi_mumu);
        tree->SetBranchAddress("Lxy_mumu", &Lxy_mumu, &b_Lxy_mumu);
        tree->SetBranchAddress("rapidity_mumu", &rapidity_mumu, &b_rapidity_mumu);
        tree->SetBranchAddress("normalizedChi2_mumu", &normalizedChi2_mumu, &b_normalizedChi2_mumu);
        tree->SetBranchAddress("chi2_mumu", &chi2_mumu, &b_chi2_mumu);
        tree->SetBranchAddress("ndof_mumu", &ndof_mumu, &b_ndof_mumu);
        tree->SetBranchAddress("X_Lambda0", &X_Lambda0, &b_X_Lambda0);
        tree->SetBranchAddress("Y_Lambda0", &Y_Lambda0, &b_Y_Lambda0);
        tree->SetBranchAddress("Z_Lambda0", &Z_Lambda0, &b_Z_Lambda0);
        tree->SetBranchAddress("Lambda0Mass", &Lambda0Mass, &b_Lambda0Mass);
        tree->SetBranchAddress("p_Lambda0", &p_Lambda0, &b_p_Lambda0);
        tree->SetBranchAddress("pT_Lambda0", &pT_Lambda0, &b_pT_Lambda0);
        tree->SetBranchAddress("eta_Lambda0", &eta_Lambda0, &b_eta_Lambda0);
        tree->SetBranchAddress("phi_Lambda0", &phi_Lambda0, &b_phi_Lambda0);
        tree->SetBranchAddress("rapidity_Lambda0", &rapidity_Lambda0, &b_rapidity_Lambda0);
        tree->SetBranchAddress("normalizedChi2_Lambda0", &normalizedChi2_Lambda0, &b_normalizedChi2_Lambda0);
        tree->SetBranchAddress("chi2_Lambda0", &chi2_Lambda0, &b_chi2_Lambda0);
        tree->SetBranchAddress("ndof_Lambda0", &ndof_Lambda0, &b_ndof_Lambda0);
        tree->SetBranchAddress("LambdaBMass", &LambdaBMass, &b_LambdaBMass);
        tree->SetBranchAddress("p_LambdaB", &p_LambdaB, &b_p_LambdaB);
        tree->SetBranchAddress("pT_LambdaB", &pT_LambdaB, &b_pT_LambdaB);
        tree->SetBranchAddress("eta_LambdaB", &eta_LambdaB, &b_eta_LambdaB);
        tree->SetBranchAddress("phi_LambdaB", &phi_LambdaB, &b_phi_LambdaB);
        tree->SetBranchAddress("rapidity_LambdaB", &rapidity_LambdaB, &b_rapidity_LambdaB);
        tree->SetBranchAddress("angle", &angle, &b_angle);
        tree->SetBranchAddress("normalizedChi2_pv", &normalizedChi2_pv, &b_normalizedChi2_pv);
        tree->SetBranchAddress("chi2_pv", &chi2_pv, &b_chi2_pv);
        tree->SetBranchAddress("ndof_pv", &ndof_pv, &b_ndof_pv);
        tree->SetBranchAddress("NEvent", &NEvent, &b_NEvent);
        tree->SetBranchAddress("NRun", &NRun, &b_NRun);
		
		Int_t nentries= (Int_t)tree->GetEntries();
		
		for (Int_t i = 0; i<nentries; i++) {
			tree->GetEntry(i);

			cut_kv = false;
			cut_tv = false;
			cut_PsiMass = false;
			cut_L0Mass = false;
			cut_LBMass = false;
			cut_Psi2SMass = false;
			cut_JPsi = false;
			cut_L0 = false;
			cut_eta = false;
			cut_normchi2 = false;

			double mu1_eta = abs(eta_mu1);
			double mu2_eta = abs(eta_mu2);
			double rap_LambdaB = abs(rapidity_LambdaB);

			if (Lambda0Mass > 1.09 && Lambda0Mass < 1.15) histo_L0Mass->Fill(Lambda0Mass);
			if (PsiMass > 2.9 && PsiMass < 3.3) h_PsiMass1->Fill(PsiMass);
			if (PsiMass > 3.5 && PsiMass < 3.9) h_PsiMass2->Fill(PsiMass);
			histo_JPsiMass->Fill(PsiMass);
			histo_LambdaBMass->Fill(LambdaBMass);
			histo_MumuMass->Fill(PsiMass);
//Testes de cortes:
			h_PsiRapidity->Fill(rapidity_mumu);
			h_LambdaBRapidity->Fill(rapidity_LambdaB);
			h_Lxy->Fill(Lxy_mumu);
			h_cos->Fill(cos(angle));
			h_Lambda0Pt->Fill(pT_Lambda0);
			h_LambdaBPt->Fill(pT_LambdaB);
			h_PsiPt->Fill(pT_mumu);
			h_mu1Pt->Fill(pT_mu1);
			h_Lambda0P->Fill(p_Lambda0);
			h_LambdaBP->Fill(p_LambdaB);
			h_PsiP->Fill(p_mumu);
			h_mu1P->Fill(p_mu1);
			if (NRun > 185000) Run2012->Fill(LambdaBMass);
			if (NRun < 185000) Run2011->Fill(LambdaBMass);
	
			//p_mumu > 13.0 && p_mu1 > 6.0 && p_mu2 > 6.0 && p_Lambda0 > 2.0 && p_LambdaB > 14.0 && pT_mu1 > 5. && pT_mu2 > 5.
//Cortes para a massa do Lambda B:
			if (mu1_eta < 2.4 && mu2_eta < 2.4) cut_eta = true;
//			if (pT_mu1 > 2.0 && pT_mu2 > 2.0 && pT_Lambda0 > 1.0 && pT_mumu > 6.9 && pT_LambdaB > 10.) cut_kv = true; // 
			if (pT_mu1 > 6.5 && pT_mu2 > 6.5  && pT_Lambda0 > 1.0  && pT_mumu > 10 && pT_LambdaB > 10.) cut_kv = true; 

			if (Lxy_mumu > 20.0 && cos(angle) > 0.999) cut_tv = true; //
//			if (Lxy_mumu > 5.0 && cos(angle) > 0.998) cut_tv = true;
			if (PsiMass > 3.023 && PsiMass < 3.159) cut_PsiMass = true;
			if (Lambda0Mass > 1.11 && Lambda0Mass < 1.12) cut_L0Mass = true;
			if (PsiMass > 3.61518 && PsiMass < 3.74682) cut_Psi2SMass = true;
			if (LambdaBMass > 5.2 && LambdaBMass < 6.0) cut_LBMass = true;
			if (cut_kv && cut_tv && cut_LBMass) {
				//if (PsiMass > 2.7 && PsiMass < 3.5) h_PsiMass1->Fill(PsiMass);
				//if (PsiMass > 3.5 && PsiMass < 4.1) h_PsiMass2->Fill(PsiMass);
				if (Lambda0Mass > 1.09 && Lambda0Mass < 1.15) h_Lambda0Mass->Fill(Lambda0Mass);
				h_PsiMass->Fill(PsiMass);
				//h_PsiMass1->Fill(PsiMass);
			}
			
			if (cut_kv && cut_tv && cut_PsiMass && cut_L0Mass && cut_LBMass) {
				h_LambdaBMass->Fill(LambdaBMass);
			}
//			if (cut_LBMass) h_LambdaBMass2->Fill(LambdaBMass);
//			if (cut_kv && cut_tv && cut_Psi2SMass && cut_L0Mass && cut_LBMass) h_LambdaBMass2->Fill(LambdaBMass);*/			
		}	
		f->Close();
	}

//Funções para o fit:
	TF1 *lb_fit = new TF1("lb_fit", "(0.01*[0]*exp(-0.5*pow((x-[1])/[2],2))/([2]*sqrt(2*TMath::Pi())))+expo(3)", 5.2, 6.0); 
	lb_fit->SetParLimits(0, 0., 2.e+5);
	lb_fit->SetParLimits(1, 5.54, 5.68);
	lb_fit->SetParLimits(2, 0.01, 0.25);
	lb_fit->SetParName(0, "N^{signal}");
	lb_fit->SetParName(1, "m_{#Lambda_{b}}");
	lb_fit->SetParName(2, "#sigma");
	lb_fit->SetParName(3, "N^{bkg}");
	lb_fit->SetParName(4, "#alpha");

/*	TF1 *jpsi_fit = new TF1("jpsi_fit", "(0.01*[0]*exp(-0.5*pow((x-[1])/[2],2))/([2]*sqrt(2*TMath::Pi())))+(0.01*[3]*exp(-0.5*pow((x-[1])/[4],2))/([4]*sqrt(2*TMath::Pi())))+expo(5)+(0.01*[7]*exp(-0.5*pow((x-[8])/[9],2))/([9]*sqrt(2*TMath::Pi())))", 2.7, 3.9);	
	jpsi_fit->SetParLimits(0, 100., 1.6e+5);
	jpsi_fit->SetParLimits(1, 3.05, 3.15);
	jpsi_fit->SetParLimits(2, 0.02, 0.032);
	jpsi_fit->SetParLimits(3, 100., 2.0e+5);//	jpsi_fit->SetParLimits(3, 0.5, 2.0);
	jpsi_fit->SetParLimits(4, 0.025, 0.1);
	jpsi_fit->SetParName(0, "Constante_Gauss1 (J/#psi)");
	jpsi_fit->SetParName(1, "Media_Gauss (J/#psi)");
	jpsi_fit->SetParName(2, "Sigma_Gauss1 (J/#psi)");
	jpsi_fit->SetParName(3, "Constante_Gauss2 (J/#psi)");
	jpsi_fit->SetParName(4, "Sigma_Gauss2 (J/#psi)");
	jpsi_fit->SetParName(5, "Constante_Expo (J/#psi)");
	jpsi_fit->SetParName(6, "Inclinacao_Expo (J/#psi)");
	jpsi_fit->SetParLimits(7, 20., 1.e+4);
	jpsi_fit->SetParLimits(8, 3.64, 3.74);
	jpsi_fit->SetParLimits(9, 0.02, 0.4);
	jpsi_fit->SetParName(7, "Constante_Gauss (#psi(2S))");
	jpsi_fit->SetParName(8, "Media_Gauss (#psi(2S))");
	jpsi_fit->SetParName(9, "Largura_Gauss (#psi(2S))");
*/
	TF1 *jpsi_fit = new TF1("jpsi_fit", "(0.01*[0]*exp(-0.5*pow((x-[1])/[2],2))/([2]*sqrt(2*TMath::Pi())))+expo(3)+(0.01*[5]*exp(-0.5*pow((x-[6])/[7],2))/([7]*sqrt(2*TMath::Pi())))", 2.7, 4.1);	
	jpsi_fit->SetParLimits(0, 100., 1.6e+5);
	jpsi_fit->SetParLimits(1, 3.09, 3.10);
	jpsi_fit->SetParLimits(2, 0.02, 0.1);//0.02, 0.032);
	jpsi_fit->SetParLimits(5, 20., 1.e+4);
	jpsi_fit->SetParLimits(6, 3.50, 3.74);
	jpsi_fit->SetParLimits(7, 0.02, 1.);
	jpsi_fit->SetParName(0, "N_{J/#psi}");
	jpsi_fit->SetParName(1, "m_{J/#psi}");
	jpsi_fit->SetParName(2, "#sigma_{J/#psi}");
	jpsi_fit->SetParName(3, "N^{bkg}");
	jpsi_fit->SetParName(4, "#alpha");
	jpsi_fit->SetParName(5, "N_{#psi(2S)}");
	jpsi_fit->SetParName(6, "m_{#psi(2S)}");
	jpsi_fit->SetParName(7, "#sigma_{#psi(2S)}");
	
	TF1 *l0_fit = new TF1("l0_fit", "0.001*[0]*exp(-0.5*pow(((x-[1])/[2]),2))/([2]*sqrt(2*TMath::Pi()))+0.001*[3]*exp(-0.5*pow(((x-[1])/[4]),2))/([4]*sqrt(2*TMath::Pi()))+[5]*pow((x-1.07784),[6])", 1.09, 1.15);
	l0_fit->SetParLimits(0, 0., 1.e+4);
	l0_fit->SetParLimits(1, 1.112, 1.118);
	l0_fit->SetParLimits(2, 1.e-3, 8.e-3);
	l0_fit->SetParLimits(3, 0., 6.e+4);
	l0_fit->SetParLimits(4, 1.47e-3, 9.31e-2);
	l0_fit->SetParName(0, "N_{1}");
	l0_fit->SetParName(1, "m_{#Lambda^{0}}");
	l0_fit->SetParName(2, "#sigma_{1}");
	l0_fit->SetParName(3, "N_{2}");
	l0_fit->SetParName(4, "#sigma_{2}");
	l0_fit->SetParName(5, "A");
	l0_fit->SetParName(6, "B");

	TF1 *j_psi_fit = new TF1("j_psi_fit", "(0.01*[0]*exp(-0.5*pow((x-[1])/[2],2))/([2]*sqrt(2*TMath::Pi())))+expo(3)", 2.9, 3.3);	
	j_psi_fit->SetParLimits(0, 100., 1.6e+5);
	j_psi_fit->SetParLimits(1, 3.05, 3.15);
	j_psi_fit->SetParLimits(2, 0.02, 0.1);
	j_psi_fit->SetParName(0, "N");
	j_psi_fit->SetParName(1, "Mean");
	j_psi_fit->SetParName(2, "#sigma");
	j_psi_fit->SetParName(3, "N_Expo");
	j_psi_fit->SetParName(4, "#alpha_Expo");

/*	TF1 *j_psi_fit = new TF1("j_psi_fit", "(0.01)*([0]*exp(-0.5*pow((x-[1])/[2],2))/([2]*sqrt(2*TMath::Pi())))+expo(3)", 2.7, 3.5);	
	j_psi_fit->SetParLimits(0, 1.e+3, 1.e+5);
	j_psi_fit->SetParLimits(1, 3.093, 3.1);
	j_psi_fit->SetParLimits(2, 0.01, 0.05);
*/
	TF1 *psi2s_fit = new TF1("psi2s_fit", "(0.01*[0]*exp(-0.5*pow((x-[1])/[2],2))/([2]*sqrt(2*TMath::Pi())))+expo(3)", 3.5, 3.9);
	psi2s_fit->SetParLimits(0, 20., 1.e+4);
	psi2s_fit->SetParLimits(1, 3.64, 3.74);
	psi2s_fit->SetParLimits(2, 0.02, 0.4);
	psi2s_fit->SetParName(0, "N");
	psi2s_fit->SetParName(1, "Mean");
	psi2s_fit->SetParName(2, "#sigma");
	psi2s_fit->SetParName(3, "N_Expo");
	psi2s_fit->SetParName(4, "#alpha_Expo");

/*	h_PsiPtMC->Draw("hist");
	h_PsiPt->Draw("e1same");
	
	TLegend *leg = new TLegend(.75, .80,.95, .95);
	leg->AddEntry(h_PsiPtMC, "dados MC");
	leg->AddEntry(h_PsiPt, "dados");
	leg->Draw();*/
	
/*	TCanvas *c = new TCanvas("c", "c", 400, 400);
	c->Divide(1,1);
	
	c->cd(1);
//	h_PsiMass1->Draw("e1");
//	h_PsiMass1->Fit("j_psi_fit", "R");
	h_PsiMass2->Draw("E1");
	h_PsiMass2->Fit("psi2s_fit", "R");*/
/*	cout << "1 - Massa do LambdaB sem cortes" << endl;
	cout << "2 - Massa do LambdaB com cortes"<< endl;	
	cout << "3 - Massa do J/Psi e Psi2S"<< endl;
	cout << "4 - Massa do Lambda0" << endl;
	cout << "5 - Massa do J/Psi" << endl;
	cout << "6 - Massa do Psi2S"<< endl;
//	cout << "7 em diante são variaveis de cortes" << endl;

	int valor;
	printf ("Selecione um histograma de 1 a 6: ");
	scanf("%d", &valor);
	
	switch (valor){
    case 1 :
	h_LambdaBMass->Draw("hist"); 
	break;
    
    case 2 :
	histo_LambdaBMass->Draw("E1");
	histo_LambdaBMass->Fit("lb_fit", "R");
    break;
    
    case 3 :
	h_PsiMass->Draw("E1");
	h_PsiMass->Fit("jpsi_fit", "R");
	break;
    
    case 4 :
	h_Lambda0Mass->Draw("E1");
	h_Lambda0Mass->Fit("l0_fit", "R");
    break;
    
    case 5 :
	h_PsiMass1->Draw("E1");
	h_PsiMass1->Fit("j_psi_fit", "R");
    break;
    
    case 6 :
	h_PsiMass2->Draw("E1");
	h_PsiMass2->Fit("psi2s_fit", "R");
    break;
   	
    default :
    printf ("Valor invalido!\n");
	}
*/

//LbMass sem cortes
/*    TCanvas *c = new TCanvas("c", "c", 800, 600);
	c->Divide(1,1);

	c->cd(1);
	h_LambdaBMass2->Draw("e1");
	h_LambdaBMass2->Fit("lb_fit", "R");*/

//	h_PsiMass1->Draw("e1");
//	h_PsiMass1->Fit("j_psi_fit", "R");
//	h_PsiMass2->Draw("e1");
//	h_PsiMass2->Fit("psi2s_fit", "R");
//	histo_MumuMass->Draw("e1");
//J/Psi e Psi2S Mass sem cortes
/*    TCanvas *c1 = new TCanvas("c1", "c1", 800, 600);
	c1->Divide(1,1);

	c1->cd(1);
	histo_JPsiMass->Draw("E1");
	histo_JPsiMass->Fit("jpsi_fit", "R");

//L0Mass sem cortes
    TCanvas *c2 = new TCanvas("c2", "c2", 800, 600);
	c2->Divide(1,1);
	c2->cd(1);
	histo_L0Mass->Draw("E1");
	histo_L0Mass->Fit("l0_fit", "R");*/

//LbMass diferentes runs
/*	TCanvas *c3 = new TCanvas("c3", "c3", 800, 600);
	c3->Divide(2,1);
	c3->cd(1);
	Run2011->Draw("hist");
	
	c3->cd(2);
	Run2012->Draw("hist");*/
//J/Psi e Psi2S Mass com cortes:
 /*   TCanvas *c4 = new TCanvas("c4", "c4", 800, 600);
	c4->Divide(1,1);

	c4->cd(1);
	h_PsiMass->Draw("E1");
	h_PsiMass->Fit("jpsi_fit", "R");*/


//LBMass com cortes
    TCanvas *c5 = new TCanvas("c5", "c5", 800, 600);
	c5->Divide(1,1);
	c5->cd(1);
	h_Lambda0Mass->Draw("E1");
	h_Lambda0Mass->Fit("l0_fit", "R");

//	histo_LambdaBMass->Draw("E1");
//	histo_LambdaBMass->Fit("lb_fit", "R");

/*    TCanvas *c5 = new TCanvas("c5", "c5", 600, 600);
	c5->Divide(2,3);
	
	c5->cd(1);
	h_mu1Pt->Draw("hist");
	
	c5->cd(2);
	h_Lambda0Pt->Draw("hist");
	
	c5->cd(3);
	h_PsiPt->Draw("hist");
	
	c5->cd(4);
	h_LambdaBPt->Draw("hist");
	
	c5->cd(5);
	h_Lxy->Draw("hist");
	
	c5->cd(6);
	h_cos->Draw("hist");*/
	
	gStyle->SetOptFit(111);  
}