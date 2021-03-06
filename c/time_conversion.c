#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

static const int A = 65;
// static const int a = 97;

static const int M = 77;
// static const int m = 109;

static const int P = 80;
// static const int p = 112;

char * removeAMPM(const char *s, const int originalLength){
    // len - 2 removes the AM part of the string
    const int trimmed_len = originalLength - 2;  
            
    // can I return a stack char[] into the char * ?
    char* res = (char *)malloc(trimmed_len * sizeof(char));

    strncpy(res, s, trimmed_len);
    
    return res;

}
char* timeConversion(char* s) {
    // Complete this function
    const int len = strlen(s);
    
    if(s[len-2] =='A'){
        char * res = removeAMPM(s, len);
        
        // special case is 12 AM
        if(s[1] == '2' && s[0] == '1'){
            // set the special case to midnight
            res[0]='0'; res[1] = '0';
            return res;
        }
        
        // for normal cases nothing needs to be done
        return res;
    }
    else if(s[len-2] == 'P'){
        char * res = removeAMPM(s, len);
        
        // 12 PM is special case -> nothing is done
        if(s[1] == '2' && s[0] == '1'){
            return res;
        }
        
        // need to add 12 to the clock
        // 2nd digit
        // 9 special case -> change to 1
        // 8 special case -> change to 0
        // others just add 2
        if(res[1] == '9'){
            res[1] = '1';
        }else if(res[1] == '8'){
            res[1] = '0';
        }else{
            res[1] += 2;
        }
        
        res[0]+=1;
        
        // 1st digit always add 1
        return res;
    }
    
    return "Invalid input";
}

int main() {
    char* s = (char *)malloc(512000 * sizeof(char));
    scanf("%s", s);
        int result_size;
char* result = timeConversion(s);
    printf("%s\n", result);
    return 0;
}

