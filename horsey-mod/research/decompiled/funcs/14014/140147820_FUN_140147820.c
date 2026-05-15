// Address: 0x140147820
// Ghidra name: FUN_140147820
// ============ 0x140147820 FUN_140147820 (size=856) ============


ulonglong FUN_140147820(byte *param_1,int param_2,int param_3,float *param_4,float *param_5,

                       float *param_6,float *param_7)



{

  uint uVar1;

  float fVar2;

  float fVar3;

  char cVar4;

  byte bVar5;

  undefined4 uVar6;

  ulonglong uVar7;

  longlong lVar8;

  ulonglong uVar9;

  uint uVar10;

  undefined8 *puVar11;

  char *pcVar12;

  float *pfVar13;

  float *pfVar14;

  float *pfVar15;

  byte local_res20 [8];

  undefined8 in_stack_ffffffffffffff78;

  undefined4 uVar16;

  undefined8 in_stack_ffffffffffffff88;

  undefined4 uVar17;

  float local_48 [2];

  undefined8 local_40;

  undefined8 uStack_38;

  

  uVar16 = (undefined4)((ulonglong)in_stack_ffffffffffffff78 >> 0x20);

  uVar17 = (undefined4)((ulonglong)in_stack_ffffffffffffff88 >> 0x20);

  uVar9 = 0;

  if (param_4 == (float *)0x0) {

    param_4 = local_48;

  }

  else {

    *param_4 = 0.0;

  }

  if (param_5 == (float *)0x0) {

    pfVar14 = local_48;

  }

  else {

    *param_5 = 0.0;

    pfVar14 = param_5;

  }

  if (param_6 == (float *)0x0) {

    pfVar13 = local_48;

  }

  else {

    *param_6 = 0.0;

    pfVar13 = param_6;

  }

  if (param_7 == (float *)0x0) {

    pfVar15 = local_48;

  }

  else {

    *param_7 = 0.0;

    pfVar15 = param_7;

  }

  cVar4 = FUN_1401489c0();

  if (((cVar4 == '\0') || (uVar1 = *(uint *)(param_1 + 4), uVar1 == 0)) ||

     (*(longlong *)(param_1 + 0x18) == 0)) {

    pcVar12 = "surface";

LAB_140147b4b:

    uVar9 = FUN_14012e850("Parameter \'%s\' is invalid",pcVar12);

    return uVar9;

  }

  if ((param_2 < 0) || (*(int *)(param_1 + 8) <= param_2)) {

    pcVar12 = "x";

    goto LAB_140147b4b;

  }

  if ((param_3 < 0) || (*(int *)(param_1 + 0xc) <= param_3)) {

    pcVar12 = "y";

    goto LAB_140147b4b;

  }

  if ((uVar1 & 0xf0000000) != 0x10000000) {

    lVar8 = FUN_140145bb0(param_1,0x16362004);

    if (lVar8 == 0) {

      return 0;

    }

    bVar5 = FUN_140147820(lVar8,param_2,param_3,param_4,pfVar14,pfVar13,pfVar15);

    FUN_140146010(lVar8);

    return (ulonglong)bVar5;

  }

  if ((byte)uVar1 < 5) {

    cVar4 = FUN_140147b80(param_1,param_2,param_3,&param_5,&param_6,&param_7,local_res20);

    if (cVar4 == '\0') {

      return 0;

    }

    *param_4 = (float)(byte)param_5 / DAT_14030a2d0;

    *pfVar14 = (float)(byte)param_6 / DAT_14030a2d0;

    *pfVar13 = (float)(byte)param_7 / DAT_14030a2d0;

    *pfVar15 = (float)local_res20[0] / DAT_14030a2d0;

    return 1;

  }

  if (((*param_1 & 2) != 0) && (uVar7 = FUN_140146f20(param_1), (char)uVar7 == '\0')) {

    return uVar7;

  }

  uVar1 = *(uint *)(param_1 + 4);

  if ((uVar1 == 0) || ((uVar1 & 0xf0000000) == 0x10000000)) {

    uVar10 = uVar1 & 0xff;

  }

  else if ((((uVar1 == 0x32595559) || (uVar1 == 0x59565955)) || (uVar1 == 0x55595659)) ||

          (uVar1 == 0x30313050)) {

    uVar10 = 2;

  }

  else {

    uVar10 = 1;

  }

  puVar11 = (undefined8 *)

            ((longlong)(*(int *)(param_1 + 0x10) * param_3) + (longlong)(int)(uVar10 * param_2) +

            *(longlong *)(param_1 + 0x18));

  if (uVar1 == 0x1b208010) {

    local_40 = *puVar11;

    uStack_38 = puVar11[1];

  }

  else {

    uVar6 = 0x120005a0;

    if (*(int *)(param_1 + 0x40) == 0x12000500) {

      uVar6 = 0x12000500;

    }

    cVar4 = FUN_140144d60(1,1,uVar1,*(int *)(param_1 + 0x40),

                          CONCAT44(uVar16,*(undefined4 *)(param_1 + 0x34)),puVar11,

                          CONCAT44(uVar17,*(int *)(param_1 + 0x10)),0x1b208010,uVar6,0,&local_40,

                          0x10);

    if (cVar4 == '\0') goto LAB_140147ad9;

  }

  uVar9 = 1;

  fVar2 = local_40._4_4_;

  *param_4 = (float)local_40;

  fVar3 = (float)uStack_38;

  *pfVar14 = fVar2;

  fVar2 = uStack_38._4_4_;

  *pfVar13 = fVar3;

  *pfVar15 = fVar2;

LAB_140147ad9:

  if ((*param_1 & 2) == 0) {

    return uVar9;

  }

  FUN_1401489e0(param_1);

  return uVar9;

}




