# This is a simple bash script which initiates the analysis on the JEWEL simulations by calling the analyse_files* script in this directory. It was tailored for the Nikhef stoomboot server as it was setup in 2022. Changes may be required to reflect the new stoomboot queueing scheme.
if [ $# -lt 3 ]
then
  echo "Need input directory name: $0 <indir> <startfolder> <endfolder> [nfolder]"
  exit 255
fi

# indir=/home/staff/leeuw179/JEWEL/$1
indir=$1
outdir=$1
firstfile=$2
lastfile=$3
nfile=${4:-10}
#firstfile=5
#lastfile=20

for ((ifile=$firstfile;ifile<=$lastfile;ifile+=$nfile))
do
let  lastfile_job=$ifile+$nfile-1
if [ $lastfile_job -gt $lastfile ]
then
	lastfile_job=$lastfile
fi
# The arguments correspond to: the job name, the queue, the logfile for output stream, logfile for error stream, input directory, input file, starting file, last file and executable script

#qsub -V -N analyse_EF_AAnorec_emb -q generic -o log2 -e log2 -v indir=$indir,infile=example.hepmc,firstfile=$ifile,lastfile=$lastfile_job analyze_files_batch_EF_AAnorec.sh

qsub -V -N analyse_EF_AAnorec_emb_low -q generic -o log2 -e log2 -v indir=$indir,infile=example.hepmc,firstfile=$ifile,lastfile=$lastfile_job analyze_files_batch_EF_AAnorec.sh


done

