// Address: 0x1402efaac
// Ghidra name: FUN_1402efaac
// ============ 0x1402efaac FUN_1402efaac (size=740) ============


undefined8

FUN_1402efaac(ulonglong *param_1,undefined1 *param_2,ulonglong param_3,longlong param_4,

             longlong param_5,int param_6,undefined4 param_7,ulonglong param_8,uint param_9,

             longlong param_10)



{

  ulonglong uVar1;

  int iVar2;

  undefined8 uVar3;

  longlong lVar4;

  undefined4 uVar5;

  uint uVar6;

  longlong lVar7;

  undefined8 in_stack_ffffffffffffffe0;

  undefined4 uVar8;

  

  if (param_2 == (undefined1 *)0x0) {

    *(undefined1 *)(param_10 + 0x30) = 1;

    *(undefined4 *)(param_10 + 0x2c) = 0x16;

  }

  else {

    if (((param_3 != 0) && (param_4 != 0)) && (param_5 != 0)) {

      if ((param_6 == 0x41) || (param_6 - 0x45U < 3)) {

        uVar6 = 1;

      }

      else {

        uVar6 = 0;

      }

      if (((param_8 & 8) == 0) && (uVar1 = *param_1, ((uint)(uVar1 >> 0x34) & 0x7ff) == 0x7ff)) {

        if ((uVar1 & 0xfffffffffffff) == 0) {

          lVar4 = 0;

        }

        else if (((longlong)uVar1 < 0) && ((uVar1 & 0xfffffffffffff) == 0x8000000000000)) {

          lVar4 = 0xc;

        }

        else {

          lVar4 = (-(ulonglong)((uVar1 & 0x8000000000000) != 0) & 0xfffffffffffffffc) + 8;

        }

        if (param_3 < 4U - ((longlong)uVar1 >> 0x3f)) {

          *param_2 = 0;

          return 0xc;

        }

        lVar7 = -1;

        if ((longlong)uVar1 < 0) {

          *param_2 = 0x2d;

          param_2[1] = 0;

        }

        do {

          lVar7 = lVar7 + 1;

        } while ((&PTR_DAT_140391940)[(ulonglong)((uVar6 ^ 1) * 2) + lVar4][lVar7] != '\0');

        iVar2 = FUN_1402e8180();

        if (iVar2 == 0) {

          return 0;

        }

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      uVar5 = (undefined4)(param_8 >> 4);

      param_9 = -(uint)((param_8 & 0x20) != 0) & param_9;

      uVar8 = (undefined4)((ulonglong)in_stack_ffffffffffffffe0 >> 0x20);

      if (param_6 != 0x41) {

        if (param_6 == 0x45) {

LAB_1402efcf9:

          uVar3 = FUN_1402ef330(param_1,param_2,param_3,param_4,param_5,param_7,uVar6,

                                CONCAT44(uVar8,uVar5) & 0xffffffff00000001 | 2,param_9,param_10);

          return uVar3;

        }

        if (param_6 == 0x46) {

LAB_1402efcc8:

          uVar3 = FUN_1402ef618(param_1,param_2,param_3,param_4,param_5,param_7,param_9,param_10);

          return uVar3;

        }

        if (param_6 != 0x47) {

          if (param_6 == 0x61) goto LAB_1402efd33;

          if (param_6 == 0x65) goto LAB_1402efcf9;

          if (param_6 == 0x66) goto LAB_1402efcc8;

        }

        uVar3 = FUN_1402ef840(param_1,param_2,param_3,param_4,param_5,param_7,uVar6,

                              CONCAT44(uVar8,uVar5) & 0xffffffff00000001 | 2,param_9,param_10);

        return uVar3;

      }

LAB_1402efd33:

      uVar3 = FUN_1402eef9c(param_1,param_2,param_3,param_4,param_5,param_7,uVar6,

                            CONCAT44(uVar8,uVar5) & 0xffffffff00000001 | 2,param_9,param_10);

      return uVar3;

    }

    *(undefined1 *)(param_10 + 0x30) = 1;

    *(undefined4 *)(param_10 + 0x2c) = 0x16;

  }

  FUN_1402cd39c(0,0,0,0,0,param_10);

  return 0x16;

}




