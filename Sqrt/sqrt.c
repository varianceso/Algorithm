#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

float InvSqrt(float x){
    float xhalf = 0.5f*x;
    int i = *(int*)&x;      // get bits for floating VALUE 
    i = 0x5f375a86- (i>>1); // gives initial guess y0
    x = *(float*)&i; // convert bits BACK to float
    x = x*(1.5f-xhalf*x*x); // Newton step, repeating increases accuracy
    x = x*(1.5f-xhalf*x*x); // Newton step, repeating increases accuracy
    x = x*(1.5f-xhalf*x*x); // Newton step, repeating increases accuracy
return 1/x;
}

int main(){
    int x=0;
    scanf("%d",&x);
    printf("%f\n",1/InvSqrt(x));
return 0;
}
