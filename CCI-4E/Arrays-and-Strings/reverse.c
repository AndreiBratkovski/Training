//
// 1.2 Write code to reverse a C-style string.
//

void reverse(char *str) {
    char *end = str;
    char tmp;
    if (str) {
        while (*end) {
	    tmp = *str;
	    *str++ = *end;
	    *end-- = tmp;
	}
    }
}
