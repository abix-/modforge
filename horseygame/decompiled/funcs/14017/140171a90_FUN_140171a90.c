// Address: 0x140171a90
// Ghidra name: FUN_140171a90
// ============ 0x140171a90 FUN_140171a90 (size=575) ============


ulonglong FUN_140171a90(longlong param_1,uint param_2,uint param_3)



{

  int iVar1;

  int iVar2;

  code *pcVar3;

  char cVar4;

  byte bVar5;

  uint uVar6;

  undefined4 uVar7;

  int iVar8;

  uint uVar9;

  ulonglong uVar10;

  longlong lVar11;

  uint uVar12;

  uint uVar13;

  bool bVar14;

  undefined8 local_38;

  undefined8 uStack_30;

  

  if (DAT_1403fc410 == 0) {

    uVar10 = FUN_1401730c0();

    return uVar10 & 0xffffffffffffff00;

  }

  if ((param_1 == 0) ||

     ((DAT_1403e3d60 != '\0' && (cVar4 = FUN_1401aa7c0(param_1,1), cVar4 == '\0')))) {

    uVar10 = FUN_14012e850("Invalid window");

    return uVar10 & 0xffffffffffffff00;

  }

  bVar14 = *(char *)(param_1 + 0x10c) == '\0';

  lVar11 = 0x94;

  if (bVar14) {

    lVar11 = 0x74;

  }

  iVar1 = *(int *)(lVar11 + param_1);

  lVar11 = 0x98;

  if (bVar14) {

    lVar11 = 0x78;

  }

  iVar2 = *(int *)(lVar11 + param_1);

  uVar6 = FUN_14016d540(param_1);

  *(undefined4 *)(param_1 + 0x68) = 0;

  if ((param_2 & 0xffff0000) == 0x1fff0000) {

    param_2 = *(uint *)(param_1 + 0x6c);

  }

  if ((param_3 & 0xffff0000) == 0x1fff0000) {

    param_3 = *(uint *)(param_1 + 0x70);

  }

  uVar13 = param_2 & 0xffff0000;

  uVar12 = param_3 & 0xffff0000;

  if (uVar13 == 0x2fff0000) {

LAB_140171b94:

    uVar9 = param_2 & 0xffff;

    if (uVar9 == 0) goto LAB_140171b9f;

LAB_140171bb7:

    iVar8 = FUN_14016d5f0(uVar9);

    if (iVar8 < 0) goto LAB_140171bc2;

  }

  else {

    if (uVar12 != 0x2fff0000) {

      uVar7 = FUN_140169c90(param_2,param_3);

      *(undefined4 *)(param_1 + 0x68) = uVar7;

      goto LAB_140171c5f;

    }

    if (uVar13 == 0x2fff0000) goto LAB_140171b94;

LAB_140171b9f:

    if (((uVar12 == 0x2fff0000) && (uVar9 = param_3 & 0xffff, uVar9 != 0)) ||

       (uVar9 = uVar6, uVar6 != 0)) goto LAB_140171bb7;

LAB_140171bc2:

    uVar9 = FUN_14016dba0();

  }

  *(uint *)(param_1 + 0x68) = uVar9;

  local_38 = 0;

  uStack_30 = 0;

  cVar4 = FUN_14016d6c0(uVar9,&local_38);

  if (((cVar4 == '\0') || ((int)uStack_30 < iVar1)) || (uStack_30._4_4_ < iVar2)) {

    uVar10 = FUN_14016d280(uVar9,&local_38);

    if ((char)uVar10 == '\0') {

      return uVar10;

    }

  }

  if (uVar13 == 0x2fff0000) {

    param_2 = ((int)uStack_30 - iVar1) / 2 + (int)local_38;

  }

  if (uVar12 == 0x2fff0000) {

    param_3 = (uStack_30._4_4_ - iVar2) / 2 + local_38._4_4_;

  }

LAB_140171c5f:

  lVar11 = DAT_1403fc410;

  *(uint *)(param_1 + 0x8c) = param_2;

  *(uint *)(param_1 + 0x90) = param_3;

  *(undefined2 *)(param_1 + 0x9d) = 0;

  *(undefined1 *)(param_1 + 0x10b) = 1;

  pcVar3 = *(code **)(lVar11 + 0x60);

  if (pcVar3 == (code *)0x0) {

    uVar10 = FUN_14012e850("That operation is not supported");

  }

  else {

    bVar5 = (*pcVar3)(lVar11,param_1);

    if (bVar5 != 0) {

      FUN_140172f30(param_1);

    }

    uVar10 = (ulonglong)bVar5;

  }

  return uVar10;

}




