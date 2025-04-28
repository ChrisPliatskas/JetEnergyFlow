void MakeClosure_pp(int Niter){


  double R =0.;

 // for(int i=1;i<8;i++){R=0.05*i; UnfoldPreparation_EF_embed("Summary_Embed_FixRM_ch1_train.root",R,15.,-10.);}
/*
for(int i=1;i<8;i++){ R=0.05*i;ClosureTest_pp_wFakes("Summary_ppMC_2016test.root","ResponseMatrix_pp_Updated_wFakes_NewBinW3_Ptw5_ptmin15_Dptmin-1_25.root",R,40,60,Niter,3);}

for(int i=1;i<8;i++){ R=0.05*i;ClosureTest_pp_wFakes("Summary_ppMC_2016test.root","ResponseMatrix_pp_Updated_wFakes_NewBinW3_Ptw5_ptmin15_Dptmin-1_25.root",R,60,80,Niter,3);}


for(int i=1;i<8;i++){ R=0.05*i;ClosureTest_pp_wFakes("Summary_ppMC_2016test.root","ResponseMatrix_pp_Updated_wFakes_NewBinW3_Ptw5_ptmin15_Dptmin-1_31.root",R,40,60,Niter,3);}

for(int i=1;i<8;i++){ R=0.05*i;ClosureTest_pp_wFakes("Summary_ppMC_2016test.root","ResponseMatrix_pp_Updated_wFakes_NewBinW3_Ptw5_ptmin15_Dptmin-1_31.root",R,60,80,Niter,3);}


for(int i=1;i<8;i++){ R=0.05*i;ClosureTest_pp_wFakes("Summary_ppMC_2016test.root","ResponseMatrix_pp_Updated_wFakes_NewBinW3_Ptw5_ptmin15_Dptmin-1_25_140.root",R,60,80,Niter,3);}


for(int i=1;i<8;i++){ R=0.05*i;ClosureTest_pp_wFakes("Summary_ppMC_2016test.root","ResponseMatrix_pp_Updated_wFakes_NewBinW3_Ptw5_ptmin15_Dptmin-1_22.root",R,60,80,Niter,3);}

for(int i=1;i<8;i++){ R=0.05*i;ClosureTest_pp_wFakes("Summary_ppMC_2016test.root","ResponseMatrix_pp_PrelimConfig_wFakes_NewBinW3_Ptw5_ptmin15_Dptmin-1_25.root",R,60,80,Niter,3);}

for(int i=1;i<8;i++){ R=0.05*i;ClosureTest_pp_wFakes("Summary_ppMC_2016test.root","ResponseMatrix_pp_PrelimConfig_wFakes_NewBinW3_Ptw5_ptmin15_Dptmin-1_25.root",R,40,60,Niter,3);}
*/
for(int i=1;i<8;i++){ R=0.05*i;ClosureTest_pp_wFakes("Summary_ppMC_2018_ch4.root","ResponseMatrix_pp_Updated_wFakes_2018_NewBinW3_Ptw5_ptmin15_Dptmin-1_22.root",R,60,80,Niter,3);}

for(int i=1;i<8;i++){ R=0.05*i;ClosureTest_pp_wFakes("Summary_ppMC_2018_ch4.root","ResponseMatrix_pp_Updated_wFakes_2018_NewBinW3_Ptw5_ptmin15_Dptmin-1_25.root",R,60,80,Niter,3);}

for(int i=1;i<8;i++){ R=0.05*i;ClosureTest_pp_wFakes("Summary_ppMC_2018_ch4.root","ResponseMatrix_pp_Updated_wFakes_2018_NewBinW3_Ptw5_ptmin15_Dptmin-1_22.root",R,40,60,Niter,3);}

for(int i=1;i<8;i++){ R=0.05*i;ClosureTest_pp_wFakes("Summary_ppMC_2018_ch4.root","ResponseMatrix_pp_Updated_wFakes_2018_NewBinW3_Ptw5_ptmin15_Dptmin-1_25.root",R,40,60,Niter,3);}

//*/
}
