#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H
#include <vector>
#include "block.h"
using namespace std;

class Blockchain {
public:
    Blockchain();
    Block add_block(Block block);
    Block create_block();
    Block add_genesis_block();
private:
    vector<Block> chain;
};

#endif //BLOCKCHAIN_H