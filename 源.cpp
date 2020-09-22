#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        if (target == "0000")return 0;
        unordered_map<string,int>um;
        for (string i : deadends)um[i]++;
        if (um["0000"])return -1;
        vector<string>pre,cur;
        pre.push_back("0000");
        vector<bool>visited(10000,false);
        visited[0] = true;
        int ans = 0;
        while (!pre.empty()) {
            ans++;
            for (string i : pre) {                
                string temp="";
                if (i[0] == '9')temp = "0";
                else temp = to_string(i[0]-'0' + 1);                
                string next = temp + i.substr(1);                
                if (um[next] == 0 && !visited[stoi(next)]) {
                    if (next == target)return ans;
                    visited[stoi(next)] = true;
                    cur.push_back(next);
                }
                if (i[0] == '0')temp = "9";
                else temp = to_string(i[0] - '0' - 1);
                next = temp + i.substr(1);
                if (um[next] == 0 && !visited[stoi(next)]) {
                    if (next == target)return ans;
                    visited[stoi(next)] = true;
                    cur.push_back(next);
                }
                if (i[1] == '9')temp = "0";
                else temp = to_string(i[1] - '0' + 1);
                next = i.substr(0,1)+temp + i.substr(2);
                if (um[next] == 0 && !visited[stoi(next)]) {
                    if (next == target)return ans;
                    visited[stoi(next)] = true;
                    cur.push_back(next);
                }
                if (i[1] == '0')temp = "9";
                else temp = to_string(i[1] - '0' - 1);
                next = i.substr(0, 1) + temp + i.substr(2);
                if (um[next] == 0 && !visited[stoi(next)]) {
                    if (next == target)return ans;
                    visited[stoi(next)] = true;
                    cur.push_back(next);
                }
                if (i[2] == '9')temp = "0";
                else temp = to_string(i[2] - '0' + 1);
                next = i.substr(0, 2) + temp + i.substr(3);
                if (um[next] == 0 && !visited[stoi(next)]) {
                    if (next == target)return ans;
                    visited[stoi(next)] = true;
                    cur.push_back(next);
                }
                if (i[2] == '0')temp = "9";
                else temp = to_string(i[2] - '0' - 1);
                next = i.substr(0, 2) + temp + i.substr(3);
                if (um[next] == 0 && !visited[stoi(next)]) {
                    if (next == target)return ans;
                    visited[stoi(next)] = true;
                    cur.push_back(next);
                }
                if (i[3] == '9')temp = "0";
                else temp = to_string(i[3] - '0' + 1);
                next = i.substr(0, 3) + temp ;
                if (um[next] == 0 && !visited[stoi(next)]) {
                    if (next == target)return ans;
                    visited[stoi(next)] = true;
                    cur.push_back(next);
                }
                if (i[3] == '0')temp = "9";
                else temp = to_string(i[3] - '0' - 1);
                next = i.substr(0, 3) + temp ;
                if (um[next] == 0 && !visited[stoi(next)]) {
                    if (next == target)return ans;
                    visited[stoi(next)] = true;
                    cur.push_back(next);
                }
            }
            pre = cur;
            cur.clear();
        }
        if (pre.empty())return -1;
        return -1;
    }
};
int main() {
    Solution sol;
    vector<string>deadends = { "0201","0101","0102","1212","2002"};
    string target = "0202";
    
    cout << sol.openLock(deadends, target);

    return 0;
}