#include "transaction.h"
#include <string>
#include <ctime>
#include "sha256.h"
using namespace std;

// Constructor
Transaction::Transaction(string sender, string receiver, string amount) {
    _sender = sender;
    _receiver = receiver;
    _amount = amount;
    _time_stamp = std::to_string(time(nullptr));
    _hash = calculate_hash(_sender,_receiver,_amount,_time_stamp);
}

// Hashing
string Transaction::calculate_hash(string sender, string receiver, string amount, string time_stamp) {
    SHA256 sha256;
    string hash_string = sender + receiver + amount + time_stamp;
    string hash = sha256(hash_string);
    return hash;
}

// Signing
void Transaction::sign_transaction(string sender_key) {
    _sender_key = sender_key;
}


// Getters
string Transaction::get_sender() {
    return _sender;
}

string Transaction::get_receiver() {
    return _receiver;
}

string Transaction::get_amount() {
    return _amount;
}

string Transaction::get_time_stamp() {
    return _time_stamp;
}

string Transaction::get_hash() {
    return _hash;
}

