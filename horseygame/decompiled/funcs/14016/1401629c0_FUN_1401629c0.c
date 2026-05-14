// Address: 0x1401629c0
// Ghidra name: FUN_1401629c0
// ============ 0x1401629c0 FUN_1401629c0 (size=384) ============


void FUN_1401629c0(undefined8 param_1,longlong param_2,undefined4 param_3,float param_4,

                  float param_5,undefined4 param_6)



{

  char cVar1;

  longlong lVar2;

  undefined4 uVar3;

  float local_res10 [4];

  float local_res20 [2];

  undefined4 local_b8 [2];

  undefined8 local_b0;

  undefined4 local_a8;

  undefined4 local_a4;

  float local_a0;

  float local_9c;

  undefined4 local_98;

  undefined4 local_94;

  undefined4 local_90;

  int local_8c;

  int local_88;

  

  lVar2 = FUN_1401611a0();

  if (param_2 != 0) {

    FUN_140162ca0(param_2);

  }

  if (((param_4 != 0.0) || (param_5 != 0.0)) && (cVar1 = FUN_140139420(0x403), cVar1 != '\0')) {

    if ((*(char *)(lVar2 + 0xc1) == '\0') || (*(char *)(lVar2 + 0xc6) != '\0')) {

      param_3 = 0;

    }

    local_b8[0] = 0x403;

    if (*(undefined4 **)(lVar2 + 0x88) == (undefined4 *)0x0) {

      local_a8 = 0;

    }

    else {

      local_a8 = **(undefined4 **)(lVar2 + 0x88);

    }

    local_94 = *(undefined4 *)(lVar2 + 0x90);

    local_90 = *(undefined4 *)(lVar2 + 0x94);

    local_98 = param_6;

    local_b0 = param_1;

    local_a4 = param_3;

    uVar3 = FUN_140190500(param_4 + *(float *)(lVar2 + 0xa8),local_res20);

    local_8c = (int)local_res20[0];

    *(undefined4 *)(lVar2 + 0xa8) = uVar3;

    uVar3 = FUN_140190500(param_5 + *(float *)(lVar2 + 0xac),local_res10);

    local_88 = (int)local_res10[0];

    *(undefined4 *)(lVar2 + 0xac) = uVar3;

    if ((*(byte *)(lVar2 + 0x78) & 2) == 0) {

      local_9c = param_5;

      local_a0 = param_4;

    }

    else {

      local_a0 = local_res20[0];

      local_9c = local_res10[0];

    }

    FUN_14013b140(local_b8);

  }

  return;

}




