// Address: 0x140080730
// Ghidra name: FUN_140080730
// ============ 0x140080730 FUN_140080730 (size=766) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140080730(longlong param_1,longlong param_2,char param_3,char param_4)



{

  int iVar1;

  uint uVar2;

  undefined4 uVar3;

  undefined8 uVar4;

  int iVar5;

  float fVar6;

  float fVar7;

  

  *(longlong *)(param_1 + 0x80) = param_2;

  uVar3 = 1;

  if (*(char *)(param_2 + 0x1a) != '\0') {

    uVar3 = 0xffffffff;

  }

  *(undefined4 *)(param_1 + 0x38) = uVar3;

  *(float *)(param_1 + 0x30) = *(float *)(param_2 + 300) * DAT_140303750;

  *(float *)(param_1 + 0x34) = (float)(*(uint *)(param_2 + 0x130) & _DAT_14039cab0) * DAT_140303750;

  *(float *)(param_1 + 0x88) = *(float *)(param_2 + 0x130) * DAT_14039ca34;

  iVar1 = *(int *)(param_2 + 0x24c);

  *(bool *)(param_1 + 0xb0) = iVar1 == 2;

  uVar2 = 2;

  *(undefined4 *)(param_1 + 0x48) = 2;

  if (*(char *)(param_2 + 0x161) == '\0') {

    *(undefined4 *)(param_1 + 0x48) = 3;

    uVar2 = 3;

    if ((*(char *)(param_2 + 0x161) == '\0') && (iVar1 == 2)) goto LAB_1400807f4;

  }

  *(uint *)(param_1 + 0x48) = uVar2 | 0x10;

LAB_1400807f4:

  *(undefined4 *)(param_1 + 0xa8) = 0x3e800000;

  if ((*(char *)(param_2 + 0x155) == '\0') ||

     (fVar7 = DAT_14030335c, (*(byte *)(param_2 + 600) & 0x70) != 0)) {

    *(undefined4 *)(param_1 + 0xa8) = 0;

    fVar7 = 0.0;

  }

  fVar6 = DAT_14030ad50;

  if (-1 < *(int *)(param_2 + 0x234)) {

    *(undefined4 *)(param_1 + 0xa8) = 0x3ccccccd;

    *(undefined1 *)(param_1 + 0xb0) = 1;

    fVar7 = fVar6;

  }

  if ((*(uint *)(param_2 + 600) & 0x800000) != 0) {

    *(undefined1 *)(param_1 + 0xb0) = 0;

  }

  fVar6 = *(float *)(param_2 + 0x158) * DAT_1403053e8;

  *(undefined4 *)(param_1 + 0x98) = 3;

  iVar5 = (int)fVar6;

  *(int *)(param_1 + 0x8c) = iVar5;

  iVar1 = (iVar5 * 4) / 5;

  *(int *)(param_1 + 0x94) = iVar1;

  *(int *)(param_1 + 0x90) = (iVar5 * 9) / 10;

  uVar4 = 10;

  fVar6 = *(float *)(param_2 + 0x148) * DAT_14030a23c;

  *(undefined4 *)(param_1 + 0xac) = 10;

  *(undefined4 *)(param_1 + 0xa0) = 0xc;

  *(undefined4 *)(param_1 + 0xa4) = 4;

  *(int *)(param_1 + 0x9c) = 4 - (int)fVar6;

  if (*(int *)(param_2 + 0x24c) == 2) {

    *(undefined4 *)(param_1 + 0xa4) = 8;

    uVar4 = 0x14;

    *(undefined4 *)(param_1 + 0xac) = 0x14;

    *(float *)(param_1 + 0xa8) = fVar7 + fVar7;

  }

  else {

    *(undefined1 *)(param_1 + 0xc4) = 1;

  }

  if (param_3 == '\0') {

    if (param_4 == '\0') {

      uVar3 = FUN_1400c65c0(iVar1 / 2,iVar1);

      *(undefined4 *)(param_1 + 0x74) = uVar3;

      uVar3 = FUN_1400c6580(*(undefined4 *)(param_1 + 0xac));

      FUN_140080cc0(param_1,0,uVar3);

      uVar3 = FUN_1400c6580(0x3c);

      *(undefined4 *)(param_1 + 0x18) = uVar3;

      return;

    }

    *(int *)(param_1 + 0x74) = iVar5;

    return;

  }

  if ((*(char *)(param_2 + 0x205) != '\0') || (*(char *)(param_2 + 0x206) != '\0')) {

    iVar5 = iVar1;

  }

  *(int *)(param_1 + 0x74) = iVar5;

  *(int *)(param_1 + 0x7c) = *(int *)(param_2 + 0x1fc) * 0x78;

  if (*(int *)(param_2 + 0x1c) != 6) {

    if (*(int *)(param_2 + 0x1c) != 4) {

      FUN_140080e40(param_1);

      return;

    }

    FUN_140080cc0(param_1,0xb,uVar4);

    return;

  }

  FUN_140080cc0(param_1,0xd,0);

  return;

}




