// Address: 0x14013e8e0
// Ghidra name: FUN_14013e8e0
// ============ 0x14013e8e0 FUN_14013e8e0 (size=449) ============


ulonglong FUN_14013e8e0(uint *param_1)



{

  undefined4 *puVar1;

  int iVar2;

  undefined8 *puVar3;

  char *_Str;

  size_t sVar4;

  ulonglong uVar5;

  longlong lVar6;

  uint uVar7;

  longlong lVar8;

  ulonglong uVar9;

  longlong lVar10;

  undefined8 *puVar11;

  longlong lVar12;

  longlong lVar13;

  undefined4 local_48;

  undefined4 uStack_44;

  undefined4 uStack_40;

  undefined4 uStack_3c;

  

  uVar5 = 0;

  uVar7 = 0;

  if (param_1 != (uint *)0x0) {

    *param_1 = 0;

  }

  FUN_140159d30();

  uVar9 = uVar5;

  puVar1 = DAT_1403fbf18;

  while (puVar1 != (undefined4 *)0x0) {

    iVar2 = memcmp(puVar1,&DAT_1403fbf08,0x10);

    puVar1 = *(undefined4 **)(puVar1 + 10);

    uVar7 = (uint)uVar9 + 1;

    if (iVar2 == 0) {

      uVar7 = (uint)uVar9;

    }

    uVar9 = (ulonglong)uVar7;

  }

  lVar12 = (longlong)(int)uVar7;

  lVar10 = 8;

  puVar3 = (undefined8 *)FUN_1401841a0(lVar12 + 1,8);

  puVar11 = puVar3;

  puVar1 = DAT_1403fbf18;

  if (puVar3 == (undefined8 *)0x0) {

    FUN_14015bb10();

  }

  else {

    for (; puVar1 != (undefined4 *)0x0; puVar1 = *(undefined4 **)(puVar1 + 10)) {

      iVar2 = memcmp(puVar1,&DAT_1403fbf08,0x10);

      if (iVar2 != 0) {

        local_48 = *puVar1;

        uStack_44 = puVar1[1];

        uStack_40 = puVar1[2];

        uStack_3c = puVar1[3];

        _Str = (char *)FUN_14013c130(puVar1,&local_48);

        if (_Str == (char *)0x0) {

          FUN_14015bb10();

          goto LAB_14013ea62;

        }

        *puVar11 = _Str;

        puVar11 = puVar11 + 1;

        sVar4 = strlen(_Str);

        lVar10 = lVar10 + 9 + sVar4;

      }

    }

    FUN_14015bb10();

    uVar5 = FUN_1401841f0(lVar10);

    if (uVar5 != 0) {

      lVar13 = uVar5 + (lVar12 + 1) * 8;

      lVar10 = lVar10 + lVar12 * -8 + -1;

      if (0 < (int)uVar7) {

        lVar8 = lVar12;

        puVar11 = puVar3;

        do {

          *(longlong *)((longlong)puVar11 + (uVar5 - (longlong)puVar3)) = lVar13;

          lVar6 = FUN_14012f1a0(lVar13,*puVar11,lVar10);

          puVar11 = puVar11 + 1;

          lVar10 = lVar10 - (lVar6 + 1);

          lVar13 = lVar13 + lVar6 + 1;

          lVar8 = lVar8 + -1;

        } while (lVar8 != 0);

      }

      *(undefined8 *)(lVar12 * 8 + uVar5) = 0;

      if (param_1 != (uint *)0x0) {

        *param_1 = uVar7;

      }

    }

LAB_14013ea62:

    lVar10 = 0;

    if (0 < (int)uVar7) {

      do {

        FUN_1401841e0(puVar3[lVar10]);

        lVar10 = lVar10 + 1;

      } while (lVar10 < lVar12);

    }

    FUN_1401841e0(puVar3);

  }

  return uVar5;

}




