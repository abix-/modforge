// Address: 0x14022ff60
// Ghidra name: FUN_14022ff60
// ============ 0x14022ff60 FUN_14022ff60 (size=53) ============


undefined8 FUN_14022ff60(HANDLE param_1)



{

  BOOL BVar1;

  LARGE_INTEGER local_res8 [4];

  

  BVar1 = GetFileSizeEx(param_1,local_res8);

  if (BVar1 == 0) {

    FUN_1401a9ed0("GetFileSizeEx");

    return 0xffffffffffffffff;

  }

  return local_res8[0].QuadPart;

}




