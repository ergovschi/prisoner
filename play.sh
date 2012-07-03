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

echo "The found players are: "
I=0;
for p in $PLAYERS
do
    NAME=`echo $p| cut -c11- | sed 's/\([a-z]\)\([a-zA-Z0-9]*\)/\u\1\2/g' | sed 's/\.[^ ]*/ /g'`
    sed -i "$(($NUM_PLAYERS+$I+12)) a\
        [](){return new $NAME;},
    " genplay.cpp
    echo "  " $NAME
done

sed -i "$(($NUM_PLAYERS+$NUM_PLAYERS+14)) a\
    num_players = $NUM_PLAYERS;
" genplay.cpp


echo "Compiling... " 
g++ -std=c++0x -o play.out genplay.cpp

echo "Executing..."
./play.out

