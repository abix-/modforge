// Address: 0x14015c2a0
// Ghidra name: FUN_14015c2a0
// ============ 0x14015c2a0 FUN_14015c2a0 (size=51) ============


longlong FUN_14015c2a0(longlong param_1)



{

  longlong lVar1;

  uint7 uVar2;

  

  lVar1 = *(longlong *)(param_1 + 0xd0);

  uVar2 = (uint7)((ulonglong)lVar1 >> 8);

  if ((((lVar1 != 0) && (*(longlong *)(lVar1 + 0x38) == 0)) && (*(longlong *)(lVar1 + 0x28) == 0))

     && ((*(longlong *)(lVar1 + 0x18) != 0 &&

         (*(longlong *)(*(longlong *)(lVar1 + 0x18) + 200) == 0)))) {

    return CONCAT71(uVar2,1);

  }

  return (ulonglong)uVar2 << 8;

}




