#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H
#include <vector>
#include "block.h"
using namespace std;

class Blockchain {
public:
    Blockchain();
    void add_block(Block block);
    Block create_block(vector<Transaction> transactions, Block previous_block);
    vector<Block> get_blocks();
private:
    vector<Block> _chain;
};

#endif //BLOCKCHAIN_H