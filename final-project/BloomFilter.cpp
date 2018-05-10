#include "BloomFilter.h"

template<size_t SIZE, size_t N>
BloomFilter<SIZE, N>::BloomFilter() : numHashes(N) {}

template<size_t SIZE, size_t N>
bitset<SIZE> BloomFilter<SIZE, N>::getBits() const {
	return bits;
}

template<size_t SIZE, size_t N>
size_t BloomFilter<SIZE, N>::getNumHashes() const {
	return numHashes;
}

template<size_t SIZE, size_t N>
void BloomFilter<SIZE, N>::insert(string data) {
	for (size_t i = 0; i < numHashes; i++) {
		bits[hash(data, i) % SIZE] = 1;
	}
}

template<size_t SIZE, size_t N>
bool BloomFilter<SIZE, N>::contains(string data) const {
	for (size_t i = 0; i < numHashes; i++) {
		if (bits[hash(data, i) % SIZE] == 0) {
			return false;
		}
	}
	return true;
}

template<size_t SIZE, size_t N>
size_t BloomFilter<SIZE, N>::hash(string data, size_t n) const {
	size_t hashVal = data;
	for (size_t i = 0; i < n; i++) {
		hashVal = hash<string>{} (hashVal);
	}
	return hashVal;
}