#include <math.h>
#include <stdio.h>

int reverse(int x) {
    unsigned long long y, z, v;
    int r;
    int result = 0;
    int n[16];
    int m_flag = 0;
    int overflow_flag = 0;

    if (x<0) m_flag = 1;
    
    y = abs(x);
    
    int cnt;
    cnt = 0;
    while (1){
        v = y/10;
        r = y%10;
        n[cnt] = r;
        cnt ++;
        
        y = v;
        
        if (y==0) break;
    }
    
    int cnt1=0;
    z = 0;
    while (1){
        cnt--;
        z += n[cnt]*pow(10, cnt1);
        cnt1++;
        
        printf("z: %llu ", z);

        if (z > (2147483647L + (unsigned long long) m_flag)) {
            printf("overflow\n");
            overflow_flag = 1;
            break;
        }
        printf("\n");

        if (cnt == 0) break;
    }
    
    if (overflow_flag == 1){
        result = 0;
    }else {
        if (m_flag == 1) {
            result = -1 * (int) z;
        }else{
            result = (int) z;
        }
    }

    return result;
    
}

int main(int argc, char * argv[]){
    int z;
    z = reverse(321);
    printf("%d\n", z);

}