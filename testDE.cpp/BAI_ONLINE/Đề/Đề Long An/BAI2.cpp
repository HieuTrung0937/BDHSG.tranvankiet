#include <bits/stdc++.h>
using namespace std;
#define TASK "BAI2"
class Student {
private:
    long long id;
    int firstPos;
    int lastPos;

public:
    Student(long long _id, int pos): id(_id), firstPos(pos), lastPos(pos) {}

    void update(int pos) {
        lastPos = pos;
    }

    long long getId() const {
        return id;
    }

    int readingTime() const {
        return lastPos - firstPos;
    }

    int getFirstPos() const {
        return firstPos;
    }
}; 
class TimelineSystem {
private:
    unordered_map<long long, Student> mp;

public:
    void addScan(int id, int time) {
        auto it = mp.find(id);
        if (mp.find(id) == mp.end()) {
            mp.emplace(id, Student(id, time));
        } else {
            it -> second.update(time);
        }
    }

    pair<long long, int> getBestStudent() {
        long long bestId = -1;
        int bestTime = -1;
        int bestFirstPos = INT_MAX;

        for (auto &p : mp) {
            Student &st = p.second;
            int t = st.readingTime();

            if (t > bestTime ||(t == bestTime && st.getFirstPos() < bestFirstPos)) {
                bestTime = t;
                bestId = st.getId();
                bestFirstPos = st.getFirstPos();
            }
        }
        return {bestId, bestTime};
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    // clock_t timer1, timer2;
    // timer1 = clock();
    int N; cin>> N;//cout<<N;
    vector<int> ID(N + 1);
    for(int i = 1; i<N; i++) cin>>ID[i];
    TimelineSystem ThoiGian;
    for(int i  = 1; i < N; i++)
    {
        ThoiGian.addScan(ID[i],i);
    }
    pair<int, int> ketqua = ThoiGian.getBestStudent();
    cout<<ketqua.first<<"\n"<<ketqua.second;
    // timer2 = clock();
    // cout<<(double)(timer2 - timer1);
    // cout<<"\n";
    // for(int i : ID)
    // {
    //     cout<<i<<" ";
    // }
    // return 0;
}
