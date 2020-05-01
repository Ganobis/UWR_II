#!/bin/bash

TESTS=$1
MAXF=$2
MAXC=$3
MAXP=$4

COUNT=1

while (( "$COUNT" <= "$TESTS" )); do
    ./gen $MAXF $MAXC $MAXP > test.in
    ./solution < test.in > test.out
    cat test.in > tested.in
    ./tested < test.in >> tested.in
    ./verify < tested.in > tested.out
    if [ $? -eq 1 ]; then
        echo "$(<tested.out)"
        break
    fi
    cat test.in > solution.in
    ./solution < test.in >> solution.in
    ./verify < solution.in > solution.out
    if [ $? -eq 1 ]; then
        echo "Wzorcówka nie działa?"
        echo "Proszę o dostarczenie mi pliku test.in"
        break
    fi
    OK=$(diff -q tested.out solution.out)
    if [ -z "$OK" ]
    then
        echo "Test $COUNT OK"
    else
        echo "ZŁA ODPOWIEDŹ"
        echo "PORÓWNAJ PLIKI tested.out I solution.out"
        break
    fi
    COUNT=$((COUNT+1))
done
