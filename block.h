#ifndef BLOCK_H
#define BLOCK_H
#include <string>
#include <vector>
#include "transaction.h"
using namespace std;

class Block {
public:
    Block(vector<Transaction> transactions = vector<Transaction>());
    Block(vector<Transaction> transactions, Block previous_block);
    string calculate_hash(vector<Transaction> transactions, int height, string time_stamp);
    int get_height();
    string get_hash();
private:
    int _height;
    string _time_stamp;
    string _hash;
    string _previous_hash;
    vector<Transaction> _transactions;
};

#endif //BLOCK_H
