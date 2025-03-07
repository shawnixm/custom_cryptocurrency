#include "block.h"
#include "sha256.h"
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>
#include <iostream>
using namespace std;

// Constructors
// Create genesis block
Block::Block() {
    _height = 0;
    _time_stamp = std::to_string(time(nullptr));
    _previous_hash = "0";
    _transactions = {};
    _hash = "000000000019d6689c085ae165831e934ff763ae46a2a6c172b3f1b60a8ce26f";
    _nonce = 0;
    _difficulty = 0;
    _target = "";
}
// Create all other blocks
Block::Block(vector<Transaction> transactions, Block previous_block, int difficulty) {
    _height = previous_block.get_height() + 1;
    _previous_hash = previous_block.get_hash();
    _transactions = transactions;
    _difficulty = difficulty;
    int zero_count = difficulty / 4;
    _target = std::string(zero_count, '0') + std::string(64 - zero_count, 'f');
    _nonce = 0;
    _time_stamp = std::to_string(time(nullptr));
    _hash = mine_block();
}

// Hashing
string Block::calculate_hash(vector<Transaction> transactions) {
    SHA256 sha256;
    string hashes;
    for (int i = 0; i < transactions.size(); i++) {
        hashes += transactions[i].get_hash();
    }
    string hash_string = hashes + _previous_hash + _time_stamp + to_string(_nonce);
    string hash = sha256(hash_string);
    return hash;
}

// Helper
bool is_hash_valid(const std::string& hash, const std::string& target) {
    std::string hash_lower(hash);
    std::string target_lower(target);
    std::transform(hash_lower.begin(), hash_lower.end(), hash_lower.begin(), ::tolower);
    std::transform(target_lower.begin(), target_lower.end(), target_lower.begin(), ::tolower);

    return hash_lower <= target_lower;
}

// Setters
void Block::set_nonce(int nonce) {
    _nonce = nonce;
}

void Block::set_difficulty(int difficulty) {
    _difficulty = difficulty;
}

// Proof of Work
string Block::mine_block() {
    cout << "Mining block with difficulty " << _difficulty << endl;
    string hash_value;
    while (true) {
        hash_value = calculate_hash(_transactions);
        if(is_hash_valid(hash_value, _target)) {
            std::cout << "Block mined! Nonce: " << _nonce << std::endl;
            break;
        }
        _nonce++;
    }
    return hash_value;
}

// Getters
int Block::get_height() {
    return _height;
}
string Block::get_hash() {
    return _hash;
}

int Block::get_nonce() {
    return _nonce;
}

int Block::get_difficulty() {
    return _difficulty;
}