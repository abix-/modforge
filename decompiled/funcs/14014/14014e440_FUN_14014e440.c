// Address: 0x14014e440
// Ghidra name: FUN_14014e440
// ============ 0x14014e440 FUN_14014e440 (size=223) ============


undefined8

FUN_14014e440(undefined8 param_1,undefined1 *param_2,undefined1 *param_3,undefined1 *param_4,

             undefined1 *param_5)



{

  float fVar1;

  char cVar2;

  float local_18;

  float local_14;

  float local_10;

  float local_c;

  

  cVar2 = FUN_14014e350(param_1,&local_18,&local_14,&local_10,&local_c);

  fVar1 = DAT_14030a2d0;

  if (cVar2 == '\0') {

    if (param_2 != (undefined1 *)0x0) {

      *param_2 = 0;

    }

    if (param_3 != (undefined1 *)0x0) {

      *param_3 = 0;

    }

    if (param_4 != (undefined1 *)0x0) {

      *param_4 = 0;

    }

    if (param_5 != (undefined1 *)0x0) {

      *param_5 = 0;

    }

    return 0;

  }

  if (param_2 != (undefined1 *)0x0) {

    *param_2 = (char)(int)(local_18 * DAT_14030a2d0);

  }

  if (param_3 != (undefined1 *)0x0) {

    *param_3 = (char)(int)(local_14 * fVar1);

  }

  if (param_4 != (undefined1 *)0x0) {

    *param_4 = (char)(int)(local_10 * fVar1);

  }

  if (param_5 != (undefined1 *)0x0) {

    *param_5 = (char)(int)(local_c * fVar1);

  }

  return 1;

}




