#iclude <signal.lh>
#include <stdio.h>
#iclude <unistd.h>

void handlesignal(int signal){
    printf("jajasjasa no me matas xd\n");
}

int main(){
    signal(2,handlesignal);
    while(1){
        printf("trabajando\n");
        sleep(1);
    }


    return 0;
}