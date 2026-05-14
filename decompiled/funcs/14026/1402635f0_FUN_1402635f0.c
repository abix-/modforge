// Address: 0x1402635f0
// Ghidra name: FUN_1402635f0
// ============ 0x1402635f0 FUN_1402635f0 (size=592) ============


void FUN_1402635f0(undefined8 param_1,undefined8 param_2,int *param_3)



{

  int iVar1;

  int iVar2;

  undefined4 uVar3;

  undefined4 uVar4;

  longlong local_158 [2];

  int local_148;

  undefined4 local_144;

  undefined4 local_140;

  undefined4 local_13c;

  undefined4 local_138;

  undefined4 local_134;

  undefined4 local_130;

  undefined1 local_12c;

  undefined1 local_12b;

  undefined4 local_12a;

  undefined2 local_126;

  undefined4 local_118;

  undefined4 local_114;

  undefined4 local_110;

  undefined4 local_10c;

  undefined4 local_108;

  undefined4 local_104;

  undefined4 local_100;

  undefined4 local_fc;

  undefined8 local_f8;

  undefined8 uStack_f0;

  undefined8 local_e8;

  undefined8 uStack_e0;

  undefined8 local_d8;

  undefined8 local_d0;

  longlong *local_c8;

  undefined4 local_c0;

  undefined4 *local_b8;

  undefined4 local_b0;

  int local_a8;

  undefined8 local_a4;

  undefined4 local_9c;

  undefined1 local_8b;

  undefined4 local_88;

  undefined1 local_80;

  int *local_50;

  undefined4 local_48;

  

  iVar1 = *param_3;

  local_148 = param_3[3];

  local_12b = iVar1 != 0;

  local_12a = 0;

  local_126 = 0;

  local_12c = 0xf;

  iVar2 = FUN_14014de60(iVar1);

  local_13c = 0x7fffffff;

  uVar4 = 3;

  if (iVar2 == 1) {

    local_130 = 1;

  }

  else if (iVar2 == 2) {

    local_130 = 2;

  }

  else if (iVar2 == 3) {

    local_130 = 3;

  }

  else if (iVar2 == 4) {

    local_130 = 4;

  }

  else if (iVar2 == 5) {

    local_130 = 5;

  }

  else {

    local_130 = 0x7fffffff;

  }

  uVar3 = FUN_14014dea0(iVar1);

  local_134 = FUN_140203470(uVar3);

  uVar3 = FUN_14014dee0(iVar1);

  local_138 = FUN_140203470(uVar3);

  iVar2 = FUN_14014de80(iVar1);

  if (iVar2 == 1) {

    local_13c = 1;

  }

  else if (iVar2 == 2) {

    local_13c = 2;

  }

  else if (iVar2 == 3) {

    local_13c = 3;

  }

  else if (iVar2 == 4) {

    local_13c = 4;

  }

  else if (iVar2 == 5) {

    local_13c = 5;

  }

  uVar3 = FUN_14014dec0(iVar1);

  local_140 = FUN_140203470(uVar3);

  uVar3 = FUN_14014df00(iVar1);

  local_144 = FUN_140203470(uVar3);

  FUN_1402f94c0(&local_d8,0,0xa8);

  local_50 = &local_148;

  local_48 = 1;

  local_d8 = FUN_140263310(param_2,param_3[2]);

  local_d0 = FUN_140263300(param_2,param_3[1]);

  local_a8 = param_3[4];

  local_158[1] = 0;

  local_10c = 0;

  local_88 = 0;

  local_80 = 0;

  local_a4 = 0;

  local_9c = 0;

  local_8b = 1;

  local_114 = 0;

  local_104 = 0;

  local_f8 = 0;

  uStack_f0 = 0;

  local_e8 = 0;

  uStack_e0 = 0;

  local_118 = 0;

  local_110 = 10;

  local_108 = 1;

  local_100 = 0xc;

  local_fc = 8;

  if (param_3[2] == 2) {

    local_f8 = 2;

    uStack_f0 = 0x180000000a;

    local_158[0] = 0x20;

  }

  else {

    local_158[0] = 0x18;

    uVar4 = 2;

  }

  local_158[0] = local_158[0] << 0x20;

  local_b8 = &local_118;

  local_c8 = local_158;

  local_c0 = 1;

  local_b0 = uVar4;

  FUN_1401349d0(param_1,&local_d8);

  return;

}




