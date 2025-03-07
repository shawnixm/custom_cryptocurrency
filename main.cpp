#include <iostream>
#include "blockchain.h"
#include "block.h"
#include "transaction.h"
using namespace std;

int main() {
    Blockchain blockchain;
    Blockchain blockchain2;
    while (true) {
        cout << "1. Add & mine block with transaction data to blockchain 1" << endl;
        cout << "2. Add & mine block with transaction data to blockchain 2" << endl;
        cout << "3. Print the entire blockchain 1" << endl;
        cout << "4. Print the entire blockchain 2" << endl;
        cout << "5. Exit Program" << endl;
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
            blockchain = blockchain.resolve_conflicts(blockchain,blockchain2);
            blockchain2 = blockchain.resolve_conflicts(blockchain,blockchain2);
            cout << "" << endl;
        } else if (choice == 2) {
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
            blockchain2.add_block(block);
            blockchain2 = blockchain.resolve_conflicts(blockchain,blockchain2);
            blockchain = blockchain.resolve_conflicts(blockchain,blockchain2);
            cout << "" << endl;
        } else if (choice == 3) {
            blockchain.print_blockchain();
        } else if (choice == 4) {
            blockchain2.print_blockchain();
        } else if (choice == 5) {
            cout << "Exited program!" << endl;
            return 0;
        }
    }
}