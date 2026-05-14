// Address: 0x1401b71e0
// Ghidra name: FUN_1401b71e0
// ============ 0x1401b71e0 FUN_1401b71e0 (size=276) ============


undefined8

FUN_1401b71e0(longlong param_1,longlong param_2,undefined4 param_3,undefined4 param_4,

             undefined4 param_5,undefined4 *param_6,undefined8 *param_7)



{

  int iVar1;

  undefined8 uVar2;

  undefined4 local_58 [2];

  undefined8 local_50;

  undefined4 local_48;

  undefined8 local_40;

  undefined4 local_38;

  undefined4 local_34;

  undefined4 local_30;

  undefined4 uStack_2c;

  undefined4 uStack_28;

  undefined4 uStack_24;

  undefined4 local_20;

  undefined4 local_1c;

  undefined4 local_18;

  undefined4 local_14;

  undefined4 local_10;

  

  local_40 = *(undefined8 *)(param_2 + 0x18);

  local_58[0] = 0xf;

  local_50 = 0;

  local_48 = 0;

  local_34 = param_5;

  local_30 = *param_6;

  uStack_2c = param_6[1];

  uStack_28 = param_6[2];

  uStack_24 = param_6[3];

  local_20 = *(undefined4 *)(param_2 + 0x38);

  local_18 = 1;

  local_10 = 1;

  local_38 = 1;

  local_1c = param_4;

  local_14 = param_3;

  iVar1 = (**(code **)(param_1 + 0xb38))(*(undefined8 *)(param_1 + 0x570),local_58,0,param_7);

  if (iVar1 == 0) {

    return 1;

  }

  *param_7 = 0;

  if (*(char *)(param_1 + 0x57c) != '\0') {

    uVar2 = FUN_1401c0ba0(iVar1);

                    /* WARNING: Subroutine does not return */

    FUN_14012e0b0(9,"%s %s","vkCreateImageView",uVar2);

  }

  uVar2 = FUN_1401c0ba0(iVar1);

  FUN_14012e850("%s %s","vkCreateImageView",uVar2);

  return 0;

}




