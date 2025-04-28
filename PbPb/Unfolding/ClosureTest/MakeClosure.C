void MakeClosure(int Niter){


  double R =0.;

//for(int k=1;k<5;k++){R=0.05*k;ClosureTest_wFakes("Summary_embed_SmallR_ch2.root","ResponseMatrix_PbPb_ConstSub_Updated_LCJC_wFakes_smallR_NewBinW3_LC8_Ptw5_ptmin15_Dptmin-1_25.root",R,60,80,Niter,3);}

for(int k=1;k<5;k++){R=0.05*k;ClosureTest_wFakes("Summary_embed_SmallR_ch2.root","ResponseMatrix_PbPb_ConstSub_Updated_LCJC_wFakes_smallR_NewBinW3_LC8_Ptw5_ptmin15_Dptmin-1_31.root",R,60,80,Niter,3);}

//for(int k=1;k<5;k++){R=0.05*k;ClosureTest_wFakes("Summary_embed_lcjc8_smallR_ch2.root","ResponseMatrix_PbPb_ConstSub_Updated_oldTest_LCJC_wFakes_smallR_NewBinW3_LC8_Ptw5_ptmin15_Dptmin-1_31.root",R,60,80,Niter,3);}

//for(int k=5;k<8;k++){R=0.05*k;ClosureTest_wFakes("Summary_embed_lcjc8_largeR_ch2.root","ResponseMatrix_PbPb_ConstSub_Updated_new_extended_wFakes_NewBinW3_LC8_Ptw5_ptmin15_Dptmin-1_31.root",R,60,80,Niter,3);}
}

