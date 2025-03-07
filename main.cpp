#include <iostream>
#include "blockchain.h"
#include "block.h"
#include "transaction.h"
using namespace std;

int main() {
    Blockchain blockchain;
    while (true) {
        cout << "1. Add & mine block with transaction data" << endl;
        cout << "2. Print the entire blockchain" << endl;
        cout << "3. Exit Program" << endl;
        int choice;
        cin >> choice;
        if (choice == 1) {
            string sender, receiver, amount;
            cout << "Enter the sender: " << endl;
            cin >> sender;
            cout << "Enter the receiver: " << endl;
            cin >> receiver;
            cout << "Enter the amount: " << endl;
            cin >> amount;
            Transaction transaction(sender,receiver, amount);
            string sender_key;
            cout << "Enter the sender public key: " << endl;
            cin >> sender_key;
            transaction.sign_transaction(sender_key);
            vector<Transaction> transactions;
            transactions.push_back(transaction);
            Block block(transactions,blockchain.get_top_block(),blockchain.get_blockchain_difficulty());
            blockchain.add_block(block);
            cout << "" << endl;
        } else if (choice == 2) {
            blockchain.print_blockchain();
        } else if (choice == 3) {
            cout << "Exited program!" << endl;
            return 0;
        }
    }
}