// Address: 0x140136cd0
// Ghidra name: FUN_140136cd0
// ============ 0x140136cd0 FUN_140136cd0 (size=735) ============


void FUN_140136cd0(undefined8 *param_1,undefined8 *param_2,undefined8 param_3,undefined8 param_4,

                  undefined8 param_5,ulonglong param_6,undefined8 param_7,undefined8 param_8,

                  undefined8 param_9,undefined8 param_10,undefined8 param_11,undefined8 param_12,

                  undefined8 param_13)



{

  int *piVar1;

  undefined8 uVar2;

  undefined8 uVar3;

  byte bVar4;

  uint uVar5;

  float fVar6;

  float fVar7;

  float local_a8;

  float local_a4;

  float local_a0;

  float local_9c;

  undefined4 local_98;

  float local_94;

  float local_90;

  float local_8c;

  float local_88;

  float local_84;

  undefined4 local_80;

  undefined4 local_7c;

  undefined8 local_78;

  undefined8 local_70;

  undefined8 local_68;

  undefined4 local_60;

  undefined4 local_5c;

  undefined4 local_58;

  undefined4 uStack_54;

  undefined4 uStack_50;

  undefined4 uStack_4c;

  undefined4 local_48;

  undefined4 local_44;

  undefined1 local_30;

  

  piVar1 = (int *)*param_2;

  uVar2 = FUN_140137340(*param_1,*piVar1,*(undefined4 *)(param_2[4] + 4),param_5,param_6,param_7,

                        param_8,param_9,param_10,param_11,param_12,param_13);

  local_48 = *(undefined4 *)(param_2 + 8);

  local_58 = *(undefined4 *)((longlong)param_2 + 0x44);

  uStack_54 = *(undefined4 *)(param_2 + 9);

  uStack_50 = *(undefined4 *)((longlong)param_2 + 0x4c);

  uStack_4c = *(undefined4 *)(param_2 + 10);

  local_68 = param_2[4];

  local_60 = *(undefined4 *)(param_2 + 5);

  local_5c = *(undefined4 *)((longlong)param_2 + 0x2c);

  local_30 = *(undefined1 *)((longlong)param_2 + 0x5c);

  local_44 = 0;

  uVar3 = FUN_140132d50(param_1,&local_68,1,0);

  local_80 = 0;

  local_7c = 0x3f800000;

  local_90 = (float)*(uint *)(param_2 + 6);

  local_8c = (float)*(uint *)((longlong)param_2 + 0x34);

  local_88 = (float)*(uint *)(param_2 + 7);

  local_84 = (float)*(uint *)((longlong)param_2 + 0x3c);

  FUN_1401384e0(uVar3,&local_90);

  FUN_140133940(uVar3,uVar2);

  local_78 = *param_2;

  local_70 = param_3;

  if (*(int *)(param_2 + 0xb) == 0) {

    local_70 = param_4;

  }

  FUN_140133610(uVar3,0,&local_78,1);

  local_98 = *(undefined4 *)(param_2 + 1);

  bVar4 = (byte)local_98;

  local_a8 = (float)*(uint *)(param_2 + 2) / (float)((uint)piVar1[3] >> (bVar4 & 0x1f));

  local_a4 = (float)*(uint *)((longlong)param_2 + 0x14) / (float)((uint)piVar1[4] >> (bVar4 & 0x1f))

  ;

  fVar7 = (float)*(uint *)(param_2 + 3) / (float)((uint)piVar1[3] >> (bVar4 & 0x1f));

  fVar6 = (float)*(uint *)((longlong)param_2 + 0x1c) / (float)((uint)piVar1[4] >> (bVar4 & 0x1f));

  if (*piVar1 == 2) {

    uVar5 = piVar1[5];

  }

  else {

    uVar5 = 1;

  }

  local_94 = (float)*(uint *)((longlong)param_2 + 0xc) / (float)uVar5;

  local_a0 = fVar7;

  if ((*(uint *)((longlong)param_2 + 0x54) & 1) != 0) {

    local_a0 = fVar7 * DAT_14039ca80;

    local_a8 = fVar7 + local_a8;

  }

  local_9c = fVar6;

  if ((*(uint *)((longlong)param_2 + 0x54) & 2) != 0) {

    local_9c = fVar6 * DAT_14039ca80;

    local_a4 = fVar6 + local_a4;

  }

  FUN_140137ce0(param_1,0,&local_a8,0x18);

  FUN_140136560(uVar3,3,1,0,param_6 & 0xffffffff00000000);

  FUN_1401367c0(uVar3);

  return;

}




