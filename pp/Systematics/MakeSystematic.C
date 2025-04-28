void MakeSystematic(int Ptlow, int Pthigh){


//------------------------Tracking efficiency-----------------------------//
for(int j=1;j<8;j++)Systematics(Form("UnfoldedResults_ppFinalSolution_wFakes_smallR_Binw3_pt_%d_%d_ptmin20_Dptmin-1_max28_Iter4.root",Ptlow,Pthigh),Form("TrackEff/UnfoldedResults_ppFinalSolution_TrackEff_wFakes_smallR_Binw3_pt_%d_%d_ptmin20_Dptmin-1_max28_Iter4.root",Ptlow,Pthigh),0.05*j,Ptlow,Pthigh,1);


//------------------------Unfolding/Truncation----------------------------//
for(int j=1;j<8;j++)Systematics(Form("UnfoldedResults_ppFinalSolution_wFakes_smallR_Binw3_pt_%d_%d_ptmin20_Dptmin-1_max28_Iter4.root",Ptlow,Pthigh),Form("Unfolding/Truncation/UnfoldedResults_ppFinalSolution_Trunc_wFakes_smallR_Binw3_pt_%d_%d_ptmin25_Dptmin-1_max28_Iter4.root",Ptlow,Pthigh),0.05*j,Ptlow,Pthigh,1);

//-------------------------Unfolding/Niter--------------------------------//
for(int j=1;j<8;j++)Systematics(Form("UnfoldedResults_ppFinalSolution_wFakes_smallR_Binw3_pt_%d_%d_ptmin20_Dptmin-1_max28_Iter4.root",Ptlow,Pthigh),Form("Unfolding/Niter/UnfoldedResults_ppFinalSolution_wFakes_smallR_Binw3_pt_%d_%d_ptmin20_Dptmin-1_max28_Iter3.root",Ptlow,Pthigh),0.05*j,Ptlow,Pthigh,1);

for(int j=1;j<8;j++)Systematics(Form("UnfoldedResults_ppFinalSolution_wFakes_smallR_Binw3_pt_%d_%d_ptmin20_Dptmin-1_max28_Iter4.root",Ptlow,Pthigh),Form("Unfolding/Niter/UnfoldedResults_ppFinalSolution_wFakes_smallR_Binw3_pt_%d_%d_ptmin20_Dptmin-1_max28_Iter5.root",Ptlow,Pthigh),0.05*j,Ptlow,Pthigh,1);

//-------------------------Unfolding/Prior--------------------------------//
for(int j=1;j<8;j++)Systematics(Form("UnfoldedResults_ppFinalSolution_wFakes_smallR_Binw3_pt_%d_%d_ptmin20_Dptmin-1_max28_Iter4.root",Ptlow,Pthigh),Form("Unfolding/Prior/UnfoldedResults_ppFinalSolution_ModResponse_DPt5_pt_%d_%d_ptmin20_Dptmin-1_ptmax100_Dptmax28_Iter4.root",Ptlow,Pthigh),0.05*j,Ptlow,Pthigh,1);

for(int j=1;j<8;j++)Systematics(Form("UnfoldedResults_ppFinalSolution_wFakes_smallR_Binw3_pt_%d_%d_ptmin20_Dptmin-1_max28_Iter4.root",Ptlow,Pthigh),Form("Unfolding/Prior/UnfoldedResults_ppFinalSolution_ModResponse_DPt5_pt_%d_%d_ptmin20_Dptmin-1_ptmax100_Dptmax28_Iter4.root",Ptlow,Pthigh),0.05*j,Ptlow,Pthigh,2);
//--------------------------Model dependence------------------------------//

for(int j=1;j<8;j++)Systematics(Form("Model_dependence/UnfoldedResults_pp_PYTHIAfastSim_wFakes_smallR_Binw3_pt_%d_%d_ptmin20_Dptmin-1_max28_Iter4.root",Ptlow,Pthigh),Form("Model_dependence/UnfoldedResults_pp_HERWIGfastsim_wFakes_smallR_Binw3_pt_%d_%d_ptmin20_Dptmin-1_max28_Iter4.root",Ptlow,Pthigh),0.05*j,Ptlow,Pthigh,1);
}
