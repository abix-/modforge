// Address: 0x1401a8920
// Ghidra name: FUN_1401a8920
// ============ 0x1401a8920 FUN_1401a8920 (size=562) ============


void FUN_1401a8920(undefined8 param_1,int param_2,undefined4 *param_3,float param_4,float param_5)



{

  undefined4 uVar1;

  undefined8 uVar2;

  char cVar3;

  longlong lVar4;

  longlong lVar5;

  undefined8 local_a8;

  undefined8 local_a0;

  undefined4 local_98;

  int local_94;

  undefined4 local_90;

  float local_8c;

  float local_88;

  undefined8 local_84;

  undefined8 uStack_7c;

  undefined8 local_74;

  undefined8 uStack_6c;

  undefined8 local_64;

  undefined8 uStack_5c;

  undefined8 local_54;

  undefined8 uStack_4c;

  undefined8 local_44;

  undefined8 uStack_3c;

  undefined8 local_34;

  undefined4 local_2c;

  

  FUN_14017caa0(DAT_1403fcd48);

  lVar4 = FUN_1401a8110(param_2);

  if ((lVar4 == 0) ||

     ((FUN_1401a80e0(param_1,lVar4,param_3), uVar2 = DAT_1403fcd48,

      *(float *)(lVar4 + 0x44) == param_4 && (*(float *)(lVar4 + 0x48) == param_5)))) {

    FUN_14017cae0(DAT_1403fcd48);

  }

  else {

    uVar1 = *(undefined4 *)(lVar4 + 0x4c);

    *(float *)(lVar4 + 0x44) = param_4;

    *(float *)(lVar4 + 0x48) = param_5;

    FUN_14017cae0(uVar2);

    cVar3 = FUN_140139420(0x1306);

    if (cVar3 != '\0') {

      local_88 = param_5;

      local_a8 = 0x1306;

      local_34 = 0;

      local_2c = 0;

      local_84 = 0;

      uStack_7c = 0;

      local_74 = 0;

      uStack_6c = 0;

      local_64 = 0;

      uStack_5c = 0;

      local_54 = 0;

      uStack_4c = 0;

      local_44 = 0;

      uStack_3c = 0;

      local_a0 = param_1;

      local_94 = param_2;

      local_90 = uVar1;

      local_8c = param_4;

      if (param_3 == (undefined4 *)0x0) {

        local_98 = 0;

        FUN_14013b140(&local_a8);

      }

      else {

        local_98 = *param_3;

        FUN_14013b140(&local_a8);

        lVar5 = FUN_1401611a0();

        if (lVar5 != 0) {

          if (DAT_1403fcd40 == param_2) {

            if (*(char *)(lVar5 + 0xee) != '\0') {

              FUN_1401628f0(param_1,param_3,0xfffffffe,0,param_4,param_5);

            }

            if (*(char *)(lVar5 + 0xef) != '\0') {

              FUN_140186970(param_1,0xfffffffffffffffe,1,param_3,param_4 / (float)(int)param_3[8],

                            param_5 / (float)(int)param_3[9],*(undefined4 *)(lVar4 + 0x28));

            }

          }

          else if ((DAT_1403fcd40 == 0) && (*(char *)(lVar5 + 0xee) != '\0')) {

            FUN_1401628f0(param_1,param_3,0xfffffffe,0,param_4,param_5);

          }

        }

      }

    }

  }

  return;

}




