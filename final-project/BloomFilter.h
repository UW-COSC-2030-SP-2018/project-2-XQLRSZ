// This header is a mess because of this:
// https://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file
// Because of template stuff that I don't really understand,
// templates must be defined in the header or use some other, non-ideal workarounds.
// Can you help me understand this?

#ifndef BLOOMFILTER_H
#define BLOOMFILTER_H

#include <bitset>
#include <string>

using namespace std;

template<size_t SIZE, size_t N>
class BloomFilter {
public:
	// This crashes if SIZE == 0 and doesn't work if N == 0
	BloomFilter() : numHashes(N) {}

	bitset<SIZE> getBits() const {
		return bits;
	}

	size_t getNumHashes() const {
		return numHashes;
	}

	void insert(string data) {
		for (size_t i = 0; i < numHashes; i++) {
			bits[BloomFilter::hash(data, i) % SIZE] = 1;
		}
	}

	bool contains(string data) const {
		for (size_t i = 0; i < numHashes; i++) {
			if (bits[BloomFilter::hash(data, i) % SIZE] == 0) {
				return false;
			}
		}
		return true;
	}

protected:
	size_t hash(string data, size_t n) const {
		std::hash<string> hashFunc;
		size_t hashVal = hashFunc(data);
		for (size_t i = 1; i < n; i++) {
			hashVal = hashFunc(to_string(hashVal));
		}
		return hashVal;
	}

private:
	bitset<SIZE> bits;
	const size_t numHashes;
};

#endif