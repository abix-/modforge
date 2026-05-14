// Address: 0x1400845f0
// Ghidra name: FUN_1400845f0
// ============ 0x1400845f0 FUN_1400845f0 (size=109) ============


void FUN_1400845f0(longlong param_1,ushort param_2,char param_3)



{

  longlong lVar1;

  undefined2 local_res8;

  ushort uStackX_a;

  undefined2 local_resc;

  

  for (lVar1 = *(longlong *)(param_1 + 0x70); lVar1 != 0; lVar1 = *(longlong *)(lVar1 + 8)) {

    local_resc = *(undefined2 *)(lVar1 + 0x38);

    local_res8 = (undefined2)*(undefined4 *)(lVar1 + 0x34);

    uStackX_a = (ushort)((uint)*(undefined4 *)(lVar1 + 0x34) >> 0x10);

    if (param_3 == '\0') {

      uStackX_a = uStackX_a & ~param_2;

    }

    else {

      uStackX_a = uStackX_a | param_2;

    }

    FUN_1400082e0(lVar1,&local_res8);

  }

  return;

}




