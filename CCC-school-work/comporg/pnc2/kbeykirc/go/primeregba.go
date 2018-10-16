// prime number calculator
// 
// to compile, type: go build primeregba.go
// to run (after compiling): ./primeregba QTY
//	where QTY is the number of primes you want to calculate

package main

import "fmt"
import "os"
import "strconv"
import "time"

func main() {

	var qty int // quantity of primes to calculate
	var err error // for checking atoi down below

	// check arguments and make sure quantity is ok
	if len(os.Args) == 2 {
		qty, err = strconv.Atoi(os.Args[1])

		if err != nil {
			fmt.Fprintf(os.Stderr, "Error in string conversion!\n")
			os.Exit(4)
		}

		if qty < 0 {
			fmt.Fprintf(os.Stderr, "Quantity must be positive\n")
			os.Exit(1)
		}
	} else {
		fmt.Fprintf(os.Stderr, "USAGE: ./primeregba QTY\n")
		os.Exit(2)
	}

	start := time.Now() // begin timing

	num := 2 // numbers to check for primality
	factor := 2 // start checking factors at 2
	num_primes := 0 // how many primes have we found?
	prime := 1 // is a number prime or not 

	for num_primes < qty {
		// check factors up to square root of number
		for factor*factor <= num {
			// if factor divides evenly, num is composite
			if num%factor == 0 {
				prime = 0
				break
			}

			factor += 1 // go to next factor
		}
		// if a number is prime, print it and increment num_primes
		if prime == 1 {
			num_primes += 1
			fmt.Fprintf(os.Stderr, "%d ", num)
		} else {
			prime = 1
		}

		factor = 2 // restore to starting value
		num += 1 // go to next number
	}

	fmt.Fprintf(os.Stderr, "\n")

	end := time.Now() // end time 

	diff := end.Sub(start) // get elapsed time

	fmt.Fprintf(os.Stdout, "%8.4f\n", diff.Seconds())
}
