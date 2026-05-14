// Address: 0x14026c980
// Ghidra name: FUN_14026c980
// ============ 0x14026c980 FUN_14026c980 (size=177) ============


longlong FUN_14026c980(longlong param_1,uint param_2,void *param_3,byte param_4)



{

  int iVar1;

  longlong lVar2;

  ulonglong uVar3;

  

  lVar2 = FUN_140149350();

  iVar1 = FUN_14026c790(param_1);

  do {

    if (iVar1 == -1) {

      return 0;

    }

    if (iVar1 < 1) {

      FUN_1401492f0(1);

LAB_14026c9ff:

      uVar3 = FUN_140149350();

      if (lVar2 + 100U <= uVar3) {

        return 0;

      }

    }

    else {

      if (*(char *)(param_1 + 0x40) != '!') goto LAB_14026c9ff;

      if (((*(byte *)(param_1 + 0x4e) == param_2) && (*(char *)(param_1 + 0x4d) < '\0')) &&

         ((*(byte *)(param_1 + 0x4e) != 0x10 ||

          (iVar1 = memcmp((void *)(param_1 + 0x4f),param_3,(ulonglong)param_4), iVar1 == 0)))) {

        return param_1 + 0x41;

      }

    }

    iVar1 = FUN_14026c790(param_1);

  } while( true );

}




