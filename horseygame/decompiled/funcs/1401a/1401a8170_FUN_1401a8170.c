// Address: 0x1401a8170
// Ghidra name: FUN_1401a8170
// ============ 0x1401a8170 FUN_1401a8170 (size=329) ============


int FUN_1401a8170(undefined8 param_1,char *param_2,undefined8 param_3,int *param_4,

                 undefined8 param_5,char param_6)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  longlong lVar5;

  longlong lVar6;

  char *pcVar7;

  int *piVar8;

  longlong lVar9;

  

  pcVar7 = "Unnamed pen";

  if (param_2 != (char *)0x0) {

    pcVar7 = param_2;

  }

  lVar5 = FUN_14012f0d0(pcVar7);

  if (lVar5 == 0) {

    return 0;

  }

  piVar8 = (int *)0x0;

  FUN_14017cab0(DAT_1403fcd48);

  iVar4 = 0;

  lVar6 = FUN_140184230(DAT_1403fcd50,(longlong)(DAT_1403fcd44 + 1) * 0x60);

  if (lVar6 != 0) {

    iVar4 = FUN_1401aa810();

    lVar9 = (longlong)DAT_1403fcd44;

    DAT_1403fcd44 = DAT_1403fcd44 + 1;

    piVar8 = (int *)(lVar9 * 0x60 + lVar6);

    DAT_1403fcd50 = lVar6;

    piVar8[0] = 0;

    piVar8[1] = 0;

    piVar8[2] = 0;

    piVar8[3] = 0;

    piVar8[4] = 0;

    piVar8[5] = 0;

    piVar8[6] = 0;

    piVar8[7] = 0;

    piVar8[8] = 0;

    piVar8[9] = 0;

    piVar8[10] = 0;

    piVar8[0xb] = 0;

    piVar8[0xc] = 0;

    piVar8[0xd] = 0;

    piVar8[0xe] = 0;

    piVar8[0xf] = 0;

    piVar8[0x10] = 0;

    piVar8[0x11] = 0;

    piVar8[0x12] = 0;

    piVar8[0x13] = 0;

    piVar8[0x14] = 0;

    piVar8[0x15] = 0;

    piVar8[0x16] = 0;

    piVar8[0x17] = 0;

    *piVar8 = iVar4;

    *(longlong *)(piVar8 + 2) = lVar5;

    if (param_4 != (int *)0x0) {

      iVar1 = param_4[1];

      iVar2 = param_4[2];

      iVar3 = param_4[3];

      piVar8[4] = *param_4;

      piVar8[5] = iVar1;

      piVar8[6] = iVar2;

      piVar8[7] = iVar3;

      *(undefined8 *)(piVar8 + 8) = *(undefined8 *)(param_4 + 4);

    }

    *(undefined8 *)(piVar8 + 0x16) = param_5;

  }

  FUN_14017cae0(DAT_1403fcd48);

  if (piVar8 == (int *)0x0) {

    FUN_1401841e0(lVar5);

  }

  if ((iVar4 != 0) && (param_6 != '\0')) {

    FUN_1401a8b60(param_1,iVar4,param_3,1,1);

  }

  return iVar4;

}




