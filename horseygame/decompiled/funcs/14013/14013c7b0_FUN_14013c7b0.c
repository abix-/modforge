// Address: 0x14013c7b0
// Ghidra name: FUN_14013c7b0
// ============ 0x14013c7b0 FUN_14013c7b0 (size=208) ============


void FUN_14013c7b0(void)



{

  undefined4 *puVar1;

  longlong lVar2;

  undefined8 uVar3;

  int iVar4;

  longlong lVar5;

  int local_res8 [2];

  

  _guard_check_icall();

  if (DAT_1403fbf30 == (int *)0x0) {

    puVar1 = (undefined4 *)FUN_1401841a0(1,0x28);

    DAT_1403fbf30 = puVar1;

    *puVar1 = 1;

    lVar2 = FUN_140158f60(local_res8);

    *(longlong *)(puVar1 + 2) = lVar2;

    if ((lVar2 != 0) && (local_res8[0] != 0)) {

      lVar2 = FUN_1401841f0((longlong)local_res8[0] << 3);

      *(longlong *)(puVar1 + 4) = lVar2;

      if ((lVar2 != 0) && (iVar4 = 0, 0 < local_res8[0])) {

        lVar2 = 0;

        lVar5 = 0;

        do {

          uVar3 = FUN_140140710(*(undefined4 *)(*(longlong *)(puVar1 + 2) + lVar2),0);

          lVar2 = lVar2 + 4;

          iVar4 = iVar4 + 1;

          *(undefined8 *)(lVar5 + *(longlong *)(puVar1 + 4)) = uVar3;

          lVar5 = lVar5 + 8;

        } while (iVar4 < local_res8[0]);

      }

    }

    return;

  }

  *DAT_1403fbf30 = *DAT_1403fbf30 + 1;

  return;

}




