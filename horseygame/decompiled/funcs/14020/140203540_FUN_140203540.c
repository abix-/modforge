// Address: 0x140203540
// Ghidra name: FUN_140203540
// ============ 0x140203540 FUN_140203540 (size=172) ============


bool FUN_140203540(longlong param_1,longlong param_2)



{

  longlong *plVar1;

  longlong lVar2;

  undefined4 local_38;

  undefined4 local_34;

  undefined4 local_30;

  undefined4 local_2c;

  undefined4 local_28;

  undefined4 local_24;

  undefined8 local_20;

  undefined4 local_18;

  

  lVar2 = *(longlong *)(param_1 + 0x2e0);

  plVar1 = (longlong *)FUN_1401841a0(1,8);

  if (plVar1 != (longlong *)0x0) {

    *(longlong **)(param_2 + 0x10) = plVar1;

    local_38 = 0;

    local_18 = 0;

    local_34 = FUN_1401378d0(0x16762004);

    local_24 = 1;

    local_20 = 1;

    local_30 = 1;

    local_2c = 0x100;

    local_28 = 1;

    lVar2 = FUN_1401355b0(*(undefined8 *)(lVar2 + 8),&local_38);

    *plVar1 = lVar2;

    return lVar2 != 0;

  }

  return false;

}




