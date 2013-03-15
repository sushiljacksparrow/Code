
#include<iostream>
using namespace std;
int n;
unsigned int arr[100][100];

void rotate() {

    int i,j,temp;

    for(i=0; i<n; i++) {
        for(j=i; j<n; j++) {
            if(i!=j) {
                //arr[i][j]^=arr[j][i];
                //arr[j][i]^=arr[i][j];
                //arr[i][j]^=arr[j][i];
                swap(arr[i][j], arr[j][i]);
            }
        }
    }


    for(i=0; i<n/2; i++) {
        for(j=0; j<n; j++) {
			swap(arr[j][n-i-1], arr[j][i]);
            //arr[j][i]^=arr[j][n-1-i];
            //arr[j][n-1-i]^=arr[j][i];
            //arr[j][i]^=arr[j][n-1-i];
        }
    }

}

void display(){

    int i,j;

    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            printf("%d ",arr[i][j]);}
            printf("%s","\n");
        }
    }

    int main(int argc, char *argv[]){

    int i,j;

    printf("%s","Enter size of matrix:");
    scanf("%d",&n);

    printf("%s","Enter matrix elements\n");

    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            scanf("%d",&arr[i][j]);
        }
    }

    rotate();
    display();

    system("pause");
}
