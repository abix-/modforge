// Address: 0x1401695a0
// Ghidra name: FUN_1401695a0
// ============ 0x1401695a0 FUN_1401695a0 (size=121) ============


undefined1 FUN_1401695a0(void)



{

  undefined1 uVar1;

  char cVar2;

  longlong lVar3;

  ulonglong uVar4;

  ulonglong local_res8;

  

  lVar3 = FUN_14016dcf0();

  if (lVar3 == 0) {

    uVar1 = FUN_1401730c0();

    return uVar1;

  }

  lVar3 = FUN_1401694d0(lVar3,&local_res8);

  uVar4 = 0;

  if (local_res8 != 0) {

    do {

      cVar2 = FUN_1401694f0(*(undefined8 *)(lVar3 + uVar4 * 8));

      if (cVar2 != '\0') {

        return 1;

      }

      uVar4 = uVar4 + 1;

    } while (uVar4 < local_res8);

  }

  return 0;

}




