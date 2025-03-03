#include "blockchain.h"
#include "block.h"
#include <vector>
using namespace std;

Blockchain::Blockchain() {
    Block genesis_block;
    _chain.push_back(genesis_block);
}

void Blockchain::add_block(Block block) {
    _chain.push_back(block);
}

Block Blockchain::create_block(vector<Transaction> transactions, Block previous_block) {
    Block block(transactions,_chain.back());
    return block;
}

