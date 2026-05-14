// Address: 0x140184280
// Ghidra name: FUN_140184280
// ============ 0x140184280 FUN_140184280 (size=25) ============


LARGE_INTEGER FUN_140184280(void)



{

  LARGE_INTEGER local_res8 [4];

  

  QueryPerformanceCounter(local_res8);

  return (LARGE_INTEGER)local_res8[0].QuadPart;

}




