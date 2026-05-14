// Address: 0x140204b80
// Ghidra name: FUN_140204b80
// ============ 0x140204b80 FUN_140204b80 (size=289) ============


bool FUN_140204b80(longlong param_1,longlong param_2,int param_3,undefined8 param_4)



{

  longlong lVar1;

  undefined8 *puVar2;

  longlong lVar3;

  undefined8 uVar4;

  undefined4 local_68;

  int local_64;

  undefined4 local_60;

  longlong local_58;

  undefined4 local_50;

  int local_4c;

  undefined8 local_48;

  undefined8 local_40;

  undefined8 local_38;

  undefined8 local_30;

  undefined4 local_28;

  int local_24;

  undefined4 local_20;

  undefined4 local_1c;

  

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  puVar2 = *(undefined8 **)(param_2 + 0x10);

  local_60 = 0;

  local_68 = 0;

  local_64 = param_3 * 4;

  lVar3 = FUN_140135d10(*(undefined8 *)(lVar1 + 8),&local_68);

  if (lVar3 != 0) {

    uVar4 = FUN_140137ac0(*(undefined8 *)(lVar1 + 8),lVar3,0);

    FUN_1402f8e20(uVar4,param_4,param_3 * 4);

    FUN_140138720(*(undefined8 *)(lVar1 + 8),lVar3);

    uVar4 = FUN_140132c70(*(undefined8 *)(lVar1 + 0xa0));

    local_50 = 0;

    local_48 = 1;

    local_38 = 0;

    local_28 = 0;

    local_40 = *puVar2;

    local_30 = 0;

    local_20 = 1;

    local_1c = 1;

    local_58 = lVar3;

    local_4c = param_3;

    local_24 = param_3;

    FUN_1401388a0(uVar4,&local_58,&local_40,0);

    FUN_140136720(uVar4);

    FUN_140138000(*(undefined8 *)(lVar1 + 8),lVar3);

  }

  return lVar3 != 0;

}




