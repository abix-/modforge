// Address: 0x140169340
// Ghidra name: FUN_140169340
// ============ 0x140169340 FUN_140169340 (size=136) ============


void FUN_140169340(void)



{

  longlong lVar1;

  longlong lVar2;

  ulonglong uVar3;

  ulonglong local_res8;

  undefined1 local_res10 [8];

  

  lVar1 = FUN_14016dcf0();

  if (lVar1 == 0) {

    FUN_1401730c0();

    FUN_14012f0d0(&DAT_14039bcb9);

    return;

  }

  lVar1 = FUN_1401694d0(lVar1,&local_res8);

  uVar3 = 0;

  if (local_res8 != 0) {

    do {

      lVar2 = FUN_1401691d0(*(undefined8 *)(lVar1 + uVar3 * 8),local_res10);

      if (lVar2 != 0) {

        return;

      }

      uVar3 = uVar3 + 1;

    } while (uVar3 < local_res8);

  }

  FUN_14012f0d0(&DAT_14039bcb9);

  return;

}




