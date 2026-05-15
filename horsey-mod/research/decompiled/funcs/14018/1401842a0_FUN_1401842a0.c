// Address: 0x1401842a0
// Ghidra name: FUN_1401842a0
// ============ 0x1401842a0 FUN_1401842a0 (size=25) ============


LARGE_INTEGER FUN_1401842a0(void)



{

  LARGE_INTEGER local_res8 [4];

  

  QueryPerformanceFrequency(local_res8);

  return (LARGE_INTEGER)local_res8[0].QuadPart;

}




