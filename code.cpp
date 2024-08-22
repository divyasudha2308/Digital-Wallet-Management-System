#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findUserIndex(const vector<pair<int,int>>& accounts, int userID) {
    for(int index = 0; index < (int)accounts.size(); ++index) {
        if(accounts[index].first == userID)
            return index;
    }
    return -1;
}

bool balanceComparison(const pair<int,int>& user1, const pair<int,int>& user2) {
    if(user1.second == user2.second)
        return user1.first < user2.first;
    return user1.second < user2.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int numAccounts;
    cin >> numAccounts;
    vector<pair<int,int>> accounts(numAccounts);
    
    for(int i = 0; i < numAccounts; ++i) {
        int accountID, balance;
        cin >> accountID >> balance;
        accounts[i] = {accountID, balance};
    }
    
    int numTransactions;
    cin >> numTransactions;
    vector<string> transactionStatus;
    
    while(numTransactions--) {
        int senderID, receiverID, amount;
        cin >> senderID >> receiverID >> amount;
        
        int senderIndex = findUserIndex(accounts, senderID);
        int receiverIndex = findUserIndex(accounts, receiverID);
        
        if(senderIndex != -1 && receiverIndex != -1 && accounts[senderIndex].second >= amount) {
            accounts[senderIndex].second -= amount;
            accounts[receiverIndex].second += amount;
            transactionStatus.push_back("Success");
        } else {
            transactionStatus.push_back("Failure");
        }
    }
    
    for(const auto& result : transactionStatus)
        cout << result << endl;
    cout << endl;
    
    sort(accounts.begin(), accounts.end(), balanceComparison);
    
    for(const auto& account : accounts)
        cout << account.first << " " << account.second << endl;
    
    return 0;
}
