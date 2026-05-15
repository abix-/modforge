// Address: 0x140224c40
// Ghidra name: FUN_140224c40
// ============ 0x140224c40 FUN_140224c40 (size=393) ============


void FUN_140224c40(longlong param_1)



{

  undefined4 uVar1;

  ulonglong uVar2;

  undefined2 *puVar3;

  char *pcVar4;

  int iVar5;

  longlong lVar6;

  ulonglong uVar7;

  

  lVar6 = (longlong)*(int *)(param_1 + 0x170);

  if (*(short *)(param_1 + 0x174) == 0) {

    puVar3 = (undefined2 *)FUN_1401841f0(lVar6 + 2);

    if (puVar3 == (undefined2 *)0x0) {

      return;

    }

    *puVar3 = 0;

    FUN_14012fcd0(puVar3,*(undefined8 *)(param_1 + 0x168),lVar6);

  }

  else {

    uVar2 = FUN_14012fd40(*(undefined8 *)(param_1 + 0x168));

    uVar7 = (ulonglong)*(int *)(param_1 + 0x194);

    if (uVar2 < uVar7) {

      uVar7 = FUN_14012fd40(*(undefined8 *)(param_1 + 0x168));

    }

    puVar3 = (undefined2 *)FUN_1401841f0(lVar6 + 0x22);

    if (puVar3 == (undefined2 *)0x0) {

      return;

    }

    *puVar3 = 0;

    FUN_14012fcd0(puVar3,*(undefined8 *)(param_1 + 0x168),uVar7 + 1);

    FUN_14012fc50(puVar3,param_1 + 0x174,lVar6 + 0x20);

    FUN_14012fc50(puVar3,*(longlong *)(param_1 + 0x168) + uVar7 * 2,lVar6 + 0x20);

  }

  lVar6 = FUN_14012fd40(puVar3);

  pcVar4 = (char *)FUN_140197820(&DAT_14039c6f0,"UTF-16LE",puVar3,lVar6 * 2 + 2);

  if (pcVar4 != (char *)0x0) {

    if (*(short *)(param_1 + 0x174) == 0) {

      iVar5 = *(int *)(param_1 + 0x194);

      if (iVar5 == *(int *)(param_1 + 0x198)) {

        uVar1 = *(undefined4 *)(param_1 + 0x19c);

        iVar5 = *(int *)(param_1 + 0x198);

      }

      else {

        uVar1 = 0;

      }

    }

    else {

      uVar1 = FUN_14012fd40(param_1 + 0x174);

      iVar5 = *(int *)(param_1 + 0x194);

    }

    FUN_140183810(pcVar4,iVar5,uVar1);

    if (*pcVar4 != '\0') {

      *(undefined1 *)(param_1 + 0x158) = 1;

    }

    FUN_1401841e0(pcVar4);

  }

  FUN_1401841e0(puVar3);

  return;

}




