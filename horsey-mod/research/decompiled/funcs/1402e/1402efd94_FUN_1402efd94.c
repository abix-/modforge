// Address: 0x1402efd94
// Ghidra name: FUN_1402efd94
// ============ 0x1402efd94 FUN_1402efd94 (size=432) ============


undefined4

FUN_1402efd94(int *param_1,undefined1 *param_2,ulonglong param_3,ushort param_4,longlong param_5)



{

  int iVar1;

  DWORD DVar2;

  undefined4 uVar3;

  ulonglong local_res10;

  ushort local_res20 [4];

  undefined8 in_stack_ffffffffffffffd0;

  

  uVar3 = (undefined4)((ulonglong)in_stack_ffffffffffffffd0 >> 0x20);

  if ((param_2 == (undefined1 *)0x0) && (param_3 != 0)) {

    if (param_1 == (int *)0x0) {

      return 0;

    }

    *param_1 = 0;

    return 0;

  }

  if (param_1 != (int *)0x0) {

    *param_1 = -1;

  }

  local_res20[0] = param_4;

  if (param_3 < 0x80000000) {

    if (*(char *)(param_5 + 0x28) == '\0') {

      FUN_1402d74e0(param_5);

    }

    iVar1 = *(int *)(*(longlong *)(param_5 + 0x18) + 0xc);

    if (iVar1 == 0xfde9) {

      local_res10 = 0;

      iVar1 = FUN_1402f7f1c(param_2,local_res20[0],&local_res10,param_5);

      if (param_1 != (int *)0x0) {

        *param_1 = iVar1;

      }

      if (iVar1 < 5) {

        return 0;

      }

      if (*(char *)(param_5 + 0x30) != '\0') {

        return *(undefined4 *)(param_5 + 0x2c);

      }

      return 0;

    }

    if (*(longlong *)(*(longlong *)(param_5 + 0x18) + 0x138) == 0) {

      if (0xff < local_res20[0]) {

        if ((param_2 != (undefined1 *)0x0) && (param_3 != 0)) {

          FUN_1402f94c0(param_2,0,param_3);

        }

        goto LAB_1402efe76;

      }

      if (param_2 == (undefined1 *)0x0) {

LAB_1402efea2:

        if (param_1 != (int *)0x0) {

          *param_1 = 1;

        }

        return 0;

      }

      if (param_3 != 0) {

        *param_2 = (char)local_res20[0];

        goto LAB_1402efea2;

      }

    }

    else {

      local_res10 = local_res10 & 0xffffffff00000000;

      iVar1 = FUN_1402f31e0(iVar1,0,local_res20,1,param_2,CONCAT44(uVar3,(int)param_3),0,

                            &local_res10);

      if (iVar1 != 0) {

        if ((int)local_res10 == 0) {

          if (param_1 == (int *)0x0) {

            return 0;

          }

          *param_1 = iVar1;

          return 0;

        }

LAB_1402efe76:

        *(undefined4 *)(param_5 + 0x2c) = 0x2a;

        *(undefined1 *)(param_5 + 0x30) = 1;

        return 0x2a;

      }

      DVar2 = GetLastError();

      if (DVar2 != 0x7a) goto LAB_1402efe76;

      if ((param_2 != (undefined1 *)0x0) && (param_3 != 0)) {

        FUN_1402f94c0(param_2,0,param_3);

      }

    }

    uVar3 = 0x22;

  }

  else {

    uVar3 = 0x16;

  }

  *(undefined4 *)(param_5 + 0x2c) = uVar3;

  *(undefined1 *)(param_5 + 0x30) = 1;

  FUN_1402cd39c(0,0,0,0,0,param_5);

  return uVar3;

}




