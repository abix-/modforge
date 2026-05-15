// Address: 0x14020bb10
// Ghidra name: FUN_14020bb10
// ============ 0x14020bb10 FUN_14020bb10 (size=54) ============


int FUN_14020bb10(void)



{

  longlong lVar1;

  int iVar2;

  

  iVar2 = 0;

  _guard_check_icall();

  for (lVar1 = DAT_1403fd260; lVar1 != 0; lVar1 = *(longlong *)(lVar1 + 0x108)) {

    iVar2 = iVar2 + 1;

  }

  return iVar2;

}




