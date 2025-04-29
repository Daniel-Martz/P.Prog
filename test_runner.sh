bash

#!/bin/bash

# Script to run the tests
# ./test_runner.sh 0/1 [testname]_test

valgrind="$1"
test="$2"
TESTS=$(ls src/*_test.c)


#Checking the number of arguments
if [ $# -lt 1 ] || [ $# -gt 2 ]; then
    echo "Error, the number of arguments must be 1 or 2"
    exit 1
fi

#Checking if the first argument is 0 or 1
if [ "$valgrind" != "1" ] && [ "$valgrind" != "0" ]; then
    echo "Error, the first argument must be 0 or 1"
    exit 1
fi


#Running all tests
if [ -z "$test" ]; then

    if [ "$valgrind" -eq 0 ]; then 
        echo "Running all tests:"

        for test_file in $TESTS
        do
            base_name=$(basename "$test_file" .c)
            prefix=${base_name%_test}
            test_name="test${prefix}" 

            # Compile each test
            make "$test_name"

            # Execute the test
            echo "Executing $test_name..."
            ./"$test_name"

        done

    else
        echo "Running all tests with valgrind:"

        for test_file in $TESTS
        do
            base_name=$(basename "$test_file" .c)
            prefix=${base_name%_test}
            test_name="test${prefix}" 

            # Compile each test
            make "$test_name"

            # Execute the test
            echo "Executing $test_name..."
            valgrind --leak-check=full ./"$test_name"

        done

    
    fi

#Running the given test
else

    prefix=${test%_test}
    test_name="test${prefix}" 

    if [ "$valgrind" -eq 0 ]; then 
        echo "Running $test:"
        make "$test_name"
        ./$test_name

        

    else
        echo "Running $test with valgrind:"
        make "$test_name"
        valgrind --leak-check=full ./$test_name
    
    fi



fi

echo "--- runned with success ---"

exit 0
