echo "Test ID;Return code validation;Out result;StdErr result;File creation result;Global result" >results.csv
nOk=0
nKo=0
nTotal=0
nMis=0

for i in TestO*
do
  ./test.sh $i results.csv
  result=$?
  if [ $result -eq 0 ]
  then
    let "nKo=$nKo+1"
  elif [ $result -eq 1 ]
  then
    let "nOk=$nOk+1"
  else
    let "nMis=$nMis+1"
  fi
  let "nTotal=$nTotal+1"
done

echo "Passed tests     : $nOk">>results.csv
echo "Failed tests     : $nKo">>results.csv
echo "Misformed tests  : $nMis">>results.csv
echo "-----------------------">>results.csv
echo "Total            : $nTotal">>results.csv
