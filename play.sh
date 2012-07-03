#!/bin/bash
echo "Preparing for execution"



# Empty the file genplay
cat /dev/null > genplay.cpp
cat play.cpp >> genplay.cpp

PLAYERS=prisoners/*

NUM_PLAYERS=${#PLAYERS[@]}
echo "There are $NUM_PLAYERS players..."
for p in $PLAYERS
do
    sed -i "5 a\
        #include \"$p\"
    " genplay.cpp
done

I=0;
for p in $PLAYERS
do
    NAME=`echo $p| cut -c11-`
    sed -i "$(($NUM_PLAYERS+$I+15)) a\
        [](){return new $NAME;},
    " genplay.cpp
done


echo "Compiling... " 
g++ -std=c++0x -o play.out genplay.cpp

echo "Executing..."
./play.out

