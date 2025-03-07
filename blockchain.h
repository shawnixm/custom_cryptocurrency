#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H
#include <vector>
#include "block.h"
using namespace std;

class Blockchain {
public:
    // Constructor
    Blockchain();

    // Wallet Generation
    void generate_wallet();

    // Setters
    void add_block(Block block);

    // Getters
    vector<Block> get_blocks();
    Block get_top_block();
    int get_blockchain_difficulty();
    void print_blockchain();
private:
    vector<Block> _chain;
    int _blockchain_difficulty;
};

#endif //BLOCKCHAIN_H