// Address: 0x1401a8590
// Ghidra name: FUN_1401a8590
// ============ 0x1401a8590 FUN_1401a8590 (size=433) ============


void FUN_1401a8590(undefined8 param_1,int param_2,undefined4 *param_3,int param_4,float param_5)



{

  float fVar1;

  float fVar2;

  undefined4 uVar3;

  undefined8 uVar4;

  char cVar5;

  longlong lVar6;

  undefined8 local_c8;

  undefined8 local_c0;

  undefined4 local_b8;

  int local_b4;

  undefined4 local_b0;

  float local_ac;

  float local_a8;

  int local_a4;

  float local_a0;

  undefined8 local_9c;

  undefined8 uStack_94;

  undefined8 local_8c;

  undefined8 uStack_84;

  undefined8 local_7c;

  undefined8 uStack_74;

  undefined8 local_6c;

  undefined8 uStack_64;

  undefined8 local_5c;

  undefined8 uStack_54;

  undefined4 local_4c;

  

  FUN_14017caa0(DAT_1403fcd48);

  lVar6 = FUN_1401a8110(param_2);

  uVar4 = DAT_1403fcd48;

  if ((lVar6 == 0) || (*(float *)(lVar6 + 0x28 + (longlong)param_4 * 4) == param_5)) {

    FUN_14017cae0(DAT_1403fcd48);

  }

  else {

    *(float *)(lVar6 + 0x28 + (longlong)param_4 * 4) = param_5;

    uVar3 = *(undefined4 *)(lVar6 + 0x4c);

    fVar1 = *(float *)(lVar6 + 0x48);

    fVar2 = *(float *)(lVar6 + 0x44);

    FUN_14017cae0(uVar4);

    cVar5 = FUN_140139420(0x1307);

    if (cVar5 != '\0') {

      local_a0 = param_5;

      local_c8 = 0x1307;

      local_4c = 0;

      local_9c = 0;

      uStack_94 = 0;

      local_8c = 0;

      uStack_84 = 0;

      local_7c = 0;

      uStack_74 = 0;

      local_6c = 0;

      uStack_64 = 0;

      local_5c = 0;

      uStack_54 = 0;

      local_c0 = param_1;

      local_b4 = param_2;

      local_b0 = uVar3;

      local_ac = fVar2;

      local_a8 = fVar1;

      local_a4 = param_4;

      if (param_3 == (undefined4 *)0x0) {

        local_b8 = 0;

        FUN_14013b140(&local_c8);

      }

      else {

        local_b8 = *param_3;

        FUN_14013b140(&local_c8);

        if ((((param_4 == 0) && (DAT_1403fcd40 == param_2)) && (lVar6 = FUN_1401611a0(), lVar6 != 0)

            ) && (*(char *)(lVar6 + 0xef) != '\0')) {

          FUN_140186970(param_1,0xfffffffffffffffe,1,param_3,fVar2 / (float)(int)param_3[8],

                        fVar1 / (float)(int)param_3[9],param_5);

        }

      }

    }

  }

  return;

}




