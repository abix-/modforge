// Address: 0x1402c6e18
// Ghidra name: _Xtime_get_ticks
// ============ 0x1402c6e18 _Xtime_get_ticks (size=47) ============


/* Library Function - Single Match

    _Xtime_get_ticks

   

   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */



longlong _Xtime_get_ticks(void)



{

  uint local_res8;

  uint local_resc;

  

  FUN_1402c7024(&local_res8);

  return ((ulonglong)local_resc << 0x20) + -0x19db1ded53e8000 + (ulonglong)local_res8;

}




