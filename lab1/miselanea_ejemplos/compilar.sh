#! /bin/bash

search_dir=$PWD/sources/
bin_dir=$PWD/bin/


for file in $search_dir/*.c; do
  echo $file
done

echo "COMPILANDO ARCHIVOS... \n"
for file in $search_dir*.c; do
  #echo "Compilando $file"
  echo "gcc -Wall $file -o ${file%.c}.out"
  gcc -Wall $file -o ${file%.c}.out
done

echo "GENERANDO CARPETA BIN...\n"
echo "mkdir $bin_dir"
mkdir $bin_dir


echo "MOVIENDO LOS EJECUTABLES A BIN...\n"
for file in $search_dir*.out; do
  filename=$(basename -- "$file")
  mv $file $bin_dir
done

echo "HASTA LA VISTA BABY YESUS..."
