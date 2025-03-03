#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <string>
using namespace std;

class Transaction {
public:
    Transaction(string sender, string receiver, string amount);
    string calculate_hash(string sender, string receiver, string amount, string time_stamp);
    string get_hash();
private:
    string _sender;
    string _receiver;
    string _amount;
    string _time_stamp;
    string _hash;
};
#endif //TRANSACTION_H
