// Address: 0x1400e8890
// Ghidra name: FUN_1400e8890
// ============ 0x1400e8890 FUN_1400e8890 (size=398) ============


undefined8 FUN_1400e8890(longlong *param_1)



{

  undefined1 uVar1;

  longlong lVar2;

  undefined1 *puVar3;

  char cVar4;

  int iVar5;

  char *pcVar6;

  

  *(undefined4 *)((longlong)param_1 + 0x36e4) = 0;

  iVar5 = FUN_1400e8760(param_1,0);

  if (iVar5 == 0) {

    return 0;

  }

  cVar4 = FUN_1400e8c90(param_1);

joined_r0x0001400e88c6:

  if (cVar4 == -0x27) {

    return 1;

  }

  if (cVar4 == -0x26) {

    iVar5 = FUN_1400ed070();

    if (iVar5 == 0) {

      return 0;

    }

    iVar5 = FUN_1400ea690(param_1);

    if (iVar5 == 0) {

      return 0;

    }

    if ((char)param_1[0x6d9] == -1) {

LAB_1400e8910:

      lVar2 = *param_1;

      if (*(longlong *)(lVar2 + 0x10) == 0) {

LAB_1400e8932:

        if (*(ulonglong *)(lVar2 + 0xc0) <= *(ulonglong *)(lVar2 + 0xb8)) goto LAB_1400e89f8;

      }

      else {

        iVar5 = (**(code **)(lVar2 + 0x20))(*(undefined8 *)(lVar2 + 0x28));

        if (iVar5 != 0) {

          if (*(int *)(lVar2 + 0x30) != 0) goto LAB_1400e8932;

          goto LAB_1400e89f8;

        }

      }

      lVar2 = *param_1;

      pcVar6 = *(char **)(lVar2 + 0xb8);

      if (*(char **)(lVar2 + 0xc0) <= pcVar6) goto code_r0x0001400e8959;

      goto LAB_1400e896e;

    }

  }

  else {

    iVar5 = FUN_1400ecc50(param_1,cVar4);

    if (iVar5 == 0) {

      return 0;

    }

  }

  goto LAB_1400e89f8;

code_r0x0001400e8959:

  if (*(int *)(lVar2 + 0x30) == 0) goto LAB_1400e8910;

  FUN_1400ed820(lVar2);

  pcVar6 = *(char **)(lVar2 + 0xb8);

LAB_1400e896e:

  cVar4 = *pcVar6;

  *(char **)(lVar2 + 0xb8) = pcVar6 + 1;

  if (cVar4 != -1) {

    if (cVar4 != '\0') {

      return 0;

    }

    goto LAB_1400e8910;

  }

  lVar2 = *param_1;

  puVar3 = *(undefined1 **)(lVar2 + 0xb8);

  if (puVar3 < *(undefined1 **)(lVar2 + 0xc0)) {

    uVar1 = *puVar3;

    *(undefined1 **)(lVar2 + 0xb8) = puVar3 + 1;

    *(undefined1 *)(param_1 + 0x6d9) = uVar1;

  }

  else if (*(int *)(lVar2 + 0x30) == 0) {

    *(undefined1 *)(param_1 + 0x6d9) = 0;

  }

  else {

    FUN_1400ed820(lVar2);

    uVar1 = **(undefined1 **)(lVar2 + 0xb8);

    *(undefined1 **)(lVar2 + 0xb8) = *(undefined1 **)(lVar2 + 0xb8) + 1;

    *(undefined1 *)(param_1 + 0x6d9) = uVar1;

  }

LAB_1400e89f8:

  cVar4 = FUN_1400e8c90(param_1);

  goto joined_r0x0001400e88c6;

}




