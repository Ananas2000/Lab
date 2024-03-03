#include "unorderedset.h"

// additional methods.
static void unordered_set_shrink_to_fit(unordered_array_set *set) {
	if (set->m_capacity != set->m_size) {
		set->m_data = realloc(set->m_data, sizeof(int) * set->m_size);
		set->m_capacity = set->m_size;
	}
}

unordered_array_set unordered_set_create(const size_t capacity) {
	unordered_array_set res;

	res.m_size = 0u;
	res.m_capacity = capacity;
	res.m_data = malloc(sizeof(int) * capacity);

	return res;
}

unordered_array_set unordered_set_create_from_array(const int *array, const size_t size) {
	unordered_array_set set = unordered_set_create(size);

	for (size_t i = 0u; i < size; ++i)
		unordered_set_insert(&set, array[ i ]);

	unordered_set_shrink_to_fit(&set);

	return set;
}

size_t unordered_set_in(const unordered_array_set set, const int value) {
	for (size_t i = 0u; i < set.m_size; ++i)
		if (set.m_data[ i ] == value)
			return i;

	return set.m_size;
}

size_t unordered_set_isSubset(const unordered_array_set sub, const unordered_array_set parent) {
	if (sub.m_size > parent.m_size)
		return 0;

	size_t intersections = 0u;
	for (size_t i = 0u; i < parent.m_size; ++i) {
		for (size_t j = 0u; j < sub.m_size; ++j) {
			if (sub.m_data[ j ] == parent.m_data[ i + j ])
				++intersections;
			else {
				intersections = 0;
				break;
			}

			if (intersections == sub.m_size)
				return i;
		}
	}

	return parent.m_size;
}

int unordered_set_isEqual(const unordered_array_set a, const unordered_array_set b) {
	if (a.m_size != b.m_size)
		return 0;

	size_t intersections = 0u;
	for (size_t i = 0u; i < a.m_size; ++i) {
		for (size_t j = 0u; j < b.m_size; ++j) {
			if (a.m_data[ i ] == b.m_data[ j ])
				++intersections;

		}
	}

	if (intersections == a.m_size)
		return 1;

	return 0;
}

void unordered_set_isAbleToAppend(unordered_array_set *set) {
	assert(set->m_size < set->m_capacity);
}

void unordered_set_insert(unordered_array_set *set, const int value) {
	if (unordered_set_in(*set, value) == set->m_size) {
		unordered_set_isAbleToAppend(set);


		set->m_data[ set->m_size++ ] = value;
	}
}

void unordered_set_delete(unordered_array_set *set, const int value) {
	if (unordered_set_in(*set, value) == set->m_size)
		return;

	size_t read = 0u;
	while (read < set->m_size) {
		if (set->m_data[ read ] == value)
			set->m_data[ read ] = set->m_data[ --set->m_size ];
		else
			++read;
	}
}

unordered_array_set unordered_set_union(const unordered_array_set a, const unordered_array_set b) {
	size_t estimate_capacity = a.m_size + b.m_size;

	unordered_array_set set = unordered_set_create(estimate_capacity);
	
	// add set(a) values.
	for (size_t i = 0u; i < a.m_size; ++i) {
		unordered_set_insert(&set, a.m_data[ i ]);
	}

	// add set(b) values.
	for (size_t i = 0u; i < b.m_size; ++i) {
		unordered_set_insert(&set, b.m_data[ i ]);
	}

	unordered_set_shrink_to_fit(&set);

	return set;
}

unordered_array_set unordered_set_intersection(const unordered_array_set a, const unordered_array_set b) {
	size_t estimate_capacity = a.m_size + b.m_size;

	unordered_array_set set = unordered_set_create(estimate_capacity);

	for (size_t i = 0u; i < a.m_size; ++i) {
		for (size_t j = 0u; j < b.m_size; ++j) {
			if (a.m_data[ i ] == b.m_data[ j ])
				unordered_set_insert(&set, a.m_data[ i ]);
		}
	}

	unordered_set_shrink_to_fit(&set);

	return set;
}

unordered_array_set unordered_set_diff(const unordered_array_set a, const unordered_array_set b) {
	size_t estimate_capacity = a.m_size + b.m_size;

	unordered_array_set set = unordered_set_create(estimate_capacity);

	for (size_t i = 0u; i < a.m_size; ++i) {
		int should_insert = 1;
		for (size_t j = 0u; j < b.m_size; ++j) {
			if (a.m_data[ i ] == b.m_data[ j ])
				should_insert = 0;
		}

		if (should_insert)
				unordered_set_insert(&set, a.m_data[ i ]);
	}

	unordered_set_shrink_to_fit(&set);

	return set;
}

unordered_array_set unordered_set_symdiff(const unordered_array_set a, const unordered_array_set b) {
	unordered_array_set left  = unordered_set_diff(a, b);
	unordered_array_set right = unordered_set_diff(b, a);
	
	unordered_array_set set = unordered_set_union(left, right);

	unordered_set_shrink_to_fit(&set);

	return set;
}

unordered_array_set unordered_set_complement(const unordered_array_set set, const unordered_array_set universum) {
	unordered_array_set diff = unordered_set_diff(universum, set);

	return diff;
}

void unordered_set_print(const unordered_array_set set) {
	for (size_t i = 0u; i < set.m_size; ++i)
		printf("%d ", set.m_data[ i ]);

	printf("\n");
}

void unordered_set_erasemem(unordered_array_set *set) {
	set->m_capacity = 0u;
	set->m_size = 0u;
	free(set->m_data);
}