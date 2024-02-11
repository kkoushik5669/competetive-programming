const int N = 3e5 + 9;
struct VeniceSet {
    multiset<int> S;
    int water_level = 0;
    void add(int v) {
        S.insert(v + water_level);
    }
    void remove(int v) {
        S.erase(S.find(v + water_level));
    }
    void updateAll(int v) {
        water_level += v;
    }
    int getMin() {
        return *S.begin() - water_level;
    }
    int size() {
        return S.size();
    }
};
