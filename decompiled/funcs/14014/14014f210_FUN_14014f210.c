// Address: 0x14014f210
// Ghidra name: FUN_14014f210
// ============ 0x14014f210 FUN_14014f210 (size=123) ============


undefined8 FUN_14014f210(undefined4 param_1,undefined1 *param_2)



{

  char cVar1;

  float fVar2;

  float fVar3;

  float local_res18 [4];

  

  fVar3 = DAT_14039ca44;

  local_res18[0] = 1.0;

  cVar1 = FUN_14014f1a0(param_1,local_res18);

  if (cVar1 != '\0') {

    if (param_2 != (undefined1 *)0x0) {

      fVar2 = 0.0;

      if ((0.0 <= local_res18[0]) && (fVar2 = fVar3, local_res18[0] <= fVar3)) {

        fVar2 = local_res18[0];

      }

      fVar3 = (float)thunk_FUN_1402e1d00(fVar2 * DAT_14030a2d0);

      *param_2 = (char)(int)fVar3;

    }

    return 1;

  }

  if (param_2 != (undefined1 *)0x0) {

    *param_2 = 0xff;

  }

  return 0;

}




