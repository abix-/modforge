// Address: 0x1401abe00
// Ghidra name: FUN_1401abe00
// ============ 0x1401abe00 FUN_1401abe00 (size=222) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



ulonglong FUN_1401abe00(longlong *param_1,undefined4 *param_2)



{

  uint uVar1;

  ulonglong uVar2;

  ulonglong uVar3;

  undefined4 local_res8 [2];

  ulonglong local_res18;

  undefined4 local_18;

  undefined4 uStack_14;

  undefined4 uStack_10;

  undefined4 uStack_c;

  

  local_res8[0] = 0;

  uVar1 = (**(code **)(*param_1 + 0x38))(param_1,&DAT_14033cb00,local_res8);

  uVar2 = (ulonglong)uVar1;

  if ((int)uVar1 < 0) {

    local_res18 = 0;

    local_18 = _DAT_140398d38;

    uStack_14 = _UNK_140398d3c;

    uStack_10 = _UNK_140398d40;

    uStack_c = _UNK_140398d44;

    uVar2 = (**(code **)(*param_1 + 0x50))(param_1,&DAT_14033cb20,&local_18);

    if ((int)uVar2 < 0) {

      return uVar2;

    }

    uVar2 = (**(code **)(*param_1 + 0x40))(param_1,&DAT_14033cb80,&local_res18);

    if ((int)uVar2 < 0) {

      return uVar2;

    }

    uVar3 = (*DAT_1403fcdf8)(local_18,local_res18 >> 0x20,local_res8);

    uVar2 = uVar3 & 0xffffffff;

    if ((int)uVar3 < 0) {

      return uVar3;

    }

    (**(code **)(*param_1 + 0xa8))(param_1,&DAT_14033cb00,local_res8[0]);

  }

  *param_2 = local_res8[0];

  return uVar2;

}




