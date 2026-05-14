// Address: 0x14013f010
// Ghidra name: FUN_14013f010
// ============ 0x14013f010 FUN_14013f010 (size=167) ============


ulonglong FUN_14013f010(undefined4 param_1)



{

  uint uVar1;

  longlong lVar2;

  size_t sVar3;

  undefined1 *puVar4;

  ulonglong uVar5;

  

  FUN_140159d30();

  lVar2 = FUN_140140710(param_1,1);

  uVar1 = 0;

  if ((lVar2 != 0) &&

     (lVar2 = thunk_FUN_1402c9340(*(undefined8 *)(lVar2 + 0x18),"type:"), uVar1 = 0, lVar2 != 0)) {

    sVar3 = strlen("type:");

    puVar4 = (undefined1 *)thunk_FUN_1402c9190(lVar2 + sVar3,0x2c);

    uVar1 = 0;

    if (puVar4 != (undefined1 *)0x0) {

      *puVar4 = 0;

      uVar1 = FUN_14013f0c0(lVar2 + sVar3);

      *puVar4 = 0x2c;

    }

  }

  FUN_14015bb10();

  if (uVar1 == 0) {

    uVar5 = FUN_14013f350(param_1);

    return uVar5;

  }

  return (ulonglong)uVar1;

}




