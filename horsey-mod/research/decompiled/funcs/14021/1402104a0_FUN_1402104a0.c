// Address: 0x1402104a0
// Ghidra name: FUN_1402104a0
// ============ 0x1402104a0 FUN_1402104a0 (size=703) ============


undefined8 FUN_1402104a0(longlong *param_1)



{

  undefined2 uVar1;

  undefined2 uVar2;

  undefined8 *puVar3;

  undefined4 uVar4;

  undefined4 uVar5;

  byte bVar6;

  char cVar7;

  undefined4 uVar8;

  longlong lVar9;

  undefined8 *puVar10;

  longlong lVar11;

  undefined8 uVar12;

  undefined4 *puVar13;

  uint uVar14;

  longlong lVar16;

  ulonglong uVar17;

  undefined1 local_res8;

  undefined1 local_res10;

  undefined1 local_res20 [8];

  ulonglong uVar18;

  undefined1 local_60 [32];

  ulonglong uVar15;

  

  uVar15 = 0;

  local_res10 = 0x67;

  _guard_check_icall();

  lVar9 = (**(code **)(*param_1 + 0x18))(param_1);

  uVar1 = *(undefined2 *)(lVar9 + 6);

  uVar2 = *(undefined2 *)(lVar9 + 4);

  lVar11 = lVar9;

  local_res8 = FUN_140210280();

  bVar6 = FUN_14000c9a0();

  uVar17 = uVar15;

  if (*(longlong *)(lVar11 + 0x128) != 0) {

    uVar17 = *(ulonglong *)(*(longlong *)(lVar11 + 0x128) + 8);

  }

  cVar7 = FUN_14015ba80(uVar2,uVar1,0,uVar17);

  if (((cVar7 != '\0') ||

      (uVar18 = uVar17, cVar7 = FUN_1401599b0(&PTR_FUN_1403e51e0,uVar2,uVar1,0,uVar17),

      cVar7 != '\0')) ||

     ((cVar7 = FUN_140142940("SDL_JOYSTICK_DIRECTINPUT",1), cVar7 != '\0' &&

      ((*(int *)(lVar9 + 0x90) != 0 &&

       (cVar7 = (**(code **)(*param_1 + 0x38))(param_1,0), cVar7 != '\0')))))) {

    return 1;

  }

  cVar7 = FUN_140210780(lVar9);

  if ((cVar7 == '\0') && (bVar6 == 0)) {

    cVar7 = FUN_140142940("SDL_JOYSTICK_DIRECTINPUT",1);

    if (cVar7 != '\0') {

      return 1;

    }

    cVar7 = FUN_1402853c0();

    if (cVar7 != '\0') {

      return 1;

    }

    if ((*(byte *)(lVar9 + 0x68) & 0xe) == 0) {

      return 1;

    }

    local_res10 = 0;

    local_res8 = 0;

  }

  puVar10 = DAT_1403fd3a0;

  if (0 < DAT_1403fd3a8) {

    do {

      puVar3 = (undefined8 *)*puVar10;

      if ((puVar3 != (undefined8 *)0x0) && ((longlong *)*puVar3 == param_1)) {

        *(undefined1 *)((longlong)puVar3 + 0x81) = 0;

        return 1;

      }

      uVar14 = (int)uVar15 + 1;

      uVar15 = (ulonglong)uVar14;

      puVar10 = puVar10 + 1;

    } while ((int)uVar14 < DAT_1403fd3a8);

  }

  puVar10 = (undefined8 *)FUN_1401841a0(1,0x88);

  if (puVar10 == (undefined8 *)0x0) {

    return 0;

  }

  lVar11 = FUN_140184230(DAT_1403fd3a0,(longlong)DAT_1403fd3a8 * 8 + 8);

  if (lVar11 != 0) {

    lVar16 = 0;

    do {

      FUN_14012ef10(local_res20,4,"%02hhX",*(undefined1 *)(lVar9 + 0x20 + lVar16));

      FUN_14012f120(puVar10 + 1,local_res20,0x41);

      lVar16 = lVar16 + 1;

    } while (lVar16 < 0x20);

    (**(code **)(*param_1 + 8))(param_1);

    *puVar10 = param_1;

    uVar12 = FUN_1401578c0(uVar2,uVar1,0,uVar17);

    puVar10[10] = uVar12;

    puVar13 = (undefined4 *)

              FUN_140157780(local_60,3,uVar2,uVar1,uVar18 & 0xffffffffffff0000,0,uVar17,local_res10,

                            local_res8);

    uVar8 = puVar13[1];

    uVar4 = puVar13[2];

    uVar5 = puVar13[3];

    *(undefined4 *)(puVar10 + 0xb) = *puVar13;

    *(undefined4 *)((longlong)puVar10 + 0x5c) = uVar8;

    *(undefined4 *)(puVar10 + 0xc) = uVar4;

    *(undefined4 *)((longlong)puVar10 + 100) = uVar5;

    uVar8 = FUN_1401aa810();

    *(undefined4 *)(puVar10 + 0xd) = uVar8;

    puVar10[0xe] = lVar9;

    *(uint *)(puVar10 + 0xf) = (uint)bVar6;

    *(undefined4 *)((longlong)puVar10 + 0x7c) = 0xffffffff;

    *(undefined8 **)(lVar11 + (longlong)DAT_1403fd3a8 * 8) = puVar10;

    DAT_1403fd3a0 = (undefined8 *)lVar11;

    DAT_1403fd3a8 = DAT_1403fd3a8 + 1;

    return 1;

  }

  FUN_1401841e0(puVar10);

  return 0;

}




