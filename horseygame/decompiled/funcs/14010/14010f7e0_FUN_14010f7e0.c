// Address: 0x14010f7e0
// Ghidra name: FUN_14010f7e0
// ============ 0x14010f7e0 FUN_14010f7e0 (size=1050) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_14010f7e0(longlong param_1)



{

  float fVar1;

  undefined4 uVar2;

  int iVar3;

  int iVar4;

  undefined8 *puVar5;

  undefined4 uVar6;

  undefined1 auVar7 [16];

  undefined8 in_stack_ffffffffffffff98;

  undefined4 uVar9;

  undefined8 uVar8;

  longlong local_48 [3];

  ulonglong local_30;

  

  uVar9 = (undefined4)((ulonglong)in_stack_ffffffffffffff98 >> 0x20);

  if ((*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) + 4)

       < DAT_1403fb458) && (FUN_1402c7138(&DAT_1403fb458), DAT_1403fb458 == -1)) {

    atexit(FUN_140301080);

    _Init_thread_footer(&DAT_1403fb458);

  }

  if (*(int *)(param_1 + 0x308) != DAT_1403dc3b8) {

    DAT_1403dc3b8 = *(int *)(param_1 + 0x308);

    puVar5 = (undefined8 *)FUN_14008d760(local_48,&DAT_140307a38);

    if ((undefined8 **)puVar5 != &DAT_1403dc3c0) {

      if (0xf < DAT_1403dc3d8) {

        if ((0xfff < DAT_1403dc3d8 + 1) &&

           (0x1f < (ulonglong)((longlong)DAT_1403dc3c0 + (-8 - DAT_1403dc3c0[-1]))))

        goto LAB_14010fbe3;

        FUN_1402c7088();

      }

      DAT_1403dc3c0 = (undefined8 *)*puVar5;

      uRam00000001403dc3c8 = puVar5[1];

      _DAT_1403dc3d0 = puVar5[2];

      DAT_1403dc3d8 = puVar5[3];

      puVar5[2] = 0;

      puVar5[3] = 0xf;

      *(undefined1 *)puVar5 = 0;

    }

    if (0xf < local_30) {

      if ((0xfff < local_30 + 1) && (0x1f < (local_48[0] - *(longlong *)(local_48[0] + -8)) - 8U)) {

LAB_14010fbe3:

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088();

    }

    puVar5 = &DAT_1403dc3c0;

    if (0xf < DAT_1403dc3d8) {

      puVar5 = DAT_1403dc3c0;

    }

    DAT_1403fb45c = FUN_140086450(DAT_1403ede20,puVar5);

  }

  uVar6 = DAT_1403dc2ec;

  iVar3 = DAT_1403ed998 + 4;

  auVar7 = ZEXT416((uint)(float)iVar3);

  if (0 < *(int *)(param_1 + 0x30c)) {

    iVar4 = *(int *)(param_1 + 0x30c) + -1;

    *(int *)(param_1 + 0x30c) = iVar4;

    if (*(int *)(param_1 + 0x310) < 1) {

      if ((*(int *)(param_1 + 0x310) < 0) && (0x32 < iVar4)) {

        uVar6 = DAT_1403dc318;

      }

    }

    else if (0x32 < iVar4) {

      auVar7 = ZEXT416((uint)((float)iVar3 + DAT_14039ca80));

    }

  }

  fVar1 = DAT_140304c00;

  FUN_140071000();

  uVar2 = DAT_14039ca44;

  auVar7._0_4_ = auVar7._0_4_ + fVar1;

  FUN_140071000(DAT_1403ed994 + DAT_1403eda00 + DAT_1403fb45c + 7,auVar7._0_8_);

  puVar5 = &DAT_1403dc3c0;

  if (0xf < DAT_1403dc3d8) {

    puVar5 = DAT_1403dc3c0;

  }

  uVar8 = CONCAT44(uVar9,uVar2);

  FUN_140086570(DAT_1403ede20);

  if (0 < *(int *)(param_1 + 0x30c)) {

    FUN_14008d760(local_48,&DAT_1403139ec,*(undefined4 *)(param_1 + 0x310),*(int *)(param_1 + 0x30c)

                  ,uVar8,uVar6,puVar5);

    FUN_140086570(DAT_1403ede20);

    if (0xf < local_30) {

      if ((0xfff < local_30 + 1) && (0x1f < (local_48[0] - *(longlong *)(local_48[0] + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088();

    }

  }

  return;

}




