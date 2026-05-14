// Address: 0x1401a8cc0
// Ghidra name: FUN_1401a8cc0
// ============ 0x1401a8cc0 FUN_1401a8cc0 (size=661) ============


void FUN_1401a8cc0(undefined8 param_1,int param_2,longlong param_3,char param_4,char param_5)



{

  bool bVar1;

  char cVar2;

  longlong lVar3;

  longlong lVar4;

  uint uVar5;

  float fVar6;

  float fVar7;

  undefined4 uVar8;

  

  fVar7 = 0.0;

  bVar1 = false;

  fVar6 = 0.0;

  FUN_14017caa0(DAT_1403fcd48);

  lVar3 = FUN_1401a8110(param_2);

  if (lVar3 != 0) {

    uVar5 = *(uint *)(lVar3 + 0x4c);

    fVar6 = *(float *)(lVar3 + 0x44);

    fVar7 = *(float *)(lVar3 + 0x48);

    bVar1 = false;

    if (param_5 == '\0') {

      if ((uVar5 & 1) != 0) {

        uVar5 = uVar5 & 0xfffffffe;

        goto LAB_1401a8d48;

      }

    }

    else if ((uVar5 & 1) == 0) {

      uVar5 = uVar5 | 1;

LAB_1401a8d48:

      bVar1 = true;

    }

    if (param_4 == '\0') {

      if ((uVar5 & 0x40000000) != 0) {

        uVar5 = uVar5 & 0xbfffffff;

        goto LAB_1401a8d69;

      }

    }

    else if ((uVar5 & 0x40000000) == 0) {

      uVar5 = uVar5 | 0x40000000;

LAB_1401a8d69:

      bVar1 = true;

    }

    *(uint *)(lVar3 + 0x4c) = uVar5;

  }

  FUN_14017cae0(DAT_1403fcd48);

  if (!bVar1) {

    return;

  }

  cVar2 = FUN_140139420();

  if (cVar2 != '\0') {

    FUN_14013b140();

  }

  lVar4 = FUN_1401611a0();

  if ((lVar4 == 0) || (param_3 == 0)) goto LAB_1401a8f02;

  if (*(char *)(lVar4 + 0xee) != '\0') {

    if (param_5 == '\0') {

      if (DAT_1403fcd40 == param_2) {

        uVar8 = 0;

        goto LAB_1401a8e7b;

      }

    }

    else if (DAT_1403fcd40 == 0) {

      FUN_1401628f0(param_1,param_3,0xfffffffe,0,fVar6,fVar7);

      uVar8 = 1;

LAB_1401a8e7b:

      FUN_1401628d0(param_1,param_3,0xfffffffe,1,uVar8);

    }

  }

  if ((*(char *)(lVar4 + 0xef) != '\0') && ((DAT_1403fcd40 == 0 || (DAT_1403fcd40 == param_2)))) {

    FUN_1401865d0(param_1,0xfffffffffffffffe,1,param_3,0x701 - (uint)(param_5 != '\0'),

                  fVar6 / (float)*(int *)(param_3 + 0x20),fVar7 / (float)*(int *)(param_3 + 0x24),

                  *(undefined4 *)(lVar3 + 0x28));

  }

LAB_1401a8f02:

  if (param_5 == '\0') {

    if (DAT_1403fcd40 == param_2) {

      DAT_1403fcd40 = 0;

    }

  }

  else if (DAT_1403fcd40 == 0) {

    DAT_1403fcd40 = param_2;

  }

  return;

}




