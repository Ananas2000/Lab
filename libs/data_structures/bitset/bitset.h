#include <assert.h>
#include <stdio.h>

typedef struct bitset {
	unsigned m_data;
	unsigned m_max_value;
} bitset_t;

bitset_t	bitset_create(const unsigned max_value);

int		bitset_in(const bitset_t set, const unsigned value);

int		bitset_isEqual(const bitset_t a, const bitset_t b);

int		bitset_isSubitset_t(const bitset_t sub, const bitset_t parent);

void	bitset_insert(bitset_t *set, const unsigned value);

void	bitset_delete(bitset_t *set, const unsigned value);

bitset_t	bitset_union(const bitset_t a, const bitset_t b);

bitset_t	bitset_intersection(const bitset_t a, const bitset_t b);

bitset_t	bitset_diff(const bitset_t a, const bitset_t b);

bitset_t	bitset_symdiff(const bitset_t a, const bitset_t b);

bitset_t	bitset_complement(const bitset_t set);