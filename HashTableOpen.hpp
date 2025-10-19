#ifndef HT_OPEN_HPP
#define HT_OPEN_HPP

#include "Dictionary.hpp"
#include "LinkedList.hpp"

template <typename Key, typename Val>
class HashTableOpen : public Dictionary<Key, Val> {
    protected:
        // an element in a dictionary, contains a key and a value
        struct Record {
            Key k;
            Val v;

            Record() : k(Key()), v(Val()) { }
            Record(Key x, Val y) : k(x), v(y) { }
        };

        // the size of the hash table (total number of slots)
        int M;

        // the underlying (dynamic) array of (dynamic) linked lists
        LinkedList<Record>** ht;

    private:
        // hash function
        // folding method (assumes that Key = string)
        int hash(const Key&) const;

        // copy the state of the argument hash table to `this`
        void copy(const HashTableOpen<Key, Val>&);

    public:
        // default constructor
        HashTableOpen(int = 100);

        // copy constructor
        HashTableOpen(const HashTableOpen<Key, Val>&);

        // overloaded assignment operator
        HashTableOpen<Key, Val>& operator=(const HashTableOpen<Key, Val>&);

        // destructor
        virtual ~HashTableOpen();

        // remove all records in the dictionary, resetting to the initial state
        virtual void clear() override;

        // retrieve the record that matches the argument key
        // if multiple records match, return an arbitrary one
        virtual Val find(const Key&) const override;

        // add the record as a key-value pair to the dictionary
        virtual void insert(const Key&, const Val&) override;

        // remove the record that matches the argument key from the dictionary
        // if multiple records match, remove an arbitrary one
        virtual void remove(const Key&) override;

        // return the number of records in the dictionary
        virtual int size() const override;
};

#include "HashTableOpen.tpp"
#endif
