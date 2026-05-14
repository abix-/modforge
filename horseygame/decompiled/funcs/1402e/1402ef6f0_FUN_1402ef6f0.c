// Address: 0x1402ef6f0
// Ghidra name: FUN_1402ef6f0
// ============ 0x1402ef6f0 FUN_1402ef6f0 (size=333) ============


undefined8

FUN_1402ef6f0(undefined1 *param_1,undefined8 param_2,int param_3,int *param_4,char param_5,

             longlong param_6)



{

  undefined1 *puVar1;

  bool bVar2;

  int iVar3;

  longlong lVar4;

  longlong lVar5;

  

  if ((param_5 != '\0') && (param_4[1] + -1 == param_3)) {

    *(undefined2 *)(param_1 + (longlong)param_4[1] + -1 + (ulonglong)(*param_4 == 0x2d)) = 0x30;

  }

  if (*param_4 == 0x2d) {

    *param_1 = 0x2d;

    param_1 = param_1 + 1;

  }

  iVar3 = param_4[1];

  if (iVar3 < 1) {

    if ((iVar3 == 0) && (**(char **)(param_4 + 2) == '0')) {

      bVar2 = true;

    }

    else {

      bVar2 = false;

    }

    if ((param_5 == '\0') || (!bVar2)) {

      lVar5 = -1;

      do {

        lVar4 = lVar5;

        lVar5 = lVar4 + 1;

      } while (param_1[lVar5] != '\0');

      FUN_1402f8e20(param_1 + 1,param_1,lVar4 + 2);

    }

    *param_1 = 0x30;

    param_1 = param_1 + 1;

  }

  else {

    param_1 = param_1 + iVar3;

  }

  if (0 < param_3) {

    puVar1 = param_1 + 1;

    lVar5 = -1;

    do {

      lVar4 = lVar5;

      lVar5 = lVar4 + 1;

    } while (param_1[lVar5] != '\0');

    FUN_1402f8e20(puVar1,param_1,lVar4 + 2);

    if (*(char *)(param_6 + 0x28) == '\0') {

      FUN_1402d74e0(param_6);

    }

    *param_1 = *(undefined1 *)**(undefined8 **)(*(longlong *)(param_6 + 0x18) + 0xf8);

    if (param_4[1] < 0) {

      iVar3 = -param_4[1];

      if ((param_5 != '\0') || (iVar3 < param_3)) {

        param_3 = iVar3;

      }

      lVar5 = -1;

      do {

        lVar4 = lVar5;

        lVar5 = lVar4 + 1;

      } while (puVar1[lVar5] != '\0');

      FUN_1402f8e20(puVar1 + param_3,puVar1,lVar4 + 2);

      FUN_1402f94c0(puVar1,0x30,(longlong)param_3);

    }

  }

  return 0;

}




