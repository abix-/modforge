// Address: 0x14020f6c0
// Ghidra name: FUN_14020f6c0
// ============ 0x14020f6c0 FUN_14020f6c0 (size=166) ============


void FUN_14020f6c0(void)



{

  undefined8 *puVar1;

  ulonglong uVar2;

  int iVar3;

  longlong lVar4;

  

  _guard_check_icall();

  iVar3 = 0;

  if (0 < DAT_1403fd3a8) {

    lVar4 = 0;

    do {

      puVar1 = *(undefined8 **)(lVar4 + DAT_1403fd3a0);

      if (puVar1 != (undefined8 *)0x0) {

        if (*(char *)(puVar1 + 0x10) == '\0') {

          FUN_14015a2b0(*(undefined4 *)(puVar1 + 0xd));

          *(undefined1 *)(puVar1 + 0x10) = 1;

        }

        if ((*(char *)((longlong)puVar1 + 0x81) != '\0') ||

           (uVar2 = (**(code **)(*(longlong *)*puVar1 + 0x20))(), (uVar2 & 1) == 0)) {

          FUN_14015a550(*(undefined4 *)(puVar1 + 0xd));

          FUN_140210810(iVar3);

          iVar3 = iVar3 + -1;

          lVar4 = lVar4 + -8;

        }

      }

      iVar3 = iVar3 + 1;

      lVar4 = lVar4 + 8;

    } while (iVar3 < DAT_1403fd3a8);

  }

  return;

}




