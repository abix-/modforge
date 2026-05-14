// Address: 0x14026d3d0
// Ghidra name: FUN_14026d3d0
// ============ 0x14026d3d0 FUN_14026d3d0 (size=182) ============


byte FUN_14026d3d0(longlong *param_1,undefined1 *param_2,byte param_3)



{

  longlong lVar1;

  byte extraout_var;

  byte extraout_var_00;

  byte bVar2;

  ulonglong uVar3;

  ulonglong uVar4;

  undefined1 local_48 [64];

  

  lVar1 = *param_1;

  uVar3 = 0x40;

  if (*(char *)(lVar1 + 0x54) != '\0') {

    uVar3 = 0x31;

  }

  if (0x31 < param_3) {

    return 0;

  }

  uVar4 = (ulonglong)param_3;

  if (uVar4 < uVar3) {

    FUN_1402f8e20(local_48,param_2,param_3);

    FUN_1402f94c0(local_48 + uVar4,0,uVar3 - uVar4);

    param_2 = local_48;

    param_3 = (byte)uVar3;

  }

  if ((char)param_1[3] == '\0') {

    FUN_14026d370(param_1,param_2,param_3);

    bVar2 = extraout_var_00;

  }

  else {

    FUN_140195730(*(undefined8 *)(lVar1 + 0x80),param_2,param_3);

    bVar2 = extraout_var;

  }

  return bVar2 >> 7 ^ 1;

}




