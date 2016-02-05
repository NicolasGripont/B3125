# echo "Performances :"

nOk=0
nKo=0
nTotal=0
nMis=0

echo "Test ID;Description;Nombre de figures;Secondes et microsecondes" > results.csv


for i in Test*
do
  ./test.sh $i results.csv
done
