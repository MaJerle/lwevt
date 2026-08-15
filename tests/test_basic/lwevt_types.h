/* Event types used by test_basic - do not use include guard macros, file is included multiple times */

LWEVT_TYPE_BASIC(TEST_EVT_BASIC_1)
LWEVT_TYPE_BASIC(TEST_EVT_BASIC_2)
LWEVT_TYPE_EXT(TEST_EVT_EXT_1, struct { int par1; int par2; } ext1)
