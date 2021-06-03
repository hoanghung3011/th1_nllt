#include <iostream>

using namespace std;

void input(int &n, int &m, int &k, char (&ListPerson)[100], int (&bottleList)[100]) {
    cout<<"\n N=";
    cin>>n;
    cout<<"\n M=";
    cin>>m;
    cout<<"\n K=";
    cin>>k;

    for(int i=0; i<n; i++)
        cin>>ListPerson[i];
    
    for(int i=0; i<m; i++)
        cin>>bottleList[i];
}

void output(int n, int m, int k, char ListPerson[100], int bottleList[100]) {
    cout<<"\n N=";
    cout<<n;
    cout<<"\n M=";
    cout<<m;
    cout<<"\n K=";
    cout<<k;

    cout<<"\n";
    for(int i=0; i<n; i++)
        cout<<ListPerson[i]<<"\t";
    cout<<"\n";
    for(int i=0; i<m; i++)
        cout<<bottleList[i]<<"\t";
}


void solver(int n, int m, int k, char ListPerson[100], int bottleList[100]) {
    int result[100];
    for (int i=n-1; i>-1; i--) {
        int found = 0;
        for (int j=m-1; j>-1; j--) {
            if (ListPerson[i] == 'E' && found == 0) {
                if(bottleList[j] < k) {
                    bottleList[j]++;
                    result[i]=j;
                    found=1;
                }
            }

            
            if (ListPerson[i] == 'W' && found == 0) {
                if (bottleList[j] == k-1 && bottleList[j] < k) {
                    bottleList[j]++;
                    result[i]=j;
                    found=1;
                }

                if (j==0 && found==0) {
                    cout<<"error: khong tim duoc ket qua";
                    exit(0);
                }
            }   
        }
    }
    cout<<"\n";
    for(int i=0; i<n; i++)
        cout<<result[i]+1<<"\t";
}

int main() {
    int n=5, m=5, k=2;
    char listPerson[100] = {'E','E','W','W','E'};
    int bottleList[100] = {1,2,0,2,0};
    // input(n, m, k, listPerson, bottleList);
    output(n, m, k, listPerson, bottleList);
    cout<<"\n";
    cout<<"dap an:";
    cout<<"\n";
    solver(n, m, k, listPerson, bottleList);
    return 1;
}