#include <iostream>
#include "blockchain.h"
#include "block.h"
#include "transaction.h"

int main() {
    Blockchain blockchain;

    // Transactions
    vector<Transaction> transactions;
    Transaction transaction("me","you","10");
    transactions.push_back(transaction);

    // Adding
    blockchain.add_block(blockchain.create_block(transactions,blockchain.get_blocks()[0]));

    // Results
    cout << blockchain.get_blocks()[0]<< endl;
    return 0;
}