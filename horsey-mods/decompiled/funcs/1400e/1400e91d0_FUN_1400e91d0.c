// Address: 0x1400e91d0
// Ghidra name: FUN_1400e91d0
// ============ 0x1400e91d0 FUN_1400e91d0 (size=424) ============


longlong FUN_1400e91d0(longlong param_1,longlong param_2)



{

  int iVar1;

  char *pcVar2;

  ulonglong uVar3;

  char cVar4;

  uint uVar5;

  ulonglong uVar6;

  

  pcVar2 = *(char **)(param_1 + 0xb8);

  uVar3 = 0;

  uVar6 = uVar3;

  if (pcVar2 < *(char **)(param_1 + 0xc0)) {

    cVar4 = *pcVar2;

    *(char **)(param_1 + 0xb8) = pcVar2 + 1;

  }

  else if (*(int *)(param_1 + 0x30) == 0) {

    cVar4 = '\0';

  }

  else {

    FUN_1400ed820();

    cVar4 = **(char **)(param_1 + 0xb8);

    *(char **)(param_1 + 0xb8) = *(char **)(param_1 + 0xb8) + 1;

  }

LAB_1400e9243:

  uVar5 = (uint)uVar6;

  if (*(longlong *)(param_1 + 0x10) == 0) {

LAB_1400e9261:

    if (*(ulonglong *)(param_1 + 0xc0) <= *(ulonglong *)(param_1 + 0xb8)) goto LAB_1400e932e;

  }

  else {

    iVar1 = (**(code **)(param_1 + 0x20))(*(undefined8 *)(param_1 + 0x28));

    if (iVar1 != 0) {

      if (*(int *)(param_1 + 0x30) != 0) goto LAB_1400e9261;

      goto LAB_1400e932e;

    }

  }

  if (cVar4 == '\n') goto LAB_1400e932e;

  *(char *)(param_2 + uVar3) = cVar4;

  uVar5 = uVar5 + 1;

  uVar6 = (ulonglong)uVar5;

  uVar3 = uVar3 + 1;

  if (uVar3 != 0x3ff) {

    pcVar2 = *(char **)(param_1 + 0xb8);

    if (pcVar2 < *(char **)(param_1 + 0xc0)) {

      cVar4 = *pcVar2;

      *(char **)(param_1 + 0xb8) = pcVar2 + 1;

    }

    else if (*(int *)(param_1 + 0x30) == 0) {

      cVar4 = '\0';

    }

    else {

      FUN_1400ed820(param_1);

      cVar4 = **(char **)(param_1 + 0xb8);

      *(char **)(param_1 + 0xb8) = *(char **)(param_1 + 0xb8) + 1;

    }

    goto LAB_1400e9243;

  }

LAB_1400e92e7:

  do {

    if (*(longlong *)(param_1 + 0x10) == 0) {

LAB_1400e9301:

      if (*(ulonglong *)(param_1 + 0xc0) <= *(ulonglong *)(param_1 + 0xb8)) goto LAB_1400e932e;

      pcVar2 = *(char **)(param_1 + 0xb8);

    }

    else {

      iVar1 = (**(code **)(param_1 + 0x20))(*(undefined8 *)(param_1 + 0x28));

      if (iVar1 != 0) {

        if (*(int *)(param_1 + 0x30) != 0) goto LAB_1400e9301;

        goto LAB_1400e932e;

      }

      pcVar2 = *(char **)(param_1 + 0xb8);

      if (*(char **)(param_1 + 0xc0) <= pcVar2) {

        if (*(int *)(param_1 + 0x30) == 0) goto LAB_1400e92e7;

        FUN_1400ed820(param_1);

        pcVar2 = *(char **)(param_1 + 0xb8);

      }

    }

    cVar4 = *pcVar2;

    *(char **)(param_1 + 0xb8) = pcVar2 + 1;

    if (cVar4 == '\n') {

LAB_1400e932e:

      *(undefined1 *)((int)uVar5 + param_2) = 0;

      return param_2;

    }

  } while( true );

}




