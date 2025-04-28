# Documentation for PbPb

This directory contains the analysis macros for the PbPb component of the JEFF analysis.
Below are some details or instructions you may find helpful.

Instructions for PbPb:

**Data**: Macros for the calculation and plotting of the relevant histograms for the analysis task output when it is executed over the ALICE Run 2 PbPb data.

**Embedded**: This script plots the relevant histograms of the embedded Pythia simulations which are present in the thesis document.

**Unfolding**: Similarly to the pp counterpart it has the scripts for the setup of the RooUnfold objects and the unfolding of the PbPb data. There is a steering macro and some scripts to run the closure tests.

**Systematics**: This directory contains the macros for the unfolding of the data with each systematic variation, the estimation of the systematic variation ratio and its extraction to a txt file and finally a couple of macros that combine all of the individual systematic contributions and also plot the final PbPb results of the analysis.
