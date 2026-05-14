// Address: 0x14008f310
// Ghidra name: FUN_14008f310
// ============ 0x14008f310 FUN_14008f310 (size=921) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_14008f310(longlong param_1)



{

  longlong lVar1;

  int iVar2;

  uint uVar3;

  uint uVar4;

  longlong lVar5;

  float fVar6;

  undefined8 local_88;

  undefined8 uStack_80;

  undefined8 local_78;

  ulonglong local_70;

  

  FUN_140070f90(DAT_1403d9f2c);

  FUN_140071000();

  if ((*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) + 4)

       < DAT_1403edec4) && (FUN_1402c7138(&DAT_1403edec4), DAT_1403edec4 == -1)) {

    uStack_80 = 0;

    local_78 = 6;

    local_70 = 0xf;

    local_88 = (ulonglong)CONCAT24(s_Dealer_14030b9ec._4_2_,s_Dealer_14030b9ec._0_4_);

    DAT_1403edec0 = FUN_14006fe60(&local_88);

    _Init_thread_footer(&DAT_1403edec4);

  }

  FUN_140071d20(DAT_1403edec0);

  iVar2 = 0x18;

  do {

    FUN_140071d20(DAT_1403edec0 + 1);

    iVar2 = iVar2 + 0x40;

  } while (iVar2 < 0x118);

  fVar6 = (float)(*(uint *)(param_1 + 0x114) ^ DAT_14039cac0);

  FUN_140072fe0(CONCAT44(fVar6 * *(float *)(param_1 + 0x110),fVar6 * *(float *)(param_1 + 0x10c)));

  FUN_1400d5d90(param_1,1);

  FUN_1400d5ff0(param_1,1);

  FUN_1400730f0();

  fVar6 = DAT_14039ca44;

  uVar4 = 0;

  lVar1 = *(longlong *)(param_1 + 0x130);

  if (*(longlong *)(param_1 + 0x138) - lVar1 >> 3 != 0) {

    lVar5 = 0;

    do {

      lVar1 = *(longlong *)(lVar5 + lVar1);

      if ((*(char *)(lVar1 + 0x204) == '\0') && (lVar1 != *(longlong *)(param_1 + 0x148))) {

        uVar3 = uVar4 & 0x80000001;

        if ((int)uVar3 < 0) {

          uVar3 = (uVar3 - 1 | 0xfffffffe) + 1;

        }

        FUN_140071d20(DAT_1403edec0 + 2 + uVar3,

                      *(float *)(param_1 + 0x114) * *(float *)(*(longlong *)(lVar1 + 0x40) + 0x40) -

                      fVar6);

        FUN_14008d760(&local_88,&DAT_140307a38);

        FUN_140086570(DAT_1403ede30);

        if (0xf < local_70) {

          if ((0xfff < local_70 + 1) && (0x1f < (local_88 - *(longlong *)(local_88 - 8)) - 8)) {

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

          FUN_1402c7088();

        }

      }

      uVar4 = uVar4 + 1;

      lVar5 = lVar5 + 8;

      lVar1 = *(longlong *)(param_1 + 0x130);

    } while ((ulonglong)(longlong)(int)uVar4 <

             (ulonglong)(*(longlong *)(param_1 + 0x138) - lVar1 >> 3));

  }

  FUN_1400cacd0(param_1,1);

  return;

}




