/**
 * \file            test.h
 * \brief           Test assert helper
 */
#ifndef TEST_HDR_H
#define TEST_HDR_H

/* Assert check */
#define TEST_ASSERT(x)                                                                                               \
    do {                                                                                                             \
        if (!(x)) {                                                                                                  \
            printf("Assert in file %s and on line %d failed with condition (" #x ")\r\n", __FILE__, (int)__LINE__);  \
            return -1;                                                                                               \
        }                                                                                                            \
    } while (0)

#endif /* TEST_HDR_H */
