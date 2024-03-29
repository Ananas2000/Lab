add_library(data_structures
        bitset/bitset.c
        vector/vector.c
        vector/vector.h
        vector/vectorVoid.c
        vector/vectorVoid.h
        matrix/matrix.c
        matrix/matrix.h
)

target_link_libraries(data_structures algorithms)