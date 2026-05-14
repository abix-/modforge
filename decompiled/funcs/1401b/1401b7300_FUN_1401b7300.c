// Address: 0x1401b7300
// Ghidra name: FUN_1401b7300
// ============ 0x1401b7300 FUN_1401b7300 (size=300) ============


undefined8

FUN_1401b7300(longlong param_1,int *param_2,longlong param_3,undefined4 param_4,undefined4 param_5,

             undefined4 *param_6,undefined8 *param_7)



{

  int iVar1;

  undefined8 uVar2;

  undefined4 local_58 [2];

  undefined8 local_50;

  undefined4 local_48;

  undefined8 local_40;

  int local_38;

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

  

  local_40 = *(undefined8 *)(param_3 + 0x18);

  local_58[0] = 0xf;

  local_50 = 0;

  local_34 = *(undefined4 *)(&DAT_1403e3ec0 + (longlong)param_2[1] * 4);

  local_48 = 0;

  local_18 = 1;

  local_10 = 1;

  local_30 = *param_6;

  uStack_2c = param_6[1];

  uStack_28 = param_6[2];

  uStack_24 = param_6[3];

  local_20 = *(undefined4 *)(param_3 + 0x38);

  local_1c = param_5;

  local_38 = (*param_2 == 2) + 1;

  local_14 = param_4;

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




