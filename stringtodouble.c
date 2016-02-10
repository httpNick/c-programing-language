//
// Created by Nick Duncan on 2/9/16.
// Exercise 4-2 include scientific notation conversion.
//
#include <ctype.h>
#include <stdio.h>

int main() {
    double convertToDouble(char[]);
    double t = convertToDouble("123.45e-6");
    printf("%f", t);
}

double convertToDouble(char s[]) {

    double val, power;
    int i, sign, sciSign;
    // skips initial whitespace of s[]
    for (i = 0; isspace(s[i]); i++);

    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;

    for(val = 0.0; isdigit(s[i]); i++) {
        // subtract by '0' since it is the first integer ascii character.
        int valOfChar = s[i] - '0';
        val = 10.0 * val + valOfChar;
    }

    if (s[i] == '.')
        i++;

    for (power = 1.0; isdigit(s[i]); i++) {
        int valOfChar = (s[i] - '0');
        val = 10.0 * val + valOfChar;
        power *= 10.0;
    }
    double res = sign * val / power;
    /* scientific notation region */
    if (s[i] == 'e' || s[i] == 'E') {
        i++;
        sciSign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-')
            i++;
        double sciVal;
        for(sciVal = 0.0; isdigit(s[i]); i++) {
            sciVal = 10.0 * sciVal + (s[i] - '0');
        }
        while(sciVal > 0) {
            if (sciSign == -1) {
                res /= 10.0;
            } else {
                res *= 10.0;
            }
            sciVal--;
        }
    }

    return res;
}