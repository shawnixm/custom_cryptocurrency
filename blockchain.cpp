#include "blockchain.h"
#include "block.h"
#include <vector>
using namespace std;

// Constructor
Blockchain::Blockchain() {
    Block genesis_block;
    _blockchain_difficulty = 20; // Limit: 0 -> 256
    genesis_block.set_difficulty(_blockchain_difficulty);
    _chain.push_back(genesis_block);
}

// Setters
void Blockchain::add_block(Block block) {
    _chain.push_back(block);
}

// Getters
vector<Block> Blockchain::get_blocks() {
    return _chain;
}

Block Blockchain::get_top_block() {
    return _chain.back();
}

int Blockchain::get_blockchain_difficulty() {
    return _blockchain_difficulty;
}
