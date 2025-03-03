#include "block.h"
#include "sha256.h"
#include <vector>
#include <string>
#include <ctime>
using namespace std;

Block::Block(vector<Transaction> transactions) {
    _height = 0;
    _time_stamp = std::to_string(time(nullptr));
    _previous_hash = "0";
    _transactions = transactions;
    _hash = calculate_hash(_transactions, _height, _time_stamp);
}
Block::Block(vector<Transaction> transactions, Block previous_block) {
    _height = previous_block.get_height() + 1;
    _transactions = transactions;
    _previous_hash = previous_block.get_hash();
    _time_stamp = std::to_string(time(nullptr));
    _hash = calculate_hash(_transactions,_height,_time_stamp);
}

string Block::calculate_hash(vector<Transaction> transactions, int height, string time_stamp) {
    SHA256 sha256;
    string hashes;
    for (int i = 0; i < transactions.size(); i++) {
        hashes += transactions[i].get_hash();
    }
    string hash_string = hashes + to_string(height) + time_stamp;
    string hash = sha256(hash_string);
    return hash;
}

int Block::get_height() {
    return _height;
}
string Block::get_hash() {
    return _hash;
}