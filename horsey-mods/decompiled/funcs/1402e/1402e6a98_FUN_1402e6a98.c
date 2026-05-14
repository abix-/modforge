// Address: 0x1402e6a98
// Ghidra name: FUN_1402e6a98
// ============ 0x1402e6a98 FUN_1402e6a98 (size=281) ============


undefined4 FUN_1402e6a98(short *param_1,longlong param_2,undefined8 param_3,undefined4 param_4)



{

  int iVar1;

  DWORD DVar2;

  undefined4 *puVar3;

  

  if (param_1 == (short *)0x0) {

    if (*(char *)(param_2 + 0x28) != '\0') {

      *(undefined1 *)(param_2 + 0x28) = 0;

    }

    *(undefined8 *)(param_2 + 0x10) = 0;

    *(undefined8 *)(param_2 + 0x18) = 0;

  }

  else {

    if (*param_1 != 0) {

      iVar1 = FUN_1402f31e0(param_4,0,param_1,0xffffffff,0,0,0,0);

      if (iVar1 != 0) {

        if (*(ulonglong *)(param_2 + 0x18) < (ulonglong)(longlong)iVar1) {

          if (*(char *)(param_2 + 0x28) != '\0') {

            *(undefined1 *)(param_2 + 0x28) = 0;

          }

          goto LAB_1402e6aec;

        }

        iVar1 = FUN_1402f31e0(param_4,0,param_1,0xffffffff,*(undefined8 *)(param_2 + 0x10),

                              (int)*(ulonglong *)(param_2 + 0x18),0,0);

        if ((longlong)iVar1 != 0) {

          *(longlong *)(param_2 + 0x20) = (longlong)iVar1 + -1;

          return 0;

        }

      }

      DVar2 = GetLastError();

      FUN_1402e6840(DVar2);

      puVar3 = (undefined4 *)FUN_1402e68b0();

      return *puVar3;

    }

    if (*(longlong *)(param_2 + 0x18) == 0) {

      if (*(char *)(param_2 + 0x28) != '\0') {

        *(undefined1 *)(param_2 + 0x28) = 0;

      }

LAB_1402e6aec:

      puVar3 = (undefined4 *)FUN_1402e68b0();

      *puVar3 = 0x22;

      *(undefined1 *)(param_2 + 0x28) = 0;

      *(undefined8 *)(param_2 + 0x18) = 0;

      return 0x22;

    }

    **(undefined1 **)(param_2 + 0x10) = 0;

  }

  *(undefined8 *)(param_2 + 0x20) = 0;

  return 0;

}




