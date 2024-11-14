#include<bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};

bool Cmp(Item a, Item b){
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double Knapsack(int w, vector<Item>& itms){
    sort(itms.begin(), itms.end(), Cmp);

    double TotalValue = 0.0;
    int CurrentWeight = w;

    for(int i = 0; i < itms.size(); i++){
        if(itms[i].weight <= CurrentWeight){
            TotalValue += itms[i].value;
            CurrentWeight -= itms[i].weight;
        } else {
            TotalValue += itms[i].value * ((double)CurrentWeight / itms[i].weight);
            break;
        }
    }

    return TotalValue;
}

int main(){
    vector<Item> itms = {{60, 10}, {100, 20}, {120, 30}};
    int W = 50;

    cout << "Maximum value: " << Knapsack(W, itms) << endl;
    return 0;
}
