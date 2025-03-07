#include "blockchain.h"
#include "block.h"
#include <vector>
#include "sha256.h"
#include <fstream>
#include <string>
#include <random>
#include <iostream>
#include <sstream>
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

// Wallet Generation (Simplified / Unsecure) (ECC used in BTC)
// Helper function to generate a random private or public key
string generateKey() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 255);

    std::stringstream ss;
    for (int i = 0; i < 32; ++i) {
        ss << std::hex << std::setw(2) << std::setfill('0') << distrib(gen);
    }
    return ss.str();
}

void Blockchain::generate_wallet() {
    SHA256 sha256;
    string private_key = sha256(generateKey());
    string public_key = sha256(generateKey());
    ofstream wallet_file;
    wallet_file.open("wallet.txt");
    wallet_file << "Private key: " << private_key << endl;
    wallet_file << "Public Key: " << public_key << endl;
    wallet_file.close();
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
