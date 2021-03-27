void Centrality(){

  TFile *f = new TFile("getmultiplicity_BiBi_9.46GeV.root", "READ");

  TH1F * hmultiplicity = (TH1F*)f->Get("h_multiplicity;1");
  TH1F * hcompare = (TH1F*)f->Get("h_mult_compare;1");
  TH1F * hold = (TH1F*)f->Get("h_mult_old;1");

  //  f->ls();
  /*
  hmultiplicity->SetDirectory(0);  
  hmultiplicity->SetFillColor(2);
  hmultiplicity->SetLineColor(kBlack);
  hmultiplicity->Draw("HIST L");
  gPad->SetLogy();
  */
  
  Double_t nbin = hmultiplicity->GetNbinsX();
  Double_t nbinn=700;
  Double_t xmax=700;
  TH1F *hmultiplicity10= new TH1F("hmultiplicity10","",nbinn,0,xmax);
  TH1F *hmultiplicity20= new TH1F("hmultiplicity20","",nbinn,0,xmax);
  TH1F *hmultiplicity30= new TH1F("hmultiplicity30","",nbinn,0,xmax);
  TH1F *hmultiplicity40= new TH1F("hmultiplicity40","",nbinn,0,xmax);
  TH1F *hmultiplicity50= new TH1F("hmultiplicity50","",nbinn,0,xmax);
  TH1F *hmultiplicity60= new TH1F("hmultiplicity60","",nbinn,0,xmax);
  TH1F *hmultiplicity70= new TH1F("hmultiplicity70","",nbinn,0,xmax);
  TH1F *hmultiplicity80= new TH1F("hmultiplicity80","",nbinn,0,xmax);
  TH1F *hmultiplicity90= new TH1F("hmultiplicity90","",nbinn,0,xmax);
  TH1F *hmultiplicity100= new TH1F("hmultiplicity100","",nbinn,0,xmax);
  TH2D *hcentrality = new TH2D("hcentrality","",nbin,0,101,nbin,0,668);
  Double_t C=0;
  Double_t Total = hmultiplicity->Integral(0,nbin);


  Double_t nbinold = hold->GetNbinsX();
  Double_t nbinnold=1600;
  Double_t xmaxold=1600;
  TH1F *hmultiplicity10old= new TH1F("hmultiplicity10old","",nbinnold,0,xmaxold);
  TH1F *hmultiplicity20old= new TH1F("hmultiplicity20old","",nbinnold,0,xmaxold);
  TH1F *hmultiplicity30old= new TH1F("hmultiplicity30old","",nbinnold,0,xmaxold);
  TH1F *hmultiplicity40old= new TH1F("hmultiplicity40old","",nbinnold,0,xmaxold);
  TH1F *hmultiplicity50old= new TH1F("hmultiplicity50old","",nbinnold,0,xmaxold);
  TH1F *hmultiplicity60old= new TH1F("hmultiplicity60old","",nbinnold,0,xmaxold);
  TH1F *hmultiplicity70old= new TH1F("hmultiplicity70old","",nbinnold,0,xmaxold);
  TH1F *hmultiplicity80old= new TH1F("hmultiplicity80old","",nbinnold,0,xmaxold);
  TH1F *hmultiplicity90old= new TH1F("hmultiplicity90old","",nbinnold,0,xmaxold);
  TH1F *hmultiplicity100old= new TH1F("hmultiplicity100old","",nbinnold,0,xmaxold);
  TH2D *hcentralityold = new TH2D("hcentralityold","",nbinold,0,101,nbinold,0,1400);
  Double_t Cold=0;
  Double_t Totalold = hold->Integral(0,nbinold);
  
  Int_t a10old=0;
  Int_t a20old=0;
  Int_t a30old=0;
  Int_t a40old=0;
  Int_t a50old=0;
  Int_t a60old=0;
  Int_t a70old=0;
  Int_t a80old=0;
  Int_t a90old=0;
  Int_t a100old=0;

  for(Double_t i=nbinold; i>=0; i--){
    Double_t Rangeold = hold->Integral(i, nbinold);
    Double_t Cold = Rangeold*100/Totalold;
    hcentralityold->Fill(Cold,i);
    if(Cold>=0 && Cold<=10){
      a10old=i;
      hmultiplicity10old->Fill(i,hold->GetBinContent(i));
    }
    if(Cold>=10 && Cold<=20){
      a20old=i;
      hmultiplicity20old->Fill(i,hold->GetBinContent(i));
    }
    if(Cold>=20 && Cold<=30){
      a30old=i;
      hmultiplicity30old->Fill(i,hold->GetBinContent(i));
    }
    if(Cold>=30 && Cold<=40){
      a40old=i;
      hmultiplicity40old->Fill(i,hold->GetBinContent(i));
    }
    if(Cold>=40 && Cold<=50){
      a50old=i;
      hmultiplicity50old->Fill(i,hold->GetBinContent(i));
    }
    if(Cold>=50 && Cold<=60){
      a60old=i;
      hmultiplicity60old->Fill(i,hold->GetBinContent(i));
    }
    if(Cold>=60 && Cold<=70){
      a70old=i;
      hmultiplicity70old->Fill(i,hold->GetBinContent(i));
    }
    if(Cold>=70 && Cold<=80){
      a80old=i;
      hmultiplicity80old->Fill(i,hold->GetBinContent(i));
    }
    if(Cold>=80 && Cold<=90){
      a90old=i;
      hmultiplicity90old->Fill(i,hold->GetBinContent(i));
    }
    if(Cold>=90 && Cold<=100){
      a100old=i;
      hmultiplicity100old->Fill(i,hold->GetBinContent(i));
    }
    //        cout<<"Centrality= "<<Cold<<"    Multplicity= "<<i<<endl;
  }

  
  Int_t a10=0;
  Int_t a20=0;
  Int_t a30=0;
  Int_t a40=0;
  Int_t a50=0;
  Int_t a60=0;
  Int_t a70=0;
  Int_t a80=0;
  Int_t a90=0;
  Int_t a100=0;
  for(Double_t i=nbin; i>=0; i--){
    Double_t Range = hmultiplicity->Integral(i, nbin);
    Double_t C = Range*100/Total;
    hcentrality->Fill(C,i);
    if(C>=0 && C<=10){
      a10=i;
      hmultiplicity10->Fill(i,hmultiplicity->GetBinContent(i));
    }
    if(C>=10 && C<=20){
      a20=i;
      hmultiplicity20->Fill(i,hmultiplicity->GetBinContent(i));
    }
    if(C>=20 && C<=30){
      a30=i;
      hmultiplicity30->Fill(i,hmultiplicity->GetBinContent(i));
    }
    if(C>=30 && C<=40){
      a40=i;
      hmultiplicity40->Fill(i,hmultiplicity->GetBinContent(i));
    }
    if(C>=40 && C<=50){
      a50=i;
      hmultiplicity50->Fill(i,hmultiplicity->GetBinContent(i));
    }
    if(C>=50 && C<=60){
      a60=i;
      hmultiplicity60->Fill(i,hmultiplicity->GetBinContent(i));
    }
    if(C>=60 && C<=70){
      a70=i;
      hmultiplicity70->Fill(i,hmultiplicity->GetBinContent(i));
    }
    if(C>=70 && C<=80){
      a80=i;
      hmultiplicity80->Fill(i,hmultiplicity->GetBinContent(i));
    }
    if(C>=80 && C<=90){
      a90=i;
      hmultiplicity90->Fill(i,hmultiplicity->GetBinContent(i));
    }
    if(C>=90 && C<=100){
      a100=i;
      hmultiplicity100->Fill(i,hmultiplicity->GetBinContent(i));
    }
    cout<<"Centrality= "<<C<<"    Multplicity= "<<i<<endl;
  }

  /*
  cout<<a10<<endl;
  cout<<a20<<endl;
  cout<<a30<<endl;
  cout<<a40<<endl;
  cout<<a50<<endl;
  cout<<a60<<endl;
  cout<<a70<<endl;
  cout<<a80<<endl;
  cout<<a90<<endl;
  cout<<a100<<endl;
  cout<<nbin<<endl;
  */
  TCanvas* c2 = new TCanvas("c2","Multiplicity",600,600);
  gStyle->SetOptStat(false);
  auto axis = hmultiplicity10->GetXaxis();
  hmultiplicity10->SetDirectory(0);
  hmultiplicity10->SetFillColor(2);
  hmultiplicity10->SetLineColor(kBlack);
  hmultiplicity10->GetYaxis()->SetRangeUser(0.1,400000);
  hmultiplicity10->SetXTitle("N_{tracks} in TPC");
  hmultiplicity10->GetXaxis()->CenterTitle(true);
  hmultiplicity10->GetXaxis()->SetTitleOffset(1.4);
  hmultiplicity10->SetYTitle("N_{events}");
  hmultiplicity10->GetYaxis()->CenterTitle(true);
  hmultiplicity10->GetYaxis()->SetTitleOffset(1.4);
  //  hmultiplicity10->SetTitle("Multiplicity in TPC after cuts");
  hmultiplicity10->Draw("HIST L");
  gPad->SetLogy();

  hmultiplicity20->SetDirectory(0);
  hmultiplicity20->SetFillColor(3);
  hmultiplicity20->SetLineColor(kBlack);
  hmultiplicity20->Draw("HIST L sames");

  hmultiplicity30->SetDirectory(0);
  hmultiplicity30->SetFillColor(4);
  hmultiplicity30->SetLineColor(kBlack);
  hmultiplicity30->Draw("HIST L sames");

  hmultiplicity40->SetDirectory(0);
  hmultiplicity40->SetFillColor(5);
  hmultiplicity40->SetLineColor(kBlack);
  hmultiplicity40->Draw("HIST L sames");

  hmultiplicity50->SetDirectory(0);
  hmultiplicity50->SetFillColor(6);
  hmultiplicity50->SetLineColor(kBlack);
  hmultiplicity50->Draw("HIST L sames");

  hmultiplicity60->SetDirectory(0);
  hmultiplicity60->SetFillColor(7);
  hmultiplicity60->SetLineColor(kBlack);
  hmultiplicity60->Draw("HIST L sames");

  hmultiplicity70->SetDirectory(0);
  hmultiplicity70->SetFillColor(8);
  hmultiplicity70->SetLineColor(kBlack);
  hmultiplicity70->Draw("HIST L sames");

  hmultiplicity80->SetDirectory(0);
  hmultiplicity80->SetFillColor(9);
  hmultiplicity80->SetLineColor(kBlack);
  hmultiplicity80->Draw("HIST L sames");

  hmultiplicity90->SetDirectory(0);
  hmultiplicity90->SetFillColor(42);
  hmultiplicity90->SetLineColor(kBlack);
  hmultiplicity90->Draw("HIST L sames");

  hmultiplicity100->SetDirectory(0);
  hmultiplicity100->SetFillColor(11);
  hmultiplicity100->SetLineColor(kBlack);
  hmultiplicity100->Draw("HIST L sames");

  TLegend *leg2 = new TLegend(0.6,0.62,0.89,0.89);
  leg2->SetTextFont(62);
  // leg2->SetTextSize(1);                                    
  leg2->SetLineColor(0);
  leg2->SetLineStyle(0);
  leg2->SetLineWidth(1);
  leg2->SetFillColor(0);
  leg2->SetFillStyle(1001);
  leg2->AddEntry("","Multiplicity in TPC after cuts","");
  leg2->AddEntry("","UrQMD, Bi+Bi 9.46 GeV","");
  leg2->AddEntry("hmultiplicity10","0-10%","f");
  leg2->AddEntry("hmultiplicity20","10-20%","f");
  leg2->AddEntry("hmultiplicity30","20-30%","f");
  leg2->AddEntry("hmultiplicity40","30-40%","f"); 
  leg2->AddEntry("hmultiplicity50","40-50%","f");
  leg2->AddEntry("hmultiplicity60","50-60%","f");
  leg2->AddEntry("hmultiplicity70","60-70%","f");
  leg2->AddEntry("hmultiplicity80","70-80%","f");
  leg2->AddEntry("hmultiplicity90","80-90%","f");
  leg2->AddEntry("hmultiplicity100","90-100%","f");
  leg2->Draw();
  c2->SaveAs("Multiplicity_BiBi_9.46GeV.pdf");
  c2->SaveAs("Multiplicity_BiBi_9.46GeV.eps");
  
  TCanvas* c3 = new TCanvas("c3","Centrality",600,600);
  gStyle->SetOptStat(false);
  c3->SetRightMargin(0.0465116);
  c3->SetTopMargin(0.1);
  c3->SetFillColor(0);
  //  hcentrality->Draw("hist p sames");
  hcentralityold->SetMarkerColor(1);
  hcentralityold->SetMarkerStyle(20);
  hcentralityold->SetMarkerSize(0.8);
  hcentralityold->SetXTitle("Centrality %");
  hcentralityold->GetXaxis()->CenterTitle(true);
  hcentralityold->GetXaxis()->SetTitleSize(0.04);
  hcentralityold->GetXaxis()->SetLabelSize(0.03);
  hcentralityold->GetXaxis()->SetTitleOffset(1.2);
  hcentralityold->SetYTitle("N_{tracks} in TPC");
  hcentralityold->GetYaxis()->CenterTitle(true);
  hcentralityold->GetYaxis()->SetTitleSize(0.04);
  hcentralityold->GetYaxis()->SetLabelSize(0.03);
  hcentralityold->GetYaxis()->SetTitleOffset(1.2);
  //  hcentralityold->SetTitle("Centrality in TPC after cuts");
  hcentralityold->Draw("hist p");

  hcentrality->SetMarkerColor(2);
  hcentrality->SetMarkerStyle(20);
  hcentrality->SetMarkerSize(0.8);
  hcentrality->Draw("hist p sames");
   
  TLegend *leg3 = new TLegend(0.6,0.62,0.89,0.89);
  leg3->SetTextFont(62);
  // leg3->SetTextSize(1);                                    
  leg3->SetLineColor(0);
  leg3->SetLineStyle(0);
  leg3->SetLineWidth(1);
  leg3->SetFillColor(0);
  leg3->SetFillStyle(1001);
  leg3->AddEntry("","UrQMD, Bi+Bi 9.46 GeV","");
  leg3->AddEntry("hcentralityold","TPC before cuts","p");
  leg3->AddEntry("hcentrality","TPC after cuts","p");
  leg3->Draw();

  c3->SaveAs("Centrality_BiBi_9.46GeV.pdf");
  c3->SaveAs("Centrality_BiBi_9.46GeV.eps");

  TCanvas* c4 = new TCanvas("c4","Multiplicity old",600,600);
  gStyle->SetOptStat(false);
  auto axisold = hmultiplicity10old->GetXaxis();
  hmultiplicity10old->SetDirectory(0);
  hmultiplicity10old->SetFillColor(2);
  hmultiplicity10old->SetLineColor(kBlack);
  hmultiplicity10old->GetYaxis()->SetRangeUser(0.1,400000);
  hmultiplicity10old->SetXTitle("N_{tracks} in TPC");
  hmultiplicity10old->GetXaxis()->CenterTitle(true);
  hmultiplicity10old->GetXaxis()->SetTitleOffset(1.4);
  hmultiplicity10old->SetYTitle("N_{events}");
  hmultiplicity10old->GetYaxis()->CenterTitle(true);
  hmultiplicity10old->GetYaxis()->SetTitleOffset(1.4);
  //  hmultiplicity10old->SetTitle("Multiplicity in TPC before cuts");
  hmultiplicity10old->Draw("HIST L");
  gPad->SetLogy();

  hmultiplicity20old->SetDirectory(0);
  hmultiplicity20old->SetFillColor(3);
  hmultiplicity20old->SetLineColor(kBlack);
  hmultiplicity20old->Draw("HIST L sames");

  hmultiplicity30old->SetDirectory(0);
  hmultiplicity30old->SetFillColor(4);
  hmultiplicity30old->SetLineColor(kBlack);
  hmultiplicity30old->Draw("HIST L sames");

  hmultiplicity40old->SetDirectory(0);
  hmultiplicity40old->SetFillColor(5);
  hmultiplicity40old->SetLineColor(kBlack);
  hmultiplicity40old->Draw("HIST L sames");

  hmultiplicity50old->SetDirectory(0);
  hmultiplicity50old->SetFillColor(6);
  hmultiplicity50old->SetLineColor(kBlack);
  hmultiplicity50old->Draw("HIST L sames");

  hmultiplicity60old->SetDirectory(0);
  hmultiplicity60old->SetFillColor(7);
  hmultiplicity60old->SetLineColor(kBlack);
  hmultiplicity60old->Draw("HIST L sames");

  hmultiplicity70old->SetDirectory(0);
  hmultiplicity70old->SetFillColor(8);
  hmultiplicity70old->SetLineColor(kBlack);
  hmultiplicity70old->Draw("HIST L sames");

  hmultiplicity80old->SetDirectory(0);
  hmultiplicity80old->SetFillColor(9);
  hmultiplicity80old->SetLineColor(kBlack);
  hmultiplicity80old->Draw("HIST L sames");

  hmultiplicity90old->SetDirectory(0);
  hmultiplicity90old->SetFillColor(42);
  hmultiplicity90old->SetLineColor(kBlack);
  hmultiplicity90old->Draw("HIST L sames");

  hmultiplicity100old->SetDirectory(0);
  hmultiplicity100old->SetFillColor(11);
  hmultiplicity100old->SetLineColor(kBlack);
  hmultiplicity100old->Draw("HIST L sames");

  TLegend *leg4 = new TLegend(0.6,0.62,0.89,0.89);
  leg4->SetTextFont(62);
  // leg4->SetTextSize(1);                                    
  leg4->SetLineColor(0);
  leg4->SetLineStyle(0);
  leg4->SetLineWidth(1);
  leg4->SetFillColor(0);
  leg4->SetFillStyle(1001);
  leg4->AddEntry("","Multiplicity in TPC before cuts","");
  leg4->AddEntry("","UrQMD, Bi+Bi 9.46 GeV","");
  leg4->AddEntry("hmultiplicity10old","0-10%","f");
  leg4->AddEntry("hmultiplicity20old","10-20%","f");
  leg4->AddEntry("hmultiplicity30old","20-30%","f");
  leg4->AddEntry("hmultiplicity40old","30-40%","f"); 
  leg4->AddEntry("hmultiplicity50old","40-50%","f");
  leg4->AddEntry("hmultiplicity60old","50-60%","f");
  leg4->AddEntry("hmultiplicity70old","60-70%","f");
  leg4->AddEntry("hmultiplicity80old","70-80%","f");
  leg4->AddEntry("hmultiplicity90old","80-90%","f");
  leg4->AddEntry("hmultiplicity100old","90-100%","f");
  leg4->Draw();
  c4->SaveAs("Multiplicity_BiBi_9.46GeV_old.pdf");
  c4->SaveAs("Multiplicity_BiBi_9.46GeV_old.eps");

}
