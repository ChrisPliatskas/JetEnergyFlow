# Bash script which serves as the steering macro for the JEWEL analysis. This script is called by the submit_files.sh. Its functionality is very similar to the calling function and the run arguments are specified in that file. 

#!/bin/bash

# Use bash shell on SGE (only relevant on quark)
#$ -S /bin/bash
#
# Use current working directory
#$ -cwd
#
# use log dir for logiles
#$ -o log

#PBS -o $HOME/jewel/analysis/log/analyse_files_batch.o$PBS_O_JOBID

# . /scratch/software/ns-sap-env.sh v5-05-56-AN
# . /scratch/software/ns-sap-env.sh vAN-20141001
# . /scratch/software/ns-sap-env.sh -c v5-05-Rev-21-test
# . /scratch/software/ns-sap-env.sh vAN-20150818
# source /cvmfs/alice.cern.ch/etc/login.sh
#eval $(alienv printenv VO_ALICE@AliPhysics::vAN-20180913-1)

#outdir=$indir

# indir=../$indir
outdir=`basename $indir`

#lastfile=$firstfile+$nfile
echo "nfile = $nfile"
echo "lastfile = $lastfile"
echo " indir = $indir"
echo " outdir = $outdir"


cd $PBS_O_WORKDIR

if [ ! -d $outdir ]
then
  mkdir $outdir
fi

for ((ifile=$firstfile; ifile<$lastfile; ifile++))
do
  inpathfile=$indir/$ifile/$infile
  if [ -f $inpathfile ]
  then
# ./analyze_hepmc_jet_Rdiff_new $indir/$ifile/$infile $outdir/jet_rdiff_NEW_$ifile
  ./analyze_hepmc_jet_EnergyFlow_zr $indir/$ifile/$infile $outdir/EF_jewel_pp13TeV_2PtH_FixPtCut_$ifile 
  fi
done
