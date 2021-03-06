#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

static int ten(int n){
    int m=1;
    for(int i=1;i<=n;i++){
        m=m*10;
    }
return m;
}

/*只转换整数*/
static char* num_to_char(int num){
    int count=0;
    char sign='+';
    if(num<0){
        sign='-';
        num=0-num;
    }
    int value=num;
    if(0<=num && num<10){
        count=1;
    }else{
        while(value){
            value=value/10;
            count++;
        }
    }
    char* res=(char*)malloc(sizeof(char)*(count+1));
    int k=1;
    int base=1;
    res[0]=sign;
    for(int i=1;i<=count;i++){
        k=ten(count-i);
        base=num/k;
        res[i]=(char)(base+'0');
        num=num-k*base;
    }
return res;
}

static char* num_to_char2(int num){
    int count=0;
    int value=num;
    if(0<=num && num<10){
        count=1;
    }else{
        while(value){
            value=value/10;
            count++;
        }
    }
    char* res=(char*)malloc(sizeof(char)*(count));
    int k=1;
    int base=1;
    for(int i=0;i<count;i++){
        k=ten(count-1-i);
        base=num/k;
        res[i]=(char)(base+'0');
        num=num-k*base;
    }
return res;
}

int main(){
    int a=3;
    char* res=num_to_char2(a);
    char* temp=res;
    while(*temp){
        printf("%c",*temp);
        temp++;
    }
    printf("\n");
    free(res);
return 0;
}
