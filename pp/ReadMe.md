# Documentation for pp

This directory contains the analysis macros for the pp component of the JEFF analysis.
Below are some details or instructions you may find helpful.

Instructions for pp: 
**Data**: Macros for the calculation and plotting of the relevant histograms for the analysis task output when it is executed over the ALICE Run 2 pp data.

**MC**: Macros for the calculation and plotting of the relevant histograms for the analysis task output when it is executed over the ALICE PYTHIA simulations anchored to the analysed data.

**Unfolding**: Holds the macros that can be used to set up the relevant RooUnfold objects as well as the macro that does the actual unfolding.In the closure subdirectory, there is a variation of the default unfolding task to be more suitable for this purpose as well as plotting macro. The correct execution order is UnfoldPreparation....C followed by Unfolding_macro... or ClosureTest.. There are also two steering macros which can help automate the process.


**Systematics**: This directory contains the sub-analysis macros for each systematic variation which was examined in the analysis.
There is a macro that calculates the systematic ratio for each variation (Systematics.C), a steering macro(MakeSystematics),a few plotting macros and two macros which calculate the total systematic per Dpt bin in each of the two pt bins(Syst_Comb).
 The contribution from each source is hardcoded and has been previously estimated through visual inspection of the individual variation ratios. 
 There are two macros in the Unfolding subdirectory which set up and calculate the unfolded resulted with a scaling of the prior.
There are scripts which can print out the variation ratios for each source in a short text file(Syst_Extractor...C)
