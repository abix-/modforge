// Address: 0x14022fff0
// Ghidra name: FUN_14022fff0
// ============ 0x14022fff0 FUN_14022fff0 (size=201) ============


void FUN_14022fff0(undefined8 *param_1,longlong *param_2)



{

  int iVar1;

  longlong lVar2;

  undefined4 local_18 [2];

  undefined8 uStack_10;

  

  if (((*param_2 != 0) && (*(longlong *)(*param_2 + 0x28) != 0)) &&

     (lVar2 = FUN_1401841a0(1,0x88), lVar2 != 0)) {

    local_18[0] = 0;

    uStack_10 = *(undefined8 *)(*param_2 + 0x28);

    FUN_140179b40(*param_1);

    iVar1 = (*DAT_1403fdd90)(param_1[3],local_18,param_2,lVar2);

    if (iVar1 < 0) {

      FUN_140179b60(*param_1);

      FUN_1401841e0(lVar2);

      return;

    }

    *(longlong **)(lVar2 + 0x50) = param_2;

    FUN_14022ffa0(param_1,param_2);

    FUN_140179b60(*param_1);

  }

  return;

}




