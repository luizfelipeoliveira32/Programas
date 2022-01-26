#include <stdio.h>
#include <TFile.h>
#include <TLorentzVector.h>
#include <iostream>

using namespace std;

	void massa_invariante(){

		TLorentzVector particula_pos, particula_neg, particula;
		TLorentzVector hadB, lepB, hadWq, hadWqb, lepWl, lepWn;
		TLorentzVector met;
		double m;
  
//		TFile *f = new TFile("files/data.root");
		TFile *f = new TFile("files/ttbar.root");
   
		TTree *tree = (TTree*)f->Get("events");
   
   
		Int_t           NMuon;
		Float_t         Muon_Px[5];   //[NMuon]
		Float_t         Muon_Py[5];   //[NMuon]
		Float_t         Muon_Pz[5];   //[NMuon]
		Float_t         Muon_E[5];   //[NMuon]
		Int_t           Muon_Charge[5];   //[NMuon]
		Float_t         Muon_Iso[5];   //[NMuon]
		//Float_t MET_px;
		//Float_t MET_py;
		Float_t MChadronicBottom_px;
		Float_t MChadronicBottom_py;
		Float_t MChadronicBottom_pz;
		Float_t MCleptonicBottom_px;
		Float_t MCleptonicBottom_py;
		Float_t MCleptonicBottom_pz;
		Float_t MChadronicWDecayQuark_px;
		Float_t MChadronicWDecayQuark_py;
		Float_t MChadronicWDecayQuark_pz;
		Float_t MChadronicWDecayQuarkBar_px;
		Float_t MChadronicWDecayQuarkBar_py;
		Float_t MChadronicWDecayQuarkBar_pz;
		Float_t MClepton_px;
		Float_t MClepton_py;
		Float_t MClepton_pz;
		Int_t MCleptonPDGid;
		Float_t MCneutrino_px;
		Float_t MCneutrino_py;
		Float_t MCneutrino_pz;
		Bool_t triggerIsoMu24;
		Float_t EventWeight;

		// List of branches
		TBranch        *b_NMuon;   //!
		TBranch        *b_Muon_Px;   //!
		TBranch        *b_Muon_Py;   //!
		TBranch        *b_Muon_Pz;   //!
		TBranch        *b_Muon_E;   //!
		TBranch        *b_Muon_Charge;   //!
		TBranch        *b_Muon_Iso;   //!
		TBranch *b_MChadronicBottom_px; //!
		TBranch *b_MChadronicBottom_py; //!
		TBranch *b_MChadronicBottom_pz; //!
		TBranch *b_MCleptonicBottom_px; //!
		TBranch *b_MCleptonicBottom_py; //!
		TBranch *b_MCleptonicBottom_pz; //!
		TBranch *b_MChadronicWDecayQuark_px; //!
		TBranch *b_MChadronicWDecayQuark_py; //!
		TBranch *b_MChadronicWDecayQuark_pz; //!
		TBranch *b_MChadronicWDecayQuarkBar_px; //!
		TBranch *b_MChadronicWDecayQuarkBar_py; //!
		TBranch *b_MChadronicWDecayQuarkBar_pz; //!
		TBranch *b_MClepton_px; //!
		TBranch *b_MClepton_py; //!
		TBranch *b_MClepton_pz; //!
		TBranch *b_MCleptonPDGid; //!
		TBranch *b_MCneutrino_px; //!
		TBranch *b_MCneutrino_py; //!
		TBranch *b_MCneutrino_pz; //!
		TBranch *b_EventWeight; //!
		TBranch *b_triggerIsoMu24; //!
		
		tree->SetBranchAddress("NMuon", &NMuon);
		tree->SetBranchAddress("Muon_Px", &Muon_Px);
		tree->SetBranchAddress("Muon_Py", &Muon_Py);
		tree->SetBranchAddress("Muon_Pz", &Muon_Pz);
		tree->SetBranchAddress("Muon_E", &Muon_E);
		tree->SetBranchAddress("Muon_Charge", &Muon_Charge);
		tree->SetBranchAddress("Muon_Iso", &Muon_Iso);
		tree->SetBranchAddress("triggerIsoMu24", &triggerIsoMu24, &b_triggerIsoMu24);
		tree->SetBranchAddress("EventWeight", &EventWeight, &b_EventWeight);
	//	tree->SetBranchAddress("MET_px", &MET_px, &b_MET_px);
	//	tree->SetBranchAddress("MET_py", &MET_py, &b_MET_py);
		tree->SetBranchAddress("MChadronicBottom_px", &MChadronicBottom_px, &b_MChadronicBottom_px);
		tree->SetBranchAddress("MChadronicBottom_py", &MChadronicBottom_py, &b_MChadronicBottom_py);
		tree->SetBranchAddress("MChadronicBottom_pz", &MChadronicBottom_pz, &b_MChadronicBottom_pz);
		tree->SetBranchAddress("MCleptonicBottom_px", &MCleptonicBottom_px, &b_MCleptonicBottom_px);
		tree->SetBranchAddress("MCleptonicBottom_py", &MCleptonicBottom_py, &b_MCleptonicBottom_py);
		tree->SetBranchAddress("MCleptonicBottom_pz", &MCleptonicBottom_pz, &b_MCleptonicBottom_pz);
		tree->SetBranchAddress("MChadronicWDecayQuark_px", &MChadronicWDecayQuark_px, &b_MChadronicWDecayQuark_px);
		tree->SetBranchAddress("MChadronicWDecayQuark_py", &MChadronicWDecayQuark_py, &b_MChadronicWDecayQuark_py);
		tree->SetBranchAddress("MChadronicWDecayQuark_pz", &MChadronicWDecayQuark_pz, &b_MChadronicWDecayQuark_pz);
		tree->SetBranchAddress("MChadronicWDecayQuarkBar_px", &MChadronicWDecayQuarkBar_px, &b_MChadronicWDecayQuarkBar_px);
		tree->SetBranchAddress("MChadronicWDecayQuarkBar_py", &MChadronicWDecayQuarkBar_py, &b_MChadronicWDecayQuarkBar_py);
		tree->SetBranchAddress("MChadronicWDecayQuarkBar_pz", &MChadronicWDecayQuarkBar_pz, &b_MChadronicWDecayQuarkBar_pz);
		tree->SetBranchAddress("MClepton_px", &MClepton_px, &b_MClepton_px);
		tree->SetBranchAddress("MClepton_py", &MClepton_py, &b_MClepton_py);
		tree->SetBranchAddress("MClepton_pz", &MClepton_pz, &b_MClepton_pz);
		tree->SetBranchAddress("MCleptonPDGid", &MCleptonPDGid, &b_MCleptonPDGid);
		tree->SetBranchAddress("MCneutrino_px", &MCneutrino_px, &b_MCneutrino_px);
		tree->SetBranchAddress("MCneutrino_py", &MCneutrino_py, &b_MCneutrino_py);
		tree->SetBranchAddress("MCneutrino_pz", &MCneutrino_pz, &b_MCneutrino_pz);
		//tree->SetBranchAddress("NPrimaryVertices", &NPrimaryVertices, &b_NPrimaryVertices);
		tree->SetBranchAddress("triggerIsoMu24", &triggerIsoMu24, &b_triggerIsoMu24);
		tree->SetBranchAddress("EventWeight", &EventWeight, &b_EventWeight);
		
		
		
		
		//met.SetXYZM(MET_px, MET_py, 0., 0.);
		TLorentzVector hadW, lepW; 
		
		
		//TH1F *h1 = new TH1F("h1", "Massa Invariante de 2Muons", 120, 0, 120);
		//TH1F *h1 = new TH1F("h1", "No. de Muons Isolados", 4, 0, 4);
		TH2F *h1 = new TH2F("h1", "", 32, -3.2, 3.2, 32, -3.2, 3.2);
		
		
//Frequencia de Muons Isolados:
/*		Int_t nentries= (Int_t)tree->GetEntries();
		for (Int_t i = 0; i<nentries; i++) {
			tree->GetEntry(i);
			int N_IsoMuon = 0;
			if (NMuon>1){
				for (int j=0; j<NMuon; j++) {
					if (Muon_Iso[j]<0.05){
						++N_IsoMuon;
					}
				}
			}
			h1->Fill(N_IsoMuon);
		}
		h1->SetYTitle("Eventos");
		h1->SetXTitle("No. de Muons");
		h1->Draw();
*/
//Massa Invariante
/*		Int_t nentries= (Int_t)tree->GetEntries();
		for (Int_t i = 0; i<nentries; i++) {
			tree->GetEntry(i);
   			if (NMuon>1){
				for (int j=0; j<NMuon; j++) {
					if ((Muon_Charge[j]>0)&&(Muon_Iso[j]<0.05)) {
						for(int l = 0; l<NMuon ; l++) {
							if (j!=l) {
								if ((Muon_Charge[l]<0)&&(Muon_Iso[l]<0.05)) {
									particula_pos.SetPxPyPzE(Muon_Px[j], Muon_Py[j], Muon_Pz[j], Muon_E[j]);
									particula_neg.SetPxPyPzE(Muon_Px[l], Muon_Py[l], Muon_Pz[l], Muon_E[l]);
									particula= particula_pos + particula_neg;
									m= particula.Mag();
									h1->Fill(m, EventWeight);
								} //muon charge l<0
							} //j diferente de l
						} //for l
					} //charge>0
				} //for j
			}
		}

		h1->SetYTitle("Eventos");
		h1->SetXTitle("#mu+#mu-(GeV)");
		h1->Fit("gaus");
		h1->SetFillColor(38);
		h1->Draw();	
*/
//Grafico TH2F:
		Int_t nentries= (Int_t)tree->GetEntries();
		for (Int_t i = 0; i<nentries; i++) {
			tree->GetEntry(i);
			hadB.SetXYZM(MChadronicBottom_px, MChadronicBottom_py, MChadronicBottom_pz, 4.8);
			lepB.SetXYZM(MCleptonicBottom_px, MCleptonicBottom_py, MCleptonicBottom_pz, 4.8);
			hadWq.SetXYZM(MChadronicWDecayQuark_px, MChadronicWDecayQuark_py, MChadronicWDecayQuark_pz, 0.0);
			hadWqb.SetXYZM(MChadronicWDecayQuarkBar_px, MChadronicWDecayQuarkBar_py, MChadronicWDecayQuarkBar_pz, 0.0);
			lepWl.SetXYZM(MClepton_px, MClepton_py, MClepton_pz, 0.0);
			lepWn.SetXYZM(MCneutrino_px, MCneutrino_py, MCneutrino_pz, 0.0);
			hadW = hadWq +hadWqb; //soma de TLorentzVector dos MC de W_had;
			lepW = lepWl +lepWn;
		
			if (hadW.E() >0) {
//Estudo de Phi		
				double delta_phi_1 = hadW.DeltaPhi(hadB);
				double delta_phi_2 = hadW.DeltaPhi(lepB);
				double delta_phi_3 = lepW.DeltaPhi(hadB);
				double delta_phi_4 = lepW.DeltaPhi(lepB);
//Estudo de Eta
				double dif_eta_1 = hadW.Eta() -hadB.Eta();
				double dif_eta_2 = hadW.Eta() -lepB.Eta();
				double dif_eta_3 = lepW.Eta() - hadB.Eta();
				double dif_eta_4 = lepW.Eta() - lepB.Eta();

//Estudo do DeltaR		
				double delta_r = hadW.DeltaR(hadB);
				double delta_r_2 = hadW.DeltaR(lepB);
				double delta_r_3 = lepW.DeltaR(hadB);
				double delta_r_4 = lepW.DeltaR(lepB);
				
				//h1->Fill(hadW.Eta() -hadB.Eta(), hadW.DeltaPhi(hadB));
				//h1->Fill(hadW.Eta() -lepB.Eta(), hadW.DeltaPhi(lepB));
				//h1->Fill(lepW.Eta() -hadB.Eta(), lepW.DeltaPhi(hadB));
				h1->Fill(lepW.Eta() -lepB.Eta(), lepW.DeltaPhi(lepB));
			}
		}
			
			
		h1->Sumw2();
		h1->SetXTitle("#Delta#eta (rad)");
		h1->SetYTitle("#Delta#phi(rad)");
		h1->SetFillColor(8);
		//h1->SetFillColor(5);
		h1->SetTitle("Distribuicao para W_{had} e b_{had}");
		//h1->SetTitle("Distribuicao para W_{had} e b_{lep}");
		//h1->SetTitle("Distribuicao para W_{lep} e b_{had}");
		//h1->SetTitle("Distribuicao para W_{lep} e b_{lep}");
		h1->Draw("box");
    }