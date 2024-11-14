#include<bits/stdc++.h>
using namespace std;

struct Activity{
    int start;
    int finish;
};

bool Cmp(Activity a, Activity b){
    return a.finish < b.finish;
}

vector<Activity> SelectActivity(vector<Activity>& act){
    sort(act.begin(),act.end(),Cmp);
    vector<Activity> selectedAct;

    selectedAct.push_back(act[0]);

    for(int i=1;i<act.size();i++){
        if(act[i].start >= selectedAct.back().finish){
            selectedAct.push_back(act[i]);
        }
    }

    return selectedAct;
}

int main() {
    vector<Activity> activities = {{1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}, {5, 9}};
    vector<Activity> result = SelectActivity(activities);
    
    for (auto activity : result) {
        cout << "Activity: (" << activity.start << ", " << activity.finish << ")" << endl;
    }
    
    return 0;
}