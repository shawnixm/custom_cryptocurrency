#ifndef BLOCK_H
#define BLOCK_H
#include <string>
#include <vector>
#include "transaction.h"
using namespace std;

class Block {
public:
    // Constructors
    Block();
    Block(vector<Transaction> transactions, Block previous_block, int difficulty);

    // Hashing
    string calculate_hash(vector<Transaction> transactions);

    // Setters
    void set_nonce(int nonce);
    void set_difficulty(int difficulty);

    // Proof of Work
    string mine_block();

    // Getters
    int get_height();
    string get_hash();
    int get_nonce();
    int get_difficulty();
    vector<Transaction> get_transactions();
    string get_previous_hash();
    string get_timestamp();
private:
    int _height;
    string _time_stamp;
    string _hash;
    string _previous_hash;
    vector<Transaction> _transactions;
    int _nonce;
    int _difficulty;
    string _target;
};

#endif //BLOCK_H
