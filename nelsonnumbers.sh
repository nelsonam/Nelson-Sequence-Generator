#!/bin/bash

#    Nelson Number Calculator
#    derived and programmed by Allison Nelson

#    calculates the drop down value in a Nelson sequence given a set of parameters:
#    s : the starting value in the second column of a Nelson sequence
#    n : the line number of the sequence that you are interested in
#    f : the first number on every line of your sequence (default 1)

#    now comes with "the unified theory", available for any starting value, not just 1!

echo ""
echo -n "Enter f (the number that will come first on every line): "
read f
echo -n "Enter s (the starting value for column two of the sequence): "
read s
echo -n "Lower bound on line numbers: "
read lb_n
echo -n "Upper bound on line numbers: "
read ub_n

echo ""
echo "-------------------"
echo "TABLE FOR F=$f S=$s"
echo "-------------------"
echo ""

for (( n=$lb_n; n<=$ub_n; n++)); do
    # checking for primes
    # now with even more timeconsuming brute force checks! :D
    num=$((2**n*(s+f)-f))
    prime=1;
    for (( j=2; j<$num; j++)); do
	if [ $((num % j)) -eq 0 ]; then
	    echo "$num";
	    prime=0;
	    break
	fi
    done
    if [ $prime -eq 1 ]; then
	echo "$num <--IS PRIME"
    fi
done
