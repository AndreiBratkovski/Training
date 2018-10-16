package main

import "fmt"
import "os"
import "time"
import "math"
import "strconv"

func main() {

	var err     error
	var upBound int
	upBound, err = strconv.Atoi(os.Args[1])
	if err != nil{
		fmt.Print(err)
	}

	start := time.Now()

	num   := 2
	i     := 3
	divBy := 2

	fmt.Fprintf(os.Stderr, "2 3 ")


	for num!=upBound{

		mod := i%divBy
		sqt := math.Sqrt(float64(i))

		if mod!=0{
			if divBy!=int(sqt){
				divBy+=1
			} else if divBy == int(sqt){
				fmt.Fprintf(os.Stderr, "%d ", i)
				i+=1
				num+=1
				divBy=2
			}else{
				fmt.Fprintf(os.Stderr, "%d ", i)
				i+=1
				num+=1
				divBy=2
			}
		} else{
			i+=1
			divBy=2
		}

	}


	end := time.Now()


	elapsed := end.Sub(start)
	tm := float64(elapsed) / float64(time.Second)

	fmt.Fprintf(os.Stdout, "%8.4f\n", tm)
}
