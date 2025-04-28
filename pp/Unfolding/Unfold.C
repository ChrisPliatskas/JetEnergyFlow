void Unfold(int Niter){

double R=0.;

/*
for(int i =1;i<8;i++){R=0.05*i;Unfolding_macro_pp_updated_wFakes("Summary_ppdata_13TeV_NewBinning.root","ResponseMatrix_pp_Updated_wFakes_NewBinW3_Ptw5_ptmin15_Dptmin-1_25.root",R,40,60,3,Niter);}

for(int i =1;i<8;i++){R=0.05*i;Unfolding_macro_pp_updated_wFakes("Summary_ppdata_13TeV_NewBinning.root","ResponseMatrix_pp_Updated_wFakes_NewBinW3_Ptw5_ptmin15_Dptmin-1_25.root",R,60,80,3,Niter);}
*/

for(int i =1;i<8;i++){R=0.05*i;Unfolding_macro_ppTest_updated_wFakes("Summary_ppdata_13TeV_NewBinning.root","ResponseMatrix_pp_FinalSolution_wFakes_smallR_NewBinW3_Ptw5_ptmin20_Dptmin-1_28_2024.root",R,40,60,3,Niter);}

for(int i =1;i<8;i++){R=0.05*i;Unfolding_macro_ppTest_updated_wFakes("Summary_ppdata_13TeV_NewBinning.root","ResponseMatrix_pp_FinalSolution_wFakes_smallR_NewBinW3_Ptw5_ptmin20_Dptmin-1_28_2024.root",R,60,80,3,Niter);}


}
