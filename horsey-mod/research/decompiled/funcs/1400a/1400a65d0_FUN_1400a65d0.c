// Address: 0x1400a65d0
// Ghidra name: FUN_1400a65d0
// ============ 0x1400a65d0 FUN_1400a65d0 (size=920) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1400a65d0(undefined8 param_1,int param_2)



{

  undefined8 uVar1;

  longlong lVar2;

  ulonglong uVar3;

  longlong lVar4;

  ulonglong uVar5;

  undefined8 ****ppppuVar6;

  ulonglong uVar7;

  ulonglong uVar8;

  undefined8 *puVar9;

  longlong lVar10;

  uint uVar11;

  ulonglong uVar13;

  undefined8 *puVar14;

  undefined8 ***local_80;

  undefined8 uStack_78;

  undefined8 local_70;

  ulonglong uStack_68;

  ulonglong uVar12;

  

  lVar2 = FUN_1402c704c(0xd8);

  uVar7 = 0;

  uVar3 = uVar7;

  if (lVar2 != 0) {

    uVar3 = FUN_140025490(lVar2,&DAT_14030ccfc);

  }

  uStack_78 = 0;

  local_70 = _DAT_140305680;

  uStack_68 = _UNK_140305688;

  local_80 = (undefined8 ****)0x656d616e;

  lVar2 = (longlong)param_2 * 0x1018;

  FUN_140025980(uVar3,&local_80);

  if (0xf < uStack_68) {

    if ((0xfff < uStack_68 + 1) &&

       (0x1f < (ulonglong)((longlong)local_80 + (-8 - (longlong)local_80[-1])))) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088();

  }

  uVar8 = _UNK_14030cd48;

  uVar1 = _DAT_14030cd40;

  puVar14 = &DAT_1403f11a0;

  lVar4 = DAT_1403f2fc0;

  uVar12 = uVar7;

  uVar13 = uVar7;

  do {

    if (*(char *)(lVar4 + 0xf28 + lVar2) == '\0') {

      lVar4 = FUN_1402c704c(0xd8);

      uVar5 = uVar7;

      if (lVar4 != 0) {

        uVar5 = FUN_140025490(lVar4,&DAT_14030ccd8);

      }

      puVar9 = &DAT_1403f11a0 + (longlong)(int)uVar12 * 4;

      if (0xf < (ulonglong)puVar14[3]) {

        puVar9 = (undefined8 *)*puVar14;

      }

      FUN_140025930(uVar5,&DAT_140304430,puVar9);

      uStack_78 = 0;

      local_70 = uVar1;

      uStack_68 = uVar8;

      local_80 = (undefined8 ****)0x3070;

      lVar4 = (longlong)param_2 * 0x406;

      if (0 < *(int *)(DAT_1403f2fc0 + (uVar13 + lVar4) * 4 + 0x28)) {

        local_80 = (undefined8 ****)0x3070;

        FUN_140025900(uVar5,&local_80);

      }

      if (0 < *(int *)((lVar4 + uVar13) * 4 + 0x2c + DAT_1403f2fc0)) {

        ppppuVar6 = &local_80;

        if (0xf < uStack_68) {

          ppppuVar6 = (undefined8 ****)local_80;

        }

        *(undefined1 *)((longlong)ppppuVar6 + 1) = 0x31;

        FUN_140025900(uVar5,&local_80);

      }

      if (0 < *(int *)((lVar4 + uVar13) * 4 + 0x30 + DAT_1403f2fc0)) {

        ppppuVar6 = &local_80;

        if (0xf < uStack_68) {

          ppppuVar6 = (undefined8 ****)local_80;

        }

        *(undefined1 *)((longlong)ppppuVar6 + 1) = 0x32;

        FUN_140025900(uVar5,&local_80);

      }

      if (0 < *(int *)((lVar4 + uVar13) * 4 + 0x34 + DAT_1403f2fc0)) {

        ppppuVar6 = &local_80;

        if (0xf < uStack_68) {

          ppppuVar6 = (undefined8 ****)local_80;

        }

        *(undefined1 *)((longlong)ppppuVar6 + 1) = 0x33;

        FUN_140025900(uVar5,&local_80);

      }

      FUN_140025120(uVar3,uVar5);

      lVar4 = DAT_1403f2fc0;

      if (0xf < uStack_68) {

        if ((0xfff < uStack_68 + 1) &&

           (0x1f < (ulonglong)((longlong)local_80 + (-8 - (longlong)local_80[-1])))) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088();

        lVar4 = DAT_1403f2fc0;

      }

    }

    uVar11 = (int)uVar12 + 1;

    uVar12 = (ulonglong)uVar11;

    lVar2 = lVar2 + 1;

    puVar14 = puVar14 + 4;

    uVar13 = uVar13 + 4;

    if (0xef < (int)uVar11) {

      lVar2 = DAT_1403f2fc8 - lVar4 >> 0x3f;

      uVar8 = uVar7;

      lVar10 = DAT_1403f2fc8;

      if ((DAT_1403f2fc8 - lVar4) / 0x1018 + lVar2 != lVar2) {

        do {

          if (*(int *)(uVar8 + 4 + lVar4) == param_2) {

            FUN_1400a65d0(uVar3,uVar7);

            lVar4 = DAT_1403f2fc0;

            lVar10 = DAT_1403f2fc8;

          }

          uVar11 = (int)uVar7 + 1;

          uVar7 = (ulonglong)uVar11;

          uVar8 = uVar8 + 0x1018;

        } while ((ulonglong)(longlong)(int)uVar11 < (ulonglong)((lVar10 - lVar4) / 0x1018));

      }

      FUN_140025120(param_1,uVar3);

      return;

    }

  } while( true );

}




