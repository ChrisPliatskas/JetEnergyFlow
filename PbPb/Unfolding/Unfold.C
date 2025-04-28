void Unfold(int Niter){

double R=0.;

for(int i =1;i<5;i++){R=0.05*i;Unfolding_macro_PbPb_updated_wFakes("Summary_PbPbdata_smallR_LC8_dR01.root","ResponseMatrix_PbPb_ConstSub_Updated_LCJC8_wFakes_smallR_NewBinW3_Ptw10_ptmin10_Dptmin-1_25.root",R,60,80,3,Niter);}

for(int i =1;i<5;i++){R=0.05*i;Unfolding_macro_PbPb_updated_wFakes("Summary_PbPbdata_smallR_LC8_dR01.root","ResponseMatrix_PbPb_ConstSub_Updated_LCJC8_wFakes_smallR_NewBinW5_Ptw5_ptmin15_Dptmin-2_27.root",R,60,80,5,Niter);}

for(int i =1;i<5;i++){R=0.05*i;Unfolding_macro_PbPb_updated_wFakes("Summary_PbPbdata_smallR_LC8_dR01.root","ResponseMatrix_PbPb_ConstSub_Updated_LCJC8_wFakes_smallR_NewBinW5_Ptw10_ptmin10_Dptmin-2_27.root",R,60,80,5,Niter);}


/*
for(int i =1;i<5;i++){R=0.05*i;Unfolding_macro_PbPb_updated_wFakes("Summary_PbPbdata_smallR_LC8_dR01.root","ResponseMatrix_PbPb_ConstSub_Updated_LCJC8_wFakes_smallR_NewBinW3_Ptw5_ptmin15_Dptmin-1_25.root",R,60,80,3,Niter);}

for(int i =1;i<5;i++){R=0.05*i;Unfolding_macro_PbPb_updated_wFakes("Summary_PbPbdata_smallR_LC8_dR01.root","ResponseMatrix_PbPb_ConstSub_Updated_LCJC8_wFakes_smallR_NewBinW3_Ptw5_ptmin15_Dptmin-1_31.root",R,60,80,3,Niter);}
*/
}
