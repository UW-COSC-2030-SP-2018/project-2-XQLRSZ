#ifndef BLOOMFILTER_H
#define BLOOMFILTER_H

#include <bitset>
#include <string>
#include <functional>

using namespace std;

template<size_t SIZE, size_t N>
class BloomFilter {
public:
	BloomFilter();
	bitset getBits() const;
	size_t getNumHashes() const;
	void insert(string data);
	bool contains(string data) const;
protected:
	size_t hash(string data, size_t n) const;
private:
	bitset<SIZE> bits;
	const size_t numHashes;
};
#endif