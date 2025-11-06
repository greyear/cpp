#!/bin/bash
# Run with: bash tests.sh
# Assumes your executable is named ./RPN

echo "✅ Running RPN tests..."

run_test() {
    input="$1"
    expected="$2"
    echo -n "Test: '$input' → Expected: $expected | Result: "
    output=$(./RPN "$input" 2>&1)
    if [ "$output" = "$expected" ]; then
        echo "✅ OK"
    else
        echo "❌ Got '$output'"
    fi
}

# --- Valid expressions ---
run_test "8 9 * 9 - 9 - 9 - 4 - 1 +" "42"
run_test "3 4 +" "7"
run_test "5 1 2 + 4 * + 3 -" "14"
run_test "2 3 *" "6"
run_test "9 3 /" "3"
run_test "5 2 -" "3"
run_test "0 1 -" "-1"

# --- Division by zero ---
run_test "4 0 /" "Error: division by zero!"

# --- Invalid token ---
run_test "2 a +" "Error: invalid token: a"
run_test "2 -1 +" "Error: invalid token: -1"
run_test "2 2 ^" "Error: invalid token: ^"

# --- Too few operands ---
run_test "3 +" "Error: invalid expression"

# --- Too few operators ---
run_test "3 3" "Error: invalid expression"

# --- Empty input ---
run_test "" "Error: invalid expression"
run_test " " "Error: invalid expression"

# --- Overflow test ---
run_test "2147483647 1 +" "Error: invalid token: 2147483647"

echo "✅ Done."
