#!/bin/bash

# Script to run the tests
#   ./test_runner.sh 0 [testname]_test     -> Run tests normally
#   ./test_runner.sh 1 [testname]_test     -> Run tests with valgrind

# if no test argument is provided, it will run all tests normally (./test_runner.sh 0) or with valgrind (./test_runner.sh 1)

# Argument checking
if [ $# -lt 1 ] || [ $# -gt 2 ]; then
    echo "Error: The number of arguments must be 1 or 2"
    exit 1
fi

valgrind="$1"
test="$2"

# Validate first argument
if [ "$valgrind" != "0" ] && ["$valgrind" != "1" ]; then
    echo "Error: The first argument must be 0 or 1"
    exit 1
fi

# Run all tests
if [ -z "$test" ]; then
    echo "Running all tests:"

    for test_file in src/*_test.c; do
        base_name=$(basename "$test_file" .c)

        echo "Compiling $base_name..."
        make "$base_name"

        echo "Executing $base_name..."
        if [ "$valgrind" -eq "1" ]; then
            valgrind --leak-check=full "./$base_name"
        else
            "./$base_name"
        fi
        echo
    done

# Run a specific test
else
    echo "Running $test:"
    make "$test"

    if [ "$valgrind" -eq "1" ]; then
        valgrind --leak-check=full "./$test"
    else
        "./$test"
    fi
fi

echo "--- ran successfully ---"
exit 0

