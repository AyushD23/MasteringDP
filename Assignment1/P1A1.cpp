#include <bits/stdc++.h>

using namespace std;

unordered_map<int, int> inv;
unordered_map<int, double> cp;
unordered_map<int, double> sp;

vector<string> logs;
vector<int> cids;
vector<int> pids;
vector<int> qtys;
vector<double> amts;

double cash = 0.0;
double debt = 0.0;
double net = 0.0;

struct Item {
    int idx;
    int pid;
    int q;
    double val;
    double cost;
    double ratio;
};

bool cmp(const Item& a, const Item& b) {
    return a.ratio > b.ratio;
}

void log(string t, int c, int p, int q, double a) {
    logs.push_back(t);
    cids.push_back(c);
    pids.push_back(p);
    qtys.push_back(q);
    amts.push_back(a);
}

double calc(int p, int q) {
    if (sp.find(p) == sp.end()) {
        return 0.0;
    }
    return sp[p] * q;
}

vector<int> solve(int c, double b, vector<int>& ps, vector<int>& qs, vector<double>& vs) {
    int n = ps.size();
    vector<Item> items(n);
    
    for (int i = 0; i < n; i++) {
        double cost = calc(ps[i], qs[i]);
        items[i].idx = i;
        items[i].pid = ps[i];
        items[i].q = qs[i];
        items[i].val = vs[i];
        items[i].cost = cost;
        if (cost > 0) {
            items[i].ratio = vs[i] / cost;
        } else {
            items[i].ratio = 0.0;
        }
    }
    
    sort(items.begin(), items.end(), cmp);
    
    vector<int> res;
    double rem = b;
    
    for (int i = 0; i < n; i++) {
        if (items[i].cost <= rem) {
            res.push_back(items[i].idx);
            rem = rem - items[i].cost;
        }
    }
    
    return res;
}

bool proc(int p, int q, int c) {
    if (sp.find(p) == sp.end()) {
        return false;
    }
    
    double amt = sp[p] * q;
    
    if (inv[p] < q) {
        int need = q - inv[p];
        double rcost = need * cp[p];
        
        if (cash >= rcost) {
            cash = cash - rcost;
            inv[p] = inv[p] + need;
            log("RESTOCK", -1, p, need, rcost);
        } else {
            debt = debt + rcost;
            inv[p] = inv[p] + need;
            log("LOAN", -1, p, need, rcost);
        }
    }
    
    inv[p] = inv[p] - q;
    cash = cash + amt;
    double prof = amt - (q * cp[p]);
    net = net + prof;
    
    log("SALE", c, p, q, amt);
    return true;
}

void handle(int c, double b, vector<int>& ps, vector<int>& qs, vector<double>& vs) {
    cout << "\n=== Customer " << c << " ===\n";
    cout << "Budget: Rs." << fixed << setprecision(2) << b << endl;
    cout << "Queries: " << ps.size() << endl;
    
    vector<int> sel = solve(c, b, ps, qs, vs);
    
    cout << "Selected: ";
    double tcost = 0.0;
    double tval = 0.0;
    
    for (int i : sel) {
        int p = ps[i];
        int q = qs[i];
        double v = vs[i];
        
        cout << "(" << p << "," << q << ") ";
        
        if (proc(p, q, c)) {
            tcost = tcost + calc(p, q);
            tval = tval + v;
        }
    }
    
    cout << "\nCost: Rs." << tcost << endl;
    cout << "Value: " << tval << endl;
}

void close() {
    cout << "\n=== End Day ===\n";
    
    if (debt > 0) {
        double interest = debt * 0.10;
        double total = debt + interest;
        
        log("REPAY", -1, -1, 0, total);
        cash = cash - total;
        net = net - interest;
        
        cout << "Repay: Rs." << fixed << setprecision(2) << total << endl;
        cout << "Interest: Rs." << interest << endl;
    }
    
    cout << "Cash: Rs." << cash << endl;
    cout << "Net: Rs." << net << endl;
}

void showLog() {
    cout << "\n=== Log ===\n";
    cout << left << setw(12) << "Type" << setw(8) << "Cust" 
         << setw(8) << "Prod" << setw(8) << "Qty" 
         << setw(10) << "Amt" << endl;
    
    for (int i = 0; i < 50; i++) cout << "-";
    cout << endl;
    
    for (int i = 0; i < logs.size(); i++) {
        cout << left << setw(12) << logs[i];
        
        if (cids[i] != -1) {
            cout << setw(8) << cids[i];
        } else {
            cout << setw(8) << "-";
        }
        
        if (pids[i] != -1) {
            cout << setw(8) << pids[i];
        } else {
            cout << setw(8) << "-";
        }
        
        if (qtys[i] != 0) {
            cout << setw(8) << qtys[i];
        } else {
            cout << setw(8) << "-";
        }
        
        cout << setw(10) << fixed << setprecision(2) << amts[i] << endl;
    }
}

void showInv() {
    cout << "\n=== Inventory ===\n";
    cout << left << setw(8) << "ID" << setw(8) << "Stock" 
         << setw(10) << "Cost" << setw(10) << "Price" << endl;
    
    for (int i = 0; i < 40; i++) cout << "-";
    cout << endl;
    
    for (auto& x : inv) {
        int id = x.first;
        int stock = x.second;
        double cost = cp[id];
        double price = sp[id];
        
        cout << left << setw(8) << id << setw(8) << stock
             << setw(10) << fixed << setprecision(2) << cost
             << setw(10) << price << endl;
    }
}

void init(double m) {
    cash = m;
    debt = 0.0;
    net = 0.0;
    
    inv.clear();
    cp.clear();
    sp.clear();
    logs.clear();
    cids.clear();
    pids.clear();
    qtys.clear();
    amts.clear();
}

void add(int id, int stock, double cost, double price) {
    inv[id] = stock;
    cp[id] = cost;
    sp[id] = price;
}

int main() {
    init(1000.0);
    
    add(1, 50, 10.0, 15.0);
    add(2, 30, 20.0, 35.0);
    add(3, 20, 5.0, 8.0);
    
    vector<int> c1p = {1, 2, 3};
    vector<int> c1q = {5, 2, 10};
    vector<double> c1v = {25.0, 40.0, 15.0};
    
    vector<int> c2p = {1, 2, 3};
    vector<int> c2q = {10, 3, 5};
    vector<double> c2v = {50.0, 60.0, 12.0};
    
    vector<int> c3p = {1, 2};
    vector<int> c3q = {60, 10};
    vector<double> c3v = {200.0, 150.0};
    
    cout << "=== Shop Sim ===\n";
    showInv();
    
    handle(1, 100.0, c1p, c1q, c1v);
    handle(2, 150.0, c2p, c2q, c2v);
    handle(3, 200.0, c3p, c3q, c3v);
    
    close();
    showLog();
    showInv();
    
    return 0;
}
