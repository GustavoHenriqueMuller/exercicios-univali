#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

//Primeira resposta
int Resposta1(){
    int s=5;
    int vetor[s];
    for(int i=0;i<s;i++){
        vetor[i]=i+1;
    }
    for(int i=4;i>=0;i--){
        cout<<vetor[i]<<" ";
    }
    return 0;
}
//Segunda resposta
int Resposta2(){
    int s=3;
    float vetor[s];
    float media=0;
    for(int i=0;i<s;i++){
        cout<<"Digite o valor real de indice "<<i<<" :\n";
        cin>>vetor[i];
    }
    for(int i=0;i<s;i++){
        media+=vetor[i];
    }
    media/=3;
    cout<<"A media dos 3 valores e : "<< media <<".";
    return 0;
}
//Terceira resposta
int Resposta3(){
    int a;
    int sum=0;
    vector<int> par;
    vector<int> impar;
    for(int i=0;i<10;i++){
        cout<<"Digite o elemento "<<i+1<<".\n";
        cin>>a;
        if(a%2==0){
            par.push_back(a);
        } else {
            impar.push_back(a);
        }
    }
    cout<<"\nVetor par :\n";
    for(int i=0;i<par.size();i++){
        cout<<"["<<par[i]<<"] ";
        sum+=par[i];
    }
    cout<<"\nVetor impar :\n";
    for(int i=0;i<impar.size();i++){
        cout<<"["<<impar[i]<<"] ";
        sum+=impar[i];
    }
    cout<<"\nSoma dos dois vetores e : "<<sum<<".\n";
    return 0;
}
//Quarta resposta
int Resposta4(){
    int s=5;
    int num;
    vector <int> vetor;
    for(int i=0;i<s;i++){
        cout<<"Digite o valor de indice "<<i<<" do vetor:\n";
        cin>>num;
        vetor.push_back(num);
    }
    sort(vetor.begin(),vetor.end());
    for(int i=0;i<s;i++){
        cout<<"["<<vetor[i]<<"] ";
    }
    return 0;
}

int main()
{
    cout<<"========================================\n";
    Resposta4();
    cout<<"\n========================================\n";
    return 0;
}
