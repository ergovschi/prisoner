#!/bin/bash
echo "Preparing for execution"


# Empty the file genplay
cat /dev/null > genplay.cpp

echo "#include <iostream>" >> genplay.cpp
PLAYERS=prisoners/*
for p in $PLAYERS
do
    sed "3 a\
        #include \"$p\""  genplay.cpp
done

cat play.cpp >> genplay.cpp

g++ -o play.out play.cpp
./play.out

