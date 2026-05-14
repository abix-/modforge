// Address: 0x1401104f0
// Ghidra name: FUN_1401104f0
// ============ 0x1401104f0 FUN_1401104f0 (size=600) ============


void FUN_1401104f0(longlong param_1)



{

  longlong lVar1;

  float fVar2;

  longlong lVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  undefined8 local_68;

  undefined8 uStack_60;

  undefined8 local_58;

  ulonglong local_50;

  

  iVar4 = DAT_1403ed994;

  iVar6 = DAT_1403d9e6c + -0x16;

  *(float *)(*(longlong *)(param_1 + 0x60) + 0x514) = (float)(DAT_1403ed994 + 0x16);

  *(float *)(*(longlong *)(param_1 + 0x60) + 0x518) = (float)iVar6;

  if ((*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) + 4)

       < DAT_1403fb480) && (FUN_1402c7138(&DAT_1403fb480), DAT_1403fb480 == -1)) {

    uStack_60 = 0;

    local_58 = 6;

    local_50 = 0xf;

    local_68 = (ulonglong)CONCAT24(s_EcoBar_140313a10._4_2_,s_EcoBar_140313a10._0_4_);

    DAT_1403fb47c = FUN_14006fe60(&local_68);

    _Init_thread_footer(&DAT_1403fb480);

  }

  FUN_140071d20(DAT_1403fb47c);

  fVar2 = DAT_14039ca44;

  iVar5 = 8;

  lVar3 = 0x340;

  iVar4 = iVar4 + 0x18;

  do {

    lVar1 = *(longlong *)(param_1 + 0x60);

    *(float *)(lVar3 + 0x34 + lVar1) = (float)iVar4;

    *(float *)(lVar3 + 0x38 + lVar1) = (float)iVar6;

    FUN_140071d20((uint)(*(int *)(param_1 + 0xd8) == iVar5) + *(int *)(lVar3 + 0x2c + lVar1),

                  (float)iVar4 + fVar2);

    iVar5 = iVar5 + 1;

    iVar4 = iVar4 + 0xe;

    lVar3 = lVar3 + 0x68;

  } while (iVar5 < 0xc);

  FUN_14008d760(&local_68,&DAT_140313a18);

  FUN_140086570(DAT_1403ede28);

  if (0xf < local_50) {

    if ((0xfff < local_50 + 1) && (0x1f < (local_68 - *(longlong *)(local_68 - 8)) - 8)) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088();

  }

  return;

}




