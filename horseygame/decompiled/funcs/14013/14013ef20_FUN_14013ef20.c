// Address: 0x14013ef20
// Ghidra name: FUN_14013ef20
// ============ 0x14013ef20 FUN_14013ef20 (size=239) ============


undefined1

FUN_14013ef20(undefined8 param_1,int param_2,int param_3,undefined1 *param_4,undefined4 *param_5,

             undefined4 *param_6,undefined4 *param_7)



{

  undefined1 uVar1;

  longlong lVar2;

  int *piVar3;

  undefined1 *puVar4;

  char *pcVar5;

  

  uVar1 = 0;

  FUN_140159d30();

  lVar2 = FUN_14013e670(param_1);

  if (lVar2 != 0) {

    if ((param_2 < 0) || (*(int *)(lVar2 + 0x80) <= param_2)) {

      pcVar5 = "touchpad";

    }

    else {

      piVar3 = (int *)((longlong)param_2 * 0x10 + *(longlong *)(lVar2 + 0x88));

      if ((-1 < param_3) && (param_3 < *piVar3)) {

        puVar4 = (undefined1 *)((longlong)param_3 * 0x10 + *(longlong *)(piVar3 + 2));

        if (param_4 != (undefined1 *)0x0) {

          *param_4 = *puVar4;

        }

        if (param_5 != (undefined4 *)0x0) {

          *param_5 = *(undefined4 *)(puVar4 + 4);

        }

        if (param_6 != (undefined4 *)0x0) {

          *param_6 = *(undefined4 *)(puVar4 + 8);

        }

        if (param_7 != (undefined4 *)0x0) {

          *param_7 = *(undefined4 *)(puVar4 + 0xc);

        }

        uVar1 = 1;

        goto LAB_14013efeb;

      }

      pcVar5 = "finger";

    }

    uVar1 = FUN_14012e850("Parameter \'%s\' is invalid",pcVar5);

  }

LAB_14013efeb:

  FUN_14015bb10();

  return uVar1;

}




