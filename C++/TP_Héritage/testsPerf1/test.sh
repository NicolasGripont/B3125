# echo "-----------------------------------------------------------"

execDir=`pwd`

if [ "$1" = "" ]
then
  # echo "No directory given, default to current"
  Directory="."
else  
  # echo "| Test id : $1"
  if [ -d "$1" ]
  then 
     Directory="$1"
  else
     # echo "$1 is not a directory. Exiting."
     exit 2
  fi
fi

cd $Directory

description=""

if [ -r "description" ]
then 
  # echo "-----------------------------------------------------------"
  # echo "Description :"
  # cat description
  description=`cat description`
  # echo ""
  # echo "-----------------------------------------------------------"
fi

nTestCount=0
nSuccesfulTests=0
nStrResult="$1 "

if [ -r "run" ]
then
  sRun=`cat run`
else
  # echo "No run file found. Exiting."
  exit 2
fi

# stdin has been specified
if [ -r "std.in" ]
then 
  sRun="$sRun < std.in"
fi

# execute the command line
sortie=`eval $sRun` 

cd ..
# echo "$Directory;$description;$sortie"
echo "$Directory;$description;$sortie" >> $2

