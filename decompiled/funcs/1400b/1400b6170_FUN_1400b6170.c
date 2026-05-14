// Address: 0x1400b6170
// Ghidra name: FUN_1400b6170
// ============ 0x1400b6170 FUN_1400b6170 (size=229) ============


void FUN_1400b6170(longlong param_1)



{

  longlong lVar1;

  int iVar2;

  longlong lVar3;

  longlong lVar4;

  undefined4 uVar5;

  

  lVar4 = *(longlong *)(param_1 + 0x40);

  lVar3 = *(longlong *)(param_1 + 0x48) - lVar4;

  iVar2 = 0;

  lVar3 = SUB168(SEXT816(-0x4de9bd37a6f4de9b) * SEXT816(lVar3),8) + lVar3;

  if (lVar3 >> 7 != lVar3 >> 0x3f) {

    lVar3 = 0;

    uVar5 = DAT_14030d9fc;

    do {

      lVar1 = *(longlong *)(lVar3 + 0x30 + lVar4);

      if ((lVar1 != 0) && (*(char *)(lVar3 + 0x14 + lVar4) != '\0')) {

        for (lVar4 = *(longlong *)(lVar1 + 0x70); lVar4 != 0; lVar4 = *(longlong *)(lVar4 + 8)) {

          uVar5 = FUN_1400c5c10(uVar5,*(undefined4 *)(*(longlong *)(lVar4 + 0x28) + 0xc));

        }

      }

      lVar4 = *(longlong *)(param_1 + 0x40);

      iVar2 = iVar2 + 1;

      lVar1 = *(longlong *)(param_1 + 0x48) - lVar4;

      lVar3 = lVar3 + 0xb8;

      lVar1 = SUB168(SEXT816(-0x4de9bd37a6f4de9b) * SEXT816(lVar1),8) + lVar1;

    } while ((ulonglong)(longlong)iVar2 < (ulonglong)((lVar1 >> 7) - (lVar1 >> 0x3f)));

  }

  return;

}




