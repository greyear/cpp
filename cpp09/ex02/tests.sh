#!/bin/bash

for i in {1..10}
do
    num_elements=$((RANDOM % 100 + 1))
    max_element=$(shuf -i 1-10000 -n 1)
    args=$(shuf -i 1-$max_element -n $num_elements | tr "\n" " ")

    echo "Test $i: ./PmergeMe with $num_elements elements"
    ./PmergeMe $args
    echo ""
done

echo "Test 11: small number of elements"
./PmergeMe 5 3 9 1 2 8
echo ""

echo "Test 12: already sorted input"
seq 1 100 | ./PmergeMe $(tr "\n" " ")
echo ""

echo "Test 13: reverse sorted input"
seq 100 -1 1 | ./PmergeMe $(tr "\n" " ")
echo ""

#echo "Test 14: large random input"
#./PmergeMe $(shuf -i 1-100000 -n 10000 | tr "\n" " ")
#echo ""
echo "All tests completed."
