// Address: 0x14016fc90
// Ghidra name: FUN_14016fc90
// ============ 0x14016fc90 FUN_14016fc90 (size=900) ============


undefined8 FUN_14016fc90(longlong param_1,ulonglong param_2)



{

  undefined1 uVar1;

  ulonglong uVar2;

  bool bVar3;

  bool bVar4;

  char cVar5;

  undefined8 uVar6;

  longlong lVar7;

  ulonglong uVar8;

  uint uVar9;

  bool bVar10;

  bool bVar11;

  bool bVar12;

  bool bVar13;

  

  uVar9 = (uint)param_2 & 0x30000002;

  bVar10 = false;

  bVar11 = false;

  bVar4 = false;

  bVar12 = false;

  bVar13 = false;

  if ((uVar9 & uVar9 - 1) != 0) {

    uVar6 = FUN_14012e850("Conflicting window flags specified");

    return uVar6;

  }

  if (((param_2 & 2) != 0) && (*(longlong *)(DAT_1403fc410 + 0x1b8) == 0)) {

    uVar6 = FUN_14016a680("OpenGL");

    return uVar6;

  }

  if (((param_2 >> 0x1c & 1) != 0) && (*(longlong *)(DAT_1403fc410 + 0x210) == 0)) {

    uVar6 = FUN_14016a680("Vulkan");

    return uVar6;

  }

  if (((param_2 >> 0x1d & 1) != 0) && (*(longlong *)(DAT_1403fc410 + 0x228) == 0)) {

    uVar6 = FUN_14016a680("Metal");

    return uVar6;

  }

  uVar8 = param_2 | 0x800;

  if ((*(ulonglong *)(param_1 + 0x48) & 0x800) == 0) {

    uVar8 = param_2 & 0xfffffffffffff7ff;

  }

  if ((*(ulonglong *)(param_1 + 0x48) & 0x1000) != 0) {

    FUN_1401714d0(param_1,0);

  }

  if ((*(uint *)(param_1 + 0x48) >> 0xb & 1) == 0) {

    uVar1 = *(undefined1 *)(param_1 + 0x10a);

    FUN_14016f190(param_1);

    *(undefined1 *)(param_1 + 0x10a) = uVar1;

  }

  bVar3 = false;

  FUN_14016b5e0(param_1);

  uVar2 = *(ulonglong *)(param_1 + 0x48);

  if (((uint)uVar2 & 2) == ((uint)uVar8 & 2)) {

    if ((uVar2 & 2) != 0) {

      bVar10 = true;

      bVar11 = true;

    }

  }

  else {

    bVar10 = (uVar8 & 2) == 0;

    bVar11 = (uVar8 & 2) != 0;

  }

  if (((uint)uVar2 & 0x10000000) == ((uint)uVar8 & 0x10000000)) {

    if ((uVar2 & 0x10000000) != 0) {

      bVar12 = true;

      bVar13 = true;

    }

  }

  else {

    bVar12 = (uVar8 & 0x10000000) == 0;

    bVar13 = (uVar8 & 0x10000000) != 0;

  }

  if (bVar10) {

    FUN_14016cef0();

  }

  if (bVar12) {

    FUN_1401741d0();

  }

  if ((*(code **)(DAT_1403fc410 + 0x130) != (code *)0x0) && ((uVar8 >> 0xb & 1) == 0)) {

    (**(code **)(DAT_1403fc410 + 0x130))(DAT_1403fc410,param_1);

  }

  if (bVar11) {

    cVar5 = FUN_14016c850(0);

    if (cVar5 != '\0') {

      bVar3 = true;

      goto LAB_14016fe65;

    }

LAB_14016ff08:

    uVar6 = 0;

  }

  else {

LAB_14016fe65:

    if (bVar13) {

      cVar5 = FUN_140174130(0);

      if (cVar5 == '\0') goto LAB_14016ff08;

      bVar4 = true;

    }

    lVar7 = DAT_1403fc410;

    *(undefined1 *)(param_1 + 0x10f) = 0;

    *(ulonglong *)(param_1 + 0x48) = uVar8 & 0xf02f2072 | 8;

    if (*(longlong *)(lVar7 + 0x48) == 0) {

      if ((uVar8 >> 0xb & 1) != 0) goto LAB_14016ff1f;

    }

    else {

      if ((uVar8 >> 0xb & 1) == 0) {

        *(undefined4 *)(param_1 + 0x6c) = *(undefined4 *)(param_1 + 0x7c);

        *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x7c);

        *(undefined4 *)(param_1 + 0x70) = *(undefined4 *)(param_1 + 0x80);

        *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x80);

        *(undefined4 *)(param_1 + 0x74) = *(undefined4 *)(param_1 + 0x84);

        *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_1 + 0x84);

        *(undefined4 *)(param_1 + 0x78) = *(undefined4 *)(param_1 + 0x88);

        *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(param_1 + 0x88);

        cVar5 = (**(code **)(lVar7 + 0x48))(lVar7,param_1,0);

        lVar7 = DAT_1403fc410;

        if (cVar5 != '\0') goto LAB_14016ff27;

        if (bVar3) {

          FUN_14016cef0();

          *(ulonglong *)(param_1 + 0x48) = *(ulonglong *)(param_1 + 0x48) & 0xfffffffffffffffd;

        }

        if (bVar4) {

          FUN_1401741d0();

          *(ulonglong *)(param_1 + 0x48) = *(ulonglong *)(param_1 + 0x48) & 0xffffffffefffffff;

        }

        goto LAB_14016ff08;

      }

LAB_14016ff1f:

      *(ulonglong *)(param_1 + 0x48) = *(ulonglong *)(param_1 + 0x48) | 0x800;

    }

LAB_14016ff27:

    if ((*(code **)(lVar7 + 0x50) != (code *)0x0) && (*(longlong *)(param_1 + 8) != 0)) {

      (**(code **)(lVar7 + 0x50))(lVar7,param_1);

      lVar7 = DAT_1403fc410;

    }

    if ((*(code **)(lVar7 + 0x58) != (code *)0x0) && (*(longlong *)(param_1 + 0x10) != 0)) {

      (**(code **)(lVar7 + 0x58))(lVar7,param_1);

      lVar7 = DAT_1403fc410;

    }

    if ((*(code **)(lVar7 + 0x70) != (code *)0x0) &&

       ((*(int *)(param_1 + 0x28) != 0 || (*(int *)(param_1 + 0x2c) != 0)))) {

      (**(code **)(lVar7 + 0x70))(lVar7,param_1);

      lVar7 = DAT_1403fc410;

    }

    if ((*(code **)(lVar7 + 0x78) != (code *)0x0) &&

       ((*(int *)(param_1 + 0x30) != 0 || (*(int *)(param_1 + 0x34) != 0)))) {

      (**(code **)(lVar7 + 0x78))(lVar7,param_1);

      lVar7 = DAT_1403fc410;

    }

    if ((*(code **)(lVar7 + 0x80) != (code *)0x0) &&

       ((0.0 < *(float *)(param_1 + 0x38) || (0.0 < *(float *)(param_1 + 0x3c))))) {

      (**(code **)(lVar7 + 0x80))(lVar7,param_1);

      lVar7 = DAT_1403fc410;

    }

    if (*(longlong *)(param_1 + 0x160) != 0) {

      (**(code **)(lVar7 + 0x2f8))(param_1,1);

    }

    FUN_14016bc90(param_1,uVar8);

    uVar6 = 1;

  }

  return uVar6;

}




