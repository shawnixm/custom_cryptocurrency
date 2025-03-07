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

// Consensus Mechanism (Longest Chain)
Blockchain Blockchain::resolve_conflicts(Blockchain blockchain1, Blockchain blockchain2) {
    if (blockchain1.get_blocks().size() >= blockchain2.get_blocks().size()) {
        return blockchain1;
    } else {
        return blockchain2;
    }
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

void Blockchain::print_blockchain() {
    for (int i = 0; i < _chain.size(); ++i) {
        cout << "Height: " << _chain[i].get_height() << endl;
        cout << "Hash: " << _chain[i].get_hash() <<endl;
        cout << "Hash of previous block: " << _chain[i].get_previous_hash() << endl;
        cout << "Timestamp: " << _chain[i].get_timestamp() << endl;
        cout << "Nonce: " << _chain[i].get_nonce() << endl;
        cout << "Difficulty: " << _chain[i].get_difficulty() << endl;
        vector<Transaction> transactions = _chain[i].get_transactions();
        cout << "Transaction: " << endl;
        if (transactions.size() > 0) {
            for (int j = 0; j < transactions.size(); ++j) {
                cout << "   Transaction #" << j+1 << endl;
                cout << "   Sender: " << transactions[j].get_sender() << endl;
                cout << "   Reciever: " << transactions[j].get_receiver() << endl;
                cout << "   Amount: " << transactions[j].get_amount() << endl;
                cout << "   Timestamp: " << transactions[j].get_time_stamp() << endl;
                cout << "   Hash: " << transactions[j].get_hash() << endl;
            }
        } else {
            cout << "   {}" << endl;
        }
        cout << "" << endl;
    }
}
