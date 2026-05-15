// Address: 0x14019eeb0
// Ghidra name: FUN_14019eeb0
// ============ 0x14019eeb0 FUN_14019eeb0 (size=376) ============


longlong FUN_14019eeb0(longlong *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4

                      ,uint param_5,longlong param_6,undefined4 param_7,int *param_8)



{

  undefined4 *puVar1;

  int iVar2;

  longlong lVar3;

  char *pcVar4;

  

  lVar3 = 0;

  if (param_6 == 0) {

    if (4 < param_5) {

      pcVar4 = "Internal error";

      goto LAB_14019f004;

    }

  }

  else if (param_5 != 1) {

    pcVar4 = "req_comp must be 1 if loading paletted image without expansion";

    goto LAB_14019f004;

  }

  iVar2 = FUN_1401a25a0(param_1,0,param_5,param_6,param_7);

  if (iVar2 != 0) {

    iVar2 = (int)param_1[4];

    if (iVar2 < 9) {

      iVar2 = 8;

    }

    else if (iVar2 != 0x10) {

      pcVar4 = "PNG not supported: unsupported color depth";

LAB_14019f004:

      FUN_14019f050(pcVar4);

      return 0;

    }

    *param_8 = iVar2;

    lVar3 = param_1[3];

    param_1[3] = 0;

    if (param_5 != 0) {

      puVar1 = (undefined4 *)*param_1;

      if (param_5 != puVar1[3]) {

        if (param_6 == 0) {

          if (*param_8 == 8) {

            lVar3 = FUN_14019d3a0();

          }

          else {

            lVar3 = FUN_14019d7f0(lVar3,puVar1[3],param_5,*puVar1,puVar1[1]);

          }

        }

        *(uint *)(*param_1 + 0xc) = param_5;

        if (lVar3 == 0) {

          return 0;

        }

      }

    }

    *param_2 = *(undefined4 *)*param_1;

    *param_3 = *(undefined4 *)(*param_1 + 4);

    if (param_4 != (undefined4 *)0x0) {

      if (param_6 == 0) {

        *param_4 = *(undefined4 *)(*param_1 + 8);

      }

      else {

        *param_4 = 1;

      }

    }

  }

  FUN_1401841e0(param_1[3]);

  param_1[3] = 0;

  FUN_1401841e0(param_1[2]);

  param_1[2] = 0;

  FUN_1401841e0(param_1[1]);

  param_1[1] = 0;

  return lVar3;

}




