#include <iostream>
#include "blockchain.h"
#include "block.h"
#include "transaction.h"

int main() {
    Blockchain blockchain;
    Transaction transaction("me","you","10");
    vector<Transaction> transactions;
    transactions.push_back(transaction);
    Block block(transactions,blockchain.get_top_block(),blockchain.get_blockchain_difficulty());
    blockchain.add_block(block);
    blockchain.generate_wallet();
    cout << blockchain.get_top_block().get_nonce() << endl;
    return 0;
}