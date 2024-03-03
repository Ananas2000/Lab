#include "bitset.h"

bitset_t bitset_create(const unsigned max_value) {
	bitset_t res;

	res.m_data = 0u; // zero data.
	res.m_max_value = max_value; // set max value in set.

	return res;
}

int	bitset_in(const bitset_t set, const unsigned value) {
	if (value > set.m_max_value)
		return 0;

	return (set.m_data & (1 << value)) ? 1 : 0;
}

int bitset_isEqual(const bitset_t a, const bitset_t b) {
	if (a.m_max_value != b.m_max_value)
		return 0;

	return a.m_data == b.m_data;
}

int bitset_isSubitset(const bitset_t sub, const bitset_t parent) {
	if (sub.m_data > parent.m_data || sub.m_max_value > parent.m_max_value)
		return 0;

	for (size_t i = 0u; i <= sub.m_max_value; ++i) {
		int a = bitset_in(parent, i);
		int b = bitset_in(sub, i);
		if (b && a != b)
			return 0;
	}

	return 1;
}

void bitset_insert(bitset_t *set, const unsigned value) {
	assert(set && set->m_max_value >= value);

	set->m_data |= (1 << value);
}

void bitset_delete(bitset_t *set, const unsigned value) {
	assert(set && set->m_max_value >= value);
	if (bitset_in( *set, value))
		set->m_data &= ~(1 << value);
}

bitset_t bitset_union(const bitset_t a, const bitset_t b) {
	size_t max_value = a.m_max_value > b.m_max_value ? a.m_max_value : b.m_max_value;

	bitset_t res = bitset_create(max_value);

	for (size_t i = 0u; i < max_value; ++i)
		if ( bitset_in(a, i) || bitset_in(b, i))
			bitset_insert(&res, i);

	return res;
}

bitset_t bitset_intersection(const bitset_t a, const bitset_t b) {
	size_t max_value = a.m_max_value > b.m_max_value ? a.m_max_value : b.m_max_value;

	bitset_t res = bitset_create(max_value);

	for (size_t i = 0u; i < max_value; ++i)
		if (bitset_in(a, i) && bitset_in(b, i))
			bitset_insert(&res, i);

	return res;
}

bitset_t bitset_diff(const bitset_t a, const bitset_t b) {
	size_t max_value = a.m_max_value > b.m_max_value ? a.m_max_value : b.m_max_value;

	bitset_t res = bitset_create(max_value);

	for (size_t i = 0u; i < max_value; ++i)
		if (bitset_in(a, i) && !bitset_in(b, i))
			bitset_insert(&res, i);

	return res;
}

bitset_t bitset_symdiff(const bitset_t a, const bitset_t b) {
	size_t max_value = a.m_max_value > b.m_max_value ? a.m_max_value : b.m_max_value;

	bitset_t res = bitset_create(max_value);

	for (size_t i = 0u; i < max_value; ++i)
		if ((bitset_in(a, i) && !bitset_in(b, i))
			|| (!bitset_in(a, i) && bitset_in(b, i)))
			bitset_insert(&res, i);

	return res;
}

bitset_t bitset_complement(const bitset_t set) {
	bitset_t res = bitset_create(set.m_max_value);

	for (size_t i = 0u; i < res.m_max_value; ++i) {
		if (!bitset_in(set, i))
			bitset_insert(&res, i);
	}

	return res;
}