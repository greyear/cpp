#!/bin/bash

check_sorted() {
    after_line=$(grep "^After" <<< "$1" | head -n 1 | sed 's/After:\t//')
    echo "$after_line" | awk '
    {
        prev = $1
        for (i = 2; i <= NF; i++) {
            if ($i < prev) {
                print "❌ Not sorted! First disorder:", prev, ">", $i
                exit 1
            }
            prev = $i
        }
        print "✅ Sorted OK"
    }'
}

for i in {1..10}
do
    num_elements=$((RANDOM % 100 + 1))
    max_element=$(shuf -i 1-10000 -n 1)
    args=$(shuf -i 1-$max_element -n $num_elements | tr "\n" " ")

    echo "Test $i: ./PmergeMe with $num_elements elements"
    output=$(./PmergeMe $args)
    echo "$output"
    check_sorted "$output"
    echo ""
done

echo "Test 11: small number of elements"
output=$(./PmergeMe 5 3 9 1 2 8)
echo "$output"
check_sorted "$output"
echo ""

echo "Test 12: duplicates"
output=$(./PmergeMe 10 5 5 5 5 5 5 5)
echo "$output"
check_sorted "$output"
echo ""

echo "Test 13: already sorted input"
output=$(seq 1 100 | ./PmergeMe $(tr "\n" " "))
echo "$output"
check_sorted "$output"
echo ""

echo "Test 14: reverse sorted input"
output=$(seq 100 -1 1 | ./PmergeMe $(tr "\n" " "))
echo "$output"
check_sorted "$output"
echo ""

#echo "Test 15: large random input"
#output=$(./PmergeMe $(shuf -i 1-100000 -n 10000 | tr "\n" " "))
#echo "$output"
#check_sorted "$output"
#echo ""
echo "All tests completed."
