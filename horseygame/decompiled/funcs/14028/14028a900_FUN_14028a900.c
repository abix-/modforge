// Address: 0x14028a900
// Ghidra name: FUN_14028a900
// ============ 0x14028a900 FUN_14028a900 (size=229) ============


ulonglong FUN_14028a900(longlong param_1,undefined8 param_2)



{

  longlong lVar1;

  char cVar2;

  int iVar3;

  char *pcVar4;

  ulonglong uVar5;

  int iVar6;

  ulonglong uVar7;

  

  lVar1 = *(longlong *)(param_1 + 0x18);

  cVar2 = FUN_14028ae60();

  if (cVar2 == '\0') {

    FUN_14012e850("Unsupported effect");

    return 0xffffffff;

  }

  FUN_140179b40(*(undefined8 *)(lVar1 + 0xb80));

  uVar5 = 0;

  pcVar4 = (char *)(lVar1 + 0x9c);

  uVar7 = uVar5;

  do {

    iVar6 = (int)uVar7;

    if (*pcVar4 == '\0') {

      if (iVar6 != -1) {

        iVar3 = FUN_14028bf60(lVar1,param_2,uVar7);

        FUN_140179b60(*(undefined8 *)(lVar1 + 0xb80));

        if (iVar3 == 0) {

          *(undefined1 *)((longlong)iVar6 * 0x98 + 0x9c + lVar1) = 1;

          return uVar7;

        }

        pcVar4 = "Bad effect parameters";

        goto LAB_14028a9c6;

      }

      break;

    }

    uVar7 = (ulonglong)(iVar6 + 1);

    uVar5 = uVar5 + 1;

    pcVar4 = pcVar4 + 0x98;

  } while ((longlong)uVar5 < 0x10);

  FUN_140179b60(*(undefined8 *)(lVar1 + 0xb80));

  pcVar4 = "All effect slots in-use";

LAB_14028a9c6:

  FUN_14012e850(pcVar4);

  return 0xffffffff;

}




