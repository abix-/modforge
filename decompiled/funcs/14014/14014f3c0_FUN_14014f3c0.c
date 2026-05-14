// Address: 0x14014f3c0
// Ghidra name: FUN_14014f3c0
// ============ 0x14014f3c0 FUN_14014f3c0 (size=285) ============


undefined8

FUN_14014f3c0(undefined4 param_1,undefined1 *param_2,undefined1 *param_3,undefined1 *param_4)



{

  char cVar1;

  undefined8 uVar2;

  float fVar3;

  float fVar4;

  float local_38;

  float local_34;

  float local_30 [10];

  

  fVar4 = DAT_14039ca44;

  local_38 = 1.0;

  local_34 = 1.0;

  local_30[0] = 1.0;

  cVar1 = FUN_14014f300(param_1,&local_38,&local_34,local_30);

  if (cVar1 == '\0') {

    if (param_2 != (undefined1 *)0x0) {

      *param_2 = 0xff;

    }

    if (param_3 != (undefined1 *)0x0) {

      *param_3 = 0xff;

    }

    if (param_4 != (undefined1 *)0x0) {

      *param_4 = 0xff;

    }

    uVar2 = 0;

  }

  else {

    if (param_2 != (undefined1 *)0x0) {

      if (0.0 <= local_38) {

        fVar3 = fVar4;

        if (local_38 <= fVar4) {

          fVar3 = local_38;

        }

      }

      else {

        fVar3 = 0.0;

      }

      fVar3 = (float)thunk_FUN_1402e1d00(fVar3 * DAT_14030a2d0);

      *param_2 = (char)(int)fVar3;

    }

    if (param_3 != (undefined1 *)0x0) {

      if (0.0 <= local_34) {

        fVar3 = fVar4;

        if (local_34 <= fVar4) {

          fVar3 = local_34;

        }

      }

      else {

        fVar3 = 0.0;

      }

      fVar3 = (float)thunk_FUN_1402e1d00(fVar3 * DAT_14030a2d0);

      *param_3 = (char)(int)fVar3;

    }

    if (param_4 != (undefined1 *)0x0) {

      fVar3 = 0.0;

      if ((0.0 <= local_30[0]) && (fVar3 = fVar4, local_30[0] <= fVar4)) {

        fVar3 = local_30[0];

      }

      fVar4 = (float)thunk_FUN_1402e1d00(fVar3 * DAT_14030a2d0);

      *param_4 = (char)(int)fVar4;

    }

    uVar2 = 1;

  }

  return uVar2;

}




