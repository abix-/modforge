// Address: 0x140274150
// Ghidra name: FUN_140274150
// ============ 0x140274150 FUN_140274150 (size=195) ============


void FUN_140274150(longlong *param_1)



{

  longlong lVar1;

  char cVar2;

  undefined4 uVar3;

  

  if (*(char *)((longlong)param_1 + 0x22) == '\0') {

    *(undefined1 *)((longlong)param_1 + 0x22) = 1;

    if (*(char *)((longlong)param_1 + 0x16) != '\0') {

      FUN_14015a220(param_1[1],2);

      *(undefined1 *)((longlong)param_1 + 0x24) = 1;

    }

    uVar3 = DAT_14030c28c;

    if (*(char *)((longlong)param_1 + 0x12) != '\0') {

      lVar1 = *param_1;

      if ((*(char *)(lVar1 + 0x54) != '\0') ||

         (cVar2 = FUN_140159400(*(undefined2 *)(lVar1 + 0x20),*(undefined2 *)(lVar1 + 0x22)),

         cVar2 != '\0')) {

        uVar3 = DAT_14039ca60;

      }

      FUN_14015a190(param_1[1],2,uVar3);

      FUN_14015a190(param_1[1],1,uVar3);

    }

    if (*(char *)((longlong)param_1 + 0x19) != '\0') {

      FUN_14015a190(param_1[1],1,DAT_14030c28c);

    }

    *(undefined1 *)((longlong)param_1 + 0x25) = 1;

    FUN_1402089a0(*param_1);

    return;

  }

  return;

}




