package main
import "fmt"
import "os"
import "time"
import "strconv"

func main() {
var numberofprimes int
var err error

numberofprimes, err = strconv.Atoi(os.Args[1])
testednumber:=2
n:=0

if err != nil {
os.Exit(0)
}

start := time.Now()

for n < numberofprimes {
	m:=2
	for m<=testednumber{
		if m == testednumber{
			n++
			fmt.Fprintf(os.Stderr,"%d ", testednumber)
		}
		if testednumber%m==0 && testednumber !=2{
			break
		}
		m++
	}
	testednumber++
}
end := time.Now()
diff := end.Sub(start)
fmt.Fprintf(os.Stdout, "\n%8.4f\n", diff.Seconds())
}
