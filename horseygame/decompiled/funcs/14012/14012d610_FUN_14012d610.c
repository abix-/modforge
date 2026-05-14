// Address: 0x14012d610
// Ghidra name: FUN_14012d610
// ============ 0x14012d610 FUN_14012d610 (size=52) ============


ulonglong FUN_14012d610(undefined8 *param_1)



{

  byte bVar1;

  BOOL BVar2;

  LARGE_INTEGER local_res8 [4];

  

  BVar2 = GetFileSizeEx((HANDLE)*param_1,local_res8);

  if (BVar2 == 0) {

    bVar1 = FUN_1401a9ed0("windows_file_size");

    return (ulonglong)bVar1;

  }

  return local_res8[0].QuadPart;

}




