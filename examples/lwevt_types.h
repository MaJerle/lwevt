/* Define basic types */
LWEVT_TYPE_BASIC(LWEVT_TYPE_MY_BASIC_1)
LWEVT_TYPE_BASIC(LWEVT_TYPE_MY_BASIC_2)
LWEVT_TYPE_BASIC(LWEVT_TYPE_MY_BASIC_3)

/* Define extended types */
LWEVT_TYPE_EXT(LWEVT_TYPE_MY_EXT_1, struct { int par1; int par2; } ext1)
LWEVT_TYPE_EXT(LWEVT_TYPE_MY_EXT_2, struct { int par3; int par4; } ext2)
LWEVT_TYPE_EXT(LWEVT_TYPE_MY_EXT_3, struct { int par1; int par2; } ext3)