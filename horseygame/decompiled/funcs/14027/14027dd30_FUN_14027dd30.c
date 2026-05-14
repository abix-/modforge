// Address: 0x14027dd30
// Ghidra name: FUN_14027dd30
// ============ 0x14027dd30 FUN_14027dd30 (size=387) ============


undefined8 FUN_14027dd30(longlong param_1)



{

  char *pcVar1;

  uint uVar2;

  longlong lVar3;

  longlong lVar4;

  char local_48;

  undefined1 local_47 [63];

  

  pcVar1 = *(char **)(param_1 + 0x70);

  lVar3 = 0;

  if (0 < *(int *)(param_1 + 0x8c)) {

    lVar3 = FUN_1401581c0(**(undefined4 **)(param_1 + 0x90));

  }

  if ((*pcVar1 != '\0') && (lVar3 != 0)) {

    lVar4 = FUN_140149350();

    if ((*(longlong *)(pcVar1 + 0x18) == 0) ||

       (2999 < (ulonglong)(lVar4 - *(longlong *)(pcVar1 + 0x18)))) {

      FUN_14027e010(*(undefined8 *)(param_1 + 0x80));

      *(longlong *)(pcVar1 + 0x18) = lVar4;

    }

  }

  uVar2 = FUN_140193780(*(undefined8 *)(param_1 + 0x80),&local_48,0x40);

  do {

    if (uVar2 == 0) {

      return 1;

    }

    if ((int)uVar2 < 0) {

      FUN_14027e520(param_1,0);

      return 0;

    }

    if (local_48 == 'B') {

LAB_14027de1c:

      if (((lVar3 != 0) ||

          ((FUN_14027e520(param_1,1), 0 < *(int *)(param_1 + 0x8c) &&

           (lVar3 = FUN_1401581c0(**(undefined4 **)(param_1 + 0x90)), lVar3 != 0)))) &&

         (0x35 < uVar2)) {

        FUN_14027e0d0(param_1,lVar3,local_47);

      }

    }

    else if (local_48 == 'C') {

      if ((lVar3 != 0) && (0xe < uVar2)) {

        FUN_14027e070(param_1,lVar3,local_47);

      }

    }

    else {

      if (local_48 == 'E') goto LAB_14027de1c;

      if (((local_48 == 'F') || (local_48 == 'y')) && (1 < uVar2)) {

        FUN_14027e4f0(param_1,local_47);

      }

    }

    uVar2 = FUN_140193780(*(undefined8 *)(param_1 + 0x80),&local_48,0x40);

  } while( true );

}




