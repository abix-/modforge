// Address: 0x1400a4e00
// Ghidra name: FUN_1400a4e00
// ============ 0x1400a4e00 FUN_1400a4e00 (size=468) ============


void FUN_1400a4e00(void)



{

  ulonglong uVar1;

  longlong lVar2;

  undefined8 uVar3;

  undefined8 *puVar4;

  undefined8 ****ppppuVar5;

  ulonglong uVar6;

  undefined8 ***local_d8;

  undefined8 uStack_d0;

  ulonglong local_c8;

  ulonglong uStack_c0;

  undefined **local_b8 [14];

  undefined1 local_48 [48];

  

  FUN_140025e00(local_b8);

  lVar2 = FUN_1402c704c(0xd8);

  if (lVar2 == 0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_140025490(lVar2,&DAT_14030cd00);

  }

  FUN_140025120(local_b8,uVar3);

  FUN_1400a65d0(uVar3,0);

  puVar4 = (undefined8 *)FUN_1400c4e00();

  lVar2 = puVar4[2];

  if (6 < 0x7fffffffffffffffU - lVar2) {

    if (0xf < (ulonglong)puVar4[3]) {

      puVar4 = (undefined8 *)*puVar4;

    }

    local_d8 = (undefined8 ****)0x0;

    uStack_d0 = 0;

    local_c8 = 0;

    uStack_c0 = 0;

    uVar1 = lVar2 + 7;

    uVar6 = 0xf;

    ppppuVar5 = &local_d8;

    if (0xf < uVar1) {

      uVar6 = uVar1 | 0xf;

      if (uVar6 < 0x8000000000000000) {

        if (uVar6 < 0x16) {

          uVar6 = 0x16;

        }

      }

      else {

        uVar6 = 0x7fffffffffffffff;

      }

      ppppuVar5 = (undefined8 ****)FUN_1400285e0(uVar6 + 1);

      local_d8 = ppppuVar5;

    }

    local_c8 = uVar1;

    uStack_c0 = uVar6;

    FUN_1402f8e20(ppppuVar5,puVar4);

    *(undefined4 *)((longlong)ppppuVar5 + lVar2) = (undefined4)DAT_14030cce0;

    *(undefined2 *)((longlong)ppppuVar5 + lVar2 + 4) = DAT_14030cce0._4_2_;

    *(undefined1 *)((longlong)ppppuVar5 + lVar2 + 6) = DAT_14030cce0._6_1_;

    *(undefined1 *)((longlong)ppppuVar5 + uVar1) = 0;

    ppppuVar5 = &local_d8;

    if (0xf < uStack_c0) {

      ppppuVar5 = (undefined8 ****)local_d8;

    }

    FUN_1400262c0(local_b8,ppppuVar5);

    if (0xf < uStack_c0) {

      if (0xfff < uStack_c0 + 1) {

        if (0x1f < (ulonglong)((longlong)local_d8 + (-8 - (longlong)local_d8[-1]))) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

      }

      FUN_1402c7088();

    }

    local_b8[0] = TiXmlDocument::vftable;

    FUN_140027900(local_48);

    FUN_140024a60(local_b8);

    return;

  }

                    /* WARNING: Subroutine does not return */

  FUN_140024130();

}




