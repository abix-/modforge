// Address: 0x1402156d0
// Ghidra name: FUN_1402156d0
// ============ 0x1402156d0 FUN_1402156d0 (size=36) ============


ulonglong FUN_1402156d0(longlong param_1,int param_2)



{

  longlong lVar1;

  ulonglong in_RAX;

  undefined7 uVar2;

  

  if (param_2 == 0) {

    return in_RAX & 0xffffffffffffff00;

  }

  lVar1 = *(longlong *)(param_1 + 200);

  uVar2 = (undefined7)((ulonglong)lVar1 >> 8);

  if (param_2 == -0x7776fffc) {

    *(undefined1 *)(lVar1 + 0x44) = 1;

    return CONCAT71(uVar2,1);

  }

  *(undefined1 *)(lVar1 + 0x45) = 1;

  return CONCAT71(uVar2,1);

}




