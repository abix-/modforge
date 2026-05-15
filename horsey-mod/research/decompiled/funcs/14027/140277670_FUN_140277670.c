// Address: 0x140277670
// Ghidra name: FUN_140277670
// ============ 0x140277670 FUN_140277670 (size=247) ============


int FUN_140277670(longlong param_1,char *param_2,int param_3)



{

  byte bVar1;

  undefined8 uVar2;

  ulonglong uVar3;

  uint uVar4;

  bool bVar5;

  

  if (*(char *)(param_1 + 0x98) == '\0') {

    FUN_1402f8e20(param_1,param_2,(longlong)param_3);

    return param_3;

  }

  bVar1 = param_2[1];

  uVar3 = (ulonglong)bVar1;

  uVar4 = bVar1 & 7;

  if (*param_2 == '\x03') {

    if (param_3 != 0x14) {

      FUN_14012e310("Bad segment size! %d\n",param_3);

      FUN_140277770(param_2,param_3);

      FUN_140276ec0(param_1);

      return -1;

    }

    if ((char)bVar1 < '\0') {

      if (uVar4 != *(uint *)(param_1 + 0x94)) {

        FUN_140276ec0();

        bVar5 = uVar4 != 0;

        uVar4 = 0;

        if (bVar5) {

          return -1;

        }

      }

      uVar2 = *(undefined8 *)(param_2 + 10);

      uVar4 = uVar4 * 0x12;

      *(undefined8 *)((ulonglong)uVar4 + param_1) = *(undefined8 *)(param_2 + 2);

      ((undefined8 *)((ulonglong)uVar4 + param_1))[1] = uVar2;

      *(undefined2 *)((ulonglong)uVar4 + 0x10 + param_1) = *(undefined2 *)(param_2 + 0x12);

      if ((uVar3 & 0x40) != 0) {

        *(undefined4 *)(param_1 + 0x94) = 0;

        return uVar4 + 0x12;

      }

      *(int *)(param_1 + 0x94) = *(int *)(param_1 + 0x94) + 1;

    }

  }

  return 0;

}




