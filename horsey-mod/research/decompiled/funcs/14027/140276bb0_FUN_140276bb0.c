// Address: 0x140276bb0
// Ghidra name: FUN_140276bb0
// ============ 0x140276bb0 FUN_140276bb0 (size=90) ============


undefined8 FUN_140276bb0(undefined8 param_1,longlong param_2,uint param_3)



{

  undefined8 uVar1;

  int iVar2;

  

  iVar2 = 0;

  while ((uVar1 = FUN_140276960(param_1,param_2), (int)uVar1 < 0 ||

         (*(byte *)(param_2 + 1) != param_3))) {

    iVar2 = iVar2 + 1;

    if (9 < iVar2) {

      return 0xffffffff;

    }

  }

  return uVar1;

}




